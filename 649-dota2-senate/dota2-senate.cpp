class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r, d;
        int n = senate.size();
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') r.push(i);
            else d.push(i);
        }
        while (!r.empty() && !d.empty()) {
            int rad = r.front(); r.pop();
            int dir = d.front(); d.pop();

            if (rad < dir) {
                r.push(rad + n); 
            } else {
                d.push(dir + n); 
            }
        }

        return r.empty() ? "Dire" : "Radiant";
    }
};
