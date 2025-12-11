#pragma once
#include "Process.h"
#include <iostream>
#include <fstream>
#include <string>

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ Set_Net;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ ClassCountBox;

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ ClassNoBox;

	private: System::Windows::Forms::Label^ label3;

	private:
		/// <summary>
		/// User Defined Variables
		int  class_count = 0, numSample = 0, inputDim = 2;
		float* Samples, * targets, * Weights, * bias;

		int max_epochs = 1000;
		float learning_rate = 0.01f;

		Chart^ errorChart;
		bool isRegressionMode = false;
		float minX, maxX, minY, maxY;
		float* TrainingMean = nullptr;
		float* TrainingStd = nullptr;
		NeuralNetwork* myNet = nullptr;
		float* InputMean = nullptr;
		float* InputStd = nullptr;
		float* TargetMean = nullptr; 
		float* TargetStd = nullptr;

	private: System::Windows::Forms::TextBox^ txtHiddenLayers;
	private: System::Windows::Forms::Label^ lblHiddenLayers;
	private: System::Windows::Forms::TextBox^ txtMomentum;
	private: System::Windows::Forms::Label^ lblMomentum;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ readDataToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

	private: System::Windows::Forms::ToolStripMenuItem^ saveDataToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^ processToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ trainingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ testingToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBoxTraining;
	private: System::Windows::Forms::Label^ labelEpoch;
	private: System::Windows::Forms::TextBox^ txtEpoch;
	private: System::Windows::Forms::Label^ labelLR;
	private: System::Windows::Forms::TextBox^ txtLR;

	private: System::Windows::Forms::ToolStripMenuItem^ regressionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ linearRegressionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ nonlinearRegressionToolStripMenuItem;

		   /// </summary>
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Erforderliche Methode für die Designerunterstützung.
		   /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			   System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			   System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			   this->Set_Net = (gcnew System::Windows::Forms::Button());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->ClassCountBox = (gcnew System::Windows::Forms::ComboBox());
			   this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->ClassNoBox = (gcnew System::Windows::Forms::ComboBox());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			   this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->readDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->saveDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->trainingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->testingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->regressionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->linearRegressionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->nonlinearRegressionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			   this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			   this->groupBoxTraining = (gcnew System::Windows::Forms::GroupBox());
			   this->txtLR = (gcnew System::Windows::Forms::TextBox());
			   this->labelLR = (gcnew System::Windows::Forms::Label());
			   this->txtEpoch = (gcnew System::Windows::Forms::TextBox());
			   this->labelEpoch = (gcnew System::Windows::Forms::Label());
			   this->lblHiddenLayers = (gcnew System::Windows::Forms::Label());
			   this->txtHiddenLayers = (gcnew System::Windows::Forms::TextBox());
			   this->lblMomentum = (gcnew System::Windows::Forms::Label());
			   this->txtMomentum = (gcnew System::Windows::Forms::TextBox());
			   this->errorChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   this->groupBox1->SuspendLayout();
			   this->groupBox2->SuspendLayout();
			   this->menuStrip1->SuspendLayout();
			   this->groupBoxTraining->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorChart))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->BackColor = System::Drawing::Color::White;
			   this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->pictureBox1->Location = System::Drawing::Point(16, 44);
			   this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(1066, 738);
			   this->pictureBox1->TabIndex = 0;
			   this->pictureBox1->TabStop = false;
			   this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			   this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseClick);
			   // 
			   // groupBox1
			   // 
			   this->groupBox1->Controls->Add(this->Set_Net);
			   this->groupBox1->Controls->Add(this->label1);
			   this->groupBox1->Controls->Add(this->ClassCountBox);
			   this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold));
			   this->groupBox1->Location = System::Drawing::Point(1107, 49);
			   this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			   this->groupBox1->Name = L"groupBox1";
			   this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			   this->groupBox1->Size = System::Drawing::Size(267, 123);
			   this->groupBox1->TabIndex = 1;
			   this->groupBox1->TabStop = false;
			   this->groupBox1->Text = L"Network Architecture";
			   // 
			   // Set_Net
			   // 
			   this->Set_Net->Location = System::Drawing::Point(13, 74);
			   this->Set_Net->Margin = System::Windows::Forms::Padding(4);
			   this->Set_Net->Name = L"Set_Net";
			   this->Set_Net->Size = System::Drawing::Size(173, 37);
			   this->Set_Net->TabIndex = 2;
			   this->Set_Net->Text = L"Network Setting";
			   this->Set_Net->UseVisualStyleBackColor = true;
			   this->Set_Net->Click += gcnew System::EventHandler(this, &Form1::Set_Net_Click);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(133, 31);
			   this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(88, 17);
			   this->label1->TabIndex = 1;
			   this->label1->Text = L"Sýnýf Sayýsý";
			   // 
			   // ClassCountBox
			   // 
			   this->ClassCountBox->FormattingEnabled = true;
			   this->ClassCountBox->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"2", L"3", L"4", L"5", L"6", L"7" });
			   this->ClassCountBox->Location = System::Drawing::Point(13, 27);
			   this->ClassCountBox->Margin = System::Windows::Forms::Padding(4);
			   this->ClassCountBox->Name = L"ClassCountBox";
			   this->ClassCountBox->Size = System::Drawing::Size(105, 25);
			   this->ClassCountBox->TabIndex = 0;
			   this->ClassCountBox->Text = L"2";
			   // 
			   // groupBox2
			   // 
			   this->groupBox2->Controls->Add(this->label2);
			   this->groupBox2->Controls->Add(this->ClassNoBox);
			   this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold));
			   this->groupBox2->Location = System::Drawing::Point(1107, 185);
			   this->groupBox2->Margin = System::Windows::Forms::Padding(4);
			   this->groupBox2->Name = L"groupBox2";
			   this->groupBox2->Padding = System::Windows::Forms::Padding(4);
			   this->groupBox2->Size = System::Drawing::Size(267, 74);
			   this->groupBox2->TabIndex = 2;
			   this->groupBox2->TabStop = false;
			   this->groupBox2->Text = L"Data Collection";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(120, 31);
			   this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(102, 17);
			   this->label2->TabIndex = 1;
			   this->label2->Text = L"Örnek Etiketi";
			   // 
			   // ClassNoBox
			   // 
			   this->ClassNoBox->FormattingEnabled = true;
			   this->ClassNoBox->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				   L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					   L"9"
			   });
			   this->ClassNoBox->Location = System::Drawing::Point(13, 27);
			   this->ClassNoBox->Margin = System::Windows::Forms::Padding(4);
			   this->ClassNoBox->Name = L"ClassNoBox";
			   this->ClassNoBox->Size = System::Drawing::Size(99, 25);
			   this->ClassNoBox->TabIndex = 0;
			   this->ClassNoBox->Text = L"1";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(1107, 271);
			   this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(104, 16);
			   this->label3->TabIndex = 3;
			   this->label3->Text = L"Sample Count: 0";
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				   this->fileToolStripMenuItem,
					   this->processToolStripMenuItem
			   });
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Size = System::Drawing::Size(1533, 28);
			   this->menuStrip1->TabIndex = 4;
			   this->menuStrip1->Text = L"menuStrip1";
			   // 
			   // fileToolStripMenuItem
			   // 
			   this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				   this->readDataToolStripMenuItem,
					   this->saveDataToolStripMenuItem
			   });
			   this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			   this->fileToolStripMenuItem->Size = System::Drawing::Size(46, 24);
			   this->fileToolStripMenuItem->Text = L"File";
			   // 
			   // readDataToolStripMenuItem
			   // 
			   this->readDataToolStripMenuItem->Name = L"readDataToolStripMenuItem";
			   this->readDataToolStripMenuItem->Size = System::Drawing::Size(164, 26);
			   this->readDataToolStripMenuItem->Text = L"Read_Data";
			   this->readDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::readDataToolStripMenuItem_Click);
			   // 
			   // saveDataToolStripMenuItem
			   // 
			   this->saveDataToolStripMenuItem->Name = L"saveDataToolStripMenuItem";
			   this->saveDataToolStripMenuItem->Size = System::Drawing::Size(164, 26);
			   this->saveDataToolStripMenuItem->Text = L"Save_Data";
			   this->saveDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveDataToolStripMenuItem_Click);
			   // 
			   // processToolStripMenuItem
			   // 
			   this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				   this->trainingToolStripMenuItem,
					   this->testingToolStripMenuItem, this->regressionToolStripMenuItem
			   });
			   this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			   this->processToolStripMenuItem->Size = System::Drawing::Size(72, 24);
			   this->processToolStripMenuItem->Text = L"Process";
			   // 
			   // trainingToolStripMenuItem
			   // 
			   this->trainingToolStripMenuItem->Name = L"trainingToolStripMenuItem";
			   this->trainingToolStripMenuItem->Size = System::Drawing::Size(164, 26);
			   this->trainingToolStripMenuItem->Text = L"Training";
			   this->trainingToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::trainingToolStripMenuItem_Click);
			   // 
			   // testingToolStripMenuItem
			   // 
			   this->testingToolStripMenuItem->Name = L"testingToolStripMenuItem";
			   this->testingToolStripMenuItem->Size = System::Drawing::Size(164, 26);
			   this->testingToolStripMenuItem->Text = L"Testing";
			   this->testingToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testingToolStripMenuItem_Click);
			   // 
			   // regressionToolStripMenuItem
			   // 
			   this->regressionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				   this->linearRegressionToolStripMenuItem,
					   this->nonlinearRegressionToolStripMenuItem
			   });
			   this->regressionToolStripMenuItem->Name = L"regressionToolStripMenuItem";
			   this->regressionToolStripMenuItem->Size = System::Drawing::Size(164, 26);
			   this->regressionToolStripMenuItem->Text = L"Regression";
			   // 
			   // linearRegressionToolStripMenuItem
			   // 
			   this->linearRegressionToolStripMenuItem->Name = L"linearRegressionToolStripMenuItem";
			   this->linearRegressionToolStripMenuItem->Size = System::Drawing::Size(233, 26);
			   this->linearRegressionToolStripMenuItem->Text = L"Linear Regression";
			   // 
			   // nonlinearRegressionToolStripMenuItem
			   // 
			   this->nonlinearRegressionToolStripMenuItem->Name = L"nonlinearRegressionToolStripMenuItem";
			   this->nonlinearRegressionToolStripMenuItem->Size = System::Drawing::Size(233, 26);
			   this->nonlinearRegressionToolStripMenuItem->Text = L"Nonlinear Regression";
			   // 
			   // openFileDialog1
			   // 
			   this->openFileDialog1->FileName = L"openFileDialog1";
			   // 
			   // groupBoxTraining
			   // 
			   this->groupBoxTraining->Controls->Add(this->txtLR);
			   this->groupBoxTraining->Controls->Add(this->labelLR);
			   this->groupBoxTraining->Controls->Add(this->txtEpoch);
			   this->groupBoxTraining->Controls->Add(this->labelEpoch);
			   this->groupBoxTraining->Controls->Add(this->lblHiddenLayers);
			   this->groupBoxTraining->Controls->Add(this->txtHiddenLayers);
			   this->groupBoxTraining->Controls->Add(this->lblMomentum);
			   this->groupBoxTraining->Controls->Add(this->txtMomentum);
			   this->groupBoxTraining->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold));
			   this->groupBoxTraining->Location = System::Drawing::Point(1107, 295);
			   this->groupBoxTraining->Margin = System::Windows::Forms::Padding(4);
			   this->groupBoxTraining->Name = L"groupBoxTraining";
			   this->groupBoxTraining->Padding = System::Windows::Forms::Padding(4);
			   this->groupBoxTraining->Size = System::Drawing::Size(267, 193);
			   this->groupBoxTraining->TabIndex = 6;
			   this->groupBoxTraining->TabStop = false;
			   this->groupBoxTraining->Text = L"Training Parameters";
			   // 
			   // txtLR
			   // 
			   this->txtLR->Location = System::Drawing::Point(107, 65);
			   this->txtLR->Margin = System::Windows::Forms::Padding(4);
			   this->txtLR->Name = L"txtLR";
			   this->txtLR->Size = System::Drawing::Size(132, 23);
			   this->txtLR->TabIndex = 1;
			   this->txtLR->Text = L"0.01";
			   // 
			   // labelLR
			   // 
			   this->labelLR->AutoSize = true;
			   this->labelLR->Location = System::Drawing::Point(13, 68);
			   this->labelLR->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->labelLR->Name = L"labelLR";
			   this->labelLR->Size = System::Drawing::Size(33, 17);
			   this->labelLR->TabIndex = 2;
			   this->labelLR->Text = L"LR:";
			   // 
			   // txtEpoch
			   // 
			   this->txtEpoch->Location = System::Drawing::Point(107, 27);
			   this->txtEpoch->Margin = System::Windows::Forms::Padding(4);
			   this->txtEpoch->Name = L"txtEpoch";
			   this->txtEpoch->Size = System::Drawing::Size(132, 23);
			   this->txtEpoch->TabIndex = 0;
			   this->txtEpoch->Text = L"1000";
			   // 
			   // labelEpoch
			   // 
			   this->labelEpoch->AutoSize = true;
			   this->labelEpoch->Location = System::Drawing::Point(13, 31);
			   this->labelEpoch->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->labelEpoch->Name = L"labelEpoch";
			   this->labelEpoch->Size = System::Drawing::Size(58, 17);
			   this->labelEpoch->TabIndex = 3;
			   this->labelEpoch->Text = L"Epoch:";
			   // 
			   // lblHiddenLayers
			   // 
			   this->lblHiddenLayers->AutoSize = true;
			   this->lblHiddenLayers->Location = System::Drawing::Point(13, 97);
			   this->lblHiddenLayers->Name = L"lblHiddenLayers";
			   this->lblHiddenLayers->Size = System::Drawing::Size(188, 17);
			   this->lblHiddenLayers->TabIndex = 4;
			   this->lblHiddenLayers->Text = L"Hidden Layer (örn: 5,10)";
			   // 
			   // txtHiddenLayers
			   // 
			   this->txtHiddenLayers->Location = System::Drawing::Point(18, 117);
			   this->txtHiddenLayers->Name = L"txtHiddenLayers";
			   this->txtHiddenLayers->Size = System::Drawing::Size(100, 23);
			   this->txtHiddenLayers->TabIndex = 5;
			   this->txtHiddenLayers->Text = L"10,10";
			   // 
			   // lblMomentum
			   // 
			   this->lblMomentum->AutoSize = true;
			   this->lblMomentum->Location = System::Drawing::Point(13, 143);
			   this->lblMomentum->Name = L"lblMomentum";
			   this->lblMomentum->Size = System::Drawing::Size(126, 17);
			   this->lblMomentum->TabIndex = 6;
			   this->lblMomentum->Text = L"Momentum (0-1)";
			   // 
			   // txtMomentum
			   // 
			   this->txtMomentum->Location = System::Drawing::Point(18, 163);
			   this->txtMomentum->Name = L"txtMomentum";
			   this->txtMomentum->Size = System::Drawing::Size(60, 23);
			   this->txtMomentum->TabIndex = 7;
			   this->txtMomentum->Text = L"0.9";
			   // 
			   // errorChart
			   // 
			   chartArea1->Name = L"ChartArea1";
			   this->errorChart->ChartAreas->Add(chartArea1);
			   legend1->Enabled = false;
			   legend1->Name = L"Legend1";
			   this->errorChart->Legends->Add(legend1);
			   this->errorChart->Location = System::Drawing::Point(1107, 496);
			   this->errorChart->Margin = System::Windows::Forms::Padding(4);
			   this->errorChart->Name = L"errorChart";
			   series1->ChartArea = L"ChartArea1";
			   series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			   series1->Legend = L"Legend1";
			   series1->Name = L"MSE";
			   this->errorChart->Series->Add(series1);
			   this->errorChart->Size = System::Drawing::Size(400, 246);
			   this->errorChart->TabIndex = 7;
			   this->errorChart->Text = L"errorChart";
			   // 
			   // Form1
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1533, 886);
			   this->Controls->Add(this->errorChart);
			   this->Controls->Add(this->groupBoxTraining);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->groupBox2);
			   this->Controls->Add(this->groupBox1);
			   this->Controls->Add(this->pictureBox1);
			   this->Controls->Add(this->menuStrip1);
			   this->MainMenuStrip = this->menuStrip1;
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->Name = L"Form1";
			   this->Text = L"Neural Network Interface";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   this->groupBox1->ResumeLayout(false);
			   this->groupBox1->PerformLayout();
			   this->groupBox2->ResumeLayout(false);
			   this->groupBox2->PerformLayout();
			   this->menuStrip1->ResumeLayout(false);
			   this->menuStrip1->PerformLayout();
			   this->groupBoxTraining->ResumeLayout(false);
			   this->groupBoxTraining->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorChart))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
		   void draw_sample(int temp_x, int temp_y, int label) {
			   Pen^ pen;// = gcnew Pen(Color::Black, 3.0f);
			   switch (label) {
			   case 0: pen = gcnew Pen(Color::Black, 3.0f); break;
			   case 1: pen = gcnew Pen(Color::Red, 3.0f); break;
			   case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
			   case 3: pen = gcnew Pen(Color::Green, 3.0f); break;
			   case 4: pen = gcnew Pen(Color::Yellow, 3.0f); break;
			   case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
			   default: pen = gcnew Pen(Color::YellowGreen, 3.0f);
			   }//switch
			   pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
			   pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
		   }//draw_sample
