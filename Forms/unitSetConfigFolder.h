#ifndef unitSetConfigFolderH
#define unitSetConfigFolderH
//------------------------------------------------------------------------------

//******************************************************************************
// INCLUDES
//******************************************************************************
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Registry.hpp>
//******************************************************************************


//******************************************************************************
// CLASSES
//******************************************************************************
class TformSetConfigFolder : public TForm
{
__published:	// IDE-managed Components
	TButton *Button3;
	TFileOpenDialog *FileOpenDialog1;
	TButton *buttonOkay;
	TLabel *Label1;
	TEdit *editFolder;
	TEdit *mainCard;
	TLabel *Label2;
	TLabel *Label3;
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall buttonOkayClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
    void setupInitialFields();
public:		// User declarations
	__fastcall TformSetConfigFolder(TComponent* Owner);
	void readProgramDataPath();
	AnsiString getProgramDataFileName();
	TRegistry *reg;
	AnsiString programDataPath;
};
//******************************************************************************


//******************************************************************************
// GLOBAL VARS
//******************************************************************************
extern PACKAGE TformSetConfigFolder *formSetConfigFolder;
//******************************************************************************

//------------------------------------------------------------------------------
#endif
