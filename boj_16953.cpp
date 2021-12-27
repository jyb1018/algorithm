#include <iostream>

#define INF 2147483647

using namespace std;



int func(long long origin, long long dest, int depth)
{
    if(origin > dest)
        return INF;
    else if(origin == dest)
        return depth+1;
    
    int f1 = func(origin * 2, dest, depth+1);
    int f2 = func(origin * 10ll + 1ll, dest,  depth + 1);
    
    return min(f1, f2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    long long A, B;
    cin >> A >> B;

    int ans = func(A, B, 0);
    ans == INF ? cout << -1 : cout << ans;

}