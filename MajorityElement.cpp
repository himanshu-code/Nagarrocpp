#include <iostream>
using namespace std;
int CandidateFreq(int *arr, int n, int candidate)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == candidate)
        {
            cnt++;
        }
    }
    return cnt;
}
int majority(int *arr, int n)
{
    int cnt = 0;
    int candidate;
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            candidate = arr[i];
        }
        cnt += (candidate == arr[i]) ? 1 : -1;
    }
    int f = CandidateFreq(arr, n, candidate);
    if (f > (n / 2))
    {
        return candidate;
    }
    else
        return -1;
}
int main()
{
    int arr[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << majority(arr, n);
    return 0;
}