#include <iostream>
#include <fstream>
#include <map>
using namespace std;

class Date
{
	private:
		uint32_t day;
		uint32_t month;
		uint32_t year;
	public:
		Date(uint32_t d, uint32_t m, uint32_t y)
			: day{d}, month{m}, year{y} {}

		Date() : Date(1,1,1) {}

		friend istream& operator>>(istream& in, Date& date)
		{
			in >> date.day >> date.month >> date.year;
			return in;
		}
		
};

class Good
{
	private:
		string name;
		uint32_t amount;
		double price;
		Date date;
	public:
		Good(string name, uint32_t amount, double price, Date date)
			: name{name}, amount{1}, price{1}, date{date} {}
		Good() : Good{"", 1, 1, Date()} {}
		
		friend istream& operator>>(istream& in, Good& g)
		{
			in >> g.name >> g.amount >> g.price >> g.date;
			
			if (g.amount <= 0) g.amount = 1;
			if (g.price <= 0) g.price = 1;
			
			return in;
		}
		
		string getName() const
		{
			return name;
		}
		uint32_t getAmount() const
		{
			return amount;
		}
		double getPrice() const
		{
			return price;
		}
		
};

class Shop
{
	private:
		map<string, Good> data;
		double totalPrice;
	public:
		Shop() : totalPrice{0} {}
		void operator+=(Good& g)
		{
			data[g.getName()] = g;
			totalPrice += g.getAmount() * g.getPrice();
		}
		
		double getTotalPrice() const
		{
			return totalPrice;
		}
		
};


int main()
{
	ifstream input;
	input.open("input_shop.txt", ios::in);
	
	Shop shop;
	
	int goodsAmount;
	input >> goodsAmount;
	
	for (int goodId=0; goodId < goodsAmount; goodId++)
	{
		Good g;
		input >> g;
		shop += g;
	}
	
	input.close();
	
	ofstream output;
	output.open("output_shop.txt", ios::out);
	
	output << shop.getTotalPrice() << endl;
	
	output.close();
	
}