#include "vec.h"
#include <iostream>

Vector::Vector()
   {m_size = 0;
    m_capacity =1;
    arr = new int[m_capacity];
   }
Vector::Vector(const Vector& obj)
   {
      m_size = obj.m_size;
      m_capacity = obj.m_capacity;
      arr = new int[m_capacity];
      for(int i = 0; i<size(); ++i)
      {
            arr[i] = obj.arr[i];
      }
     
   }
   Vector::~Vector()
   { delete [] arr; arr = nullptr; }
int& Vector::operator[](int pos )
{
    return arr[pos];
}
int Vector::size()
{
    return m_size;
}
Vector& Vector::operator=(const Vector& rhs)
{     
     if(this == &rhs)
     {
         return *this;
     }

     if(empty())
     {
         m_size = rhs.m_size;
         m_capacity = rhs.m_capacity;
         delete [] arr;
         arr = new int[m_capacity];
         for(int i =0; i<m_size; ++i)
         {
             arr[i] = rhs.arr[i];
         }

     }

  return *this;
}
void Vector::push_front(int element)
   {
       if(m_size == m_capacity){
        int* arr1 = new int[m_capacity*2];
        for(int i = 0; i<m_size; ++i)
        {
            arr1[i+1]=arr[i];
        }
        arr1[0] = element;
        delete [] arr;
        arr = arr1;
        arr1 = nullptr;
        ++m_size;
   }
   }

 void Vector::push_back(int element)
   {  if(m_size == m_capacity){
        int * arr1 = new int[m_capacity*2];
      for(int i = 0; i < m_size; ++i)
      {
          arr1[i] = arr[i];
      }  
      arr1[m_size] = element;
      delete [] arr;
      arr = arr1;
      arr1 = nullptr;
      ++m_size;
   }else
   {
       arr[m_size] = element;
       ++m_size;
   }
   }

void Vector::pop_back()
{
    --m_size;
}
void Vector::pop_front()
{
    
    for(int i =0; i< m_size; ++i)
    {
        arr[i] = arr[i+1];
    }
   
    --m_size;

}    
bool Vector::empty()
{
    if(m_size == 0)
     return true;

  return false;   
}
int main()
{
   Vector v;
   v.push_back(4); 
   v.push_back(5); 
   v.push_back(4);
   Vector vec = v;
   for(int i =0; i<vec.size(); ++i)
   {
       std::cout<< vec[i];
   }
   
}