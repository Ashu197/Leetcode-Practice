class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if (num.empty()) {
            return ans;
        }
        for (int i = 1; i <= num.size(); i++) {
            string s = num.substr(0, i);
            long v = stol(s);
            if (to_string(v).size() != s.size()) {
                continue;
            }
            add(ans, num, target, s, i, v, v, '*');
        }
        return ans;
    }
private:
    void add(vector<string>& ans, string num, int target, string s, int i, long cv, long pv, char op) {
        if (i == num.size() && cv == target) {
            ans.push_back(s);
        } else {
            for (int j = i + 1; j <= num.size(); j++) {
                string t = num.substr(i, j - i);
                long v = stol(t);
                if (to_string(v).size() != t.size()) {
                    continue;
                }
                add(ans, num, target, s + '+' + t, j, cv + v, v, '+');
                add(ans, num, target, s + '-' + t, j, cv - v, v, '-');
                if (op == '+') {
                    add(ans, num, target, s + '*' + t, j, cv - pv + pv * v, pv * v, op);
                } else if (op == '-') {
                    add(ans, num, target, s + '*' + t, j, cv + pv - pv * v, pv * v, op);
                } else {
                    add(ans, num, target, s + '*' + t, j, cv * v, pv * v, op);
                }
            }
        }
    }
};