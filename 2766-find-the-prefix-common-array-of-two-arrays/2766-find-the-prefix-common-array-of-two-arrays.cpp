class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        unordered_map<int, int> mp;
        vector<int> res;
        int common = 0;

        for (int i = 0; i < A.size(); i++) {
            mp[A[i]]++;
            mp[B[i]]++;

            if (A[i] == B[i]) {
                common++;
            } else {
                if (mp[A[i]] == 2)
                    common++;
                if (mp[B[i]] == 2)
                    common++;
            }
            res.push_back(common);
        }

        return res;
    }
};