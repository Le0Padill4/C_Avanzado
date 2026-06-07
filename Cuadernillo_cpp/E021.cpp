#include <iostream>

int main(){
    std:: string palabra;
    std::cin>>palabra;
    int cont=0;
    for(int i=0; i<palabra.size();i++){
        if(palabra[i]=='a' or palabra[i]=='e' or palabra[i]=='i' or palabra[i]=='o' or palabra[i]=='u'){
            cont++;
        }
    }
    std::cout<<"Vocales: "<<cont<<std::endl;

    return 0;
}