/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main(){
    int idade;
    
    printf("digite sua idade: ");
    scanf("%d", &idade);
    
    if(idade>= 65){
        printf("vá beber no buteco");
    }else if(idade>= 18){
        printf("entre e se divirta");
    }else if(idade< 12){
        printf("chora");
    }else{
        printf("espia");
    }
    
    
    return 0;
}

