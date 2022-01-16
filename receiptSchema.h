
// ******************************************************************************************************************* //
//                                                                                                                   
//                                                 XML Data Binding                                                  
//                                                                                                                   
//         Generated on: 6.1.2022. 23:00:01                                                                          
//       Generated from: C:\Users\User\Desktop\All\Programiranje\Racun al ovaj nemoj obrisat\Res\receiptSchema.xml   
//   Settings stored in: C:\Users\User\Desktop\All\Programiranje\Racun al ovaj nemoj obrisat\Res\receiptSchema.xdb   
//                                                                                                                   
// ******************************************************************************************************************* //

#ifndef   receiptSchemaH
#define   receiptSchemaH

#include <System.hpp>
#include <System.Variants.hpp>
#include <Xml.Xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Xml.XMLDoc.hpp>
#include <XMLNodeImp.h>
#include <Xml.xmlutil.hpp>


// Forward Decls 

__interface IXMLreceiptType;
typedef System::DelphiInterface<IXMLreceiptType> _di_IXMLreceiptType;

// IXMLreceiptType 

__interface INTERFACE_UUID("{5619383F-2E83-427C-92A5-31178A14814C}") IXMLreceiptType : public Xml::Xmlintf::IXMLNode
{
public:
  // Property Accessors 
  virtual int __fastcall Get_number() = 0;
  virtual System::UnicodeString __fastcall Get_serviceDate() = 0;
  virtual System::UnicodeString __fastcall Get_issueDate() = 0;
  virtual System::UnicodeString __fastcall Get_issueTime() = 0;
  virtual System::UnicodeString __fastcall Get_arrivalDate() = 0;
  virtual System::UnicodeString __fastcall Get_card() = 0;
  virtual System::UnicodeString __fastcall Get_OIB() = 0;
  virtual System::UnicodeString __fastcall Get_articleID() = 0;
  virtual int __fastcall Get_articleType() = 0;
  virtual double __fastcall Get_quantity() = 0;
  virtual int __fastcall Get_measureUnit() = 0;
  virtual double __fastcall Get_wholesalePrice() = 0;
  virtual double __fastcall Get_wholesaleDiscount() = 0;
  virtual double __fastcall Get_pdv() = 0;
  virtual void __fastcall Set_number(int Value) = 0;
  virtual void __fastcall Set_serviceDate(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_issueDate(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_issueTime(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_arrivalDate(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_card(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_OIB(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_articleID(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_articleType(int Value) = 0;
  virtual void __fastcall Set_quantity(double Value) = 0;
  virtual void __fastcall Set_measureUnit(int Value) = 0;
  virtual void __fastcall Set_wholesalePrice(double Value) = 0;
  virtual void __fastcall Set_wholesaleDiscount(double Value) = 0;
  virtual void __fastcall Set_pdv(double Value) = 0;
  // Methods & Properties 
  __property int number = { read=Get_number, write=Set_number };
  __property System::UnicodeString serviceDate = { read=Get_serviceDate, write=Set_serviceDate };
  __property System::UnicodeString issueDate = { read=Get_issueDate, write=Set_issueDate };
  __property System::UnicodeString issueTime = { read=Get_issueTime, write=Set_issueTime };
  __property System::UnicodeString arrivalDate = { read=Get_arrivalDate, write=Set_arrivalDate };
  __property System::UnicodeString card = { read=Get_card, write=Set_card };
  __property System::UnicodeString OIB = { read=Get_OIB, write=Set_OIB };
  __property System::UnicodeString articleID = { read=Get_articleID, write=Set_articleID };
  __property int articleType = { read=Get_articleType, write=Set_articleType };
  __property double quantity = { read=Get_quantity, write=Set_quantity };
  __property int measureUnit = { read=Get_measureUnit, write=Set_measureUnit };
  __property double wholesalePrice = { read=Get_wholesalePrice, write=Set_wholesalePrice };
  __property double wholesaleDiscount = { read=Get_wholesaleDiscount, write=Set_wholesaleDiscount };
  __property double pdv = { read=Get_pdv, write=Set_pdv };
};

// Forward Decls 

class TXMLreceiptType;

// TXMLreceiptType 

class TXMLreceiptType : public Xml::Xmldoc::TXMLNode, public IXMLreceiptType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLreceiptType 
  virtual int __fastcall Get_number();
  virtual System::UnicodeString __fastcall Get_serviceDate();
  virtual System::UnicodeString __fastcall Get_issueDate();
  virtual System::UnicodeString __fastcall Get_issueTime();
  virtual System::UnicodeString __fastcall Get_arrivalDate();
  virtual System::UnicodeString __fastcall Get_card();
  virtual System::UnicodeString __fastcall Get_OIB();
  virtual System::UnicodeString __fastcall Get_articleID();
  virtual int __fastcall Get_articleType();
  virtual double __fastcall Get_quantity();
  virtual int __fastcall Get_measureUnit();
  virtual double __fastcall Get_wholesalePrice();
  virtual double __fastcall Get_wholesaleDiscount();
  virtual double __fastcall Get_pdv();
  virtual void __fastcall Set_number(int Value);
  virtual void __fastcall Set_serviceDate(System::UnicodeString Value);
  virtual void __fastcall Set_issueDate(System::UnicodeString Value);
  virtual void __fastcall Set_issueTime(System::UnicodeString Value);
  virtual void __fastcall Set_arrivalDate(System::UnicodeString Value);
  virtual void __fastcall Set_card(System::UnicodeString Value);
  virtual void __fastcall Set_OIB(System::UnicodeString Value);
  virtual void __fastcall Set_articleID(System::UnicodeString Value);
  virtual void __fastcall Set_articleType(int Value);
  virtual void __fastcall Set_quantity(double Value);
  virtual void __fastcall Set_measureUnit(int Value);
  virtual void __fastcall Set_wholesalePrice(double Value);
  virtual void __fastcall Set_wholesaleDiscount(double Value);
  virtual void __fastcall Set_pdv(double Value);
};

// Global Functions 

_di_IXMLreceiptType __fastcall Getreceipt(Xml::Xmlintf::_di_IXMLDocument Doc);
_di_IXMLreceiptType __fastcall Getreceipt(Xml::Xmldoc::TXMLDocument *Doc);
_di_IXMLreceiptType __fastcall Loadreceipt(const System::UnicodeString& FileName);
_di_IXMLreceiptType __fastcall  Newreceipt();

#define TargetNamespace ""

#endif