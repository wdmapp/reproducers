cmake_minimum_required(VERSION 3.18..3.21)
project(gtensor_unravel_reproducer
        VERSION 0.01
        LANGUAGES CXX
        HOMEPAGE_URL https://github.com/wdmapp/gtensor)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/")
include(cmake/CPM.cmake)

if(NOT DEFINED ROCM_PATH)
  set(ROCM_PATH "/opt/rocm")
endif()

CPMAddPackage("gh:wdmapp/gtensor#main")

add_executable(gtensor_unravel_reproducer)
target_gtensor_sources(gtensor_unravel_reproducer PRIVATE src/gtensor_unravel_reproducer.cxx)
target_link_libraries(gtensor_unravel_reproducer gtensor::gtensor)
