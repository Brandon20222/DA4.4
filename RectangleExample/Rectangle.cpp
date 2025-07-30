#include "Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle() : Rectangle(1, 1) {}

Rectangle::Rectangle(int l, int w) : length(l), width(w) {
}

Rectangle::Rectangle(Rectangle& otherRectangle) {
	if (this != &otherRectangle) {
		this->length = otherRectangle.length;
		this->width = otherRectangle.width;
	}
}

void Rectangle::setLength(int l) {
	length = l;
}

int Rectangle::getLength()const {
	return length;
}
int Rectangle::getWidth()const {
	return width;
}

void Rectangle::setWidth(int w) {
	width = w;
}

double Rectangle::getArea() {
	return length * width;
}

Rectangle& Rectangle::operator=(Rectangle& otherRect) {
	if (this != &otherRect) {
		this->length = otherRect.length;
		this->width = otherRect.width;
	}
	return *this;
}
std::ostream& operator<<(std::ostream& strm, Rectangle& rect) {
	strm << "A Rectangle with length: " << rect.getLength() <<
		", width: " << rect.getWidth() <<
		" and an area of " << rect.getArea();
	return strm;
}

std::ostream& Rectangle::draw(std::ostream& strm)const{
	// print out the top of the box
	for (int w = 0; w < getWidth(); w++)
		strm << "-";
	strm << endl;
	// print out the sides of the box
	for (int l = 0; l < getLength(); l++) {
		strm << "|";
		for (int w2 = 1; w2 < getWidth() - 1; w2++)
			strm << " ";
		strm << "|" << endl;
	}
	// print out the bottom of the box.
	for (int w = 0; w < getWidth(); w++)
		strm << "-";
	strm << endl;

	return strm;
}
