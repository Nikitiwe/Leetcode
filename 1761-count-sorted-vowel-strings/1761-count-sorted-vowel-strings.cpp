class Solution {
public:
    int countVowelStrings(int n) {
        return (n-1)*(n-2)*(n-3)*(n-4)/24+(n-1)*(n-2)*(n-3)*5/6+(n-1)*(n-2)*5+(n-1)*10+5;
    }
};