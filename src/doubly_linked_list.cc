#include <iomanip>
#include <sstream>
#include <stdexcept>
using std::endl;
using std::ostream;
using std::ostringstream;
using std::setfill;
using std::setw;
using std::string;

#include "doubly_linked_list.hpp"

// Functions provided to you
ostream& operator<<(ostream& os, const DoublyLinkedList& ll) {
  constexpr unsigned int kWidth = 16;
  os << "Doubly Linked List" << endl;
  os << "Head: " << ll.head_ << "\t Tail: " << ll.tail_ << endl;
  os << "Size: " << ll.size_ << endl;
  if (ll.head_ == nullptr) return (os << "Empty" << endl);
  const Node* curr = ll.head_;
  os << "Nodes (accessible from head to tail):" << endl << endl;
  os << setw(kWidth) << setfill(' ') << ' ' << ' ' << Center("prev", kWidth - 1)
     << ' ' << Center("data", kWidth - 1) << ' ' << Center("next", kWidth - 1)
     << endl;
  while (curr != nullptr) {
    ostringstream oss;
    oss << (curr->prev);
    string prev = oss.str();
    oss.str("");
    oss << (curr->next);
    string next = oss.str();
    oss.str("");
    oss << (curr->data);
    string data = oss.str();
    oss.str("");
    oss << curr;
    string address = oss.str();
    os << setw(kWidth) << setfill(' ') << ' ' << '.' << setw(kWidth)
       << setfill('-') << '.' << setw(kWidth) << '.' << setw(kWidth) << '.'
       << endl;
    os << setw(kWidth) << setfill(' ') << Center(address, kWidth - 1) << '|'
       << setw(kWidth - 1) << setfill(' ') << Center(prev, kWidth - 1) << '|'
       << setw(kWidth - 1) << Center(data, kWidth - 1) << '|' << setw(kWidth - 1)
       << Center(next, kWidth - 1) << '|' << endl;
    os << setw(kWidth) << setfill(' ') << ' ' << '\'' << setw(kWidth)
       << setfill('-') << '\'' << setw(kWidth) << '\'' << setw(kWidth) << '\''
       << endl;
    os << endl;
    curr = curr->next;
  }
  return os;
}

std::string Center(const std::string& str, decltype(str.length()) col_width) {
  // quick and easy (but error-prone) implementation
  decltype(str.length()) padl = (col_width - str.length()) / 2;
  decltype(str.length()) padr = (col_width - str.length()) - padl;
  string strf = string(padl, ' ') + str + string(padr, ' ');
  return strf;
}