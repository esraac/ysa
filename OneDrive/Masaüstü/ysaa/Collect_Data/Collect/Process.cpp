#include "pch.h"
#include "Process.h"
#include <cmath>
#include <cstdlib>
#include <vector>

float* Add_Data(float* sample, int Size, float* x, int Dim) {
	float* temp;
	temp = new float[Size * Dim];
	for (int i = 0; i < (Size - 1) * Dim; i++)
		temp[i] = sample[i];
	for (int i = 0; i < Dim; i++)
		temp[(Size - 1) * Dim + i] = x[i];
	//Deallocate memory
	delete[] sample;
	return temp;
}//Add_data
float* Add_Labels(float* Labels, int Size, int label) {
	float* temp;
	temp = new float[Size];
	for (int i = 0; i < Size - 1; i++)
		temp[i] = Labels[i];
	temp[Size - 1] = float(label);
	//Deallocate memory
	delete[] Labels;
	return temp;
}
float* init_array_random(int len) {
	float* arr = new float[len];
	for (int i = 0; i < len; i++)
		arr[i] = ((float)rand() / RAND_MAX) - 0.5f;
	return arr;
}
void Z_Score_Parameters(float* x, int Size, int dim, float* mean, float* std) {

	float* Total = new float[dim];

	int i, j;
	for (i = 0; i < dim; i++) {
		mean[i] = std[i] = Total[i] = 0.0;
	}
	for (i = 0; i < Size; i++)
		for (j = 0; j < dim; j++)
			Total[j] += x[i * dim + j];
	for (i = 0; i < dim; i++)
		mean[i] = Total[i] / float(Size);

	for (i = 0; i < Size; i++)
		for (j = 0; j < dim; j++)
			std[j] += ((x[i * dim + j] - mean[j]) * (x[i * dim + j] - mean[j]));

	for (j = 0; j < dim; j++)
		std[j] = sqrt(std[j] / float(Size));

	delete[] Total;

}//Z_Score_Parameters
int Test_Forward(float* x, float* weight, float* bias, int num_Class, int inputDim) {
	int i, j, index_Max;
	if (num_Class > 2) {
		float* output = new float[num_Class];
		// Calculation of the output layer input
		for (i = 0; i < num_Class; i++) {
			output[i] = 0.0f;
			for (j = 0; j < inputDim; j++)
				output[i] += weight[i * inputDim + j] * x[j];
			output[i] += bias[i];
		}
		for (i = 0; i < num_Class; i++)
			output[i] = tanh(output[i]);

		//Find Maximum in neuron
		float temp = output[0];
		index_Max = 0;
		for (i = 1; i < num_Class; i++)
			if (temp < output[i]) {
				temp = output[i];
				index_Max = i;
			}

		delete[] output;
	}
	else {
		float output = 0.0f;
		for (j = 0; j < inputDim; j++)
			output += weight[j] * x[j];
		output += bias[0];
		output = tanh(output);
		if (output > 0.0f)
			index_Max = 0;
		else index_Max = 1;
	}
	return index_Max;

}//
float activation(float x, bool isLinear) {
	if (isLinear) return x;
	return tanh(x);
}
float derivative(float x, bool isLinear) {
	if (isLinear) return 1.0f;
	return 1.0f - (x * x); // tanh türevi
}

NeuralNetwork* CreateNetwork(int inputDim, std::vector<int> hiddenLayers, int outputDim) {
	NeuralNetwork* net = new NeuralNetwork;

	net->numLayers = 2 + hiddenLayers.size();
	net->layerSizes = new int[net->numLayers];

	net->layerSizes[0] = inputDim;
	for (size_t i = 0; i < hiddenLayers.size(); ++i)
		net->layerSizes[i + 1] = hiddenLayers[i];
	net->layerSizes[net->numLayers - 1] = outputDim;

	// Bellek Ayýrma
	net->weights = new float* [net->numLayers - 1];
	net->biases = new float* [net->numLayers - 1];
	net->prev_dWeights = new float* [net->numLayers - 1];
	net->prev_dBiases = new float* [net->numLayers - 1];

	net->neurons = new float* [net->numLayers];
	net->deltas = new float* [net->numLayers];

	// Nöronlar için yer ayýr
	for (int i = 0; i < net->numLayers; i++) {
		net->neurons[i] = new float[net->layerSizes[i]];
		net->deltas[i] = new float[net->layerSizes[i]];
	}

	// Aðýrlýklar için yer ayýr (Layer i -> Layer i+1)
	for (int i = 0; i < net->numLayers - 1; i++) {
		int rows = net->layerSizes[i + 1];
		int cols = net->layerSizes[i];

		net->weights[i] = new float[rows * cols];
		net->prev_dWeights[i] = new float[rows * cols];

		net->biases[i] = new float[rows];
		net->prev_dBiases[i] = new float[rows];
	}

	InitNetwork(net);
	return net;
}

void InitNetwork(NeuralNetwork* net) {
	for (int i = 0; i < net->numLayers - 1; i++) {
		int rows = net->layerSizes[i + 1];
		int cols = net->layerSizes[i];
		for (int j = 0; j < rows * cols; j++) {
			net->weights[i][j] = ((float)rand() / RAND_MAX) - 0.5f;
			net->prev_dWeights[i][j] = 0.0f; // Momentum sýfýrla
		}
		for (int j = 0; j < rows; j++) {
			net->biases[i][j] = ((float)rand() / RAND_MAX) - 0.5f;
			net->prev_dBiases[i][j] = 0.0f;
		}
	}
}

