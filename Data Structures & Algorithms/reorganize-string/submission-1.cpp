class Solution {
public:
    string reorganizeString(string s) {
        array<int, 26> freq{};
        priority_queue<pair<int, char>> pq;

        for(char c : s){
            ++freq[c - 'a'];
        }

        for(int i = 0; i < 26; ++i){
            if(freq[i] != 0){
                pq.emplace(freq[i], static_cast<char>('a' + i));
            }
        }

        string ans;
        pair<int, char> prev(0, ' ');

        while(!pq.empty()){
            pair<int, char> current = pq.top();
            pq.pop();

            ans += current.second;
            --current.first;

            if(prev.first > 0){
                pq.push(prev);
            } 

            prev = current;
        }

        return prev.first == 0 ? ans : "";        
    }
};