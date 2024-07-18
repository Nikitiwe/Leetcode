class Solution {
public:
    int checkRecord(int n) {
        long long prev0ALL=0, prev0A=1, prev1ALL=0, prev1A=1, prev1AL=0, prev0AL=1,
                  next0ALL=0, next0A=0, next1ALL=0, next1A=0, next1AL=0, next0AL=0;
        for (int i=1; i!=n; i++)
        {
            next0ALL=prev0AL;
            next0A=prev0A+prev0ALL+prev0AL;
            next1ALL=prev1AL;
            next1A=prev1A+prev0A+prev0ALL+prev1AL+prev0AL+prev1ALL;
            next1AL=prev1A;
            next0AL=prev0A;

            prev0ALL=next0ALL%1000000007;
            prev0A=next0A%1000000007;
            prev1ALL=next1ALL%1000000007;
            prev1A=next1A%1000000007;
            prev1AL=next1AL%1000000007;
            prev0AL=next0AL%1000000007;
        }
        return (prev0ALL+prev0A+prev1ALL+prev1A+prev1AL+prev0AL)%1000000007;
    }
};