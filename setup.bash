function rebuild {
    echo "Building..."
    rm -rf build
    mkdir -p build
    cd build
    cmake ..
    cmake --build . -j6
    cd ..
}

function build {
    echo "Building..."
    cd build
    cmake --build . -j6
    cd ..
}