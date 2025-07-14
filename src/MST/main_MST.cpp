#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> result;
    map<int, vector<int>> mp;
    vector<int> du(v, 0);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        du[b]++;
    }
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (du[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        result.push_back(cur);
        for (int i = 0; i < mp[cur].size(); i++)
        {
            du[mp[cur][i]]--;
            if (du[mp[cur][i]] == 0)
                q.push(mp[cur][i]);
        }
    }
    if (result.size() == v)
    {
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
    }
    else
        cout << "-1";
    return 0;
}
