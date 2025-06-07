cmake_minimum_required(VERSION 3.10)
project(AuthenticationTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(/opt/homebrew/include)
link_directories(/opt/homebrew/lib)

# Test 1: random_seed (opcional)
add_executable(test_random_seed test_random_seed.cpp)
target_link_libraries(test_random_seed gtest gtest_main pthread)

# ✅ Test 2: authentication
add_executable(test_authentication test_authentication.cpp)
target_link_libraries(test_authentication gtest gmock gtest_main pthread)
