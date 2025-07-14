#include "perimeter_of_island.h"
void findPerimeter(std::vector<std::vector<int>> grid, int n, int m, int direction[4][2], int &result)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                for (int d = 0; d < 4; d++)
                {
                    int ni = i + direction[d][0];
                    int nj = j + direction[d][1];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m || grid[ni][nj] == 0)
                    {
                        result++;
                    }
                }
            }
        }
    }
}