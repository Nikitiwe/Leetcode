class Solution {
public:
    int f(int m, int d)
    {
        vector<int> arr{31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        int ans = 0;
        if (m-2 >= 0) ans = arr[m-2];
        return ans + d;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int am = (arriveAlice[0] - '0') * 10 + (arriveAlice[1] - '0');
        int ad = (arriveAlice[3] - '0') * 10 + (arriveAlice[4] - '0');
        int bm = (leaveAlice[0] - '0') * 10 + (leaveAlice[1] - '0');
        int bd = (leaveAlice[3] - '0') * 10 + (leaveAlice[4] - '0');
        int cm = (arriveBob[0] - '0') * 10 + (arriveBob[1] - '0');
        int cd = (arriveBob[3] - '0') * 10 + (arriveBob[4] - '0');
        int dm = (leaveBob[0] - '0') * 10 + (leaveBob[1] - '0');
        int dd = (leaveBob[3] - '0') * 10 + (leaveBob[4] - '0');
        int a = max(f(am, ad), f(cm, cd));
        int b = min(f(bm, bd), f(dm, dd));
        if (b - a + 1>= 0) return b - a + 1;
        else return 0;
    }
};