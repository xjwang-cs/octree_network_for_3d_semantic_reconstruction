# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xiaojwan/thesis/octree_primal_dual

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xiaojwan/thesis/octree_primal_dual/build

# Include any dependencies generated for this target.
include tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/depend.make

# Include the progress variables for this target.
include tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/progress.make

# Include the compile flags for this target's objects.
include tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/flags.make

tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/scannet_groundtruth_octree_converter.cpp.o: tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/flags.make
tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/scannet_groundtruth_octree_converter.cpp.o: ../tools/scannet_groundtruth_octree_converter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xiaojwan/thesis/octree_primal_dual/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/scannet_groundtruth_octree_converter.cpp.o"
	cd /home/xiaojwan/thesis/octree_primal_dual/build/tools && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/scannet_groundtruth_octree_converter.dir/scannet_groundtruth_octree_converter.cpp.o -c /home/xiaojwan/thesis/octree_primal_dual/tools/scannet_groundtruth_octree_converter.cpp

tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/scannet_groundtruth_octree_converter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/scannet_groundtruth_octree_converter.dir/scannet_groundtruth_octree_converter.cpp.i"
	cd /home/xiaojwan/thesis/octree_primal_dual/build/tools && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xiaojwan/thesis/octree_primal_dual/tools/scannet_groundtruth_octree_converter.cpp > CMakeFiles/scannet_groundtruth_octree_converter.dir/scannet_groundtruth_octree_converter.cpp.i

tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/scannet_groundtruth_octree_converter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/scannet_groundtruth_octree_converter.dir/scannet_groundtruth_octree_converter.cpp.s"
	cd /home/xiaojwan/thesis/octree_primal_dual/build/tools && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xiaojwan/thesis/octree_primal_dual/tools/scannet_groundtruth_octree_converter.cpp -o CMakeFiles/scannet_groundtruth_octree_converter.dir/scannet_groundtruth_octree_converter.cpp.s

tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/scannet_groundtruth_octree_converter.cpp.o.requires:

.PHONY : tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/scannet_groundtruth_octree_converter.cpp.o.requires

tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/scannet_groundtruth_octree_converter.cpp.o.provides: tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/scannet_groundtruth_octree_converter.cpp.o.requires
	$(MAKE) -f tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/build.make tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/scannet_groundtruth_octree_converter.cpp.o.provides.build
.PHONY : tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/scannet_groundtruth_octree_converter.cpp.o.provides

tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/scannet_groundtruth_octree_converter.cpp.o.provides.build: tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/scannet_groundtruth_octree_converter.cpp.o


# Object files for target scannet_groundtruth_octree_converter
scannet_groundtruth_octree_converter_OBJECTS = \
"CMakeFiles/scannet_groundtruth_octree_converter.dir/scannet_groundtruth_octree_converter.cpp.o"

# External object files for target scannet_groundtruth_octree_converter
scannet_groundtruth_octree_converter_EXTERNAL_OBJECTS =

tools/scannet_groundtruth_octree_converter: tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/scannet_groundtruth_octree_converter.cpp.o
tools/scannet_groundtruth_octree_converter: tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/build.make
tools/scannet_groundtruth_octree_converter: lib/libcaffe.so.1.0.0-rc5
tools/scannet_groundtruth_octree_converter: lib/libproto.a
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libboost_system.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libboost_thread.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libboost_serialization.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libpthread.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libglog.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libgflags.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/hdf5/serial/lib/libhdf5_hl.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/hdf5/serial/lib/libhdf5.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libsz.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libz.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libdl.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libm.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libpthread.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libglog.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libgflags.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/hdf5/serial/lib/libhdf5_hl.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/hdf5/serial/lib/libhdf5.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libsz.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libz.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libdl.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libm.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libprotobuf.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/liblmdb.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libleveldb.so
tools/scannet_groundtruth_octree_converter: /usr/local/cuda-9.0/lib64/libcudart.so
tools/scannet_groundtruth_octree_converter: /usr/local/cuda-9.0/lib64/libcurand.so
tools/scannet_groundtruth_octree_converter: /usr/local/cuda-9.0/lib64/libcublas.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libcudnn.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.9
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.9
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.9
tools/scannet_groundtruth_octree_converter: /usr/lib/liblapack.so
tools/scannet_groundtruth_octree_converter: /usr/lib/libcblas.so
tools/scannet_groundtruth_octree_converter: /usr/lib/libatlas.so
tools/scannet_groundtruth_octree_converter: /usr/lib/x86_64-linux-gnu/libboost_python.so
tools/scannet_groundtruth_octree_converter: tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xiaojwan/thesis/octree_primal_dual/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable scannet_groundtruth_octree_converter"
	cd /home/xiaojwan/thesis/octree_primal_dual/build/tools && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/scannet_groundtruth_octree_converter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/build: tools/scannet_groundtruth_octree_converter

.PHONY : tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/build

tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/requires: tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/scannet_groundtruth_octree_converter.cpp.o.requires

.PHONY : tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/requires

tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/clean:
	cd /home/xiaojwan/thesis/octree_primal_dual/build/tools && $(CMAKE_COMMAND) -P CMakeFiles/scannet_groundtruth_octree_converter.dir/cmake_clean.cmake
.PHONY : tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/clean

tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/depend:
	cd /home/xiaojwan/thesis/octree_primal_dual/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xiaojwan/thesis/octree_primal_dual /home/xiaojwan/thesis/octree_primal_dual/tools /home/xiaojwan/thesis/octree_primal_dual/build /home/xiaojwan/thesis/octree_primal_dual/build/tools /home/xiaojwan/thesis/octree_primal_dual/build/tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/CMakeFiles/scannet_groundtruth_octree_converter.dir/depend

