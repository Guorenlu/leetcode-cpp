#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int main()
{
    int n, m, p1, p2, val;
    cin >> n >> m;

    vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 0; i < m; i++)
    {
        cin >> p1 >> p2 >> val;
        grid[p1][p2] = val;
    }

    int start = 1;
    int end = n;

    vector<int> minDist(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);

    minDist[start] = 0;

    for (int i = 1; i <= n; i++)
    {
        int minVal = INT_MAX;
        int cur = -1;

        for (int v = 1; v <= n; ++v)
        {
            if (!visited[v] && minDist[v] < minVal)
            {
                minVal = minDist[v];
                cur = v;
            }
        }

        if (cur == -1)
            break; // 防止死循环
        visited[cur] = true;

        for (int v = 1; v <= n; v++)
        {
            if (!visited[v] && grid[cur][v] != INT_MAX && minDist[cur] + grid[cur][v] < minDist[v])
            {
                minDist[v] = minDist[cur] + grid[cur][v];
                parent[v] = cur;
            }
        }
    }

    if (minDist[end] == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << "Shortest distance: " << minDist[end] << endl;
        vector<int> path;
        for (int cur = end; cur != -1; cur = parent[cur])
        {
            path.push_back(cur);
        }
        reverse(path.begin(), path.end());
        cout << "Path: ";
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i];
            if (i != path.size() - 1)
                cout << " -> ";
        }
        cout << endl;
    }
    return 0;
}
