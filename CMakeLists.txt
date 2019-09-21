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
option(BENRI_CPP17_ENABLED      "Compile using c++17 flags" OFF)
option(BENRI_UNIT_TESTS_ENABLED "Run Unit Tests"            OFF)
option(BENRI_BUILD_EXAMPLES     "Build Examples"            OFF)

#add library interface
add_library(benri INTERFACE)
#add header files
target_include_directories(benri INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
#add compile features
if (BENRI_CPP17_ENABLED)
    target_compile_features(benri INTERFACE cxx_std_17)
    if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        target_compile_options(benri INTERFACE /Zc:__cplusplus)
    endif()
else()
    target_compile_features(benri INTERFACE cxx_std_14)
endif()

#add unit tests
if(BENRI_UNIT_TESTS_ENABLED)
    #googletest is taken from the submodule --> https://cliutils.gitlab.io/modern-cmake/chapters/testing/googletest.html
    enable_testing()
    add_subdirectory(tests)
    #fix a linker error with msvc
    #--> https://github.com/google/googletest/blob/master/googletest/README.md#visual-studio-dynamic-vs-static-runtimes
    #--> https://stackoverflow.com/questions/12540970/how-to-make-gtest-build-mdd-instead-of-mtd-by-default-using-cmake
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    mark_as_advanced(BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS gmock_build_tests gtest_build_samples gtest_build_tests gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols)
    set_target_properties(gtest PROPERTIES FOLDER lib)
    set_target_properties(gtest_main PROPERTIES FOLDER lib)
    set_target_properties(gmock PROPERTIES FOLDER lib)
    set_target_properties(gmock_main PROPERTIES FOLDER lib)
endif()

#add examples
if(BENRI_BUILD_EXAMPLES)
    add_executable(affine examples/affine.cpp)
    target_link_libraries(affine PUBLIC benri)
    add_executable(cake examples/cake.cpp)
    target_link_libraries(cake PUBLIC benri)
    add_executable(implicit examples/implicit.cpp)
    target_link_libraries(implicit PUBLIC benri)
    add_executable(ostream examples/ostream.cpp)
    target_link_libraries(ostream PUBLIC benri)
    add_executable(oven examples/oven.cpp)
    target_link_libraries(oven PUBLIC benri)
    add_executable(overflow examples/overflow.cpp)
    target_link_libraries(overflow PUBLIC benri)
    add_executable(pirate_ninja examples/pirate_ninja.cpp)
    target_link_libraries(pirate_ninja PUBLIC benri)
    add_executable(radioactivity examples/radioactivity.cpp)
    target_link_libraries(radioactivity PUBLIC benri)
    if(BENRI_CPP17_ENABLED)
        add_executable(runtime examples/runtime.cpp)
        target_link_libraries(runtime PUBLIC benri)
        target_compile_features(runtime PUBLIC cxx_std_17)
        if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
            target_compile_options(runtime PUBLIC /Zc:__cplusplus)
        endif()
    endif()
    add_executable(temperature examples/temperature.cpp)
    target_link_libraries(temperature PUBLIC benri)
endif()