// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <unistd.h>

int ftruncate(int fd, off_t length) {
    /* TODO: Implement ftruncate(). */
    int ans = syscall(77, fd, length);

    if (ans == -EINVAL || ans == -EBADF) {
        errno = -ans;
        return -1;
    }

    return ans;
}
