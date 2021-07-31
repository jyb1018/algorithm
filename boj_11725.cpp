#include <iostream>
#include <vector>

#define ROOT 1

using namespace std;

vector<vector<int>> v(100001);
int parent[100001];
int isVisited[100001];

void dfs(int n, int prev)
{
    if(isVisited[n])
        return;
    isVisited[n] = 1;

    parent[n] = prev;
    vector<int>& vv = v[n];
    for(int i = 0; i<vv.size(); i++)
        dfs(vv[i], n);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for(int i = 0; i<N; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    dfs(ROOT, 0);
    for(int i = 2; i<=N; i++)
        cout << parent[i] << "\n";
    


}