#include <iostream>
#include <string>

using namespace std;
class complex
 {
    complex(){next = NULL;}
    void setnext(complex *n){next = n;}
    ///assigns an object to the end of the chain

    complex *getnext(){return next;}
    ///proceeds down the linked list chain

    void makenew(){next = new complex;}
    ///makes a new object of dude type


    private:
        double real, imaginary;
        complex *next;
 };
  int main()
  {


  return 0;
  };
