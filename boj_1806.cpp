#include <iostream>


#define INF -2
using namespace std;


int N, S;
int arr[100001];

int sum[100001];
int cache[100001];

// 0 ~ n 까지의 원소 n을 포함하는 최소 부분합 시작 인덱스
int dp(int n)
{ 
    if(sum[n] < S)
        return INF;
    if(cache[n] != -1)
        return cache[n];

    int s = dp(n-1);
    if(s == INF)
        return cache[n] = 0;
    if(arr[n] >= S)
        return n;
    while((s > 0 ? sum[n] - sum[s-1] : sum[n]) >= S)
       s++;
    
    return cache[n] =  s - 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N >> S;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        sum[i] = i != 0 ? sum[i-1] + arr[i] : arr[i];
    }
    fill(cache, cache+100001, -1);

    int ans = 100001;

    int mini = -1;
    for(int i = 0; i<N; i++)
        if(dp(i) != INF && (mini == -1  || (i - dp(i) + 1) <= mini - dp(mini) + 1))
            mini = i;

    // cout << mini << endl;
    if(mini != -1 && dp(mini) != INF)
        cout << mini - dp(mini) + 1;
    else
        cout << 0;
    
    
}