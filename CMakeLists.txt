cmake_minimum_required(VERSION 3.16)
project(GraphProcessor)

set(CMAKE_CXX_STANDARD 17)

add_executable(graphProcessor gp/GraphHandler.cpp gp/GraphHandler.h gp/Graph.cpp gp/Graph.h gp/GraphNode.cpp gp/GraphNode.h gp/Edges.h gp/GraphProcessor.h source.cpp gp/GraphLib.h gp/GraphDefines.h gp/GraphLib.cpp)