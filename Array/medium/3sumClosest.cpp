class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size=nums.size();
        int closest_diff=INT_MAX;
        int diff=0, sum=0, closest_sum=0;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<size-2; i++) {
            int j=i+1, k=size-1;
            while(j<k) {
                sum=nums[i]+nums[j]+nums[k];
                diff=fabs(sum-target);
                if(diff<closest_diff) {
                    closest_diff=diff;
                    closest_sum=sum;
                }
                if(sum==target)
                    return closest_sum;
                else if(sum<target)
                    j++;
                else
                    k--;
                
            }
        }
        return closest_sum;
    }
};