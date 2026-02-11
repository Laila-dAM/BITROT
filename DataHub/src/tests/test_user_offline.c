#include <stdio.h>
#include <string.h>

#define MAX_USERS 100

typedef struct {
    int id;
    char username[51];
    char password[65];
    char email[101];
} User;

User users_db[MAX_USERS];
int user_count = 0;

int service_create_user(const char *username, const char *password, const char *email) {
    if (user_count >= MAX_USERS) return 1;
    users_db[user_count].id = user_count + 1;
    strncpy(users_db[user_count].username, username, 50);
    strncpy(users_db[user_count].password, password, 64);
    strncpy(users_db[user_count].email, email, 100);
    user_count++;
    return 0;
}

int service_get_user(int id, User *user) {
    for (int i = 0; i < user_count; i++) {
        if (users_db[i].id == id) {
            *user = users_db[i];
            return 0;
        }
    }
    return 1; 
}

int service_update_user(int id, const char *username, const char *password, const char *email) {
    for (int i = 0; i < user_count; i++) {
        if (users_db[i].id == id) {
            strncpy(users_db[i].username, username, 50);
            strncpy(users_db[i].password, password, 64);
            strncpy(users_db[i].email, email, 100);
            return 0;
        }
    }
    return 1; 
}

int service_delete_user(int id) {
    int found = -1;
    for (int i = 0; i < user_count; i++) {
        if (users_db[i].id == id) {
            found = i;
            break;
        }
    }
    if (found == -1) return 1; 
    for (int i = found; i < user_count - 1; i++) {
        users_db[i] = users_db[i + 1];
    }
    user_count--;
    return 0;
}

void test_create_user() {
    int result = service_create_user("testuser", "Test1234", "test@example.com");
    printf("Test create user: %s\n", result == 0 ? "PASS" : "FAIL");
}

void test_get_user() {
    User user;
    int result = service_get_user(1, &user);
    if (result == 0) {
        printf("Test get user: PASS | ID: %d, Username: %s, Email: %s\n",
               user.id, user.username, user.email);
    } else {
        printf("Test get user: FAIL\n");
    }
}

void test_update_user() {
    int result = service_update_user(1, "updateduser", "NewPass123", "updated@example.com");
    printf("Test update user: %s\n", result == 0 ? "PASS" : "FAIL");
}

void test_delete_user() {
    int result = service_delete_user(1);
    printf("Test delete user: %s\n", result == 0 ? "PASS" : "FAIL");
}

int main() {
    printf("=== User Service Offline Tests ===\n");

    test_create_user();
    test_get_user();
    test_update_user();
    test_get_user(); 
    test_delete_user();
    test_get_user(); 

    return 0;
}
