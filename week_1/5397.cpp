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
    // 커서를 기준으로 left, right 스택을 나눠서 품.
    // '<' 일때는 커서 바로 앞에 있는 수 (left.top)을 right로
    // '>' 일때는 반대
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
    // 출력시에 stack이기 때문에 거꾸로 출력해줘야함. left에 몰아넣고 거꾸로 출력.
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
