class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long temp=0, mint=0, maxt=0;
        for (int i=0; i!=differences.size(); i++)
        {
            temp+=differences[i];
            mint=min(mint, temp);
            maxt=max(maxt, temp);
        }
        if (upper-lower<maxt-mint) return 0;
        else return upper-lower-(maxt-mint)+1;
    }
};