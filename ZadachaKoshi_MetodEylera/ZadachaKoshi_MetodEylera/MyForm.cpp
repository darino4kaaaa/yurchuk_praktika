#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // ��������� �� ������ �����
    YurchukDarina4::MyForm^ form = gcnew YurchukDarina4::MyForm();
    Application::Run(form);
}
