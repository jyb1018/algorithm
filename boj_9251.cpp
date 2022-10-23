// dp 문제?
// 점화식 세우면 이전 답 + 같은경우 하나씩 추가하는 형태 LIS 처럼?
// memoization으로는 ans(길이) 넣을 것
// + 같을 경우는 그 이후의 모든 경우를 검사하지 않아도 됨. 

#include <iostream>

using namespace std;

int cache[1001][1001];

string s1, s2;

int count = 0;


int dp(int idx1, int idx2)
{
    if(idx1 >= s1.size() || idx2 >= s2.size())
        return 0;
    int& ret =  cache[idx1][idx2];
    if(ret != -1)
        return ret;
    ret = 0;
    if(s1[idx1] == s2[idx2])
        ret = dp(idx1 + 1, idx2 + 1) + 1;
    else
        ret = max(dp(idx1 + 1, idx2), dp(idx1, idx2 + 1));
    return ret;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    fill(&cache[0][0], &cache[1000][1000], -1);
    
    string buff;
    getline(cin, buff);
    s1 = "$";
    s1 = s1.append(buff);
    getline(cin, buff);
    s2 = "$";
    s2 = s2.append(buff);
    if(buff.size() != 0)
        cout << dp(0, 0) - 1;
    else
        cout << 0;

    
}