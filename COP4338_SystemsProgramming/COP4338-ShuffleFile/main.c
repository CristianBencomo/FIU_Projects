#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>


#define lrand()((long long)rand() % 8 + 8L * ((long long)rand() + 32768L * ((long long)rand() + 32768L * ((long long)rand() + 32768L * (long long)rand())))) 
//lrand() macro generates a uniformly distributed
//non-negative long integer (MAX: 263−1)
main(int argc, char* argv[])
{
    int fd = open(argv[1], O_RDWR);
    long fileSize = lseek(fd, 0, 2);//find the file size
    srand(time(NULL));//to initialize rand and lrand so that they can properly

    //generate random numbers.
    lseek(fd, 0, 0);//rewind

    //use lrand, read, write and lseek to shuffle the bytes stored in the file
    //your code comes here:  (code size:  about 10 lines)

    char *currentCh = malloc(1);
    char *shuffledCH = malloc(1);
    long x, randCharNum;
    
    for(int i=0; i<fileSize; i++)
    {
        read(fd, currentCh, 1);
        printf("%s\n", currentCh);
        
        x = fileSize - i -1; 
        randCharNum = lrand() % (x+1);
        lseek(fd, randCharNum, 1);
        read(fd, shuffledCH, 1);
        printf("%s\n", shuffledCH);
        lseek(fd, -1, 1);
        write(fd, currentCh, 1);

        lseek(fd, -(randCharNum+1), 1);
        write(fd, shuffledCH, 1);
    }
}