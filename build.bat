IF EXIST out (
    rmdir /s /q out
)

mkdir out
cd out
cmake .. -G "Visual Studio 17 2022" -A x64 -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release