class MyStack {
public:
    queue<int> q1, q2;
    MyStack(){}

    void push(int x){
        q1.push(x);
        while (!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        swap(q2,q1);
    }

    int pop(){
        int ret = q2.front();
        q2.pop();
        return ret;
    }

    int top() {
        return q2.front();
    }

    bool empty(){
        if(q2.size()) return false;
        return true;
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