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

#include <Xml.omnixmldom.hpp>
#include <Xml.adomxmldom.hpp>

#include "receiptSchema.h"
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
	TButton *buttonClose;
	TPanel *Panel1;
	TImage *imageFirstPage;
	TMemo *Memo1;
	TButton *buttonOptions;
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
	TLabel *labelTotalSumHRK;
	TLabel *labelOnlyPdv;
	TLabel *labelNoPdv1;
	TButton *btnAddNewArticle;
	TButton *btnDeleteArticle;
	TLabel *labelPdvkurco;
	TEdit *editFixExRate;
	TLabel *Label26;
	TFontDialog *fontDlgPrintLabels;
	TLabel *Label28;
	TLabel *labelTotalSum;
	TGroupBox *GroupBox6;
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
	void __fastcall buttonCloseClick(TObject *Sender);
	void __fastcall buttonOptionsClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall editCardChange(TObject *Sender);
	void __fastcall buttonOpenClick(TObject *Sender);
	void __fastcall checkBoxIssueDateClick(TObject *Sender);
	void __fastcall checkBoxArrivalDateClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall editArticleIDChange(TObject *Sender);
	void __fastcall comboBoxMeasureUnitChange(TObject *Sender);
	void __fastcall comboBoxArticleTypesChange(TObject *Sender);
	void __fastcall btnAddNewArticleClick(TObject *Sender);
	void __fastcall StringGrid1Click(TObject *Sender);
	void __fastcall btnDeleteArticleClick(TObject *Sender);
	void __fastcall GroupBox6MouseEnter(TObject *Sender);
	void __fastcall spinEditReceiptNumberChange(TObject *Sender);





private:	// User declarations
	float defQuantity = 0;
	float defWholesalePrice = 0;
	float defWholesaleDiscount = 0;
	float defPdv = 5;
	TDateTime defDate = TDateTime(2021, 1, 1);
	int defMeasureUnit = 0;

	bool validatedDate = true;
	bool validatedOib = true;
	bool validatedCard = true;
	bool validatedFloat = true;
	bool skipValidate = false;
	float quantity = defQuantity;
	float pdv = defPdv;
	float noPdv = defPdv;
	float vpc = defWholesalePrice;
	int pgWidth = 0;
	int pgHeight= 0;
    int currRow = 0;

	void validate(TEdit *edit, float *var);
	void validate(TComboBox *combo);
	void validateDate();
	void validateDateColor(TDatePicker* checkDt);
	void validateDateColor();
	void validateCard();
	void validateOib();
	bool validateAll();
	void calculate();
    void printLine();
	void printReceipt();
	void printToFile();
	void printWithPrinter();
	bool checkEmpty();
	void saveFormProgramDataFields();
	void updateFieldsFromReceipt(_di_IXMLreceiptType receipt);
	void openReceipt();
	void saveReceipt();
	void updateFromGrid(int row);

public:		// User declarations
	TCHAR outFileName[800];
	bool receiptSaved = false;
	bool enableDbgOut = false;

	__fastcall TformMain(TComponent* Owner);
	void makeNew();
	void doThePrint();
	String getReceiptFileName();
};
//******************************************************************************


//******************************************************************************
// GLOBAL VARS
//******************************************************************************
extern PACKAGE TformMain *formMain;
//******************************************************************************

//------------------------------------------------------------------------------
#endif

