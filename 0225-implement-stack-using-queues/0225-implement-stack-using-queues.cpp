class MyStack {
public:
    MyStack() {}

    void push(int x) {
        temp1.push(x);
    }
    
    int pop() {
        if (temp1.empty()) return -1; 

        while (temp1.size() > 1) {
            temp2.push(temp1.front());
            temp1.pop();
        }

        int topElement = temp1.front();
        temp1.pop();

        swap(temp1, temp2);
        return topElement;
    }
    int top() {
        if (temp1.empty()) return -1; 
        while (temp1.size() > 1) {
            temp2.push(temp1.front());
            temp1.pop();
        }
        int topElement = temp1.front();
        temp2.push(temp1.front());
        temp1.pop();
        swap(temp1, temp2);
        return topElement;
    }
    
    bool empty() {
        return temp1.empty();
    }
    queue<int> temp1;
    queue<int> temp2;
};
