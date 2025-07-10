#include <bits/stdc++.h>
using namespace std;
int n, m;
int dir[8][2] = {
    {-1, -1}, // 左上
    {-1, 0},  // 上
    {-1, 1},  // 右上
    {0, 1},   // 右
    {1, 1},   // 右下
    {1, 0},   // 下
    {1, -1},  // 左下
    {0, -1}   // 左
};

bool judge(int x, int y, vector<vector<char>> &mp)
{
    bool flag = false; // 判断小鼠周围有没有暖壶
    for (int i = 0; i < 8; i++)
    {
        int cx = x + dir[i][0];
        int cy = y + dir[i][1];
        if (cx < 0 || cy < 0 || cx >= n || cy >= m)
            continue;
        if (mp[cx][cy] == 'm')
        {
            flag = true;
            break;
        }
    }
    return flag;
}

class Compare
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.first != b.first)
            return a.first < b.first;
        else
            return a.second < b.second;
    }
};
int main()
{
    vector<pair<int, int>> result;
    cin >> n >> m;
    vector<vector<char>> mp(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
        }
    }
    int x, y;  // 记录异常小鼠的位置
    int z = 0; // 记录异常小鼠 如果大于1 直接结束

    // 寻找异常小鼠
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mp[i][j] == 'w')
            {
                bool flag = judge(i, j, mp);
                if (flag == false)
                {
                    x = i;
                    y = j;
                    z++;
                    if (z >= 2)
                    {
                        cout << "Too cold!" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    if (z == 0)
    {
        cout << "Too cold!" << endl;
        return 0;
    }
    // cout << "异常小鼠" << x + 1 << " " << y + 1 << endl;
    //  找异常小鼠周围的可能暖壶
    for (int i = 0; i < 8; i++)
    {
        int cx = x + dir[i][0];
        int cy = y + dir[i][1];
        if (cx < 0 || cy < 0 || cx >= n || cy >= m)
            continue;
        // 判断cx, cy周围是否有cold小鼠，如果有就不是可能暖壶
        if (mp[cx][cy] != '.')
            continue;
        bool p = true;
        for (int j = 0; j < 8; j++)
        {
            int ccx = cx + dir[j][0];
            int ccy = cy + dir[j][1];
            if (ccx < 0 || ccy < 0 || ccx >= n || ccy >= m)
                continue;
            if (mp[ccx][ccy] == 'c')
            {
                p = false;
                break;
            }
        }
        if (p == true)
        {
            result.push_back({cx + 1, cy + 1});
        }
    }
    if (result.size() == 0)
    {
        cout << "Too cold!" << endl;
        return 0;
    }
    sort(result.begin(), result.end(), Compare());
    for (auto t : result)
    {
        cout << t.first << " " << t.second << endl;
    }
}