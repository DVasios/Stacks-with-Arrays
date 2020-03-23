#include <iostream>

using namespace std;

template <typename T>
class stack {
public:
  stack (int size) {
    stack_size = 0;
    stack_array = new T[size];
    top = stack_array;
  }
  stack (const stack &s){
    stack_size = s.size();
    stack_array = new T[s.stack_size];
    top = stack_array;
    int i;
    // αρχικοποίηση 
    for(i = 0; i < s.stack_size ; i++){
      stack_array[ i ] = s.stack_array [ i ];
      top ++;
    }
  }

  ~stack (){ 
    //delete top;
    delete[] stack_array;
  }

  const stack & operator = (const stack &s){
    stack_size = s.size();
    stack_array = new T[stack_size];
    top = stack_array;
    int i;
    for( i = 0; i < stack_size ; i++){
      stack_array[ i ] = s.stack_array[  i ];
      top++;
    }
    return *this;
  }

  bool empty (){
    return stack_array = 0;
  }

  void push (const T &x){
    if (stack_size == 0){
       *top = x;
       stack_size++;
    }
    else{
      top++;
      *top = x;
      stack_size ++;
    }
  }

  T pop() {
    T k = *top;
    top--;
    stack_size--;
    return k;
  }

  int size () const {
    return stack_size;
  }

  friend ostream & operator << (ostream &out, const stack &s){
    out << "[";
    
    int i;
    for(i=0; i<s.size(); i++){
      out << s.stack_array[i];
      if(i != (s.size() - 1)) cout << ", ";
    }
    out << "]";
    return out;
  }

private: 
  int stack_size;
  T *stack_array, *top;
};

