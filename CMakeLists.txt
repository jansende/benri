#this project is valid for cmake 3.1 to 3.11
cmake_minimum_required(VERSION 3.1...3.11)
#fix the above syntax for cmake <3.12
if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_VERSION})
endif()

#create the benri project
project(benri VERSION 0.1.0
              DESCRIPTION "benri is a c++ library for working with physical quantities, with abilities for math on physical units and conversions between them."
              LANGUAGES CXX)

#add additional build options
option(BENRI_CPP17_ENABLED "Compile using c++17 flags" OFF)
#add library interface
add_library(benri INTERFACE)
#add header files
target_include_directories(benri INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
#add compile features
if (BENRI_CPP17_ENABLED)
    target_compile_features(benri INTERFACE cxx_std_17)
else()
    target_compile_features(benri INTERFACE cxx_std_14)
endif()