/*
Name: Aaryan Sharma
CS 251 (Fall 2023) - Prof Drishika Dey
Project - 3 (Shape List)
*/

#include "shape.h"
#include <sstream>


Shape::Shape() {                                                                                                        // Following are the class function definitions for the "Shape" base class.
    x = 0;
    y = 0;
}


Shape::Shape(int x, int y) {                                                                                            // Shape constructor, which sets the values of x and y based on the parameters x and y,
    this->x = x;
    this->y = y;
}


Shape::~Shape() {}                                                                                                      // Empty destructor.


Shape* Shape::copy() {                                                                                                  // Copy constructor.
    return new Shape(x, y);
}

int Shape::getX() const {
    return x;
}


int Shape::getY() const {
    return y;
}


void Shape::setX(int x) {
    this->x = x;
}


void Shape::setY(int y) {
    this->y = y;
}


string Shape::printShape() const {                                                                                      // This function returns details about the shape.
    stringstream ss;
    ss << "It's a Shape at x: " << x << ", y: " << y;
    return ss.str();
}


Circle::Circle() : Shape(), radius(0) {                                                                                 // Following are the class function definitions for the "Circle" class, based on the "Shape" class.
}


Circle::Circle(int r) : radius(r) {
}


Circle::Circle(int x, int y, int r) : Shape(x, y), radius(r) {
}


Circle::~Circle() {}


Circle* Circle::copy() {
    return new Circle(x, y, radius);
}


int Circle::getRadius() const {
    return radius;
}


void Circle::setRadius(int radius) {
        this->radius = radius;
}


string Circle::printShape() const {
    stringstream ss;
    ss << "It's a Circle at x: " << x << ", y: " << y << ", radius: " << radius;
    return ss.str();
}


Rect::Rect() : Shape(), width(0), height(0) {                                                                                                                                                            // Following are the class function definitions for the "Rect" class, based on the "Shape" class.
}


Rect::Rect(int w, int h) : width(w), height(h) {
}


Rect::Rect(int x, int y, int w, int h) : Shape(x, y), width(w), height(h) {
}


Rect::~Rect() {}


Rect* Rect::copy() {
    return new Rect(x, y, width, height);
}


int Rect::getWidth() const {
    return width;
}


int Rect::getHeight() const {
    return height;
}


void Rect::setWidth(int width) {
        this->width = width;
}


void Rect::setHeight(int height) {
        this->height = height;
}


string Rect::printShape() const {
    stringstream ss;
    ss << "It's a Rectangle at x: " << x << ", y: " << y << " with width: " << width << " and height: " << height;
    return ss.str();
}


RightTriangle::RightTriangle() : Shape(), base(0), height(0) {                                                          // Following are the class function definitions for the "RightTriangle" class, based on the "Shape" class.
}


RightTriangle::RightTriangle(int b, int h) : base(b), height(h) {
}


RightTriangle::RightTriangle(int x, int y, int b, int h) : Shape(x, y), base(b), height(h) {
}


RightTriangle::~RightTriangle() {}


RightTriangle* RightTriangle::copy() {
    return new RightTriangle(x, y, base, height);
}


int RightTriangle::getBase() const {
    return base;
}


int RightTriangle::getHeight() const {
    return height;
}


void RightTriangle::setBase(int base) {
        this->base = base;
}


void RightTriangle::setHeight(int height) {
        this->height = height;
}


string RightTriangle::printShape() const {
    stringstream ss;
    ss << "It's a Right Triangle at x: " << x << ", y: " << y << " with base: " << base << " and height: " << height;
    return ss.str();
}