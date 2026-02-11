#include <stdio.h>
#include <string.h>
#include "../src/services/user_service.h"
#include "../src/models/user.h"

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
    printf("=== User Service Tests ===\n");

    test_create_user();
    test_get_user();
    test_update_user();
    test_get_user(); // Verify after update
    test_delete_user();

    return 0;
}
