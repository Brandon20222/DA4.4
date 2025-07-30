#include "Circle.h"

// Constructors
Circle::Circle() {
	radius = 1;
}
Circle::Circle(int radius) {
	this->radius = radius;
}
Circle::Circle(Circle& otherCircle) {
	if (this != &otherCircle) {
		this->radius = otherCircle.radius;
	}
}
// getters and setters
void Circle::setRadius(int radius) {
	this->radius = radius;
}
int Circle::getRadius() {
	return radius;
}
double Circle::getArea() {
	double PI = 3.1415;
	return PI * radius * radius;
}
// operator overloads
Circle& Circle::operator=(Circle& otherCircle) {
	if (this != &otherCircle) {
		this->radius = otherCircle.radius;
	}
	return *this;
}
std::ostream& operator<<(std::ostream& strm, Circle& circle) {
	strm << "A Circle with radius: " << circle.getRadius() <<
		" and an area of " << circle.getArea();
	return strm;
}

std::ostream& Circle::draw(std::ostream& strm)const {
	/*
	//Top
	for (int space = 0; space < radius; space++) {
		strm << " ";
	}
	strm << "_" << endl;
	//Growing sides
	for (int rad = 0; rad < radius; rad++) {
		//left side
		for (int leftSpace = rad; leftSpace < radius - 1;  leftSpace++) {
			strm << " ";
		}
		strm << "/";
		//middle space
		for (int middleSpace = 0; middleSpace < rad; middleSpace++)
			strm << " ";
		//right side
		strm << "\\" << endl;
	}
	//Middle
	//Shrinking sides 
	//Bottom
	*/

	int radius = 6;
	int i, j;
	for (i = 0; i <= 2 * radius; i++)
	{
		for (j = 0; j <= 2 * radius; j++)
		{
			double distance = sqrt((double)(i - radius) * (i - radius) + (j - radius) * (j - radius));
			if (distance > radius - 0.65 && distance < radius + 0.2)
			{
				strm << "**";
			}
			else
			{
				strm << "  ";
			}
		}
		strm << std::endl;
	}
	return strm;
}
