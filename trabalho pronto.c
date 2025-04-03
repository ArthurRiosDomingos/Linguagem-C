#include <stdio.h>

// Variáveis Globais
float totalDespesas = 0.0;
float totalReceitas = 0.0;
float saldoAtual = 0.0;
int totalVendas = 0;

// Funções de Controle Financeiro
void registrarDespesa(float valor) {
    totalDespesas += valor;
    printf("Despesa de R$%.2f registrada com sucesso!\n", valor);
}

void registrarReceita(float valor) {
    totalReceitas += valor;
    printf("Receita de R$%.2f registrada com sucesso!\n", valor);
}

void consultarSaldo() {
    saldoAtual = totalReceitas - totalDespesas;
    printf("Saldo Atual: R$%.2f\n", saldoAtual);
}

// Função para registrar venda
void registrarVenda(int produto, int quantidade) {
    float precos[4] = {10.0, 20.0, 15.0, 25.0};
    if (produto >= 1 && produto <= 4) {
        float total = precos[produto - 1] * quantidade;
        registrarReceita(total);
        totalVendas++;
        printf("Venda registrada: Produto %d, Quantidade: %d, Total: R$%.2f\n", produto, quantidade, total);
    } else {
        printf("Produto inválido!\n");
    }
}

// Função para realizar o pagamento
void realizarPagamento() {
    float totalGeral = totalReceitas + totalDespesas;
    printf("\n==========Pagamento==========\n Consolidado:\n");
    printf(" Vendas - Total: R$%.2f\n", totalReceitas);
    printf(" Controle Financeiro - Total: R$%.2f\n", totalDespesas);
    printf(" Total Geral: R$%.2f\n", totalGeral);
    
    int metodoPagamento;
    printf("\n==========Forma de Pagamento==========\n Escolha a forma de pagamento:\n 1) Dinheiro\n 2) Cartão\n");
    scanf("%d", &metodoPagamento);
    
    if (metodoPagamento == 1) {
        float desconto = 0.0;
        if (totalGeral <= 50.0) {
            desconto = 0.05;
        } else if (totalGeral < 100.0) {
            desconto = 0.10;
        } else {
            desconto = 0.18;
        }
        
        float totalComDesconto = totalGeral * (1 - desconto);
        printf("Desconto aplicado: %.2f%%\n", desconto * 100);
        printf("Total com desconto: R$%.2f\n", totalComDesconto);
        
        float valorRecebido;
        printf("Digite o valor recebido: R$");
        scanf("%f", &valorRecebido);
        
        if (valorRecebido >= totalComDesconto) {
            printf("Troco: R$%.2f\n", valorRecebido - totalComDesconto);
        } else {
            printf("Valor insuficiente. Tente novamente.\n");
            realizarPagamento();
        }
    } else if (metodoPagamento == 2) {
        int pagamentoOk;
        printf("Pagamento na máquina? (1 - Sim, 0 - Não): ");
        scanf("%d", &pagamentoOk);
        
        if (pagamentoOk == 1) {
            printf("Pagamento confirmado!\n");
        } else {
            printf("Pagamento não realizado. Escolha novamente a forma de pagamento.\n");
            realizarPagamento();
        }
    } else {
        printf("Opção inválida. Escolha novamente.\n");
        realizarPagamento();
    }
}
// Inicio do menu principal
int main() {
    char opcaoMenu;
    while (1) {
        printf("\n==========Bem Vindo ao Menu Principal==========\n Digite:\n 1) Controle de Estoque\n 2) Controle de Vendas\n 3) Controle Financeiro\n 4) Pagamento\n 5) Encerrar Programa\n\n");
        scanf(" %c", &opcaoMenu);
        // opcao dos itens disponiveis
        switch (opcaoMenu) {
            case '1':
                printf("\n==========Itens Disponíveis==========\n");
                printf("1 - Produto A - 50 unidades\n");
                printf("2 - Produto B - 30 unidades\n");
                printf("3 - Produto C - 20 unidades\n");
                printf("4 - Produto D - 15 unidades\n");
                break;
            // opcao de itens para venda
            case '2': {
                int produto, quantidade;
                printf("\n==========Itens Disponíveis para Venda==========\n");
                printf("1 - Produto A - R$10,00\n");
                printf("2 - Produto B - R$20,00\n");
                printf("3 - Produto C - R$15,00\n");
                printf("4 - Produto D - R$25,00\n");
                printf("\nDigite o número do produto: ");
                scanf("%d", &produto);
                printf("Digite a quantidade: ");
                scanf("%d", &quantidade);
                registrarVenda(produto, quantidade);
                break;
            }
            // opcoes do financeiro
            case '3': {
                char opcaoFinanceiro;
                printf("\n==========Bem Vindo ao Controle Financeiro==========\n 1) Registrar Despesa\n 2) Registrar Receita\n 3) Consultar Saldo\n 4) Voltar ao Menu\n");
                scanf(" %c", &opcaoFinanceiro);
                if (opcaoFinanceiro == '1') {
                    float despesa;
                    printf("Digite o valor da despesa: R$");
                    scanf("%f", &despesa);
                    registrarDespesa(despesa);
                } else if (opcaoFinanceiro == '2') {
                    float receita;
                    printf("Digite o valor da receita: R$");
                    scanf("%f", &receita);
                    registrarReceita(receita);
                } else if (opcaoFinanceiro == '3') {
                    consultarSaldo();
                }
                break;
            }
            // finalizacao do pagamaaento
            case '4':
                realizarPagamento();
                break;
            // finalizacao do sistema com total de vendas e faturamento
            case '5':
                printf("Saindo do sistema... Total de vendas: %d, Faturamento: R$%.2f\n", totalVendas, totalReceitas);
                return 0;
            // opcoes invalidas do sistema
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }
    return 0;
}
