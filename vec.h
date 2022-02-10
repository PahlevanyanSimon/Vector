#ifndef __vech__
#define __vech__

class Vector
{
public:
  
   Vector();
   Vector(const Vector&);
   ~Vector();
public: 
   int& operator[](int pos); 
   Vector& operator=(const Vector& rhs);
   void push_back(int element);
   void push_front(int element);
   void pop_back();
   void pop_front();
   bool empty();
   int  size();
   

private:
     
    int m_size;
    int m_capacity;
    int * arr;
};



#endif