#include <iostream>
#include <vector>
#include "utils/sort.hpp"

int es_factible(int N[],  std::vector<int> K, int cantidad_N){
    for (int delta=0; delta<100; delta++){
        int objetivo = N[0] + delta;
        int i = cantidad_N-1;
        for (int num : K) {
            if (i<0) {
                break;
            }
            // printf("%d + %d == %d\n", N[i], num, objetivo);
            if (objetivo == num + N[i])
                i--;
        }
        if (i == -1) return (int)K.size() - 1;
    }
    return -1;
}

int main() {
    int cantidad_N, cantidad_P, cantidad_K, temp;
    std::cin >> cantidad_P;
    while(cantidad_P--){
        std::vector<int> K = {};
        int indice_encontrado = -1;
        std::cin >> cantidad_N >> cantidad_K;

        int N[cantidad_N] = {0};

        for (int i = 0; i < cantidad_N; i++) {
            std::cin >> N[i];
        }
        sort(N, cantidad_N);
        for (int i = 0; i < cantidad_K; i++) {
            std::cin >> temp;
            K.push_back(temp);
            // checkeo
            if (i >= cantidad_N && indice_encontrado == -1){
                sort(K);
                indice_encontrado = es_factible(N, K, cantidad_N);
            }
        }
        std::cout << indice_encontrado << std::endl;
    }
    return 0;
}
