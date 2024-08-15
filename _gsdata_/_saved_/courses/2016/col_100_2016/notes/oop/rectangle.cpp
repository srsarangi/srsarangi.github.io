#include <iostream>
using namespace std;

class Rectangle {
	private:
		int height, width; // class variable
	public:
		Rectangle (int h, int w);  // constructor
		Rectangle () {
			height = -1;
			width = -1;
		}

		int getArea(); // regular member function
};

int y ; //global variable

Rectangle::Rectangle(int h, int w){
	height = h;
	width = w;
}
int Rectangle::getArea(){
	int y; // local variable
	return (height * width);
}
/*
   C   --> C++
   printf --> cout
   scanf --> cin
   malloc --> new
   free --> delete
   */

int main(){
	Rectangle def; // height = -1, width = -1
	Rectangle rect (3,5); // creating an object, rect, from the class Rectangle

	// create a new rectangle and read in the height and width from the user
	int height, width;

	cin >> height >> width ; 
	cout << "Height = " << height << " width = " << width << endl;
	Rectangle *rect2 = new Rectangle (height, width);

	cout << rect.getArea() << " , " << rect2->getArea() << endl;
}
