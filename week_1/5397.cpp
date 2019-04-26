#include <iostream>
#include <string>
#include <stack>

using namespace std;

void printStack(stack<char> &s)
{
  if (s.empty())
    return;
  char curr = s.top();
  s.pop();
  printStack(s);
  cout << curr;
  return;
}
int main()
{
  int t;
  string s;
  stack<char> left;
  stack<char> right;
  cin >> t;
  while (t--)
  {
    cin >> s;
    for (char c : s)
    {
      if (c == '<')
      {
        if (!left.empty())
        {
          right.push(left.top());
          left.pop();
        }
      }
      else if (c == '>')
      {
        if (!right.empty())
        {
          left.push(right.top());
          right.pop();
        }
      }
      else if (c == '-')
      {
        if (!left.empty())
        {
          left.pop();
        }
      }
      else
      {
        left.push(c);
      }
    }
    while (!right.empty())
    {
      left.push(right.top());
      right.pop();
    }
    printStack(left);
    cout << endl;
  }
  return 0;
}