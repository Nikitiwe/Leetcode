class Solution {
public:
    int numberOfRounds(string loginTime, string logoutTime) {
        int hours=(loginTime[0]-'0')*10+loginTime[1]-'0',
            minutes=(loginTime[3]-'0')*10+loginTime[4]-'0',
            hourf=(logoutTime[0]-'0')*10+logoutTime[1]-'0',
            minutef=(logoutTime[3]-'0')*10+logoutTime[4]-'0';
        int f=0;
        if (hours<hourf||(hours==hourf&&minutes<=minutef))
            if ((hourf-hours)*60+minutef-minutes<15) return 0;
        else if ((24-hours)*60-minutes+hourf*60+minutef<15) return 0;
        while (minutes%15!=0) {minutes++; f=1;}
        if (minutes==0&&f==1) hours++;
        if (hours==24) hours=0;
        while (minutef%15!=0) minutef--;
        if (hours<hourf||(hours==hourf&&minutes<=minutef)) return (hourf-hours)*4+minutef/15-minutes/15;
        else return (24-hours)*4-minutes/15+hourf*4+minutef/15;
    }
};