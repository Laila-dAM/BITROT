SELECT 
    u.id AS UserID,
    u.username AS Username,
    u.email AS Email,
    GROUP_CONCAT(r.name SEPARATOR ', ') AS Roles
FROM users u
LEFT JOIN user_roles ur ON u.id = ur.user_id
LEFT JOIN roles r ON ur.role_id = r.id
GROUP BY u.id, u.username, u.email
ORDER BY u.username ASC;
