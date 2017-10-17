// This file demos the functions defined in the Node class.

#include <iostream>

#include<linked_list.h>

int main(int argc, char** argv) {
  using namespace ::linked_list;

  Node<int> n0 = Node<int>(0, nullptr, nullptr);

  n0.PrintNodeSummary();
  std::cout << "~~ Push back 1 \n";
  n0.PushBack(1);
  n0.PrintNodeSummary();
  n0.PrintForward();
  std::cout << "~~ Push front -1 \n";
  n0.PushFront(-1);
  n0.PrintNodeSummary();
  n0.PrintBackward();
  std::cout << "~~ Pop Back \n";
  std::cout << "Popped back value: " << n0.PopBack() << std::endl;
  n0.PrintNodeSummary();
  std::cout << "~~ Pop Front \n";
  std::cout << "Popped front value: " << n0.PopFront() << std::endl;
  n0.PrintNodeSummary();
  std::cout << "~~ Insert After \n";
  n0.InsertAfter(1);
  n0.PrintNodeSummary();
  std::cout << "~~ Insert Before \n";
  n0.InsertBefore(-1);
  n0.PrintNodeSummary();
  std::cout << "~~ Delete Next \n";
  n0.DeleteNext();
  n0.PrintNodeSummary();
  std::cout << "~~ Delete Prev \n";
  n0.DeletePrev();
  n0.PrintNodeSummary();

  return 0;
}
