class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int size = nums.size();
        
        // sort the array to put all the duplicates together.
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<size-2; i++) {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int j=i+1, k=size-1;
            
            while(j<k) {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==0) {
                    vector<int> v{nums[i], nums[j], nums[k]};
                    res.push_back(v);
                    k--;
                    // skip all duplicates from last.
                    while(j<k && nums[k]==nums[k+1]) k--; 
                } else if(sum>0) {
                    // Decrease from last to reduce sum.
                    k--;
                } else {
                    // Increase from left to increase sum.
                    j++;
                }
            }
        }
        return res;
    }
};