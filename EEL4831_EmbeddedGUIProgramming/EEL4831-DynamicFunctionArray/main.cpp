#include <iostream>
#include <algorithm>

typedef void (*funcPointer)(int);

int randomGenerator(int i)
{
    return rand()%i;
}

void f1(int x)
{
    std::cout << "I am f1, my value is " << x << std::endl;
}

void f2(int x)
{
    std::cout << "I am f2, my value is " << x << std::endl;
}

void f3(int x)
{
    std::cout << "I am f3, my value is " << x << std::endl;
}

void callerFunction(funcPointer *functions, int order[])
{
    int j=0;
    int val;
    do
    {
        val = rand()%99 + 1;
        (*(functions[order[j]]))(val);

        j++;    
    } while (order[j] != -1);
    
}


int main()
{   
    srand(time(0));
    funcPointer *functionArray = new funcPointer[3];
    functionArray[0] = &f1;
    functionArray[1] = &f2;
    functionArray[2] = &f3;

    int N;
    std::cout << "How many functions do you want to be called?" << std::endl;
    std::cin >> N;
    std::cout << std::endl << "creating an array with " << N << " positions" << std::endl;

    int *sequenceArray = new int[N+1];
    for (int i=0; i<N; i++)
    {
        sequenceArray[i] = (i%3);
    }
    sequenceArray[N] = -1;

    for(int i=0; i<100; i++)
    {
        std::random_shuffle(&sequenceArray[0], &sequenceArray[N], randomGenerator);
    }

    callerFunction(functionArray, sequenceArray);

    delete[] sequenceArray;
    delete[] functionArray;

    return 0;
}