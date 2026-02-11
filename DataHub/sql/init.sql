CREATE TABLE roles (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50) NOT NULL UNIQUE,
    description VARCHAR(255) NOT NULL
);

CREATE TABLE permissions (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50) NOT NULL UNIQUE,
    description VARCHAR(255) NOT NULL
);

CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) NOT NULL UNIQUE,
    password_hash VARCHAR(255) NOT NULL,
    email VARCHAR(100) NOT NULL UNIQUE,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE user_roles (
    id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT NOT NULL,
    role_id INT NOT NULL,
    FOREIGN KEY (user_id) REFERENCES users(id) ON DELETE CASCADE,
    FOREIGN KEY (role_id) REFERENCES roles(id) ON DELETE CASCADE,
    UNIQUE(user_id, role_id)
);

CREATE TABLE role_permissions (
    id INT AUTO_INCREMENT PRIMARY KEY,
    role_id INT NOT NULL,
    permission_id INT NOT NULL,
    FOREIGN KEY (role_id) REFERENCES roles(id) ON DELETE CASCADE,
    FOREIGN KEY (permission_id) REFERENCES permissions(id) ON DELETE CASCADE,
    UNIQUE(role_id, permission_id)
);

CREATE TABLE access_logs (
    id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT NOT NULL,
    action VARCHAR(100) NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (user_id) REFERENCES users(id) ON DELETE CASCADE
);

INSERT INTO roles (name, description) VALUES
('Admin', 'Full access to all features'),
('Manager', 'Can manage users and generate reports'),
('Employee', 'Can view own data and perform limited actions'),
('Guest', 'Can view public data only');

INSERT INTO permissions (name, description) VALUES
('CREATE_USER', 'Ability to create new users'),
('READ_USER', 'Ability to read user information'),
('UPDATE_USER', 'Ability to update user information'),
('DELETE_USER', 'Ability to delete users'),
('CREATE_ROLE', 'Ability to create new roles'),
('READ_ROLE', 'Ability to read role information'),
('UPDATE_ROLE', 'Ability to update role information'),
('DELETE_ROLE', 'Ability to delete roles'),
('ASSIGN_ROLE', 'Ability to assign roles to users'),
('CREATE_PERMISSION', 'Ability to create new permissions'),
('READ_PERMISSION', 'Ability to read permission information'),
('UPDATE_PERMISSION', 'Ability to update permissions'),
('DELETE_PERMISSION', 'Ability to delete permissions'),
('VIEW_REPORTS', 'Ability to view system reports'),
('LOG_ACTIONS', 'Ability to log and track user actions');

INSERT INTO users (username, password_hash, email) VALUES
('admin', '$2y$12$abcdefghijklmnopqrstuvwxyz0123456789ABCD', 'admin@example.com');

INSERT INTO user_roles (user_id, role_id) VALUES
(1, 1);

INSERT INTO role_permissions (role_id, permission_id)
SELECT 1, id FROM permissions;
