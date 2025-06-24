class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> keys;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == key)
                keys.push_back(i);
        }

        set<int> st;
        for(int i = 0; i<nums.size(); i++){
            if(count(keys.begin(), keys.end(), i)){
                st.insert(i);
                continue;
            }
            for(int c:keys){
                if(abs(i-c)<=k)st.insert(i);
            }
        }
        vector<int> res(st.begin(), st.end());
        return res;
    }
};
