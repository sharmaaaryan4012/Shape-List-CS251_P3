/*
Name: Aaryan Sharma
CS 251 (Fall 2023) - Prof Drishika Dey
Project - 3 (Shape List)
*/

#include "canvaslist.h"
#include <iostream>
using namespace std;


CanvasList::CanvasList() {                                                                                              // Default constructor.
    listFront = NULL;
    listSize = 0;
}


CanvasList::CanvasList(const CanvasList &other) {                                                                       // Copy constructor for the "CanvasList" class.
    listSize = other.listSize;

    if (other.listFront != NULL) {
        listFront = new ShapeNode();
        listFront->value = other.listFront->value->copy();                                                              // Copying over the value stored in linked list's head node.

        ShapeNode *temp = other.listFront->next;
        ShapeNode *tempCpy = listFront;

        while (temp != NULL) {                                                                                          // Traversing the linked list.
            tempCpy->next = new ShapeNode();
            tempCpy->next->value = temp->value->copy();                                                                 // Copying over corresponding values for each node of the linked list.
            tempCpy = tempCpy->next;
            temp = temp->next;
        }
        tempCpy->next = NULL;
    }

    else {
        listFront = NULL;                                                                                               // In case, no nodes exists, we simply point the listFront to NULL.
    }
}


CanvasList& CanvasList::operator=(const CanvasList &other) {

    clear();                                                                                                            // Clears the existing "CanvasList", before copying

    listSize = other.listSize;                                                                                          // Sets the size of the "CanvasList".

    if (other.listFront == NULL) {                                                                                      // If the "other" CanvasList is empty.
        listFront = NULL;
    }

    else {
        listFront = new ShapeNode();
        listFront->value = other.listFront->value->copy();
        ShapeNode *otherNode = other.listFront->next;
        ShapeNode *tempNode = listFront;

        while (otherNode != NULL) {                                                                                     // Traversing the "CanvasList".
            tempNode->next = new ShapeNode();
            tempNode->next->value = otherNode->value->copy();                                                           // Copying over values present in "other" to its corresponding node in the copy "CanvasList".
            otherNode = otherNode->next;
            tempNode = tempNode->next;
        }

        tempNode->next = NULL;                                                                                          // Ending the "CanvasList".

    }
    return (*this);
}



CanvasList::~CanvasList() {clear();}                                                                                    // Class destructor.



void CanvasList::clear() {                                                                                              // Freeing the memory occupied by the "CanvasList".
    ShapeNode* temp = listFront;
    ShapeNode* tempPrev;

    while (temp != NULL) {                                                                                              // Traversing the "CanvasList".
        tempPrev = temp;

        temp = temp->next;

        delete tempPrev->value;                                                                                         // Accessing the next node of "temp", and then freeing the previous node.
        delete tempPrev;
    }
    listSize = 0;
    listFront = NULL;
}


void CanvasList::insertAfter(int idx, Shape* shape) {
    int pos = 0;
    ShapeNode* temp = listFront;

    while (temp != NULL) {                                                                                              // Traversing the "CanvasList".
        if (pos == idx) {
            ShapeNode* tempNode = new ShapeNode();
            tempNode->value = shape;
            tempNode->next = temp->next;                                                                                // Creating "tempNode" and pointing it towards the next node of "temp".
            temp->next = tempNode;                                                                                      // Updating temp's next to point at the "tempNode".
            listSize++;
            return;
        }
        pos++;
        temp = temp->next;
    }

}


void CanvasList::push_front(Shape* shape) {                                                                             // Adding node to the very beginning of the "CanvasList".
    ShapeNode* tempNode = new ShapeNode;
    tempNode->value = shape;
    tempNode->next = listFront;                                                                                         // Pointing the "tempNode" to the head of "CanvasList".
    listFront = tempNode;
    listSize++;
}


void CanvasList::push_back(Shape* shape) {                                                                              // Adding a node to the end of the "CanvasList".
    ShapeNode* tempNode = new ShapeNode;

    tempNode->value = shape;
    tempNode->next = NULL;

    if(isempty()) {                                                                                                     // In case the "CanvasList" is empty, we add "tempNode" to the front.
        listFront = tempNode;
        listSize++;
        return;
    }
    else {
        ShapeNode* temp = listFront;
        while (temp->next != NULL) {                                                                                    // Traversing the "CanvasList".
            temp = temp->next;
        }
        temp->next = tempNode;                                                                                          // Linking the last node to the "tempNode".
        listSize++;
    }
}


