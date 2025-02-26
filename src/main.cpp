#include "../include/mem_alloc.h"
using namespace std;

int main () {

  MemoryAllocator allocator(10000);
  allocator.printMemoryLayout();
  return 0;

}
