class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> M;

        for(auto &i : s) M[i]++;

        vector<pair<int,char>> S;

        for(auto [key,value] : M){
            S.push_back({value,key});
        }

        sort(rbegin(S),rend(S));

        string Ans;

        for(auto [first,second] : S){
            int freq = first;
            while(freq--){
                Ans.push_back(second);
            }
        }
        return Ans;
    }
};