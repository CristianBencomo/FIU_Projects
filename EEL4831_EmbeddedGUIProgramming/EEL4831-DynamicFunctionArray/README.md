#EEL4831_A2b_DynamycFunctionArray

>Author: Cristian Bencomo      
>Class: EEL4831         
>Assignment #: 2b              

Professors pons' embedded GUI course.        

This code creates and 2 arrays, one with function pointers and another with indexes, the index array is shuffled to call the functions within the other array in random order        


## Assisgnment instructions:
Develop a program that creates a dynamic array of function pointers that return void and takes an integer parameter. It will then initialize the array with values as addresses of f1, f2, f3 in sequence. It will also, produce a call sequence array of N (entered by user)element to hold the index number for the function array and shuffle it 100 time and then pass these two arrays to a function that will call the functions in the first array according to the sequence in the second array, which terminates with an -1 terminator. Each function should print out "I am fx, my value is,  where x is 1, 2, or 3 and the value is a random number between 1 - 100.