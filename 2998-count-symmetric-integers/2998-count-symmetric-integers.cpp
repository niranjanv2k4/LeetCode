class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0, sum = 0;
        string str;
        for (int i = low>11?low:11 ; i <= high; i++) {
            if (to_string(i).size() % 2 == 1) {
                i *= 10;
                continue;
            }

            str = to_string(i);
            sum = 0;

            for (int j = 0; j < str.size(); j++) {
                sum +=
                    (j < str.size() / 2) ? (str[j] - '0') : (-(str[j] - '0'));
            }

            count = sum == 0 ? count + 1 : count;
        }
        return count;
    }
};