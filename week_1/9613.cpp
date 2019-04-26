#include <stdio.h>

using namespace std;

int nums[100];
int gcd(int a, int b)
{
  return a % b ? gcd(b, a % b) : b;
}
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &nums[i]);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
      for (int j = i + 1; j < n; ++j)
      {
        ans += gcd(nums[i], nums[j]);
      }
    }
    printf("%lld\n", ans);
  }
}