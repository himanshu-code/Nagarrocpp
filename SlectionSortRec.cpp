#include <iostream>
using namespace std;
int FindMinIndex(int *a, int n, int i)
{
    int min = i;
    for (int j = i + 1; j < n; j++)
    {
        if (a[j] < a[min])
        {
            min = j;
        }
    }
    return min;
}
void SelectionSort(int *arr, int n, int i)
{
    if (i == n - 1)
    {
        return;
    }
    int min = FindMinIndex(arr, n, i);
    if (i != min)
    {
        swap(arr[i], arr[min]);
    }
    SelectionSort(arr, n, i + 1);
}
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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
    print(arr, n);
    SelectionSort(arr, n, 0);
    print(arr, n);
}