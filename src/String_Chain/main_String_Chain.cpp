#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
using namespace std;
int main()
{
  int n;
  cin >> n;
  set<string> s;
  string start, end;
  cin >> start >> end;
  while (n--)
  {
    string t;
    cin >> t;
    s.insert(t);
  }
  map<string, int> mp;
  mp[start] = 1;
  queue<string> q;
  q.push(start);
  while (!q.empty())
  {
    string word = q.front();
    q.pop();
    for (int i = 0; i < word.size(); i++)
    {
      string newword = word;
      for (int j = 0; j < 26; j++)
      {
        newword[i] = 'a' + j;
        if (newword == end)
        {
          cout << mp[word] + 1;
          return 0;
        }
        if (s.find(newword) != s.end() && mp.find(newword) == mp.end())
        {
          mp[newword] = mp[word] + 1;
          q.push(newword);
        }
      }
    }
  }
  return 0;
}
