//
// Created by trey on 2021-11-25. For CMPE 320 Assignment 5
// 18gdw 20170403
//

#include "ShapesGood.h"
#include <string>
#include <iostream>
using namespace std;

//Deafault Constructor For Shape
Shape::Shape(){
    length = 0;
    width = 0;
    outlineColour = "";
}
//Initialize the common properties of all shapes
Shape::Shape(int len, int wid, string colour){
    length = len;
    width = wid;
    outlineColour = colour;
}
//Shape Desconstrucor
Shape::~Shape() {}

//Made getters for the private variables of shape even though they are never referenced
int Shape::getLength() const{
    return length;
}
int Shape::getWidth() const{
    return width;
}
//Every shape has an outline colour
string Shape::getOutlineColour() const{
    return outlineColour;
}
//Never actually called this would only be called if a shape object was created
void Shape::draw() const {
    cout << "Drawing a " + this->getOutlineColour() + " Shape" << endl;
}
//Create class fillable to 'fill' a shape with a colour
Fillable::Fillable(string fill){
    fillColour = fill;
}
//Get fill colour
string Fillable::getFillColour() const{
    return fillColour;
}
//Create class text to put a text message inside a shape
Text::Text(string message){
    text = message;
}
//Get text
string Text::getText() const{
    return text;
}
//Initialize a square (inherits public and private members from shape)
Square::Square(int len, int wid, string colour) : Shape(len, wid, colour){}
//Draw/Print the square this is called if a square is drawn
void Square::draw() const {
    cout << "Drawing a " + getOutlineColour() + " square" << endl;
}
//Initialize a filled square(inherits public and private members from shape and fillable)
FilledSquare::FilledSquare(int len, int wid, string colour, string fill) : Square(len, wid, colour), Fillable(fill){}

//Draw/Print the filled square this is called if a filled square is drawn
void FilledSquare::draw() const {
    cout << "Drawing a " + getOutlineColour() + " square. With "  + getFillColour() + " fill." << endl;
}
//Initalize a filled text square (inherits public and private members from filled square( and square) and text)
FilledTextSquare::FilledTextSquare(int len, int wid, string colour, string fillCol, string message) : FilledSquare(len, wid, colour, fillCol) , Text(message){}

//Draw/Print the filled text square this is called if a filled text square is drawn
void FilledTextSquare::draw() const {
    cout << "Drawing a " + getOutlineColour() + " square. With "  + getFillColour() + " fill.  Containing the text: \"" + getText() + "\"."<< endl;
}
//Initialize a circle (inherits public and private members from shape)
Circle::Circle(int len, int wid, string colour) : Shape(len, wid, colour){}

//Draw/Print the circle this is called if a circle is drawn
void Circle::draw() const {
    cout << "Drawing a " + getOutlineColour() + " circle." << endl;
}
//Initialize a filled circle(inherits public and private members from circle and fillable)
FilledCircle::FilledCircle(int len, int wid, string colour, string fillCol) : Circle(len, wid, colour), Fillable(fillCol){}

//Draw/Print the filled circle this is called if a dilled circle is drawn
void FilledCircle::draw() const {
    cout << "Drawing a " + getOutlineColour() + " circle. With "  + getFillColour() + " fill." << endl;
}
//Initialize an arc(inherits public and private members from shape)
Arc::Arc(int len, int wid, string colour) : Shape(len, wid, colour){}
//Draw/Print the arc this is called if an arc is drawn
void Arc::draw() const {
    cout << "Drawing a " + getOutlineColour() + " arc" << endl;
}


