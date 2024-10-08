class Solution {
public:
    int numberOfChild(int n, int k) {
        k%=(2*n-2);
        if (k<n) return k;
        else return 2*n-2-k;
    }
};