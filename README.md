# C-Practice


## TestFile.c

This file was the start, me just playing around making sure I am able to run c from my terminal


## Project 1
**Dynamic Inventory Tracker**

A command-line inventory management system in C designed to practice dynamic memory allocation, pointer manipulation, and custom structures without fixed-size array limitations.

**Features**

- Dynamic Memory Resizing: Allocates heap memory at runtime and uses realloc to double capacity automatically as inventory grows.

- Interactive Control Loop: Provides a command-line interface to add items, view real-time inventory valuations, and locate the highest-priced assets

- Memory Safety: Implements strict clean up routines to prevent memory leaks and avoids dangling pointers by resetting pointers to NULL.


**Core Functions**

```
struct Item* addItem(...)
```
Manages dynamic reallocation and captures item details (Id, price, quantity)

```
float calculateTotalValue(...)
```
Computes combined financial worth (price * quantity) across all stored items

```
int findMostExpensive(...)
```
Scans the array and returns the index of the most expensive item

```
void freeInventory(...)
```
Safely releases all allocated heap blocks before program termination

## Project 2
**Mini-Notepad Text Buffer**

A command-line text editor built in C to master pointers-to-pointers (char **), dynamic array resizing, and nested heap memory manaagement

**Features**
- Double Pointer Architecture: Manages an array of string pointers (char **) stored on the heap, allowing variable-length rows to grow dynamically

- Nested Memory Allocation: Allocates individual heap memory blocks for each line string using malloc and strlen, ensuring zero wasted buffer space

- Input Safety Control: Combines fgets with newline stripping to prevent buffer overflows, paired with clean input stream management between scanf and string entry

- Strict Leak Prevention: Implements a two-tier cleanup routine that releases individual line allocations before freeing the master pointer array

**Core Functions**

```
char ** addLine(...)
```
Handles dynamic array doubling via realloc and captures new string lines from standard input

```
void printNotepad(...)
```
Iterates through row pointers to display formatted line numbers and text content

```
void freeNotepad(...)
```
Safely deallocates every individual string row and the root pointer array to prevent memory leaks


## Project 3
**Minishell**

A custom command-line shell built in C designed to practice operating system process management, system calls, string tokenization, and UNIX process lifecycles.

**Features**

- REPL: Continuously reads user input from standard input, strips control characters, and handles EOF gracefully

- Process Forking & Execution: Spawns independent child processes using fork() and executes external system binaries via execvp() using dynamic argument arrays

- Process Synchronization: Employs waitpid() in the parent process loop to block execution until the spawned child command finishes running

- Built-in Command Management: Intercepts internal state commands like cd and exit directly within the parent process scope

**Core Functions**
```
void parse_input(...)
```
Parses raw input lines using strtok() to split strings by spaces and tabs, populating and null-terminating the argument array required for binary execution

```
int main()
```
Manages the primary interactive REPL loop, reads input streams with fgets(), evaluates build in command overrides, and orchestrates the fork-exec-wait workflow


