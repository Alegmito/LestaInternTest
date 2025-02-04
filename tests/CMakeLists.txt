﻿add_executable(LestaInternCPPTest "MixedSortBenchmark.cpp" "MixedSortBenchmark.h")
target_link_libraries(LestaInternCPPTest PUBLIC CircularBuffArray DivisionByTwo)

add_executable(Tests
  CircularBuffArrayTests.cpp
  CircularBuffListTests.cpp
  DivisionByTwoTests.cpp
  MixedSortTests.cpp
 )

 add_executable(MixedSortBenchmark MixedSortBenchmark.cpp MixedSortBenchmark.h)
 target_link_libraries(MixedSortBenchmark PRIVATE MixedSort)

include(FetchContent)
option(INSTALL_GTEST OFF)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

target_link_libraries(Tests PRIVATE
  gtest_main
  CircularBuffArray
  CircularBuffList
  DivisionByTwo
  MixedSort
)

include(GoogleTest)
gtest_discover_tests(Tests)