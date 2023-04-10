    int shipWithinDays(vector<int>& weights, int days) {
        int i = 1,j = INT_MAX;
        
        auto valid = [&](int capacity){
            int count = 1,curr = 0;
            for(auto &i : weights){
                if(i > capacity) return false;
                if(i + curr <= capacity) curr += i;
                else{
                    curr = i;
                    ++count;
                }
            }
            return count <= days;
        };

        while(i + 1 < j){
            int m = i + (j - i)/2;
            if(valid(m)) j = m;
            else i = m;
        }
        return j;
    }