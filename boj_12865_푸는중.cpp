#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

int N, K;
vector<pair<int,int>> WV;

int knapsack(int idx, int w_left)
{
    if(idx == N-1)
        return WV[idx].second;
    
    int ret = 0;
    for(int i = idx + 1; i<N; i++)
        if(w_left - WV[i].first >= 0)
            ret = max(ret, knapsack(i, w_left - WV[i].first));
    return ret + WV[idx].second;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    for(int i = 0; i<N; i++)
    {
        int a, b;
        cin >> a >> b;
        WV.push_back(make_pair(a,b));
    }

    sort(WV.begin(), WV.end());

    cout << knapsack(-1, K);
    

}