#include <string.h>

char *strcpy(char *destination, const char *source) {
    /* TODO: Implement strcpy(). */
    char *d;

    for (d = destination; *source != '\0'; source++, d++) {
        *d = *source;
    }

    // adding NULL at the end of the string
    *d = *source;
    destination = d;

    return destination;
}

char *strncpy(char *destination, const char *source, size_t len) {
    /* TODO: Implement strncpy(). */

    char *d = destination;

    for (size_t i = 0; i < len; ++i, ++d, ++source) {
        *d = *source;
    }

    return destination;
}

char *strcat(char *destination, const char *source) {
    /* TODO: Implement strcat(). */
    int l1 = strlen(destination);
    int l2 = strlen(source);
    for (int i = 0; i <= l2; ++i) {
        destination[l1 + i] = source[i];
    }
    return destination;
}

char *strncat(char *destination, const char *source, size_t len) {
    /* TODO: Implement strncat(). */
    size_t l1 = strlen(destination);
    for (size_t i = 0; i < len; ++i) {
        destination[l1 + i] = source[i];
    }

    // adding NULL at the end of the string
    destination[l1 + len] = '\0';

    return destination;
}

int strcmp(const char *str1, const char *str2) {
    /* TODO: Implement strcmp(). */
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    int mini = l1, i;

    if (mini > l2) {
        mini = l2;
    }

    for (i = 0; i < mini; ++i) {
        if (str1[i] != str2[i]) {
            return (str1[i] - str2[i]);
        }
    }

    return (str1[i] - str2[i]);
}

int strncmp(const char *str1, const char *str2, size_t len) {
    /* TODO: Implement strncmp(). */

    for (size_t i = 0; i < len; ++i) {
        if (str1[i] != str2[i]) {
            return (str1[i] - str2[i]);
        }
    }

    return 0;
}

size_t strlen(const char *str) {
    size_t i = 0;

    for (; *str != '\0'; str++, i++)
        ;

    return i;
}

char *strchr(const char *str, int c) {
    /* TODO: Implement strchr(). */
    while (*str != '\0') {
        if (*str == c) {
            return (char *)str;
        }
        str++;
    }

    return NULL;
}

char *strrchr(const char *str, int c) {
    /* TODO: Implement strrchr(). */
    char *ans = NULL;
    while (*str != '\0') {
        if (*str == c) {
            ans = (char *)str;
        }
        str++;
    }

    return ans;
}

char *strstr(const char *haystack, const char *needle) {
    /* TODO: Implement strstr(). */
    int len_hs = strlen(haystack);
    int len_ndl = strlen(needle);
    while (len_hs >= len_ndl) {
        if (strncmp(haystack, needle, len_ndl) == 0) return (char *)haystack;
        len_hs--;
        haystack++;
    }
    return NULL;
}

char *strrstr(const char *haystack, const char *needle) {
    /* TODO: Implement strrstr(). */
    char *ans = NULL;
    int len_hs = strlen(haystack);
    int len_ndl = strlen(needle);
    while (len_hs >= len_ndl) {
        if (strncmp(haystack, needle, len_ndl) == 0) ans = (char *)haystack;
        len_hs--;
        haystack++;
    }
    return ans;
}

void *memcpy(void *destination, const void *source, size_t num) {
    /* TODO: Implement memcpy(). */
	char *d = destination;
	const char *s = source;
	while(num) {
		*d = *s;
		s++;
		d++;
		num--;
	}
    return destination;
}

void *memmove(void *destination, const void *source, size_t num) {
    /* TODO: Implement memmove(). */
	char *d = destination;
	const char *s = source;
	while(num) {
		*d = *s;
		s++;
		d++;
		num--;
	}
    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num) {
    /* TODO: Implement memcmp(). */
	const char *p1 = ptr1;
	const char *p2 = ptr2;
	while(num) {
		if(*p1 != *p2)
			return *p1 - *p2;
		p1++;
		p2++;
		num--;
	}
    return 0;
}

void *memset(void *source, int value, size_t num) {
    /* TODO: Implement memset(). */
	unsigned char *s = source;
	while(num) {
		*s = value;
		s++;
		num--;
	}
    return source;
}
