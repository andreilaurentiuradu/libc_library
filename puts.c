#include <unistd.h>
#include <string.h>

int puts(const char* str) {
    // sending the string to stdout
    write(1, str, strlen(str));

    // sending newline to stdout
    write(1, "\n", 1);
    return 1;
}
