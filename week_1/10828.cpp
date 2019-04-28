#include <iostream>
#include <string>

using namespace std;
int arr[10001];
int pos = -1;
void push(int value)
{
  arr[++pos] = value;
}
int pop()
{
  if (pos == -1)
    return -1;
  return arr[pos--];
}
int top()
{
  if (pos == -1)
    return -1;
  return arr[pos];
}
int size()
{
  return pos + 1;
}
bool empty()
{
  return pos == -1;
}
int main()
{
  int t;
  cin >> t;
  string exec;
  while (t--)
  {
    int result = 0;
    cin >> exec;
    if (exec == "top")
    {
      result = top();
    }
    else if (exec == "size")
    {
      result = size();
    }
    else if (exec == "pop")
    {
      result = pop();
    }
    else if (exec == "empty")
    {
      result = empty();
    }
    else if (exec == "push")
    {
      int value;
      cin >> value;
      push(value);
      continue;
    }
    cout << result << endl;
  }
}
