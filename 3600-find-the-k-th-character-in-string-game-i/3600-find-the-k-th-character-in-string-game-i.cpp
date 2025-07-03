class Solution {
public:
    char kthCharacter(int k) {
        string temp = "a";
        
        for (int i = 1; i < k; i *= 2) {
            int size = temp.size();
            for (int j = 0; j < size; j++) {
                temp += temp[j] == 'z' ? 'a' : temp[j] + 1;
            }
        }

        return temp[k - 1];
    }
};