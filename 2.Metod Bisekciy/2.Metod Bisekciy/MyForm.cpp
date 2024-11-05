#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Создание и запуск формы
    YurchukDarina2::MyForm^ form = gcnew YurchukDarina2::MyForm();
    Application::Run(form);
}