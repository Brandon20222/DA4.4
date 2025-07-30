#ifndef RECTANGLE
#define RECTANGLE
#include "Shape.h"
#include <iostream>


class Rectangle : public Shape {
private:
	int length;
	int width;
public:
	Rectangle();
	Rectangle(int l, int w);
	Rectangle(Rectangle& otherRectangle);  // *
	int getLength()const;
	int getWidth()const;
	void setLength(int l);
	void setWidth(int w);
	double getArea();
	Rectangle& operator=(Rectangle& otherRect);
	friend std::ostream& operator<<(std::ostream& strm, Rectangle& rect);
	std::ostream& draw(std::ostream& strm)const override;

};


#endif // !RECTANGLE

