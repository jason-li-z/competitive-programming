class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(int i = 0; i < time.size(); i++) {
            int remainder = time[i] % 60;
            int diff = (60 - remainder) % 60;
            ans += mp[remainder];
            mp[diff]++;
            
        }
        
        return ans;
        
    }
};