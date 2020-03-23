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
    return *top == 0;
  }
  void push (const T &x){
    if (*top == 0){
       *top = x;
       stack_size++;
    }
    else{
      top++;
      *top = x;
      stack_size ++;
    }
  }
  T pop(){
    T k = *top;
    *top = 0;
    top--;
    stack_size--;
    return k;
  }
  int size () const{
    return stack_size;
  }

  friend ostream& operator << (ostream &out, const stack &s){
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

#ifndef CONTEST
int main(){
  stack<int> s(10);
  cout << "s is empty: " << s << endl;
  s.push(42);
  cout << "s has one element: " << s <<endl;
  s.push(17);
  s.push(34);
  cout << "s has more elements: " << s << endl;
  cout << "How many? " << s.size() << endl;

  stack<int> t(5);
  t.push(7);
  cout << "t: " << t << endl;
  
  t = s;
  cout << "t: " << t << endl;
  cout << "popping from s: " << s.pop() << endl;
  s.push(8);
  //cout << "s: " << s << endl;


  stack<int> a(s);
  t.push(99);
  a.push(77);
  cout << "s: " << s <<endl;
  cout << "t: " << t << endl;
  cout << "a: " << a << endl;

  stack<double> c(4);
  c.push(3.14);
  c.push(1.414);
  cout << "c contains a character " << c << endl;

  stack<char> k(4);
  k.push('$');
  cout << "k contains a character " << k << endl;
  
  return 0;
}
#endif

