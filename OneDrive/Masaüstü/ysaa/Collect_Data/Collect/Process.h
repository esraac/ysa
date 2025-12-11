#pragma once
#include <vector>

// Að Yapýsý
struct NeuralNetwork {
	int numLayers;          // Toplam katman sayýsý (Girdi + Gizli + Çýktý)
	int* layerSizes;        // Her katmandaki nöron sayýsý dizisi
	float** weights;        // Aðýrlýk matrisleri
	float** biases;         // Bias vektörleri
	float** neurons;        // Her katmanýn çýkýþ deðerleri (aktivasyon sonrasý)
	float** deltas;         // Geri yayýlým hata terimleri

	// Momentum için önceki deðiþimleri saklayan diziler
	float** prev_dWeights;
	float** prev_dBiases;
};

// Fonksiyon Prototipleri
NeuralNetwork* CreateNetwork(int inputDim, std::vector<int> hiddenLayers, int outputDim);
void DeleteNetwork(NeuralNetwork* net);
void InitNetwork(NeuralNetwork* net);
float* ForwardProp(NeuralNetwork* net, float* input, bool isRegression);
float TrainNetwork(NeuralNetwork* net, float* input, float* target, float lr, float momentum, bool isRegression);

// Yardýmcýlar
float* Add_Data(float* sample, int Size, float* x, int Dim);
float* Add_Labels(float* Labels, int Size, int label);
void Z_Score_Parameters(float* x, int Size, int dim, float* mean, float* std);