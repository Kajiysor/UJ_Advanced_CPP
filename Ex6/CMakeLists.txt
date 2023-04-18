add_executable(Ex6_1 src/main.cpp)
add_executable(Ex6_2 src/main2.cpp)
add_executable(Ex6_3 src/main3.cpp)
add_executable(Ex6_4 src/main4.cpp)

target_include_directories(Ex6_1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/Ex6_1)
target_include_directories(Ex6_2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/Ex6_2)
target_include_directories(Ex6_3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/Ex6_3)
target_include_directories(Ex6_4 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/Ex6_4)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
