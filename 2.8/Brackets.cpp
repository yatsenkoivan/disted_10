#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<char> brackets;
    string s;
    cin >> s;
    bool flag = 1;
    for (int i=0; i<s.size() && flag; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            brackets.push(s[i]);
            continue;
        }
        if (brackets.empty())
        {
            flag = 0;
            break;
        }
        if ((s[i] == ')' && brackets.top() == '(')
         || (s[i] == ']' && brackets.top() == '[')
         || (s[i] == '}' && brackets.top() == '{'))
        {
            brackets.pop();
        }
        else
        {
            flag = 0;
        }
    }
    if (!brackets.empty()) flag = 0;
    cout << (flag ? "TRUE" : "FALSE") << endl;
}
