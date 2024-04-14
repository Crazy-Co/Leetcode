// initilization block // runs x10 faster than normal code
int init = [] {
	cin.tie(nullptr)->sync_with_stdio(false);
    freopen("user.out", "w", stdout);

    for (string s; getline(cin, s); cout << '\n') {
        int solution = 0, minPrice = INT_MAX;
        for (int _i = 1, _n = s.length(); _i < _n; ++_i) {
            int price = s[_i++] & 15;
            while ((s[_i] & 15) < 10) price = price * 10 + (s[_i++] & 15);
            minPrice = min(minPrice, price);
            solution = max(solution, price - minPrice);
        }
        cout << solution;
    }
    //exit(0);
    return 0;
}();

// normal code
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int profit = 0;
        // int mini = prices[0];
        // for(int i=0; i<prices.size(); i++){
        //     profit = max(prices[i] - mini, profit);
        //     mini = min(prices[i], mini);
        // }
        // return profit;
        return 0;
    }
};