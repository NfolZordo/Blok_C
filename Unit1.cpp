//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <ctime>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#pragma warning(disable : 4996)

TForm1 *Form1;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	 time_t now = time(0);
tm* ltm = localtime(&now);


 float h = 0, m = 0, s = 0,t,tb,thrTimer;
   h = StrToFloat (Edit1-> Text);
   m = StrToFloat (Edit2-> Text);
   s = StrToFloat (Edit3-> Text);
   tb = StrToFloat (Edit4-> Text);
if(RadioButton1->Checked == true) {
while (true)
{
time_t now = time(0);
tm* ltm = localtime(&now);
if (h <= ltm->tm_hour && m <= ltm->tm_min && s <=ltm->tm_sec) {
	 break;

	}
else { Sleep(1000); }
}
}
if(RadioButton2->Checked == true) {
t=time(0)%1000000;
thrTimer = t + s + m * 60 + h * 60 * 60;
            while (true)
			{
			t=time(0)%1000000;
				if (thrTimer <= t) {
					break;
				}
				else { Sleep(1000); }  }
}


HINSTANCE hDll; //���� �������� ������� �������
DWORD __stdcall (*BlockInput)(bool Status);
DWORD Result;
Memo1->Lines->Add("");
Memo1->Lines->Add("�������� ������� BlockInput()...");
hDll = LoadLibrary(_T("User32.dll"));
Memo1->Lines->Add("hDll = " + IntToHex(int(hDll), 8));
BlockInput = (DWORD __stdcall (*)(bool Status))GetProcAddress(hDll,
"BlockInput");
Memo1->Lines->Add("BlockInput = " + IntToHex(int(BlockInput), 8));
if(!BlockInput)
{
Memo1->Lines->Add("������!!!");
FreeLibrary(hDll);
return;
}
Memo1->Lines->Add("������� BlockInput(true)...");
Result = BlockInput(true);
Memo1->Lines->Add("Result = " + FloatToStr(Result));
if(Result)
{
Memo1->Lines->Add("����� �������� � ��� �������� �����, ���� ������ CTRL+ALT+DEL");
Memo1->Lines->Add("���� " + FloatToStr(tb) );
tb = tb*1000;
Sleep(tb);
}
else Memo1->Lines->Add("������!!!");
Memo1->Lines->Add("��������������� ��� ��� ����...");
BlockInput(false);
FreeLibrary(hDll);
Memo1->Lines->Add("������.");
}
//---------------------------------------------------------------------------


