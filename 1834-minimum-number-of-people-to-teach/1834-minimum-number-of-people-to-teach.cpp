class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        vector<vector<int>> temp;
        for(auto& vec:languages){
            sort(vec.begin(), vec.end());
        }
        for (auto vec : friendships) {
            if (!check(languages, vec[0] - 1, vec[1] - 1)) {
                temp.push_back(vec);
            }
        }
        int res = 0;
        vector<int> fre(n+1, 0);
        set<int> vis;
        for(auto vec:temp){
            int u = vec[0], v = vec[1];
            if(vis.find(u)==vis.end()){
                for(int lang:languages[u-1]){
                    fre[lang]++;
                }
                vis.insert(u);
            }
            if(vis.find(v)==vis.end()){
                for(int lang:languages[v-1]){
                    fre[lang]++;
                }
                vis.insert(v);
            }
        }

        int max_lang = 0;
        for(int i = 0; i<fre.size(); i++){
            if(fre[max_lang]<fre[i]){
                max_lang = i;
            }
        }

        for(auto el:vis){
            bool flag = false;
            for(auto lang : languages[el - 1]){
                if(lang==max_lang){
                    flag = true;
                    break;
                }
            }
            if(!flag)res++;
        }

        return res;
    }

    bool check(vector<vector<int>>& lang, int u, int v) {
        int i = 0, j = 0;
        while (i < lang[u].size() && j < lang[v].size()) {
            if (lang[u][i] < lang[v][j]) {
                i++;
            } else if (lang[u][i] > lang[v][j]) {
                j++;
            } else {
                return true;
            }
        }

        return false;
    }
};