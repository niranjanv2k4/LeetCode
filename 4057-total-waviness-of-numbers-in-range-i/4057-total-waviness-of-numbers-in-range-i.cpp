class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int res = 0;

        for(int i = num1; i <= num2; i++)
            res += waviness(i);

        return res;
    }

    int waviness(int n){
        int res = 0;
        string s = to_string(n);

        for(int i = 1; i<s.size() - 1; i++){
            if(s[i] < s[i-1] && s[i] < s[i+1])
                res++;
            else if(s[i] > s[i-1] && s[i] > s[i+1])
                res++;
        }

        return res;
    }
};