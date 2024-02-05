#ifndef USER_H
#define USER_H
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "product.h"

/**
 * Implements User functionality and information storage
 *  You should not need to derive anything from User at this time
 */
class User {
public:
    User();
    User(std::string name, double balance, int type);
    virtual ~User();

    double getBalance() const;
    std::string getName() const;
    void deductAmount(double amt);
    void dump(std::ostream& os);
    std::vector<Product*>* getCart();
    void changeCart(std::vector<Product*>* new_cart);

protected:
    std::string name_;
    double balance_;
    int type_;
    std::vector<Product*> cart;
};
#endif
