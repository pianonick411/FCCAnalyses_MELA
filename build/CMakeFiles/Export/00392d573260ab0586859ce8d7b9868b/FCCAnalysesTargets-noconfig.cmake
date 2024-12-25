#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "FCCAnalyses::FastJet" for configuration ""
set_property(TARGET FCCAnalyses::FastJet APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(FCCAnalyses::FastJet PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libFastJet.so"
  IMPORTED_SONAME_NOCONFIG "libFastJet.so"
  )

list(APPEND _cmake_import_check_targets FCCAnalyses::FastJet )
list(APPEND _cmake_import_check_files_for_FCCAnalyses::FastJet "${_IMPORT_PREFIX}/lib/libFastJet.so" )

# Import target "FCCAnalyses::ONNXRuntime" for configuration ""
set_property(TARGET FCCAnalyses::ONNXRuntime APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(FCCAnalyses::ONNXRuntime PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libONNXRuntime.so"
  IMPORTED_SONAME_NOCONFIG "libONNXRuntime.so"
  )

list(APPEND _cmake_import_check_targets FCCAnalyses::ONNXRuntime )
list(APPEND _cmake_import_check_files_for_FCCAnalyses::ONNXRuntime "${_IMPORT_PREFIX}/lib/libONNXRuntime.so" )

# Import target "FCCAnalyses::TMVAHelper" for configuration ""
set_property(TARGET FCCAnalyses::TMVAHelper APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(FCCAnalyses::TMVAHelper PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_NOCONFIG "TBB::tbb;ROOT::ROOTVecOps;ROOT::TMVA"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libTMVAHelper.so"
  IMPORTED_SONAME_NOCONFIG "libTMVAHelper.so"
  )

list(APPEND _cmake_import_check_targets FCCAnalyses::TMVAHelper )
list(APPEND _cmake_import_check_files_for_FCCAnalyses::TMVAHelper "${_IMPORT_PREFIX}/lib/libTMVAHelper.so" )

# Import target "FCCAnalyses::FCCAnalyses" for configuration ""
set_property(TARGET FCCAnalyses::FCCAnalyses APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(FCCAnalyses::FCCAnalyses PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libFCCAnalyses.so"
  IMPORTED_SONAME_NOCONFIG "libFCCAnalyses.so"
  )

list(APPEND _cmake_import_check_targets FCCAnalyses::FCCAnalyses )
list(APPEND _cmake_import_check_files_for_FCCAnalyses::FCCAnalyses "${_IMPORT_PREFIX}/lib/libFCCAnalyses.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
