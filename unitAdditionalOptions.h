#ifndef unitAdditionalOptionsH
#define unitAdditionalOptionsH
//------------------------------------------------------------------------------

//******************************************************************************
// INCLUDES
//******************************************************************************
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Samples.Spin.hpp>
//******************************************************************************


//******************************************************************************
// CLASSES
//******************************************************************************
class TformAdditionalOptions : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TSpinEdit *spinEditMessageFontSize;
	TColorListBox *colorListBoxMessageFontColor;
	TButton *btnSave;
	TButton *btnCancel;
	void __fastcall btnCancelClick(TObject *Sender);
	void __fastcall btnSaveClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TformAdditionalOptions(TComponent* Owner);
    void resetFormFields();
};
//******************************************************************************


//******************************************************************************
// GLOBAL VARS
//******************************************************************************
extern PACKAGE TformAdditionalOptions *formAdditionalOptions;
//******************************************************************************

//------------------------------------------------------------------------------
#endif