// Ýleri Besleme (Forward Propagation)
// Ýleri Besleme (Forward Propagation)
float* ForwardProp(NeuralNetwork* net, float* input, bool isRegression) {
	// 1. Giriþ katmanýný ayarla
	for (int i = 0; i < net->layerSizes[0]; i++)
		net->neurons[0][i] = input[i];

	// 2. Gizli Katmanlar ve Çýkýþ Katmaný
	for (int i = 0; i < net->numLayers - 1; i++) {
		int prevSize = net->layerSizes[i];
		int currSize = net->layerSizes[i + 1];

		// Son katmanda mýyýz?
		bool isOutputLayer = (i == net->numLayers - 2);

		for (int j = 0; j < currSize; j++) {
			float sum = net->biases[i][j];
			for (int k = 0; k < prevSize; k++) {
				sum += net->weights[i][j * prevSize + k] * net->neurons[i][k];
			}

			// KRÝTÝK NOKTA: Aktivasyon Fonksiyonu Seçimi
			if (isOutputLayer) {
				if (isRegression) {
					// Regresyon: Lineer Çýkýþ (f(x) = x)
					// Çünkü hedef deðer 500 de olabilir, -200 de. Tanh bunu ezer.
					net->neurons[i + 1][j] = sum;
				}
				else {
					// Sýnýflandýrma: Tanh Çýkýþ (-1 ile 1 arasý)
					// Karar vermek için sýkýþtýrýlmýþ deðer lazým.
					net->neurons[i + 1][j] = tanh(sum);
				}
			}
			else {
				// Gizli Katmanlar: Her zaman Tanh (Non-linearity için)
				net->neurons[i + 1][j] = tanh(sum);
			}
		}
	}
	return net->neurons[net->numLayers - 1];
}

// Eðitim (Training)
float TrainNetwork(NeuralNetwork* net, float* input, float* target, float lr, float momentum, bool isRegression) {

	// 1. Ýleri Yayýlým
	float* output = ForwardProp(net, input, isRegression);
	int outputLayerIdx = net->numLayers - 1;
	int outputSize = net->layerSizes[outputLayerIdx];
	float totalError = 0.0f;

	// 2. Çýkýþ Hatasýný Hesapla (Delta)
	for (int i = 0; i < outputSize; i++) {
		float desiredOutput = 0.0f;

		// HEDEF DEÐER BELÝRLEME
		if (isRegression) {
			// Regresyon: Hedef doðrudan gelen deðerdir (Normalize edilmiþ Y)
			desiredOutput = target[i];
		}
		else {
			// Sýnýflandýrma: Hedef -1 veya 1 olmalý
			int label = (int)target[0]; // Sýnýflandýrmada target[0] etiket bilgisidir (0, 1, 2...)

			if (outputSize == 1) {
				// Binary (2 Sýnýf): Sýnýf 0 -> -1, Sýnýf 1 -> +1
				desiredOutput = (label == 0) ? -1.0f : 1.0f;
			}
			else {
				// Multi-Class: Ýlgili nöron 1, diðerleri -1
				desiredOutput = (label == i) ? 1.0f : -1.0f;
			}
		}

		float err = desiredOutput - output[i];
		totalError += err * err;

		// TÜREV HESAPLAMA (Delta)
		if (isRegression) {
			// Lineer Türev: f'(x) = 1
			// Delta = Hata * 1
			net->deltas[outputLayerIdx][i] = err;
		}
		else {
			// Tanh Türev: f'(x) = 1 - output^2
			// Delta = Hata * (1 - y^2)
			net->deltas[outputLayerIdx][i] = err * (1.0f - output[i] * output[i]);
		}
	}

	// 3. Geri Yayýlým (Hidden Layers - Her zaman Tanh olduðu için türevi bellidir)
	for (int i = net->numLayers - 2; i > 0; i--) {
		int currSize = net->layerSizes[i];
		int nextSize = net->layerSizes[i + 1];

		for (int j = 0; j < currSize; j++) {
			float errorSum = 0.0f;
			for (int k = 0; k < nextSize; k++) {
				errorSum += net->deltas[i + 1][k] * net->weights[i][k * currSize + j];
			}
			// Gizli katman türevi (1 - y^2)
			net->deltas[i][j] = errorSum * (1.0f - net->neurons[i][j] * net->neurons[i][j]);
		}
	}

	// 4. Aðýrlýk Güncelleme (Momentum Dahil)
	for (int i = 0; i < net->numLayers - 1; i++) {
		int prevSize = net->layerSizes[i];
		int currSize = net->layerSizes[i + 1];

		for (int j = 0; j < currSize; j++) {
			for (int k = 0; k < prevSize; k++) {
				float gradient = net->deltas[i + 1][j] * net->neurons[i][k];
				float deltaWeight = (lr * gradient) + (momentum * net->prev_dWeights[i][j * prevSize + k]);

				net->weights[i][j * prevSize + k] += deltaWeight;
				net->prev_dWeights[i][j * prevSize + k] = deltaWeight;
			}
			float gradientBias = net->deltas[i + 1][j];
			float deltaBias = (lr * gradientBias) + (momentum * net->prev_dBiases[i][j]);

			net->biases[i][j] += deltaBias;
			net->prev_dBiases[i][j] = deltaBias;
		}
	}

	return totalError;
}