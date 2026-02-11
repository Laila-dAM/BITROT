#include <string.h>
#include <openssl/sha.h>
#include "hash.h"

void hash_password(const char *password, char *hash) {
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)password, strlen(password), digest);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hash[i * 2], "%02x", (unsigned int)digest[i]);
    }
    hash[SHA256_DIGEST_LENGTH * 2] = '\0';
}

int verify_password(const char *password, const char *hash) {
    char computed_hash[65];
    hash_password(password, computed_hash);
    return strcmp(computed_hash, hash) == 0;
}
