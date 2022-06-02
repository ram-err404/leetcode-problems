// Amazon Q1: getMaxFreqDeviation.

#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'getMaxFreqDeviation' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
#define max(a, b) ((a > b) ? a : b)

int modifiedK(vector<int> &arr, int k)
{
  int n = arr.size();
  if (n < k)
    return 0;

  vector<int> maxSum(n);
  maxSum[0] = arr[0];

  for (int i = 1; i < n; i++)
  {
    maxSum[i] = max(arr[i], maxSum[i - 1] + arr[i]);
  }

  int sum = 0;
  for (int i = 0; i < k; i++)
  {
    sum += arr[i];
  }
  int ans = sum;
  for (int i = k; i < n; i++)
  {
    sum = sum + arr[i] - arr[i - k];
    ans = max(ans, sum);
    ans = max(ans, sum + maxSum[i - k]);
  }
  return ans;
}

int getMaxFreqDeviation(string s)
{
  int ans = 0;

  for (char c1 = 'a'; c1 <= 'z'; c1++)
  {
    for (char c2 = 'a'; c2 <= 'z'; c2++)
    {
      if (c1 == c2)
        continue;

      vector<int> arr;

      for (auto c : s)
      {
        if (c == c1)
        {
          if (arr.size() && arr.back() != -1)
            arr.back() += 1;
          else
            arr.push_back(1);
        }
        else if (c == c2)
        {
          arr.push_back(-1);
        }
      }
      ans = max(ans, modifiedK(arr, 2));
    }
  }
  return ans;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  string s;
  getline(cin, s);

  int result = getMaxFreqDeviation(s);

  fout << result << "\n";

  fout.close();

  return 0;
}
