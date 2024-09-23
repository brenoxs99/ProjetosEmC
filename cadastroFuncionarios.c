#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define TAM 50
#define L 12
#define C 30

struct MESES
{
    int FLAG_M;
    float Q_HORA;
};

struct FUNCIONARIO
{
    int CODIGO, ANO, FLAG_F;
    char NOME[50], CARGO[30];
    float VALOR_HORA;
    struct MESES meses[L][C];  // Individual array for each employee
} funcionario[TAM];



///--------FUNCOES---------///

void INICIALIZA_FLAG()
{
    int i, j, k;
    
    for (i = 0; i < TAM; i++)
    {
        funcionario[i].FLAG_F = 0;
        
        for (j = 0; j < L; j++)
        {
            for (k = 0; k < C; k++)
            {
                funcionario[i].meses[j][k].FLAG_M = 0;
            }
        }
    }
}


int POSICAO_LIVRE_FLAG_F()
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        if (funcionario[i].FLAG_F == 0)
            return i;
    }
    return -1; // Retorna -1 se todos os ?ndices estiverem ocupados
}


void POSICAO_LIVRE_FLAG_M(int *LINHA, int *COLUNA)
{
    int i, j;
    for (i = 0; i < L; i++)
    {
        for (j = 0; j < C; j++)
        {
            if (funcionario[*LINHA].meses[i][j].FLAG_M == 0)
            {
                *LINHA = i;
                *COLUNA = j;
                return;
            }
        }
    }
    *LINHA = -1; // Retorna -1 se todos os ?ndices estiverem ocupados
    *COLUNA = -1;
}

void CADASTRAR_FUNCIONARIO() //FUNCAO 1
{
    int POSICAO;
    POSICAO = POSICAO_LIVRE_FLAG_F();

    printf("\n\tFICHA DE NUMERO: %d\n", POSICAO + 1);

    srand(time(NULL));

    funcionario[POSICAO].CODIGO = rand() % 9999;

    printf("\nDigite seu nome completo: ");
    fflush(stdin);
    gets(funcionario[POSICAO].NOME);

    printf("\nDigite o ano de registro: ");
    scanf("%d", &funcionario[POSICAO].ANO);

    printf("\nDigite seu cargo na empresa: ");
    fflush(stdin);
    gets(funcionario[POSICAO].CARGO);

    printf("\nDigite valor da hora (Quanto vale sua hora trabalhada): ");
    scanf("%f", &funcionario[POSICAO].VALOR_HORA);

    // Inicializandoo flag_M
    int i, j;
    for (i = 0; i < L; i++)
    {
        for (j = 0; j < C; j++)
        {
            funcionario[POSICAO].meses[i][j].FLAG_M = 0;
        }
    }

    printf("\n\tUSUARIO CADASTRADO COM SUCESSO!\n");
    funcionario[POSICAO].FLAG_F = 1; // Tornando posicao ocupada

    printf("\tSEU CODIGO DE CADASTRO E: %d\n", funcionario[POSICAO].CODIGO);

    printf("\n\tO QUE DESEJA FAZER AGORA?\n");
}



void INSERIR_HORAS() //FUNCAO 2
{
    int i, MES_DIG, CODIGO_USU, DIA_DIG;

    printf("\nInforme o seu codigo de cadastro: ");
    scanf("%d", &CODIGO_USU);

    for (i = 0; i < TAM; i++)
    {
        if (funcionario[i].FLAG_F == 1 && funcionario[i].CODIGO == CODIGO_USU)
        {
            break; // Funcionario encontrado
        }
    }

    if (i == TAM)
    {
        printf("\n\tNAO ENCONTRAMOS FUNCIONARIOS COM OS DADOS FORNECIDOS!\n");
        printf("\tVERIFIQUE OS DADOS E TENTE NOVAMENTE!\n");
        return;
    }

    

    printf("\nINFORME O MES (Ex: 1-Janeiro a 12-Dezembro): ");
    scanf("%d", &MES_DIG);
    MES_DIG--; // Ajuste para o indice come?ar em 0

    if (MES_DIG < 0 || MES_DIG >= L)
    {
        printf("\n\tMES INVALIDO.\n");
        printf("\tVERIFIQUE OS DADOS DIGITADOS E TENTE NOVAMENTE\n");
        return;
    }

    printf("\nINFORME O DIA (Ex: 1 a 30): ");
    scanf("%d", &DIA_DIG);
    DIA_DIG--;

    if (DIA_DIG < 0 || DIA_DIG > C)
    {
        printf("\n\tDIA INVALIDO.\n");
        printf("\tVERIFIQUE OS DADOS DIGITADOS E TENTE NOVAMENTE\n");
        return;
    }

	do
	{
		if (funcionario[i].meses[MES_DIG][DIA_DIG].FLAG_M == 1)
	    {
	        printf("\n\tJA FORAM INSERIDAS HORAS NESTE DIA!\n");
	        printf("\nSELECIONE OUTRO DIA: ");
    		scanf("%d", &DIA_DIG);
    		DIA_DIG--;
	    }
	}while(funcionario[i].meses[MES_DIG][DIA_DIG].FLAG_M == 1);
    

    printf("\nInforme a quantidade de horas trabalhadas: ");
    scanf("%f", &funcionario[i].meses[MES_DIG][DIA_DIG].Q_HORA);

    funcionario[i].meses[MES_DIG][DIA_DIG].FLAG_M = 1;
    printf("\n\tHORAS TRABALHADAS INSERIDAS COM SUCESSO!\n");
}


