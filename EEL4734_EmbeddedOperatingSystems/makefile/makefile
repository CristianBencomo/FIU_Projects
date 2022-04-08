OBJS = a.o b.o c.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

p1 : $(OBJS)
    $(CC) $(LFLAGS) $(OBJS) -o p1

a.o : a.cpp a.h c.h
    $(CC) $(CFLAGS) a.cpp
    
b.o : b.cpp b.h c.h
    $(CC) $(CFLAGS) b.cpp

c.o : c.cpp c.h
    $(CC) $(CFLAGS) c.cpp

clean :
    \rm *.o *~ p1

tar :
    tar cfv p1.tar a.cpp a.h b.cpp b.h c.cpp c.h

