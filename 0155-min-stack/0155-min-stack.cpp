class MinStack {
public:
    stack<int> og;
    stack<int> minstack;
    MinStack() {
        
    }
    void push(int val) {
        if(og.empty()){
            og.push(val);
            minstack.push(val);
            return;
        }
        og.push(val);
        if(minstack.empty() || minstack.top() >= val){
            minstack.push(val);
        }
    }
    
    void pop() {
        if(og.top() == minstack.top()){
            og.pop();
            minstack.pop();
            return;
        }
        og.pop();
    }
    
    int top() {
        return og.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */