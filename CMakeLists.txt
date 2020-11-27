cmake_minimum_required(VERSION 3.16)
project(GraphProcessor)

set(CMAKE_CXX_STANDARD 20)

add_executable(graphProcessor gp/GraphHandler.cpp gp/GraphHandler.h gp/Graph.cpp gp/Graph.h gp/GraphNode.cpp gp/GraphNode.h gp/Edges.h gp/GraphProcessor.h source.cpp gp/GraphLib.h)