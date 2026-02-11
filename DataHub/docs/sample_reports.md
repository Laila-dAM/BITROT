# DataHub Sample Reports

This document provides examples of SQL-based reports that can be generated in DataHub.  
Reports are executed from the CLI and display data in a clear and structured format.

---

## 1. User List Report

Description: Lists all users with their roles and email addresses.

SQL Query:
```sql
SELECT u.id AS UserID,
       u.username AS Username,
       u.email AS Email,
       GROUP_CONCAT(r.name SEPARATOR ', ') AS Roles
FROM users u
LEFT JOIN user_roles ur ON u.id = ur.user_id
LEFT JOIN roles r ON ur.role_id = r.id
GROUP BY u.id, u.username, u.email
ORDER BY u.username ASC;
Expected Output: Displays user ID, username, email, and assigned roles.

2. Access Logs Report

Description: Shows all user actions in the system with timestamps.

SQL Query:

SELECT al.id AS LogID,
       u.username AS Username,
       al.action AS Action,
       al.created_at AS Timestamp
FROM access_logs al
JOIN users u ON al.user_id = u.id
ORDER BY al.created_at DESC;


Expected Output: Displays log ID, username, action performed, and timestamp of the action.

3. Role-Permission Report

Description: Displays which permissions are assigned to each role.

SQL Query:

SELECT r.name AS Role,
       GROUP_CONCAT(p.name SEPARATOR ', ') AS Permissions
FROM roles r
LEFT JOIN role_permissions rp ON r.id = rp.role_id
LEFT JOIN permissions p ON rp.permission_id = p.id
GROUP BY r.name
ORDER BY r.name ASC;


Expected Output: Shows the role name and a list of all permissions assigned to that role.

4. Summary

Reports provide insights into users, roles, permissions, and activity logs.
SQL queries are stored in sql/reports/ for easy execution.
Reports can be extended or customized based on application requirements.