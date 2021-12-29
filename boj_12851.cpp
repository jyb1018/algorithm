#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int N, K;

int isVisited[100001];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N >> K;
    
    queue<pair<int, int>> q;
    q.push(make_pair(N, 0));
    int ans1 = 0, ans2 = 0;
    while(q.size() != 0)
    {
        int pos = q.front().first;
        int dep = q.front().second;
        q.pop();
        
        if(pos > 100000)
            continue;

        isVisited[pos] = 1;

        if(ans2 != 0 && dep > ans1)
            break;

        if(pos == K && (ans1 == 0 || ans1 == dep))
        {
            ans1 = dep;
            ans2++;
        }

        if(pos > 0 && isVisited[pos-1] == 0)
            q.push(make_pair(pos-1, dep + 1));
        if(pos < 100001 && isVisited[pos+1] == 0)
            q.push(make_pair(pos+1, dep + 1));
        q.push(make_pair(pos*2, dep + 1));
    }
    
    cout << ans1 << "\n" << ans2;

}