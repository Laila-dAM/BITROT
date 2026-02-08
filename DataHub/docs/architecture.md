# DataHub System Architecture

## Overview

DataHub is a terminal-based application designed to simulate a corporate user and access control system.  
The system follows a modular architecture to ensure maintainability, scalability, and clarity.

The application interacts with a relational database to persist data and enforce access rules.

---

## High-Level Architecture

The system is divided into the following main layers:

- **CLI Layer**
  - Handles user interaction
  - Displays menus and messages
  - Collects and validates input

- **Application Logic Layer**
  - Implements business rules
  - Controls authentication and authorization
  - Manages system workflows

- **Database Layer**
  - Executes SQL queries
  - Manages connections
  - Handles persistence and transactions

---

## Core Modules

### Authentication Module
- User login and logout
- Password hashing and verification
- Session control

### Authorization Module
- Role-based access control
- Permission validation
- Restricted operations

### User Management Module
- Create, read, update, and delete users
- Assign roles to users

### Menu Module
- Interactive terminal menus
- Navigation logic
- Error handling

### Reporting Module
- SQL-based reports
- Aggregated system data

---

## Data Flow

1. User interacts with the CLI menu
2. Input is validated by the application layer
3. Business rules are applied
4. SQL queries are executed
5. Results are returned to the CLI

---

## Security Considerations

- Passwords are never stored in plain text
- Authentication data is protected
- Access to system features is role-based

---

## Future Improvements

- Logging system
- Configuration files
- Unit testing support
