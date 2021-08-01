#include <iostream>
using namespace std;
bool isSafe(int board[][10], int i, int j, int n)
{
    for (int k = 0; k < n; k++)
    {
        if (board[i][k] == 1 || board[k][j] == true)
        {
            return false;
        }
    }
    int l = i, m = j;
    while (i >= 0 && j < n)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j--;
    }
    i = l;
    j = m;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j++;
    }
    return true;
}
bool Nqueen(int board[][10], int i, int n)
{
    if (i == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
    for (int j = 0; j < n; j++)
    {
        if (isSafe(board, i, j, n))
        {
            board[i][j] = 1;
            bool nextSafe = Nqueen(board, i + 1, n);
            if (nextSafe == true)
            {
                return true;
            }
            board[i][j] = 0;
        }
    }
    return false;
}
int main()
{
    int board[10][10] = {0};
    int n;
    cin >> n;
    Nqueen(board, 0, n);
}