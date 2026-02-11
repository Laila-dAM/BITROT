# DataHub Architecture

## Overview

DataHub is a command-line User and Access Control System with a layered architecture.  
The system is designed to separate concerns, provide scalability, and simulate a real corporate environment.

The architecture is modular and divided into several layers: Core, Auth, Security, Models, Repositories, Services, Database, Reports, and Utils.

---

## Layers

### Core
Handles application flow and interactive menus.  
Coordinates user actions and routes requests to appropriate services.

### Auth
Manages user authentication and session control.  
Validates credentials and handles login and logout processes.

### Security
Handles password hashing and role-based access control.  
Ensures users can only access authorized features.

### Models
Defines data structures that represent database entities:  
- User  
- Role  
- Permission  
- Role-Permission mapping  
- User-Role mapping  
- Access logs  

### Repositories
Directly interacts with the database to perform CRUD operations.  
Each repository corresponds to a model and contains methods for create, read, update, and delete.

### Services
Implements business logic and validation rules.  
Coordinates data from repositories and enforces application rules and permissions.

### Database
Manages database connections and executes SQL queries.  
Supports SQLite or MySQL as relational databases.  
Contains initialization scripts, migrations, and seeds.

### Reports
Executes predefined SQL queries and formats the results for display in CLI.  
Generates user lists, access logs, and role-permission mappings.

### Utils
Contains helper functions for input handling, validation, and logging.  
Provides reusable utilities across all layers.

---

## Data Flow

1. User interacts with CLI menu in Core layer.
2. Auth layer validates login credentials.
3. Security layer verifies user roles and permissions.
4. Services layer applies business rules.
5. Repositories layer executes CRUD operations in the Database layer.
6. Reports layer fetches data and formats results for display.

---

## Database Entities

- **users**: stores user information and credentials.  
- **roles**: stores role definitions.  
- **permissions**: stores permission definitions.  
- **role_permissions**: maps roles to permissions.  
- **user_roles**: maps users to roles.  
- **access_logs**: tracks user logins and actions.

---

## Architecture Diagram

```bash
CLI <-> Core <-> Services <-> Repositories <-> Database
|
v
Security
|
v
Reports
```


---

## Principles

- Layered architecture with separation of concerns.  
- Modular and scalable design for easy maintenance.  
- Clear division between business logic, data access, and presentation.  
- Secure authentication and role-based access control.  
- CLI-focused but designed for future API expansion.
