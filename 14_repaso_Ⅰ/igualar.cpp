#include <iostream>
#include <vector>
#include "utils/sort.hpp"

int main() {
    std::vector<int> S;
    int cantidad_N, cantidad_K, temp;
    std::cin >> cantidad_N;

    int N[cantidad_N] = {0};

    for (int i = 0; i < cantidad_N; i++) {
        std::cin >> N[i];
    }

    // S.push_back(i)

    sort(N, cantidad_N);

    std::cout << "N ordenado: ";
    for (int num : N) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
