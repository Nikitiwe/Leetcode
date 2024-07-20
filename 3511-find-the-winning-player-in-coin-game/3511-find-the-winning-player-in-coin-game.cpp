class Solution {
public:
    string losingPlayer(int x, int y) {
        int a=0;
        while (x>0&&y>3)
        {
            x-=1;
            y-=4;
            a++;
        }
        if (a%2==1) return "Alice";
        else return "Bob";
    }
};