SELECT 
    al.id AS LogID,
    u.username AS Username,
    al.action AS Action,
    al.created_at AS Timestamp
FROM access_logs al
JOIN users u ON al.user_id = u.id
ORDER BY al.created_at DESC;
