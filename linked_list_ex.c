#include <iostream>
#include <string>

class dude
{
    dude(){next = NULL;}
    void setnext(dude *n){next = n;}
    ///assigns an object to the end of the chain

    dude *getnext(){return next;}
    ///proceeds down the linked list chain

    void makenew(){next = new dude;}
    ///makes a new object of dude type

private:
    int height;
    int weight;
    string Major;

    dude *next;
};
