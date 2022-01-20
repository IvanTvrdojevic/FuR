
// *************************************************************************************** //
//                                                                                       
//                                   XML Data Binding                                    
//                                                                                       
//         Generated on: 1/20/2022 9:46:58 PM                                            
//       Generated from: E:\00_WORK\99_RAD\00_CPP\00_FUR\XML\receipt\receiptSchema.xml   
//                                                                                       
// *************************************************************************************** //

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

__interface INTERFACE_UUID("{F0D4DCA1-CFB6-4109-940E-F663FF02E8E3}") IXMLreceiptType : public Xml::Xmlintf::IXMLNode
{
public:
  // Property Accessors 
  virtual int __fastcall Get_number() = 0;
  virtual double __fastcall Get_serviceDate() = 0;
  virtual double __fastcall Get_issueDate() = 0;
  virtual System::UnicodeString __fastcall Get_issueTime() = 0;
  virtual double __fastcall Get_arrivalDate() = 0;
  virtual System::UnicodeString __fastcall Get_card() = 0;
  virtual System::UnicodeString __fastcall Get_OIB() = 0;
  virtual System::UnicodeString __fastcall Get_articleID() = 0;
  virtual System::UnicodeString __fastcall Get_articleType() = 0;
  virtual System::UnicodeString __fastcall Get_quantity() = 0;
  virtual System::UnicodeString __fastcall Get_measureUnit() = 0;
  virtual System::UnicodeString __fastcall Get_wholesalePrice() = 0;
  virtual System::UnicodeString __fastcall Get_wholesaleDiscount() = 0;
  virtual System::UnicodeString __fastcall Get_pdv() = 0;
  virtual void __fastcall Set_number(int Value) = 0;
  virtual void __fastcall Set_serviceDate(double Value) = 0;
  virtual void __fastcall Set_issueDate(double Value) = 0;
  virtual void __fastcall Set_issueTime(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_arrivalDate(double Value) = 0;
  virtual void __fastcall Set_card(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_OIB(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_articleID(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_articleType(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_quantity(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_measureUnit(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_wholesalePrice(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_wholesaleDiscount(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_pdv(System::UnicodeString Value) = 0;
  // Methods & Properties 
  __property int number = { read=Get_number, write=Set_number };
  __property double serviceDate = { read=Get_serviceDate, write=Set_serviceDate };
  __property double issueDate = { read=Get_issueDate, write=Set_issueDate };
  __property System::UnicodeString issueTime = { read=Get_issueTime, write=Set_issueTime };
  __property double arrivalDate = { read=Get_arrivalDate, write=Set_arrivalDate };
  __property System::UnicodeString card = { read=Get_card, write=Set_card };
  __property System::UnicodeString OIB = { read=Get_OIB, write=Set_OIB };
  __property System::UnicodeString articleID = { read=Get_articleID, write=Set_articleID };
  __property System::UnicodeString articleType = { read=Get_articleType, write=Set_articleType };
  __property System::UnicodeString quantity = { read=Get_quantity, write=Set_quantity };
  __property System::UnicodeString measureUnit = { read=Get_measureUnit, write=Set_measureUnit };
  __property System::UnicodeString wholesalePrice = { read=Get_wholesalePrice, write=Set_wholesalePrice };
  __property System::UnicodeString wholesaleDiscount = { read=Get_wholesaleDiscount, write=Set_wholesaleDiscount };
  __property System::UnicodeString pdv = { read=Get_pdv, write=Set_pdv };
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
  virtual double __fastcall Get_serviceDate();
  virtual double __fastcall Get_issueDate();
  virtual System::UnicodeString __fastcall Get_issueTime();
  virtual double __fastcall Get_arrivalDate();
  virtual System::UnicodeString __fastcall Get_card();
  virtual System::UnicodeString __fastcall Get_OIB();
  virtual System::UnicodeString __fastcall Get_articleID();
  virtual System::UnicodeString __fastcall Get_articleType();
  virtual System::UnicodeString __fastcall Get_quantity();
  virtual System::UnicodeString __fastcall Get_measureUnit();
  virtual System::UnicodeString __fastcall Get_wholesalePrice();
  virtual System::UnicodeString __fastcall Get_wholesaleDiscount();
  virtual System::UnicodeString __fastcall Get_pdv();
  virtual void __fastcall Set_number(int Value);
  virtual void __fastcall Set_serviceDate(double Value);
  virtual void __fastcall Set_issueDate(double Value);
  virtual void __fastcall Set_issueTime(System::UnicodeString Value);
  virtual void __fastcall Set_arrivalDate(double Value);
  virtual void __fastcall Set_card(System::UnicodeString Value);
  virtual void __fastcall Set_OIB(System::UnicodeString Value);
  virtual void __fastcall Set_articleID(System::UnicodeString Value);
  virtual void __fastcall Set_articleType(System::UnicodeString Value);
  virtual void __fastcall Set_quantity(System::UnicodeString Value);
  virtual void __fastcall Set_measureUnit(System::UnicodeString Value);
  virtual void __fastcall Set_wholesalePrice(System::UnicodeString Value);
  virtual void __fastcall Set_wholesaleDiscount(System::UnicodeString Value);
  virtual void __fastcall Set_pdv(System::UnicodeString Value);
};

// Global Functions 

_di_IXMLreceiptType __fastcall Getreceipt(Xml::Xmlintf::_di_IXMLDocument Doc);
_di_IXMLreceiptType __fastcall Getreceipt(Xml::Xmldoc::TXMLDocument *Doc);
_di_IXMLreceiptType __fastcall Loadreceipt(const System::UnicodeString& FileName);
_di_IXMLreceiptType __fastcall  Newreceipt();

#define TargetNamespace ""

#endif