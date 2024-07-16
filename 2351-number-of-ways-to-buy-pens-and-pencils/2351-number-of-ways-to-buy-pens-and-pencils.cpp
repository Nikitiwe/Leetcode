class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
            long long ans=0, i=0;
            if (cost2<cost1) swap (cost2, cost1);
            while (total>=0)
            {
                ans+=total/cost1;
                ans++;
                total-=cost2;
            }
            return ans;
    }
};