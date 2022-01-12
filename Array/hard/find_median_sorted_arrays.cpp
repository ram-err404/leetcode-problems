/*Solution: Runtime: 32 ms, Memory Usage: 89.6 MB. */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& vect1, vector<int>& vect2) {
        for(int i = 0; i < vect2.size(); i++)
            vect1.push_back(vect2[i]);
        sort(vect1.begin(), vect1.end());
        int n = vect1.size();
        if(n % 2 != 0)
            return (double)vect1[n/2];
        else
            return (double)(vect1[(n/2)-1] + vect1[n/2])/2;
    }
};

