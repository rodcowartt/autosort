//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <FileCtrl.hpp>
#include <Menus.hpp>
#include <Buttons.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdHTTPServer.hpp>
#include <IdTCPServer.hpp>
#include <IdHTTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdAntiFreeze.hpp>
#include <IdAntiFreezeBase.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TFileListBox *FileListBox1;
        TDriveComboBox *DriveComboBox1;
        TDirectoryListBox *DirectoryListBox1;
        TButton *Button5;
        TIdHTTP *IdHTTP1;
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *Exit1;
        TMenuItem *Help1;
        TMenuItem *About1;
        TIdAntiFreeze *IdAntiFreeze1;
        TLabel *Label1;
        TTimer *Timer1;
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall About1Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:
        int a;	// User declarations
        TSearchRec Folder;
        char Katalog [100][100];
        int ScrollSearch;
        int MB;
        int TestNumb[100];
        int numEl;
        AnsiString DirectorySt;
        AnsiString DirectoryCo;
        __fastcall TForm1(TComponent* Owner);
};

extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
