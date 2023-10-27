#include <iostream>
#include <fstream>
#include <map>
using namespace std;

#define uint unsigned int

class Date
{
    private:
        uint day;
        uint month;
        uint year;
    public:
        Date(uint day, uint month, uint year) : day{day}, month{month}, year{year} {}
};

class Good
{
    private:
        string name;
        uint amount;
        double price;
        Date date;
    public:
        Good(string name, uint amount, double price, Date date) : name{name}, amount{amount}, price{price}, date{date} {}
        Good() : Good("", 0, 0, Date(1,1,1)) {}
        uint GetAmount() const
        {
            return amount;
        }
        double GetPrice() const
        {
            return price;
        }
};

int main()
{
    ifstream input;
    input.open("input_shop.txt", ios::in);
    
    int n;
    input >> n;
    
    string name;
    uint amount;
    double price;
    uint day, month;
    uint year;
    
    map<string, Good> shop;
    
    for (int good_id=0; good_id<n; good_id++)
    {
        input >> name;
        input >> amount;
        input >> price;
        input >> day >> month >> year;
        
        shop[name] = Good(name, amount, price, Date(day,month,year));
    }
    
    input.close();
    
    double total_price = 0;
    
    Good* good;
    
    for (pair<string, Good> good_pair : shop)
    {
        good = &(good_pair.second);
        total_price += good->GetAmount() * good->GetPrice();
    }
    
    ofstream output;
    output.open("output_shop.txt", ios::out);
    output << total_price << endl;
    output.close();
}
