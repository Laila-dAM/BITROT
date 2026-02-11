#include <stdio.h>
#include <string.h>
#include "../src/auth.h"
#include "../src/security/hash.h"

void test_login_success() {
    const char *username = "admin";
    const char *password = "Admin123";
    int result = auth_login(username, password);
    printf("Test login success: %s\n", result == 0 ? "PASS" : "FAIL");
    auth_logout();
}

void test_login_failure() {
    const char *username = "admin";
    const char *password = "WrongPass";
    int result = auth_login(username, password);
    printf("Test login failure: %s\n", result != 0 ? "PASS" : "FAIL");
}

void test_logout() {
    const char *username = "admin";
    const char *password = "Admin123";
    auth_login(username, password);
    int result = auth_logout();
    printf("Test logout: %s\n", result == 0 ? "PASS" : "FAIL");
}

int main() {
    test_login_success();
    test_login_failure();
    test_logout();
    return 0;
}
