// SPDX-License-Identifier: BSD-3-Clause

#include <internal/essentials.h>
#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

void *malloc(size_t size) {
    /* TODO: Implement malloc(). */

    void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE,
                     MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (mem_list_add(ptr, size) != 0) {
        return NULL;
    }

    return ptr;
}

void *calloc(size_t nmemb, size_t size) {
    /* TODO: Implement calloc(). */
    size_t total_size = nmemb * size;
    void *ptr = malloc(total_size);

    if (ptr != NULL) {
        // reset the memory
        memset(ptr, 0, total_size);
    }

    return ptr;
}

void free(void *ptr) {
    /* TODO: Implement free(). */
    struct mem_list *block = mem_list_find(ptr);
    munmap(block->start, block->len);
    mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size) {
    free(ptr);
    void *new_ptr = malloc(size);
    return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size) {
    /* TODO: Implement reallocarray(). */
    size_t total_size = nmemb * size;
    void *new_ptr = realloc(ptr, total_size);
    return new_ptr;
}
