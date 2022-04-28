#ifndef __vectemp__
#define __vectemp__
#include <iostream>

template <typename T>
class Vector
{
public:
      Vector();
      Vector(const Vector<T>&);
      Vector(Vector<T>&&);
      Vector<T>& operator=(const Vector<T>&);
      Vector<T>& operator=(Vector<T>&&);
      ~Vector();

     
     void push_back(T);
     void pop_back();
     void push_front(T);
     void pop_front();
     void insert(int pos,int num);
     bool empty();
     int  size();
     const T& operator[](int pos)const;
     friend std::ostream& operator<<(std::ostream& cout, const Vector& oth)
     {
         cout << oth.arr;
         return cout; 
     }
     const T& at(int pos)const;
   
    class iterator
    {
     public:
           iterator() = default;
           iterator(const iterator&) = default;
           iterator(iterator&&) = default;
           iterator& operator=(const iterator&) = default;
           iterator& operator=(iterator&&) = default;
           ~iterator() = default;
           iterator(T*);
           iterator& operator++()&;
           iterator operator++(int)&;
           iterator& operator--()&;
           iterator  operator--(int)&;
           iterator operator+=(int)&;
           iterator operator+(int)const;
           iterator operator-(int)const;
           T& operator*();
           bool operator==(const iterator)const;
           bool operator!=(const iterator)const;



     public:
           T* m_ptr;
         
       
    };

       iterator begin()
         {
           iterator a = arr;
           return a;
         }
         
         iterator end()
         {
            iterator a = arr + m_size;
            return a;
         }
 


private:
      T m_size;
      T m_capacity;
      T* arr;
    


};
#include "vectemp.h"
#endif

