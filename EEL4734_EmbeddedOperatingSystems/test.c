#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void main (int argv,char argc[]) 
{
    FILE *filehandle = NULL;
    int sampnum;
    char filename[20]; //amount of characters can be modifien

    //Too many arguments error
    if(argv > 3)
    {
        argerror();
    }
    
    //assigning variables to arguments
    for(int i=1; i<argv; i++)
    {
        if(isnumber(argc[i]))
        {
            sampnum = atoi(argc[i]);
        }
        else
        {
            strcmp(filename, argc[i]);
        }
    }

    //modify file
    if ((filehandle = fopen(filename , "r+")) != NULL);
    
    


}


//function to find out if the string is a number
bool isnumber(char str[])
{
    int length = strlen(str);
    for (int i=0; i<length; i++)
    {
        if( !isdigit(str[i]) )
        return false;
    }

    return true;
}

//function for too many arguments input
void argerror()
{
    printf("Error: more than 2 arguments have been detected.\n"); 
    printf("You can only input the number of samples and the destination filename.");
    printf("Example: \"./waveform data.dat 100\"");
    exit(0);
}