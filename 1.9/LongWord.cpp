#include <iostream>
#include <vector>
using namespace std;

vector<string> split(const string& s)
{
    vector<string> arr;
    
    string word = "";
    for (int i=0; i<s.size(); i++)
    {
        if (s[i] == ' ')
        {
            if (word != "") arr.push_back(word);
            word = "";
        }
        else
            word += s[i];
    }
    
    if (word != "")
        arr.push_back(word);
        
    return arr;
}

int main()
{
    string s;
    getline(cin, s);
    
    vector<string> words = split(s);

    
    int current_len = 0;
    int current_idx = 0;
    for (int i=0; i<words.size(); i++)
    {
        if (words[i].length() > current_len)
        {
            current_len = words[i].length();
            current_idx = i+1;
        }
    }
    cout << current_len << ' ' << current_idx << endl;
}
