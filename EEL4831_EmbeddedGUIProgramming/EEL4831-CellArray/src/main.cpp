#include "cell.h"
#include <string>
#include <iostream>


Cell ****array;
int x, y, z, randNum;
std::string userAnswer;

// Generates and populates the 3d Cell pointer Array
void cellArrayGen()
{
    array = new Cell ***[x];

    for (int i = 0; i < x; i++)
    {
        array[i] = new Cell **[y];

        for (int j = 0; j < y; j++)
        {
            array[i][j] = new Cell  *[z];
        
            for (int k = 0; k < z; k++)
            {
                Cell *cell = new Cell(i, j, k);
                array[i][j][k] = cell;
            }
        }
    }
    std::cout << std::endl;
}

// Deletes and cleans up the space used for the 3d Array
void cellArrayDelete()
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for(int k = 0; k < z; k++)
            {
                delete[] array[i][j][k];
            }
            delete[] array[i][j];
        }
        delete[] array[i];
    }
    delete [] array;
}

int main(int argc, char const *argv[])
{
    srand(time(0));

    // Do while used to loop until the user selects 'N'
    do
    {
        //Asking for the size of the array
        std::cout << "Please enter the X, Y, and Z coordinates\nFormat:\nX Y Z" << std::endl;
        std::cin >> x >> y >> z;

        cellArrayGen();

        // For loops to tick each individual Cell
        for (int i = 0; i < x; i++)
        {           
            for (int j = 0; j < y; j++)
            {
                for (int k = 0; k < z; k++)
                {
                    array[i][j][k]->tick();
                }
            }
        }

        cellArrayDelete();

        // Prompt user if they want to run the program again
        std::cout << "Would you like to run the programn again? (Y/N)" << std::endl;
        std::cin >> userAnswer;
    } while (userAnswer.compare("N"));
    
    return 0;
}
