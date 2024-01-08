#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T value;
	Node<T>* next;
	Node<T>* prev;
	Node(T value, Node<T>* next = nullptr, Node<T>* prev = nullptr) : value{ value }, next{ next }, prev{ prev }
	{}

	friend ostream& operator<<(ostream& out, const Node<T>& node)
	{
		out << node.value;
		return out;
	}

};

template <typename T>
struct LinkedList
{
	Node<T>* begin;
	LinkedList(Node<T>* begin = nullptr) : begin{ begin }
	{}
	~LinkedList()
	{
		Node<T>* current = begin;
		Node<T>* next;
		while (current)
		{
			next = current->next;
			delete current;
			current = next;
		}
	}

	friend ostream& operator<<(ostream& out, const LinkedList<T>& _list)
	{
		Node<T>* current = _list.begin;
		while (current)
		{
			out << *current << ' ';
			current = current->next;
		}
		return out;
	}

};

int main()
{
	int n, s, k;
	cin >> n >> s >> k;

	Node<int>* head = new Node<int>(1);
	Node<int>* start = head;
	Node<int>* current = head;
	for (int i = 2; i <= n; i++)
	{
		current->next = new Node<int>(i);
		current->next->prev = current;
		current = current->next;
		if (i == s) start = current;
	}

	LinkedList<int> _list(head);

	Node<int>* next;
	//has next (after head) element (2 or more elements)
	while (_list.begin->next)
	{
		for (int i = 0; i < k - 1; i++)
		{
			start = start->next;
			if (start == nullptr) start = _list.begin;
		}

		next = start->next;
		if (next == nullptr) next = _list.begin;

		if (start == _list.begin)
		{
			start->next->prev = nullptr;
			_list.begin = start->next;
			delete start;
			start = _list.begin;
		}
		else
		{
			if (start->next == nullptr)
			{
				start->prev->next = nullptr;
				delete start;
				start = _list.begin;
			}
			else
			{
				start->prev->next = start->next;
				start->next->prev = start->prev;
				delete start;
				start = next;
			}
		}
	}

	cout << *_list.begin << endl;

}