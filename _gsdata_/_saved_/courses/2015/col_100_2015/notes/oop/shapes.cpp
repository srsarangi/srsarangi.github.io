#include <iostream>
using namespace std;

class Shape {
	public:
		Shape();
		virtual int getArea();
};

Shape::Shape (){
}
int Shape::getArea(){
	return -1;
}

// inheritance

class Rectangle : public Shape {
	private:
		int height, width; // class variable
	public:
		Rectangle (int h, int w);  // constructor
		int getArea(); // regular member function
};


Rectangle::Rectangle(int h, int w){
	height = h;
	width = w;
}
int Rectangle::getArea(){
	int y; // local variable
	return (height * width);
}

class Triangle : public Shape{
	private:
		int base, height;

	public:
		Triangle (int b, int h);
		int getArea();
};

Triangle::Triangle(int b, int h){
	base = b;
	height = h;
}

int Triangle::getArea(){
	return (base * height / 2);
}

void printArea(Shape *shape){
	cout << shape->getArea() << endl;
}

int main(){
	Rectangle * rect = new Rectangle (2,4);
	Triangle * tri = new Triangle (2,4);

	printArea(rect);
	printArea(tri);
}
