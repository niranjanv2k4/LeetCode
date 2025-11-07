class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> pref(n, 0);
        long long curr = 0;
        for(int i = 0; i<=r; i++){
            curr += stations[i];
        }
        for(int i = 0; i<n; i++){
            pref[i] = curr;
            if(i - r >= 0)
                curr -= stations[i - r];
            if(i + r + 1 < n){
                curr += stations[i + r + 1];
            }
        }

        for(int c:pref)cout<<c<<" ";
        
        long long high = 1e18, low = 0, ans = 0;
        while(low<=high){
            long long mid = low + (high - low)/2;
            if(possible(pref, mid, r, k)){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return ans;
    }

    bool possible(vector<long long>& pref, long long mid, int r, int k){
        int n = pref.size();
        vector<long long> diff(n+1, 0);
        long long tot = 0;

        for(int i = 0; i<n; i++){
            tot += diff[i];
            long long curr = pref[i] + tot;

            if(curr < mid){
                long long temp  = mid - curr;
                if(temp > k)return false;
                k -= temp;
                tot += temp;
                int end = i + 2*r + 1;
                if(end<n)diff[end] -= temp;
            } 
        }
        return true;
    }
};