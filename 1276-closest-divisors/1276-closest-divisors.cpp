class Solution {
public:
    vector<int> closestDivisors(int num) {
        int ans1, ans2, a;
        a=sqrt(num+1);
        while (1)
        {
            if ((num+1)%a==0) {ans1=a; ans2=(num+1)/a; break;}
            else a--;
        }
        a=sqrt(num+2);
        while (1)
        {
            if ((num+2)%a==0) {if((num+2)/a-a<ans2-ans1) {ans1=a; ans2=(num+2)/a;} else break;}
            else a--;
        }
        return {ans1, ans2};
    }
};