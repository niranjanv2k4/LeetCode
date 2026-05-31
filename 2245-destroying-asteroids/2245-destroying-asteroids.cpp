class Solution {
public:
    bool asteroidsDestroyed(long long  mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        for (int el : asteroids) {
            if (el > mass)
                return false;
            mass += el;
        }

        return true;
    }
};