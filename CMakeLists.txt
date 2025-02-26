cmake_minimum_required(VERSION 3.10)
project(MemoryAllocator)

set(CMAKE_CXX_STANDARD 17)

add_executable(memory_allocator src/mem_alloc.cpp src/main.cpp)
target_include_directories(memory_allocator PRIVATE include)

