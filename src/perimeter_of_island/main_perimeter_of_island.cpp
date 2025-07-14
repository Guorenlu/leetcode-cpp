#include <iostream>
#include <vector>
#include "perimeter_of_island.h"
using namespace std;
int n, m;
int main()
{
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int direction[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
    int result = 0;
    findPerimeter(grid, n, m, direction, result);
    cout << result << endl;
}