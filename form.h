#pragma once
#include "functions.h"

namespace PasswordGenerator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for form
	/// </summary>
	public ref class form : public System::Windows::Forms::Form
	{
	public:
		form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ LengthBox;
	protected:
	private: System::Windows::Forms::TextBox^ PassBox;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->LengthBox = (gcnew System::Windows::Forms::TextBox());
			this->PassBox = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// LengthBox
			// 
			this->LengthBox->Location = System::Drawing::Point(148, 55);
			this->LengthBox->Name = L"LengthBox";
			this->LengthBox->Size = System::Drawing::Size(68, 22);
			this->LengthBox->TabIndex = 0;
			// 
			// PassBox
			// 
			this->PassBox->BackColor = System::Drawing::SystemColors::Window;
			this->PassBox->Location = System::Drawing::Point(148, 108);
			this->PassBox->Name = L"PassBox";
			this->PassBox->ReadOnly = true;
			this->PassBox->Size = System::Drawing::Size(141, 22);
			this->PassBox->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(148, 163);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(96, 57);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Generate";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &form::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(69, 58);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 17);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Length:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(69, 111);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Password:";
			// 
			// form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(389, 242);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->PassBox);
			this->Controls->Add(this->LengthBox);
			this->Name = L"form";
			this->Text = L"Password Generator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		srand(time(NULL));

		PassBox->Text = "";

		int PassLength;
		int choose;

		char pass[40];

		if (check(LengthBox->Text)) {
			PassLength = System::Convert::ToInt32(LengthBox->Text);

			if (PassLength > 35) {
				PassBox->Text = "Password is too long!";
			}
			else{
				for (int i = 0; i < PassLength; i++) {
					choose = rand() % 3;
					switch (choose) {
					case 0:
						pass[i] = (48 + rand() % 10);
						break;
					case 1:
						pass[i] = (65 + rand() % 26);
						break;
					case 2:
						pass[i] = (97 + rand() % 26);
						break;
					}
				}

				for (int i = 0; i < PassLength; i++) {
					PassBox->Text += System::Convert::ToChar(pass[i]);
				}
			}
		}
		else {
			PassBox->Text = "Incorrect input!";
		}
	}
};
}
