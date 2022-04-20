#include <iostream>
#include "vectempt.h"

int main()
{
  Vector<int> v;
  
   v.push_front(1);
   v.push_front(4);
   v.push_front(1);
  for(int i = 0; i < v.size(); ++i)
  {
    std::cout << v[i] << " ";
  }
}