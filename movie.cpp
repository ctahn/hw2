#include <sstream>
#include <iomanip>
#include "movie.h"


using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string rating, const std::string genre) :
    Product(category, name, price, qty)
  {
    rating_=rating; genre_= genre;
  }


Movie::~Movie()
{

}

std::set<std::string> Movie::keywords() const
{
  std::set<std::string> words = parseStringToWords(getName() + " " + genre_);
  return words;
}



std::string Movie::displayString() const
{
  std::stringstream stream;
  stream << std::fixed << std::setprecision(2) << price_;
  std::string s = stream.str();
  return name_ + '\n' + "Genre: " + genre_ + " Rating: " + rating_ + '\n' + s + " " + std::to_string(qty_) + " left.";
}

void Movie::dump(std::ostream& os) const
{
  os << category_ << std::endl;
  os << name_ << std::endl;
  os << price_ << std::endl;
  os << qty_ << std::endl;
  os << genre_ << std::endl;
  os << rating_ << std::endl; 
}
