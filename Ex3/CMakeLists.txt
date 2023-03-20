add_executable(Ex3 src/main.cpp)

target_include_directories(Ex3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
