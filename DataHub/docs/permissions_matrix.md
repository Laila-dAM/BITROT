# DataHub Permissions Matrix

This matrix defines the mapping between roles and permissions in DataHub.  
Each role has specific permissions to perform actions within the system.

---

## Roles

| Role ID | Role Name          | Description                         |
|---------|------------------|-------------------------------------|
| 1       | Admin             | Full access to all features         |
| 2       | Manager           | Can manage users and generate reports |
| 3       | Employee          | Can view own data and perform limited actions |
| 4       | Guest             | Can view public data only           |

---

## Permissions

| Permission ID | Permission Name        | Description                                      |
|---------------|----------------------|--------------------------------------------------|
| 1             | CREATE_USER           | Ability to create new users                      |
| 2             | READ_USER             | Ability to read user information                |
| 3             | UPDATE_USER           | Ability to update user information              |
| 4             | DELETE_USER           | Ability to delete users                          |
| 5             | CREATE_ROLE           | Ability to create new roles                      |
| 6             | READ_ROLE             | Ability to read role information                |
| 7             | UPDATE_ROLE           | Ability to update role information              |
| 8             | DELETE_ROLE           | Ability to delete roles                          |
| 9             | ASSIGN_ROLE           | Ability to assign roles to users                |
| 10            | CREATE_PERMISSION     | Ability to create new permissions               |
| 11            | READ_PERMISSION       | Ability to read permission information          |
| 12            | UPDATE_PERMISSION     | Ability to update permissions                   |
| 13            | DELETE_PERMISSION     | Ability to delete permissions                   |
| 14            | VIEW_REPORTS          | Ability to view system reports                  |
| 15            | LOG_ACTIONS           | Ability to log and track user actions           |

---

## Role-Permission Mapping

| Role Name  | Permissions                                                                 |
|------------|----------------------------------------------------------------------------|
| Admin      | All permissions (1-15)                                                      |
| Manager    | READ_USER, UPDATE_USER, VIEW_REPORTS, ASSIGN_ROLE, CREATE_ROLE, READ_ROLE   |
| Employee   | READ_USER, VIEW_REPORTS                                                     |
| Guest      | VIEW_REPORTS                                                                |

---

## Summary

- Admin has full control of the system.  
- Manager can manage users, roles, and reports.  
- Employee has limited access to their own data and reports.  
- Guest has read-only access to public reports.  

This matrix ensures role-based access control is enforced consistently across the application.
