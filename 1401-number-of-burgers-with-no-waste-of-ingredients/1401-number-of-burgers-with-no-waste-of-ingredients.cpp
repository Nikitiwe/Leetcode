class Solution {
public:
    vector<int> numOfBurgers(int a, int b) {
        if (a%2==0&&a>=b*2&&b*4>=a) return {a/2-b, 2*b-a/2};
        else return {};
    }
};