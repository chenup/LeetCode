#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() { 
    }
    
    void push(int x) {
        stack.push_back(x);
        if(minS.size() == 0)
        {
            minS.push_back(stack.size() - 1);
        }
        else
        {
            int idx = minS[minS.size() - 1];
            if(x < stack[idx])
            {
                minS.push_back(stack.size() - 1);
            }
        }
       
    }
    
    void pop() {
        int top = stack.size() - 1;
        if(top == minS[minS.size() - 1])
        {
            minS.pop_back();
        }
        stack.pop_back();
    }
    
    int top() {
       return stack[stack.size() - 1]; 
    }  
    
    int getMin() {
        int idx = minS[minS.size() - 1];
        return stack[idx];
    }

    vector<int> stack;
    vector<int> minS;
};

int main()
{
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout << minStack->getMin() << endl;
    minStack->pop();
    cout << minStack->top() << endl;
    cout << minStack->getMin() << endl;
    return 0;
}
