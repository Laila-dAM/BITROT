#ifndef USER_H
#define USER_H

typedef struct {
    int id;
    char username[51];
    char password_hash[256];
    char email[101];
    int roles[10];
    int role_count;
} User;

int create_user_db(const char *username, const char *password_hash, const char *email);
int update_user_db(int id, const char *username, const char *password_hash, const char *email);
int delete_user_db(int id);
int get_user_by_id(int id, User *user);
int get_user_by_username(const char *username, User *user);
int list_all_users();

#endif
