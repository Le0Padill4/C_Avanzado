#include <iostream>

int* buscarValor(int* arr, int n, int valor){
    for (int i = 0; i < n; ++i) {
        if (arr[i] == valor) {
            return &arr[i]; 
        }
    }
    return nullptr;
}

int main(){
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int valor;
    std::cout << "Ingrese un numero a buscar: ";
    std::cin >> valor;
    int* resultado = buscarValor(arr, 7, valor);
    if(resultado != nullptr){
        std::cout << "El numero se encuentra en la posicion: " << (resultado - arr) << std::endl;
    } else {
        std::cout << "El numero no se encuentra en el arreglo." << std::endl;
    }

    return 0;
}