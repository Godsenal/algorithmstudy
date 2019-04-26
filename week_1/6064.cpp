#include <stdio.h>

using namespace std;
int gcd(int a, int b)
{
  return a % b ? gcd(b, a % b) : b;
}
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    int m, n, tm, tn;
    scanf("%d %d %d %d", &m, &n, &tm, &tn);
    int year;
    int maxY = m * n / gcd(m, n); // 최대 year는 두 년도의 최소 공배수
    for (year = tm; year <= maxY; year += m)
    {
      // m은 tm으로 고정 시켜둔 후 tn을 만족하는 년도를 찾는다.
      // year % n == tn 이면 그 년도가 tm, tn을 만족하는 년도임.
      int currN = year % n;
      if (currN == 0)
        currN = n;
      if (currN == tn)
        break;
    }
    printf("%d\n", year > maxY ? -1 : year);
  }
}