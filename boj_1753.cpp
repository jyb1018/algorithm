#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>

#define mINF -2147483647
#define INF 2147483647

using namespace std;

int V, E;
vector<pair<int, int>> vp[20001];


int main()
{

    // freopen("./input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> V >> E;

    int start;
    cin >> start;

    for (int i = 0; i < E; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        vp[a].push_back(make_pair(b, w));
    }

    int D[20001];



    int isVisited[20001];
    for (int i = 0; i < V + 1; i++)
    {
        D[i] = INF;
        isVisited[i] = 0;
    }

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    D[start] = 0;

    while(pq.size() != 0)
    {
        int tempnode = pq.top().second;
        int dist = -pq.top().first;

        pq.pop();

        for (int i = 0; i < vp[tempnode].size(); i++)
        {
            int nextnode = vp[tempnode][i].first;
            int nextdist = vp[tempnode][i].second;

            if(D[nextnode] > dist + nextdist)
            {
                D[nextnode] = dist + nextdist;
                pq.push(make_pair(-D[nextnode], nextnode));
            }   
        }
        

        
    }


    for (int i = 1; i <= V; i++)
    {
        D[i] != INF ? cout << D[i] << "\n" : cout << "INF\n";
    }
}