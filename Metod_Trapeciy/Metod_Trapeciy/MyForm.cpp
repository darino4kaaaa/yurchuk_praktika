#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // ��������� �� ������ �����
    YurchukDarina3::MyForm^ form = gcnew YurchukDarina3::MyForm();
    Application::Run(form);
}