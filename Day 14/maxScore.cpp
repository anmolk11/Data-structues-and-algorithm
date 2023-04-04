// Problem link : https://leetcode.com/problems/maximum-score-words-formed-by-letters/
class Solution {
public:
    int Ans = 0;
    vector<int> score;
    int Hash[26] = {0};
    
    void include(string &A){
        for(auto &i : A) Hash[i - 'a']--;
    }

    void remove(string &A){
        for(auto &i : A) Hash[i - 'a']++;
    }

    int Score(string &A){
        int x = 0;
        for(auto &i : A) x += score[i - 'a'];
        return x;
    }

    bool valid(string &A){
        int hash[26] = {0};
        for(auto &i : A) hash[i - 'a']++;

        for(int i = 0;i < 26;i++){
            if(hash[i] > Hash[i]) return false;
        }
        return true;
    }

    void dfs(vector<string> &words,int i,int points){
        if(i == words.size()){
            Ans = max(Ans,points);
            return;
        }

        if(valid(words[i])){
            include(words[i]);
            int scr = Score(words[i]);
            dfs(words,i + 1,points + scr);   
            remove(words[i]);
        }
        dfs(words,i + 1,points);
    }


    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        this->score = score;
        for(auto &i : letters) Hash[i - 'a']++;
        dfs(words,0,0);
        return Ans;
    }
};