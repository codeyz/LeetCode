class MinStack {
public:
    void push(int x) {
        s.push_back(x);
        if(s.size() == 1)
            lmin = x;
        else
            lmin = min(lmin, x);
    }

    void pop() {
        int tmp = top();
        s.pop_back();
        if(tmp == lmin && !s.empty())
        {
            lmin = s[0];
            for(size_t i = 1; i < s.size(); ++i)
                lmin = min(lmin, s[i]);
        }
    }

    int top() {
        return s[s.size() - 1];
    }

    int getMin() {
        return lmin;
    }
private:
    vector<int> s;
    int lmin;
};
