add_library(Network
    src/TcpServer.cpp
    src/TcpClient.cpp
    src/Socket.cpp
)

target_include_directories(Network
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)