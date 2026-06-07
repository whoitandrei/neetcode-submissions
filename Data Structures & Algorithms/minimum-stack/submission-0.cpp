class MinStack {
private:
    vector<int> data_;
    vector<int> mins_;
public:
    MinStack() = default;
    
    void push(int val) {
        data_.push_back(val);
        auto minValue = min(val, mins_.empty() ? val : mins_.back());
        mins_.push_back(minValue);
    }
    
    void pop() {
        data_.pop_back();
        mins_.pop_back();
    }
    
    int top() {
        return data_.back();
    }
    
    int getMin() {
        return mins_.back();
    }
};
