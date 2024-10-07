class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num==1) return 0;
        int sum=1, mind;
        for (int i=2; i<=num/2; i++)
        {
            if (num%i==0)
            {
                mind=i;
                break;
            }
        }
        for (int i=2; i<=num/mind; i++) if (num%i==0) sum+=i;
        if (sum==num) return 1;
        else return 0;
    }
};
