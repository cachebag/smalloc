#include "../include/mem_alloc.h"
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <new>
#include <iostream>
using namespace std;

// Initalize memory pool
MemoryAllocator::MemoryAllocator(size_t size) {

  totalSize = size;
  memoryPool = malloc(size); // Allocate raw memory block

  if (!memoryPool) {
    throw bad_alloc();
  }

  // Intialize first block as a single large free block
  freeList = static_cast<BlockHeader*>(memoryPool);
  freeList->size = size - sizeof(BlockHeader);
  freeList->isFree = true;
  freeList->next = nullptr;

}

// Destructor
MemoryAllocator::~MemoryAllocator() {
  
  free(memoryPool);

}

// TODO: Implement memory allocation logic in allocate().
//       - Search the free list for a suitable block.
//       - Split larger blocks if needed.
//       - Return a pointer to the allocated memory.
//       - Handle cases where no block is large enough.
void* MemoryAllocator::allocate(size_t size) {
  // TODO: Implement this function.
  return nullptr;
}

// TODO: Implement memory deallocation logic in deallocate().
//       - Mark the block as free.
//       - Merge adjacent free blocks to reduce fragmentation.
void MemoryAllocator::deallocate(void* ptr) {
  // TODO: Implement this function.
}

// Debug function to print memory layout
void MemoryAllocator::printMemoryLayout() {
  
  BlockHeader* current = freeList;

  cout << "Memory Layout: \n ";

  while (current) {
    cout << "[Block: " << (current->isFree ? "Free" : "Allocated") 
         << ", Size: " << current->size << " bytes]\n";
    current = current->next;
  }
  
  // TODO: Improve formatting for better readability.
  // TODO: Optionally include memory addresses.
}

// TODO: Implement a method to check total allocated and free memory.
// TODO: Implement memory defragmentation to compact free blocks.

