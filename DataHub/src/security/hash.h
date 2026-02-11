#ifndef HASH_H
#define HASH_H

void hash_password(const char *password, char *hash);
int verify_password(const char *password, const char *hash);

#endif
