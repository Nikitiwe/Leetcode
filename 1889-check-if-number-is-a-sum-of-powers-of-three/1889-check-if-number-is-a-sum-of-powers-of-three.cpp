class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n>0)
        {
            if (n%3==2) return 0;
            n=n/3;
        }
        return 1;
    }
};