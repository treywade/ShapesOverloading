//
// Created by trey on 2021-11-25. For CMPE 320 Assignment 5
// 18gdw 20170403
//

#ifndef ASSIGNMENT5_SHAPESGOOD_H
#define ASSIGNMENT5_SHAPESGOOD_H

#pragma once

#include <string>
using namespace std;
//Shape Class this is the basis of all shapes defined later
//It is assumed all shapes have a length, width and colour even though this is not the case
class Shape {
public:
    //Constructors
    Shape();
    Shape(int , int , string);
    //Deconstructor
    virtual ~Shape();
    //Getters (Length and Width aren't used)
    int getLength() const;
    int getWidth() const;
    string getOutlineColour() const;
    virtual void draw() const;
private:
    //Private attributes of all shapes
    int length;
    int width;
    string outlineColour;
};
//Fillable Class
//ALl shapes that are fillable must have a fill colour
class Fillable {
public:
    Fillable(string);
    string getFillColour() const;
private:
    string fillColour;
};
//Text Class
//All shapes that are filled with text must have a message
class Text{
public:
    Text(string);
    string getText() const;
private:
    string text;
};
//Square inherts shape
class Square : public Shape {
public:
    Square(int, int, string);
    void draw() const;
};
//Filled Square inherits Square(and Shape) along with fillable
class FilledSquare : public Square, public Fillable {
public:
    FilledSquare(int, int, string, string);
    void draw() const;
};
//Filled Text Square inherits FilledSquare( and Square( and Shape)) along with text
class FilledTextSquare : public FilledSquare, public Text {
public:
    FilledTextSquare(int, int, string, string, string);
    void draw() const;
};

//Circle inherits shape
class Circle : public Shape {
public:
    Circle(int, int, string);
    void draw() const ;
};
//Filled Circle inherits Circle( and Shape) and Fillable
class FilledCircle : public Circle, public Fillable {
public:
    FilledCircle(int, int, string, string);
    void draw() const;
};
//Arc inherits Shape
class Arc : public Shape {
public:
    Arc(int, int, string);
    void draw() const;
};


#endif //ASSIGNMENT5_SHAPESGOOD_H
