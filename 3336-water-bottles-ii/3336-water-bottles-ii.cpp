class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int emp=0, ans=0;
        while (numBottles>0||emp>=numExchange)
        {
            ans+=numBottles;
            emp+=numBottles;
            numBottles=0;
            if (emp>=numExchange)
            {
                emp-=numExchange;
                numBottles++;
                numExchange++;
            }
        }
        return ans;
    }
};