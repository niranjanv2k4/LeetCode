class Solution {
public:
    string countAndSay(int n) {

        string result = "1";

        for (int i = 1; i < n; i++) {
            stringstream temp;
            int idx = 0;

            while (idx < result.size()) {
                char c = result[idx];
                int count = 0;

                while (idx < result.size() && result[idx] == c) {
                    count++;
                    idx++;
                }

                temp << count << c;
            }

            result = temp.str();
        }

        return result;
    }
};