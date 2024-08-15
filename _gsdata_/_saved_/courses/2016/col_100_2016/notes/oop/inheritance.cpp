#include <iostream>
using namespace std;

/* 
   public : everybody can see
   protected: only the derived classes can see
   private : only the class can see
   */

// super base class 
class Base {
	public:
		virtual int getData() = 0;
		/* this is called a pure virtual function
			It means that this class will not provide an implementation
			but all derived class have to provide an implementation for getData() */
};

// base class
class A : public Base {
	protected:
		int data;
	public:
		A (int x) {
			data = x;
		}
		A () {
		}
		/* test by removing virtual */
		virtual int getData(){
			return data;
		}

		/* test by removing virtual */
		virtual void printMyType (){
			cout << "I am type A" << endl;
		}
};

// derived class
// any function in a derived class can access the variables defined in its base
// class
class B : public A{
	protected:
		int data;
	public:
		B (int x){
			A::data = -1;
			data = x;
		}
		int getData(){
			return data;
		}

		void printMyType (){
			cout << "I am type B" << endl;
		}
};

void printData (A obj){
	// I am a third party. I want an input which is of type A 
	// or any of its derived classes

	cout << obj.getData() << " " ;
}
/* this function is meant to be written by a third party
   It does not take inputs as objects, but takes pointers as inputs
   It does not care if the object is of type A, or a derived class of A
   The correct version of getData should be called */

void printData2 (Base* obj){
	cout << obj->getData() << " " ;
}

void printMyType(A* obj){
	obj->printMyType();
}



int main(){
	A* objA = new A(3);
	B* objB = new B(5);

	/* approach 1:  this works */
	cout << objA->getData() << " " << objB->getData() << endl;

	/* approach 2:  this does not work */
	printData(*objA);
	printData(*objB); 
	cout << endl;

	/* approach 3 */
	printData2(objA);
	printData2(objB);
	cout << endl;

	printMyType(objA);
	printMyType(objB);
}
