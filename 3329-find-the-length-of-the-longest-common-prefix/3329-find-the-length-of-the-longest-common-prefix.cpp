class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for(int el : arr1){
            while(el){
                st.insert(el);
                el /= 10;
            }
        }

        int res = 0;
        for(int el : arr2){
            while(el){
                if(st.count(el)){
                    res = max(res, (int)floor(log10(el)) + 1);
                    // break;
                }
                el /= 10;
            }
        }

        return res;
    }
};