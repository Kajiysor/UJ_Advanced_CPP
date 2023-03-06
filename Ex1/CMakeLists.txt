add_executable(Ex1 src/main.cpp)

target_include_directories(Ex1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )
