#include <iostream>
#include <vector>
using namespace std;

void go(vector<vector<int>> &island,
        int i,
        int j,
        vector<int> &path,
        vector<vector<bool>> &visited)
{
    int n = island.size();
    int m = island[0].size();

    // Out of bounds
    if (i < 0 || j < 0 || i >= n || j >= m)
        return;

    // Already visited
    if (visited[i][j])
        return;

    visited[i][j] = true;

    path.push_back(island[i][j]);

    // Reached boundary
    if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
    {
        for (int ele : path)
            cout << ele << " ";

        cout << endl;
    }

    // UP
    if (i - 1 >= 0 &&
        island[i - 1][j] <= island[i][j] &&
        !visited[i - 1][j])
    {
        go(island, i - 1, j, path, visited);
    }

    // DOWN
    if (i + 1 < n &&
        island[i + 1][j] <= island[i][j] &&
        !visited[i + 1][j])
    {
        go(island, i + 1, j, path, visited);
    }

    // LEFT
    if (j - 1 >= 0 &&
        island[i][j - 1] <= island[i][j] &&
        !visited[i][j - 1])
    {
        go(island, i, j - 1, path, visited);
    }

    // RIGHT
    if (j + 1 < m &&
        island[i][j + 1] <= island[i][j] &&
        !visited[i][j + 1])
    {
        go(island, i, j + 1, path, visited);
    }

    // Backtracking
    path.pop_back();
}

int main()
{
    vector<vector<int>> island{
        {11,4,7,1,9},
        {6,2,8,2,7},
        {0,1,1,3,7},
        {11,9,11,6,8},
        {3,4,8,5,10},
    };

    vector<vector<bool>> visited(5, vector<bool>(5, false));

    vector<int> path;

    go(island, 3, 3, path, visited);

    return 0;
}