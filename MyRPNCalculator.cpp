#include <iostream>
#include <string>
using namespace std;

#include "Stack.h"

string getOperator(string);
float operate(string, float, float);
void printContents(Stack<float>);

int main() {
  cout << "Programmer: John Chin-Jew\n";
  cout << "File:       " << __FILE__ << "\n\n";
  cout << "Reverse Polish Notation Calculator!\n";
  cout << "Enter 'Q' to quit.\n" << endl;

  // Stack for storing values/results
  Stack<float> stk;

  while(1) {
    // Awaiting input...
    cout << "RPN ["; printContents(stk); cout << " ]: ";
    string buf; cin >> buf;

    // Quit?
    if (buf == "Q" || buf == "q") break;

    // Either it's an operator...
    string opr = getOperator(buf);
    if (opr != "") {

      // Enough operands?
      if (stk.size() < 2)
        continue;

      // Operate on and replace last two operands in stack!
      float a = stk.peek(); stk.pop();
      float b = stk.peek(); stk.pop();
      stk.push(operate(opr, b, a));
      continue;
    }

    // Or, it's a new digit... push to stack!
    stk.push(atof(buf.c_str()));
    cin.ignore(1000, '\n');
  }

  return 0;
}

string getOperator(string s) {
  if (s=="+" || s=="-" || s=="*" || s=="/")
    return s; // returns the operator if an operator
  return "";  // returns "" if not an operator
}

float operate(string opr, float a, float b) {
  if (opr == "+") return a + b;
  if (opr == "-") return a - b;
  if (opr == "*") return a * b;
  if (b != 0)     return a / b; // divide by zero error...
  return 0;
}

void printContents(Stack<float> orig) {
  Stack<float> copy = orig;
  while(copy.size() != 0) {
    cout << " " << copy.peek();
    copy.pop();
  }
}
