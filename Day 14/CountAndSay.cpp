// Problem link : https://leetcode.com/problems/count-and-say/description/

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1"; // base case

        string prev = countAndSay(n - 1); // relation

        string Ans;

        int i = 0;
        int N = prev.length();

        while(i < N){
            char x = prev[i];
            int count = 0;
            while(i < N and prev[i] == x){
                ++count;
                ++i;
            }
            Ans += to_string(count) + x;
        }
        return Ans;
    }
};