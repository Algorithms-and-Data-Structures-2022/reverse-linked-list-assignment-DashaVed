#include "assignment/linked_list.hpp"

#include <utility> // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    Node* curr_node = front_;
    back_ = front_;
    Node* temporary_node = nullptr;
    Node* prev_node = nullptr;
    while (curr_node != nullptr){
        temporary_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = temporary_node;
      }
    front_ = prev_node;
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    if (front_ != nullptr) {
      Node* curr_node = front_;
      Node* prev_node = nullptr;
      reverse_recursive_helper(curr_node, prev_node);
    }
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    if (curr != back_){
      reverse_recursive_helper(curr->next, curr);
    }else{
      front_ = curr;
    }
    if (prev == nullptr){
      back_ = curr;
    }
    curr->next = prev;
  }

}  // namespace assignment
