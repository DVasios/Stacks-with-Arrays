#include "stackdemo.cpp"
#include <string>

#ifndef CONTEST
int main(){
  
  stack<string> s(10);
  s.push("giannis");
  s.push("Alekos");
  s.push("Stathis");
  s.push("Vasilis");
  s.push("Thanasis");
  s.pop();
  s.push("Thanasis");
  cout << "Size: " << s.size() << endl;

  cout << "s: " << s << endl; 


  /*stack<int> s(10);
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
  cout << "k contains a character " << k << endl;*/
  
  return 0;
}
#endif
