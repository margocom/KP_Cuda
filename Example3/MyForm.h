
#include<windows.h>
#include <chrono>
#include <string>
#include <stdio.h>
#include <iostream>
#include <omp.h>

using namespace std::chrono;
struct img
{
	int width;
	int height;
	unsigned* image;
};

namespace Example3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ calculateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::TrackBar^ trackBar2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->calculateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1185, 33);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->openToolStripMenuItem,
					this->saveToolStripMenuItem, this->calculateToolStripMenuItem, this->toolStripMenuItem2, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(69, 29);
			this->fileToolStripMenuItem->Text = L"Файл";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(289, 34);
			this->openToolStripMenuItem->Text = L"Открыть";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(289, 34);
			this->saveToolStripMenuItem->Text = L"Сохранить";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveToolStripMenuItem_Click);
			// 
			// calculateToolStripMenuItem
			// 
			this->calculateToolStripMenuItem->Name = L"calculateToolStripMenuItem";
			this->calculateToolStripMenuItem->Size = System::Drawing::Size(289, 34);
			this->calculateToolStripMenuItem->Text = L"Обработать";
			this->calculateToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::calculateToolStripMenuItem_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(289, 34);
			this->toolStripMenuItem2->Text = L"_________________________";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(289, 34);
			this->exitToolStripMenuItem->Text = L"Выйти";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(13, 143);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(554, 546);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox2->Location = System::Drawing::Point(589, 143);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(564, 546);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1085, 78);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"0 мс";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(27, 40);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(144, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Выбор алгоритма";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Последовательный алгоритм", L"Параллельный алгоритм (OpenMP)",
					L"Параллельный алгоритм (Cuda)"
			});
			this->comboBox1->Location = System::Drawing::Point(31, 75);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(373, 28);
			this->comboBox1->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(920, 78);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(159, 20);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Время выполнения:";
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(418, 69);
			this->trackBar1->Maximum = 255;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(234, 69);
			this->trackBar1->TabIndex = 7;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(658, 69);
			this->trackBar2->Maximum = 255;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(234, 69);
			this->trackBar2->TabIndex = 8;
			this->trackBar2->Value = 255;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar2_Scroll);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(434, 43);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(47, 20);
			this->label4->TabIndex = 9;
			this->label4->Text = L"gmin:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(670, 43);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(51, 20);
			this->label5->TabIndex = 10;
			this->label5->Text = L"gmax:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1185, 765);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->trackBar2);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"MyForm";
			this->Text = L"Контрастирование изображения";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		openFileDialog1->Filter = "Формат (png, jpg, jpeg) | * .jpg; *.png; *.jpeg";
			openFileDialog1->Title = "Выберите изображение";
		if (openFileDialog1->ShowDialog() ==
			System::Windows::Forms::DialogResult::OK) {
			pictureBox1->Image =
				Bitmap::FromFile(openFileDialog1->FileName);
		}
	}
