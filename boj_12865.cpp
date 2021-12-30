#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> things;

int N, K;

int dp[100001][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);


    cin >> N >> K;

    things.push_back(make_pair(0,0));
    for (int i = 0; i < N; i++)
    {
        int price, weight;
        cin >> weight >> price;
        things.push_back(make_pair(weight, price));
    }



    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= K; j++)
        {
            dp[j][i] = j - things[i].first >= 0 ?  max(dp[j][i-1], dp[j - things[i].first][i-1] + things[i].second) : dp[j][i-1];
            // cout << "dp[" << j << "][" << i << "] : " << dp[j][i] << endl;
        }
        
    cout << dp[K][N];
        
    
    
    
}