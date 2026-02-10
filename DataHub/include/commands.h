#ifndef COMMANDS_H
#define COMMANDS_H

void cmd_help(void);
void cmd_init(void);
void cmd_status(void);
void cmd_add_user(const char *username, const char *password, const char *role);
void cmd_list_users(void);

#endif
