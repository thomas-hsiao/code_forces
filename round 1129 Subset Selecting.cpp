#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>

class Sol {
private:
    int n;
    int k;
    std::vector<int> count;
public:
    Sol(int n, int k, std::vector<int> count) : n{n}, k{k}, count{std::move(count)} {}

    void work() {
         int v = 0;
         long long prefix_sum = 0;
         
         for (int x = 0; x <= n; ++x) {
            if (count[x] < 1) break; 
                prefix_sum += count[x];
              
            if (prefix_sum < (long long)(x + 1) * k) {
                break;
            }
            v = x + 1;
          }

          std::cout << v << "\n";
    }
};

int main() {
    int cases = 0;
    std::cin >> cases;
    std::cin.ignore();
    
    for (int i = 0; i < cases; ++i) {
      int n = 0;
      int k = 0;
      std::string tmp;
      
      std::cin >> n >> k;
      std::cin.ignore(100, '\n');
      std::getline(std::cin, tmp);

      std::vector<int> count(n + 1, 0);
      std::stringstream ss(tmp);
      int val = 0;
      
      while (ss >> val) {
          count[val]++;
      }

      Sol sol(n, k, count);
      sol.work();
    }

    return 0;
}
