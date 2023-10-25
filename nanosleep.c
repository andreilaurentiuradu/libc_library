// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <unistd.h>

int nanosleep(const struct timespec *req, struct timespec *rem) {
    int ans = syscall(35, req, rem);

    if (ans < 0) {
        errno = -ans;
        return -1;
    }

    return ans;
}