class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        unordered_map<char, int> lower_index, upper_index;
        int res = 0;

        for(int i = 0; i<word.size(); i++){
            if(isupper(word[i])){
                if(upper_index.find(word[i]) == upper_index.end())
                    upper_index[word[i]] = i;
            }else{
                lower_index[word[i]] = i;
            }
        }

        for(auto [ch, idx] : lower_index){
            if(upper_index.find(toupper(ch)) != upper_index.end() && upper_index[toupper(ch)] > idx)
                res++;
        }

        return res;
    }
};