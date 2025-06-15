class Solution {
public:
    int maxDiff(int num) {
        string num_1 = to_string(num);
        string num_2 = num_1;

        char first;
        if (num_2[0] == '1') {
            auto it = find_if(num_2.begin() + 1, num_2.end(),
                               [](char c) { return c != '0' && c!='1'; });
            if (it != num_2.end()){
                first = *it;
                replace(num_2.begin(), num_2.end(), first, '0');
            }
        } else {
            first = num_2[0];
            replace(num_2.begin(), num_2.end(), first, '1');
        }

        first = *find_if(num_1.begin(), num_1.end(),
                         [](char c) { return c != '9'; });
        replace(num_1.begin(), num_1.end(), first, '9');

        return stoi(num_1) - stoi(num_2);
    }
};
