// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <unistd.h>

int truncate(const char *path, off_t length) {
    /* TODO: Implement truncate(). */
    int ans = syscall(76, path, length);

    if (ans == -EINVAL || ans == -EISDIR || ans == -ENOENT) {
        errno = -ans;
        return -1;
    }

    return ans;
}
