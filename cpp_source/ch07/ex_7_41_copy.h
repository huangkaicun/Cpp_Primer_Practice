// BEGIN: 4f3c5d4fj3d9
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data {
public:
    // constructors
    Sales_data() = default;
    Sales_data(const std::string &book) : bookNo(book) {}
    Sales_data(const std::string &book, const unsigned num,
               const double sellp, const double salep);
    Sales_data(std::istream &is);

    // member functions
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);

private:
    double avg_price() const;

    std::string bookNo;
    unsigned units_sold = 0;
    double sellingprice = 0.0;
    double saleprice = 0.0;
    double discount = 0.0;
};

// nonmember Sales_data interface functions
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

#endif
// END: 4f3c5d4fj3d9#ifdef EX_7_41_COPY_H
#define EX_7_41_COPY_H 

#include <iostream>
#include <string>
using namespace std;
class Sales_data {
    friend std::istream &read(istream &is, Sales_data &item);
    friend std::ostream &print(ostream &os, const Sales_data &item);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
public:
Sales_data(const string &s, unsigned n, double p):bookNo(s), unites_sold(n), revenue(n*p)
{ cout << "Sales_data(const std::string&, unsigned, double)", endl; }

private:
//q: 为什么要在avg_price 后面加const？方法后面加const是什么意思？
//a: const成员函数，不会修改对象的内容。

//q: inline double avg_price() const; inline 是什么意思? 能否不加inline? 
//a: inline是内联函数，编译器会在调用处展开函数体，而不是跳转到函数体的地方执行。inline只是对编译器的建议，编译器可以选择忽略。 
inline double avg_price() const;
private:
string bookNo;
unsigned unites_sold = 0;
double revenue = 0.0;

};
inline
double Sales_data::avg_price() const
{
    return unites_sold ? revenue/unites_sold : 0;
}


//declearations for nonmember parts of the Sales_data interface.
istream &read(istream &is, Sales_data &item);
istream &print(istream &os, const Sales_data &item);
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
#endif