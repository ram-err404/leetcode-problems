#include <bits/stdc++.h>
using namespace std;

vector<int> noOfitems(string s, vector<int>& start, vector<int>& end) {
    vector<int> res;
    int size = start.size();
    int count = 0;
    int count_closed = 0;
    int open = 0;

    for (int i = 0; i < size; i++) {
        count = 0; count_closed = 0;
        for (int j = start[i]; j < end[i]; j++) {
            if (!open && s[j] == '|')
                open = 1;
            else if (open && s[j] == '*')
                count++;
            else if (open && s[j] == '|') {
                count_closed += count;
                count = 0;
            }
        }
        res.push_back(count_closed);
    }

    return res;
}

int main() {
    string s = "*|*|*|*********|***|****";
    vector<int> start{ 1,3 };
    vector<int> end{ 25,21 };

    vector<int> res = noOfitems(s, start, end);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    
    return 0;
}