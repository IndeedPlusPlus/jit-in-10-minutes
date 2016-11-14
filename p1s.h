#ifndef P1S_H_
#define P1S_H_

#if !defined(__x86_64__) && !defined(_M_AMD64)
#error This program support amd64 architecture only
#endif

#include <stdlib.h>
#include <stdint.h>

/* memory page related macros */
#define PAGE_SIZE 4096
#define ROUND_TO_PAGE(X) ((((X) - 1) / PAGE_SIZE + 1 ) * PAGE_SIZE)

/* memory page related functions */
void * alloc_page(size_t size);
void protect_page(void * ptr, size_t size);
void free_page(void * ptr, size_t size);

/* code block type */
struct code_block
{
    uint8_t * code;
    void * executable_code;
    size_t capacity;
    size_t length;
};

/* code block related functions */
struct code_block * create_code_block();
void destroy_code_block(struct code_block * block);
void * make_block_executable(struct code_block * block);

/* common types */
typedef int64_t (*GeneratedFunction)(int64_t);
typedef int64_t * (*code_generator)(struct code_block *, int64_t *);

/* common functions */
int64_t incr(int64_t x);

#endif // P1S_H_

