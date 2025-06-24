class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        const int n = nums.size();
        vector<bool> valid(n, false);

        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                
                int l = max(i - k, 0);
                int r = min(i + k, n-1);
                
                for(int idx = l; idx<=r; idx++){
                    valid[idx]=true;
                }
            }
        }

        vector<int> res;
        
        for(int i = 0; i<n; i++){
            if(valid[i]){
                res.push_back(i);
            }
        }

        return res;
    }
};
