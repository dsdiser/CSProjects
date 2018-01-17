#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

class Book{

 public:
  Book(string name, string m_author);
  void Borrow();
  void Open();
  void Close();
  void Bookmark();

 protected:
  string m_name;
  string m_author;
};

class Fiction : public Book {
 public:
  Fiction(string name, string author);
  void Open();
  void Close();
  void Borrow();
};

class NonFiction : public Book {
 public:
  NonFiction(string name, string author);
  void Open();
  void Close();
  void Borrow();
};

#endif
