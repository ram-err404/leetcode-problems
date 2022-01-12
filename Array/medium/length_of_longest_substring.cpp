
/*Solution: Runtime: 16 ms, Memory: 8.3 MB*/
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

/*Another Solution: Runtime: 9 ms, Memory6.9 MB*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if (len < 2) return len; //Trivial cases
        int begin = 0; //Start of max length nonrepeating substring
        int end = 0; //End of max length nonrepeating substring
        int max = 1; //Max length of nonrepeating substring

        //Direct-address table with keys of all ASCII characters
        //first[c] = index of first appearance of the character c
        int first[256] = {[0 ... 255] = -1};

        while (end < len && len - begin > max){
            int ascii = int(s[end]); //Convert the end character to ASCII code

            //If s[end] is found in first, it means there's a repeating
            //character, so update the begin pointer to the character after
            //first[ascii]
            if (first[ascii] >= begin){
                begin = first[ascii] + 1;
            }
            //Update the direct-address table with the rightmost appearance of
            //the char s[end]
            first[ascii] = end;

            end++;
            int diff = end - begin;
            if (diff > max) max = diff; //Get the maximum distance between end and begin

        }
        return max;
    }
};
