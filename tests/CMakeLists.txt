#googletest is taken from the submodule --> https://cliutils.gitlab.io/modern-cmake/chapters/testing/googletest.html   
add_subdirectory("${PROJECT_SOURCE_DIR}/lib/googletest" "lib/googletest")

macro(add_test_files TESTNAME)
    add_executable(${TESTNAME} ${ARGN})
    target_link_libraries(${TESTNAME} gtest gmock gtest_main)
    add_test(${TESTNAME} ${TESTNAME})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER test)
endmacro()

add_test_files(benri_tests casts.cpp
                           chrono.cpp
                           everything.cpp
                           one.cpp 
                           constants.cpp
                           quantity.cpp
                           quantity_point.cpp
                           temperature.cpp)
target_link_libraries(benri_tests benri)
