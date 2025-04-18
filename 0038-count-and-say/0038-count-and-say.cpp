class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        string temp;
        for (int i = 1; i < n; i++) {
            int idx = 0;
            while (idx < result.size()) {
                char c = result[idx];
                int count = 0;
                while (idx < result.size() && result[idx] == c) {
                    count++;
                    idx++;
                }
                temp = temp + to_string(count) + c;
            }
            result = temp;
            temp = "";
        }
        return result;
    }
};