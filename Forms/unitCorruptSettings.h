//---------------------------------------------------------------------------

#ifndef unitCorruptSettingsH
#define unitCorruptSettingsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TformCorruptSettings : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TLabel *labelWarning;
	TGroupBox *GroupBox1;
	TMemo *Memo1;
	TButton *Button3;
	TButton *Button4;
	TLabel *Label1;
	TButton *Button5;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TformCorruptSettings(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformCorruptSettings *formCorruptSettings;
//---------------------------------------------------------------------------
#endif
