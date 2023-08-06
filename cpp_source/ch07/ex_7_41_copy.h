#include <iostream>
#include <string>
using namespace std;
class Sales_data {
    friend std::istream &read(istream &is, Sales_data &item);
    friend std::ostream &print(ostream &os, const Sales_data &item);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
public:

};