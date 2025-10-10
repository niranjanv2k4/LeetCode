class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> pre(k, INT_MIN);
        
        for(int i = 0; i<k; i++){
            int temp = 0;
            for(int j = n-1-i; j>=0; j-=k){
                temp += energy[j];
                pre[i] = max(pre[i], temp);
            }
        }
        
        return *max_element(pre.begin(), pre.end());
    }
};