#ifndef programDataBindingsH
#define programDataBindingsH
//------------------------------------------------------------------------------

//******************************************************************************
// INCLUDES
//******************************************************************************
#include <vcl.h>

#include "programDataSchema.h"
//******************************************************************************

//******************************************************************************
// CLASSES
//******************************************************************************
class TXMLBinding_programData
{
private:
    void InitFromFile();

	String fileName;
	_di_IXMLDocument XMLDocument;
	_di_IXMLprogramDataType programData;

public:		// User declarations
	TXMLBinding_programData();
	void setFieldOf_printerName();
	void setFieldOf_receiptFilePath();
	void setFieldOf_receiptFileName();
	void setFieldOf_receiptDateSufix();
	void setFieldOf_receiptNumberSufix();
	void setFieldOf_receiptNumber();
	void setFieldOf_messageFontSize();
	void setFieldOf_messageFontColor();
	void setFieldOf_OIBs();
	void setFieldOf_articleTypes();
	void setAllFieldsOf_programData();

	void update_printerName();
	void update_receiptFilePath();
	void update_receiptFileName();
	void update_receiptDateSufix();
	void update_receiptNumberSufix();
	void update_receiptNumber();
	void update_messageFontSize();
	void update_messageFontColor();
	void update_OIBs();
	void update_articleTypes();
	void updateAll_programData();

	bool openFromFile(String fileName);
	void saveToFile(String fileName);
};
//******************************************************************************

//------------------------------------------------------------------------------
#endif

