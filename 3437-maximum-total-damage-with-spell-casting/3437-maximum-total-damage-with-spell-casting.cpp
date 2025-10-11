class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> mp;
        for(int p:power){
            mp[p]++;
        }

        vector<pair<int, int>> vec = {{INT_MIN, 0}};
        for(auto &el:mp){
            vec.push_back(el);
        }

        long long max_val = 0;
        int n = vec.size();
        vector<long long> f(n, 0);

        for(int i = 1, j = 1; i<n; i++){
            while(j<i && vec[j].first < vec[i].first - 2){
                max_val = max(max_val, f[j]);
                j++;
            }

            f[i] = max_val + 1LL*vec[i].first*vec[i].second;
        }

        return *max_element(f.begin(), f.end());
    }
};