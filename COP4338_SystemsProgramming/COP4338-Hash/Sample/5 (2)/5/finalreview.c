#include <stdio.h> 
#include <stdlib.h> 

int main() {
double r1 = (double)rand(), r2 = (double)rand(), R = (double) RAND_MAX; 
printf("%f", r2);
printf ("(%d, %d)", (int)(r1/(R+1)*6+1),(int)(r2/(R+1)*6+1)); 
return 0; }