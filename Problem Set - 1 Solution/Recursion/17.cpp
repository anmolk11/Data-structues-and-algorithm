    vector<string> key = {
        "","","abc","def","ghi","jkl","mno",
        "pqrs","tuv","wxyz"
    };

    vector<string> dfs(string digits) {
        
        int N = digits.length();
        if(N == 0) return {""};

        vector<string> next = dfs(digits.substr(1));

        int curr = digits[0] - '0';


        string keys = key[curr];

        vector<string> Ans;

        for(auto &k : keys){
            for(auto &comb : next){
                Ans.push_back(k + comb);
            }
        }
        return Ans;
    }

    vector<string> letterCombinations(string digits) {
        
        int N = digits.length();
        if(N == 0) return {};

        return dfs(digits);
    }