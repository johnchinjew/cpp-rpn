#include <iostream>
#include <string>
using namespace std;

#include <cassert>

#include "Stack.h" // ifndef test
#include "Stack.h"

int main() {
  cout << "Programmer: John Chin-Jew\n";
  cout << "File:       " << __FILE__ << '\n' << endl;

  cout << "* TESTS STARTING for `Stack` *\n";

  Stack<int> stk; // create instance of Stack
  cout << "Instance of Stack created.\n";
  cout << "OK!" << endl;

  // Stack::size
  cout << "\nTesting `Stack::size`.\n";
  cout << "Expected: 0\n";
  cout << "Actual:   " << stk.size() << endl;
  assert(stk.size() == 0);
  cout << "OK!" << endl;

  // Stack::Stack
  cout << "\nTesting `Stack::Stack` constructor for valid instantiation.\n";
  assert(stk.peek() == int());
  cout << "OK!" << endl;

  // Stack::push and Stack::peek
  cout << "\nTesting `Stack::push` and `Stack::peek`.\n";
  stk.push(0);
  stk.push(9999);
  stk.push(1);
  stk.push(-1);
  stk.push(408);
  stk.push(-123);
  stk.push(17);
  cout << "Pushed 7 values to stk with stk.push().\n";
  cout << "Expected: 17 for stk.peek()\n";
  cout << "Actual:   " << stk.peek();
  assert(stk.peek() == 17);
  cout << "\nExpected: 7 for stk.size()\n";
  cout << "Actual:   " << stk.size() << '\n';
  assert(stk.size() == 7);
  cout << "OK!" << endl;

  // Stack::pop
  cout << "\nTesting `Stack::pop`\n";
  cout << "Expected: 17 for stk.peek() before pop\n";
  cout << "Actual:   " << stk.peek() << " before pop\n";
  stk.pop();
  cout << "Popped 1 element from stk with stk.pop().\n";
  cout << "Expected: -123 for stk.peek() after pop\n";
  cout << "Actual:   " << stk.peek() << " after pop\n";
  assert(stk.peek() == -123);
  cout << "Expected: 6 for stk.size()\n";
  cout << "Actual:   " << stk.size() << "\n";
  assert(stk.size() == 6);
  cout << "OK!" << endl;

  // Copy constructor test
  cout << "\nCopy constructor test.\n";
  Stack<int> stk_copy = stk;
  assert(stk.size() == stk_copy.size());
  assert(stk.peek() == stk_copy.peek());
  stk.pop(); stk_copy.pop();
  assert(stk.peek() == stk_copy.peek());
  cout << "OK!" << endl;

  // Object assignment operator test
  cout << "\nObject assignment operator test.\n";
  Stack<int> stk_assign;
  stk_assign = stk;
  assert(stk.size() == stk_assign.size());
  assert(stk.peek() == stk_assign.peek());
  stk.pop(); stk_assign.pop();
  assert(stk.peek() == stk_assign.peek());
  cout << "OK!" << endl;

  // Stack::clear and Stack::empty
  cout << "\nTesting `Stack::clear` and `Stack::empty`\n";
  stk.clear();
  assert(stk.empty() == true);
  cout << "OK!" << endl;

  // Constant Stack instance test
  cout << "\nConstant object `const Stack` test.\n";
  const Stack<int> stk_const;
  cout << "OK!\n";

  // Destructor tests implicitl by successful compilation and runtime
  cout << "* TESTS COMPLETE for `Stack` *\n" << endl;

  return 0;
}
