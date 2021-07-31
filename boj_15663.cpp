#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int N, M;

int input[10001];

vector<int> v;

void printst(stack<int> st)
{
    stack<int> stst;
    while(st.size() != 0)
    {
        stst.push(st.top());
        st.pop();
    }
    
    while(stst.size() != 0)
    {
        cout << v[stst.top()] << " ";
        stst.pop();
    }
    cout << "\n";

}

void func2(stack<int>& st, int num)
{
    if(st.size() == M)
    {
        printst(st);
        return;
    }

    input[num]--;
    for(int i = 0; i<v.size(); i++)
    {
        if(input[v[i]])
        {
            st.push(i);
            func2(st, v[i]);
            st.pop();
        }
    }

    input[num]++;

}

int main()
{
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M;
    for(int i = 0; i<N; i++)
    {
        int temp;
        cin >> temp;
        if(find(v.begin(), v.end(), temp) == v.end())
            v.push_back(temp);
        input[temp]++;
    }

    sort(v.begin(), v.end());
    stack<int> st;
    func2(st, 0);


}