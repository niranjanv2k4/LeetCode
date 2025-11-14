class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> pref(n, vector<int>(n, 0));

        for(auto& query:queries){
            for(int i = query[0]; i<=query[2]; i++){
                pref[i][query[1]] += 1;
                if(query[3] + 1<n)
                    pref[i][query[3]+1] -= 1;
            }
        }

        for(int i = 0; i<n; i++){
            for(int j = 1; j<n; j++){
                pref[i][j] += pref[i][j-1];
            }
        }

        return pref;

    }
};