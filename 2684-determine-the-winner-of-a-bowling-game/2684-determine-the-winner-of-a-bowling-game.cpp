class Solution {
public:
    int isWinner(vector<int>& p1, vector<int>& p2) {
        int sum1=p1[0], sum2=p2[0];
        if (p1.size()>1)
        {
            if (p1[0]==10) sum1+=2*p1[1];
            else sum1+=p1[1];
        }
        for (int i=2; i<p1.size(); i++)
        {
            if ((p1[i-1]==10)||(p1[i-2]==10)) sum1+=2*p1[i];
            else sum1+=p1[i];
        }
        if (p2.size()>1)
        {
            if (p2[0]==10) sum2+=2*p2[1];
            else sum2+=p2[1];
        }
        for (int i=2; i<p2.size(); i++)
        {
            if ((p2[i-1]==10)||(p2[i-2]==10)) sum2+=2*p2[i];
            else sum2+=p2[i];
        }
        if (sum1>sum2) return 1;
        else if (sum1<sum2) return 2;
        else return 0;
    }
};