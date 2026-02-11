#ifndef APP_H
#define APP_H

#include "../session.h"

void cli_main_menu(Session *session);
void handle_user_choice(Session *session, int choice);
void clear_screen();

#endif
