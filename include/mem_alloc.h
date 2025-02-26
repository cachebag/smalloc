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

  void* allocate(size_t size);
  void deallocate(void* ptr);
  void printMemoryLayout();

};


#endif // MEM_ALLOC_H
