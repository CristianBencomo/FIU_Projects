#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>


typedef enum {false, true} bool;

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

//too many arguments input
void argerror()
{
    printf("Error: more than 2 arguments have been detected.\n"); 
    printf("You can only input the number of samples and the destination filename.");
    printf("Example: \"./waveform data.dat 100\"");
    exit(0);
}

int main(int argc, char argv[])
{
    FILE *filehandle = NULL;
    char filename[40];
    char ch[1]; 
    int sampnumtotal;
    int sampnumcurrent = 0;
    char str[10];

    //Too many arguments error
    if(argc > 3)
    {
        argerror();
    }
    
    //assign command line arguments
    for(int i=1; i<argc; i++)
    {
        *str = argv[i];
        if(isnumber(str))
        {
            sampnumtotal = atoi(str);
        }
        else
        {
            strcmp(filename, str);
        }
    }
    
    //modify file
    filehandle = fopen(filename , "r+");
    for (int i = 0; i < sampnumtotal; i++)
    {    
        sleep(1);
        if(!kbhit())
        {
            fprintf(filehandle,"0");
            printf("0");
        }
        else 
        {
            fprintf(filehandle,"1");
            printf("1");
        }
    return 0;
    }
}