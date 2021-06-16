#define NO_WIN32_LEAN_AND_MEAN
#include <vcl.h>
#pragma hdrstop
#include "main.h"
#include <String.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
a=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
  Label1->Caption="Сортировка";
  Timer1->Enabled = true;
char szPath1[256];
SHGetSpecialFolderPath(NULL, szPath1, CSIDL_DESKTOP, FALSE);
DriveComboBox1->Drive ='c';
DirectoryListBox1->Directory=szPath1;
   if(DirectoryExists(szPath1+String("\\video"))==0)
   MkDir(szPath1+String("\\video"));
   if(DirectoryExists(szPath1+String("\\text"))==0)
   MkDir(szPath1+String("\\text"));
   if(DirectoryExists(szPath1+String("\\other"))==0)
   MkDir(szPath1+String("\\other"));
   if(DirectoryExists(szPath1+String("\\images"))==0)
   MkDir(szPath1+String("\\images"));
   if(DirectoryExists(szPath1+String("\executable"))==0)
   MkDir(szPath1+String("\\executable"));
for(int i=0;i< FileListBox1->Count;i++)
{
String file=FileListBox1->Items->Strings[i];
int a=file.Length()-2;
bool b;
AnsiString q1 =szPath1+String("\\")+FileListBox1->Items->Strings[i];
AnsiString q2 =szPath1+String("\\text\\")+FileListBox1->Items->Strings[i];
AnsiString q3 = szPath1+String("\\images\\")+FileListBox1->Items->Strings[i];
AnsiString q4 = szPath1+String("\\video\\")+FileListBox1->Items->Strings[i];
AnsiString q5 =szPath1+String("\\executable\\")+FileListBox1->Items->Strings[i];
AnsiString q6 = szPath1+String("\\other\\")+FileListBox1->Items->Strings[i];
if(file.SubString(a,3)=="txt"||file.SubString(a,3)=="doc")
b=MoveFile(q1.c_str(),q2.c_str());
else if (file.SubString(a,3)=="jpg"||file.SubString(a,3)=="png")
b=MoveFile(q1.c_str(),q3.c_str());
else if (file.SubString(a,3)=="mp4"||file.SubString(a,3)=="avi"||file.SubString(a,3)=="mov")
b=MoveFile(q1.c_str(),q4.c_str());
else if (file.SubString(a,3)=="exe")
b=MoveFile(q1.c_str(),q5.c_str());
else
b=MoveFile(q1.c_str(),q6.c_str());
}
Timer1->Enabled = false;
Label1->Caption="Сортировка завершена!";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Exit1Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::About1Click(TObject *Sender)
{
 ShowMessage("Программа выполнена для учебных целей.\nПрограмма сортирует файлы рабочего стола по соответсвующим папкам.\nАвтор программы студент группы БИ-31 Белков А.И.");
}

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
if(a==0)
{
 Label1->Caption="Cортировка ";
  a=1;
}
else if(a==1)
{
  Label1->Caption="Cортировка .";
  a=2;
}
 else if(a==2)
{
  Label1->Caption="Cортировка . .";
  a=3;
}
else
{
  Label1->Caption="Cортировка . . .";
  a=0;
}
}
//---------------------------------------------------------------------------


