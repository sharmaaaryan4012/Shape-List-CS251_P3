/*
Name: Aaryan Sharma
CS 251 (Fall 2023) - Prof Drishika Dey
Project - 3 (Shape List)
*/

// The tutorial for Catch 1.x can be found at:
// https://github.com/catchorg/Catch2/blob/Catch1.x/docs/tutorial.md

// This tells Catch to provide a main() - do not remove
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "canvaslist.h"
#include <sstream>
#include <vector>

using namespace std;

TEST_CASE("(0) no tests") {}


TEST_CASE ("Test - 1: Shape Default Constructor") {
    Shape toCheck = Shape();                                                                                            // Calling the default constructor of "Shape" class.

    REQUIRE(toCheck.getX() == 0);                                                                                       // Checks whether the default constructor correctly sets the values for X and Y.
    REQUIRE(toCheck.getY() == 0);

}


TEST_CASE ("Test - 2: Shape Constructor") {
    Shape toCheck = Shape(1, 3);                                                                                  // Calling the "Shape" constructor.

    REQUIRE(toCheck.getX() == 1);                                                                                       // Checks whether the values for X and Y are set correctly.
    REQUIRE(toCheck.getY() == 3);

}


TEST_CASE ("Test - 3: Shape Copy Constructor") {
    Shape OrigShape = Shape(1,2);
    Shape toCheck = *(OrigShape.copy());                                                                                // Copying over the "OrigShape" to "toCheck" object, using the copy constructor.

    REQUIRE(OrigShape.getX() == toCheck.getX());
    REQUIRE(OrigShape.getY() == toCheck.getY());

}


TEST_CASE ("Test - 4: Shape Getters") {
    Shape toCheck = Shape(1, 3);

    REQUIRE(toCheck.getX() == 1);                                                                                       // Checks whether the values for X and Y in the "toCheck" object are set correctly.
    REQUIRE(toCheck.getY() == 3);

}


TEST_CASE ("Test - 5: Shape Setters") {
    Shape toCheck = Shape();
    toCheck.setX(1);                                                                                                    // Calling the setter functions of the "Shape" class.
    toCheck.setY(3);

    REQUIRE(toCheck.getX() == 1);                                                                                       // Checks whether the values for X and Y in the "toCheck" object are set correctly.
    REQUIRE(toCheck.getY() == 3);

}


TEST_CASE ("Test - 6: Shape Print Shape") {
    Shape toCheckShape = Shape(1, 3);
    stringstream Sol;
    Sol << "It's a Shape at x: " << toCheckShape.getX() << ", y: " << toCheckShape.getY();

    REQUIRE(Sol.str() == toCheckShape.printShape());                                                                    // Checks the two strings against each other, comparing the solution with the "toCheckShape".

}


TEST_CASE ("Test - 7: CanvasList Default Constructor") {
    CanvasList toCheck = CanvasList();                                                                                  // Calling the default constructor of the "CanvasList" class.

    REQUIRE(toCheck.front() == NULL);                                                                                   // Checks whether the values for "listFront" and "listSize" are set correctly.
    REQUIRE(toCheck.size() == 0);

}


TEST_CASE ("Test - 8: CanvasList Copy Constructor") {
    CanvasList OrigList = CanvasList();
    Shape* First = new Shape(1, 3);
    OrigList.push_back(First);
    Shape* Second = new Shape(2, 4);
    OrigList.push_back(Second);

    CanvasList toCheck = CanvasList(OrigList);                                                                          // Copying over the "OrigList" to "toCheck", using the copy constructor of "CanvasList" class.

    REQUIRE((toCheck.front()->value->getX()) == (OrigList.front()->value->getX()));                                     // Checks whether the values of X and Y in the "toCheck" are set correctly.
    REQUIRE((toCheck.front()->value->getY()) == (OrigList.front()->value->getY()));

    REQUIRE((toCheck.front()->next->value->getX()) == (OrigList.front()->next->value->getX()));
    REQUIRE((toCheck.front()->next->value->getY()) == (OrigList.front()->next->value->getY()));

}


