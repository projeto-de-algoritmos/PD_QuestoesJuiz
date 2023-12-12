#include <stdbool.h>

bool isMatch(char *s, char *p) {
    if (*p == '\0') {
        return *s == '\0';
    }

    if (*(p + 1) == '*') {
        if (isMatch(s, p + 2)) {
            return true;
        }

        while (*s != '\0' && (*s == *p || *p == '.')) {
            if (isMatch(++s, p + 2)) {
                return true;
            }
        }
    } else {
        if (*s != '\0' && (*s == *p || *p == '.')) {
            return isMatch(s + 1, p + 1);
        }
    }

    return false;
}