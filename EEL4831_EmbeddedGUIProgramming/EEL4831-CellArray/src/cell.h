#ifndef CELL_H
#define CELL_H

class Cell
{
    private:
        int x,y,z,funcIndex;
        void static f1(int x);
        void static f2(int x);
        void static f3(int x);
        void callFunc(int index);


    public:
        void tick();
        Cell(int x, int y, int z);
        typedef void (*funcPointer)(int);
};

#endif