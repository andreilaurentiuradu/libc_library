// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <sys/mman.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd,
           off_t offset) {
    // mmap syscall for allocating memory
    void *ans = (void *)syscall(9, addr, length, prot, flags, fd, offset);

    if ((long)ans < 0) {
        errno = -(long)ans;
        return MAP_FAILED;
    }

    return ans;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags) {
    /* TODO: Implement mremap(). */
    void *ans = (void *)syscall(25, old_address, old_size, new_size, flags);
    if ((long)ans < 0) {
        errno = -(long)ans;
        return MAP_FAILED;
    }

    return ans;
}

int munmap(void *addr, size_t length) {
    /* TODO: Implement munmap(). */
    void *ans = (void *)syscall(11, addr, length);
    if ((long)ans < 0) {
        errno = -(long)ans;
        return -1;
    }

    return ans;
}
