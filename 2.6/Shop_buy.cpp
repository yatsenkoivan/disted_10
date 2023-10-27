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
        double Buy(uint amount_to_buy)
        {
            amount_to_buy = min(amount_to_buy, amount);
            amount -= amount_to_buy;
            return amount_to_buy * price;
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
    
    input.open("input_buy.txt", ios::in);
    
    double total_price=0;
    
    input >> n;
    for (int good_id=0; good_id<n; good_id++)
    {
        input >> name;
        input >> amount;
        
        total_price += shop[name].Buy(amount);
        
    }
    
    input.close();
    
    ofstream output;
    output.open("output_buy.txt", ios::out);
    output << total_price << endl;
    output.close();
    
}
