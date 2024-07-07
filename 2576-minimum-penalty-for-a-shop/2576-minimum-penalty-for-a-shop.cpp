class Solution {
public:
    int bestClosingTime(string customers) {
        int hour=0, m=0, t;
        t=m;
        for (int i=1; i!=customers.size()+1; i++)
        {
            if(customers[i-1]=='Y') t--;
            else t++;
            if (t<m) {m=t; hour=i;}
        }
        return hour;
    }
};