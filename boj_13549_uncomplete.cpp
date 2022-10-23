// 숨바꼭질 3
// 처음엔 dp로 풀었는데 알고리즘 분류 보니깐
// 다익스트라로 푸는 게 맞는 듯.

#include <iostream>
#include <queue>

#define INF 2147483640

using namespace std;

int N, K;

int dijkstra(int org, int dst)
{
    int confirmed[200001];
    int D[200001];

    fill(D, D + dst * 2, INF);
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, N));

    while(pq.size() != 0)
    {
        pair<int, int> node = pq.top();
        pq.pop();
        
        int nextnode1 = node.second - 1;
        int nextnode2 = node.second + 1;
        int nextnode3 = node.second * 2;


    }
    
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> K;

}