#include <stdio.h>
#include "../src/services/permission_service.h"
#include "../src/models/permission.h"

void test_create_permission() {
    int result = service_create_permission("TEST_PERMISSION", "Test permission description");
    printf("Test create permission: %s\n", result == 0 ? "PASS" : "FAIL");
}

void test_get_permission() {
    Permission permission;
    int result = service_get_permission(1, &permission);
    if (result == 0) {
        printf("Test get permission: PASS | ID: %d, Name: %s, Description: %s\n",
               permission.id, permission.name, permission.description);
    } else {
        printf("Test get permission: FAIL\n");
    }
}

void test_update_permission() {
    int result = service_update_permission(1, "UPDATED_PERMISSION", "Updated description");
    printf("Test update permission: %s\n", result == 0 ? "PASS" : "FAIL");
}

void test_delete_permission() {
    int result = service_delete_permission(1);
    printf("Test delete permission: %s\n", result == 0 ? "PASS" : "FAIL");
}

int main() {
    printf("=== Permission Service Tests ===\n");

    test_create_permission();
    test_get_permission();
    test_update_permission();
    test_get_permission(); // Verify after update
    test_delete_permission();

    return 0;
}