const char *nome_do_mes(int mes) //Funcao para mostrar o nome do mes de acordo com o valor informado pelo usario 
{
    switch (mes) 
    {
        case 0: return "Janeiro";
        case 1: return "Fevereiro";
        case 2: return "Marco";
        case 3: return "Abril";
        case 4: return "Maio";
        case 5: return "Junho";
        case 6: return "Julho";
        case 7: return "Agosto";
        case 8: return "Setembro";
        case 9: return "Outubro";
        case 10: return "Novembro";
        case 11: return "Dezembro";
        default: return "Mes Invalido";
    }
}

void CALCULAR_SALARIO() // FUNCAO 3
{
    int i, dia, MES_DIG;
    char NOME_USU[50];
    float salario_mensal = 0;

    printf("\nInforme o seu NOME cadastrado: ");
    fflush(stdin);
    gets(NOME_USU);

    for (i = 0; i < TAM; i++)
    {
        if (funcionario[i].FLAG_F == 1 && strcmp(funcionario[i].NOME, NOME_USU) == 0)
        {
            break; // Funcionario encontrado
        }
    }

    if (i == TAM)
    {
        printf("\n\tNAO ENCONTRAMOS FUNCIONARIOS COM O NOME FORNECIDO!\n");
        printf("\tVERIFIQUE OS DADOS E TENTE NOVAMENTE!\n");
        return;
    }

    printf("\nINFORME O MES (Ex: 1-Janeiro a 12-Dezembro): ");
    scanf("%d", &MES_DIG);
    MES_DIG--; // Ajuste para o indice comecar em 0

    if (MES_DIG < 0 || MES_DIG >= L)
    {
        printf("\n\tMES INVALIDO.\n");
        printf("\tVERIFIQUE OS DADOS DIGITADOS E TENTE NOVAMENTE\n");
        return;
    }

    // Verificar se o mes tem horas caadastradas
    for (dia = 0; dia < C; dia++)
    {
        if (funcionario[i].meses[MES_DIG][dia].FLAG_M == 1)
        {
            salario_mensal += funcionario[i].VALOR_HORA * funcionario[i].meses[MES_DIG][dia].Q_HORA;
        }
    }

    if (salario_mensal > 0)
    {
        printf("\n\tNo mes de %s seu salario foi de: %.2f\n", nome_do_mes(MES_DIG), salario_mensal);
    }
    else
    {
        printf("\n\tVoce nao cadastrou horas no mes de %s.\n", nome_do_mes(MES_DIG));
    }
}



void LISTAR_FUNCIONARIOS() // FUNCAO 4
{
    int mesesComHoras, i, mes, dia, ACHOU = 0;

    for (i = 0; i < TAM; i++)
    {
        if (funcionario[i].FLAG_F == 1)
        {
            printf("\nFUNCIONARIO %d:\n\n", i + 1);
            printf("----------------------\n");
            printf("\nCodigo: %d\n", funcionario[i].CODIGO);
            printf("Nome: %s\n", funcionario[i].NOME);
            printf("Ano de Registro: %d\n", funcionario[i].ANO);
            printf("Cargo: %s\n", funcionario[i].CARGO);
            printf("Valor da Hora: %.2f Reais\n", funcionario[i].VALOR_HORA);

            // Variavel para verificar se ha meses com horas cadastradas
            mesesComHoras = 0;

            for (mes = 0; mes < L; mes++)
            {
                for (dia = 0; dia < C; dia++)
                {
                    if (funcionario[i].meses[mes][dia].FLAG_M == 1)
                    {
                        mesesComHoras = 1;
                        break;
                    }
                }

                if (mesesComHoras)
                {
                    break; // Se encontrou um dia com horas, nao precisa verificar os outros meses
                }
            }

            if (mesesComHoras)
            {
                printf("\nMeses com horas trabalhadas:\n");
                for (mes = 0; mes < L; mes++)
                {
                    for (dia = 0; dia < C; dia++)
                    {
                        if (funcionario[i].meses[mes][dia].FLAG_M == 1)
                        {
                            printf("\n%s ", nome_do_mes(mes));
                            break;
                        }
                    }
                }
            }

            printf("\n----------------------\n");
            ACHOU = 1;
        }
    }

    if (!ACHOU)
    {
        printf("\n\tNAO HA FUNCIONARIOS CADASTRADOS!\n");
        printf("\tCADASTRE PELO MENOS UM FUNCIONARIO PARA EXIBIR!\n");
    }
}


