#include <bits/stdc++.h>
using namespace std;

vector<int> noOfitems(string s, vector<int> &start, vector<int> &end)
{
  vector<int> res;
  int size = start.size();
  int count = 0;
  int count_closed = 0;
  int open = 0;

  for (int i = 0; i < size; i++)
  {
    count = 0;
    count_closed = 0;
    for (int j = start[i]; j < end[i]; j++)
    {
      if (!open && s[j] == '|')
        open = 1;
      else if (open && s[j] == '*')
        count++;
      else if (open && s[j] == '|')
      {
        count_closed += count;
        count = 0;
      }
    }
    res.push_back(count_closed);
  }

  return res;
}

int main()
{
  string s = "*|*|*|*********|***|****";
  vector<int> start{1, 3};
  vector<int> end{25, 21};

  vector<int> res = noOfitems(s, start, end);
  for (int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
}

/*
// More accurate and optimised solution. O(n) Solution.
public
List<Integer> numberOfItems(String s, List<Integer> startIndices, List<Integer> endIndices)
{
  int n = s.length();
  int[] dp = new int[n];
  int count = 0;
  for (int i = 0; i < s.length(); i++)
  {
    if (s.charAt(i) == '|')
    {
      dp[i] = count;
    }
    else
    {
      count++;
    }
  }
  List<Integer> ans = new ArrayList<>();
  for (int i = 0; i < startIndices.size(); i++)
  {
    int start = startIndices.get(i);
    int end = endIndices.get(i);

    while (s.charAt(start) != '|')
      start++;
    while (s.charAt(end) != '|')
      end--;
    if (start < end)
    {
      ans.add(dp[end] - dp[start]);
    }
    else
    {
      ans.add(0);
    }
  }
  return ans;
}
*/