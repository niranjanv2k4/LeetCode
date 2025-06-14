class Solution {
public:
    int minMaxDifference(int num) {

        string temp_1 = to_string(num);
        string temp_2 = temp_1;

        char first = *find_if(temp_1.begin(), temp_1.end(), [](char c){
            return c!='9';
        });
        replace(temp_1.begin(), temp_1.end(), first, '9');

        first = temp_2[0];
        replace(temp_2.begin(), temp_2.end(), first, '0');

        return stoi(temp_1) - stoi(temp_2);
    }
};