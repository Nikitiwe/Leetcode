class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum=0;
        double s=0;
        int c=0;
        priority_queue<double> m;
        for (int i=0; i!=nums.size(); i++)
        {
            sum+=nums[i];
            m.push((double)nums[i]);
        }
        sum/=2;
        while (1)
        {
            c++;
            double t=m.top()/2;
            m.pop();
            s+=t;
            if (s>=sum) return c;
            m.push(t);
        }
        return -1;
    }
};