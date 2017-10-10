// John Chin-Jew
// 1603526
// COMSC-210-3157

#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

template <typename T>
class Stack {
  private:
    struct Node {T value; Node* next;};
    Node* firstNode;
    int siz;
    T dummy;
  public:
    Stack();
    Stack(const Stack<T>&); // copy constructor
    ~Stack();
    Stack<T>& operator=(const Stack<T>&); // assignment operator
    void push(const T&);
    T& peek();
    void pop();
    int size() const {return siz;}
    void clear();
    bool empty() const {return (siz == 0);}
};

// constructor
template <typename T>
Stack<T>::Stack() {
  firstNode = 0;
  siz = 0;
  dummy = T();
}

// copy constructor
template <typename V>
Stack<V>::Stack(const Stack<V>& original) {
  firstNode = 0;
  Node* lastNode = 0;
  siz = original.siz;
  for (Node* p = original.firstNode; p; p = p->next)
  {
    Node* temp = new Node;
    temp->value = p->value;
    temp->next = 0;
    if (lastNode) lastNode->next = temp;
    else firstNode = temp;
    lastNode = temp;
  }
}

// destructor
template <typename V>
Stack<V>::~Stack() {
  while (firstNode)
  {
    Node* p   = firstNode;
    firstNode = firstNode->next;
    delete p;
  }
}

// assignment operator
template <typename V>
Stack<V>& Stack<V>::operator=(const Stack<V>& original) {
  if (this != &original)
  {
    while (firstNode)
    {
      Node* p = firstNode->next;
      delete firstNode;
      firstNode = p;
    }
    Node* lastNode = 0;
    for (Node* p = original.firstNode; p; p = p->next)
    {
      Node* temp = new Node;
      temp->value = p->value;
      temp->next = 0;
      if (lastNode) lastNode->next = temp;
      else firstNode = temp;
      lastNode = temp;
    }
    siz = original.siz;
  }
  return *this;
}

// adds element onto stack
template <typename T>
void Stack<T>::push(const T& value) {
  Node* temp = new Node;
  temp->value = value;
  temp->next = firstNode;
  firstNode = temp;
  siz++;
}

// returns mustable reference to top element
template <typename T>
T& Stack<T>::peek() {
  if (firstNode == 0)
    return dummy;
  return firstNode->value;
}

// returns and removes top element
template <typename V>
void Stack<V>::pop() {
  if (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
    siz--;
  }
}

// clears stack
template <typename V>
void Stack<V>::clear() {
  while (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
    siz--;
  }
}

#endif
