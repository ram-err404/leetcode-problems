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

/*Solution:  Runtime: 28 ms, Memory Usage: 89.3 MB. */
class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0, j = 0, last = 0, current = 0, n = nums1.size(), m = nums2.size(), q = m + n;
        while (i < n || j < m)
        {
            if (i == n)
                current = nums2[j++];
            else if (j == m)
                current = nums1[i++];
            else if (nums1[i] > nums2[j])
                current = nums2[j++];
            else
                current = nums1[i++];

            if (i + j > q / 2)
                break;
            last = current;
        }

        return q % 2? current: (last + current) / 2.0;
    }
};
