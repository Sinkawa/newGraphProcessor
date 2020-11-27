cmake_minimum_required(VERSION 3.16)
project(GraphProcessor)

set(CMAKE_CXX_STANDARD 20)

add_executable(AnotherOne GraphHandler.cpp GraphHandler.h Graph.cpp Graph.h GraphNode.cpp GraphNode.h Edges.h GraphProcessor.h source.cpp GraphLib.h)