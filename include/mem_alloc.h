#ifndef MEM_ALLOC_H
#define MEM_ALLOC_H

#include <cstddef>

struct BlockHeader {
  size_t size;
  bool isFree;
  BlockHeader* next;
};

class MemoryAllocator {

private:
  void* memoryPool;
  BlockHeader* freeList;
  size_t totalSize;

public:
  MemoryAllocator(size_t size);
  ~MemoryAllocator();

  // TODO: Implement allocate() to find a free block and allocate memory.
  void* allocate(size_t size);

  // TODO: Implement deallocate() to free memory and merge adjacent blocks.
  void deallocate(void* ptr);

  // TODO: Implement a function to print memory usage statistics.
  void printMemoryLayout();

  // TODO: Implement memory defragmentation to merge and optimize free memory.
};

#endif // MEM_ALLOC_H

