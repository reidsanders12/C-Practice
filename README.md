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
