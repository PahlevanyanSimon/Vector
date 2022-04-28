#include "vectempt.h"
#include <iostream>

template<typename T>
Vector<T>::Vector(): m_size{}, m_capacity{1}
{
    arr = new T[m_capacity];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& obj)
{
    m_size = obj.m_size;
    m_capacity = obj.m_capacity;
    arr = new T[m_capacity];
    for ( int i = 0; i<m_size; ++i)
    {
        arr[i] = obj.arr[i];
    }

}

template<typename T>
Vector<T>::Vector(Vector<T>&& obj)
{
    this->m_size = obj.m_size;
    this->m_capacity = obj.m_capacity;
    this->arr = obj.arr;
    obj.arr = nullptr;
    obj.m_size = 0;
    obj.m_capacity = 0;
    
}


template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& rhs)
{
   
   this->m_size = rhs.m_size;
   this->m_capacity = rhs.m_capacity;
   this->arr = rhs.arr;
   rhs.m_size = 0;
   rhs.m_capacity = 0;
   rhs.arr = nullptr;
   
   return *this;

} 

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs)
{
   if(this == &rhs)
   {
       return *this;
   }
   m_size = rhs.m_size;
   m_capacity = rhs.m_capacity;
    for ( int i = 0; i<m_size; ++i)
    {
        arr[i] = rhs.arr[i];
    }
    return *this;
}

template<typename T>
Vector<T>::~Vector()
{
    delete [] arr;
    arr = nullptr;
}

template<typename T>
void Vector<T>::push_back(T element)
{
    if(m_size == m_capacity)
    { T* arr1 = new T[m_capacity*2];
    for(int i = 0; i < m_size; ++i)
    {
        arr1[i] = arr[i];
    }
    arr1[m_size] = element;
    delete [] arr;
    arr = arr1;
    arr1 = nullptr;
    ++m_size;
    }
    else
    {
        arr[m_size] = element;
        ++m_size;
    }
} 

template<typename T>
void Vector<T>::pop_back()
{
    --m_size;
}

template<typename T>
void Vector<T>::push_front(T elem)
{   if(empty())
     arr[0] = elem;
    if(m_size == m_capacity)
    {
        T* arr1 = new T[m_capacity*2];
     for( int i = 0; i< m_size; ++i)
    {
        arr1[i+1] = arr[i];
    }
    arr1[0] = elem;
    delete [] arr;
    arr = arr1;
    arr1 = nullptr;
    ++m_size;
    }
    else{
     ++m_size;
     T* arr1 = new T[m_size];   
    for( int i = 0; i< m_size; ++i)
    {
       arr1[i+1] = arr[i];
    }    
    arr1[0] = elem;
    delete [] arr;
    arr = arr1;
    arr1 = nullptr;
    }
   
}


template<typename T>
void Vector<T>::pop_front()
{
    for( int i = 0; i < m_size; ++i )
    {
        arr[i] = arr[i+1];
    }
    --m_size;
}


template<typename T>
bool Vector<T>::empty()
{
    if(m_size == 0)
       return true;

    return false;
}

template<typename T>
int Vector<T>::size()
{
    return m_size;
}

template<typename T>
const T& Vector<T>::operator[](int pos)const
{
    return arr[pos];
}


template<typename T>
const T& Vector<T>::at(int pos)const
{
     if(pos >= 0 && pos < m_size)
         return arr[pos];
     else
     {
        throw std::out_of_range("Segmentation fault-runtime eror");
     }    
}

// iterator

template<typename T>
Vector<T>::iterator::iterator(T* ptr): m_ptr{ptr}{}

template<typename T>
typename Vector<T>::iterator&  Vector<T>::iterator::operator++()&
{
    this->m_ptr++;
    return *this;
}

template<typename T>
typename Vector<T>::iterator Vector<T>::iterator::operator++(int)&
{
    iterator tmp = *this;
    this->m_ptr++;
    
     return tmp;

}

template<typename T>
typename Vector<T>::iterator& Vector<T>::iterator::operator--()&
{
    this->m_ptr--;
    return *this;
}

template<typename T>
typename Vector<T>::iterator Vector<T>::iterator::operator--(int)&
{
    iterator tmp = *this;
    this->m_ptr--;
    
     return tmp;

}

template<typename T>
typename Vector<T>::iterator Vector<T>::iterator::operator+=(int pos)&
{
       m_ptr += pos;
       return *this;
}

template<typename T>
typename Vector<T>::iterator Vector<T>::iterator::operator+(int pos) const
{
         typename Vector<T>::iterator tmp = &this;
         tmp += pos;
         return tmp;
}


template<typename T>
typename Vector<T>::iterator Vector<T>::iterator::operator-(int pos) const
{
         typename Vector<T>::iterator tmp = &this;
         tmp -= pos;
         return tmp;
}

template<typename T>
T& Vector<T>::iterator::operator*()
{
    return *m_ptr;
}

template<typename T>
 bool Vector<T>::iterator::operator==(const iterator i)const
{
     return m_ptr == i.m_ptr;
}

template<typename T>
 bool Vector<T>::iterator::operator!=(const iterator i)const
{
     return m_ptr != i.m_ptr;
}