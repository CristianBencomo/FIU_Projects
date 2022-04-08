CC = g++
CFLAGS = -g -Wall -c
LFLAGS = -g -Wall 
OBJS = objs/main.o objs/cell.o 



cellArray : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o cellArray

objs/main.o : src/main.cpp src/cell.cpp src/cell.h 
	$(CC) $(CFLAGS) src/main.cpp -o objs/main.o 
 
objs/cell.o : src/cell.cpp src/cell.h 
	$(CC) $(CFLAGS) src/cell.cpp -o objs/cell.o 
 

clean :
	\rm -rf objs/* cellArray