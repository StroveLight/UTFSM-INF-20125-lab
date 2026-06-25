#include <iostream>
#include <numeric>

int main(){
    int cantidad_problemas, reloj1, reloj2, reloj3;
    std::cin >> cantidad_problemas;
    while(cantidad_problemas--){
        std::cin >> reloj1 >> reloj2 >> reloj3;
        int lcm_1y2 = std::lcm(reloj1, reloj2);
        int lcm = std::lcm(lcm_1y2, reloj3);
        std::cout << lcm << std::endl;
    }
    return 0;
}