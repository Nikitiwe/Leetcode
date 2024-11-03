class Solution {
public:
    vector<int> constructRectangle(int s) {
        for (int i=sqrt(s); i>=1; i--)
        {
            if (s%i==0) return {s/i, i};
        }
        return {-1, -1};
    }
};