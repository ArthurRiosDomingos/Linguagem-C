/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main(){
        
    char cv , ce , cf;
    char menu;
    printf ("Digite: \n 1) - Controle de Vendas\n 2) - Controle de Estoque \n 3) - Controle financeiro \n 4) - Voltar \n \n "); 
    scanf(" %c", &menu);
    switch(menu){
        
        case '1':
        printf("\n Bem Vindo ao Controle de vendas!");
        while(1){
            printf(" \n Digite: \n 1) - Colocar Preço\n 2) - Visualizar preço\n 3) - Voltar ao menu principal ");
            scanf("%c", &cv);
            

            
            if(cv == '1'){
                printf("Digite:");
            }else if(cv == '2'){
                printf("demnasdmn");
            }
        }
        
        break;
    }
        switch(menu){    
        case '2':
            printf("\n Bem Vindo ao Controle de Estoque!");
            break;
        }
        switch(menu){
        case '3':
            printf("\n Bem Vindo ao Controle Financeiro!");
            break;
        
        case '4':
            printf("Voltar");
            break;
        
        default:
            printf("\nOpção invalida");
            break;
    }
    
    
    
    return 0;
}