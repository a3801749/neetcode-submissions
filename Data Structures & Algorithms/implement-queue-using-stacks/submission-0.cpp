class MyQueue {
public:
    stack<int> in;
    stack<int> out;
    MyQueue() {    
    }
    
    void push(int x) {
        in.push(x);   
    }
    
    int pop() {
        int result;

        while (in.size() > 1) {
            out.push(in.top());
            in.pop();
        }

        result = in.top();
        in.pop();

        while (out.size() > 0) {
            in.push(out.top());
            out.pop();
        }

        return result; 
    }
    
    int peek() {
        int result;

        while (in.size() > 1) {
            out.push(in.top());
            in.pop();
        }

        result = in.top();
        out.push(in.top());
        in.pop();

        while (out.size() > 0) {
            in.push(out.top());
            out.pop();
        }

        return result;
    }
    
    bool empty() {
        return (in.size() == 0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */