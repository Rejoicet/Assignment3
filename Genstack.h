#include <iostream>

using namespace std;

template <class T>
class GenStack {
  T *genArray;
  T *tempArray;
  int capacity, t;

public:
  int size() const;  //const because they do not alter the contents of the stack
  bool empty() const;
  const T& top ();
  T& pop ();
  void push (const T& p);

  GenStack();
  ~GenStack();
};

template <class T>
GenStack<T>::GenStack()
{
  capacity = 5;
  genArray = new T [capacity];
  t = -1;
}

template <class T>
GenStack<T>::~GenStack()
{
  delete genArray;
}

template <class T>
int GenStack<T>::size() const
{
  return (t+1);
}

template <class T>
bool GenStack<T>::empty() const
{
  return (t<0);
}

template <class T>
const T& GenStack<T>::top()
{
  return genArray[t];
}

template <class T>
T& GenStack<T>::pop()
{
  if (empty()) {
    cout << "There are no elements in the stack to pop!!" << endl;
    exit(1);
  }
  else {
    return genArray[t--];
  }
}

/*template <class T>
T GenStack <T>::top()
{
  if (empty()) {
    cout << "There are no elements in the stack" << endl;
    exit(1);
  }
  else {
    return genArray[t];
  }
}

template <class T>
T GenStack <T>::pop()
{
  if (empty()) {
    cout << "There are no elements in the stack" << endl;
    exit(1);
  }
  else {
    return genArray[t--];
  }
}*/

template <class T>
void GenStack<T>::push (const T& p)
{
  if (size() == capacity) {
    tempArray = new T [capacity];
    for (int i = 0; i < capacity; i++) {
      tempArray[i] = genArray[i];
    }
    capacity = capacity*2;
    genArray = new T [capacity];
    for (int i = 0; i < capacity; i++) {
      genArray[i] = tempArray[i];
    }
    genArray[++t] = p;
  }
  else {
    genArray[++t] = p;
  }
}
