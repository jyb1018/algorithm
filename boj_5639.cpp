#include <iostream>
#include <vector>

using namespace std;

pair<int, int> bi_node[1000001];
int parent[1000001];


void postorder(int n)
{
    if(n == 0)
        return;
    postorder(bi_node[n].first);
    postorder(bi_node[n].second);
    cout << n << "\n";
}


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("input.txt", "r", stdin);

    int t;
    vector<int> v;
    while(cin >> t) v.push_back(t);



    for(int i = 1; i<v.size(); i++)
    {
        int p = v[0];
        int n = v[i];

        while((n < p && bi_node[p].first != 0) || (n > p && bi_node[p].second != 0))
            p = n < p ? bi_node[p].first : bi_node[p].second; 
        
        parent[n] = p;
        n < p ? bi_node[p].first = n : bi_node[p].second = n;
    }

    postorder(v[0]);

}