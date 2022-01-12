class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int last_unique_index=0, max_val=0;
        for(int i=0;i<s.size();i++){
            char key = s[i];
            if(mp.count(key)>0) {
                std::cout<<"mp.count(key): "<<mp.count(key)<<" and mp[key]: "<<mp[key]<<" last_unique_index: "<<last_unique_index<<std::endl;
                last_unique_index = max(last_unique_index, mp[key]+1);
            }
            mp[key] = i;
            max_val = max(max_val, i-last_unique_index+1);
            std::cout<<"mp[key]: "<<mp[key]<<" max_val: "<<max_val<<" last_unique_index: "<<last_unique_index<<std::endl;
        }
        
        return max_val;
    }
};
