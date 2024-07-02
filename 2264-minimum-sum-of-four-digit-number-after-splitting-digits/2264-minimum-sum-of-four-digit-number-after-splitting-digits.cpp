class Solution {
public:
    int minimumSum(int num) {
        vector<int> a={num/1000, (num/100)%10, (num/10)%10, num%10};
        sort(a.begin(), a.end());
        return 10*a[0]+10*a[1]+a[2]+a[3];
    }
};