void CanvasList::removeAt(int idx) {                                                                                    // This function removes a specific node, given its index.

    int pos = 0;
    ShapeNode* temp = listFront;
    if (idx == 0) {                                                                                                     // In case, the node to be removed lies at the 1st index.
        temp = temp->next;
        delete listFront->value;
        delete listFront;
        listSize--;
        listFront = temp;
        return;
    }

    while (temp->next !=  NULL) {                                                                                       // Traversing the "CanvasList".
        if (pos + 1 == idx) {
            ShapeNode* tempPrev = temp->next;
            temp->next = temp->next->next;
            delete tempPrev->value;                                                                                     // Deleting the value assigned to the "tempPrev".
            delete tempPrev;
            listSize--;
            return;
        }
        pos++;
        temp  = temp->next;                                                                                             // Linking the node prior to the selected node to the node right after.
    }

    temp->next = NULL;
}


void CanvasList::removeEveryOther() {

    if (!isempty()) {                                                                                                   // This function executes only when "CanvasList" is not empty.
        ShapeNode* temp = listFront;
        ShapeNode* tempNext;

        while (temp != nullptr && temp->next != nullptr) {                                                              // Traversing the "CanvasList".
            tempNext = temp->next->next;
            delete temp->next->value;                                                                                   // Deleting the value and the node present next to the "temp" node.
            delete temp->next;
            temp->next = tempNext;
            temp = temp->next;
            listSize--;                                                                                                 // Decrementing "listSize".
        }
    }
}


Shape* CanvasList::pop_front() {                                                                                        // This function removes the very first node from the "CanvasList" and returns the value stored inside it.
    if (!isempty()) {
        Shape* val;
        ShapeNode* temp = listFront;

        val = temp->value;                                                                                              // Pointing "val" to the value stored inside the first node.
        listFront = temp->next;                                                                                         // Moving the head pointer "listFront" to the next node.
        delete temp;
        listSize--;

        return val;
    }
    return NULL;
}


Shape* CanvasList::pop_back() {

    if (isempty()) {
        return NULL;
    }

    ShapeNode *temp = listFront;

    if (temp->next == NULL) {                                                                                           // In case the "CanvasList" contains just one node.
        Shape *val = temp->value;
        listFront = NULL;
        listSize--;
        delete temp;
        return val;
    }

    if (!isempty()) {
        while (temp->next->next != NULL) {                                                                              // Traversing the "CanvasList", until we reach the second last node.
            temp = temp->next;
        }

        Shape *val = temp->next->value;                                                                                  // Pointing "val" to the value stored inside the popped node.
        delete temp->next;
        temp->next = NULL;                                                                                               // Ending the "CanvasList", by assigning "NULL" to the next of last node.
        listSize--;

        return val;
    }
}


ShapeNode* CanvasList::front() const {                                                                                  // This function returns the "listFront", since its a private attribute of the "CanvasList" class.
    return listFront;
}


bool CanvasList::isempty() const {                                                                                      // This function returns a boolean representing the empty statues of the "CanvasList".
    if (listFront != NULL) {
        return false;
    }
    return true;
}


int CanvasList::size() const {                                                                                          // This function returns the "listSize", since its a private attribute of the "CanvasList" class.
    return listSize;
}


int CanvasList::find(int x, int y) const {                                                                              // This function returns the index of a node which stores same values as the parameters.
    int idx = 0;
    int valX = 0;
    int valY = 0;
    ShapeNode* temp = listFront;

    while (temp != NULL) {                                                                                              // Traversing the "CanvasList".
        valX = temp->value->getX();
        valY = temp->value->getY();

        if (valX == x && valY == y) {                                                                                   // If the value stored at a node matches the parameters, then we return the node's index.
            return idx;
        }

        idx++;                                                                                                          // Incrementing the index nad moving to the next node.
        temp = temp->next;
    }

    return -1;
}


Shape* CanvasList::shapeAt(int idx) const {

    if (idx < listSize) {
        int indx = 0;
        ShapeNode* temp = listFront;

        while (temp != NULL) {                                                                                          // Traversing the "CanvasList".
            if (indx == idx) {                                                                                          // Returning the value(Shape*) stored at a specific index.
                return temp->value;
            }
            indx++;
            temp = temp->next;                                                                                          // Incrementing the index and moving to the next node.
        }
    }

    return NULL;                                                                                                        // This function returns "NULL" in case the index doesn't exist in the "CanvasList".
}


void CanvasList::draw() const {
    ShapeNode* temp = listFront;

    while (temp !=NULL) {                                                                                               // Traversing the "CanvasList".
        temp->value->printShape();                                                                                      // Employing the "printShape" function of the "Shape" class.
        temp = temp->next;
    }
}


void CanvasList::printAddresses() const {
    ShapeNode* temp = listFront;

    while (temp != NULL) {                                                                                              // Traversing the "CanvasList".
        cout << "Node Address:" << temp << "\t Shape Address: " << temp->value << endl;                                 // Printing out the addresses of the node and the shape value stored inside.
        temp = temp->next;
    }

}