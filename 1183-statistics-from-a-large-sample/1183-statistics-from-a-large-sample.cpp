class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double mi=0, ma=255, mo=0, me;
        for (int i=0; i!=count.size(); i++)
        {
            if (count[i]!=0) {mi=i; break;}
        }
        for (int i=0; i!=count.size(); i++)
        {
            if (count[i]>count[mo]) mo=i;
        }
        for (int i=count.size()-1; i>=0; i--)
        {
            if (count[i]!=0) {ma=i; break;}
        }
        long long sum=0, c=0, temp=0, c1;
        for (long long i=0; i!=count.size(); i++)
        {
            c+=count[i];
            sum+=count[i]*i;
        }
        c1=c;
        if (c%2==1)
        {
            c/=2;
            for (int i=0; i!=count.size(); i++)
            {
                temp+=count[i];
                if (temp>c) {me=i; break;}
            }
        }
        else
        {
            c/=2;
            for (int i=0; i!=count.size(); i++)
            {
                temp+=count[i];
                if (temp>c) {me=i; break;}
                if (temp==c)
                {
                    int t=i+1;
                    while (count[t]==0) t++;
                    me=((double)i+t)/2;
                    break;
                }
            }
        }
        return {mi, ma, (double)sum/c1, me, mo};
    }
};