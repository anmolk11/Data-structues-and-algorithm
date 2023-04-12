class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int N = capacity.size();
        for(int i = 0;i < N;i++){
            capacity[i] -= rocks[i];
        }
        int Ans = 0;

        sort(begin(capacity),end(capacity));
        
        for(int i = 0;i < N;i++){
            if(capacity[i] <= additionalRocks){
                ++Ans;
                additionalRocks -= capacity[i];
            }
            else break;
        }
        return Ans;
    }
};