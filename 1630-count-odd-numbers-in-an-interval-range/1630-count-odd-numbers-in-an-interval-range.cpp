class Solution {
public:
    int countOdds(int a, int b) {
        if (b%2==1&&a%2==1) return (b-a)/2+1;
        else if (b%2==0&&a%2==0) return (b-a)/2;
        else return (b-a+1)/2;        
    }
};