TEST_CASE ("Test - 9: CanvasList = Operator") {
    CanvasList OrigList = CanvasList();
    Shape* First = new Shape(1, 3);
    OrigList.push_back(First);
    Shape* Second = new Shape(2, 4);
    OrigList.push_back(Second);

    CanvasList toCheck = OrigList;                                                                                      // Copying over the "OrigList" to "toCheck", using the overloaded "=" operator defined in the "CanvasList" class.

    REQUIRE((toCheck.front()->value) != (OrigList.front()->value));                                                     // Checks whether the memory address of the values stored inside the 2 "CanvasList" differ, since "toCHeck" is now a deep copy of "OrigList".
    REQUIRE((toCheck.front()->value->getX()) == (OrigList.front()->value->getX()));
    REQUIRE((toCheck.front()->value->getY()) == (OrigList.front()->value->getY()));                                     // Checks whether the values of X and Y in the "toCheck" are set correctly.

    REQUIRE((toCheck.front()->next->value) != (OrigList.front()->next->value));
    REQUIRE((toCheck.front()->next->value->getX()) == (OrigList.front()->next->value->getX()));
    REQUIRE((toCheck.front()->next->value->getY()) == (OrigList.front()->next->value->getY()));

}


TEST_CASE ("Test - 10: CanvasList Clear") {
    CanvasList toCheck = CanvasList();
    Shape* First = new Shape(1, 3);
    toCheck.push_back(First);                                                                                           // Inserting elements inside the "toCheck" list.
    Shape* Second = new Shape(2, 4);
    toCheck.push_back(Second);

    REQUIRE(!toCheck.isempty());                                                                                        // Checking the empty status of the "toCheck" list, which should return "False".
    toCheck.clear();                                                                                                    // Calling the "clear" function.
    REQUIRE(toCheck.isempty());                                                                                         // Checking the empty status of the "toCheck" list, which should now return "True".

}


TEST_CASE ("Test - 11: CanvasList Destructor") {
    CanvasList* toCheck = new CanvasList();
    Shape* First = new Shape(1, 3);
    toCheck->push_back(First);                                                                                          // Inserting elements inside the "toCheck" list.
    Shape* Second = new Shape(2, 4);
    toCheck->push_back(Second);

    REQUIRE(!toCheck->isempty());                                                                                       // Checking the empty status of the "toCheck" list, which should return "False".
    delete toCheck;                                                                                                     // Calling the class destructor.
    REQUIRE(toCheck->isempty());                                                                                        // Checking the empty status of the "toCheck" list, which should now return "True".

}


TEST_CASE ("Test - 12: CanvasList InsertAfter(Back)") {
    CanvasList toCheck = CanvasList();
    Shape* First = new Shape(1, 3);
    toCheck.push_back(First);                                                                                           // Inserting elements inside the "toCheck" list.
    Shape* Second = new Shape(2, 4);
    toCheck.push_back(Second);

    Shape* Third = new Shape(3, 5);
    toCheck.insertAfter(1, Third);                                                                                      // Calling the "insertAfter" function, which adds a node at the very back of the "CanvasList".

    vector<int> valX = {1, 2, 3};
    vector<int> valY = {3, 4, 5};

    ShapeNode* temp = toCheck.front();

    for (int i=0; i<3; i++) {
        REQUIRE(temp->value->getX() == valX[i]);                                                                        // Checks whether the values of X and Y in the "toCheck" are set correctly.
        REQUIRE(temp->value->getY() == valY[i]);
        temp = temp->next;
    }
}


TEST_CASE ("Test - 13: CanvasList InsertAfter(Middle)") {
    CanvasList toCheck = CanvasList();
    Shape* First = new Shape(1, 3);
    toCheck.push_back(First);                                                                                           // Inserting elements inside the "toCheck" list.
    Shape* Second = new Shape(2, 4);
    toCheck.push_back(Second);

    Shape* Third = new Shape(3, 5);
    toCheck.insertAfter(0, Third);                                                                                      // Calling the "insertAfter" function, which adds a node in the middle of the "CanvasList".

    vector<int> valX = {1, 3, 2};
    vector<int> valY = {3, 5, 4};

    ShapeNode* temp = toCheck.front();

    for (int i=0; i<3; i++) {
        REQUIRE(temp->value->getX() == valX[i]);                                                                        // Checks whether the values of X and Y in the "toCheck" are set correctly.
        REQUIRE(temp->value->getY() == valY[i]);
        temp = temp->next;
    }
}


