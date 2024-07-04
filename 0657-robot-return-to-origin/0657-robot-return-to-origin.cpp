class Solution {
public:
    bool judgeCircle(string moves) {
        int lr=0, ud=0;
        for (int i=0; i!=moves.size(); i++)
        {
            if (moves[i]=='L') lr++;
            else if (moves[i]=='R') lr--;
            else if (moves[i]=='U') ud++;
            else ud--;
        }
        if (lr==0&&ud==0) return 1;
        else return 0;
    }
};