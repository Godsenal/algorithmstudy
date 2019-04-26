#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
  int m, n;
  scanf("%d %d", &m, &n);
  vector<bool> isPrime(n + 1, true);
  // 에라스토테네스의 체
  for (int i = 2; i * i <= n; ++i)
  {
    if (!isPrime[i])
      continue;
    for (int j = i * 2; j <= n; j += i)
    {
      isPrime[j] = false;
    }
  }
  for (int i = m; i <= n; ++i)
  {
    if (i != 1 && isPrime[i])
      printf("%d\n", i);
  }
}