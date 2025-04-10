class Solution {
public:
    #define ll long long
    ll dp[17][2];

    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  string suffix) {
        ll suffixVal = stoll(suffix);
        string sFinish = to_string(finish);
        string sStart = to_string(start - 1);

        ll finishDigits = sFinish.size();
        ll startDigits = sStart.size();

        ll uptoFinish =
            finish >= suffixVal
                ? solveUpTo(sFinish, finishDigits, limit, suffix)
                : 0;
        ll uptoStart =
            start > suffixVal ? solveUpTo(sStart, startDigits, limit, suffix)
                              : 0;

        return uptoFinish - uptoStart;
    }

    static bool ifSubstract(const string& numStr, ll numDigits,
                            const string& suffix, int limit) {
        if (numDigits < suffix.size())
            return false;

        string suffixOfNum = numStr.substr(numDigits - suffix.size());
        bool substract = stoll(suffixOfNum) < stoll(suffix);
        if (substract) {
            for (int i = 0; i < numDigits - suffix.size(); i++) {
                if ((numStr[i] - '0' > limit)) {
                    substract = false;
                    break;
                }
            }
        }
        return substract;
    }

    ll countValidNumbers(const string& numStr, ll idx,
                                    ll maxDigits, bool isTight,
                                    int limit, const string& suffix) {
        if (idx == maxDigits)
            return 1;
        if (dp[idx][isTight] != -1)
            return dp[idx][isTight];

        ll low = 0, high;
        ll suffixLen = suffix.size();

        if (idx >= maxDigits - suffixLen) {
            ll suffixIdx = idx - (maxDigits - suffixLen);
            low = high = suffix[suffixIdx] - '0';
        } else {
            high =
                isTight ? min<ll>(limit, numStr[idx] - '0') : limit;
        }

        ll total = 0;
        for (long long digit = low; digit <= high; digit++) {
            bool newTight = isTight && (digit == numStr[idx] - '0');
            total += countValidNumbers(numStr, idx + 1, maxDigits, newTight,
                                       limit, suffix);
        }

        return dp[idx][isTight] = total;
    }

    ll solveUpTo(const string& numStr, ll numDigits,
                            int limit, const string& suffix) {
        memset(dp, -1, sizeof(dp));
        ll result =
            countValidNumbers(numStr, 0, numDigits, true, limit, suffix);
        if (ifSubstract(numStr, numDigits, suffix, limit))
            result--;
        return result;
    }
};