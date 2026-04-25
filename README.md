# Engineering Lab Equipment Management System (ELEMS) II
An advanced C++ management system developed to optimize the tracking and organization of laboratory inventory through algorithmic efficiency.

# Advanced Features
- Optimized Search: Implemented searching algorithms to locate equipment instantly within the database.
- Automated Sorting: Features built-in sorting logic to organize inventory by Equipment ID or Name for better readability.
- Recursive Navigation: Utilized recursive functions for menu transitions and specific data processing tasks.
- Persistent Storage: Advanced File I/O handling to ensure all equipment records are saved and updated in equipment.txt.

# Algorithms & Data Structures
This project uses basic programming logic to organize and find lab equipment quickly.
- Data Storage:
  - Uses a Struct (a custom container) and an Array to hold all equipment details in one list.
- Sorting (Insertion Sort):
  - Used to arrange the list by Name or Date.
  - It works like sorting a deck of cards—taking one item and putting it in the right spot.
- Searching:
  - Binary Search: A fast way to find an Equipment ID. It splits the list in half repeatedly until the ID is found.
  - Linear Search: Used to find a Category or Condition by checking every item in the list one by one.
- Menu System: Uses a simple while loop so the program stays open until you choose to quit.

# Technical Details
- Language: C++
- Concepts: Inheritance, File Handling (fstream), Recursion, and Algorithm Complexity ($O$ notation).
