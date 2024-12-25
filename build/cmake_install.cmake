# Install script for directory: /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/cmake/FCCAnalyses" TYPE FILE FILES "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/FCCAnalysesConfig.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/FCCAnalyses/FCCAnalysesTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/FCCAnalyses/FCCAnalysesTargets.cmake"
         "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/CMakeFiles/Export/00392d573260ab0586859ce8d7b9868b/FCCAnalysesTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/FCCAnalyses/FCCAnalysesTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/FCCAnalyses/FCCAnalysesTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/cmake/FCCAnalyses" TYPE FILE FILES "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/CMakeFiles/Export/00392d573260ab0586859ce8d7b9868b/FCCAnalysesTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/cmake/FCCAnalyses" TYPE FILE FILES "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/CMakeFiles/Export/00392d573260ab0586859ce8d7b9868b/FCCAnalysesTargets-noconfig.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM FILES "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/bin/fccanalysis")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/install/python/__init__.py;/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/install/python/anascript.py;/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/install/python/build_analysis.py;/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/install/python/do_combine.py;/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/install/python/do_plots.py;/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/install/python/frame.py;/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/install/python/init_analysis.py;/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/install/python/parsers.py;/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/install/python/pin_analysis.py;/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/install/python/process.py;/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/install/python/run_analysis.py;/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/install/python/run_final_analysis.py;/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/install/python/test_fccanalyses.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/install/python" TYPE FILE FILES
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/python/__init__.py"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/python/anascript.py"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/python/build_analysis.py"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/python/do_combine.py"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/python/do_plots.py"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/python/frame.py"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/python/init_analysis.py"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/python/parsers.py"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/python/pin_analysis.py"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/python/process.py"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/python/run_analysis.py"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/python/run_final_analysis.py"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/python/test_fccanalyses.py"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/install/share/man/man1/fccanalysis-build.1;/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/install/share/man/man1/fccanalysis-run.1;/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/install/share/man/man1/fccanalysis-test.1;/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/install/share/man/man1/fccanalysis.1")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/install/share/man/man1" TYPE FILE FILES
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/man/man1/fccanalysis-build.1"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/man/man1/fccanalysis-run.1"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/man/man1/fccanalysis-test.1"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/man/man1/fccanalysis.1"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/install/share/man/man7/fccanalysis-script.7")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/install/share/man/man7" TYPE FILE FILES "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/man/man7/fccanalysis-script.7")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/install/share/examples/examples")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/install/share/examples" TYPE DIRECTORY FILES "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/examples")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/addons/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/analyzers/dataframe/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/case-studies/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/FCCAnalyses/doxygen" TYPE DIRECTORY OPTIONAL FILES "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/doxygen")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/tests/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
