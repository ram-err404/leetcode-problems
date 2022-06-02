#Amazon Q2: getHeaviestPackage.

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


#include "math.h"
/*
 * Complete the 'getHeaviestPackage' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY packageWeights as parameter.
 */
 
 #define max(a,b) ((a>b)?a:b)

long getHeaviestPackage(vector<int> packageWeights) {
    int n=packageWeights.size();
    int *dp = new int[n];
    long max_weight=INT32_MIN;
    
    dp[n-1]=packageWeights[n-1];
    
    for(int i=n-2; i>=0; i--) {
        if(packageWeights[i] < dp[i+1]) {
            dp[i]=dp[i+1]+packageWeights[i];
        } else {
            dp[i]=packageWeights[i];
        }
    }
    
    for(int i=0; i<n; i++) {
            max_weight=max(max_weight,dp[i]);
    }
    delete []dp;
    return max_weight;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string packageWeights_count_temp;
    getline(cin, packageWeights_count_temp);

    int packageWeights_count = stoi(ltrim(rtrim(packageWeights_count_temp)));

    vector<int> packageWeights(packageWeights_count);

    for (int i = 0; i < packageWeights_count; i++) {
        string packageWeights_item_temp;
        getline(cin, packageWeights_item_temp);

        int packageWeights_item = stoi(ltrim(rtrim(packageWeights_item_temp)));

        packageWeights[i] = packageWeights_item;
    }

    long result = getHeaviestPackage(packageWeights);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
