#ifndef SESSION_H
#define SESSION_H

void session_start(const char *username, const char *role);
void session_end(void);

int session_is_active(void);
const char *session_user(void);
const char *session_role(void);

#endif