TEST_CASE ("Test - 14: CanvasList PushFront") {
    CanvasList toCheck = CanvasList();
    Shape* First = new Shape(1, 3);
    toCheck.push_back(First);                                                                                           // Inserting elements inside the "toCheck" list.
    Shape* Second = new Shape(2, 4);
    toCheck.push_back(Second);

    Shape* Third = new Shape(3, 5);
    toCheck.push_front(Third);                                                                                          // Calling the "push_front" function, which adds a node to the very front of the "CanvasList".

    vector<int> valX = {3, 1, 2};
    vector<int> valY = {5, 3, 4};

    ShapeNode* temp = toCheck.front();

    for (int i=0; i<3; i++) {
        REQUIRE(temp->value->getX() == valX[i]);                                                                        // Checks whether the values of X and Y in the "toCheck" are set correctly.
        REQUIRE(temp->value->getY() == valY[i]);
        temp = temp->next;
    }
}


TEST_CASE ("Test - 15: CanvasList PushBack(Empty List)") {
    CanvasList toCheck = CanvasList();

    REQUIRE(toCheck.isempty());                                                                                         // Checking the empty status of the "toCheck" list, which should return "True".

    Shape* First = new Shape(1, 3);
    toCheck.push_back(First);                                                                                           // Calling the "push_back" function, which adds a node to the very back of the "CanvasList".

    REQUIRE(toCheck.front()->value->getX() == 1);
    REQUIRE(toCheck.front()->value->getY() == 3);                                                                       // Checks whether the values of X and Y in the "toCheck" are set correctly.

}


TEST_CASE ("Test - 16: CanvasList PushBack") {
    CanvasList toCheck = CanvasList();
    Shape* First = new Shape(1, 3);
    toCheck.push_back(First);
    Shape* Second = new Shape(2, 4);
    toCheck.push_back(Second);

    Shape* Third = new Shape(3, 5);
    toCheck.push_back(Third);                                                                                           // Calling the "push_back" function multiple times, which adds a node to the very back of the "CanvasList".

    vector<int> valX = {1, 2, 3};
    vector<int> valY = {3, 4, 5};

    ShapeNode* temp = toCheck.front();

    for (int i=0; i<3; i++) {
        REQUIRE(temp->value->getX() == valX[i]);                                                                        // Checks whether the values of X and Y in the "toCheck" are set correctly.
        REQUIRE(temp->value->getY() == valY[i]);
        temp = temp->next;
    }
}


TEST_CASE ("Test - 17: CanvasList RemoveAt") {
    CanvasList toCheck = CanvasList();
    Shape* First = new Shape(1, 3);
    toCheck.push_back(First);                                                                                           // Inserting elements inside the "toCheck" list.
    Shape* Second = new Shape(2, 4);
    toCheck.push_back(Second);
    Shape* Third = new Shape(3, 5);
    toCheck.push_back(Third);

    toCheck.removeAt(1);                                                                                                // Calling the "removeAt" function, which removes a node from the "CanvasList", given its index.

    vector<int> valX = {1, 3};
    vector<int> valY = {3, 5};

    ShapeNode* temp = toCheck.front();

    for (int i=0; i<2; i++) {
        REQUIRE(temp->value->getX() == valX[i]);                                                                        // Checks whether the values of X and Y in the "toCheck" are set correctly.
        REQUIRE(temp->value->getY() == valY[i]);
        temp = temp->next;
    }
}


