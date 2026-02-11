#ifndef PERMISSION_H
#define PERMISSION_H

typedef struct {
    int id;
    char name[51];
    char description[256];
} Permission;

int create_permission_db(const char *name, const char *description);
int update_permission_db(int id, const char *name, const char *description);
int delete_permission_db(int id);
int get_permission_by_id(int id, Permission *permission);
int get_permission_by_name(const char *name, Permission *permission);
int list_all_permissions();

#endif
