# Install script for directory: /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/analyzers/dataframe

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

if(CMAKE_INSTALL_COMPONENT STREQUAL "shlib" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFCCAnalyses.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFCCAnalyses.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFCCAnalyses.so"
         RPATH "/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/lib/root:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/edm4hep/0.10.5-27swdr/lib64:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/delphes/master-rapnt2/lib:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/dd4hep/1.28-q6ea5f/lib:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/podio/0.99-uovuyy/lib64:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/fastjet/3.4.1-pi2dtg/lib:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/py-onnxruntime/1.10.0-lvflvi/lib64:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/vdt/0.4.4-bx2smv/lib:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/intel-tbb/2021.9.0-bbs7w4/lib64:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/xerces-c/3.2.4-ergagi/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/analyzers/dataframe/libFCCAnalyses.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFCCAnalyses.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFCCAnalyses.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFCCAnalyses.so"
         OLD_RPATH "/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/lib/root:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/edm4hep/0.10.5-27swdr/lib64:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/delphes/master-rapnt2/lib:/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/addons/FastJet:/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/addons/ONNXRuntime:/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/addons/TMVAHelper:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/dd4hep/1.28-q6ea5f/lib:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/podio/0.99-uovuyy/lib64:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/fastjet/3.4.1-pi2dtg/lib:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/py-onnxruntime/1.10.0-lvflvi/lib64:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/vdt/0.4.4-bx2smv/lib:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/intel-tbb/2021.9.0-bbs7w4/lib64:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/xerces-c/3.2.4-ergagi/lib:"
         NEW_RPATH "/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/lib/root:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/edm4hep/0.10.5-27swdr/lib64:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/delphes/master-rapnt2/lib:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/dd4hep/1.28-q6ea5f/lib:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/podio/0.99-uovuyy/lib64:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/fastjet/3.4.1-pi2dtg/lib:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/py-onnxruntime/1.10.0-lvflvi/lib64:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/vdt/0.4.4-bx2smv/lib:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/intel-tbb/2021.9.0-bbs7w4/lib64:/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/xerces-c/3.2.4-ergagi/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFCCAnalyses.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "shlib" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/FCCAnalyses" TYPE FILE FILES
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/analyzers/dataframe/FCCAnalyses/Algorithms.h"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/analyzers/dataframe/FCCAnalyses/CaloNtupleizer.h"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/analyzers/dataframe/FCCAnalyses/Defines.h"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/analyzers/dataframe/FCCAnalyses/JetClusteringUtils.h"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/analyzers/dataframe/FCCAnalyses/JetConstituentsUtils.h"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/analyzers/dataframe/FCCAnalyses/JetFlavourUtils.h"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/analyzers/dataframe/FCCAnalyses/JetTaggingUtils.h"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/analyzers/dataframe/FCCAnalyses/Logger.h"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/analyzers/dataframe/FCCAnalyses/MCParticle.h"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/analyzers/dataframe/FCCAnalyses/ReconstructedParticle.h"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/analyzers/dataframe/FCCAnalyses/ReconstructedParticle2MC.h"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/analyzers/dataframe/FCCAnalyses/ReconstructedParticle2Track.h"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/analyzers/dataframe/FCCAnalyses/ReconstructedTrack.h"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/analyzers/dataframe/FCCAnalyses/SmearObjects.h"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/analyzers/dataframe/FCCAnalyses/Smearing.h"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/analyzers/dataframe/FCCAnalyses/Utils.h"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/analyzers/dataframe/FCCAnalyses/VertexFinderLCFIPlus.h"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/analyzers/dataframe/FCCAnalyses/VertexFitterSimple.h"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/analyzers/dataframe/FCCAnalyses/VertexingUtils.h"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/analyzers/dataframe/FCCAnalyses/WeaverUtils.h"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/analyzers/dataframe/FCCAnalyses/dummyLoader.h"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/analyzers/dataframe/FCCAnalyses/myFinalSel.h"
    "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/analyzers/dataframe/FCCAnalyses/myUtils.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/analyzers/dataframe/libFCCAnalyses.rootmap")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/analyzers/dataframe/libFCCAnalyses_rdict.pcm")
endif()

