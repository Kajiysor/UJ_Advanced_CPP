add_executable(Ex2 src/main.cpp)

target_include_directories(Ex2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )
