add_executable(Ex10 src/main.cpp)

target_include_directories(Ex10 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
