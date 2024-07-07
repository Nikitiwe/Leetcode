class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=0, t=0;
        while (t+numBottles>=numExchange||numBottles>0)
        {
            ans+=numBottles;
            t+=numBottles;
            numBottles=t/numExchange;
            t=t%numExchange;
        }
        return ans;
    }
};