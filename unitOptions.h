#ifndef unitOptionsH
#define unitOptionsH
//------------------------------------------------------------------------------

//******************************************************************************
// INCLUDES
//******************************************************************************
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

#include <vcl.h>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Menus.hpp>
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
//******************************************************************************


//******************************************************************************
// CLASSES
//******************************************************************************
class TformOptions : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *editReceiptFilePath;
	TLabel *labelFilePath;
	TComboBox *comboBoxPrinters;
	TButton *btnSave;
	TButton *btnCancel;
	TButton *btnSetReceiptFolder;
	TFileOpenDialog *FileOpenDialog1;
	TLabel *Label2;
	TEdit *editReceiptFileName;
	TCheckBox *checkBoxReceiptNumberSufix;
	TLabel *labelReceiptFileName;
	TLabel *labelReceiptFilePath;
	TCheckBox *checkBoxReceiptDateSufix;
	TButton *btnAdditionalOptions;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btnCancelClick(TObject *Sender);
	void __fastcall btnSetReceiptFolderClick(TObject *Sender);
	void __fastcall editReceiptFileNameChange(TObject *Sender);
	void __fastcall checkBoxReceiptNumberSufixClick(TObject *Sender);
	void __fastcall btnSaveClick(TObject *Sender);
	void __fastcall btnAdditionalOptionsClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TformOptions(TComponent* Owner);

	void updateReceiptFileNameWitouthExt();
	AnsiString getReceiptFileNameWitouthExt();

	void updateDependentFormFields();
    void resetFormFields();
};
//******************************************************************************


//******************************************************************************
// GLOBAL VARS
//******************************************************************************
extern PACKAGE TformOptions *formOptions;
//******************************************************************************

//------------------------------------------------------------------------------
#endif
