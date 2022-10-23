#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int cache[1000001] = {0,};
int next_minNode[10000001] = {0,};

// 1 <= N <= 10+6e

int dp(int n)
{
    // v.push_back(n);

    // cout << n << " ";

    if(n == 1) 
        return 1;
    if(cache[n] != 0)
        return cache[n];

    int div3 = 2147483647;
    int div2 = 2147483647;
    int min1;
    if(n % 3 == 0)
        div3 = dp(n/3) + 1;
    if(n % 2 == 0)
        div2 = dp(n/2) + 1;
    min1 = dp(n-1) + 1;

    if(div3 <= div2 && div3 <= min1) 
        next_minNode[n] = n/3;
    else if(div2 <= div3 && div2 <= min1)
        next_minNode[n] = n/2;
    else
        next_minNode[n] = n-1;

    return cache[n] = min(min(div3, div2), min1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    
    cout << dp(N) - 1<< "\n";
    int node = N;
    while(node != 1) 
    {
        cout << node << " ";
        node = next_minNode[node];
    }

    cout << 1;
    
    
}