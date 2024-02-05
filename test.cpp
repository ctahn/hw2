#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "book.h"

int main(){
  Book mybook("Book", "Data Abstraction & Problem Solving with C++", 79.99, 20, "Carrano and Henry", "978-013292372-9");
  std::set<std::string> keyword = mybook.keywords();
  mybook.displayString();
}
