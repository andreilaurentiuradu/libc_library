#include <internal/syscall.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

unsigned int sleep(unsigned int seconds) {
    struct timespec req, rem;
    req.tv_sec = seconds;
    req.tv_nsec = 0;

    int ans = nanosleep(&req, &rem);
    return ans;
}