TEST_CASE ("Test - 18: CanvasList RemoveEveryOther") {
    CanvasList toCheck = CanvasList();
    vector<int> valX;
    vector<int> valXAfter;
    vector<int> valY;
    vector<int> valYAfter;

    for (int i=1; i<9; i++) {
        Shape* NodeVal = new Shape(i, i+2);
        valX.push_back(i);                                                                                              // Inserting elements inside the "toCheck" list.
        valY.push_back(i+2);

        if (i%2 != 0) {
            valXAfter.push_back(i);
            valYAfter.push_back(i+2);
        }

        toCheck.push_back(NodeVal);
    }

    ShapeNode* temp = toCheck.front();
    toCheck.removeEveryOther();                                                                                         // Calling the "removeEveryOther" function, which removes alternate nodes starting from index 1.

    for (int i=0; i<4; i++) {
        REQUIRE(temp->value->getX() == valXAfter[i]);                                                                   // Checks whether the values of X and Y in the "toCheck" are set correctly.
        REQUIRE(temp->value->getY() == valYAfter[i]);
        temp = temp->next;
    }
}


TEST_CASE ("Test - 19: CanvasList RemoveEveryOther(Big)") {
    CanvasList toCheck = CanvasList();
    vector<int> valX;
    vector<int> valXAfter;
    vector<int> valY;
    vector<int> valYAfter;

    for (int i=1; i<100; i++) {
        Shape* NodeVal = new Shape(i, i+2);
        valX.push_back(i);
        valY.push_back(i+2);

        if (i%2 != 0) {
            valXAfter.push_back(i);
            valYAfter.push_back(i+2);
        }

        toCheck.push_back(NodeVal);                                                                                     // Inserting elements inside the "toCheck" list.
    }

    ShapeNode* temp = toCheck.front();
    toCheck.removeEveryOther();                                                                                         // Calling the "removeEveryOther" function, which removes alternate nodes starting from index 1.

    for (int i=0; i<50; i++) {
        REQUIRE(temp->value->getX() == valXAfter[i]);
        REQUIRE(temp->value->getY() == valYAfter[i]);                                                                   // Checks whether the values of X and Y in the "toCheck" are set correctly.
        temp = temp->next;
    }
}


TEST_CASE ("Test - 20: CanvasList PopFront(Empty)") {
    CanvasList toCheck = CanvasList();
    Shape* Popped = toCheck.pop_front();
    REQUIRE(Popped == NULL);                                                                                            // Calling the "pop_front" function on an empty "CanvasList", which should return "NULL".
    delete Popped;

}


TEST_CASE ("Test - 21: CanvasList PopFront(Checking Return)") {
    CanvasList toCheck = CanvasList();
    Shape* First = new Shape(1, 3);
    toCheck.push_back(First);                                                                                           // Inserting elements inside the "toCheck" list.

    for (int i=2; i<100; i++) {
        Shape* NodeVal = new Shape(i, i+2);
        toCheck.push_back(NodeVal);
    }

    REQUIRE(First == toCheck.pop_front());                                                                              // Calling the "pop_front" function on an empty "CanvasList", which should return the pointer to the "First" object.

}


TEST_CASE ("Test - 22: CanvasList PopFront(Checking List & Return)") {
    CanvasList toCheck = CanvasList();
    CanvasList OrigList = CanvasList();
    Shape* First = new Shape(1, 3);
    toCheck.push_back(First);                                                                                           // Inserting elements inside the "toCheck" list.

    for (int i=2; i<100; i++) {
        Shape* NodeVal = new Shape(i, i+2);
        Shape* NodeValOrig = new Shape(i, i+2);

        OrigList.push_back(NodeValOrig);
        toCheck.push_back(NodeVal);
    }

    Shape* Popped = toCheck.pop_front();
    REQUIRE(First == Popped);                                                                                           // Calling the "pop_front" function on an empty "CanvasList", which should return the pointer to the "First" object.

    ShapeNode* temp = toCheck.front();
    ShapeNode* tempOrig = OrigList.front();

    while (temp != NULL && tempOrig != NULL) {
        REQUIRE(temp->value->getX() == tempOrig->value->getX());                                                        // Checks whether the "pop_front" function performed the desired changes to the "CanvasList".
        REQUIRE(temp->value->getY() == tempOrig->value->getY());
        temp = temp->next;
        tempOrig = tempOrig->next;
    }
    delete Popped;
}


