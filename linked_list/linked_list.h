#include <iostream>
#include <string>

namespace linked_list {

template <typename T>
class Node {
 public:
  Node(const T& data, Node<T>* next, Node<T>* prev)
      : data_(data), next_(next), prev_(prev) {}

  void set_data(const T& data) { data_ = data; }
  const T& data() const { return data_; }

  const Node<T>* const next() const { return next_; }
  Node<T>* const m_next() { return next_; }
  void set_next(Node<T>* const next) { next_ = next; }

  const Node<T>* const prev() const { return prev_; }
  Node<T>* const m_prev() { return prev_; }
  void set_prev(Node<T>* const prev) { prev_ = prev; }

  void PrintForward() const {
    const Node<T>* tmp = this;
    while (tmp) {
      std::cout << tmp->data() << " ";
      tmp = tmp->next();
    }
    std::cout << std::endl;
    std::cout << "---\n";
  }

  void PrintBackward() const {
    const Node<T>* tmp = this;
    while (tmp) {
      std::cout << tmp->data() << " ";
      tmp = tmp->prev();
    }
    std::cout << std::endl;
    std::cout << "---\n";
  }

  void PrintNodeSummary() const {
    std::cout << "Data: " << data_ << std::endl;
    std::cout << "Prev: " << (prev_ ? std::to_string(prev_->data()) : "Null")
              << std::endl;
    std::cout << "Next: " << (next_ ? std::to_string(next_->data()) : "Null")
              << std::endl;
    std::cout << "---\n";
  }

  // Mutable access to the last element.
  Node<T>* const MFront() {
    Node<T>* tmp = this;
    while (tmp->prev()) {
      tmp = tmp->m_prev();
    }
    return tmp;
  }

  // Const access to the first element.
  const Node<T>* const Front() const {
    const Node<T>* tmp = this;
    while (tmp->prev()) {
      tmp = tmp->prev();
    }
    return tmp;
  }

  // Mutable access to the last element.
  Node<T>* const MBack() {
    Node<T>* tmp = this;
    while (tmp->next()) {
      tmp = tmp->m_next();
    }
    return tmp;
  }

  // Const access to the last element.
  const Node<T>* const Back() const {
    const Node<T>* tmp = this;
    while (tmp->next()) {
      tmp = tmp->next();
    }
    return tmp;
  }

  // Adds a new node to the end.
  void PushBack(const T& data) {
    this->MBack()->set_next(new Node<T>(data, nullptr, this->MBack()));
  }

  // Adds a new node to the beginning.
  void PushFront(const T& data) {
    this->MFront()->set_prev(new Node<T>(data, this->MFront(), nullptr));
  }

  // Removes the last element and returns its value.
  T PopBack() {
    const Node<T>* prev_last = this->Back();
    const T prev_last_data = prev_last->data();
    if (prev_last->prev()) {
      this->MBack()->m_prev()->set_next(nullptr);
    } else {
      std::cout << "[WARNING]:: The linkedlist is depleted with this call to "
                   "PopBack. The object that called this function no longer "
                   "exists in memory.";
    }
    delete prev_last;
    return prev_last_data;
  }

  // Removes the first element and returns its value.
  T PopFront() {
    const Node<T>* prev_front = this->Front();
    const T prev_front_data = prev_front->data();
    if (prev_front->next()) {
      this->MFront()->m_next()->set_prev(nullptr);
    } else {
      std::cout << "[WARNING]:: The linkedlist is depleted with this call to "
                   "PopFront. The object that called this function no longer "
                   "exists in memory.";
    }
    delete prev_front;
    return prev_front_data;
  }

 private:
  T data_;
  Node<T>* next_;
  Node<T>* prev_;
};

}  // namespace linked_list