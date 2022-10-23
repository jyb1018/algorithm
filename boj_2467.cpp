#include <iostream>
#include <cmath>

using namespace std;

int N;
int arr[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int backidx = N-1;
    int frontidx = 0;

    int maxidx = N-1;
    int minidx = 0;
    int res = 2147483647;
    
    while(frontidx != backidx)
    {
        int temp = arr[backidx] + arr[frontidx];
        if(abs(temp) < res)
        {
            res = abs(temp);
            maxidx = backidx;
            minidx = frontidx;
        }

        if(temp > 0)
            backidx--;
        else if (temp < 0)
            frontidx++;
        else
            break;
        // cout << frontidx << " " << backidx << " " << arr[frontidx] << " " << arr[backidx] << endl;
    }
    
    cout << arr[minidx] << " " << arr[maxidx] << endl;
    
}