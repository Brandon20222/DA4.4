#include "Rectangle.h"
#include "Car.h"
#include "RectangleConsole.h"
#include "Dog.h"
#include "Circle.h"
#include "Triangle.h"
#include "Vehicle.h"
#include "GuardDog.h"
#include "HuntingDog.h"
#include "Lapdog.h"
#include "Animal.h"
#include "Mutt.h"
#include "Die.h"
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

// Basic Class Definitions from Day One:  Exploring Classes

Rectangle* createRectangle();
void displayRectangle(Rectangle* rect);

RectangleConsole rc;
void testAssignment();
void testAttributes();
void testAssignmentOperator();
void displayCat(Cat cat);

int main()
{

    int size = 10;
   Shape* s1 = new Circle(size);
    Shape* s2 = new Rectangle(size, size);
    Shape* s3 = new Triangle(size, size);
   s1->draw(cout);
    cout << endl;
    s2->draw(cout);
    cout << endl;
   s3->draw(cout);
    /*
    Dog* myDog = new Lapdog;

    if (Animal* a1 = dynamic_cast<Animal*>(myDog))
        cout << "It is an Animal!" << endl;
    else
        cout << "It is not an Animal!" << endl;

    if (Lapdog* ld1 = dynamic_cast<Lapdog*>(myDog))
        cout << "It is a Lapdog!" << endl;
    else
        cout << "It is not a Lapdog!" << endl;
        */


    /*
    Vehicle myVehicle;
    Vehicle yourVehicle("Ferrarri", "Ferrari", 2000);

    cout << myVehicle << endl;
    cout << yourVehicle << endl;


    Circle myCircle;
    Circle yourCircle(6);
    cout << myCircle << endl;
    cout << yourCircle << endl;

    Rectangle myRect;
    Rectangle yourRect(10, 15);
    cout << myRect << endl;
    cout << yourRect << endl;

    Triangle myTriangle;
    Triangle yourTriangle(5, 6);
    cout << myTriangle << endl;
    cout << yourTriangle << endl;

    */

    /*
    Dog myDog;

    GuardDog yourDog("Flower");

    HuntingDog hisDog;

    Lapdog theirDog;

    Mutt herDog;

    Dog** theDogs = new Dog*[5];

    theDogs[0] = &myDog;
    theDogs[1] = &yourDog;
    theDogs[2] = &hisDog;
    theDogs[3] = &theirDog;
    theDogs[4] = &herDog;
    cout << "TRICKS are for Dogs" << endl;
    for (int i = 0; i < 5; i++)
        (theDogs[i])->doTrick();

*/

    /*
    //testAssignmentOperator();
    Die myDie;
    Die yourDie;

    //cout << myDie;
    //cout << yourDie;

    Die sumDie = myDie + yourDie + myDie + yourDie + myDie;
    sumDie.roll();
    //cout << sumDie;

    Die anotherDie = sumDie - myDie - yourDie;

    anotherDie.roll();
    //cout << anotherDie;
    */
    
}

Rectangle* createRectangle() {
    int length = rc.getInt("Length");
    int width = rc.getInt("Width");
    Rectangle* rect = new Rectangle(length, width);
    return rect;
}
void displayRectangle(Rectangle* rect) {
    rc.displayRectangle(rect);
}

void testAssignment() {
    Dog myDog;
    Dog yourDog;

    //cout << "A dog has " << Dog::NUMBER_OF_LEGS << " legs." << endl;
    //cout << myDog.displayDog() << endl;
    Cat myCat;


    cout << myCat.displayCat() << endl;

    myCat.setName("Shadow");

    myCat.addLikedFood("Salmon");
    myCat.addLikedFood("Rotisserie Chicken");


    cout << "My Cat: " << myCat.displayCat() << endl;
    //cout << "Your Cat: " << yourCat.displayCat() << endl;

    cout << "...Your Cat = My Cat..." << endl;
    Cat yourCat = myCat;
    cout << "My Cat: " << myCat.displayCat() << endl;
    cout << "Your Cat: " << yourCat.displayCat() << endl;

    yourCat.changeFood("Beef", 0);
    yourCat.changeFood("Dog", 1);

    cout << "My Cat: " << myCat.displayCat() << endl;
    cout << "Your Cat: " << yourCat.displayCat() << endl;

}
void testAttributes() {
    //displayRectangle(createRectangle());
    
    Rectangle myR;
    myR.setWidth(4);
    myR.setLength(6);

    cout << myR.getWidth() << endl
        << myR.getLength() << endl
        << myR.getArea() << endl;


    Car myCar, yourCar;
    Car herCar("Red", 120000, 200, "Miata");
    Car* CarPtr;
    CarPtr = new Car("Red", 120000, 200, "Miata");
    
    myCar.setColor("Grey");
    //myCar.setModel("Rogue");
    myCar.setKm(50000);
    myCar.setPrice(24000);

    yourCar.setColor("Farrari Red");
   // yourCar.setModel("Porche");
    yourCar.setKm(0);
    yourCar.setPrice(200000);

    cout << myCar.describeCar();
    cout << endl << yourCar.describeCar();
    cout << endl << herCar.describeCar();
     
}

// test the Cat class's overload of the assignment operator.
// Demonstration will be printed to the console.
void testAssignmentOperator() {
    Cat myCat;
    Cat yourCat;
    Cat hisCat;
    Cat herCat;
    Cat theirCat;

    myCat.setName("Lucy");
    yourCat.setName("Cheese");
    hisCat.setName("Happy");
    herCat.setName("Confidant");
    theirCat.setName("Stinky");

    myCat.addLikedFood("Crunchies");
    myCat.addLikedFood("Rotisserie Chicken");


    theirCat.addLikedFood("Fish");
    theirCat.addLikedFood("Pickles");

    // test the constructors
    cout << "MyCat:  ";
    displayCat(myCat);
    cout << "Their Cat:  ";
    displayCat(theirCat);

    
    
    myCat = theirCat;


    cout << "Setting their Cat's foods to Especially sour pickles and rancid fish" << endl;
    theirCat.changeFood("Rancid Fish", 1);
    theirCat.changeFood("Especially Sour Pickles", 0);


    cout << "My Cat:  ";
    displayCat(myCat);

    cout << "Their Cat:  ";
    displayCat(theirCat);


    // what happens if you don't check for idenity in the assignment 
    // overload first.
    myCat = myCat;
    cout << "My Cat:  ";
    displayCat(myCat);
}

void displayCat(Cat cat) {
    cout << cat.displayCat() << endl << endl;
}
