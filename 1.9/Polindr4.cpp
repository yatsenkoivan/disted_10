#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<char> arr = {' ','+','-','!','@','#','$','%','^','&','?','*','(',')','/','[',']','{','}','<','>'};
    
    string input;
    getline(cin,input);
    
    string s = "";
    for (int i=0; i<input.length(); i++)
    {
        if (arr.find(input[i]) == arr.end()) s+=input[i];
    }
    
    bool res = true;
    for (int i=0; i<s.length()/2 && res; i++)
    {
        if (s[i] != s[s.length()-1-i])
            res = false;
    }
    cout << (res ? "TRUE" : "FALSE") << endl;
}
