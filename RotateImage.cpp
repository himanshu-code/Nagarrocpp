#include <bits/stdc++.h>
using namespace std;
void rotateimage(int arr[100][100], int n)
{
    for (int x = 0; x < n / 2; x++)
    {
        for (int y = x; y < n - x - 1; y++)
        {
            int temp = arr[x][y];
            arr[x][y] = arr[y][n - 1 - x];

            arr[y][n - 1 - x] = arr[n - 1 - x][n - 1 - y];
            arr[n - 1 - x][n - 1 - y] = arr[n - 1 - y][x];
            arr[n - 1 - y][x] = temp;
        }
    }
}
int main()
{
    int i, j, n;
    cin >> n;
    int arr[100][100];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    rotateimage(arr, n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}