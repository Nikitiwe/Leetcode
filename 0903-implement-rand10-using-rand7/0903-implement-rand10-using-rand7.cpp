// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int temp=(rand7()-1)*7+rand7();
        if (temp<41) return temp%10+1;
        else return rand10();
    }
};