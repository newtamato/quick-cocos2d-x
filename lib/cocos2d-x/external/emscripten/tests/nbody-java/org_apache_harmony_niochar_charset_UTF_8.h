#ifndef __ORG_APACHE_HARMONY_NIOCHAR_CHARSET_UTF_8__
#define __ORG_APACHE_HARMONY_NIOCHAR_CHARSET_UTF_8__

#include "xmlvm.h"

// Preprocessor constants for interfaces:
#define XMLVM_ITABLE_SIZE_org_apache_harmony_niochar_charset_UTF_8 8
// Implemented interfaces:
// Super Class:
#include "java_nio_charset_Charset.h"

// Circular references:
#ifndef XMLVM_FORWARD_DECL_java_lang_Object
#define XMLVM_FORWARD_DECL_java_lang_Object
XMLVM_FORWARD_DECL(java_lang_Object)
#endif
#ifndef XMLVM_FORWARD_DECL_java_lang_String
#define XMLVM_FORWARD_DECL_java_lang_String
XMLVM_FORWARD_DECL(java_lang_String)
#endif
#ifndef XMLVM_FORWARD_DECL_java_nio_charset_CharsetDecoder
#define XMLVM_FORWARD_DECL_java_nio_charset_CharsetDecoder
XMLVM_FORWARD_DECL(java_nio_charset_CharsetDecoder)
#endif
#ifndef XMLVM_FORWARD_DECL_java_nio_charset_CharsetEncoder
#define XMLVM_FORWARD_DECL_java_nio_charset_CharsetEncoder
XMLVM_FORWARD_DECL(java_nio_charset_CharsetEncoder)
#endif
#ifndef XMLVM_FORWARD_DECL_org_apache_harmony_niochar_charset_UTF_8_Decoder
#define XMLVM_FORWARD_DECL_org_apache_harmony_niochar_charset_UTF_8_Decoder
XMLVM_FORWARD_DECL(org_apache_harmony_niochar_charset_UTF_8_Decoder)
#endif
#ifndef XMLVM_FORWARD_DECL_org_apache_harmony_niochar_charset_UTF_8_Encoder
#define XMLVM_FORWARD_DECL_org_apache_harmony_niochar_charset_UTF_8_Encoder
XMLVM_FORWARD_DECL(org_apache_harmony_niochar_charset_UTF_8_Encoder)
#endif
// Class declarations for org.apache.harmony.niochar.charset.UTF_8
XMLVM_DEFINE_CLASS(org_apache_harmony_niochar_charset_UTF_8, 10, XMLVM_ITABLE_SIZE_org_apache_harmony_niochar_charset_UTF_8)

extern JAVA_OBJECT __CLASS_org_apache_harmony_niochar_charset_UTF_8;
extern JAVA_OBJECT __CLASS_org_apache_harmony_niochar_charset_UTF_8_1ARRAY;
extern JAVA_OBJECT __CLASS_org_apache_harmony_niochar_charset_UTF_8_2ARRAY;
extern JAVA_OBJECT __CLASS_org_apache_harmony_niochar_charset_UTF_8_3ARRAY;
//XMLVM_BEGIN_DECLARATIONS
#define __ADDITIONAL_INSTANCE_FIELDS_org_apache_harmony_niochar_charset_UTF_8
//XMLVM_END_DECLARATIONS

#define __INSTANCE_FIELDS_org_apache_harmony_niochar_charset_UTF_8 \
    __INSTANCE_FIELDS_java_nio_charset_Charset; \
    struct { \
        __ADDITIONAL_INSTANCE_FIELDS_org_apache_harmony_niochar_charset_UTF_8 \
    } org_apache_harmony_niochar_charset_UTF_8

struct org_apache_harmony_niochar_charset_UTF_8 {
    __TIB_DEFINITION_org_apache_harmony_niochar_charset_UTF_8* tib;
    struct {
        __INSTANCE_FIELDS_org_apache_harmony_niochar_charset_UTF_8;
    } fields;
};
#ifndef XMLVM_FORWARD_DECL_org_apache_harmony_niochar_charset_UTF_8
#define XMLVM_FORWARD_DECL_org_apache_harmony_niochar_charset_UTF_8
typedef struct org_apache_harmony_niochar_charset_UTF_8 org_apache_harmony_niochar_charset_UTF_8;
#endif

#define XMLVM_VTABLE_SIZE_org_apache_harmony_niochar_charset_UTF_8 10
#define XMLVM_VTABLE_IDX_org_apache_harmony_niochar_charset_UTF_8_contains___java_nio_charset_Charset 7
#define XMLVM_VTABLE_IDX_org_apache_harmony_niochar_charset_UTF_8_newDecoder__ 8
#define XMLVM_VTABLE_IDX_org_apache_harmony_niochar_charset_UTF_8_newEncoder__ 9

void __INIT_org_apache_harmony_niochar_charset_UTF_8();
void __INIT_IMPL_org_apache_harmony_niochar_charset_UTF_8();
void __DELETE_org_apache_harmony_niochar_charset_UTF_8(void* me, void* client_data);
void __INIT_INSTANCE_MEMBERS_org_apache_harmony_niochar_charset_UTF_8(JAVA_OBJECT me, int derivedClassWillRegisterFinalizer);
JAVA_OBJECT __NEW_org_apache_harmony_niochar_charset_UTF_8();
JAVA_OBJECT __NEW_INSTANCE_org_apache_harmony_niochar_charset_UTF_8();
JAVA_OBJECT org_apache_harmony_niochar_charset_UTF_8_GET_remainingBytes();
void org_apache_harmony_niochar_charset_UTF_8_PUT_remainingBytes(JAVA_OBJECT v);
JAVA_OBJECT org_apache_harmony_niochar_charset_UTF_8_GET_remainingNumbers();
void org_apache_harmony_niochar_charset_UTF_8_PUT_remainingNumbers(JAVA_OBJECT v);
JAVA_OBJECT org_apache_harmony_niochar_charset_UTF_8_GET_lowerEncodingLimit();
void org_apache_harmony_niochar_charset_UTF_8_PUT_lowerEncodingLimit(JAVA_OBJECT v);
void org_apache_harmony_niochar_charset_UTF_8___CLINIT_();
void org_apache_harmony_niochar_charset_UTF_8___INIT____java_lang_String_java_lang_String_1ARRAY(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2);
// Vtable index: 7
JAVA_BOOLEAN org_apache_harmony_niochar_charset_UTF_8_contains___java_nio_charset_Charset(JAVA_OBJECT me, JAVA_OBJECT n1);
// Vtable index: 8
JAVA_OBJECT org_apache_harmony_niochar_charset_UTF_8_newDecoder__(JAVA_OBJECT me);
// Vtable index: 9
JAVA_OBJECT org_apache_harmony_niochar_charset_UTF_8_newEncoder__(JAVA_OBJECT me);
JAVA_OBJECT org_apache_harmony_niochar_charset_UTF_8_access$0__();
JAVA_OBJECT org_apache_harmony_niochar_charset_UTF_8_access$1__();
JAVA_OBJECT org_apache_harmony_niochar_charset_UTF_8_access$2__();

#endif
