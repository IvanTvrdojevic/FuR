
// ******************************************************************************************************************* //
//                                                                                                                   
//                                                 XML Data Binding                                                  
//                                                                                                                   
//         Generated on: 6.1.2022. 23:00:01                                                                          
//       Generated from: C:\Users\User\Desktop\All\Programiranje\Racun al ovaj nemoj obrisat\Res\receiptSchema.xml   
//   Settings stored in: C:\Users\User\Desktop\All\Programiranje\Racun al ovaj nemoj obrisat\Res\receiptSchema.xdb   
//                                                                                                                   
// ******************************************************************************************************************* //

#include <System.hpp>
#pragma hdrstop

#include "receiptSchema.h"


// Global Functions 

_di_IXMLreceiptType __fastcall Getreceipt(Xml::Xmlintf::_di_IXMLDocument Doc)
{
  return (_di_IXMLreceiptType) Doc->GetDocBinding("receipt", __classid(TXMLreceiptType), TargetNamespace);
};

_di_IXMLreceiptType __fastcall Getreceipt(Xml::Xmldoc::TXMLDocument *Doc)
{
  Xml::Xmlintf::_di_IXMLDocument DocIntf;
  Doc->GetInterface(DocIntf);
  return Getreceipt(DocIntf);
};

_di_IXMLreceiptType __fastcall Loadreceipt(const System::UnicodeString& FileName)
{
  return (_di_IXMLreceiptType) Xml::Xmldoc::LoadXMLDocument(FileName)->GetDocBinding("receipt", __classid(TXMLreceiptType), TargetNamespace);
};

_di_IXMLreceiptType __fastcall  Newreceipt()
{
  return (_di_IXMLreceiptType) Xml::Xmldoc::NewXMLDocument()->GetDocBinding("receipt", __classid(TXMLreceiptType), TargetNamespace);
};

// TXMLreceiptType 

int __fastcall TXMLreceiptType::Get_number()
{
  return GetChildNodes()->Nodes[System::UnicodeString("number")]->NodeValue.operator int();
};

void __fastcall TXMLreceiptType::Set_number(int Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("number")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLreceiptType::Get_serviceDate()
{
  return GetChildNodes()->Nodes[System::UnicodeString("serviceDate")]->Text;
};

void __fastcall TXMLreceiptType::Set_serviceDate(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("serviceDate")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLreceiptType::Get_issueDate()
{
  return GetChildNodes()->Nodes[System::UnicodeString("issueDate")]->Text;
};

void __fastcall TXMLreceiptType::Set_issueDate(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("issueDate")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLreceiptType::Get_issueTime()
{
  return GetChildNodes()->Nodes[System::UnicodeString("issueTime")]->Text;
};

void __fastcall TXMLreceiptType::Set_issueTime(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("issueTime")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLreceiptType::Get_arrivalDate()
{
  return GetChildNodes()->Nodes[System::UnicodeString("arrivalDate")]->Text;
};

void __fastcall TXMLreceiptType::Set_arrivalDate(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("arrivalDate")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLreceiptType::Get_card()
{
  return GetChildNodes()->Nodes[System::UnicodeString("card")]->Text;
};

void __fastcall TXMLreceiptType::Set_card(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("card")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLreceiptType::Get_OIB()
{
  return GetChildNodes()->Nodes[System::UnicodeString("OIB")]->Text;
};

void __fastcall TXMLreceiptType::Set_OIB(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("OIB")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLreceiptType::Get_articleID()
{
  return GetChildNodes()->Nodes[System::UnicodeString("articleID")]->Text;
};

void __fastcall TXMLreceiptType::Set_articleID(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("articleID")]->NodeValue = Value;
};

int __fastcall TXMLreceiptType::Get_articleType()
{
  return GetChildNodes()->Nodes[System::UnicodeString("articleType")]->NodeValue.operator int();
};

void __fastcall TXMLreceiptType::Set_articleType(int Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("articleType")]->NodeValue = Value;
};

double __fastcall TXMLreceiptType::Get_quantity()
{
  return XmlStrToFloatExt(GetChildNodes()->Nodes[System::UnicodeString("quantity")]->Text);
};

void __fastcall TXMLreceiptType::Set_quantity(double Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("quantity")]->NodeValue = Value;
};

int __fastcall TXMLreceiptType::Get_measureUnit()
{
  return GetChildNodes()->Nodes[System::UnicodeString("measureUnit")]->NodeValue.operator int();
};

void __fastcall TXMLreceiptType::Set_measureUnit(int Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("measureUnit")]->NodeValue = Value;
};

double __fastcall TXMLreceiptType::Get_wholesalePrice()
{
  return XmlStrToFloatExt(GetChildNodes()->Nodes[System::UnicodeString("wholesalePrice")]->Text);
};

void __fastcall TXMLreceiptType::Set_wholesalePrice(double Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("wholesalePrice")]->NodeValue = Value;
};

double __fastcall TXMLreceiptType::Get_wholesaleDiscount()
{
  return XmlStrToFloatExt(GetChildNodes()->Nodes[System::UnicodeString("wholesaleDiscount")]->Text);
};

void __fastcall TXMLreceiptType::Set_wholesaleDiscount(double Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("wholesaleDiscount")]->NodeValue = Value;
};

double __fastcall TXMLreceiptType::Get_pdv()
{
  return XmlStrToFloatExt(GetChildNodes()->Nodes[System::UnicodeString("pdv")]->Text);
};

void __fastcall TXMLreceiptType::Set_pdv(double Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("pdv")]->NodeValue = Value;
};