TEST_CASE ("Test - 23: CanvasList PopBack(Checking Return)") {
    CanvasList toCheck = CanvasList();
    for (int i=1; i<100; i++) {
        Shape* NodeVal = new Shape(i, i+2);
        toCheck.push_back(NodeVal);                                                                                     // Inserting elements inside the "toCheck" list.
    }

    Shape* Last = new Shape(100, 102);
    toCheck.push_back(Last);

    Shape* Popped = toCheck.pop_back();
    REQUIRE(Last == Popped);                                                                                // Calling the "pop_back" function on an empty "CanvasList", which should return the pointer to the "Last" object.
    delete Popped;
}


TEST_CASE ("Test - 24: CanvasList PopBack(Checking List & Return)") {
    CanvasList toCheck = CanvasList();
    CanvasList OrigList = CanvasList();

    for (int i=1; i<100; i++) {
        Shape* NodeVal = new Shape(i, i+2);
        Shape* NodeValOrig = new Shape(i, i+2);

        OrigList.push_back(NodeValOrig);
        toCheck.push_back(NodeVal);                                                                                     // Inserting elements inside the "toCheck" list.
    }

    Shape* Last = new Shape(100, 102);
    toCheck.push_back(Last);

    Shape* Popped = toCheck.pop_back();
    REQUIRE(Last == Popped);                                                                                // Calling the "pop_back" function on an empty "CanvasList", which should return the pointer to the "Last" object.

    ShapeNode* temp = toCheck.front();
    ShapeNode* tempOrig = OrigList.front();

    while (temp != NULL && tempOrig != NULL) {
        REQUIRE(temp->value->getX() == tempOrig->value->getX());                                                        // Checks whether the "pop_back" function performed the desired changes to the "CanvasList".
        REQUIRE(temp->value->getY() == tempOrig->value->getY());
        temp = temp->next;
        tempOrig = tempOrig->next;
    }
    delete Popped;
}


TEST_CASE ("Test - 25: CanvasList isEmpty") {
    CanvasList toCheck = CanvasList();
    REQUIRE(toCheck.isempty());

    for (int i=1; i<100; i++) {
        Shape* NodeVal = new Shape(i, i+2);
        toCheck.push_back(NodeVal);                                                                                     // Inserting elements inside the "toCheck" list.
    }

    REQUIRE(!toCheck.isempty());                                                                                        // Checking the empty status of the "CanvasList".
}


TEST_CASE ("Test - 26: CanvasList Find") {
    CanvasList toCheck = CanvasList();

    for (int i=1; i<100; i++) {
        Shape* NodeVal = new Shape(i, i+2);
        toCheck.push_back(NodeVal);                                                                                     // Inserting elements inside the "toCheck" list.
    }

    REQUIRE(toCheck.find(100, 101) == -1);
    REQUIRE(toCheck.find(1, 3) == 0);                                                                                   // Checking whether "find" function returns the desired index.
    REQUIRE(toCheck.find(50, 52) == 49);
}


TEST_CASE ("Test - 27: CanvasList ShapeAt(Index not in range)") {
    CanvasList OrigList = CanvasList();

    REQUIRE(OrigList.shapeAt(1) == NULL);                                                                               // Checking whether "shapeAt" function returns the "NULL" for an empty "CanvasList".

    for (int i=1; i<100; i++) {
        Shape* NodeVal = new Shape(i, i+2);
        OrigList.push_back(NodeVal);
    }

    REQUIRE(OrigList.shapeAt(200) == NULL);                                                                             // Checking whether "shapeAt" function returns the "NULL" for an INVALID index "CanvasList".
}


TEST_CASE ("Test - 28: CanvasList ShapeAt") {
    CanvasList OrigList = CanvasList();

    for (int i=1; i<50; i++) {
        Shape* NodeVal = new Shape(i, i+2);
        OrigList.push_back(NodeVal);                                                                                    // Inserting elements inside the "OrigList" list.
    }

    Shape* toCheck = new Shape(50, 52);
    OrigList.push_back(toCheck);

    for (int i=51; i<100; i++) {
        Shape* NodeVal = new Shape(i, i+2);
        OrigList.push_back(NodeVal);
    }

    REQUIRE(toCheck == OrigList.shapeAt(49));                                                                           // Checking whether "shapeAt" function returns the desired value for a valid index "CanvasList".
}