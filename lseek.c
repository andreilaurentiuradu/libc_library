// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <unistd.h>

off_t lseek(int fd, off_t offset, int whence) {
    /* TODO: Implement lseek(). */
    off_t ans = syscall(8, fd, offset, whence);

    if (ans == -EBADF || ans == -EINVAL) {
		errno = -ans;
		return -1;
    }

    return ans;
}
