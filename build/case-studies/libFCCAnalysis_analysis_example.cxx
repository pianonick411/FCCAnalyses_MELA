// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME libFCCAnalysis_analysis_example
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "ROOT/RConfig.hxx"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/case-studies/analysis_example/include/DummyAnalysis.h"
#include "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/case-studies/analysis_example/src/classes.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static TClass *analysis_examplecLcLdictionary_Dictionary();
   static void analysis_examplecLcLdictionary_TClassManip(TClass*);
   static void *new_analysis_examplecLcLdictionary(void *p = nullptr);
   static void *newArray_analysis_examplecLcLdictionary(Long_t size, void *p);
   static void delete_analysis_examplecLcLdictionary(void *p);
   static void deleteArray_analysis_examplecLcLdictionary(void *p);
   static void destruct_analysis_examplecLcLdictionary(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::analysis_example::dictionary*)
   {
      ::analysis_example::dictionary *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::analysis_example::dictionary));
      static ::ROOT::TGenericClassInfo 
         instance("analysis_example::dictionary", "", 20,
                  typeid(::analysis_example::dictionary), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &analysis_examplecLcLdictionary_Dictionary, isa_proxy, 4,
                  sizeof(::analysis_example::dictionary) );
      instance.SetNew(&new_analysis_examplecLcLdictionary);
      instance.SetNewArray(&newArray_analysis_examplecLcLdictionary);
      instance.SetDelete(&delete_analysis_examplecLcLdictionary);
      instance.SetDeleteArray(&deleteArray_analysis_examplecLcLdictionary);
      instance.SetDestructor(&destruct_analysis_examplecLcLdictionary);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::analysis_example::dictionary*)
   {
      return GenerateInitInstanceLocal(static_cast<::analysis_example::dictionary*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::analysis_example::dictionary*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *analysis_examplecLcLdictionary_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::analysis_example::dictionary*>(nullptr))->GetClass();
      analysis_examplecLcLdictionary_TClassManip(theClass);
   return theClass;
   }

   static void analysis_examplecLcLdictionary_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_analysis_examplecLcLdictionary(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::analysis_example::dictionary : new ::analysis_example::dictionary;
   }
   static void *newArray_analysis_examplecLcLdictionary(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::analysis_example::dictionary[nElements] : new ::analysis_example::dictionary[nElements];
   }
   // Wrapper around operator delete
   static void delete_analysis_examplecLcLdictionary(void *p) {
      delete (static_cast<::analysis_example::dictionary*>(p));
   }
   static void deleteArray_analysis_examplecLcLdictionary(void *p) {
      delete [] (static_cast<::analysis_example::dictionary*>(p));
   }
   static void destruct_analysis_examplecLcLdictionary(void *p) {
      typedef ::analysis_example::dictionary current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::analysis_example::dictionary

namespace {
  void TriggerDictionaryInitialization_libFCCAnalysis_analysis_example_Impl() {
    static const char* headers[] = {
"0",
nullptr
    };
    static const char* includePaths[] = {
"/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/case-studies",
"/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/include/root",
"/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/case-studies/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libFCCAnalysis_analysis_example dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace analysis_example{struct dictionary;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libFCCAnalysis_analysis_example dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#ifndef analysis_example_DummyAnalysis_h
#define analysis_example_DummyAnalysis_h

#include "ROOT/RVec.hxx"
#include "edm4hep/ReconstructedParticle.h"

namespace analysis_example {
  namespace rv = ROOT::VecOps;

  void dummy_analysis();

  rv::RVec<float> dummy_collection(const rv::RVec<edm4hep::ReconstructedParticleData>&);
}  // namespace analysis_example

#endif
namespace analysis_example {
  struct dictionary {};
}  // namespace analysis_example

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"analysis_example::dictionary", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libFCCAnalysis_analysis_example",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libFCCAnalysis_analysis_example_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libFCCAnalysis_analysis_example_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libFCCAnalysis_analysis_example() {
  TriggerDictionaryInitialization_libFCCAnalysis_analysis_example_Impl();
}
