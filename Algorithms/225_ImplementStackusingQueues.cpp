class Stack {
public:
    // Push element x onto stack.
    void push(int x) 
    {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() 
    {
        queue<int> tmp;
        while(q.size() > 1)
        {
            tmp.push(q.front());
            q.pop();
        }
        q = tmp;
    }

    // Get the top element.
    int top() 
    {
        queue<int> tmp;
        int res;
        while(!q.empty())
        {
            if(q.size() == 1)
                res = q.front();
            tmp.push(q.front());
            q.pop();
        }
        q = tmp;
        return res;
    }

    // Return whether the stack is empty.
    bool empty() 
    {
        return q.empty();
    }

private:
    queue<int> q;
};
