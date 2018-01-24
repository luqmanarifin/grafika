cmake_minimum_required (VERSION 2.8.11)
project (GRAFIKA)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# For pthread
find_package (Threads)

# For OpenMP
find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

# Add link dependencies recursively
macro (add_executable _name)
    # invoke built-in add_executable
    add_definitions(${grafika_DEFINITIONS})
    _add_executable(${ARGV})
    if (TARGET ${_name})
        target_link_libraries (${_name} grafika ${CMAKE_THREAD_LIBS_INIT})
    endif()
endmacro()

add_subdirectory (common)
add_subdirectory (grafika1)
add_subdirectory (grafika2)
add_subdirectory (grafika3)
add_subdirectory (grafika4)
add_subdirectory (grafika5)
add_subdirectory (grafika6)
add_subdirectory (grafika7)
add_subdirectory (grafika8)