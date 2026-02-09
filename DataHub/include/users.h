#ifndef USERS_H
#define USERS_H

int user_create(const char *username, const char *password, const char *role);
int user_login(const char *username, const char *password);
int user_count(void);

#endif
