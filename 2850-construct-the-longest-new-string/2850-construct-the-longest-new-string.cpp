class Solution {
public:
    int longestString(int x, int y, int z) {
        if (abs(x-y)<2) return (x+y+z)*2;
        else return (min(x, y)*2+1+z)*2;
    }
};