class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        int i = 0;
        vector<string> res;
        while (i < folder.size()) {
            string temp = folder[i++];
            int size = temp.size();
            while (i < folder.size()) {
                string sub = folder[i].substr(0, size);
                if (sub == temp && folder[i][size] == '/')
                    i++;
                else
                    break;
            }

            res.push_back(temp);
        }
        return res;
    }
};