#include "Book.h"

int main () {

  Book * newBook = new Book("The Hobbit", "J.R.R. Tolkien");
  Fiction fict1("The Magicians", "Lev Grossman");
  NonFiction non1("Webster's Dictionary", "Webster");

  Book * book1 = &fict1;
  Book * book2 = &non1;

  cout << "Book - The Hobbit" << endl;
  newBook->Open();
  newBook->Close();
  newBook->Borrow();
  cout << endl;

  cout << "Fiction - The Magicians" << endl;
  book1->Open();
  book1->Close();
  book1->Borrow();

  cout << endl << "NonFiction - Dictionary" << endl;
  book2->Open();
  book2->Close();
  book2->Borrow();

  return 0;
}
