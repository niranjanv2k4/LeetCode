class Solution {
public:
    int maxDistance(string s, int k) {
        
        int north = 0, south = 0;
        int east = 0, west = 0;
        int res = 0;

        for (int c : s) {
            if (c == 'N')
                north++;
            else if (c == 'S')
                south++;
            else if (c == 'E')
                east++;
            else if (c == 'W')
                west++;

            int vertical = min({north, south, k});
            int horizontal = min({east, west, k - vertical});

            res = max(res, dist(east, west, vertical)+ dist(north, south, horizontal));
        }
        return res;
    }

    int dist(int one, int two, int k) { return abs(one - two) + k * 2; }
};