# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\hollow\Desktop\xiaomi\UpperTester

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\hollow\Desktop\xiaomi\UpperTester\build\default_qt_qt6-Debug

# Utility rule file for UpperTester_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/UpperTester_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/UpperTester_autogen.dir/progress.make

CMakeFiles/UpperTester_autogen: UpperTester_autogen/timestamp

UpperTester_autogen/timestamp: D:/Qt6.8/6.8.0/mingw_64/bin/moc.exe
UpperTester_autogen/timestamp: D:/Qt6.8/6.8.0/mingw_64/bin/uic.exe
UpperTester_autogen/timestamp: CMakeFiles/UpperTester_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\hollow\Desktop\xiaomi\UpperTester\build\default_qt_qt6-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target UpperTester"
	"C:\Program Files\CMake\bin\cmake.exe" -E cmake_autogen C:/Users/hollow/Desktop/xiaomi/UpperTester/build/default_qt_qt6-Debug/CMakeFiles/UpperTester_autogen.dir/AutogenInfo.json Debug
	"C:\Program Files\CMake\bin\cmake.exe" -E touch C:/Users/hollow/Desktop/xiaomi/UpperTester/build/default_qt_qt6-Debug/UpperTester_autogen/timestamp

CMakeFiles/UpperTester_autogen.dir/codegen:
.PHONY : CMakeFiles/UpperTester_autogen.dir/codegen

UpperTester_autogen: CMakeFiles/UpperTester_autogen
UpperTester_autogen: UpperTester_autogen/timestamp
UpperTester_autogen: CMakeFiles/UpperTester_autogen.dir/build.make
.PHONY : UpperTester_autogen

# Rule to build all files generated by this target.
CMakeFiles/UpperTester_autogen.dir/build: UpperTester_autogen
.PHONY : CMakeFiles/UpperTester_autogen.dir/build

CMakeFiles/UpperTester_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\UpperTester_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles/UpperTester_autogen.dir/clean

CMakeFiles/UpperTester_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\hollow\Desktop\xiaomi\UpperTester C:\Users\hollow\Desktop\xiaomi\UpperTester C:\Users\hollow\Desktop\xiaomi\UpperTester\build\default_qt_qt6-Debug C:\Users\hollow\Desktop\xiaomi\UpperTester\build\default_qt_qt6-Debug C:\Users\hollow\Desktop\xiaomi\UpperTester\build\default_qt_qt6-Debug\CMakeFiles\UpperTester_autogen.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/UpperTester_autogen.dir/depend

