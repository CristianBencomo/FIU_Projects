#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;
void createArray();
void createArray(int rows, int columns, int tables);
void readFromFile(string line);
void displayArray(int flag);
void deleteArray();

int ***Ary;
int rows, columns, tables;
string inRedirect, userAnswer;
int writeFile_flag = 0;
ofstream file_write;

int main(int argc, char* argv[]) {
    if (argc > 1)
    {
        char *command1_ptr = argv[1];
        char *file_ptr;
        ifstream file_read;
        string if_file, of_file;

        // Using strcmp because a regular comparison always returns false
        if (strcmp(command1_ptr, "-of") == 0)
        {
            file_write.open(argv[2], ios::trunc);
            writeFile_flag = 1;
        }

        if (strcmp(command1_ptr, "-if") == 0)
        {
            file_read.open(argv[2]);
        }

        if (argc == 5)
        {
            char *command2_ptr = argv[3];
            if (strcmp(command2_ptr, "-of") == 0)
            {
                file_write.open(argv[4], ios::trunc);
                writeFile_flag = 1;
            }

            if (strcmp(command2_ptr, "-if") == 0)
            {
                file_read.open(argv[4]);
            }
        }

        string line, str;
        while (getline(file_read, line))
        {
            readFromFile(line);
        }
    }
    else
    {
        do
        {
            createArray();
            cout << endl
                 << endl;

            for (int i = 0; i < rows; i++)
            {
                cout << "Z-axis dimmension location: " << i << endl;

                for (int j = 0; j < columns; j++)
                {
                    for (int k = 0; k < tables; k++)
                    {
                        if (writeFile_flag == 1)
                        {
                            file_write << Ary[i][j][k] << "   ";
                        }
                        else
                        {
                            cout << Ary[i][j][k] << "   ";
                        }
                    }
                    if (writeFile_flag == 1)
                    {
                        file_write << endl;
                    }
                    else
                    {
                        cout << endl;
                    }
                }
                if (writeFile_flag == 1)
                {
                    file_write << endl
                               << endl;
                }
                else
                {
                    cout << endl
                         << endl;
                }
                cout << endl
                     << endl;
            }

            deleteArray();

            cout << "Would you like to run the programn again? (Y/N)" << endl;
            cin >> userAnswer;
        } while (userAnswer.compare("N"));
    }

    return 0;
}

void createArray(int rows, int columns, int tables)
{
    srand(time(NULL));

    Ary = new int **[rows];

    for (int i = 0; i < rows; i++)
    {
        Ary[i] = new int *[columns];

        for (int j = 0; j < columns; j++)
        {
            Ary[i][j] = new int[tables];

            for (int k = 0; k < tables; k++)
            {
                Ary[i][j][k] = rand() % 9 + 1;
            }
        }
    }
}
void createArray()
{
    cout << "Please enter the x (rows), y(columns), tables(tables) dimension of the array" << endl;
    cin >> rows >> columns >> tables;

    createArray(rows, columns, tables);
}

void displayArray(int flag)
{
    for (int i = 0; i < rows; i++)
    {
        if (flag == 1)
        {
            file_write << "Z-axis dimmension location: " << i << endl;
        }
        else
        {
            cout << "Z-axis dimmension location: " << i << endl;
        }

        for (int j = 0; j < columns; j++)
        {
            for (int k = 0; k < tables; k++)
            {
                if (flag == 1)
                {
                    file_write << Ary[i][j][k] << "   ";
                }
                else
                {
                    cout << Ary[i][j][k] << "   ";
                }
            }
            if (flag == 1)
            {
                file_write << endl;
            }
            else
            {
                cout << endl;
            }
        }
        if (flag == 1)
        {
            file_write << endl
                       << endl;
        }

        if (writeFile_flag == 1)
        {
            file_write << endl
                       << endl;
        }
        else
        {
            cout << endl
                 << endl;
        }
    }
}

void deleteArray()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            delete[] Ary[i][j];
        }

        delete[] Ary[i];
    }
    delete Ary;
}

void readFromFile(string line)
{
    string str;
    stringstream ss(line);
    ss >> str;

    if (isdigit(str[0]))
    {
        rows = stoi(str);
        ss >> columns >> tables;
        createArray(rows, columns, tables);
        if (writeFile_flag == 1)
        {
            file_write << endl
                       << endl;
        }
        else
        {
            cout << endl
                 << endl;
        }
        displayArray(writeFile_flag);
        deleteArray();
    }

    else
    {
        if (!str.compare("N"))
        {
            if (writeFile_flag == 1)
            {
                file_write << "Command to terminate program received" << endl
                           << "Closing program" << endl;
            }
            else
            {
                cout << "Command to terminate program received" << endl
                     << "Closing program" << endl;
            }
            ::exit(0);
        }
        else if (!str.compare("Y"))
        {
            if (writeFile_flag == 1)
            {
                file_write << "Looking for new input values..." << endl;
            }
            else
            {
                cout << "Looking for new input values..." << endl;
            }
        }
        else
        {
            if (writeFile_flag == 1)
            {
                file_write << "Looking for new input values..." << endl;
            }
            else
            {
                cout << "unknown command, closing program" << endl;
            }
            ::exit(0);
        }
    }
}
