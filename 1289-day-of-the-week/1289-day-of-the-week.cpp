class Solution {
public:
    string dayOfTheWeek(int d, int m, int y) {
        int s=d;
        s+=365*(y-1971);
        int yy=1972;
        while (yy<y)
        {
            s++;
            yy+=4;
        }
        if (m>1)s+=31;
        if (m>2)
        {
            if (y%4==0&&y!=2100) s++;
            s+=28;
        }
        if (m>3) s+=31;
        if (m>4) s+=30;
        if (m>5) s+=31;
        if (m>6) s+=30;
        if (m>7) s+=31;
        if (m>8) s+=31;
        if (m>9) s+=30;
        if (m>10) s+=31;
        if (m>11) s+=30;
        s%=7;
        if (s==1) return "Friday";
        if (s==2) return "Saturday";
        if (s==3) return "Sunday";
        if (s==4) return "Monday";
        if (s==5) return "Tuesday";
        if (s==6) return "Wednesday";
        return "Thursday";
    }
};