#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n, m, ans = 0;
  scanf("%d %d", &n, &m);
  deque<int> q;
  for (int i = 1; i <= n; i++)
  {
    q.push_back(i);
  }
  while (m--)
  {
    int target, cost = 0;
    vector<int> tempF;
    vector<int> tempB;
    scanf("%d", &target);
    while (!q.empty())
    {
      int front = q.front();
      int back = q.back();
      if (front == target)
      {
        q.pop_front();
        reverse(tempB.begin(), tempB.end());
        for (int b : tempB)
        {
          q.push_back(b);
        }
        for (int f : tempF)
        {
          q.push_back(f);
        }
        break;
      }
      else if (back == target)
      {
        q.pop_back();
        reverse(tempF.begin(), tempF.end());
        for (int f : tempF)
        {
          q.push_front(f);
        }
        for (int b : tempB)
        {
          q.push_front(b);
        }
        ++cost;
        break;
      }
      tempF.push_back(front);
      q.pop_front();
      tempB.push_back(back);
      q.pop_back();
      ++cost;
    }
    ans += cost;
  }
  printf("%d\n", ans);
}