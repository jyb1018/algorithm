#include <iostream>
#include <cstdlib>
#include <queue>

#define SIZE 1001
#define INF 2147483647

using namespace std;

//city, bus
int N, M;

vector<pair<int, int>> node[SIZE];

int dijkstra(int s, int d)
{
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0, s));

    int D[SIZE];
    fill(D, D+SIZE, INF);

    D[s] = 0;
    
    while(pq.size() != 0)
    {
        int tempcost = -pq.top().first;
        int tempnode = pq.top().second;

        if(tempnode == d)
            break;
        pq.pop();

        for (int i = 0; i < node[tempnode].size(); i++)
        {
            if(D[node[tempnode][i].first] > tempcost + node[tempnode][i].second)
            {
                D[node[tempnode][i].first] = tempcost + node[tempnode][i].second;
                pq.push(make_pair(-D[node[tempnode][i].first], node[tempnode][i].first));
            }

        }
        
        
    }

    return D[d];
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int  i = 0; i < M; i++)
    {
        int start, dest, cost;
        cin >> start >> dest >> cost;
        node[start].push_back(make_pair(dest, cost));
    }
    int t_start, t_dest;
    cin >> t_start >> t_dest;

    cout << dijkstra(t_start, t_dest);
    
    
    

}