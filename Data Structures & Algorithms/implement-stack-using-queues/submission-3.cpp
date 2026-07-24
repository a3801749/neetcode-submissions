class MyStack {
public:
    queue<int> in;
    queue<int> out;
    MyStack() {
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        int result;

        while (in.size() > 1) {
            out.push(in.front());
            in.pop();
        }

        result = in.front();
        in.pop();

        while (out.size() > 0) {
            in.push(out.front());
            out.pop();
        }

        return result;
    }
    
    int top() {
        int result;

        while (in.size() > 1) {
            out.push(in.front());
            in.pop();
        }

        result = in.front();
        out.push(in.front());
        in.pop();

        while (out.size() > 0) {
            in.push(out.front());
            out.pop();
        }

        return result;
    }
    
    bool empty() {
        return (in.size() == 0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */