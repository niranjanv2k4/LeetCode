class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        freq.erase(remove(freq.begin(), freq.end(), 0), freq.end());
        sort(freq.begin(), freq.end());

        int res = INT_MAX;
        int n = freq.size();

        for (int i = 0; i < n; i++) {
            
            int del = 0;
            int min_val = freq[i];

            for (int j = 0; j < i; j++) {
                del += freq[j];
            }

            for(int j = i+1; j<n; j++){
                if(freq[j]>min_val+k){
                    del += freq[j]-(min_val+k);
                }
            }
            res = min(res, del);
        }

        return res;
    }
};