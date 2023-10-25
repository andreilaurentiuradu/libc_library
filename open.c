// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>

int open(const char *filename, int flags, ...) {
    /* TODO: Implement open system call. */
    int ans = syscall(2, filename, flags, 0);

    if (ans == -EACCES || ans == -ENOENT || ans == -ENOTDIR || ans == -EISDIR ||
        ans == -EEXIST) {
        errno = -ans;
        return -1;
    }

    return ans;
}
