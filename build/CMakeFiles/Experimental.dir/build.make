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

# Utility rule file for Experimental.

# Include any custom commands dependencies for this target.
include CMakeFiles/Experimental.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Experimental.dir/progress.make

CMakeFiles/Experimental:
	/cvmfs/sw.hsf.org/key4hep/releases/2024-03-10/x86_64-almalinux9-gcc11.3.1-opt/cmake/3.27.9-4qfmfr/bin/ctest -D Experimental

Experimental: CMakeFiles/Experimental
Experimental: CMakeFiles/Experimental.dir/build.make
.PHONY : Experimental

# Rule to build all files generated by this target.
CMakeFiles/Experimental.dir/build: Experimental
.PHONY : CMakeFiles/Experimental.dir/build

CMakeFiles/Experimental.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Experimental.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Experimental.dir/clean

CMakeFiles/Experimental.dir/depend:
	cd /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/CMakeFiles/Experimental.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Experimental.dir/depend

