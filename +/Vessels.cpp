#include <iostream>
#include <list>
#include <forward_list>
using namespace std;

struct Node
{
    int value;
    
    Node* left_add;
    Node* right_add;
    Node* left_sub;
    Node* right_sub;
    Node* parent;
    
    Node(int value, Node* parent=nullptr) : value{value}, parent{parent}
    {
        left_add = nullptr; // + a
        right_add = nullptr; // + b
        left_sub = nullptr; // - a
        right_sub = nullptr; // - b
    }
    
};

void showNode(Node* n)
{
    forward_list<int> output;
    int total=0; //root included
    while (n != nullptr)
    {
        output.push_front(n->value);
        n = n->parent;
        total++;
    }
    
    cout << total-1 << endl;
    for (int i : output)
    {
        cout << i << ' ';
    }
    cout << endl;
    
}

int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    
    list<Node*> S;
    bool checked[n+1]{};
    
    Node* newNode;
    Node* node;
    
    S.push_front(new Node(0));
    checked[0] = 1;
    
    while (true)
    {
        for (list<Node*>::iterator i = S.begin(); i != S.end();)
        {
        	node = *i;
            if (node->value == n)
            {
                showNode(node);
                return 0;
            }
            
            if (node->value + a <= n && checked[node->value+a] == 0)
            {
                checked[node->value + a] = 1;
                newNode = new Node(node->value+a, node);
                node->left_add = newNode;
                S.push_front(newNode);
            }
            if (node->value + b <= n && checked[node->value+b] == 0)
            {
                checked[node->value + b] = 1;
                newNode = new Node(node->value+b, node);
                node->right_add = newNode;
                S.push_front(newNode);
            }
            
            if (node->value - a >= 0 && checked[node->value-a] == 0)
            {
                checked[node->value - a] = 1;
                newNode = new Node(node->value-a, node);
                node->left_sub = newNode;
                S.push_front(newNode);
            }
            if (node->value - b >= 0 && checked[node->value-b] == 0)
            {
                checked[node->value - b] = 1;
                newNode = new Node(node->value-b, node);
                node->right_sub = newNode;
                S.push_front(newNode);
            }
            
            list<Node*>::iterator j = next(i);
            S.erase(i);
            i = j;
        }
        if (S.empty())
        {
            cout << -1 << endl;
            break;
        }
    }
}
