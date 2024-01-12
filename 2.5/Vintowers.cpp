#include <iostream>
using namespace std;

void Hanoi(int n, int from, int to, int help)
{
    if (n == 0) return;
    
    Hanoi(n-1, from, help, to);
    cout << from << "=>" << to << endl;
    Hanoi(n-1, help, to, from);
}

void VinTowers(const string& s)
{
    const int base=1;
    const int work=2;
    const int white=3;
    const int black=4;
    
    char color;
    int temp_amount;
    int white_amount = 0;
    int black_amount = 0;
    int total_amount = s.length();
    
    int i = 0;
    while (white_amount + black_amount < total_amount)
    {
        color = s[i];
        temp_amount = 0;
        for (; s[i]==color; i++)
        {
            temp_amount++;
        }
        
        if (color == 'w')
        {
            Hanoi(white_amount, white, base, work);
            white_amount += temp_amount;
            Hanoi(white_amount, base, white, work);
        }
        else if (color == 'b')
        {
            Hanoi(black_amount, black, base, work);
            black_amount += temp_amount;
            Hanoi(black_amount, base, black, work);
        }
        
    }
}

int main()
{
    string s;
    cin >> s;
    VinTowers(s);
}