private: System::Void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	saveFileDialog1->Title = "Сохраните изображение";
	saveFileDialog1->Filter = "Формат (*.png, *.jpg, * .jpeg) | *.jpg; *.png; *.jpeg";
		if (saveFileDialog1->ShowDialog() ==
			System::Windows::Forms::DialogResult::OK)
		{
			
			if (pictureBox1->Image) {
				Bitmap^ bitmap = gcnew Bitmap(pictureBox2 -> Image);
				bitmap->Save(saveFileDialog1->FileName);
			}
			else {
				MessageBox::Show(L"Изображения для сохранения нет", L"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}

}

private: System::Void Consistently() {
		
	if (pictureBox1->Image) {

		struct img* image = new img();
		image->width = pictureBox1->Image->Width;
		image->height = pictureBox1->Image->Height;
		image->image = new unsigned[image->width * image->height];
		Bitmap^ bitmap = gcnew Bitmap(pictureBox1->Image);
		double fmax = 0 / 255.0f;
		double fmin = 100 / 255.0f;
		double gmax = trackBar2->Value / 255.0f;
		double gmin = trackBar1->Value / 255.0f;

		auto start = std::chrono::steady_clock::now();

		for (int i = 0; i < image->width; i++)
		{
			for (int j = 0; j < image->height; j++)
			{
				if (!(i == 0 || j == 0 || i == image->width - 1 || j == image->height - 1)) {
					double brightness = bitmap->GetPixel(i, j).GetBrightness();
					if (fmax < brightness)
						fmax = brightness;
					if (fmin > brightness)
						fmin = brightness;
				}
			}
		}

		double a = (gmax - gmin) / (fmax - fmin);
		double b = (gmin * fmax - gmax * fmin) / (fmax - fmin);
		// Заполнение структуры img с изображением

		for (int j = 0; j < image->height; j++)
		{
			for (int i = 0; i < image->width; i++)
			{
				image->image[j * image->width + i] = bitmap->GetPixel(i, j).ToArgb();
								
				unsigned pixel = image->image[j * image->width + i];
				unsigned red = (pixel & 0x00FF0000) >> 0x10;
				unsigned green = (pixel & 0x0000FF00) >> 0x8;
				unsigned blue = pixel & 0x000000FF;

				unsigned enhancedRed = (a * red + b);
				if (enhancedRed > 255)
					enhancedRed = 255;
				unsigned enhancedGreen = (a * green + b);
				if (enhancedGreen > 255)
					enhancedGreen = 255;
				unsigned enhancedBlue = (a * blue + b);
				if (enhancedBlue > 255)
					enhancedBlue = 255;

				image->image[j * image->width + i] = 0xFF000000 | (enhancedRed << 0x10) |
					(enhancedGreen << 0x8) | enhancedBlue;


			}
		}

		// Создание нового изображения с контрастированными пикселями
		bitmap = gcnew Bitmap(image->width, image->height);

		for (int j = 0; j < image->height; j++)
		{
			for (int i = 0; i < image->width; i++)
			{
				bitmap->SetPixel(i, j, Color::FromArgb(image->image[j * image->width + i]));
			}
		}
		auto end = std::chrono::steady_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		System::String^ s = duration.count().ToString();
		label1->Text = s + " мс";
		pictureBox2->Image = bitmap;
	}
	else {
		MessageBox::Show(L"Изображение не добавлено", L"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}



private: System::Void OpenMP() {

	if (pictureBox1->Image) {
		struct img* image = new img();
		image->width = pictureBox1->Image->Width;
		image->height = pictureBox1->Image->Height;
		image->image = new unsigned[image->width * image->height];
		Bitmap^ bitmap = gcnew Bitmap(pictureBox1->Image);
		double fmax = 0 / 255.0f;
		double fmin = 100 / 255.0f;
		double gmax = trackBar2->Value / 255.0f;
		double gmin = trackBar1->Value / 255.0f;

		auto start = std::chrono::steady_clock::now();
		
#pragma omp parallel num_threads(8) 
		{
#pragma omp for 
			for (int i = 0; i < image->width; i++)
			{
				for (int j = 0; j < image->height; j++)
				{
					if (!(i == 0 || j == 0 || i == image->width - 1 || j == image->height - 1)) {
						double brightness = bitmap->GetPixel(i, j).GetBrightness();
						if (fmax < brightness)
							fmax = brightness;
						if (fmin > brightness)
							fmin = brightness;
					}
				}
			}

			double a = (gmax - gmin) / (fmax - fmin);
			double b = (gmin * fmax - gmax * fmin) / (fmax - fmin);
			// Заполнение структуры img с изображением
#pragma omp for 
			for (int j = 0; j < image->height; j++)
			{
				for (int i = 0; i < image->width; i++)
				{
					image->image[j * image->width + i] = bitmap->GetPixel(i, j).ToArgb();

					
					unsigned pixel = image->image[j * image->width + i];
					unsigned red = (pixel & 0x00FF0000) >> 0x10;
					unsigned green = (pixel & 0x0000FF00) >> 0x8;
					unsigned blue = pixel & 0x000000FF;

					unsigned enhancedRed = (a * red + b);
					if (enhancedRed > 255)
						enhancedRed = 255;
					unsigned enhancedGreen = (a * green + b);
					if (enhancedGreen > 255)
						enhancedGreen = 255;
					unsigned enhancedBlue = (a * blue + b);
					if (enhancedBlue > 255)
						enhancedBlue = 255;

					image->image[j * image->width + i] = 0xFF000000 | (enhancedRed << 0x10) |
						(enhancedGreen << 0x8) | enhancedBlue;


				}
			}


			// Создание нового изображения с контрастированными пикселями
			bitmap = gcnew Bitmap(image->width, image->height);

#pragma omp for 
			for (int j = 0; j < image->height; j++)
			{
				for (int i = 0; i < image->width; i++)
				{
					bitmap->SetPixel(i, j, Color::FromArgb(image->image[j * image->width + i]));
				}
			}
		}
		auto end = std::chrono::steady_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		System::String^ s = duration.count().ToString();
		label1->Text = s + " мс";
		pictureBox2->Image = bitmap;
		}
	else {
		MessageBox::Show(L"Изображение не добавлено", L"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	
}


private: System::Void Cuda() {

	if (pictureBox1->Image) {
	struct img* image = new img();
	image->width = pictureBox1->Image->Width;
	image->height = pictureBox1->Image->Height;
	image->image = new unsigned[image->width * image->height];
	Bitmap^ bitmap = gcnew Bitmap(pictureBox1->Image);
		double fmax = 0 / 255.0f;
		double fmin = 100 / 255.0f;

		auto start = std::chrono::steady_clock::now();

		for (int i = 0; i < image->width; i++)
		{
			for (int j = 0; j < image->height; j++)
			{
				if (!(i == 0 || j == 0 || i == image->width - 1 || j == image->height - 1)) {
					double brightness = bitmap->GetPixel(i, j).GetBrightness();
					if (fmax < brightness)
						fmax = brightness;
					if (fmin > brightness)
						fmin = brightness;
				}
			}
		}

		double gmax = trackBar2->Value / 255.0f;
		double gmin = trackBar1->Value / 255.0f;
		double a = (gmax - gmin) / (fmax - fmin);
		double b = (gmin * fmax - gmax * fmin) / (fmax - fmin);

		for (int j = 0; j < image->height; j++)
		{
			for (int i = 0; i < image->width; i++)
			{
				image->image[j * image->width + i] = bitmap->GetPixel(i,
					j).ToArgb();
			}
		}
		// Получаем доступ к функции из DLL библиотеки
		HINSTANCE hGetProcIDDLL =
			LoadLibrary(L"KP_Cuda.dll");
		if (!hGetProcIDDLL)
		{
			throw gcnew Exception();
		}
		typedef int(__stdcall* function)(void*, double, double);
		function calc = (function)
			GetProcAddress(hGetProcIDDLL, "calculate");
		if (!calc)
		{
			throw gcnew Exception();
		}
		// Выполняем функцию из DLL библиотеки
		image = (img*)calc((void*)image, a, b);
		// Формируем результат для отображения в CLR компоненте



		bitmap = gcnew Bitmap(image->width, image->height);
		for (int j = 0; j < image->height; j++)
		{
			for (int i = 0; i < image->width; i++)
			{
				bitmap->SetPixel(i, j,
					Color::FromArgb(image->image[j * image->width +
						i]));
			}
		}


		auto end = std::chrono::steady_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		System::String^ s = duration.count().ToString();
		label1->Text = s + " мс";
		pictureBox2->Image = bitmap;
	}
	else {
		MessageBox::Show(L"Изображение не добавлено", L"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

}

private: System::Void calculateToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	// Для начала подготовим наше входное изображение для 
	if (comboBox1->SelectedItem == "Последовательный алгоритм") {
		Consistently();
	}
	else if (comboBox1->SelectedItem == "Параллельный алгоритм (OpenMP)") {
		OpenMP();
	}
	else if (comboBox1->SelectedItem == "Параллельный алгоритм (Cuda)") {
		Cuda();
	}
	else {
		MessageBox::Show(L"Алгоритм не выбран", L"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}
private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();

}

private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
	label4->Text = "gmin: " + trackBar1->Value;
}
private: System::Void trackBar2_Scroll(System::Object^ sender, System::EventArgs^ e) {
	label5->Text = "gmax: " + trackBar2->Value;
}
};
}
