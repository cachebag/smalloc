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

  // DONE
  // TODO: Implement allocate() to find a free block and allocate memory.
  void* allocate(size_t size) {
    BlockHeader* current = freeList;
    BlockHeader* prev = nullptr;

    while (current) {
      if (current->isFree && current->size >= size) {
        if ( current->size >= size + sizeof(BlockHeader)) {
          BlockHeader* newBlock = reinterpret_cast<BlockHeader*>(
            reinterpret_cast<char*>(current) + sizeof(BlockHeader) + size
          );
          newBlock->size = current->size - size - sizeof(BlockHeader);
          newBlock->isFree = true;
          newBlock->next = current->next;
          current->next = newBlock;
        }

        current->size = size;
        current->isFree = false;
        return reinterpret_cast<void*>(current + 1);
      }
      prev = current;
      current = current->next;
    }
    return nullptr;
  }



  // DONE 
  // TODO: Implement deallocate() to free memory and merge adjacent blocks.
  void deallocate(void* ptr) {
    if (!ptr) return;

    BlockHeader* block = reinterpret_cast<BlockHeader*>(static_cast<char*>(ptr) - sizeof(BlockHeader));
    block->isFree = true;

    BlockHeader* current = freeList;
    while (current) {
      if (current->isFree && current->next && current->next->isFree) {
        current->size += current->next->size + sizeof(BlockHeader);
        current->next = current->next->next;
      }
      current = current->next;
    }
  }

  // TODO: Implement a function to print memory usage statistics.
  void printMemoryLayout();

  // TODO: Implement memory defragmentation to merge and optimize free memory.
};

#endif // MEM_ALLOC_H

