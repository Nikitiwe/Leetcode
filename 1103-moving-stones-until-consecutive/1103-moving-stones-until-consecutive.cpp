class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        if (a>b) swap (a, b);
        if (a>c) swap (a, c);
        if (b>c) swap (c, b);
        int mi;
        if (c-b==1&&b-a==1) mi=0;
        else if (c-b==1||b-a==1||c-b==2||b-a==2) mi=1;
        else mi=2;
        return {mi, c-a-2};
    }
};