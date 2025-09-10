class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        vector<vector<int>> temp;
        for (auto& vec : languages) {
            sort(vec.begin(), vec.end());
        }
        
        for (auto vec : friendships) {
            if (!check(languages, vec[0] - 1, vec[1] - 1)) {
                temp.push_back(vec);
            }
        }

        int res = 0, max_lang = 0;
        vector<int> fre(n + 1, 0);
        set<int> vis;

        for (auto vec : temp) {
            for (auto el : vec) {
                if (vis.find(el) == vis.end()) {
                    for (int lang : languages[el - 1]) {
                        fre[lang]++;
                        if (fre[max_lang] < fre[lang]) {
                            max_lang = lang;
                        }
                    }
                    vis.insert(el);
                }
            }
        }

        for (auto el : vis) {
            bool flag = false;
            for (auto lang : languages[el - 1]) {
                if (lang == max_lang) {
                    flag = true;
                    break;
                }
            }
            res += !flag;
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