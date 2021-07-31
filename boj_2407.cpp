#include <iostream>
#include <cmath>

#define ZERO '0'

using namespace std;

string s[101][101];

string operator+(string a, string b)
{
    string ret = "";
    string temp = "";
    for(int i = 0; i < a.size() - b.size(); i++)
        temp = temp.append("0");
    b = temp.append(b);
    int prev = 0;
    
    for(int i = b.size()-1; i>=0; i--)
    {
        int sum = a[i] - ZERO + b[i] - ZERO + prev;
        ret = char((sum % 10) + ZERO) + ret;
        prev = sum / 10;
    }

    if(prev)
        ret = char(prev + ZERO) + ret;

    return ret;
    
}

string comb_big(int n, int m)
{
    if(n < m)
        return 0;
    if(n == 1 || m == 0 || m == n)
        return "1";
    string& ret = s[n][m];
    if(ret != "")
        return ret;

    string ret1 = comb_big(n-1, m-1);
    string ret2 = comb_big(n-1, m);
    return ret = ret1.size() >= ret2.size() ? ret1 + ret2 : ret2 + ret1;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    fill(&s[0][0], &s[100][100], "");
    cout << comb_big(n,m);
    
}