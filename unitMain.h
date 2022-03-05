#ifndef unitMainH
#define unitMainH
//------------------------------------------------------------------------------

//******************************************************************************
// INCLUDES
//******************************************************************************
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.WinXPickers.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.Samples.Spin.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ActnColorMaps.hpp>
#include <Vcl.ActnMan.hpp>
#include <Vcl.Graphics.hpp>
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Xml.Win.msxmldom.hpp>
#include <Xml.XmlTransform.hpp>
#include <Vcl.Grids.hpp>

#include "receiptSchema.h"
#include <Xml.omnixmldom.hpp>
#include <Xml.adomxmldom.hpp>
//******************************************************************************


//******************************************************************************
// CLASSES
//******************************************************************************
class TformMain : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TLabel *infoLabel;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label7;
	TEdit *editCard;
	TDatePicker *datePickerIssueDate;
	TTimePicker *timePickerIssueTime;
	TDatePicker *datePickerArrivalDate;
	TDatePicker *datePickerServiceDate;
	TGroupBox *GroupBox2;
	TLabel *Label19;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TEdit *editArticleID;
	TEdit *editQuantity;
	TEdit *editWholesalePrice;
	TLabel *labelNoPdv;
	TGroupBox *GroupBox3;
	TButton *buttonOpen;
	TButton *buttonSave;
	TButton *buttonNew;
	TGroupBox *GroupBox4;
	TButton *buttonPrint;
	TSpinEdit *spinEditCopies;
	TLabel *Label11;
	TLabel *Label23;
	TSpinEdit *spinEditReceiptNumber;
	TLabel *Label24;
	TCheckBox *checkBoxTime;
	TTimer *Timer;
	TComboBox *comboBoxArticleTypes;
	TComboBox *comboBoxMeasureUnit;
	TButton *Button1;
	TPanel *Panel1;
	TImage *imageFirstPage;
	TMemo *Memo1;
	TButton *Button3;
	TFontDialog *fontDlgPrint;
	TXMLDocument *XMLDocProgramData;
	TXMLDocument *XMLDocReceipt;
	TFileOpenDialog *FileOpenDialog1;
	TComboBox *comboBoxOIBs;
	TLabel *Label25;
	TCheckBox *checkBoxIssueDate;
	TCheckBox *checkBoxArrivalDate;
	TStringGrid *StringGrid1;
	TGroupBox *GroupBox5;
	TLabel *Label17;
	TLabel *Label18;
	TEdit *editWholesaleDiscount;
	TEdit *editPdv;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *labelTotalSum;
	TLabel *labelOnlyPdv;
	TLabel *labelNoPdv1;
	TButton *Button2;
	TButton *Button4;
	TLabel *labelPdvkurco;
	void __fastcall editPdvChange(TObject *Sender);
	void __fastcall editQuantityChange(TObject *Sender);
	void __fastcall editWholesalePriceChange(TObject *Sender);
	void __fastcall buttonNewClick(TObject *Sender);
	void __fastcall TimerTimer(TObject *Sender);
	void __fastcall checkBoxTimeClick(TObject *Sender);
	void __fastcall buttonSaveClick(TObject *Sender);
	void __fastcall buttonPrintClick(TObject *Sender);
	void __fastcall datePickerServiceDateChange(TObject *Sender);
	void __fastcall datePickerIssueDateChange(TObject *Sender);
	void __fastcall datePickerArrivalDateChange(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall editCardChange(TObject *Sender);
	void __fastcall buttonOpenClick(TObject *Sender);
	void __fastcall checkBoxIssueDateClick(TObject *Sender);
	void __fastcall checkBoxArrivalDateClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall editArticleIDChange(TObject *Sender);
	void __fastcall comboBoxMeasureUnitChange(TObject *Sender);
	void __fastcall comboBoxArticleTypesChange(TObject *Sender);

private:	// User declarations
	bool validatedDate = true;
	bool validatedOib = true;
	bool validatedCard = true;
	bool validatedFloat = true;
	bool skipValidate = false;
	float quantity = 0.;
	float pdv = 0.;
	float noPdv = 0.;
	float vpc = 0.;
	int pgWidth = 0;
	int pgHeight= 0;

	void validate(TEdit *edit, float *var);
	void validate(TComboBox *combo);
	void validateDate();
	void validateDateColor(TDatePicker* checkDt);
	void validateDateColor();
	void validateCard();
	void validateOib();
	bool validateAll();
	void calculate();
	void printReceipt();
	void printToFile();
	void printWithPrinter();
	bool checkEmpty();
	void updateFieldsFromReceipt(_di_IXMLreceiptType receipt);
	void openReceipt();
	void saveReceiptToFile(AnsiString fileName);
	void saveReceipt();

public:		// User declarations
	wchar_t outFileName[800];
	bool receiptSaved = false;
	bool enableDbgOut = false;

	__fastcall TformMain(TComponent* Owner);
	void makeNew();
	void doThePrint();
	AnsiString getReceiptFileName();
};
//******************************************************************************


//******************************************************************************
// GLOBAL VARS
//******************************************************************************
extern PACKAGE TformMain *formMain;
//******************************************************************************

//------------------------------------------------------------------------------
#endif

