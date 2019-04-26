#include <iostream>
#include <string>

using namespace std;

int costs[10];
string dp[51];

bool cmp(string s1, string s2)
{
  int size1 = s1.size();
  int size2 = s2.size();

  if (size1 > size2)
    return true;
  if (size2 > size1)
    return false;
  for (int i = 0; i < size1; ++i)
  {
    if (s1[i] > s2[i])
      return true;
    if (s2[i] > s1[i])
      return false;
  }
  return true;
}

int main()
{
  int n, money;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> costs[i];
  }
  cin >> money;
  // 동전 문제처럼 dp를 짠다.
  // money를 기준으로 0 ~ i-1 까지 반복을 돌아가면서
  // 이 i를 뒤에 넣었을 때 i의 비용을 뺀 이미 저장된 dp보다 i를 뒤에 넣은게 숫자가 더 크면,
  // 그 money를 기준으로 저장된 dp값을 더 큰걸로 바꿔줌.
  for (int i = 0; i <= money; ++i)
  {
    for (int k = 0; k < n; ++k)
    {
      if (i - costs[k] >= 0)
      {
        char curr = k + '0';
        string prev = dp[i - costs[k]] + curr;
        if (k == 0 && prev == "0")
          continue;
        if (!cmp(dp[i], prev))
        {
          dp[i] = prev;
        }
      }
    }
  }
  string ans = dp[money] == "" ? "0" : dp[money];
  cout << ans << endl;
}