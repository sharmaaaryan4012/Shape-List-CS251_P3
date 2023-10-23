# Shape List Project

## Project Summary
In this project, I implemented a simplified drawing canvas in C++, designed to mimic the storage of items to be drawn to the screen. The core of the project consists of a `CanvasList` class which maintains a linked list of shapes, and a `Shape` class with three derived classes: `Circle`, `RightTriangle`, and `Rectangle`. The project is an exercise in object-oriented programming and test-driven development, using either the Catch or Google Test framework for crafting and running test cases. Additionally, it provided an opportunity to work with dynamic memory management in C++.

## Topics Covered
- Classes
- Linked Lists
- Dynamic Memory
- Test Frameworks

## Class Descriptions

### shape.h
This file contains the definitions of the `Shape`, `Rectangle`, `RightTriangle`, and `Circle` classes. Each class has constructors, a destructor, a copy function for dynamic memory allocation, a print function, and accessors and setters for private data members.

### canvaslist.h
This file defines the `ShapeNode` and `CanvasList` classes. The `ShapeNode` class is used as the element of the linked list, while the `CanvasList` class manages the list of shapes, providing functions for manipulating the list and drawing the shapes.

## Using the Project
To use this project, you should include the header files in your source code and link against the compiled object files. You can create objects of the `CanvasList` and shape classes, and use the provided functions to manipulate and draw the shapes. Make sure to follow good memory management practices, as some functions allocate and deallocate memory dynamically.

## Final Thoughts
This project was a valuable exercise in object-oriented programming and test-driven development. It allowed me to deepen my understanding of C++'s memory management and linked list data structures, while also providing hands-on experience with writing and running tests.
