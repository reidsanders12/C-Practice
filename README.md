# C-Practice


## TestFile.c

This file was the start, me just playing around making sure I am able to run c from my terminal


## Project1
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
