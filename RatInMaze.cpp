#include <iostream>
using namespace std;
bool RatInMaze(char maze[][5], int i, int j, int sol[][4], int n, int m)
{
    if (i == n - 1 && j == m - 1)
    {
        sol[i][j] = 1;
        for (int k = 0; k < n; k++)
        {
            for (int l = 0; l < m; l++)
            {
                cout << sol[k][l] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return false;
    }
    sol[i][j] = 1;
    if (j + 1 < m && maze[i][j + 1] != 'X')
    {
        bool rightstep = RatInMaze(maze, i, j + 1, sol, n, m);
        if (rightstep == true)
        {
            return true;
        }
    }
    if (i + 1 < n && maze[i + 1][j] != 'X')
    {
        bool downstep = RatInMaze(maze, i + 1, j, sol, n, m);
        if (downstep == true)
        {
            return true;
        }
    }
    sol[i][j] = 0;
    return false;
}
int main()
{
    char maze[4][5] = {
        "0000",
        "00XX",
        "0000",
        "XX00",
    };
    int sol[4][4] = {0};
    RatInMaze(maze, 0, 0, sol, 4, 4);
}