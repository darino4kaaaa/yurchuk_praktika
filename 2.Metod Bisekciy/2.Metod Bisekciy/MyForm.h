#pragma once

namespace YurchukDarina2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btnSolve;
	private: System::Windows::Forms::Button^ btnClear;
	private: System::Windows::Forms::TextBox^ textBoxA;
	private: System::Windows::Forms::TextBox^ textBoxB;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBoxTol;
	private: System::Windows::Forms::Label^ labelResult;
	private: System::Windows::Forms::Label^ label4;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->btnSolve = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->textBoxA = (gcnew System::Windows::Forms::TextBox());
			this->textBoxB = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBoxTol = (gcnew System::Windows::Forms::TextBox());
			this->labelResult = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnSolve
			// 
			this->btnSolve->Location = System::Drawing::Point(52, 216);
			this->btnSolve->Name = L"btnSolve";
			this->btnSolve->Size = System::Drawing::Size(75, 23);
			this->btnSolve->TabIndex = 0;
			this->btnSolve->Text = L"Розв\'язати";
			this->btnSolve->UseVisualStyleBackColor = true;
			this->btnSolve->Click += gcnew System::EventHandler(this, &MyForm::btnSolve_Click);
			// 
			// btnClear
			// 
			this->btnClear->Location = System::Drawing::Point(206, 216);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(75, 23);
			this->btnClear->TabIndex = 1;
			this->btnClear->Text = L"Очистити";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &MyForm::btnClear_Click);
			// 
			// textBoxA
			// 
			this->textBoxA->Location = System::Drawing::Point(187, 41);
			this->textBoxA->Name = L"textBoxA";
			this->textBoxA->Size = System::Drawing::Size(94, 20);
			this->textBoxA->TabIndex = 2;
			// 
			// textBoxB
			// 
			this->textBoxB->Location = System::Drawing::Point(187, 97);
			this->textBoxB->Name = L"textBoxB";
			this->textBoxB->Size = System::Drawing::Size(94, 20);
			this->textBoxB->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(49, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Нижня межа A :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(49, 154);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(95, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Введіть точність :";
			// 
			// textBoxTol
			// 
			this->textBoxTol->Location = System::Drawing::Point(187, 151);
			this->textBoxTol->Name = L"textBoxTol";
			this->textBoxTol->Size = System::Drawing::Size(94, 20);
			this->textBoxTol->TabIndex = 6;
			// 
			// labelResult
			// 
			this->labelResult->AutoSize = true;
			this->labelResult->Location = System::Drawing::Point(79, 280);
			this->labelResult->Name = L"labelResult";
			this->labelResult->Size = System::Drawing::Size(65, 13);
			this->labelResult->TabIndex = 7;
			this->labelResult->Text = L"Результат :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(47, 100);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(90, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Верхня межа B :";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(331, 337);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->labelResult);
			this->Controls->Add(this->textBoxTol);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxB);
			this->Controls->Add(this->textBoxA);
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->btnSolve);
			this->Name = L"MyForm";
			this->Text = L"Метод Половинного Ділення";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void btnSolve_Click(System::Object^ sender, System::EventArgs^ e) {
		double a, b, tol;

		// Спробуйте перетворити текст з текстових полів у числа
		if (!double::TryParse(textBoxA->Text, a) ||
			!double::TryParse(textBoxB->Text, b) ||
			!double::TryParse(textBoxTol->Text, tol)) {
			labelResult->Text = "Помилка: Введіть коректні числові значення.";
			return;
		}

		// Перевірка наявності кореня в інтервалі
		if (f(a) * f(b) >= 0)
		{
			labelResult->Text = "Кореня в інтервалі немає.";
			return;
		}

		// Метод бісекції для пошуку кореня
		double root = Bisection(a, b, tol);

		// Виведення результату
		labelResult->Text = "Корінь: x = " + root.ToString("F6");
	}

	private: System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
		// Очищуємо всі текстові поля
		textBoxA->Clear();
		textBoxB->Clear();
		textBoxTol->Clear();

		// Очищуємо мітку з результатом
		labelResult->Text = "";
	}

		   // Приклад функції, корінь якої шукаємо
		   double f(double x) {
			   // Ось наше рівняння: 2*x - log(x) - 7 = 0
			   return 2 * x - 1 * Math::Log(x) - 7;
		   }

		   // Метод бісекції
		   double Bisection(double a, double b, double tol) {
			   double c = 0; // Ініціалізація c
			   while ((b - a) >= tol) {
				   c = (a + b) / 2; // Середина інтервалу

				   // Перевіряємо, чи є c коренем
				   if (f(c) == 0.0) {
					   break;
				   }
				   // Визначаємо, в якій половині шукати далі
				   else if (f(c) * f(a) < 0) {
					   b = c;
				   }
				   else {
					   a = c;
				   }
			   }
			   return c; // Повертаємо наближений корінь
		   }
	};
}