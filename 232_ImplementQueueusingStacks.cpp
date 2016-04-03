class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        s.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(s.empty())
            return;
        s = popAll();
        s.pop();
        s = popAll();
    }

    // Get the front element.
    int peek(void) {
        s = popAll();
        int res = s.top();
        s = popAll();
        return res;
    }
    
    // pop all elements
    stack<int> popAll()
    {
        stack<int> tmp;
        while(!s.empty())
        {
            tmp.push(s.top());
            s.pop();
        }
        return tmp;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }

private:
    stack<int> s;
};
