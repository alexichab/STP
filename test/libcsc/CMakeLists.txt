set(test_name time)
add_executable(
  ${test_name}.test
  ${test_name}.cpp
)

set_compile_options(${test_name}.test)

target_include_directories(
  ${test_name}.test
  PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(
  ${test_name}.test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${test_name}.test)

