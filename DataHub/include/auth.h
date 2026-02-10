#ifndef AUTH_H
#define AUTH_H

int auth_login(const char *username, const char *password);
int auth_is_authenticated();
const char* auth_current_user();

#endif
