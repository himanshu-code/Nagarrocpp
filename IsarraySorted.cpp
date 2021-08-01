#include <iostream>
using namespace std;
bool isSorted(int *arr, int n)
{
    if (n == 1 || n == 0)
    {
        return true;
    }
    bool isSmallerSorted = isSorted(arr + 1, n - 1);
    if (isSmallerSorted == true && arr[0] < arr[1])
    {
        return true;
    }
    else
    {
        return false;
    }
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
    if (isSorted(arr, n))
    {
        cout << "Sorted";
    }
    else
        cout << "Not Sorted";
}