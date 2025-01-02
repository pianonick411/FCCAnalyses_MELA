# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/cmake/3.27.9-4qfmfr/bin/cmake

# The command to remove a file.
RM = /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/cmake/3.27.9-4qfmfr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build

# Include any dependencies generated for this target.
include tests/benchmark/CMakeFiles/bench.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/benchmark/CMakeFiles/bench.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/benchmark/CMakeFiles/bench.dir/progress.make

# Include the compile flags for this target's objects.
include tests/benchmark/CMakeFiles/bench.dir/flags.make

tests/benchmark/CMakeFiles/bench.dir/algorithms.cpp.o: tests/benchmark/CMakeFiles/bench.dir/flags.make
tests/benchmark/CMakeFiles/bench.dir/algorithms.cpp.o: /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/tests/benchmark/algorithms.cpp
tests/benchmark/CMakeFiles/bench.dir/algorithms.cpp.o: tests/benchmark/CMakeFiles/bench.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/benchmark/CMakeFiles/bench.dir/algorithms.cpp.o"
	cd /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/tests/benchmark && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/benchmark/CMakeFiles/bench.dir/algorithms.cpp.o -MF CMakeFiles/bench.dir/algorithms.cpp.o.d -o CMakeFiles/bench.dir/algorithms.cpp.o -c /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/tests/benchmark/algorithms.cpp

tests/benchmark/CMakeFiles/bench.dir/algorithms.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/bench.dir/algorithms.cpp.i"
	cd /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/tests/benchmark && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/tests/benchmark/algorithms.cpp > CMakeFiles/bench.dir/algorithms.cpp.i

tests/benchmark/CMakeFiles/bench.dir/algorithms.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/bench.dir/algorithms.cpp.s"
	cd /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/tests/benchmark && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/tests/benchmark/algorithms.cpp -o CMakeFiles/bench.dir/algorithms.cpp.s

tests/benchmark/CMakeFiles/bench.dir/myutils.cpp.o: tests/benchmark/CMakeFiles/bench.dir/flags.make
tests/benchmark/CMakeFiles/bench.dir/myutils.cpp.o: /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/tests/benchmark/myutils.cpp
tests/benchmark/CMakeFiles/bench.dir/myutils.cpp.o: tests/benchmark/CMakeFiles/bench.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/benchmark/CMakeFiles/bench.dir/myutils.cpp.o"
	cd /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/tests/benchmark && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/benchmark/CMakeFiles/bench.dir/myutils.cpp.o -MF CMakeFiles/bench.dir/myutils.cpp.o.d -o CMakeFiles/bench.dir/myutils.cpp.o -c /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/tests/benchmark/myutils.cpp

tests/benchmark/CMakeFiles/bench.dir/myutils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/bench.dir/myutils.cpp.i"
	cd /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/tests/benchmark && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/tests/benchmark/myutils.cpp > CMakeFiles/bench.dir/myutils.cpp.i

tests/benchmark/CMakeFiles/bench.dir/myutils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/bench.dir/myutils.cpp.s"
	cd /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/tests/benchmark && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/tests/benchmark/myutils.cpp -o CMakeFiles/bench.dir/myutils.cpp.s

# Object files for target bench
bench_OBJECTS = \
"CMakeFiles/bench.dir/algorithms.cpp.o" \
"CMakeFiles/bench.dir/myutils.cpp.o"

# External object files for target bench
bench_EXTERNAL_OBJECTS =

