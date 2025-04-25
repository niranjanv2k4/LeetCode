#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {

        int n = nums.size();
        long long result = 0, count = 0;
        
        unordered_map<int, long long> freq;
        freq[0] = 1;  

        for (int num : nums) {
            if (num % modulo == k) {
                count += 1;
            }

            result += freq[(count + modulo - k) % modulo];
            freq[count % modulo]++;
        }

        return result;
    }
};
