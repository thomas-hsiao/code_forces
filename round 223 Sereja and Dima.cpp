#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>

class Sol {
private:
    int n;
    std::vector<int> cards;
public:
    Sol(int n, std::vector<int> cards) : n{n}, cards{std::move(cards)} {}

    void work() {
        std::vector<int> ans(2, 0);
        int l = 0;
        int r = n - 1;
        bool dima_turn = false;

        while (l <= r) {
            if (cards[r] > cards[l]) {
                ans[dima_turn] += cards[r];
                --r;
            } else {
                ans[dima_turn] += cards[l];
                ++l;
            }

            dima_turn = !dima_turn;
        }

        std::cout << ans[0] << ' ' << ans[1];   
    }
};

int main() {
        
    int n = 0;
    std::string tmp;

    std::cin >> n;
    std::cin.ignore();
    std::getline(std::cin, tmp);

    std::vector<int> cards;

    std::stringstream ss(tmp);
    
    int val;
    while (ss >> val) {
        cards.push_back(val);
    }

    Sol sol(n, cards);
    
    sol.work();

    return 0;
}
