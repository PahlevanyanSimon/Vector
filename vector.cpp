#include "vec.h"
#include <iostream>



int& Vector::operator[](int pos )
{
    return arr[pos];
}


void Vector::push_front(int element)
   {
       if(size == capacity){
        int* arr1 = new int[capacity*2];
        for(int i = 0; i<size; ++i)
        {
            arr1[i+1]=arr[i];
        }
        arr1[0] = element;
        delete [] arr;
        arr1 = arr;
        arr1 = nullptr;
        ++size;
   }
   }

 void Vector::push_back(int element)
   {  if(size == capacity){
        int * arr1 = new int[capacity*2];
      for(int i = 0; i < size; ++i)
      {
          arr1[i] = arr[i];
      }  
      arr1[size] = element;
      delete [] arr;
      arr1 = arr;
      arr1 = nullptr;
      ++size;
   }else
   {
       arr[size] = element;
       ++size;
   }
   }

void Vector::pop_back()
{
    --size;
}

bool Vector::empty()
{
    if(size == 0)
     return true;

  return false;   
}