#pragma endregion
		   // Bu fonksiyonu Form1 sýnýfýnýn içine (public veya private kýsmýna) ekleyin
		   System::Drawing::Color GetColorForClass(int classIdx, bool isBackground) {
			   if (isBackground) {
				   // ARKA PLAN RENKLERÝ (Pastel Tonlar - Noktalar görünsün diye açýk renk)
				   switch (classIdx) {
				   case 0: return Color::FromArgb(220, 220, 220); // Sýnýf 0 (Siyah) -> GRÝ Zemin
				   case 1: return Color::FromArgb(255, 200, 200); // Sýnýf 1 (Kýrmýzý) -> PEMBE Zemin
				   case 2: return Color::FromArgb(200, 200, 255); // Sýnýf 2 (Mavi) -> AÇIK MAVÝ
				   case 3: return Color::FromArgb(200, 255, 200); // Sýnýf 3 (Yeþil) -> AÇIK YEÞÝL
				   default: return Color::White;
				   }
			   }
			   else {
				   // NOKTA RENKLERÝ (Koyu Tonlar)
				   switch (classIdx) {
				   case 0: return Color::Black;
				   case 1: return Color::Red;
				   case 2: return Color::Blue;
				   case 3: return Color::Green;
				   default: return Color::Orange;
				   }
			   }
		   }
	private: System::Void pictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		// 1. AÐ KONTROLÜ (YENÝ YAPIYA GÖRE)
		// Eski kod "if (Weights == nullptr)" diyordu, bu yüzden hata alýyordunuz.
		// Artýk "myNet" yapýsýný kontrol etmeliyiz.
		if (myNet == nullptr) {
			MessageBox::Show("Lütfen önce 'Network Setting' butonuna basarak aðý kurunuz.", "Uyarý", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// 2. KOORDÝNAT HESAPLAMA (Merkez Orijinli)
		int temp_x = e->X;
		int temp_y = e->Y;

		// Matematiksel koordinata çevir (Merkez 0,0)
		float input_val_x = (float)(temp_x - (pictureBox1->Width / 2));
		float input_val_y = (float)((pictureBox1->Height / 2) - temp_y);

		// 3. ETÝKETÝ VE TÜRÜ BELÝRLE
		int label = 0;

		// --- DURUM A: REGRESYON MODU (VERÝ TOPLAMA) ---
		if (isRegressionMode) {
			// Regresyonda: Girdi = X ekseni, Hedef = Y ekseni
			// InputDim = 1 kabul ediyoruz.
			float* newData = new float[1];
			newData[0] = input_val_x;

			// Samples dizisini geniþlet
			if (numSample == 0) {
				numSample = 1;
				Samples = new float[1]; // InputDim = 1
				targets = new float[1];
				Samples[0] = newData[0];
				targets[0] = input_val_y; // Hedef Y deðeri
			}
			else {
				numSample++;
				Samples = Add_Data(Samples, numSample, newData, 1);
				// Target float olduðu için Add_Labels yerine manuel ekleme veya float uyumlu fonksiyon gerekir.
				// Basitlik için manuel geniþletme yapalým:
				float* newTargets = new float[numSample];
				for (int i = 0; i < numSample - 1; i++) newTargets[i] = targets[i];
				newTargets[numSample - 1] = input_val_y;
				delete[] targets;
				targets = newTargets;
			}

			// Ekrana Çiz (Regresyon için Mavi Nokta)
			draw_sample(temp_x, temp_y, 2); // 2 = Mavi renk kodu (draw_sample fonksiyonunuzda)
			delete[] newData;
		}
		// --- DURUM B: SINIFLANDIRMA MODU (VERÝ TOPLAMA) ---
		else {
			// Kullanýcýdan sýnýf etiketini al (ComboBox'tan)
			if (ClassNoBox->Text == "") ClassNoBox->Text = "1";
			int selectedLabel = Convert::ToInt32(ClassNoBox->Text);
			label = selectedLabel - 1; // 0 tabanlý indeks (Sýnýf 1 -> 0, Sýnýf 2 -> 1)

			// Sýnýf etiketi kontrolü
			if (label >= class_count) {
				MessageBox::Show("Seçilen etiket, toplam sýnýf sayýsýndan büyük olamaz!", "Hata");
				return;
			}

			float* newData = new float[2];
			newData[0] = input_val_x;
			newData[1] = input_val_y;

			// Samples ve Targets dizilerini geniþlet
			if (numSample == 0) {
				numSample = 1;
				Samples = new float[2]; // InputDim = 2 (x,y)
				targets = new float[1];
				Samples[0] = newData[0];
				Samples[1] = newData[1];
				targets[0] = (float)label;
			}
			else {
				numSample++;
				Samples = Add_Data(Samples, numSample, newData, 2);
				targets = Add_Labels(targets, numSample, label);
			}

			// Ekrana Çiz
			draw_sample(temp_x, temp_y, label);
			delete[] newData;
		}

		// Sayaç Güncelle
		label3->Text = "Samples Count: " + Convert::ToString(numSample);
	}
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		//Ana eksen doðrularini cizdir
		Pen^ pen = gcnew Pen(Color::Black, 3.0f);
		int center_width, center_height;
		center_width = (int)(pictureBox1->Width / 2);
		center_height = (int)(pictureBox1->Height / 2);
		e->Graphics->DrawLine(pen, center_width, 0, center_width, pictureBox1->Height);
		e->Graphics->DrawLine(pen, 0, center_height, pictureBox1->Width, center_height);
	}
	private: System::Void Set_Net_Click(System::Object^ sender, System::EventArgs^ e) {
		// 1. Modu Sor (Regresyon mu Sýnýflandýrma mý?)
		System::Windows::Forms::DialogResult result = MessageBox::Show("Tahminleme (Regresyon) Modu mu?", "Mod Seçimi", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		isRegressionMode = (result == System::Windows::Forms::DialogResult::Yes);

		// 2. Giriþ ve Çýkýþ Boyutlarýný Belirle
		inputDim = isRegressionMode ? 1 : 2; // Regresyon: 1 giriþ, Sýnýflandýrma: 2 giriþ (x,y)

		// ClassCountBox'tan deðeri güvenli al
		if (ClassCountBox->Text == "") ClassCountBox->Text = "2";
		class_count = Convert::ToInt32(ClassCountBox->Text);

		// Çýkýþ boyutu (Regresyon ise 1, Sýnýflandýrma ise Sýnýf Sayýsý)
		int outputDim;
		if (isRegressionMode) outputDim = 1;
		else outputDim = (class_count == 2) ? 1 : class_count; // Binary ise 1 nöron yeter

		// 3. Gizli Katmanlarý Okuma
		std::vector<int> layers;

		// txtHiddenLayers nesnesinin varlýðýný kontrol et (Çökme önlemi)
		String^ hiddenStr = "";
		if (txtHiddenLayers != nullptr)
			hiddenStr = txtHiddenLayers->Text->Trim();

		// -- DURUM A: TEK KATMANLI (Kutu boþ veya 0) --
		if (String::IsNullOrEmpty(hiddenStr) || hiddenStr == "0") {
			// 'layers' vektörü boþ kalýr -> CreateNetwork bunu anlar ve direkt baðlar.
			MessageBox::Show("Tek Katmanlý (Single Layer) Að Seçildi.", "Bilgi");
		}
		// -- DURUM B: ÇOK KATMANLI (MLP) --
		else {
			cli::array<String^>^ split = hiddenStr->Split(',');
			bool validConfig = false;
			for (int i = 0; i < split->Length; i++) {
				try {
					int nodes = Convert::ToInt32(split[i]);
					if (nodes > 0) {
						layers.push_back(nodes);
						validConfig = true;
					}
				}
				catch (...) {}
			}

			if (validConfig)
				MessageBox::Show("Çok Katmanlý (MLP) Að Seçildi.\nGizli Katmanlar: " + hiddenStr, "Bilgi");
			else {
				MessageBox::Show("Girilen katman formatý hatalý, Tek Katmanlý moda geçildi.", "Uyarý");
				layers.clear();
			}
		}

		// 4. Aðý Oluþtur (Önceki að varsa temizle)
		// Bellek sýzýntýsý olmamasý için eski aðý silmek iyi bir pratiktir, 
		// ancak þu anlýk basitlik için direkt yenisini oluþturuyoruz.
		myNet = CreateNetwork(inputDim, layers, outputDim);

		if (myNet != nullptr) {
			Set_Net->Text = isRegressionMode ? "Regression Ready" : "Classification Ready";
		}
		else {
			MessageBox::Show("Að oluþturulamadý!", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void readDataToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		char** c = new char* [2];
		// Veri Kümesini okunacak 
		MessageBox::Show("Veri Kümesini Yükleyin");
		c[0] = "../Data/Samples.txt";
		c[1] = "../Data/weights.txt";
		std::ifstream file;
		int num, w, h, Dim, label;
		file.open(c[0]);
		if (file.is_open()) {
			//MessageBox::Show("Dosya acildi");
			file >> Dim >> w >> h >> num;
			// Set network values
			class_count = num;
			inputDim = Dim;
			Weights = new float[class_count * inputDim];
			bias = new float[class_count];
			numSample = 0;
			float* x = new float[inputDim];
			while (!file.eof())
			{
				if (numSample == 0) { //ilk örnek için sadece
					numSample = 1;
					Samples = new float[inputDim]; targets = new float[numSample];
					for (int i = 0; i < inputDim; i++)
						file >> Samples[i];
					file >> targets[0];
				}
				else {

					for (int i = 0; i < inputDim; i++)
						file >> x[i];
					file >> label;
					if (!file.eof()) {
						numSample++;
						Samples = Add_Data(Samples, numSample, x, inputDim);
						targets = Add_Labels(targets, numSample, label);
					}
				}//else
			} //while
			delete[]x;
			file.close();
			
			//draw_sample(temp_x, temp_y, label);
			label3->Text = "Samples Count: " + System::Convert::ToString(numSample);
			MessageBox::Show("Dosya basari ile okundu");
		}//file.is_open
		else MessageBox::Show("Dosya acilamadi");
		//Get weights
		int Layer;
		file.open(c[1]);
		if (file.is_open()) {
			file >> Layer >> Dim >> num;
			class_count = num;
			inputDim = Dim;
			Weights = new float[class_count * inputDim];
			bias = new float[class_count];

			while (!file.eof())
			{
				for (int i = 0; i < class_count; i++)
					for (int j = 0; j < inputDim; j++)
						file >> Weights[i * inputDim + j];
				for (int i = 0; i < class_count; i++)
					file >> bias[i];
			}
			file.close();
		}//file.is_open
		delete[]c;
	}//Read_Data
	private: System::Void saveDataToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (numSample != 0) {
			char** c = new char* [2];
			// Veri Kümesi yazýlacak
			c[0] = "../Data/Samples.txt";
			c[1] = "../Data/weights.txt";
			std::ofstream ofs(c[0]);
			if (!ofs.bad()) {
				// Width,  Height, number of Class, data+label
				ofs << inputDim << " " << pictureBox1->Width / 2 << " " << pictureBox1->Height / 2 << " " << class_count << std::endl;
				for (int i = 0; i < numSample; i++) {
					for (int d = 0; d < inputDim; d++)
						ofs << Samples[i * inputDim + d] << " ";
					ofs << targets[i] << std::endl;
				}
				ofs.close();
			}
			else MessageBox::Show("Samples icin dosya acilamadi");
			std::ofstream file(c[1]);
			if (!file.bad()) {
				// #Layer Dimension numClass weights biases
				file << 1 << " " << inputDim << " " << class_count << std::endl;
				for (int k = 0; k < class_count * inputDim; k++)
					file << Weights[k] << " ";
				file << std::endl;
				for (int k = 0; k < class_count; k++)
					file << bias[k] << " ";
				file.close();
			}
			else MessageBox::Show("Weight icin dosya acilamadi");
			delete[]c;
		}
		else MessageBox::Show("At least one sample should be given");
	}//Save_Data

	private: System::Void testingToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (InputMean == nullptr) {
			MessageBox::Show("Lütfen önce eðitimi tamamlayýn.");
			return;
		}

		Graphics^ g = pictureBox1->CreateGraphics();
		pictureBox1->Refresh();

		// --- REGRESYON MODU ---
		if (isRegressionMode) {
			Pen^ curvePen = gcnew Pen(Color::Red, 3.0f);
			float prev_ScreenX = 0, prev_ScreenY = 0;
			bool firstPoint = true;

			// Ekraný soldan saða tara
			for (int i = 0; i < pictureBox1->Width; i += 2) {
				// 1. Ekran X -> Ham X
				float raw_x = (float)(i - (pictureBox1->Width / 2));

				// 2. Ham X -> Normalize X (Aðýn anladýðý dil)
				float norm_x = (raw_x - InputMean[0]) / InputStd[0];

				// 3. Aða Sor
				float* output = ForwardProp(myNet, &norm_x, true);

				// 4. Normalize Y -> Ham Y (Denormalizasyon)
				// Çýktýyý TargetStd ile çarpýp TargetMean ekliyoruz
				float predicted_raw_y = (output[0] * TargetStd[0]) + TargetMean[0];

				// 5. Ham Y -> Ekran Y
				float screenY = (pictureBox1->Height / 2) - predicted_raw_y;

				// Çizim Sýnýrlarý (Taþmayý önle)
				if (screenY < -5000) screenY = -5000;
				if (screenY > 5000) screenY = 5000;

				if (!firstPoint) {
					g->DrawLine(curvePen, prev_ScreenX, prev_ScreenY, (float)i, screenY);
				}
				prev_ScreenX = (float)i;
				prev_ScreenY = screenY;
				firstPoint = false;
			}
		}
		// --- SINIFLANDIRMA MODU ---
		else {
			Bitmap^ surface = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			float* input = new float[inputDim];

			for (int row = 0; row < pictureBox1->Height; row += 5) { // 5x5 piksel atlayarak hýzlandýr
				for (int column = 0; column < pictureBox1->Width; column += 5) {

					// Koordinat Dönüþümü ve Normalizasyon
					float raw_x = (float)(column - (pictureBox1->Width / 2));
					float raw_y = (float)((pictureBox1->Height / 2) - row);

					input[0] = (raw_x - InputMean[0]) / InputStd[0];
					input[1] = (raw_y - InputMean[1]) / InputStd[1];

					float* output = ForwardProp(myNet, input, false);

					// Kazanan Sýnýfý Bul
					int bestClass = 0;
					int outSize = myNet->layerSizes[myNet->numLayers - 1];

					if (outSize == 1) { // 2 Sýnýflý
						bestClass = (output[0] > 0) ? 1 : 0;
					}
					else { // Çok Sýnýflý
						float maxVal = -9999.0f;
						for (int k = 0; k < outSize; k++) {
							if (output[k] > maxVal) { maxVal = output[k]; bestClass = k; }
						}
					}

					Color c = GetColorForClass(bestClass, true); // Arka plan rengi

					// 5x5 Blok Boyama
					for (int bx = 0; bx < 5; bx++)
						for (int by = 0; by < 5; by++)
							if (column + bx < surface->Width && row + by < surface->Height)
								surface->SetPixel(column + bx, row + by, c);
				}
			}
			pictureBox1->Image = surface;
		}

		// --- NOKTALARI ÇÝZ (Ortak) ---
		// Eðer bitmap kullandýysak grafik nesnesini ondan almalýyýz, yoksa PictureBox'tan
		Graphics^ g_final = isRegressionMode ? g : Graphics::FromImage(pictureBox1->Image);

		for (int i = 0; i < numSample; i++) {
			int label = (int)targets[i];
			// Regresyonda hedef Y deðeridir, sýnýflandýrmada etiket. Rengi ona göre seç.
			Color pColor = isRegressionMode ? Color::Blue : GetColorForClass(label, false);
			Pen^ pen = gcnew Pen(pColor, 3.0f);

			int px = (int)Samples[i * inputDim] + pictureBox1->Width / 2;
			int py = 0;

			if (isRegressionMode) py = (pictureBox1->Height / 2) - (int)targets[i];
			else py = (pictureBox1->Height / 2) - (int)Samples[i * inputDim + 1];

			g_final->DrawEllipse(pen, px - 2, py - 2, 4, 4);
			delete pen;
		}
	}
	
	private: System::Void trainingToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (numSample == 0) return;

		int max_epoch = Convert::ToInt32(txtEpoch->Text);
		float lr = (float)Convert::ToDouble(txtLR->Text, System::Globalization::CultureInfo::InvariantCulture);
		float momentum = 0.9f;
		// Momentum kutusu varsa oradan alýn: Convert::ToDouble(txtMomentum->Text...

		// --- 1. NORMALÝZASYON PARAMETRELERÝNÝ HESAPLA ---
		if (InputMean != nullptr) { delete[] InputMean; delete[] InputStd; }
		if (TargetMean != nullptr) { delete[] TargetMean; delete[] TargetStd; }

		InputMean = new float[inputDim];
		InputStd = new float[inputDim];
		TargetMean = new float[1]; // Hedef genelde 1 boyutludur (Label veya Y deðeri)
		TargetStd = new float[1];

		// Girdi (Input) Z-Score
		Z_Score_Parameters(Samples, numSample, inputDim, InputMean, InputStd);

		// Hedef (Target) Z-Score (SADECE REGRESYON ÝÇÝN GEREKLÝ)
		if (isRegressionMode) {
			// Targets dizisi tek boyutlu olduðu için Z_Score fonksiyonunu kullanamayýz, manuel hesaplayalým
			float sum = 0, sumSq = 0;
			for (int i = 0; i < numSample; i++) sum += targets[i];
			TargetMean[0] = sum / numSample;

			for (int i = 0; i < numSample; i++) sumSq += pow(targets[i] - TargetMean[0], 2);
			TargetStd[0] = sqrt(sumSq / numSample);
			if (TargetStd[0] == 0) TargetStd[0] = 1.0f; // Sýfýra bölme hatasý önlemi
		}
		else {
			// Sýnýflandýrmada hedef normalize edilmez (-1 ve 1 kullanýlýr)
			TargetMean[0] = 0; TargetStd[0] = 1;
		}

		// --- 2. VERÝYÝ NORMALÝZE ET ---
		float* NormSamples = new float[numSample * inputDim];
		float* NormTargets = new float[numSample];

		for (int i = 0; i < numSample; i++) {
			// Girdi Normalizasyonu
			for (int j = 0; j < inputDim; j++) {
				if (InputStd[j] != 0)
					NormSamples[i * inputDim + j] = (Samples[i * inputDim + j] - InputMean[j]) / InputStd[j];
				else
					NormSamples[i * inputDim + j] = Samples[i * inputDim + j];
			}

			// Hedef Normalizasyonu (Sadece Regresyon)
			if (isRegressionMode) {
				NormTargets[i] = (targets[i] - TargetMean[0]) / TargetStd[0];
			}
			else {
				NormTargets[i] = targets[i]; // Sýnýflandýrmada dokunma
			}
		}

		// --- 3. EÐÝTÝM DÖNGÜSÜ ---
		if (errorChart != nullptr) errorChart->Series["MSE"]->Points->Clear();

		for (int epoch = 0; epoch < max_epoch; epoch++) {
			float totalErr = 0;
			for (int i = 0; i < numSample; i++) {
				float* input = &NormSamples[i * inputDim];
				float* targetArr = new float[1];
				targetArr[0] = NormTargets[i];

				// TrainNetwork fonksiyonu hata karesini döner
				totalErr += TrainNetwork(myNet, input, targetArr, lr, momentum, isRegressionMode);
				delete[] targetArr;
			}

			if (epoch % 100 == 0) { // Her 100 epochta bir grafik güncelle (Hýz için)
				float avgErr = totalErr / numSample;
				if (avgErr < 1000) errorChart->Series["MSE"]->Points->AddY(avgErr);
				if (epoch % 500 == 0) Application::DoEvents();
			}
		}

		delete[] NormSamples;
		delete[] NormTargets;
	}
};
}
