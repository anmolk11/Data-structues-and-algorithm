class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people),end(people));
        int Ans = 0;

        int i = 0,j = people.size() - 1;

        while(i <= j){
            if(people[i] + people[j] <= limit){
                ++Ans;
                i++;
                j--;
            }
            else{
                j--;
                ++Ans;
            }
        }

        return Ans;
    }
};