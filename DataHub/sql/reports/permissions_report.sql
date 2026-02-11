SELECT 
    r.name AS Role,
    GROUP_CONCAT(p.name SEPARATOR ', ') AS Permissions
FROM roles r
LEFT JOIN role_permissions rp ON r.id = rp.role_id
LEFT JOIN permissions p ON rp.permission_id = p.id
GROUP BY r.name
ORDER BY r.name ASC;
