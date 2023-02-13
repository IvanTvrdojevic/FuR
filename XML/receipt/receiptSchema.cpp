
// *************************************************************************************** //
//                                                                                       
//                                   XML Data Binding                                    
//                                                                                       
//         Generated on: 2/13/2023 7:02:01 AM                                            
//       Generated from: E:\00_WORK\99_RAD\00_CPP\00_FUR\XML\receipt\receiptSchema.xml   
//   Settings stored in: E:\00_WORK\99_RAD\00_CPP\00_FUR\XML\receipt\receiptSchema.xdb   
//                                                                                       
// *************************************************************************************** //

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

void __fastcall TXMLreceiptType::AfterConstruction(void)
{
  RegisterChildNode(System::UnicodeString("articles"), __classid(TXMLarticlesType));
  Xml::Xmldoc::TXMLNode::AfterConstruction();
};

double __fastcall TXMLreceiptType::Get_version()
{
  return XmlStrToFloatExt(GetAttributeNodes()->Nodes[System::UnicodeString("version")]->Text);
};

void __fastcall TXMLreceiptType::Set_version(double Value)
{
  SetAttribute(System::UnicodeString("version"), Value);
};

int __fastcall TXMLreceiptType::Get_number()
{
  return GetChildNodes()->Nodes[System::UnicodeString("number")]->NodeValue.operator int();
};

void __fastcall TXMLreceiptType::Set_number(int Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("number")]->NodeValue = Value;
};

double __fastcall TXMLreceiptType::Get_serviceDate()
{
  return XmlStrToFloatExt(GetChildNodes()->Nodes[System::UnicodeString("serviceDate")]->Text);
};

void __fastcall TXMLreceiptType::Set_serviceDate(double Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("serviceDate")]->NodeValue = Value;
};

double __fastcall TXMLreceiptType::Get_issueDate()
{
  return XmlStrToFloatExt(GetChildNodes()->Nodes[System::UnicodeString("issueDate")]->Text);
};

void __fastcall TXMLreceiptType::Set_issueDate(double Value)
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

double __fastcall TXMLreceiptType::Get_arrivalDate()
{
  return XmlStrToFloatExt(GetChildNodes()->Nodes[System::UnicodeString("arrivalDate")]->Text);
};

void __fastcall TXMLreceiptType::Set_arrivalDate(double Value)
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

System::UnicodeString __fastcall TXMLreceiptType::Get_articleType()
{
  return GetChildNodes()->Nodes[System::UnicodeString("articleType")]->Text;
};

void __fastcall TXMLreceiptType::Set_articleType(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("articleType")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLreceiptType::Get_quantity()
{
  return GetChildNodes()->Nodes[System::UnicodeString("quantity")]->Text;
};

void __fastcall TXMLreceiptType::Set_quantity(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("quantity")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLreceiptType::Get_measureUnit()
{
  return GetChildNodes()->Nodes[System::UnicodeString("measureUnit")]->Text;
};

void __fastcall TXMLreceiptType::Set_measureUnit(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("measureUnit")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLreceiptType::Get_wholesalePrice()
{
  return GetChildNodes()->Nodes[System::UnicodeString("wholesalePrice")]->Text;
};

void __fastcall TXMLreceiptType::Set_wholesalePrice(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("wholesalePrice")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLreceiptType::Get_wholesaleDiscount()
{
  return GetChildNodes()->Nodes[System::UnicodeString("wholesaleDiscount")]->Text;
};

void __fastcall TXMLreceiptType::Set_wholesaleDiscount(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("wholesaleDiscount")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLreceiptType::Get_pdv()
{
  return GetChildNodes()->Nodes[System::UnicodeString("pdv")]->Text;
};

void __fastcall TXMLreceiptType::Set_pdv(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("pdv")]->NodeValue = Value;
};

_di_IXMLarticlesType __fastcall TXMLreceiptType::Get_articles()
{
  return (_di_IXMLarticlesType) GetChildNodes()->Nodes[System::UnicodeString("articles")];
};

// TXMLarticlesType 

void __fastcall TXMLarticlesType::AfterConstruction(void)
{
  RegisterChildNode(System::UnicodeString("article"), __classid(TXMLarticleType));
  ItemTag = "article";
  ItemInterface = __uuidof(IXMLarticleType);
  Xml::Xmldoc::TXMLNodeCollection::AfterConstruction();
};

_di_IXMLarticleType __fastcall TXMLarticlesType::Get_article(int Index)
{
  return (_di_IXMLarticleType) List->Nodes[Index];
};

_di_IXMLarticleType __fastcall TXMLarticlesType::Add()
{
  return (_di_IXMLarticleType) AddItem(-1);
};

_di_IXMLarticleType __fastcall TXMLarticlesType::Insert(const int Index)
{
  return (_di_IXMLarticleType) AddItem(Index);
};

// TXMLarticleType 

System::UnicodeString __fastcall TXMLarticleType::Get_articleNum()
{
  return GetChildNodes()->Nodes[System::UnicodeString("articleNum")]->Text;
};

void __fastcall TXMLarticleType::Set_articleNum(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("articleNum")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLarticleType::Get_articleID()
{
  return GetChildNodes()->Nodes[System::UnicodeString("articleID")]->Text;
};

void __fastcall TXMLarticleType::Set_articleID(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("articleID")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLarticleType::Get_articleType()
{
  return GetChildNodes()->Nodes[System::UnicodeString("articleType")]->Text;
};

void __fastcall TXMLarticleType::Set_articleType(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("articleType")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLarticleType::Get_quantity()
{
  return GetChildNodes()->Nodes[System::UnicodeString("quantity")]->Text;
};

void __fastcall TXMLarticleType::Set_quantity(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("quantity")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLarticleType::Get_measureUnit()
{
  return GetChildNodes()->Nodes[System::UnicodeString("measureUnit")]->Text;
};

void __fastcall TXMLarticleType::Set_measureUnit(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("measureUnit")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLarticleType::Get_wholesalePrice()
{
  return GetChildNodes()->Nodes[System::UnicodeString("wholesalePrice")]->Text;
};

void __fastcall TXMLarticleType::Set_wholesalePrice(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("wholesalePrice")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLarticleType::Get_wholesaleDiscount()
{
  return GetChildNodes()->Nodes[System::UnicodeString("wholesaleDiscount")]->Text;
};

void __fastcall TXMLarticleType::Set_wholesaleDiscount(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("wholesaleDiscount")]->NodeValue = Value;
};

// TXMLarticleTypeList 

_di_IXMLarticleType __fastcall TXMLarticleTypeList::Add()
{
  return (_di_IXMLarticleType) AddItem(-1);
};

_di_IXMLarticleType __fastcall TXMLarticleTypeList::Insert(const int Index)
{
  return (_di_IXMLarticleType) AddItem(Index);
};

_di_IXMLarticleType __fastcall TXMLarticleTypeList::Get_Item(int Index)
{
  return (_di_IXMLarticleType) List->Nodes[Index];
};
