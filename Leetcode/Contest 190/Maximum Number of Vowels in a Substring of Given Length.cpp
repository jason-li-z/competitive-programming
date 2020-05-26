class Solution {
public:
    int maxVowels(string s, int k) {
        int windowStart = 0;
        int max_count = 0;
        unordered_map<char, bool> mp;
        mp['a'] = true;
        mp['e'] = true;
        mp['i'] = true;
        mp['o'] = true;
        mp['u'] = true;
        int running = 0;
        for(int windowEnd = 0; windowEnd < s.size(); windowEnd++) {
            char current = s[windowEnd];
            
            if(mp.find(current) != mp.end()) {
                running++;
            }
            
            if(windowEnd - windowStart + 1 > k) {
                char left = s[windowStart];
                if(mp.find(left) != mp.end()) {
                    running--;
                }
                windowStart++;
            }
            
            max_count = max(running, max_count);
        }
        
        return max_count;
        
    }
};
