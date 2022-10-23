// 길을 없애면서 최소 비용 Spanning Tree를 만들 것 MCST
// 단, MCST는 총 두 개가 나와야 함. -> Union-find 이용?
// kruskal 활용하는 알고리즘일듯
// O(MlogN) 혹은 O(NlogM) 안에 해결해야 함
// 아마 kruskal 이니까 최소 O(M)
// 근데 그리디하게 MST를 먼저 만들고, 제일 비용 큰 엣지를 없애면 MST 두개가 되잖음.
// 대신 U-F를 최적화 없이 사용해야할듯. -> O(N), 아마 시간초과나면 최적화 고려해야할듯

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// N 노드, M 엣지
// N <= 10e+5 M <= 10e+6
int N, M;

// 비용, 노드1, 노드2
vector<pair<int, pair<int, int>>> v;

int parent_node[100001];


// 반대편 엣지를 어떻게 찾지?
bool canRemoveEdge(int org, int dst)
{
    
}

int union_find(int n)
{
    if(parent_node[n] == 0)
        return n;
    else
        return union_find(n);
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int org, dst, capacity;
        cin >> org >> dst >> capacity;
        v.push_back(make_pair(capacity, make_pair(min(org, dst), max(org, dst))));
        
    }
    sort(v.begin(), v.end());

    // parent 정보 
    for (int i = 0; i < M; i++)
    {
        pair<int, int>& node = v[i].second;
        parent_node[node.second] = node.first;

    }

    for (int i = 0; i < M; i++)
    {
        
    }
    
    
    
    
     
}