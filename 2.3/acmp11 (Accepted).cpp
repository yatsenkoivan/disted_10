#include <iostream>
#include <vector>

typedef unsigned char _byte;

struct Digit
{
	const _byte value;
	Digit* prev;
	Digit* next;
	Digit(_byte value) : value{value}
	{
		prev = nullptr;
		next = nullptr;
	}
	Digit() : Digit(0) {}
	~Digit()
	{
		delete next;
	}
	friend std::ostream& operator<<(std::ostream& out, const Digit& d)
	{
		out << (short)(d.value);
		return out;
	}
	
};

class Integer
{
	private:
		Digit* head;
		Digit* tail;
	public:
		bool negative;
		Integer() : Integer(0)
		{}
		Integer(const Integer& num)
		{
			head = nullptr;
			tail = nullptr;
			(*this) = num;
		}
		Integer(long long num)
		{
			head = nullptr;
			tail = nullptr;
			(*this) = num;
		}
		Integer(std::string num)
		{
			head = nullptr;
			tail = nullptr;
			(*this) = num;
		}
		Integer(bool negative, Digit* head, Digit* tail) : negative{negative}, head{head}, tail{tail} {}
		~Integer()
		{
			delete head;
		}
		
		void operator=(const Integer& num)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			negative = num.negative;
			Digit* current=num.head;
			Digit* newdigit;
			Digit* prev = nullptr;
			while (current)
			{
				newdigit = new Digit(current->value);
				if (head == nullptr) head = newdigit;
				newdigit->prev = prev;
				if (prev) prev->next = newdigit;
				prev = newdigit;
				current = current->next;
			}
			tail = newdigit;
		}
		
		void operator=(long long num)
		{
			delete head;
			negative = 0;
			if (num == 0)
			{
				head = new Digit(0);
				tail = head;
				return;
			}
			head = nullptr;
			tail = nullptr;
			if (num < 0) negative = 1;
			num = abs(num);
			
			Digit* current;
			Digit* next = nullptr;
			
			while (num > 0)
			{
				current = new Digit(num%10);
				if (tail == nullptr) tail = current;
				current->next = next;
				if (next) next->prev = current;
				next = current;
				num /= 10;
			}
			
			head = current;
		}
		
		void operator=(std::string num)
		{
			delete head;
			negative = 0;
			if (num == "")
			{
				head = new Digit(0);
				tail = head;
				return;
			}
			int i = 0;
			if (num[0] == '-')
			{
				negative = 1;
				i++;
			}
			head = nullptr;
			tail = nullptr;
			Digit* current;
			Digit* prev = nullptr;
			for (;i<num.size(); i++)
			{
				if (num[i] == '0' && head == nullptr) continue;
				if (num[i] >= '0' && num[i] <= '9')
				{
					current = new Digit(num[i]-'0');
					if (head == nullptr) head = current;
					current->prev = prev;
					if (prev) prev->next = current;
					prev = current;
				}
				else
				{
					break;
				}
			}
			
			if (head == nullptr)
			{
				negative = 0;
				head = new Digit(0);
				tail = head;
				return;
			}
			tail = current;
		}
		
		Integer operator+(const Integer& num)
		{
			if (this->negative != num.negative)
			{
				Integer b(num);
				b.negative = !b.negative;
				return (*this)-b;
			}
			
			Digit* res_tail = nullptr;
			Digit* res_head = nullptr;
			
			Digit* current;
			Digit* next = nullptr;
			
			Digit* a = this->tail;
			Digit* b = num.tail;
			
			_byte val1, val2, val;
			_byte add = 0;
			
			while (a || b)
			{
				val1 = 0;
				val2 = 0;
				if (a)
				{
					val1 = a->value;
					a = a->prev;
				}
				if (b)
				{
					val2 = b->value;
					b = b->prev;
				}
				
				val = val1+val2+add;
				add = val/10;
				val %= 10;
				
				current = new Digit(val);
				if (res_tail == nullptr) res_tail = current;
				current->next = next;
				if (next) next->prev = current;
				next = current;
				
			}
			
			if (add)
			{
				current = new Digit(add);
				add = 0;
				if (res_tail == nullptr) res_tail = current;
				current->next = next;
				if (next) next->prev = current;
				next = current;
			}
			
			res_head = current;
			
			bool res_negative = 0;
			if (this->negative) res_negative = 1;
			
			Integer res(res_negative, res_head, res_tail);
			
			return res;
			
		}
		
		Integer operator+(long long value)
		{
			Integer num(value);
			return (*this)+num;
		}
		friend Integer operator+(long long value, Integer& num)
		{
			return num+value;
		}
		
		Integer operator-(Integer& num)
		{
			
			if (this->negative != num.negative)
			{
				Integer b(num);
				b.negative = !b.negative;
				return (*this)+b;
			}
			
			Digit* a = this->tail;
			Digit* b = num.tail;
			
			bool res_negative=0;
			bool values_negative = 0;
			if (num.negative) values_negative = 1;
			num.negative = 0;
			this->negative = 0;
			
			if ((*this) < num)
			{
				std::swap(a,b);
				if (!values_negative) res_negative = 1;
			}
			
			Digit* res_head = nullptr;
			Digit* res_tail = nullptr;
			
			Digit* current;
			Digit* next = nullptr;
			
			_byte val1, val2;
			char val;
			_byte rem=0;
			while (a || b)
			{
				val1 = 0;
				val2 = 0;
				if (a)
				{
					val1 = a->value;
					a = a->prev;
				}
				if (b)
				{
					val2 = b->value;
					b = b->prev;
				}
				
				val = val1-val2-rem;
				rem=0;
				if (val<0)
				{
					val+=10;
					rem=1;
				}
				
				current = new Digit(val);
				if (res_tail == nullptr) res_tail = current;
				current->next = next;
				if (next) next->prev = current;
				next = current;
				
			}
			
			res_head = current;
			
			if (values_negative)
			{
				num.negative = 1;
				this->negative = 1;
			}
			
			//delete leading zeros
			if (res_head != res_tail)
			{
				current = res_head;
				while (current->value == 0)
				{
					next = current->next;
					current->next = nullptr;
					delete current;
					current = next;
					res_head = current;
				}
			}
			
			
			Integer res(res_negative, res_head, res_tail);
			return res;
			
		}
		
		bool operator<(const Integer& num)
		{
			if (this->negative && !num.negative) return 1;
			if (!this->negative && num.negative) return 0;
			
			bool both_negative = 0;
			if (this->negative) both_negative = 1;
			
			bool checked=0;
			bool res = 0;
			Digit* a = this->head;
			Digit* b = num.head;
			while (a && b)
			{
				if (!checked)
				{
					if (a->value < b->value)
					{
						if (!both_negative) res = 1;
						checked = 1;
					}
					if (a->value > b->value)
					{
						if (both_negative) res = 1;
						checked = 1;
					}
				}
				
				a = a->next;
				b = b->next;
			}
			
			if (!a && !b) return res;
			
			if (!a)
			{
				if (!both_negative) res = 1;
				else res = 0;
			}
			if (!b)
			{
				if (both_negative) res = 1;
				else res = 0;
			}
			
			return res;
		}
		
		Integer operator-(long long value)
		{
			Integer num(value);
			return (*this)-num;
		}
		
		friend Integer operator-(long long value, Integer& num)
		{
			return num-value;
		}
		
		friend std::ostream& operator<<(std::ostream& out, const Integer& num)
		{
			if (num.negative) out << '-';
			Digit* current = num.head;
			while (current)
			{
				out << *current;
				current = current->next;
			}
			return out;
		}
		friend std::istream& operator>>(std::istream& in, Integer& num)
		{
			std::string input;
			in >> input;
			num = input;
			return in;
		}
};

using namespace std;
int main()
{
	int k, n;
	cin >> k >> n;
	vector<Integer> arr(n);
	arr[0] = 1;
	Integer s = arr[0];
	
	for (int i=1; i<k; i++)
	{
		arr[i] = s+1;
		s = s+arr[i];
	}
	
	for (int i=k; i<n; i++)
	{
		arr[i] = s;
		s = s-arr[i-k];
		s = s+arr[i];
		//cout << arr[i-k] << ' ' << arr[i] << ' ' << s << endl;
	}
	
	cout << arr[n-1] << endl;
	
}

