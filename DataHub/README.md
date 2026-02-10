# DataHub

DataHub is a command-line User and Access Control System designed to simulate a real-world corporate database management application.  
The project focuses on clean architecture, relational databases, authentication, authorization, and structured business logic.

This system was built to demonstrate strong fundamentals in software engineering, database design, and low-level programming using C and SQL.

---

## Features

- Interactive CLI menu
- User authentication system
- Role-based access control
- Permission management
- Full CRUD operations
- SQL-based reports
- Persistent relational database
- Secure password handling
- Modular and scalable architecture

---

## Technologies

- C
- SQL
- SQLite or MySQL
- Makefile
- Git

---

## Project Structure

```bash
DataHub/
├── README.md
├── docs/
├── sql/
├── src/
│ ├── auth/
│ ├── core/
│ ├── database/
│ ├── models/
│ ├── repositories/
│ ├── reports/
│ ├── security/
│ ├── services/
│ ├── utils/
│ └── main.c
├── tests/
├── build/
└── Makefile
```


---

## Architecture Overview

The project follows a layered architecture:

- Core: Application flow and menu handling
- Auth: Login and session control
- Security: Password hashing and permission validation
- Models: Data structures representing database entities
- Repositories: Direct database operations (CRUD)
- Services: Business rules and access validation
- Database: Connection and query execution
- Reports: SQL-based data extraction
- Utils: Input handling, validation, and logging

Each layer has a single responsibility and communicates through well-defined interfaces.

---

## Database Model

Main entities:

- users
- roles
- permissions
- role_permissions
- user_roles
- access_logs

All data is stored in a relational database and initialized using SQL scripts.

---

## How to Build

```bash
make
```

The executable will be generated inside the build directory.

---

## How to Run

```bash
./build/datahub
```


---

## Authentication Flow

1. User enters username and password
2. Credentials are validated against the database
3. Passwords are verified using secure hashing
4. User roles and permissions are loaded
5. Access to features is granted based on permissions

---

## Reports

Reports are generated using raw SQL queries stored in the sql/reports directory.  
They provide insights such as:

- User listings
- Access logs
- Role and permission mappings

---

## Testing

Basic test files are located in the tests directory and validate authentication, user management, and permission logic.

---

## Goals of the Project

- Simulate a real corporate access control system
- Apply clean architecture principles
- Demonstrate SQL proficiency
- Showcase secure authentication concepts
- Serve as a strong portfolio project for internships and junior positions

---

## Future Improvements

- Export reports to files
- Add pagination to CLI views
- Support multiple database engines
- Convert CLI system into REST API
- Implement audit trail visualization

---

## License

This project is intended for educational and portfolio purposes.

--- 

<p align="center"> ૮ ˙Ⱉ˙ ა ʙᴜɴxɪᴇ.ᴢɪᴘ </p>

