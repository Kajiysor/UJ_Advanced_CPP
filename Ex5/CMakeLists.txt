add_executable(Ex5 src/main.cpp)

target_include_directories(Ex5 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
