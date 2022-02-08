#ifndef __vech__
#define __vech__
#include <iostream>
#include <string>
#include <vector>


class Vector
{
public:
  
   Vector(){size = 0;
    capacity =1;
    arr = new int[capacity];
}
  
   ~Vector()
   { delete [] arr; arr = nullptr; }
public:  
   void push_back(int element);
   void push_front(int element);
   int& operator[](int pos);
   void pop_back();
   bool empty();


private:
    int size = 0;;
    int capacity = 1;
    int * arr = new int[capacity];
};


int main()
{
   Vector v;
   v.push_back(45);
   






}
#endif