tests/benchmark/bench: tests/benchmark/CMakeFiles/bench.dir/algorithms.cpp.o
tests/benchmark/bench: tests/benchmark/CMakeFiles/bench.dir/myutils.cpp.o
tests/benchmark/bench: tests/benchmark/CMakeFiles/bench.dir/build.make
tests/benchmark/bench: analyzers/dataframe/libFCCAnalyses.so
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/catch2/3.4.0-7ueg7p/lib64/libCatch2Main.a
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/lib/root/libROOTDataFrame.so.6.28.10
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/lib/root/libROOTNTuple.so.6.28.10
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/edm4hep/0.10.5-27swdr/lib64/libedm4hepDict.so
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/edm4hep/0.10.5-27swdr/lib64/libedm4hep.so
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/podio/0.99-uovuyy/lib64/libpodio.so
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/delphes/master-rapnt2/lib/libDelphes.so
tests/benchmark/bench: addons/FastJet/libFastJet.so
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/fastjet/3.4.1-pi2dtg/lib/libfastjet.so
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/fastjet/3.4.1-pi2dtg/lib/libfastjetplugins.so
tests/benchmark/bench: addons/ONNXRuntime/libONNXRuntime.so
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/py-onnxruntime/1.10.0-lvflvi/lib64/libonnxruntime.so
tests/benchmark/bench: addons/TMVAHelper/libTMVAHelper.so
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/lib/root/libROOTVecOps.so.6.28.10
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/vdt/0.4.4-bx2smv/lib/libvdt.so
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/lib/root/libTreePlayer.so.6.28.10
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/lib/root/libGraf3d.so.6.28.10
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/lib/root/libGpad.so.6.28.10
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/lib/root/libGraf.so.6.28.10
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/dd4hep/1.28-q6ea5f/lib/libDDCore.so.1.28
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/lib/root/libPhysics.so.6.28.10
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/lib/root/libTree.so.6.28.10
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/dd4hep/1.28-q6ea5f/lib/libDDParsers.so.1.28
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/lib/root/libGenVector.so.6.28.10
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/lib/root/libRint.so.6.28.10
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/lib/root/libGeom.so.6.28.10
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/lib/root/libHist.so.6.28.10
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/lib/root/libMatrix.so.6.28.10
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/lib/root/libMathCore.so.6.28.10
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/lib/root/libImt.so.6.28.10
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/lib/root/libMultiProc.so.6.28.10
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/lib/root/libNet.so.6.28.10
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/lib/root/libRIO.so.6.28.10
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/lib/root/libThread.so.6.28.10
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/root/6.28.10-j6yheu/lib/root/libCore.so.6.28.10
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/xerces-c/3.2.4-ergagi/lib/libxerces-c.so
tests/benchmark/bench: /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/catch2/3.4.0-7ueg7p/lib64/libCatch2.a
tests/benchmark/bench: tests/benchmark/CMakeFiles/bench.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable bench"
	cd /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/tests/benchmark && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bench.dir/link.txt --verbose=$(VERBOSE)
	cd /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/tests/benchmark && /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/cmake/3.27.9-4qfmfr/bin/cmake -D TEST_TARGET=bench -D TEST_EXECUTABLE=/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/tests/benchmark/bench -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/tests/benchmark -D TEST_SPEC= -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX=B_ -D TEST_SUFFIX= -D TEST_LIST=bench_TESTS -D TEST_REPORTER= -D TEST_OUTPUT_DIR= -D TEST_OUTPUT_PREFIX= -D TEST_OUTPUT_SUFFIX= -D TEST_DL_PATHS= -D CTEST_FILE=/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/tests/benchmark/bench_tests-b12d07c.cmake -P /cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/catch2/3.4.0-7ueg7p/lib64/cmake/Catch2/CatchAddTests.cmake

# Rule to build all files generated by this target.
tests/benchmark/CMakeFiles/bench.dir/build: tests/benchmark/bench
.PHONY : tests/benchmark/CMakeFiles/bench.dir/build

tests/benchmark/CMakeFiles/bench.dir/clean:
	cd /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/tests/benchmark && $(CMAKE_COMMAND) -P CMakeFiles/bench.dir/cmake_clean.cmake
.PHONY : tests/benchmark/CMakeFiles/bench.dir/clean

tests/benchmark/CMakeFiles/bench.dir/depend:
	cd /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/tests/benchmark /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/tests/benchmark /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/tests/benchmark/CMakeFiles/bench.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/benchmark/CMakeFiles/bench.dir/depend
