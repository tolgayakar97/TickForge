mkdir out
cd out
cmake .. -G Ninja -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release -j%NUMBER_OF_PROCESSORS%