class Robot {
private:
    int d, x, y, w, h;
public:
    Robot(int ww, int hh) {
        d=0, y=0, x=0, w=ww, h=hh;
    }
    
    void step(int n) {
        while (n>0)
        {
            if (x==0&&y==0&&d==0&&n>2*(w+h)-4)
            {
                n%=2*(w+h)-4;
                d=3;
            }
            else if (d==0)
            {
                int t=min(n, w-1-x);
                x+=t;
                n-=t;
                if (n>0) d++;
            }
            else if (d==1)
            {
                int t=min(n, h-1-y);
                y+=t;
                n-=t;
                if (n>0) d++;
            }
            else if (d==2)
            {
                int t=min(n, x);
                x-=t;
                n-=t;
                if (n>0) d++;
            }
            else
            {
                int t=min(n, y);
                y-=t;
                n-=t;
                if (n>0) d=0;
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        if (d==0) return "East";
        else if (d==1) return "North";
        else if (d==2) return "West";
        else return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */