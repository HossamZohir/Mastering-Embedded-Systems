# FIFO Implementation

## Description
This project implements a First In, First Out (FIFO) data structure in C. It allows for efficient addition and retrieval of items based on the FIFO principle, where the earliest added item is the first to be retrieved.

## Files
- `fifo.h` - Header file containing type definitions, function prototypes, and constants.
- `fifo.c` - Source file with the implementation of FIFO operations.

## Functions
1. **`FIFO_Init`**
   - Initializes the FIFO buffer.
   - **Parameters**:
     - Pointer to `FIFO_Buf_t` structure.
     - Pointer to an array (buffer).
     - Length of the buffer.
   - **Returns**:
     - `FIFO_No_Error` on success.
     - `FIFO_Null` if the buffer is invalid.

2. **`FIFO_Add_item`**
   - Adds an item to the FIFO.
   - **Parameters**:
     - Pointer to `FIFO_Buf_t` structure.
     - Pointer to the item to be added.
   - **Returns**:
     - `FIFO_No_Error` on success.
     - `FIFO_Full` if the FIFO is full.
     - `FIFO_Null` if the FIFO is invalid.

3. **`FIFO_Get_item`**
   - Retrieves the first item added to the FIFO.
   - **Parameters**:
     - Pointer to `FIFO_Buf_t` structure.
     - Pointer to store the retrieved item.
   - **Returns**:
     - `FIFO_No_Error` on success.
     - `FIFO_Empty` if the FIFO is empty.
     - `FIFO_Null` if the FIFO is invalid.

4. **`FIFO_is_full`**
   - Checks if the FIFO is full.
   - **Returns**:
     - `FIFO_Full` if full.
     - `FIFO_No_Error` otherwise.

5. **`FIFO_Print`**
   - Prints all elements in the FIFO for debugging.

## Usage
1. Define a buffer array and a `FIFO_Buf_t` structure.
2. Initialize the FIFO using `FIFO_Init`.
3. Add items using `FIFO_Add_item`.
4. Retrieve items using `FIFO_Get_item`.

## Example
```c
#include "fifo.h"
#include <stdio.h>

int main()
{
    uint32_t buffer[5];
    FIFO_Buf_t myFIFO;

    // Initialize the FIFO
    if (FIFO_Init(&myFIFO, buffer, 5) == FIFO_No_Error)
        printf("FIFO Initialization: SUCCESS\n");
    else
        printf("FIFO Initialization: FAILED\n");

    // Add items to the FIFO
    for (uint32_t i = 0; i < 5; i++) {
        if (FIFO_Add_item(&myFIFO, &i) == FIFO_No_Error)
            printf("Added: %d\n", i);
        else
            printf("FIFO is Full\n");
    }

    // Print the FIFO
    FIFO_Print(&myFIFO);

    // Retrieve items from the FIFO
    uint32_t item;
    for (uint32_t i = 0; i < 5; i++) {
        if (FIFO_Get_item(&myFIFO, &item) == FIFO_No_Error)
            printf("Retrieved: %d\n", item);
        else
            printf("FIFO is Empty\n");
    }

    return 0;
}
