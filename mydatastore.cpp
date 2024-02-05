#include <string>
#include <set>
#include <vector>
#include "mydatastore.h"
using namespace std;

MyDataStore::MyDataStore()
{
  std::vector<User*> users;
  users_ = users;
  std::vector<Product*> products;
  products_ = products;
}



MyDataStore::~MyDataStore()
{
  for(std::vector<User*>::iterator it = users_.begin(); it != users_.end(); ++it){
    delete *it;
  }

  for(std::vector<Product*>::iterator it = products_.begin(); it != products_.end(); ++it){
    delete *it;
  }
}

    
void MyDataStore::addProduct(Product* p)
{
  products_.push_back(p);
}

/**
  * Adds a user to the data store
  */
void MyDataStore::addUser(User* u)
{
  users_.push_back(u);
}

/**
  * Performs a search of products whose keywords match the given "terms"
  *  type 0 = AND search (intersection of results for each term) while
  *  type 1 = OR search (union of results for each term)
  */
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
  std::vector<Product*> prod;
  if(type == 1){
    for(std::vector<Product*>::iterator count=products_.begin(); count != products_.end(); ++count){
      std::set<std::string> term(terms.begin(), terms.end());
      std::set<std::string> words = (*count)->keywords();
      std::set<std::string> object;
      
      object = setIntersection(term, words);
      if(!(object.empty())){
        prod.push_back((*count));
      }
      
    }
  }
  else{
    for(std::vector<Product*>::iterator count=products_.begin(); count != products_.end(); ++count){
      std::set<std::string> term(terms.begin(), terms.end());
      std::set<std::string> words = (*count)->keywords();
      std::set<std::string> object;
      object = setIntersection(term, words);
      if(object.size() == terms.size()){
        prod.push_back((*count));
      }
    }
  } 
  return prod;
}

/**
  * Reproduce the database file from the current Products and User values
  */
void MyDataStore::dump(std::ostream& ofile)
{
  ofile << "<products>" << endl;
  for(std::vector<Product*>::iterator it=products_.begin(); it!=products_.end(); ++it){
    (*it)->dump(ofile);
  }
  ofile << "</products>" << endl;
  ofile << "<users>" << endl;
  for(std::vector<User*>::iterator it=users_.begin(); it!=users_.end(); ++it){
    (*it)->dump(ofile);
  }
  ofile << "</users>" << endl;
}


vector<User*>* MyDataStore::getUsers(){
  return &users_;
};


