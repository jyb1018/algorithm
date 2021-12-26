#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int arr[8];

//<=8
int N, M;

deque<int> dq;

void func(int depth)
{
    if(depth == 0)
    {
        for (int i = 0; i < dq.size(); i++)
        {
            cout << dq.at(i) << " ";
        }
        cout << "\n";
        return;
    }

    int duplicate = 100001;
    for (int i = 0; i < N; i++)
    {
        if (duplicate != arr[i] && (dq.size() == 0 || dq.back() <= arr[i]))
        {
            duplicate = arr[i];
            dq.push_back(arr[i]);
            func(depth-1);
            dq.pop_back();
        }
    }
    
    
}


int main() 
{
    ios_base::sync_with_stdio(false);

    // freopen("./input.txt", "r", stdin);

    cin >> N >> M;
    for(int i = 0; i<N; i++) 
    {
        cin >> arr[i];  
    }

    sort(arr, arr+N);


    func(M);

}