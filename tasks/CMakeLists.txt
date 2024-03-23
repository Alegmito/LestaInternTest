add_library(DivisionByTwo DivisionByTwo.cpp)
add_library(CircularBuffArray CircularBuffArray.cpp)
add_library(CircularBuffList CircularBuffList.cpp)
add_library(MixedSort Sort.cpp)

target_include_directories(DivisionByTwo INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(CircularBuffArray INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(CircularBuffList INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(MixedSort INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
