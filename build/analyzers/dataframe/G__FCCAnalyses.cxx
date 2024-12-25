// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__FCCAnalyses
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
#include "FCCAnalyses/Algorithms.h"
#include "FCCAnalyses/CaloNtupleizer.h"
#include "FCCAnalyses/Defines.h"
#include "FCCAnalyses/JetClusteringUtils.h"
#include "FCCAnalyses/JetConstituentsUtils.h"
#include "FCCAnalyses/JetFlavourUtils.h"
#include "FCCAnalyses/JetTaggingUtils.h"
#include "FCCAnalyses/Logger.h"
#include "FCCAnalyses/MCParticle.h"
#include "FCCAnalyses/ReconstructedParticle.h"
#include "FCCAnalyses/ReconstructedParticle2MC.h"
#include "FCCAnalyses/ReconstructedParticle2Track.h"
#include "FCCAnalyses/ReconstructedTrack.h"
#include "FCCAnalyses/SmearObjects.h"
#include "FCCAnalyses/Smearing.h"
#include "FCCAnalyses/Utils.h"
#include "FCCAnalyses/VertexFinderLCFIPlus.h"
#include "FCCAnalyses/VertexFitterSimple.h"
#include "FCCAnalyses/VertexingUtils.h"
#include "FCCAnalyses/WeaverUtils.h"
#include "FCCAnalyses/dummyLoader.h"
#include "FCCAnalyses/myFinalSel.h"
#include "FCCAnalyses/myUtils.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static TClass *vectorlEvectorlEintgRsPgR_Dictionary();
   static void vectorlEvectorlEintgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEintgRsPgR(void *p = nullptr);
   static void *newArray_vectorlEvectorlEintgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEintgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEintgRsPgR(void *p);
   static void destruct_vectorlEvectorlEintgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<int> >*)
   {
      vector<vector<int> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<int> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<int> >", -2, "vector", 389,
                  typeid(vector<vector<int> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEintgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<vector<int> >) );
      instance.SetNew(&new_vectorlEvectorlEintgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEintgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEintgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEintgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEintgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<int> > >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<vector<int> >","std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<vector<int> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEintgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<vector<int> >*>(nullptr))->GetClass();
      vectorlEvectorlEintgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEintgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEintgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<int> > : new vector<vector<int> >;
   }
   static void *newArray_vectorlEvectorlEintgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<int> >[nElements] : new vector<vector<int> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEintgRsPgR(void *p) {
      delete (static_cast<vector<vector<int> >*>(p));
   }
   static void deleteArray_vectorlEvectorlEintgRsPgR(void *p) {
      delete [] (static_cast<vector<vector<int> >*>(p));
   }
   static void destruct_vectorlEvectorlEintgRsPgR(void *p) {
      typedef vector<vector<int> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<vector<int> >

namespace ROOT {
   static TClass *vectorlEvectorlEfloatgRsPgR_Dictionary();
   static void vectorlEvectorlEfloatgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEfloatgRsPgR(void *p = nullptr);
   static void *newArray_vectorlEvectorlEfloatgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEfloatgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEfloatgRsPgR(void *p);
   static void destruct_vectorlEvectorlEfloatgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<float> >*)
   {
      vector<vector<float> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<float> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<float> >", -2, "vector", 389,
                  typeid(vector<vector<float> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEfloatgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<vector<float> >) );
      instance.SetNew(&new_vectorlEvectorlEfloatgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEfloatgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEfloatgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEfloatgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEfloatgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<float> > >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<vector<float> >","std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<vector<float> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEfloatgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<vector<float> >*>(nullptr))->GetClass();
      vectorlEvectorlEfloatgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEfloatgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEfloatgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<float> > : new vector<vector<float> >;
   }
   static void *newArray_vectorlEvectorlEfloatgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<float> >[nElements] : new vector<vector<float> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEfloatgRsPgR(void *p) {
      delete (static_cast<vector<vector<float> >*>(p));
   }
   static void deleteArray_vectorlEvectorlEfloatgRsPgR(void *p) {
      delete [] (static_cast<vector<vector<float> >*>(p));
   }
   static void destruct_vectorlEvectorlEfloatgRsPgR(void *p) {
      typedef vector<vector<float> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<vector<float> >

namespace ROOT {
   static TClass *vectorlEvectorlEdoublegRsPgR_Dictionary();
   static void vectorlEvectorlEdoublegRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEdoublegRsPgR(void *p = nullptr);
   static void *newArray_vectorlEvectorlEdoublegRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEdoublegRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEdoublegRsPgR(void *p);
   static void destruct_vectorlEvectorlEdoublegRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<double> >*)
   {
      vector<vector<double> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<double> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<double> >", -2, "vector", 389,
                  typeid(vector<vector<double> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEdoublegRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<vector<double> >) );
      instance.SetNew(&new_vectorlEvectorlEdoublegRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEdoublegRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEdoublegRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEdoublegRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEdoublegRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<double> > >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<vector<double> >","std::vector<std::vector<double, std::allocator<double> >, std::allocator<std::vector<double, std::allocator<double> > > >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<vector<double> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEdoublegRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<vector<double> >*>(nullptr))->GetClass();
      vectorlEvectorlEdoublegRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEdoublegRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEdoublegRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<double> > : new vector<vector<double> >;
   }
   static void *newArray_vectorlEvectorlEdoublegRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<double> >[nElements] : new vector<vector<double> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEdoublegRsPgR(void *p) {
      delete (static_cast<vector<vector<double> >*>(p));
   }
   static void deleteArray_vectorlEvectorlEdoublegRsPgR(void *p) {
      delete [] (static_cast<vector<vector<double> >*>(p));
   }
   static void destruct_vectorlEvectorlEdoublegRsPgR(void *p) {
      typedef vector<vector<double> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<vector<double> >

namespace ROOT {
   static TClass *vectorlEstringgR_Dictionary();
   static void vectorlEstringgR_TClassManip(TClass*);
   static void *new_vectorlEstringgR(void *p = nullptr);
   static void *newArray_vectorlEstringgR(Long_t size, void *p);
   static void delete_vectorlEstringgR(void *p);
   static void deleteArray_vectorlEstringgR(void *p);
   static void destruct_vectorlEstringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<string>*)
   {
      vector<string> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<string>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<string>", -2, "vector", 389,
                  typeid(vector<string>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEstringgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<string>) );
      instance.SetNew(&new_vectorlEstringgR);
      instance.SetNewArray(&newArray_vectorlEstringgR);
      instance.SetDelete(&delete_vectorlEstringgR);
      instance.SetDeleteArray(&deleteArray_vectorlEstringgR);
      instance.SetDestructor(&destruct_vectorlEstringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<string> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<string>","std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<string>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEstringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<string>*>(nullptr))->GetClass();
      vectorlEstringgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEstringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEstringgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<string> : new vector<string>;
   }
   static void *newArray_vectorlEstringgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<string>[nElements] : new vector<string>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEstringgR(void *p) {
      delete (static_cast<vector<string>*>(p));
   }
   static void deleteArray_vectorlEstringgR(void *p) {
      delete [] (static_cast<vector<string>*>(p));
   }
   static void destruct_vectorlEstringgR(void *p) {
      typedef vector<string> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<string>

namespace ROOT {
   static TClass *vectorlEintgR_Dictionary();
   static void vectorlEintgR_TClassManip(TClass*);
   static void *new_vectorlEintgR(void *p = nullptr);
   static void *newArray_vectorlEintgR(Long_t size, void *p);
   static void delete_vectorlEintgR(void *p);
   static void deleteArray_vectorlEintgR(void *p);
   static void destruct_vectorlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<int>*)
   {
      vector<int> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<int>", -2, "vector", 389,
                  typeid(vector<int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEintgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<int>","std::vector<int, std::allocator<int> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<int>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<int>*>(nullptr))->GetClass();
      vectorlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int> : new vector<int>;
   }
   static void *newArray_vectorlEintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int>[nElements] : new vector<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEintgR(void *p) {
      delete (static_cast<vector<int>*>(p));
   }
   static void deleteArray_vectorlEintgR(void *p) {
      delete [] (static_cast<vector<int>*>(p));
   }
   static void destruct_vectorlEintgR(void *p) {
      typedef vector<int> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<int>

namespace ROOT {
   static TClass *vectorlEfloatgR_Dictionary();
   static void vectorlEfloatgR_TClassManip(TClass*);
   static void *new_vectorlEfloatgR(void *p = nullptr);
   static void *newArray_vectorlEfloatgR(Long_t size, void *p);
   static void delete_vectorlEfloatgR(void *p);
   static void deleteArray_vectorlEfloatgR(void *p);
   static void destruct_vectorlEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<float>*)
   {
      vector<float> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<float>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<float>", -2, "vector", 389,
                  typeid(vector<float>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEfloatgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<float>) );
      instance.SetNew(&new_vectorlEfloatgR);
      instance.SetNewArray(&newArray_vectorlEfloatgR);
      instance.SetDelete(&delete_vectorlEfloatgR);
      instance.SetDeleteArray(&deleteArray_vectorlEfloatgR);
      instance.SetDestructor(&destruct_vectorlEfloatgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<float> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<float>","std::vector<float, std::allocator<float> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<float>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<float>*>(nullptr))->GetClass();
      vectorlEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEfloatgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<float> : new vector<float>;
   }
   static void *newArray_vectorlEfloatgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<float>[nElements] : new vector<float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEfloatgR(void *p) {
      delete (static_cast<vector<float>*>(p));
   }
   static void deleteArray_vectorlEfloatgR(void *p) {
      delete [] (static_cast<vector<float>*>(p));
   }
   static void destruct_vectorlEfloatgR(void *p) {
      typedef vector<float> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<float>

namespace ROOT {
   static TClass *vectorlEdoublegR_Dictionary();
   static void vectorlEdoublegR_TClassManip(TClass*);
   static void *new_vectorlEdoublegR(void *p = nullptr);
   static void *newArray_vectorlEdoublegR(Long_t size, void *p);
   static void delete_vectorlEdoublegR(void *p);
   static void deleteArray_vectorlEdoublegR(void *p);
   static void destruct_vectorlEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<double>*)
   {
      vector<double> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<double>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<double>", -2, "vector", 389,
                  typeid(vector<double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEdoublegR_Dictionary, isa_proxy, 4,
                  sizeof(vector<double>) );
      instance.SetNew(&new_vectorlEdoublegR);
      instance.SetNewArray(&newArray_vectorlEdoublegR);
      instance.SetDelete(&delete_vectorlEdoublegR);
      instance.SetDeleteArray(&deleteArray_vectorlEdoublegR);
      instance.SetDestructor(&destruct_vectorlEdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<double> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<double>","std::vector<double, std::allocator<double> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<double>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<double>*>(nullptr))->GetClass();
      vectorlEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEdoublegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<double> : new vector<double>;
   }
   static void *newArray_vectorlEdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<double>[nElements] : new vector<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEdoublegR(void *p) {
      delete (static_cast<vector<double>*>(p));
   }
   static void deleteArray_vectorlEdoublegR(void *p) {
      delete [] (static_cast<vector<double>*>(p));
   }
   static void destruct_vectorlEdoublegR(void *p) {
      typedef vector<double> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<double>

namespace ROOT {
   static TClass *vectorlETLorentzVectorgR_Dictionary();
   static void vectorlETLorentzVectorgR_TClassManip(TClass*);
   static void *new_vectorlETLorentzVectorgR(void *p = nullptr);
   static void *newArray_vectorlETLorentzVectorgR(Long_t size, void *p);
   static void delete_vectorlETLorentzVectorgR(void *p);
   static void deleteArray_vectorlETLorentzVectorgR(void *p);
   static void destruct_vectorlETLorentzVectorgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TLorentzVector>*)
   {
      vector<TLorentzVector> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TLorentzVector>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TLorentzVector>", -2, "vector", 389,
                  typeid(vector<TLorentzVector>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETLorentzVectorgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<TLorentzVector>) );
      instance.SetNew(&new_vectorlETLorentzVectorgR);
      instance.SetNewArray(&newArray_vectorlETLorentzVectorgR);
      instance.SetDelete(&delete_vectorlETLorentzVectorgR);
      instance.SetDeleteArray(&deleteArray_vectorlETLorentzVectorgR);
      instance.SetDestructor(&destruct_vectorlETLorentzVectorgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TLorentzVector> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<TLorentzVector>","std::vector<TLorentzVector, std::allocator<TLorentzVector> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<TLorentzVector>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETLorentzVectorgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<TLorentzVector>*>(nullptr))->GetClass();
      vectorlETLorentzVectorgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETLorentzVectorgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETLorentzVectorgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TLorentzVector> : new vector<TLorentzVector>;
   }
   static void *newArray_vectorlETLorentzVectorgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TLorentzVector>[nElements] : new vector<TLorentzVector>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETLorentzVectorgR(void *p) {
      delete (static_cast<vector<TLorentzVector>*>(p));
   }
   static void deleteArray_vectorlETLorentzVectorgR(void *p) {
      delete [] (static_cast<vector<TLorentzVector>*>(p));
   }
   static void destruct_vectorlETLorentzVectorgR(void *p) {
      typedef vector<TLorentzVector> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<TLorentzVector>

namespace ROOT {
   static TClass *ROOTcLcLVecOpscLcLRVeclEvectorlEfloatgRsPgR_Dictionary();
   static void ROOTcLcLVecOpscLcLRVeclEvectorlEfloatgRsPgR_TClassManip(TClass*);
   static void *new_ROOTcLcLVecOpscLcLRVeclEvectorlEfloatgRsPgR(void *p = nullptr);
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEvectorlEfloatgRsPgR(Long_t size, void *p);
   static void delete_ROOTcLcLVecOpscLcLRVeclEvectorlEfloatgRsPgR(void *p);
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEvectorlEfloatgRsPgR(void *p);
   static void destruct_ROOTcLcLVecOpscLcLRVeclEvectorlEfloatgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ROOT::VecOps::RVec<vector<float> >*)
   {
      ROOT::VecOps::RVec<vector<float> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(ROOT::VecOps::RVec<vector<float> >));
      static ::ROOT::TGenericClassInfo 
         instance("ROOT::VecOps::RVec<vector<float> >", -2, "ROOT/RVec.hxx", 1480,
                  typeid(ROOT::VecOps::RVec<vector<float> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ROOTcLcLVecOpscLcLRVeclEvectorlEfloatgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(ROOT::VecOps::RVec<vector<float> >) );
      instance.SetNew(&new_ROOTcLcLVecOpscLcLRVeclEvectorlEfloatgRsPgR);
      instance.SetNewArray(&newArray_ROOTcLcLVecOpscLcLRVeclEvectorlEfloatgRsPgR);
      instance.SetDelete(&delete_ROOTcLcLVecOpscLcLRVeclEvectorlEfloatgRsPgR);
      instance.SetDeleteArray(&deleteArray_ROOTcLcLVecOpscLcLRVeclEvectorlEfloatgRsPgR);
      instance.SetDestructor(&destruct_ROOTcLcLVecOpscLcLRVeclEvectorlEfloatgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< ROOT::VecOps::RVec<vector<float> > >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("ROOT::VecOps::RVec<vector<float> >","ROOT::VecOps::RVec<std::vector<float, std::allocator<float> > >"));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ROOT::VecOps::RVec<vector<float> >*)
   {
      return GenerateInitInstanceLocal(static_cast<ROOT::VecOps::RVec<vector<float> >*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<vector<float> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ROOTcLcLVecOpscLcLRVeclEvectorlEfloatgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<vector<float> >*>(nullptr))->GetClass();
      ROOTcLcLVecOpscLcLRVeclEvectorlEfloatgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void ROOTcLcLVecOpscLcLRVeclEvectorlEfloatgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ROOTcLcLVecOpscLcLRVeclEvectorlEfloatgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<vector<float> > : new ROOT::VecOps::RVec<vector<float> >;
   }
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEvectorlEfloatgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<vector<float> >[nElements] : new ROOT::VecOps::RVec<vector<float> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_ROOTcLcLVecOpscLcLRVeclEvectorlEfloatgRsPgR(void *p) {
      delete (static_cast<ROOT::VecOps::RVec<vector<float> >*>(p));
   }
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEvectorlEfloatgRsPgR(void *p) {
      delete [] (static_cast<ROOT::VecOps::RVec<vector<float> >*>(p));
   }
   static void destruct_ROOTcLcLVecOpscLcLRVeclEvectorlEfloatgRsPgR(void *p) {
      typedef ROOT::VecOps::RVec<vector<float> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ROOT::VecOps::RVec<vector<float> >

namespace ROOT {
   static TClass *ROOTcLcLVecOpscLcLRVeclEpodiocLcLObjectIDgR_Dictionary();
   static void ROOTcLcLVecOpscLcLRVeclEpodiocLcLObjectIDgR_TClassManip(TClass*);
   static void *new_ROOTcLcLVecOpscLcLRVeclEpodiocLcLObjectIDgR(void *p = nullptr);
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEpodiocLcLObjectIDgR(Long_t size, void *p);
   static void delete_ROOTcLcLVecOpscLcLRVeclEpodiocLcLObjectIDgR(void *p);
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEpodiocLcLObjectIDgR(void *p);
   static void destruct_ROOTcLcLVecOpscLcLRVeclEpodiocLcLObjectIDgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ROOT::VecOps::RVec<podio::ObjectID>*)
   {
      ROOT::VecOps::RVec<podio::ObjectID> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(ROOT::VecOps::RVec<podio::ObjectID>));
      static ::ROOT::TGenericClassInfo 
         instance("ROOT::VecOps::RVec<podio::ObjectID>", -2, "ROOT/RVec.hxx", 1480,
                  typeid(ROOT::VecOps::RVec<podio::ObjectID>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ROOTcLcLVecOpscLcLRVeclEpodiocLcLObjectIDgR_Dictionary, isa_proxy, 4,
                  sizeof(ROOT::VecOps::RVec<podio::ObjectID>) );
      instance.SetNew(&new_ROOTcLcLVecOpscLcLRVeclEpodiocLcLObjectIDgR);
      instance.SetNewArray(&newArray_ROOTcLcLVecOpscLcLRVeclEpodiocLcLObjectIDgR);
      instance.SetDelete(&delete_ROOTcLcLVecOpscLcLRVeclEpodiocLcLObjectIDgR);
      instance.SetDeleteArray(&deleteArray_ROOTcLcLVecOpscLcLRVeclEpodiocLcLObjectIDgR);
      instance.SetDestructor(&destruct_ROOTcLcLVecOpscLcLRVeclEpodiocLcLObjectIDgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< ROOT::VecOps::RVec<podio::ObjectID> >()));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ROOT::VecOps::RVec<podio::ObjectID>*)
   {
      return GenerateInitInstanceLocal(static_cast<ROOT::VecOps::RVec<podio::ObjectID>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<podio::ObjectID>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ROOTcLcLVecOpscLcLRVeclEpodiocLcLObjectIDgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<podio::ObjectID>*>(nullptr))->GetClass();
      ROOTcLcLVecOpscLcLRVeclEpodiocLcLObjectIDgR_TClassManip(theClass);
   return theClass;
   }

   static void ROOTcLcLVecOpscLcLRVeclEpodiocLcLObjectIDgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ROOTcLcLVecOpscLcLRVeclEpodiocLcLObjectIDgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<podio::ObjectID> : new ROOT::VecOps::RVec<podio::ObjectID>;
   }
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEpodiocLcLObjectIDgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<podio::ObjectID>[nElements] : new ROOT::VecOps::RVec<podio::ObjectID>[nElements];
   }
   // Wrapper around operator delete
   static void delete_ROOTcLcLVecOpscLcLRVeclEpodiocLcLObjectIDgR(void *p) {
      delete (static_cast<ROOT::VecOps::RVec<podio::ObjectID>*>(p));
   }
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEpodiocLcLObjectIDgR(void *p) {
      delete [] (static_cast<ROOT::VecOps::RVec<podio::ObjectID>*>(p));
   }
   static void destruct_ROOTcLcLVecOpscLcLRVeclEpodiocLcLObjectIDgR(void *p) {
      typedef ROOT::VecOps::RVec<podio::ObjectID> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ROOT::VecOps::RVec<podio::ObjectID>

namespace ROOT {
   static TClass *ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR_Dictionary();
   static void ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR_TClassManip(TClass*);
   static void *new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR(void *p = nullptr);
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR(Long_t size, void *p);
   static void delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR(void *p);
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR(void *p);
   static void destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ROOT::VecOps::RVec<edm4hep::VertexData>*)
   {
      ROOT::VecOps::RVec<edm4hep::VertexData> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(ROOT::VecOps::RVec<edm4hep::VertexData>));
      static ::ROOT::TGenericClassInfo 
         instance("ROOT::VecOps::RVec<edm4hep::VertexData>", -2, "ROOT/RVec.hxx", 1480,
                  typeid(ROOT::VecOps::RVec<edm4hep::VertexData>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR_Dictionary, isa_proxy, 4,
                  sizeof(ROOT::VecOps::RVec<edm4hep::VertexData>) );
      instance.SetNew(&new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR);
      instance.SetNewArray(&newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR);
      instance.SetDelete(&delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR);
      instance.SetDeleteArray(&deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR);
      instance.SetDestructor(&destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< ROOT::VecOps::RVec<edm4hep::VertexData> >()));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ROOT::VecOps::RVec<edm4hep::VertexData>*)
   {
      return GenerateInitInstanceLocal(static_cast<ROOT::VecOps::RVec<edm4hep::VertexData>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<edm4hep::VertexData>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<edm4hep::VertexData>*>(nullptr))->GetClass();
      ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR_TClassManip(theClass);
   return theClass;
   }

   static void ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<edm4hep::VertexData> : new ROOT::VecOps::RVec<edm4hep::VertexData>;
   }
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<edm4hep::VertexData>[nElements] : new ROOT::VecOps::RVec<edm4hep::VertexData>[nElements];
   }
   // Wrapper around operator delete
   static void delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR(void *p) {
      delete (static_cast<ROOT::VecOps::RVec<edm4hep::VertexData>*>(p));
   }
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR(void *p) {
      delete [] (static_cast<ROOT::VecOps::RVec<edm4hep::VertexData>*>(p));
   }
   static void destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVertexDatagR(void *p) {
      typedef ROOT::VecOps::RVec<edm4hep::VertexData> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ROOT::VecOps::RVec<edm4hep::VertexData>

namespace ROOT {
   static TClass *ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR_Dictionary();
   static void ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR_TClassManip(TClass*);
   static void *new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR(void *p = nullptr);
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR(Long_t size, void *p);
   static void delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR(void *p);
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR(void *p);
   static void destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ROOT::VecOps::RVec<edm4hep::Vector3d>*)
   {
      ROOT::VecOps::RVec<edm4hep::Vector3d> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(ROOT::VecOps::RVec<edm4hep::Vector3d>));
      static ::ROOT::TGenericClassInfo 
         instance("ROOT::VecOps::RVec<edm4hep::Vector3d>", -2, "ROOT/RVec.hxx", 1480,
                  typeid(ROOT::VecOps::RVec<edm4hep::Vector3d>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR_Dictionary, isa_proxy, 4,
                  sizeof(ROOT::VecOps::RVec<edm4hep::Vector3d>) );
      instance.SetNew(&new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR);
      instance.SetNewArray(&newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR);
      instance.SetDelete(&delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR);
      instance.SetDeleteArray(&deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR);
      instance.SetDestructor(&destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< ROOT::VecOps::RVec<edm4hep::Vector3d> >()));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ROOT::VecOps::RVec<edm4hep::Vector3d>*)
   {
      return GenerateInitInstanceLocal(static_cast<ROOT::VecOps::RVec<edm4hep::Vector3d>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<edm4hep::Vector3d>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<edm4hep::Vector3d>*>(nullptr))->GetClass();
      ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR_TClassManip(theClass);
   return theClass;
   }

   static void ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<edm4hep::Vector3d> : new ROOT::VecOps::RVec<edm4hep::Vector3d>;
   }
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<edm4hep::Vector3d>[nElements] : new ROOT::VecOps::RVec<edm4hep::Vector3d>[nElements];
   }
   // Wrapper around operator delete
   static void delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR(void *p) {
      delete (static_cast<ROOT::VecOps::RVec<edm4hep::Vector3d>*>(p));
   }
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR(void *p) {
      delete [] (static_cast<ROOT::VecOps::RVec<edm4hep::Vector3d>*>(p));
   }
   static void destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLVector3dgR(void *p) {
      typedef ROOT::VecOps::RVec<edm4hep::Vector3d> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ROOT::VecOps::RVec<edm4hep::Vector3d>

namespace ROOT {
   static TClass *ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR_Dictionary();
   static void ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR_TClassManip(TClass*);
   static void *new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR(void *p = nullptr);
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR(Long_t size, void *p);
   static void delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR(void *p);
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR(void *p);
   static void destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ROOT::VecOps::RVec<edm4hep::TrackState>*)
   {
      ROOT::VecOps::RVec<edm4hep::TrackState> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(ROOT::VecOps::RVec<edm4hep::TrackState>));
      static ::ROOT::TGenericClassInfo 
         instance("ROOT::VecOps::RVec<edm4hep::TrackState>", -2, "ROOT/RVec.hxx", 1480,
                  typeid(ROOT::VecOps::RVec<edm4hep::TrackState>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR_Dictionary, isa_proxy, 4,
                  sizeof(ROOT::VecOps::RVec<edm4hep::TrackState>) );
      instance.SetNew(&new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR);
      instance.SetNewArray(&newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR);
      instance.SetDelete(&delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR);
      instance.SetDeleteArray(&deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR);
      instance.SetDestructor(&destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< ROOT::VecOps::RVec<edm4hep::TrackState> >()));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ROOT::VecOps::RVec<edm4hep::TrackState>*)
   {
      return GenerateInitInstanceLocal(static_cast<ROOT::VecOps::RVec<edm4hep::TrackState>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<edm4hep::TrackState>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<edm4hep::TrackState>*>(nullptr))->GetClass();
      ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR_TClassManip(theClass);
   return theClass;
   }

   static void ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<edm4hep::TrackState> : new ROOT::VecOps::RVec<edm4hep::TrackState>;
   }
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<edm4hep::TrackState>[nElements] : new ROOT::VecOps::RVec<edm4hep::TrackState>[nElements];
   }
   // Wrapper around operator delete
   static void delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR(void *p) {
      delete (static_cast<ROOT::VecOps::RVec<edm4hep::TrackState>*>(p));
   }
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR(void *p) {
      delete [] (static_cast<ROOT::VecOps::RVec<edm4hep::TrackState>*>(p));
   }
   static void destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLTrackStategR(void *p) {
      typedef ROOT::VecOps::RVec<edm4hep::TrackState> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ROOT::VecOps::RVec<edm4hep::TrackState>

namespace ROOT {
   static TClass *ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR_Dictionary();
   static void ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR_TClassManip(TClass*);
   static void *new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR(void *p = nullptr);
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR(Long_t size, void *p);
   static void delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR(void *p);
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR(void *p);
   static void destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>*)
   {
      ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>));
      static ::ROOT::TGenericClassInfo 
         instance("ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>", -2, "ROOT/RVec.hxx", 1480,
                  typeid(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR_Dictionary, isa_proxy, 4,
                  sizeof(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>) );
      instance.SetNew(&new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR);
      instance.SetNewArray(&newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR);
      instance.SetDelete(&delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR);
      instance.SetDeleteArray(&deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR);
      instance.SetDestructor(&destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> >()));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>*)
   {
      return GenerateInitInstanceLocal(static_cast<ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>*>(nullptr))->GetClass();
      ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR_TClassManip(theClass);
   return theClass;
   }

   static void ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> : new ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>;
   }
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>[nElements] : new ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>[nElements];
   }
   // Wrapper around operator delete
   static void delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR(void *p) {
      delete (static_cast<ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>*>(p));
   }
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR(void *p) {
      delete [] (static_cast<ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>*>(p));
   }
   static void destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagR(void *p) {
      typedef ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>

namespace ROOT {
   static TClass *ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR_Dictionary();
   static void ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR_TClassManip(TClass*);
   static void *new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR(void *p = nullptr);
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR(Long_t size, void *p);
   static void delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR(void *p);
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR(void *p);
   static void destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ROOT::VecOps::RVec<edm4hep::MCParticleData>*)
   {
      ROOT::VecOps::RVec<edm4hep::MCParticleData> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(ROOT::VecOps::RVec<edm4hep::MCParticleData>));
      static ::ROOT::TGenericClassInfo 
         instance("ROOT::VecOps::RVec<edm4hep::MCParticleData>", -2, "ROOT/RVec.hxx", 1480,
                  typeid(ROOT::VecOps::RVec<edm4hep::MCParticleData>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR_Dictionary, isa_proxy, 4,
                  sizeof(ROOT::VecOps::RVec<edm4hep::MCParticleData>) );
      instance.SetNew(&new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR);
      instance.SetNewArray(&newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR);
      instance.SetDelete(&delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR);
      instance.SetDeleteArray(&deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR);
      instance.SetDestructor(&destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< ROOT::VecOps::RVec<edm4hep::MCParticleData> >()));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ROOT::VecOps::RVec<edm4hep::MCParticleData>*)
   {
      return GenerateInitInstanceLocal(static_cast<ROOT::VecOps::RVec<edm4hep::MCParticleData>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<edm4hep::MCParticleData>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<edm4hep::MCParticleData>*>(nullptr))->GetClass();
      ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR_TClassManip(theClass);
   return theClass;
   }

   static void ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<edm4hep::MCParticleData> : new ROOT::VecOps::RVec<edm4hep::MCParticleData>;
   }
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<edm4hep::MCParticleData>[nElements] : new ROOT::VecOps::RVec<edm4hep::MCParticleData>[nElements];
   }
   // Wrapper around operator delete
   static void delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR(void *p) {
      delete (static_cast<ROOT::VecOps::RVec<edm4hep::MCParticleData>*>(p));
   }
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR(void *p) {
      delete [] (static_cast<ROOT::VecOps::RVec<edm4hep::MCParticleData>*>(p));
   }
   static void destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLMCParticleDatagR(void *p) {
      typedef ROOT::VecOps::RVec<edm4hep::MCParticleData> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ROOT::VecOps::RVec<edm4hep::MCParticleData>

namespace ROOT {
   static TClass *ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLClusterDatagR_Dictionary();
   static void ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLClusterDatagR_TClassManip(TClass*);
   static void *new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLClusterDatagR(void *p = nullptr);
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLClusterDatagR(Long_t size, void *p);
   static void delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLClusterDatagR(void *p);
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLClusterDatagR(void *p);
   static void destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLClusterDatagR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ROOT::VecOps::RVec<edm4hep::ClusterData>*)
   {
      ROOT::VecOps::RVec<edm4hep::ClusterData> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(ROOT::VecOps::RVec<edm4hep::ClusterData>));
      static ::ROOT::TGenericClassInfo 
         instance("ROOT::VecOps::RVec<edm4hep::ClusterData>", -2, "ROOT/RVec.hxx", 1480,
                  typeid(ROOT::VecOps::RVec<edm4hep::ClusterData>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLClusterDatagR_Dictionary, isa_proxy, 4,
                  sizeof(ROOT::VecOps::RVec<edm4hep::ClusterData>) );
      instance.SetNew(&new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLClusterDatagR);
      instance.SetNewArray(&newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLClusterDatagR);
      instance.SetDelete(&delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLClusterDatagR);
      instance.SetDeleteArray(&deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLClusterDatagR);
      instance.SetDestructor(&destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLClusterDatagR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< ROOT::VecOps::RVec<edm4hep::ClusterData> >()));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ROOT::VecOps::RVec<edm4hep::ClusterData>*)
   {
      return GenerateInitInstanceLocal(static_cast<ROOT::VecOps::RVec<edm4hep::ClusterData>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<edm4hep::ClusterData>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLClusterDatagR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<edm4hep::ClusterData>*>(nullptr))->GetClass();
      ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLClusterDatagR_TClassManip(theClass);
   return theClass;
   }

   static void ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLClusterDatagR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLClusterDatagR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<edm4hep::ClusterData> : new ROOT::VecOps::RVec<edm4hep::ClusterData>;
   }
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLClusterDatagR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<edm4hep::ClusterData>[nElements] : new ROOT::VecOps::RVec<edm4hep::ClusterData>[nElements];
   }
   // Wrapper around operator delete
   static void delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLClusterDatagR(void *p) {
      delete (static_cast<ROOT::VecOps::RVec<edm4hep::ClusterData>*>(p));
   }
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLClusterDatagR(void *p) {
      delete [] (static_cast<ROOT::VecOps::RVec<edm4hep::ClusterData>*>(p));
   }
   static void destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLClusterDatagR(void *p) {
      typedef ROOT::VecOps::RVec<edm4hep::ClusterData> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ROOT::VecOps::RVec<edm4hep::ClusterData>

namespace ROOT {
   static TClass *ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLCalorimeterHitDatagR_Dictionary();
   static void ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLCalorimeterHitDatagR_TClassManip(TClass*);
   static void *new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLCalorimeterHitDatagR(void *p = nullptr);
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLCalorimeterHitDatagR(Long_t size, void *p);
   static void delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLCalorimeterHitDatagR(void *p);
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLCalorimeterHitDatagR(void *p);
   static void destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLCalorimeterHitDatagR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ROOT::VecOps::RVec<edm4hep::CalorimeterHitData>*)
   {
      ROOT::VecOps::RVec<edm4hep::CalorimeterHitData> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(ROOT::VecOps::RVec<edm4hep::CalorimeterHitData>));
      static ::ROOT::TGenericClassInfo 
         instance("ROOT::VecOps::RVec<edm4hep::CalorimeterHitData>", -2, "ROOT/RVec.hxx", 1480,
                  typeid(ROOT::VecOps::RVec<edm4hep::CalorimeterHitData>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLCalorimeterHitDatagR_Dictionary, isa_proxy, 4,
                  sizeof(ROOT::VecOps::RVec<edm4hep::CalorimeterHitData>) );
      instance.SetNew(&new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLCalorimeterHitDatagR);
      instance.SetNewArray(&newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLCalorimeterHitDatagR);
      instance.SetDelete(&delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLCalorimeterHitDatagR);
      instance.SetDeleteArray(&deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLCalorimeterHitDatagR);
      instance.SetDestructor(&destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLCalorimeterHitDatagR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< ROOT::VecOps::RVec<edm4hep::CalorimeterHitData> >()));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ROOT::VecOps::RVec<edm4hep::CalorimeterHitData>*)
   {
      return GenerateInitInstanceLocal(static_cast<ROOT::VecOps::RVec<edm4hep::CalorimeterHitData>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<edm4hep::CalorimeterHitData>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLCalorimeterHitDatagR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<edm4hep::CalorimeterHitData>*>(nullptr))->GetClass();
      ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLCalorimeterHitDatagR_TClassManip(theClass);
   return theClass;
   }

   static void ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLCalorimeterHitDatagR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLCalorimeterHitDatagR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<edm4hep::CalorimeterHitData> : new ROOT::VecOps::RVec<edm4hep::CalorimeterHitData>;
   }
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLCalorimeterHitDatagR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<edm4hep::CalorimeterHitData>[nElements] : new ROOT::VecOps::RVec<edm4hep::CalorimeterHitData>[nElements];
   }
   // Wrapper around operator delete
   static void delete_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLCalorimeterHitDatagR(void *p) {
      delete (static_cast<ROOT::VecOps::RVec<edm4hep::CalorimeterHitData>*>(p));
   }
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLCalorimeterHitDatagR(void *p) {
      delete [] (static_cast<ROOT::VecOps::RVec<edm4hep::CalorimeterHitData>*>(p));
   }
   static void destruct_ROOTcLcLVecOpscLcLRVeclEedm4hepcLcLCalorimeterHitDatagR(void *p) {
      typedef ROOT::VecOps::RVec<edm4hep::CalorimeterHitData> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ROOT::VecOps::RVec<edm4hep::CalorimeterHitData>

namespace ROOT {
   static TClass *ROOTcLcLVecOpscLcLRVeclETVector3gR_Dictionary();
   static void ROOTcLcLVecOpscLcLRVeclETVector3gR_TClassManip(TClass*);
   static void *new_ROOTcLcLVecOpscLcLRVeclETVector3gR(void *p = nullptr);
   static void *newArray_ROOTcLcLVecOpscLcLRVeclETVector3gR(Long_t size, void *p);
   static void delete_ROOTcLcLVecOpscLcLRVeclETVector3gR(void *p);
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclETVector3gR(void *p);
   static void destruct_ROOTcLcLVecOpscLcLRVeclETVector3gR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ROOT::VecOps::RVec<TVector3>*)
   {
      ROOT::VecOps::RVec<TVector3> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(ROOT::VecOps::RVec<TVector3>));
      static ::ROOT::TGenericClassInfo 
         instance("ROOT::VecOps::RVec<TVector3>", -2, "ROOT/RVec.hxx", 1480,
                  typeid(ROOT::VecOps::RVec<TVector3>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ROOTcLcLVecOpscLcLRVeclETVector3gR_Dictionary, isa_proxy, 4,
                  sizeof(ROOT::VecOps::RVec<TVector3>) );
      instance.SetNew(&new_ROOTcLcLVecOpscLcLRVeclETVector3gR);
      instance.SetNewArray(&newArray_ROOTcLcLVecOpscLcLRVeclETVector3gR);
      instance.SetDelete(&delete_ROOTcLcLVecOpscLcLRVeclETVector3gR);
      instance.SetDeleteArray(&deleteArray_ROOTcLcLVecOpscLcLRVeclETVector3gR);
      instance.SetDestructor(&destruct_ROOTcLcLVecOpscLcLRVeclETVector3gR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< ROOT::VecOps::RVec<TVector3> >()));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ROOT::VecOps::RVec<TVector3>*)
   {
      return GenerateInitInstanceLocal(static_cast<ROOT::VecOps::RVec<TVector3>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<TVector3>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ROOTcLcLVecOpscLcLRVeclETVector3gR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<TVector3>*>(nullptr))->GetClass();
      ROOTcLcLVecOpscLcLRVeclETVector3gR_TClassManip(theClass);
   return theClass;
   }

   static void ROOTcLcLVecOpscLcLRVeclETVector3gR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ROOTcLcLVecOpscLcLRVeclETVector3gR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<TVector3> : new ROOT::VecOps::RVec<TVector3>;
   }
   static void *newArray_ROOTcLcLVecOpscLcLRVeclETVector3gR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<TVector3>[nElements] : new ROOT::VecOps::RVec<TVector3>[nElements];
   }
   // Wrapper around operator delete
   static void delete_ROOTcLcLVecOpscLcLRVeclETVector3gR(void *p) {
      delete (static_cast<ROOT::VecOps::RVec<TVector3>*>(p));
   }
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclETVector3gR(void *p) {
      delete [] (static_cast<ROOT::VecOps::RVec<TVector3>*>(p));
   }
   static void destruct_ROOTcLcLVecOpscLcLRVeclETVector3gR(void *p) {
      typedef ROOT::VecOps::RVec<TVector3> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ROOT::VecOps::RVec<TVector3>

namespace ROOT {
   static TClass *ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR_Dictionary();
   static void ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR_TClassManip(TClass*);
   static void *new_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR(void *p = nullptr);
   static void *newArray_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR(Long_t size, void *p);
   static void delete_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR(void *p);
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR(void *p);
   static void destruct_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ROOT::VecOps::RVec<TLorentzVector>*)
   {
      ROOT::VecOps::RVec<TLorentzVector> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(ROOT::VecOps::RVec<TLorentzVector>));
      static ::ROOT::TGenericClassInfo 
         instance("ROOT::VecOps::RVec<TLorentzVector>", -2, "ROOT/RVec.hxx", 1480,
                  typeid(ROOT::VecOps::RVec<TLorentzVector>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR_Dictionary, isa_proxy, 4,
                  sizeof(ROOT::VecOps::RVec<TLorentzVector>) );
      instance.SetNew(&new_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR);
      instance.SetNewArray(&newArray_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR);
      instance.SetDelete(&delete_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR);
      instance.SetDeleteArray(&deleteArray_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR);
      instance.SetDestructor(&destruct_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< ROOT::VecOps::RVec<TLorentzVector> >()));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ROOT::VecOps::RVec<TLorentzVector>*)
   {
      return GenerateInitInstanceLocal(static_cast<ROOT::VecOps::RVec<TLorentzVector>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<TLorentzVector>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<TLorentzVector>*>(nullptr))->GetClass();
      ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR_TClassManip(theClass);
   return theClass;
   }

   static void ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<TLorentzVector> : new ROOT::VecOps::RVec<TLorentzVector>;
   }
   static void *newArray_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<TLorentzVector>[nElements] : new ROOT::VecOps::RVec<TLorentzVector>[nElements];
   }
   // Wrapper around operator delete
   static void delete_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR(void *p) {
      delete (static_cast<ROOT::VecOps::RVec<TLorentzVector>*>(p));
   }
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR(void *p) {
      delete [] (static_cast<ROOT::VecOps::RVec<TLorentzVector>*>(p));
   }
   static void destruct_ROOTcLcLVecOpscLcLRVeclETLorentzVectorgR(void *p) {
      typedef ROOT::VecOps::RVec<TLorentzVector> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ROOT::VecOps::RVec<TLorentzVector>

namespace ROOT {
   static TClass *ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEintgRsPgR_Dictionary();
   static void ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEintgRsPgR_TClassManip(TClass*);
   static void *new_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEintgRsPgR(void *p = nullptr);
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEintgRsPgR(Long_t size, void *p);
   static void delete_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEintgRsPgR(void *p);
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEintgRsPgR(void *p);
   static void destruct_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEintgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ROOT::VecOps::RVec<ROOT::VecOps::RVec<int> >*)
   {
      ROOT::VecOps::RVec<ROOT::VecOps::RVec<int> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(ROOT::VecOps::RVec<ROOT::VecOps::RVec<int> >));
      static ::ROOT::TGenericClassInfo 
         instance("ROOT::VecOps::RVec<ROOT::VecOps::RVec<int> >", -2, "ROOT/RVec.hxx", 1480,
                  typeid(ROOT::VecOps::RVec<ROOT::VecOps::RVec<int> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEintgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(ROOT::VecOps::RVec<ROOT::VecOps::RVec<int> >) );
      instance.SetNew(&new_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEintgRsPgR);
      instance.SetNewArray(&newArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEintgRsPgR);
      instance.SetDelete(&delete_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEintgRsPgR);
      instance.SetDeleteArray(&deleteArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEintgRsPgR);
      instance.SetDestructor(&destruct_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEintgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< ROOT::VecOps::RVec<ROOT::VecOps::RVec<int> > >()));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ROOT::VecOps::RVec<ROOT::VecOps::RVec<int> >*)
   {
      return GenerateInitInstanceLocal(static_cast<ROOT::VecOps::RVec<ROOT::VecOps::RVec<int> >*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<ROOT::VecOps::RVec<int> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEintgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<ROOT::VecOps::RVec<int> >*>(nullptr))->GetClass();
      ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEintgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEintgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEintgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<ROOT::VecOps::RVec<int> > : new ROOT::VecOps::RVec<ROOT::VecOps::RVec<int> >;
   }
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEintgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<ROOT::VecOps::RVec<int> >[nElements] : new ROOT::VecOps::RVec<ROOT::VecOps::RVec<int> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEintgRsPgR(void *p) {
      delete (static_cast<ROOT::VecOps::RVec<ROOT::VecOps::RVec<int> >*>(p));
   }
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEintgRsPgR(void *p) {
      delete [] (static_cast<ROOT::VecOps::RVec<ROOT::VecOps::RVec<int> >*>(p));
   }
   static void destruct_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEintgRsPgR(void *p) {
      typedef ROOT::VecOps::RVec<ROOT::VecOps::RVec<int> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ROOT::VecOps::RVec<ROOT::VecOps::RVec<int> >

namespace ROOT {
   static TClass *ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEfloatgRsPgR_Dictionary();
   static void ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEfloatgRsPgR_TClassManip(TClass*);
   static void *new_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEfloatgRsPgR(void *p = nullptr);
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEfloatgRsPgR(Long_t size, void *p);
   static void delete_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEfloatgRsPgR(void *p);
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEfloatgRsPgR(void *p);
   static void destruct_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEfloatgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ROOT::VecOps::RVec<ROOT::VecOps::RVec<float> >*)
   {
      ROOT::VecOps::RVec<ROOT::VecOps::RVec<float> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(ROOT::VecOps::RVec<ROOT::VecOps::RVec<float> >));
      static ::ROOT::TGenericClassInfo 
         instance("ROOT::VecOps::RVec<ROOT::VecOps::RVec<float> >", -2, "ROOT/RVec.hxx", 1480,
                  typeid(ROOT::VecOps::RVec<ROOT::VecOps::RVec<float> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEfloatgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(ROOT::VecOps::RVec<ROOT::VecOps::RVec<float> >) );
      instance.SetNew(&new_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEfloatgRsPgR);
      instance.SetNewArray(&newArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEfloatgRsPgR);
      instance.SetDelete(&delete_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEfloatgRsPgR);
      instance.SetDeleteArray(&deleteArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEfloatgRsPgR);
      instance.SetDestructor(&destruct_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEfloatgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< ROOT::VecOps::RVec<ROOT::VecOps::RVec<float> > >()));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ROOT::VecOps::RVec<ROOT::VecOps::RVec<float> >*)
   {
      return GenerateInitInstanceLocal(static_cast<ROOT::VecOps::RVec<ROOT::VecOps::RVec<float> >*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<ROOT::VecOps::RVec<float> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEfloatgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<ROOT::VecOps::RVec<float> >*>(nullptr))->GetClass();
      ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEfloatgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEfloatgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEfloatgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<ROOT::VecOps::RVec<float> > : new ROOT::VecOps::RVec<ROOT::VecOps::RVec<float> >;
   }
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEfloatgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<ROOT::VecOps::RVec<float> >[nElements] : new ROOT::VecOps::RVec<ROOT::VecOps::RVec<float> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEfloatgRsPgR(void *p) {
      delete (static_cast<ROOT::VecOps::RVec<ROOT::VecOps::RVec<float> >*>(p));
   }
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEfloatgRsPgR(void *p) {
      delete [] (static_cast<ROOT::VecOps::RVec<ROOT::VecOps::RVec<float> >*>(p));
   }
   static void destruct_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEfloatgRsPgR(void *p) {
      typedef ROOT::VecOps::RVec<ROOT::VecOps::RVec<float> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ROOT::VecOps::RVec<ROOT::VecOps::RVec<float> >

namespace ROOT {
   static TClass *ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagRsPgR_Dictionary();
   static void ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagRsPgR_TClassManip(TClass*);
   static void *new_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagRsPgR(void *p = nullptr);
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagRsPgR(Long_t size, void *p);
   static void delete_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagRsPgR(void *p);
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagRsPgR(void *p);
   static void destruct_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ROOT::VecOps::RVec<ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> >*)
   {
      ROOT::VecOps::RVec<ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(ROOT::VecOps::RVec<ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> >));
      static ::ROOT::TGenericClassInfo 
         instance("ROOT::VecOps::RVec<ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> >", -2, "ROOT/RVec.hxx", 1480,
                  typeid(ROOT::VecOps::RVec<ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(ROOT::VecOps::RVec<ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> >) );
      instance.SetNew(&new_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagRsPgR);
      instance.SetNewArray(&newArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagRsPgR);
      instance.SetDelete(&delete_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagRsPgR);
      instance.SetDeleteArray(&deleteArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagRsPgR);
      instance.SetDestructor(&destruct_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< ROOT::VecOps::RVec<ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> > >()));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ROOT::VecOps::RVec<ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> >*)
   {
      return GenerateInitInstanceLocal(static_cast<ROOT::VecOps::RVec<ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> >*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> >*>(nullptr))->GetClass();
      ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> > : new ROOT::VecOps::RVec<ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> >;
   }
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> >[nElements] : new ROOT::VecOps::RVec<ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagRsPgR(void *p) {
      delete (static_cast<ROOT::VecOps::RVec<ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> >*>(p));
   }
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagRsPgR(void *p) {
      delete [] (static_cast<ROOT::VecOps::RVec<ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> >*>(p));
   }
   static void destruct_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEedm4hepcLcLReconstructedParticleDatagRsPgR(void *p) {
      typedef ROOT::VecOps::RVec<ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ROOT::VecOps::RVec<ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> >

namespace ROOT {
   static TClass *ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEdoublegRsPgR_Dictionary();
   static void ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEdoublegRsPgR_TClassManip(TClass*);
   static void *new_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEdoublegRsPgR(void *p = nullptr);
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEdoublegRsPgR(Long_t size, void *p);
   static void delete_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEdoublegRsPgR(void *p);
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEdoublegRsPgR(void *p);
   static void destruct_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEdoublegRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ROOT::VecOps::RVec<ROOT::VecOps::RVec<double> >*)
   {
      ROOT::VecOps::RVec<ROOT::VecOps::RVec<double> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(ROOT::VecOps::RVec<ROOT::VecOps::RVec<double> >));
      static ::ROOT::TGenericClassInfo 
         instance("ROOT::VecOps::RVec<ROOT::VecOps::RVec<double> >", -2, "ROOT/RVec.hxx", 1480,
                  typeid(ROOT::VecOps::RVec<ROOT::VecOps::RVec<double> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEdoublegRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(ROOT::VecOps::RVec<ROOT::VecOps::RVec<double> >) );
      instance.SetNew(&new_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEdoublegRsPgR);
      instance.SetNewArray(&newArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEdoublegRsPgR);
      instance.SetDelete(&delete_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEdoublegRsPgR);
      instance.SetDeleteArray(&deleteArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEdoublegRsPgR);
      instance.SetDestructor(&destruct_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEdoublegRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< ROOT::VecOps::RVec<ROOT::VecOps::RVec<double> > >()));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ROOT::VecOps::RVec<ROOT::VecOps::RVec<double> >*)
   {
      return GenerateInitInstanceLocal(static_cast<ROOT::VecOps::RVec<ROOT::VecOps::RVec<double> >*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<ROOT::VecOps::RVec<double> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEdoublegRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<ROOT::VecOps::RVec<double> >*>(nullptr))->GetClass();
      ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEdoublegRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEdoublegRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEdoublegRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<ROOT::VecOps::RVec<double> > : new ROOT::VecOps::RVec<ROOT::VecOps::RVec<double> >;
   }
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEdoublegRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<ROOT::VecOps::RVec<double> >[nElements] : new ROOT::VecOps::RVec<ROOT::VecOps::RVec<double> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEdoublegRsPgR(void *p) {
      delete (static_cast<ROOT::VecOps::RVec<ROOT::VecOps::RVec<double> >*>(p));
   }
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEdoublegRsPgR(void *p) {
      delete [] (static_cast<ROOT::VecOps::RVec<ROOT::VecOps::RVec<double> >*>(p));
   }
   static void destruct_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEdoublegRsPgR(void *p) {
      typedef ROOT::VecOps::RVec<ROOT::VecOps::RVec<double> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ROOT::VecOps::RVec<ROOT::VecOps::RVec<double> >

namespace ROOT {
   static TClass *ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETVector3gRsPgR_Dictionary();
   static void ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETVector3gRsPgR_TClassManip(TClass*);
   static void *new_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETVector3gRsPgR(void *p = nullptr);
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETVector3gRsPgR(Long_t size, void *p);
   static void delete_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETVector3gRsPgR(void *p);
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETVector3gRsPgR(void *p);
   static void destruct_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETVector3gRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ROOT::VecOps::RVec<ROOT::VecOps::RVec<TVector3> >*)
   {
      ROOT::VecOps::RVec<ROOT::VecOps::RVec<TVector3> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(ROOT::VecOps::RVec<ROOT::VecOps::RVec<TVector3> >));
      static ::ROOT::TGenericClassInfo 
         instance("ROOT::VecOps::RVec<ROOT::VecOps::RVec<TVector3> >", -2, "ROOT/RVec.hxx", 1480,
                  typeid(ROOT::VecOps::RVec<ROOT::VecOps::RVec<TVector3> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETVector3gRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(ROOT::VecOps::RVec<ROOT::VecOps::RVec<TVector3> >) );
      instance.SetNew(&new_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETVector3gRsPgR);
      instance.SetNewArray(&newArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETVector3gRsPgR);
      instance.SetDelete(&delete_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETVector3gRsPgR);
      instance.SetDeleteArray(&deleteArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETVector3gRsPgR);
      instance.SetDestructor(&destruct_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETVector3gRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< ROOT::VecOps::RVec<ROOT::VecOps::RVec<TVector3> > >()));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ROOT::VecOps::RVec<ROOT::VecOps::RVec<TVector3> >*)
   {
      return GenerateInitInstanceLocal(static_cast<ROOT::VecOps::RVec<ROOT::VecOps::RVec<TVector3> >*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<ROOT::VecOps::RVec<TVector3> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETVector3gRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<ROOT::VecOps::RVec<TVector3> >*>(nullptr))->GetClass();
      ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETVector3gRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETVector3gRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETVector3gRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<ROOT::VecOps::RVec<TVector3> > : new ROOT::VecOps::RVec<ROOT::VecOps::RVec<TVector3> >;
   }
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETVector3gRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<ROOT::VecOps::RVec<TVector3> >[nElements] : new ROOT::VecOps::RVec<ROOT::VecOps::RVec<TVector3> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETVector3gRsPgR(void *p) {
      delete (static_cast<ROOT::VecOps::RVec<ROOT::VecOps::RVec<TVector3> >*>(p));
   }
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETVector3gRsPgR(void *p) {
      delete [] (static_cast<ROOT::VecOps::RVec<ROOT::VecOps::RVec<TVector3> >*>(p));
   }
   static void destruct_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETVector3gRsPgR(void *p) {
      typedef ROOT::VecOps::RVec<ROOT::VecOps::RVec<TVector3> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ROOT::VecOps::RVec<ROOT::VecOps::RVec<TVector3> >

namespace ROOT {
   static TClass *ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETLorentzVectorgRsPgR_Dictionary();
   static void ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETLorentzVectorgRsPgR_TClassManip(TClass*);
   static void *new_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETLorentzVectorgRsPgR(void *p = nullptr);
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETLorentzVectorgRsPgR(Long_t size, void *p);
   static void delete_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETLorentzVectorgRsPgR(void *p);
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETLorentzVectorgRsPgR(void *p);
   static void destruct_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETLorentzVectorgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ROOT::VecOps::RVec<ROOT::VecOps::RVec<TLorentzVector> >*)
   {
      ROOT::VecOps::RVec<ROOT::VecOps::RVec<TLorentzVector> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(ROOT::VecOps::RVec<ROOT::VecOps::RVec<TLorentzVector> >));
      static ::ROOT::TGenericClassInfo 
         instance("ROOT::VecOps::RVec<ROOT::VecOps::RVec<TLorentzVector> >", -2, "ROOT/RVec.hxx", 1480,
                  typeid(ROOT::VecOps::RVec<ROOT::VecOps::RVec<TLorentzVector> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETLorentzVectorgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(ROOT::VecOps::RVec<ROOT::VecOps::RVec<TLorentzVector> >) );
      instance.SetNew(&new_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETLorentzVectorgRsPgR);
      instance.SetNewArray(&newArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETLorentzVectorgRsPgR);
      instance.SetDelete(&delete_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETLorentzVectorgRsPgR);
      instance.SetDeleteArray(&deleteArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETLorentzVectorgRsPgR);
      instance.SetDestructor(&destruct_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETLorentzVectorgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< ROOT::VecOps::RVec<ROOT::VecOps::RVec<TLorentzVector> > >()));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ROOT::VecOps::RVec<ROOT::VecOps::RVec<TLorentzVector> >*)
   {
      return GenerateInitInstanceLocal(static_cast<ROOT::VecOps::RVec<ROOT::VecOps::RVec<TLorentzVector> >*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<ROOT::VecOps::RVec<TLorentzVector> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETLorentzVectorgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<ROOT::VecOps::RVec<TLorentzVector> >*>(nullptr))->GetClass();
      ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETLorentzVectorgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETLorentzVectorgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETLorentzVectorgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<ROOT::VecOps::RVec<TLorentzVector> > : new ROOT::VecOps::RVec<ROOT::VecOps::RVec<TLorentzVector> >;
   }
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETLorentzVectorgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<ROOT::VecOps::RVec<TLorentzVector> >[nElements] : new ROOT::VecOps::RVec<ROOT::VecOps::RVec<TLorentzVector> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETLorentzVectorgRsPgR(void *p) {
      delete (static_cast<ROOT::VecOps::RVec<ROOT::VecOps::RVec<TLorentzVector> >*>(p));
   }
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETLorentzVectorgRsPgR(void *p) {
      delete [] (static_cast<ROOT::VecOps::RVec<ROOT::VecOps::RVec<TLorentzVector> >*>(p));
   }
   static void destruct_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclETLorentzVectorgRsPgR(void *p) {
      typedef ROOT::VecOps::RVec<ROOT::VecOps::RVec<TLorentzVector> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ROOT::VecOps::RVec<ROOT::VecOps::RVec<TLorentzVector> >

namespace ROOT {
   static TClass *ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgRsPgR_Dictionary();
   static void ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgRsPgR_TClassManip(TClass*);
   static void *new_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgRsPgR(void *p = nullptr);
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgRsPgR(Long_t size, void *p);
   static void delete_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgRsPgR(void *p);
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgRsPgR(void *p);
   static void destruct_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ROOT::VecOps::RVec<ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex> >*)
   {
      ROOT::VecOps::RVec<ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(ROOT::VecOps::RVec<ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex> >));
      static ::ROOT::TGenericClassInfo 
         instance("ROOT::VecOps::RVec<ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex> >", -2, "ROOT/RVec.hxx", 1480,
                  typeid(ROOT::VecOps::RVec<ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(ROOT::VecOps::RVec<ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex> >) );
      instance.SetNew(&new_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgRsPgR);
      instance.SetNewArray(&newArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgRsPgR);
      instance.SetDelete(&delete_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgRsPgR);
      instance.SetDeleteArray(&deleteArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgRsPgR);
      instance.SetDestructor(&destruct_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< ROOT::VecOps::RVec<ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex> > >()));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ROOT::VecOps::RVec<ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex> >*)
   {
      return GenerateInitInstanceLocal(static_cast<ROOT::VecOps::RVec<ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex> >*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex> >*>(nullptr))->GetClass();
      ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex> > : new ROOT::VecOps::RVec<ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex> >;
   }
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex> >[nElements] : new ROOT::VecOps::RVec<ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgRsPgR(void *p) {
      delete (static_cast<ROOT::VecOps::RVec<ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex> >*>(p));
   }
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgRsPgR(void *p) {
      delete [] (static_cast<ROOT::VecOps::RVec<ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex> >*>(p));
   }
   static void destruct_ROOTcLcLVecOpscLcLRVeclEROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgRsPgR(void *p) {
      typedef ROOT::VecOps::RVec<ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ROOT::VecOps::RVec<ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex> >

namespace ROOT {
   static TClass *ROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgR_Dictionary();
   static void ROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgR_TClassManip(TClass*);
   static void *new_ROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgR(void *p = nullptr);
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgR(Long_t size, void *p);
   static void delete_ROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgR(void *p);
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgR(void *p);
   static void destruct_ROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex>*)
   {
      ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex>));
      static ::ROOT::TGenericClassInfo 
         instance("ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex>", -2, "ROOT/RVec.hxx", 1480,
                  typeid(ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgR_Dictionary, isa_proxy, 4,
                  sizeof(ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex>) );
      instance.SetNew(&new_ROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgR);
      instance.SetNewArray(&newArray_ROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgR);
      instance.SetDelete(&delete_ROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgR);
      instance.SetDeleteArray(&deleteArray_ROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgR);
      instance.SetDestructor(&destruct_ROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex> >()));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex>*)
   {
      return GenerateInitInstanceLocal(static_cast<ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex>*>(nullptr))->GetClass();
      ROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgR_TClassManip(theClass);
   return theClass;
   }

   static void ROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex> : new ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex>;
   }
   static void *newArray_ROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex>[nElements] : new ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex>[nElements];
   }
   // Wrapper around operator delete
   static void delete_ROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgR(void *p) {
      delete (static_cast<ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex>*>(p));
   }
   static void deleteArray_ROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgR(void *p) {
      delete [] (static_cast<ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex>*>(p));
   }
   static void destruct_ROOTcLcLVecOpscLcLRVeclEFCCAnalysescLcLVertexingUtilscLcLFCCAnalysesVertexgR(void *p) {
      typedef ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex>

namespace {
  void TriggerDictionaryInitialization_libFCCAnalyses_Impl() {
    static const char* headers[] = {
"FCCAnalyses/Algorithms.h",
"FCCAnalyses/CaloNtupleizer.h",
"FCCAnalyses/Defines.h",
"FCCAnalyses/JetClusteringUtils.h",
"FCCAnalyses/JetConstituentsUtils.h",
"FCCAnalyses/JetFlavourUtils.h",
"FCCAnalyses/JetTaggingUtils.h",
"FCCAnalyses/Logger.h",
"FCCAnalyses/MCParticle.h",
"FCCAnalyses/ReconstructedParticle.h",
"FCCAnalyses/ReconstructedParticle2MC.h",
"FCCAnalyses/ReconstructedParticle2Track.h",
"FCCAnalyses/ReconstructedTrack.h",
"FCCAnalyses/SmearObjects.h",
"FCCAnalyses/Smearing.h",
"FCCAnalyses/Utils.h",
"FCCAnalyses/VertexFinderLCFIPlus.h",
"FCCAnalyses/VertexFitterSimple.h",
"FCCAnalyses/VertexingUtils.h",
"FCCAnalyses/WeaverUtils.h",
"FCCAnalyses/dummyLoader.h",
"FCCAnalyses/myFinalSel.h",
"FCCAnalyses/myUtils.h",
nullptr
    };
    static const char* includePaths[] = {
"/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/delphes/master-rapnt2/include",
"/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/delphes/master-rapnt2/include/TrackCovariance",
"/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/analyzers/dataframe",
"/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/addons",
"/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/vdt/0.4.4-bx2smv/include",
"/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/delphes/master-rapnt2/include",
"/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/delphes/master-rapnt2/include/TrackCovariance",
"/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/analyzers/dataframe",
"/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/addons",
"/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/vdt/0.4.4-bx2smv/include",
"/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/include/root",
"/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/nlohmann-json/3.11.2-mxh7ki/include",
"/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/edm4hep/0.10.5-27swdr/include",
"/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/podio/0.99-uovuyy/include",
"/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/fastjet/3.4.1-pi2dtg/include",
"/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/py-onnxruntime/1.10.0-lvflvi/include",
"/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/dd4hep/1.28-q6ea5f/include",
"/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/boost/1.84.0-nqthpn/include",
"/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/xerces-c/3.2.4-ergagi/include",
"/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/include/root",
"/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/analyzers/dataframe/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libFCCAnalyses dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$bits/allocator.h")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}
namespace std{template <class _CharT> struct __attribute__((annotate("$clingAutoload$bits/char_traits.h")))  __attribute__((annotate("$clingAutoload$string")))  char_traits;
}
class __attribute__((annotate("$clingAutoload$TLorentzVector.h")))  __attribute__((annotate("$clingAutoload$FCCAnalyses/CaloNtupleizer.h")))  TLorentzVector;
namespace edm4hep{class __attribute__((annotate("$clingAutoload$edm4hep/ReconstructedParticleData.h")))  __attribute__((annotate("$clingAutoload$FCCAnalyses/Algorithms.h")))  ReconstructedParticleData;}
namespace ROOT{namespace VecOps{template <typename T> class __attribute__((annotate(R"ATTRDUMP(__cling__ptrcheck(off))ATTRDUMP"))) __attribute__((annotate("$clingAutoload$ROOT/RVec.hxx")))  __attribute__((annotate("$clingAutoload$FCCAnalyses/Algorithms.h")))  RVec;
}}
namespace edm4hep{class __attribute__((annotate("$clingAutoload$edm4hep/CalorimeterHitData.h")))  __attribute__((annotate("$clingAutoload$FCCAnalyses/CaloNtupleizer.h")))  CalorimeterHitData;}
class __attribute__((annotate("$clingAutoload$TVector3.h")))  __attribute__((annotate("$clingAutoload$FCCAnalyses/CaloNtupleizer.h")))  TVector3;
namespace edm4hep{class __attribute__((annotate("$clingAutoload$edm4hep/ClusterData.h")))  __attribute__((annotate("$clingAutoload$FCCAnalyses/CaloNtupleizer.h")))  ClusterData;}
namespace edm4hep{class __attribute__((annotate("$clingAutoload$edm4hep/MCParticleData.h")))  __attribute__((annotate("$clingAutoload$FCCAnalyses/CaloNtupleizer.h")))  MCParticleData;}
namespace edm4hep{class __attribute__((annotate("$clingAutoload$edm4hep/TrackState.h")))  __attribute__((annotate("$clingAutoload$FCCAnalyses/JetConstituentsUtils.h")))  TrackState;}
namespace edm4hep{class __attribute__((annotate("$clingAutoload$edm4hep/Vector3d.h")))  __attribute__((annotate("$clingAutoload$FCCAnalyses/CaloNtupleizer.h")))  Vector3d;}
namespace FCCAnalyses{namespace VertexingUtils{struct __attribute__((annotate("$clingAutoload$VertexingUtils.h")))  __attribute__((annotate("$clingAutoload$FCCAnalyses/VertexFinderLCFIPlus.h")))  FCCAnalysesVertex;}}
namespace edm4hep{class __attribute__((annotate("$clingAutoload$edm4hep/VertexData.h")))  __attribute__((annotate("$clingAutoload$FCCAnalyses/VertexFinderLCFIPlus.h")))  VertexData;}
namespace podio{class __attribute__((annotate("$clingAutoload$podio/ObjectID.h")))  __attribute__((annotate("$clingAutoload$FCCAnalyses/JetConstituentsUtils.h")))  ObjectID;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libFCCAnalyses dictionary payload"

#ifndef PODIO_JSON_OUTPUT
  #define PODIO_JSON_OUTPUT 1
#endif
#ifndef BOOST_SPIRIT_USE_PHOENIX_V3
  #define BOOST_SPIRIT_USE_PHOENIX_V3 1
#endif
#ifndef DD4HEP_USE_XERCESC
  #define DD4HEP_USE_XERCESC 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "FCCAnalyses/Algorithms.h"
#include "FCCAnalyses/CaloNtupleizer.h"
#include "FCCAnalyses/Defines.h"
#include "FCCAnalyses/JetClusteringUtils.h"
#include "FCCAnalyses/JetConstituentsUtils.h"
#include "FCCAnalyses/JetFlavourUtils.h"
#include "FCCAnalyses/JetTaggingUtils.h"
#include "FCCAnalyses/Logger.h"
#include "FCCAnalyses/MCParticle.h"
#include "FCCAnalyses/ReconstructedParticle.h"
#include "FCCAnalyses/ReconstructedParticle2MC.h"
#include "FCCAnalyses/ReconstructedParticle2Track.h"
#include "FCCAnalyses/ReconstructedTrack.h"
#include "FCCAnalyses/SmearObjects.h"
#include "FCCAnalyses/Smearing.h"
#include "FCCAnalyses/Utils.h"
#include "FCCAnalyses/VertexFinderLCFIPlus.h"
#include "FCCAnalyses/VertexFitterSimple.h"
#include "FCCAnalyses/VertexingUtils.h"
#include "FCCAnalyses/WeaverUtils.h"
#include "FCCAnalyses/dummyLoader.h"
#include "FCCAnalyses/myFinalSel.h"
#include "FCCAnalyses/myUtils.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex>", payloadCode, "@",
"ROOT::VecOps::RVec<ROOT::VecOps::RVec<FCCAnalyses::VertexingUtils::FCCAnalysesVertex> >", payloadCode, "@",
"ROOT::VecOps::RVec<ROOT::VecOps::RVec<TLorentzVector> >", payloadCode, "@",
"ROOT::VecOps::RVec<ROOT::VecOps::RVec<TVector3> >", payloadCode, "@",
"ROOT::VecOps::RVec<ROOT::VecOps::RVec<double> >", payloadCode, "@",
"ROOT::VecOps::RVec<ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> >", payloadCode, "@",
"ROOT::VecOps::RVec<ROOT::VecOps::RVec<float> >", payloadCode, "@",
"ROOT::VecOps::RVec<ROOT::VecOps::RVec<int> >", payloadCode, "@",
"ROOT::VecOps::RVec<TLorentzVector>", payloadCode, "@",
"ROOT::VecOps::RVec<TVector3>", payloadCode, "@",
"ROOT::VecOps::RVec<edm4hep::CalorimeterHitData>", payloadCode, "@",
"ROOT::VecOps::RVec<edm4hep::ClusterData>", payloadCode, "@",
"ROOT::VecOps::RVec<edm4hep::MCParticleData>", payloadCode, "@",
"ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>", payloadCode, "@",
"ROOT::VecOps::RVec<edm4hep::TrackState>", payloadCode, "@",
"ROOT::VecOps::RVec<edm4hep::Vector3d>", payloadCode, "@",
"ROOT::VecOps::RVec<edm4hep::VertexData>", payloadCode, "@",
"ROOT::VecOps::RVec<podio::ObjectID>", payloadCode, "@",
"ROOT::VecOps::RVec<std::vector<float> >", payloadCode, "@",
"ROOT::VecOps::RVec<vector<float> >", payloadCode, "@",
"dummyLoader", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libFCCAnalyses",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libFCCAnalyses_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libFCCAnalyses_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libFCCAnalyses() {
  TriggerDictionaryInitialization_libFCCAnalyses_Impl();
}
