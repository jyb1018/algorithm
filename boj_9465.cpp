#include <iostream>

using namespace std;

int n;

int score[2][100000];
int cache[2][100000];

// idx열 updown행을 선택하고 그 이후의 것들 선택한 결과값 반환 
// updown : 0 up 1 down
int func(int updown, int idx)
{
    //기저 out of bounds
    if(idx >= n)
        return 0;
        
    //memoization
    int& ret = cache[updown][idx];
    if(ret != -1)
        return ret;

    ret = score[updown][idx];
    int next = func(!updown, idx + 1);
    int nextnext = max(func(0, idx + 2), func(1, idx + 2));
    
    ret += max(next, nextnext);
    return ret;
}

int func()
{
    return max(func(0, 0), func(1, 0));
}

int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T-->0)
    {
        fill(&cache[0][0], &cache[1][99999], -1);
        cin >> n;
        for(int i = 0; i<2; i++)
            for(int j = 0; j<n; j++)
                cin >> score[i][j];
        cout << func() << "\n";
    }
    
}