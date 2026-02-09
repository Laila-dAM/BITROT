# DataHub Database Design

## Overview

The DataHub database is designed to support user authentication, role-based access control, and system reporting.

It follows a normalized relational model to ensure data integrity and scalability.

---

## Tables Overview

### Users
Stores system users.

| Field | Type | Description |
|------|------|-------------|
| id | INT | Primary key |
| username | VARCHAR | Unique username |
| password_hash | VARCHAR | Hashed password |
| role_id | INT | Assigned role |
| created_at | TIMESTAMP | Creation date |

---

### Roles
Defines user roles.

| Field | Type | Description |
|------|------|-------------|
| id | INT | Primary key |
| name | VARCHAR | Role name |

---

### Permissions
Defines system permissions.

| Field | Type | Description |
|------|------|-------------|
| id | INT | Primary key |
| name | VARCHAR | Permission identifier |

---

### Role_Permissions
Maps roles to permissions.

| Field | Type | Description |
|------|------|-------------|
| role_id | INT | Role reference |
| permission_id | INT | Permission reference |

---

### Access_Logs
Tracks system access.

| Field | Type | Description |
|------|------|-------------|
| id | INT | Primary key |
| user_id | INT | User reference |
| action | VARCHAR | Action performed |
| timestamp | TIMESTAMP | Event time |

---

## Relationships

- A user belongs to one role
- A role can have multiple permissions
- Permissions can be assigned to multiple roles
- Access logs are linked to users

---

## Design Considerations

- Foreign keys enforce referential integrity
- Indexes will be added for performance
- Passwords are stored as hashes only

---

## Supported Databases

- SQLite (development)
- MySQL / MariaDB (production-ready)
