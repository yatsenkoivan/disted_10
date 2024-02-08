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
    int temp;
    int white_total = 0;
    int black_total = 0;
    int total = s.length();
    
    int i = 0;
    while (white_total + black_total < total)
    {
        color = s[i];
        temp = 0;
        for (; s[i] == color; i++)
        {
            temp++;
        }
        
        if (color == 'w')
        {
            Hanoi(white_total, white, base, work);
            white_total += temp;
            Hanoi(white_total, base, white, work);
        }
        else if (color == 'b')
        {
            Hanoi(black_total, black, base, work);
            black_total += temp;
            Hanoi(black_total, base, black, work);
        }
        
    }
}

int main()
{
    string s;
    cin >> s;
    VinTowers(s);
}
