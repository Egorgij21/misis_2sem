# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.25.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.25.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/egorgij21/Desktop/aparin

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/egorgij21/Desktop/aparin/build

# Include any dependencies generated for this target.
include CMakeFiles/rational.doctest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/rational.doctest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/rational.doctest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rational.doctest.dir/flags.make

CMakeFiles/rational.doctest.dir/rational.doctest.cpp.o: CMakeFiles/rational.doctest.dir/flags.make
CMakeFiles/rational.doctest.dir/rational.doctest.cpp.o: /Users/egorgij21/Desktop/aparin/rational.doctest.cpp
CMakeFiles/rational.doctest.dir/rational.doctest.cpp.o: CMakeFiles/rational.doctest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/egorgij21/Desktop/aparin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rational.doctest.dir/rational.doctest.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/rational.doctest.dir/rational.doctest.cpp.o -MF CMakeFiles/rational.doctest.dir/rational.doctest.cpp.o.d -o CMakeFiles/rational.doctest.dir/rational.doctest.cpp.o -c /Users/egorgij21/Desktop/aparin/rational.doctest.cpp

CMakeFiles/rational.doctest.dir/rational.doctest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rational.doctest.dir/rational.doctest.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/egorgij21/Desktop/aparin/rational.doctest.cpp > CMakeFiles/rational.doctest.dir/rational.doctest.cpp.i

CMakeFiles/rational.doctest.dir/rational.doctest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rational.doctest.dir/rational.doctest.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/egorgij21/Desktop/aparin/rational.doctest.cpp -o CMakeFiles/rational.doctest.dir/rational.doctest.cpp.s

# Object files for target rational.doctest
rational_doctest_OBJECTS = \
"CMakeFiles/rational.doctest.dir/rational.doctest.cpp.o"

# External object files for target rational.doctest
rational_doctest_EXTERNAL_OBJECTS =

bin.dbg/rational.doctest: CMakeFiles/rational.doctest.dir/rational.doctest.cpp.o
bin.dbg/rational.doctest: CMakeFiles/rational.doctest.dir/build.make
bin.dbg/rational.doctest: rational/librational.a
bin.dbg/rational.doctest: CMakeFiles/rational.doctest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/egorgij21/Desktop/aparin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin.dbg/rational.doctest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rational.doctest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rational.doctest.dir/build: bin.dbg/rational.doctest
.PHONY : CMakeFiles/rational.doctest.dir/build

CMakeFiles/rational.doctest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rational.doctest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rational.doctest.dir/clean

CMakeFiles/rational.doctest.dir/depend:
	cd /Users/egorgij21/Desktop/aparin/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/egorgij21/Desktop/aparin /Users/egorgij21/Desktop/aparin /Users/egorgij21/Desktop/aparin/build /Users/egorgij21/Desktop/aparin/build /Users/egorgij21/Desktop/aparin/build/CMakeFiles/rational.doctest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rational.doctest.dir/depend

