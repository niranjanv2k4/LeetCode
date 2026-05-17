class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string s : strs){
            mp[make_key(s)].push_back(s);
        }

        vector<vector<string>> res;
        for( auto [key, vec] : mp){
            // cout << key << ": ";
            // for(string el:vec){
            //     cout<< el << " ";
            // } 
            // cout << endl;
            res.push_back(vec);
        }

        return res;
    }

    string make_key(string s){
        vector<int> freq(26, 0);
        for(char ch : s)
            freq[ch - 'a']++;
        
        string res = "";
        for(int el : freq)
            res += ("," + to_string(el));

        return res;
    }
};