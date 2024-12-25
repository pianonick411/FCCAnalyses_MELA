add_test( UT_flavtagging /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/addons/ONNXRuntime/onnxruntime-unittest flavtagging  )
set_tests_properties( UT_flavtagging PROPERTIES WORKING_DIRECTORY /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/addons/ONNXRuntime)
set( onnxruntime-unittest_TESTS UT_flavtagging)
