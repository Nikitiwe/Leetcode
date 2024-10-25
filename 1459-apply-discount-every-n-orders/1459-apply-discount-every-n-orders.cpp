class Cashier {
private:
    int n, d, c;
    unordered_map<int, int> m;
public:
    Cashier(int nn, int discount, vector<int>& p, vector<int>& prices) {
        n=nn;
        d=discount;
        for (int i=0; i!=p.size(); i++) m[p[i]]=prices[i];
        c=0;
    }
    
    double getBill(vector<int> p, vector<int> a) {
        c++;
        double ans=0;
        for (int i=0; i!=p.size(); i++)
        {
            ans+=m[p[i]]*a[i];
        }
        if (c==n)
        {
            ans*=(double)(100-d)/100;
            c-=n;
        }
        return ans;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */