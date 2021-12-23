
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;



int N, V;
//가정 : 가중치(비용)은 항상 1 이상이다.
int node[100][100];

int main()
{
    cin >> N >> V;
    int start, end;
    cin >> start >> end;
    
    for(int i = 0; i<N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        node[a][b] = c;
        node[b][a] = c;
    }

    
    //<비용, 노드>
    priority_queue<pair<int,int>> open;
    int cost[100];
    
    queue<int> closed;

    open.push(make_pair(0,start));

    while(open.size())
    {
        pair<int,int> n = open.front();
        open.pop();

        for(int i = 0; i<N; i++)
            if(node[n.second][i] && !cost[i])
            {
                cost[i] = node[n.second][i] + cost[n.second];
                open.push(make_pair(cost[i], i));
                
            }
            else if(cost[i])
            {
                for(iterator<priority_queue<pair<int,int>> it = open.begin(); it < open.end(); it++)
                    if(it->second == i)
                    {
                        it->first = min(cost[i], it->first);
                        break;
                    }
            }
    }
    
    
}