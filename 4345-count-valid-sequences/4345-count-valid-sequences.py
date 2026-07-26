class Solution:
    def countValidSequences(self, n: int, k: int) -> int:

        total = math.comb(n - 1, k - 1)
        odd = 0 if (n - k) % 2 != 0 else math.comb((n - k) // 2 + k - 1, k - 1)

        return (total - odd) % (10 ** 9 + 7)
