class Solution {
public:
    int maxOperations(string s) {
        int res = 0;
        int ones = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '0'){
                while(i+1<s.size() && s[i+1] == '0'){
                    i++;
                }
                res += ones;
            }else{
                ones++;
            }
        }
        return res;
        
    }
};