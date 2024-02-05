#include <sstream>
#include <iomanip>
#include "clothing.h"


using namespace std;


Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand) :
    Product(category, name, price, qty)
  {
    size_=size; brand_= brand;
  }


Clothing::~Clothing()
{
  
}

std::set<std::string> Clothing::keywords() const
{
  std::set<std::string> words = parseStringToWords(getName() + " " + brand_);
  return words;
}



std::string Clothing::displayString() const
{
  std::stringstream stream;
  stream << std::fixed << std::setprecision(2) << price_;
  std::string s = stream.str();
  return name_ + '\n' + "Size: " + size_ + " Brand: " + brand_ + '\n' + s + " " + std::to_string(qty_) + " left.";
}

void Clothing::dump(std::ostream& os) const
{
  os << category_ << std::endl;
  os << name_ << std::endl;
  os << price_ << std::endl;
  os << qty_ << std::endl;
  os << size_ << std::endl;
  os << brand_ << std::endl; 
}
