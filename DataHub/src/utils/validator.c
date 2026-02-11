#include <string.h>
#include <ctype.h>
#include "../utils/validator.h"

int validate_email(const char *email) {
    if (!email) return 0;

    const char *at = strchr(email, '@');
    if (!at) return 0;

    const char *dot = strchr(at, '.');
    if (!dot) return 0;

    return 1;
}

int validate_username(const char *username) {
    if (!username) return 0;

    int len = strlen(username);
    if (len < 3 || len > 32) return 0;

    for (int i = 0; i < len; i++) {
        if (!isalnum(username[i])) return 0;
    }

    return 1;
}

int validate_password(const char *password) {
    if (!password) return 0;

    int len = strlen(password);
    if (len < 6 || len > 64) return 0;

    int has_digit = 0, has_upper = 0, has_lower = 0;

    for (int i = 0; i < len; i++) {
        if (isdigit(password[i])) has_digit = 1;
        else if (isupper(password[i])) has_upper = 1;
        else if (islower(password[i])) has_lower = 1;
    }

    return has_digit && has_upper && has_lower;
}
