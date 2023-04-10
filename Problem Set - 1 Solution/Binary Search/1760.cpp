    int minimumSize(vector<int>& nums, int maxOperations) {
        auto valid = [&](int pan){
            int ops = 0;
            for(auto &i : nums){
                if(i >= pan){
                    if(i % pan == 0) ops += (i/pan - 1);
                    else ops += i/pan;
                }
            }
            return ops <= maxOperations;
        };

        int i = 0,j = *max_element(begin(nums),end(nums)) + 1;
        while(i + 1 < j){
            int m = i + (j - i)/2;
            if(valid(m)) j = m;
            else i = m;
        }
        return j;
    }