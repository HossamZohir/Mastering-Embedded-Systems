# LIFO Implementation

## Description
This project implements a Last In, First Out (LIFO) data structure in C. It allows for efficient addition and retrieval of items based on the LIFO principle, where the most recently added item is the first to be retrieved.

## Files
- `lifo.h` - Header file containing type definitions, function prototypes, and constants.
- `lifo.c` - Source file with the implementation of LIFO operations.

## Functions
1. **`LIFO_Init`**
   - Initializes the LIFO buffer.
   - **Parameters**:
     - Pointer to `LIFO_Buf_t` structure.
     - Pointer to an array (buffer).
     - Length of the buffer.
   - **Returns**:
     - `LIFO_No_Error` on success.
     - `LIFO_Null` if the buffer is invalid.

2. **`LIFO_Add_item`**
   - Adds an item to the LIFO.
   - **Parameters**:
     - Pointer to `LIFO_Buf_t` structure.
     - Pointer to the item to be added.
   - **Returns**:
     - `LIFO_No_Error` on success.
     - `LIFO_Full` if the LIFO is full.
     - `LIFO_Null` if the LIFO is invalid.

3. **`LIFO_Get_item`**
   - Retrieves the last item added to the LIFO.
   - **Parameters**:
     - Pointer to `LIFO_Buf_t` structure.
     - Pointer to store the retrieved item.
   - **Returns**:
     - `LIFO_No_Error` on success.
     - `LIFO_Empty` if the LIFO is empty.
     - `LIFO_Null` if the LIFO is invalid.

4. **`LIFO_is_full`**
   - Checks if the LIFO is full.
   - **Returns**:
     - `LIFO_Full` if full.
     - `LIFO_No_Error` otherwise.

5. **`LIFO_Print`**
   - Prints all elements in the LIFO for debugging.

## Usage
1. Define a buffer array and a `LIFO_Buf_t` structure.
2. Initialize the LIFO using `LIFO_Init`.
3. Add items using `LIFO_Add_item`.
4. Retrieve items using `LIFO_Get_item`.

## Example
```c
uint32_t buffer[5];
LIFO_Buf_t myLIFO;

LIFO_Init(&myLIFO, buffer, 5);

uint32_t value = 10;
LIFO_Add_item(&myLIFO, &value);

uint32_t retrieved;
LIFO_Get_item(&myLIFO, &retrieved);
printf("Retrieved: %d\n", retrieved);