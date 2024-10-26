class Solution {
public:
    int splitNum(int num) {
        vector<int> arr(10, 0);
        while (num>0)
        {
            arr[num%10]++;
            num/=10;
        }
        int x=0, y=0;
        string s;
        for (int i=0; i!=10; i++)
        {
            while (arr[i]>0)
            {
                arr[i]--;
                s+='0'+i;
            }
        }
        for (int i=0; i!=s.size(); i++)
        {
            if (i%2==0)
            {
                x*=10;
                x+=s[i]-'0';
            }
            else
            {
                y*=10;
                y+=s[i]-'0';
            }
        }
        return x+y;
    }
};