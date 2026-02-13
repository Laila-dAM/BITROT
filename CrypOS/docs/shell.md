# Shell

## Overview

MiniOS includes a minimal command-based shell.

The shell runs inside the kernel and interacts with:

- VGA text output
- File system
- Scheduler

It is designed for simplicity and educational clarity.

---

## Execution Model

The shell runs as a task managed by the cooperative scheduler.

It does not use keyboard interrupts or hardware input.

Commands are processed internally.

---

## Supported Commands

help

Displays the list of available commands.

clear

Clears the screen and resets the terminal cursor.

ls

Lists all existing files in the in-memory file system.

cat <file>

Displays the contents of a file.

---

## Command Parsing

Commands are compared as plain strings.

The shell:

1. Receives a command string.
2. Compares it with supported commands.
3. Executes the corresponding function.
4. Prints output to the terminal.

No advanced parsing is implemented.

---

## Limitations

- No real keyboard input
- No command history
- No piping
- No background tasks
- No process isolation
- No environment variables

The shell is cooperative and non-preemptive.

---

## Integration

The shell uses:

- kernel_print for output
- kernel_clear for screen control
- fs_read for file access
- scheduler_yield for task control

It runs continuously under the scheduler loop.

---

## Educational Purpose

The shell demonstrates:

- Command dispatching
- File system interaction
- Terminal output handling
- Modular subsystem integration

It provides a minimal interface layer between the user and kernel subsystems.
