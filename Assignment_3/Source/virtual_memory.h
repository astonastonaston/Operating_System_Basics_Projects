﻿#ifndef VIRTUAL_MEMORY_H
#define VIRTUAL_MEMORY_H

#include <cuda.h>
#include <cuda_runtime.h>
#include <inttypes.h>

typedef unsigned char uchar;
typedef uint32_t u32;

struct VirtualMemory {
  uchar *buffer; // input/result buffer
  uchar *storage; // global memory storage
  u32 *invert_page_table; // inverted page table location (in shared memory)
  int *pagefault_num_ptr; // recording # page faults

  int PAGESIZE; // size of each page in shared memory
  int INVERT_PAGE_TABLE_SIZE; // size of inv page table in shared memory
  int PHYSICAL_MEM_SIZE; // size of RAM in shared memory 
  int STORAGE_SIZE; // size of global memory storage
  int PAGE_ENTRIES; // # entries in page table in shared memory
};

// TODO
__device__ void vm_init(VirtualMemory *vm, uchar *buffer, uchar *storage,
                        u32 *invert_page_table, int *pagefault_num_ptr,
                        int PAGESIZE, int INVERT_PAGE_TABLE_SIZE,
                        int PHYSICAL_MEM_SIZE, int STORAGE_SIZE,
                        int PAGE_ENTRIES);
__device__ uchar vm_read(VirtualMemory *vm, u32 addr);
__device__ void vm_write(VirtualMemory *vm, u32 addr, uchar value);
__device__ void vm_snapshot(VirtualMemory *vm, uchar *results, int offset,
                            int input_size);

#endif
