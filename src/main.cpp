#include "../include/mem_alloc.h"
using namespace std;

int main () {

  MemoryAllocator allocator(1024);
  
  // TODO: Allocate a few blocks and print the memory layout.
  // TODO: Free some blocks and print the layout again.
  // TODO: Ensure fragmentation is handled properly.
  // TODO: Add error handling for allocation failures.
  // TODO: Implement stress tests with multiple allocations and deallocations.

  allocator.printMemoryLayout();
  return 0;

}

