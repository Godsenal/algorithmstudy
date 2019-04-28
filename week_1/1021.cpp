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
  // 덱에 전부 추가
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
    // 앞과 뒤 처음부터 target을 먼저 찾을 때까지 반복
    while (!q.empty())
    {
      int front = q.front();
      int back = q.back();
      // 앞에서 먼저 찾을 경우,
      // 1. target을 pop
      // 2. 뒤에서 뽑은 수들은 뽑은 순서와 반대로 뒤에 다시 넣어줌.
      // 3. 앞에서 뽑은 수들은 뽑은 순서대로 뒤에 넣어줌.
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
      // 뒤에서 먼저 찾았을 경우는 앞에서 찾았을 때와 반대.
      // 맨 뒤에 수를 맨 앞으로 가져오는 비용이 하나 더 있으니 cost + 1
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
