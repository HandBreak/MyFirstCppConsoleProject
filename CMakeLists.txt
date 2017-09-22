cmake_minimum_required(VERSION 2.6)
project(myfirstcppconsoleproject)

add_executable(myfirstcppconsoleproject main.cpp)

install(TARGETS myfirstcppconsoleproject RUNTIME DESTINATION bin)
