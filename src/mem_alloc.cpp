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

// Debug function to print memory layout
void MemoryAllocator::printMemoryLayout() {
  
  BlockHeader* current = freeList;

  cout << "Memory Layout: \n ";

  while (current) {
    cout << "[Block: " << (current->isFree ? "Free" : "Allocated") 
         << ", Size: " << current->size << " bytes]\n";
    current = current->next;
  }
}

