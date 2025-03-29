class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = start;
        for (int i=start + 2; i < start + 2*n; i += 2) ans ^= i;
        return ans;
    }
};