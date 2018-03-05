class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        queues = vector<queue<int>>(2, queue<int>());
        push_idx = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queues[push_idx].push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(queues[push_idx].size() > 1)
        {
            queues[1 - push_idx].push(queues[push_idx].front());
            queues[push_idx].pop();
        }
        int res = queues[push_idx].front();
        queues[push_idx].pop();
        push_idx = 1 - push_idx;
        return res;
    }
    
    /** Get the top element. */
    int top() {
       return queues[push_idx].back(); 
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(queues[0].empty() && queues[1].empty())
        {
            return true;
        }
        return false;
    }
private:
    vector<queue<int>> queues;
    int push_idx;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */