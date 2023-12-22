#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> numbers;
    int vSize;

    void calc(int x) {
        numbers.push_back(x);
    }

    int getMin() {
        int vMin = numbers[0];
        for (int i = 0; i < numbers.size(); i++) {
            if (numbers[i] < vMin) {
                vMin = numbers[i];
            }
        }
        return vMin;
    }

    int buyChoco(vector<int>& prices, int money) {
        int flag = 0;

        for (int i = 0; i < prices.size(); i++) {
            for (int j = 0; j < prices.size(); j++) {
                if (i == j) {
                    continue;
                }
                if (prices[i] + prices[j] <= money) {
                    flag = 1;
                    calc(prices[i] + prices[j]);
                }
            }
        }

         if (flag == 1) {
            return money - getMin(); // Return the maximum value ( remaining amount of money)
        } else {
            return money; // Return original money if no valid combination found
        }
    }

};

int main() {
    Solution s1;
    vector<int> vec1 = {54, 6, 34, 66, 52};
    vector<int>& vec2 = vec1;
    cout<<s1.buyChoco(vec2, 62);    // prints 22
    return 0;
}
