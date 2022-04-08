#include "cell.h"
#include <iostream>
#include <cstdio>

static Cell::funcPointer * funcArray; // array that holds pointers to our 3 functions

void Cell::f1(int x)
{
    std::cout << "I am f1, my value is " << x << std::endl;
}

void Cell::f2(int x)
{
    std::cout << "I am f2, my value is " << x << std::endl;
}

void Cell::f3(int x)
{
    std::cout << "I am f3, my value is " << x << std::endl;
}

//Function used to call the respective function pointer, and create the random value it will display
void Cell::callFunc(int index)
{
    int val = rand()%99 +1;
    (*(funcArray[index]))(val);
}

// This function will display the location of the Cell and print its respective randomly selected function
void Cell::tick()
{
    int val = rand()%99 +1; // random value for function
    
    //Create array of pointer to functions 
    funcPointer * funcArray = new funcPointer[3];
    funcArray[0] = &f1;
    funcArray[1] = &f2;
    funcArray[2] = &f3;

    // Output
    std::printf("This cell is located at X: %d\tY: %d\tZ:%d\n", x, y, z);
    (*(funcArray[funcIndex]))(val);
    std::cout << std::endl;
    
    //clean array
    delete [] funcArray;
}

// Cell constructor stores x,y,z and the index of the function that is randomly assigned to this Cell
Cell::Cell(int x, int y, int z)
{
    funcArray = new funcPointer[3];
    Cell::x = x;
    Cell::y = y;
    Cell::z = z;
    funcIndex = rand()%3;
}        