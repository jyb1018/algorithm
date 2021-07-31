#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int N, M;
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

void func(stack<int>& st, int idx)
{
    if(st.size() == M)
    {
        printst(st);
        return;
    }
    if(idx >= N)
        return;
    
    for(int i = idx; i<N; i++)
    {
        st.push(i);
        func(st, i);
        st.pop();
    }
    
}

int main() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    cin >> N >> M;
    
    for(int i = 0; i<N; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    stack<int> st;
    func(st, 0);
    

    


}