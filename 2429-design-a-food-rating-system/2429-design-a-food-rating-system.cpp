string rev(string &s)
{
    string ans = "";
    for (int i=0; i!=s.size(); i++)
    {
        ans += char(255 - s[i]);
    }
    return ans;
}

class FoodRatings {
public:
    unordered_map<string, int> r;
    unordered_map<string, priority_queue<pair<int, string>>> t;
    unordered_map<string, string> c;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i=0; i!=foods.size(); i++)
        {
            r[foods[i]] = ratings[i];
            t[cuisines[i]].push({ratings[i], rev(foods[i])});
            c[foods[i]] = cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        r[food] = newRating;
        t[c[food]].push({newRating, rev(food)});
    }
    
    string highestRated(string cuisine) {
        while (1)
        {
            auto [rat, foo] = t[cuisine].top();
            foo = rev(foo);
            if (r[foo] == rat) return foo;
            t[cuisine].pop();
            //t[cuisine].push({r[foo], rev(foo)});
        }
        return "";
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */