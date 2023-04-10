    int minDays(vector<int>& bloomDay, int m, int k) {
        auto valid = [&](int days){
            int count = 0,curr = 0;
            for(auto &i : bloomDay){
                if(i <= days) ++curr;
                else curr = 0;

                if(curr == k){
                    ++count;
                    curr = 0;
                }
            }
            return count >= m;
        };

        int i = 0,j = INT_MAX;
        while(i + 1 < j){
            int m = i + (j - i)/2;
            if(valid(m)) j = m;
            else i = m;
        }   
        return j == INT_MAX ? -1 : j;
    }