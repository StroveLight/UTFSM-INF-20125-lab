#include <iostream>
#include <new>

void recursivo(int n){
	if (n == 0){
		throw std::invalid_argument("valor 0");
		return;
	}
	recursivo(n-1);
}

int main(void) 
{
	try {
		recursivo(5);
	}
	catch (const std::invalid_argument& error){
		std::cout << "Ocurrió error en recursivo(5)" << std::endl;
		throw error;
	}
	return 0;
}
