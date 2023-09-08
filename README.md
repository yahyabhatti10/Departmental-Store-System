# Departmental-Store-System
The Departmental Store System is an advanced software solution developed in C++ and leverages the power of data structures, specifically linked lists, while incorporating core principles of System Design and Data Structure and Algorithms. This project offers a robust and efficient platform for managing departmental store operations.

# Input and User Guide

This guide will walk you through the input formats for various functions and provide you with a user manual to effectively utilize this system.

## Input Formatting

### Original Location Format

- **Format:** s12345 (e.g., s56789)
- **Description:** The original location format should consist of the letter 's' followed by a 5-digit number. The numbers can vary, but the length should always be 6 characters.

### RFID Tag Number Format

- **Format:** 123ABCDEF (e.g., 1A2B3C4D5)
- **Description:** The RFID tag number format should consist of exactly 9 characters. It can contain alphanumeric hexadecimal characters (0-9, A-F).

## User Guide

The Departmental Store System offers a set of functions to manage your store efficiently. Here's a step-by-step guide on how to use each function:

### 1. Insert an item into the list (I)

- **Command:** `I`
- **Description:** This function allows you to add a new item to the store's inventory.
- **Input:** 
  - Product Name
  - Price (in positive double)
  - RFID Tag Number (in hexadecimal format)
  - Original Location (in the specified format)

### 2. Move an item in the store (M)

- **Command:** `M`
- **Description:** Use this function to change the location of an item within the store.
- **Input:** 
  - RFID Tag Number (in hexadecimal format)
  - Source Location (in valid format)
  - Destination Location (in valid format)

### 3. List items by location (L)

- **Command:** `L`
- **Description:** This function lists items based on their current or original location.
- **Input:** 
  - Location (in valid format)

### 4. Print all items in the store (P)

- **Command:** `P`
- **Description:** Prints a list of all items currently in the store.

### 5. Checkout (O)

- **Command:** `O`
- **Description:** Use this function to process a customer's purchase. It calculates the total cost of items in the specified cart and updates their location to "out."
- **Input:** 
  - Cart Number (in valid format)

### 6. Clean store (C)

- **Command:** `C`
- **Description:** Cleans the store by moving items with incorrect or non-standard locations back to their original locations.

### 7. Update record system (U)

- **Command:** `U`
- **Description:** Removes all items that have been purchased and checked out of the store's inventory.

### 8. Print by RFID tag number (R)

- **Command:** `R`
- **Description:** Lists items based on their RFID tag number.
- **Input:** 
  - RFID Tag Number (in hexadecimal format)

### 9. Quit (Q)

- **Command:** `Q`
- **Description:** Exits the program and closes the Departmental Store System.

Now that you have an understanding of the input formats and how to use each function, you can efficiently manage your departmental store with this system. Enjoy enhanced inventory control, streamlined customer transactions, and improved store management.
