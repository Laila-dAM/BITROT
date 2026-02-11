#ifndef ROLE_H
#define ROLE_H

typedef struct {
    int id;
    char name[51];
    char description[256];
    int permissions[20];
    int permission_count;
} Role;


int create_role_db(const char *name, const char *description);
int update_role_db(int id, const char *name, const char *description);
int delete_role_db(int id);
int get_role_by_id(int id, Role *role);
int get_role_by_name(const char *name, Role *role);
int list_all_roles();

#endif
