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
		void setAmount(uint32_t value)
		{
			amount = value;
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
		
		double buy(string goodName, uint32_t amount)
		{
			map<string, Good>::iterator f = data.find(goodName);
			if (f != data.end())
			{
				Good* g = &(f->second);
				
				amount = min(amount, g->getAmount());
				g->setAmount(g->getAmount() - amount);
				double total = amount * g->getPrice();
				if (g->getAmount() == 0)
				{
					data.erase(f);
				}
				return total;
			}
			return 0;
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
	
	input.open("input_buy.txt", ios::in);
	
	double totalPrice = 0;
	input >> goodsAmount;
	for (int goodId=0; goodId < goodsAmount; goodId++)
	{
		string name;
		uint32_t amount;
		input >> name >> amount;
		totalPrice += shop.buy(name, amount);
	}
	input.close();
	
	ofstream output;
	output.open("output_buy.txt", ios::out);
	output << totalPrice << endl;
	output.close();
	
}