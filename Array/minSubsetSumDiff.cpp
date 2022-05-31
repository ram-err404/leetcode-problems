#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &arr) {
    int n=arr.size();
    int i=0, j=0;
    int sum=0;
    
    // calculate total sum.
    for(;i<n;i++)
        sum+=arr[i];
    // create an array to store results of subproblems
    bool dp[n+1][sum+1];
    
    // Initialise the 1st column as true, as 0 sum is possible with all the elements.
    for(i=0; i<=n; i++)
        dp[i][0]=true;
    // Initialise the top row as false (except dp[0][0]), as with 0 elements no other sum excpet 0 is possible.
    for(i=0; i<=n; i++)
        dp[0][i]=false;
    
    // fill the partition table with bottom up manner.
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=sum; j++) {
            // If ith element is excluded.
            dp[i][j]=dp[i-1][j];
            
            // If ith element is included.
            if(arr[i-1] <= j)
                dp[i][j]=dp[i-1][j-arr[i-1]];
        }
    }
    // Initialise diff of 2 sum.
    int diff = INT_MAX;
    // find the largest j such that dp[n][j] is true.
    // where j loops from sum/2 to 0.
    for(j=sum/2; j>=0; j--) {
        if(dp[n][j] == true) {
            diff = sum-2*j;
            break;
        }
    }
    return diff;
}

int main() {
    vector<int> v{3, 1, 4, 2, 2, 1};
    cout<<findMin(v);
    return 0;
}