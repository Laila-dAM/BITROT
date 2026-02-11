#ifndef LOGIN_H
#define LOGIN_H

int login_attempt(const char *username, const char *password);
int logout_user();
int is_user_logged_in();

#endif
