#!/bin/sh

cd "$(dirname "$0")"
cd build
cmake ..
make -j$(nproc)
sudo cmake --install .
cd ..
php generate_stubs.php > stubs/qt6.stub.php