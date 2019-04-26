#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int nums[10];

int main()
{
  string s;
  cin >> s;
  for (char c : s)
  {
    nums[c - '0']++;
  }
  int six = (nums[6] + nums[9] + 1) / 2;
  nums[6] = nums[9] = six;
  int maxC = 0;
  for (int i = 0; i < 10; ++i)
  {
    maxC = max(maxC, nums[i]);
  }
  cout << maxC;
}