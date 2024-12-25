# - Config file for the FCCANALYSES package

# - Define exported version
set(FCCANALYSES_VERSION "0.9.0")

# - Init CMakePackageConfigHelpers

####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was FCCAnalysesConfig.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################

# - Create relocatable paths to headers.
# NOTE: Do not strictly need paths as all usage requirements are encoded in
# the imported targets created later.
set_and_check(FCCANALYSES_INCLUDE_DIR "${PACKAGE_PREFIX_DIR}/include")

include(CMakeFindDependencyMacro)
find_dependency(EDM4HEP REQUIRED)
find_dependency(podio)
find_dependency(Acts)
find_dependency(ROOT COMPONENTS ROOTDataFrame)
find_dependency(DD4hep)



# - Include the targets file to create the imported targets that a client can
# link to (libraries) or execute (programs)
include("${CMAKE_CURRENT_LIST_DIR}/FCCAnalysesTargets.cmake")

# print the default "Found:" message and check library location
include(FindPackageHandleStandardArgs)
get_property(TEST_FCCANALYSES_LIBRARY TARGET FCCAnalyses::FCCAnalyses PROPERTY LOCATION)
find_package_handle_standard_args(FCCAnalyses DEFAULT_MSG CMAKE_CURRENT_LIST_FILE TEST_FCCANALYSES_LIBRARY)
