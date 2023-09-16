#include <iostream>
using namespace std;

string subtract(const string& a, const string& b)
{
    string A;
    string B;
    
    if (a > b)
    {
        A = a;
        B = b;
    }
    else
    {
        A = b;
        B = a;
    }
    
    string res="";
    int val1, val2;
    int val;
    int temp;
    
    int index_a = A.size()-1;
    int index_b = B.size()-1;
    
    while (index_a >= 0 || index_b >= 0)
    {
        val1 = 0;
        val2 = 0;
        
        if (index_a >= 0)
        {
            val1 = A[index_a]-'0';
            index_a--;
        }
        if (index_b >= 0)
        {
            val2 = B[index_b]-'0';
            index_b--;
        }
        
        val = val1-val2+temp;
        temp = 0;
        if (val < 0)
        {
            val+=10;
            temp = -1;
        }
        
        res = char(val+'0')+res;
    }
    return res;
}

string add(const string& a, const string& b)
{
    bool negative1 = false;
    bool negative2 = false;
    string res = "";
    
    if (a[0] == '-') negative1 = true;
    if (b[0] == '-') negative2 = true;
    
    string A = a.substr(negative1, a.size()-negative1);
    string B = b.substr(negative2, b.size()-negative2);
    
    if (negative1 != negative2)
    {
        res = subtract(A,B);
        if (A > B && negative1) res = '-'+res;
        if (B > A && negative2) res = '-'+res;
        return res;
    }
    
    int index_a = A.size()-1;
    int index_b = B.size()-1;
    int val1, val2;
    int val;
    int temp=0;
    while (index_a >= 0 || index_b >= 0)
    {
        val1 = 0;
        val2 = 0;
        if (index_a >= 0)
        {
            val1 = A[index_a]-'0';
            index_a--;
        }
        if (index_b >= 0)
        {
            val2 = B[index_b]-'0';
            index_b--;
        }
        
        val = val1+val2+temp;
        temp = 0;
        if (val > 9)
        {
            val -= 10;
            temp = 1;
        }
        res = char(val+'0')+res;
    }
    if (temp == 1) res = '1'+res;
    if (negative1 && negative2) res = '-'+res;
    return res;
}

int main()
{
    string a;
    string b;
    cin >> a >> b;
    
    cout << add(a,b) << endl;
}
