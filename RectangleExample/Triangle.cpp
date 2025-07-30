#include "Triangle.h"

// Constructors: default, one with base and height, and copy
Triangle::Triangle() {
	base = 1;
	height = 1;
}
Triangle::Triangle(int base, int height) {
	this->base = base;
	this->height = height;
}
Triangle::Triangle(Triangle& otherTriangle) {
	if (this != &otherTriangle) {
		this->base = otherTriangle.base;
		this->height = otherTriangle.height;
	}
}

// Getters and setters for base and height and area
int Triangle::getBase()const {
	return base;
}
int Triangle::getHeight()const {
	return height;
}
double Triangle::getArea()const{
	return .5 * base * height;
}
void Triangle::setBase(int base) {
	this->base = base;
}
void Triangle::setHeight(int height) {
	this->height = height;
}

// equals and << overload
Triangle& Triangle::operator=(Triangle& otherTriangle) {
	if (this != &otherTriangle) {
		this->base = otherTriangle.base;
		this->height = otherTriangle.height;
	}
	return *this;
}

ostream& operator<<(ostream& strm, Triangle& triangle) {
	strm << "A Triangle with base: " << triangle.getBase() <<
		", height: " << triangle.getHeight() <<
		" and an area of " << triangle.getArea();
	return strm;
}

std::ostream& Triangle::draw(std::ostream& strm)const {
	
	// print out the sides of the box
	for (int row = 0; row < height; row++) {
		strm << "|";
		for (int space = 0; space < row; space++)
			strm << " ";
		strm << "\\" << endl;
	}
	strm << ' ';
	// print out the bottom of the box.
	for (int i = 0; i < base; i++)
		strm << "-";
	strm << endl;

	return strm;
}

