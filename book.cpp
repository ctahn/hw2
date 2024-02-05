#include <sstream>
#include <iomanip>
#include "book.h"



using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, const std::string author, const std::string ISBN) :
    Product(category, name, price, qty)
  {
    ISBN_=ISBN; author_= author;
  }


Book::~Book()
{
}

std::set<std::string> Book::keywords() const
{
  std::set<std::string> words = parseStringToWords(getName() + " " + ISBN_ + " " + author_);
  return words;
}



std::string Book::displayString() const
{
  std::stringstream stream;
  stream << std::fixed << std::setprecision(2) << price_;
  std::string s = stream.str();
  return name_ + '\n' + "Author: " + author_ + " ISBN: " + ISBN_ + '\n' + s + " " + std::to_string(qty_) + " left.";
}

void Book::dump(std::ostream& os) const
{
  os << category_ << std::endl;
  os << name_ << std::endl;
  os << price_ << std::endl;
  os << qty_ << std::endl;
  os << ISBN_ << std::endl;
  os << author_ << std::endl; 
}

