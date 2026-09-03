class Solution {
public:
    vector<int> solve(string expression) {

        vector<int> ans;

        for (int i = 0; i < expression.size(); i++) {

            char ch = expression[i];

            if (ch == '+' || ch == '-' || ch == '*') {

                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);

                vector<int> leftAns = solve(left);
                vector<int> rightAns = solve(right);

                for (int x : leftAns) {
                    for (int y : rightAns) {

                        if (ch == '+')
                            ans.push_back(x + y);

                        else if (ch == '-')
                            ans.push_back(x - y);

                        else
                            ans.push_back(x * y);
                    }
                }
            }
        }
        if (ans.empty()) {
            ans.push_back(stoi(expression));
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};