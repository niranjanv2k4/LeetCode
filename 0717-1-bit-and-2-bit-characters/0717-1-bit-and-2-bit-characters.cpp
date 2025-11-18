class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int prev = 0;
        for(int i = 0; i<bits.size(); i++){
            prev = 1;
            if(bits[i] == 1){
                i++;
                prev = 2;
            }
        }
        return prev == 1;
    }
};