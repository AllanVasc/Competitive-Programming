class MovingAverage {
    int total_sum = 0;
    int max_size = 0;
    int curr_size = 0;
    queue<int> q;
public:
    MovingAverage(int size) {
        max_size = size;
    }
    
    double next(int val) {
        total_sum += val;
        if(curr_size != max_size){
            curr_size++;
            q.push(val);
            return total_sum/double(curr_size);
        }
        else{
            total_sum -= q.front();
            q.pop();
            q.push(val);
            return total_sum/double(curr_size);
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */