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
	TButton *buttonCloseAndFix;
	TButton *Button2;
	TLabel *labelWarning;
	TGroupBox *groupBoxConfig;
	TMemo *memoXMLFile;
	TButton *Button3;
	TButton *Button4;
	TLabel *labelPathToFile;
	TButton *Button5;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall buttonCloseAndFixClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall groupBoxConfigMouseEnter(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TformCorruptSettings(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformCorruptSettings *formCorruptSettings;
//---------------------------------------------------------------------------
#endif