void ALTERAR_INFORMACOES() //FUNCAO 5
{
    int CODIGO_USU;

    printf("\nInforme o seu codigo de cadastro: ");
    scanf("%d", &CODIGO_USU);

    int i;
    for (i = 0; i < TAM; i++)
    {
        if (funcionario[i].FLAG_F == 1 && funcionario[i].CODIGO == CODIGO_USU)
        {
            break; // Funcionario encontrado
        }
    }

    if (i == TAM)
    {
        printf("\n\tNAO ENCONTRAMOS FUNCIONARIOS COM OS DADOS FORNECIDOS!\n");
        printf("\tVERIFIQUE OS DADOS E TENTE NOVAMENTE!\n");

        return;
    }

    printf("\nO que deseja alterar?\n");
    printf("[1]- NOME\n");
    printf("[2]- ANO DE CADASTRO \n");
    printf("[3]- CARGO\n");
    printf("[4]- VALOR DA HORA\n");
    printf("\nInforme a Opcao aqui: ");

    int opcao;
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        printf("\nDigite o novo nome: ");
        fflush(stdin);
        gets(funcionario[i].NOME);
        printf("\n\tNome alterado com sucesso!\n");
        break;

    case 2:
        printf("\nDigite o novo ano de cadastro: ");
        scanf("%d", &funcionario[i].ANO);
        printf("\n\tAno de cadastro alterado com sucesso!\n");
        break;

    case 3:
        printf("\n\tDigite o novo cargo: ");
        fflush(stdin);
        gets(funcionario[i].CARGO);
        printf("\n\tCargo alterado com sucesso!\n");
        break;

    case 4:
        printf("\nDigite o novo valor da hora: ");
        scanf("%f", &funcionario[i].VALOR_HORA);
        printf("\n\tValor da hora alterado com sucesso!\n");
        break;

    default:
        printf("\n\tOPCAO INVALIDA\n");
        return;
    }
}


void EXCLUIR_FUNCIONARIO() //FUNCAO 6
{
    int CODIGO_USU, confirmacao=0;

    printf("\nInforme o codigo do funcionario que deseja excluir: ");
    scanf("%d", &CODIGO_USU);

    int i;
    for (i = 0; i < TAM; i++)
    {
        if (funcionario[i].FLAG_F == 1 && funcionario[i].CODIGO == CODIGO_USU)
        {
            break; // Funcionario encontrado
        }
    }

    if (i == TAM)
    {
        printf("\n\tNAO ENCONTRAMOS FUNCIONARIOS COM OS DADOS FORNECIDOS!\n");
        printf("\tVERIFIQUE OS DADOS E TENTE NOVAMENTE!\n");
        return;
    }

 
    printf("\nTem certeza que deseja excluir o funcionario %s? (1 - Sim / 2 - Nao): ", funcionario[i].NOME);
    scanf("%d", &confirmacao);

    if (confirmacao == 1)
    {
        // Marcar posicao como livre
        funcionario[i].FLAG_F = 0;

        // Zerar os dados do funcionario excluido
        memset(funcionario[i].NOME, 0, sizeof(funcionario[i].NOME));
        memset(funcionario[i].CARGO, 0, sizeof(funcionario[i].CARGO));
        funcionario[i].CODIGO = 0;
        funcionario[i].ANO = 0;
        funcionario[i].VALOR_HORA = 0;
	
        printf("\n\tFUNCIONARIO EXCLUIDO COM SUCESSO!\n");
    }
    else if(confirmacao == 2)
    {
        printf("\n\tEXCLUSAO CANCELADA, OS DADOS DO FUNCIONARIO PERMANECEM SALVOS!\n");
    }
}

    
int main()
{
    int OP_MENU;

    INICIALIZA_FLAG(); // INICIALIZANDO TODOS OS INDICES DA STRUCT COM 0;

    printf("\n*----- FICHAR DIGITAL DE FUNCIONARIOS -----*\n");
    printf("       EMPRESA: CONSTRUCAO CIVIL LTDA\n");
    do
    {
        printf("\nSELECIONE UMA OPCAO DO MENU:\n\n\t----- MENU ----- \n[1]- CADASTRAR FUNCIONARIO \n[2]- INSERIR HORAS TRABALHADAS \n[3]- CALCULAR SALARIO \n[4]- LISTAR FUNCIONARIOS CADASTRADOS \n[5]- ALTERAR INFORMACOES DO FUNCIONARIO \n[6]- EXCLUIR \n[7]- SAIR");
        printf("\n\nDIGITE O NUMERO DA OPCAO AQUI : ");
        scanf("%d", &OP_MENU);

        switch (OP_MENU)
        {
	        case 1: CADASTRAR_FUNCIONARIO(); break;
	        case 2: INSERIR_HORAS(); break;
	        case 3: CALCULAR_SALARIO(); break;
	        case 4: LISTAR_FUNCIONARIOS(); break;
	        case 5: ALTERAR_INFORMACOES(); break;
	        case 6: EXCLUIR_FUNCIONARIO(); break;  
	        case 7: printf("\n\tATE LOGO! \nO PROGRAMA FOI FINALIZADO!\n"); exit(0); break;
	        default:
	            printf("\n\tOPCAO INVALIDA, TENTE NOVAMENTE!\n");
	        }
    } while (OP_MENU != 7);

    return 0;
}
