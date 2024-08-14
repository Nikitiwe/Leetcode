class Solution {
public:
    int countCollisions(string directions) {
        int ans = 0, l = 0;
        for (int i=0; i!=directions.size(); i++)
        {
            if (directions[i]!='S') ans++;
        }
        while (l<directions.size()&&directions[l]=='L') {ans--; l++;}
        l=directions.size()-1;
        while (l>=0&&directions[l]=='R') {ans--; l--;}
        return ans;
    }
};