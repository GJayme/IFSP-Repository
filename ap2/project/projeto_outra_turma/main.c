#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAMNOME 50
#define TAMSOBRENOME 50

typedef struct data
{
    int dia;
    int mes;
    int ano;
} data;

typedef struct registro
{
    char nome[TAMNOME];
    char sobrenome[TAMSOBRENOME];
    data datadenascimento;
    int prontuario;
    char curso[4];
} aluno;

void cadastrar(aluno *, int *);
int buscar_nome(aluno *, aluno *, int);
int buscar_prontuario(aluno *, aluno *, int);
int remover_nome_sobrenome(aluno *, aluno, int *);
int remover_nome(aluno *, aluno, int *);
int remover_sobrenome(aluno *, aluno, int *);
int remover_prontuario(aluno *, aluno, int *);
int remover_nascimento(aluno *, aluno, int *);
int remover_curso(aluno *, aluno, int *);
void quick_sort_nome(aluno *, int, int);
void quick_sort_sobrenome(aluno *, int, int);
void quick_sort_nascimento(aluno *, int, int);
void quick_sort_prontuario(aluno *, int, int);
void quick_sort_curso(aluno *, int, int);
int particionar_nome(aluno *, int, int);
int particionar_sobrenome(aluno *, int, int);
int particionar_nascimento(aluno *, int, int);
int particionar_prontuario(aluno *, int, int);
int particionar_curso(aluno *, int, int);
void troca(aluno *, aluno *);

int main()
{
    aluno alunos[1000];
    int i, escolha, escolha2, escolha3, qtd_cadastrado = 0;
    aluno busca;

    do
    {
        printf("Menu:\n");
        printf("  1 - Cadastrar Aluno\n");
        printf("  2 - Ordenar Cadastro\n");
        printf("  3 - Buscar Aluno\n");
        printf("  4 - Remover Aluno\n");
        printf("  5 - Imprimir\n");
        printf("  0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &escolha);
        system("CLS");
        fflush(stdin);

        switch (escolha)
        {
        case 1:
            printf("Cadastrar Aluno:\n");
            cadastrar(alunos, &qtd_cadastrado);
            system("PAUSE");
            system("CLS");
            break;
        case 2:
            do
            {
                printf("Ordenar Cadastro:\n");
                printf("  1 - Nome e sobrenome\n");
                printf("  2 - Sobrenome e nome\n");
                printf("  3 - Data de nascimento\n");
                printf("  4 - Prontuario\n");
                printf("  5 - Curso\n");
                printf("  0 - Voltar\n");
                printf("Escolha: ");
                scanf("%d", &escolha2);
                system("CLS");
                fflush(stdin);

                switch (escolha2)
                {
                case 1:
                    quick_sort_sobrenome(alunos, 0, qtd_cadastrado - 1);
                    quick_sort_nome(alunos, 0, qtd_cadastrado - 1);
                    printf("Cadastro ordenado por nome e sobrenome!\n");
                    system("PAUSE");
                    system("CLS");
                    escolha2 = 0;
                    break;
                case 2:
                    quick_sort_nome(alunos, 0, qtd_cadastrado - 1);
                    quick_sort_sobrenome(alunos, 0, qtd_cadastrado - 1);
                    printf("Cadastro ordenado por sobrenome e nome!\n");
                    system("PAUSE");
                    system("CLS");
                    escolha2 = 0;
                    break;
                case 3:
                    quick_sort_nascimento(alunos, 0, qtd_cadastrado - 1);
                    printf("Cadastro ordenado por data de nasmimento!\n");
                    system("PAUSE");
                    system("CLS");
                    escolha2 = 0;
                    break;
                case 4:
                    quick_sort_prontuario(alunos, 0, qtd_cadastrado - 1);
                    printf("Cadastro ordenado por prontuario!\n");
                    system("PAUSE");
                    system("CLS");
                    escolha2 = 0;
                    break;
                case 5:
                    quick_sort_curso(alunos, 0, qtd_cadastrado - 1);
                    printf("Cadastro ordenado por curso!\n");
                    system("PAUSE");
                    system("CLS");
                    escolha2 = 0;
                    break;
                case 0:
                    break;
                default:
                    printf("Escolha uma opcao entre 0 e 5\n");
                    system("PAUSE");
                    system("CLS");
                }
            } while (escolha2 != 0);

            break;
        case 3:
            do
            {
                printf("Buscar Aluno:\n");
                printf("  1 - Nome e sobrenome\n");
                printf("  2 - Prontuario\n");
                printf("  0 - Voltar\n");
                printf("Escolha: ");
                scanf("%d", &escolha2);
                system("CLS");
                fflush(stdin);

                switch (escolha2)
                {
                case 1:
                    printf("Buscar Aluno:\n");
                    printf("Nome: ");
                    gets(busca.nome);
                    printf("Sobrenome: ");
                    gets(busca.sobrenome);

                    if (buscar_nome(alunos, &busca, qtd_cadastrado))
                    {
                        printf("\nNome: %s\n", busca.nome);
                        printf("Sobrenome: %s\n", busca.sobrenome);
                        printf("Nascimento: %d-%d-%d\n", busca.datadenascimento.dia, busca.datadenascimento.mes, busca.datadenascimento.ano);
                        printf("Prontuario: %d\n", busca.prontuario);
                        printf("Curso: %s\n", busca.curso);
                    }
                    else
                    {
                        printf("Aluno nao encontrado!\n");
                    }

                    escolha2 = 0;
                    system("PAUSE");
                    system("CLS");
                    break;
                case 2:
                    printf("Buscar Aluno:\n");
                    printf("Prontuario: ");
                    scanf("%d", &busca.prontuario);
                    fflush(stdin);

                    if (buscar_prontuario(alunos, &busca, qtd_cadastrado))
                    {
                        printf("\nNome: %s\n", busca.nome);
                        printf("Sobrenome: %s\n", busca.sobrenome);
                        printf("Nascimento: %d-%d-%d\n", busca.datadenascimento.dia, busca.datadenascimento.mes, busca.datadenascimento.ano);
                        printf("Prontuario: %d\n", busca.prontuario);
                        printf("Curso: %s\n", busca.curso);
                    }
                    else
                    {
                        printf("Aluno nao encontrado!\n");
                    }

                    escolha2 = 0;
                    system("PAUSE");
                    system("CLS");
                    break;
                case 0:
                    break;
                default:
                    printf("Escolha uma opcao entre 0 e 2\n");
                    system("PAUSE");
                    system("CLS");
                }
            } while (escolha2 != 0);

            break;
        case 4:
            do
            {
                printf("Remover Aluno:\n");
                printf("  1 - Nome e sobrenome\n");
                printf("  2 - Nome\n");
                printf("  3 - Sobrenome\n");
                printf("  4 - Prontuario\n");
                printf("  5 - Data de Nascimento\n");
                printf("  6 - Curso\n");
                printf("  0 - Voltar\n");
                printf("Escolha: ");
                scanf("%d", &escolha2);
                system("CLS");
                fflush(stdin);

                switch (escolha2)
                {
                case 1:
                    printf("Remover aluno por nome e sobrenome:\n");
                    printf("Nome: ");
                    gets(busca.nome);
                    printf("Sobrenome: ");
                    gets(busca.sobrenome);

                    printf("%d alunos removidos\n", remover_nome_sobrenome(alunos, busca, &qtd_cadastrado));
                    system("PAUSE");
                    system("CLS");
                    escolha2 = 0;
                    break;
                case 2:
                    printf("Remover aluno por nome:\n");
                    printf("Nome: ");
                    gets(busca.nome);

                    printf("%d alunos removidos\n", remover_nome(alunos, busca, &qtd_cadastrado));
                    system("PAUSE");
                    system("CLS");
                    escolha2 = 0;
                    break;
                case 3:
                    printf("Remover aluno por sobrenome:\n");
                    printf("Sobrenome: ");
                    gets(busca.sobrenome);

                    printf("%d alunos removidos\n", remover_sobrenome(alunos, busca, &qtd_cadastrado));
                    system("PAUSE");
                    system("CLS");
                    escolha2 = 0;
                    break;
                case 4:
                    printf("Remover aluno por prontuario:\n");
                    printf("Prontuario: ");
                    scanf("%d", &busca.prontuario);

                    printf("%d alunos removidos\n", remover_prontuario(alunos, busca, &qtd_cadastrado));
                    system("PAUSE");
                    system("CLS");
                    escolha2 = 0;
                    break;
                case 5:
                    printf("Remover aluno por data de nascimento:\n");
                    printf("Dia de nascimento: ");
                    scanf("%d", &busca.datadenascimento.dia);
                    printf("Mes de nascimento: ");
                    scanf("%d", &busca.datadenascimento.mes);
                    printf("Ano de nascimento: ");
                    scanf("%d", &busca.datadenascimento.ano);

                    printf("%d alunos removidos\n", remover_nascimento(alunos, busca, &qtd_cadastrado));
                    system("PAUSE");
                    system("CLS");
                    escolha2 = 0;
                    break;
                case 6:
                    printf("Remover aluno por curso:\n");
                    printf("Curso: ");
                    gets(busca.curso);

                    printf("%d alunos removidos\n", remover_curso(alunos, busca, &qtd_cadastrado));
                    system("PAUSE");
                    system("CLS");
                    escolha2 = 0;
                    break;
                case 0:
                    break;
                default:
                    printf("Escolha uma opcao entre 0 e 6\n");
                    system("PAUSE");
                    system("CLS");
                }
            } while (escolha2 != 0);
            break;
        case 5:
            do
            {
                printf("Imprimir:\n");
                printf("  1 - Imprimir Cadastro\n");
                printf("  2 - Ordenar Cadastro e Imprimir\n");
                printf("  3 - Imprimir por busca\n");
                printf("  0 - Sair\n");
                printf("Escolha: ");
                scanf("%d", &escolha2);
                system("CLS");
                fflush(stdin);

                switch (escolha2)
                {
                case 1:
                    for (i = 0; i < qtd_cadastrado; i++)
                    {
                        printf("\nNome: %s\n", alunos[i].nome);
                        printf("Sobrenome: %s\n", alunos[i].sobrenome);
                        printf("Nascimento: %d-%d-%d\n", alunos[i].datadenascimento.dia, alunos[i].datadenascimento.mes, alunos[i].datadenascimento.ano);
                        printf("Prontuario: %d\n", alunos[i].prontuario);
                        printf("Curso: %s\n", alunos[i].curso);
                    }
                    system("PAUSE");
                    system("CLS");
                    escolha2 = 0;
                    break;
                case 2:
                    do
                    {
                        printf("Imprimir cadastro ordenado por:\n");
                        printf("  1 - Nome e sobrenome\n");
                        printf("  2 - Sobrenome e nome\n");
                        printf("  3 - Data de nascimento\n");
                        printf("  4 - Prontuario\n");
                        printf("  5 - Curso\n");
                        printf("  0 - Voltar\n");
                        printf("Escolha: ");
                        scanf("%d", &escolha3);
                        system("CLS");
                        fflush(stdin);

                        switch (escolha3)
                        {
                        case 1:
                            quick_sort_sobrenome(alunos, 0, qtd_cadastrado - 1);
                            quick_sort_nome(alunos, 0, qtd_cadastrado - 1);
                            printf("Cadastro ordenado por nome e sobrenome!\n");
                            for (i = 0; i < qtd_cadastrado; i++)
                            {
                                printf("\nNome: %s\n", alunos[i].nome);
                                printf("Sobrenome: %s\n", alunos[i].sobrenome);
                                printf("Nascimento: %d-%d-%d\n", alunos[i].datadenascimento.dia, alunos[i].datadenascimento.mes, alunos[i].datadenascimento.ano);
                                printf("Prontuario: %d\n", alunos[i].prontuario);
                                printf("Curso: %s\n", alunos[i].curso);
                            }

                            system("PAUSE");
                            system("CLS");
                            escolha3 = 0;
                            break;
                        case 2:
                            quick_sort_nome(alunos, 0, qtd_cadastrado - 1);
                            quick_sort_sobrenome(alunos, 0, qtd_cadastrado - 1);
                            printf("Cadastro ordenado por sobrenome e nome!\n");
                            for (i = 0; i < qtd_cadastrado; i++)
                            {
                                printf("\nNome: %s\n", alunos[i].nome);
                                printf("Sobrenome: %s\n", alunos[i].sobrenome);
                                printf("Nascimento: %d-%d-%d\n", alunos[i].datadenascimento.dia, alunos[i].datadenascimento.mes, alunos[i].datadenascimento.ano);
                                printf("Prontuario: %d\n", alunos[i].prontuario);
                                printf("Curso: %s\n", alunos[i].curso);
                            }
                            system("PAUSE");
                            system("CLS");
                            escolha3 = 0;
                            break;
                        case 3:
                            quick_sort_nascimento(alunos, 0, qtd_cadastrado - 1);
                            printf("Cadastro ordenado por data de nasmimento!\n");
                            for (i = 0; i < qtd_cadastrado; i++)
                            {
                                printf("\nNome: %s\n", alunos[i].nome);
                                printf("Sobrenome: %s\n", alunos[i].sobrenome);
                                printf("Nascimento: %d-%d-%d\n", alunos[i].datadenascimento.dia, alunos[i].datadenascimento.mes, alunos[i].datadenascimento.ano);
                                printf("Prontuario: %d\n", alunos[i].prontuario);
                                printf("Curso: %s\n", alunos[i].curso);
                            }
                            system("PAUSE");
                            system("CLS");
                            escolha3 = 0;
                            break;
                        case 4:
                            quick_sort_prontuario(alunos, 0, qtd_cadastrado - 1);
                            printf("Cadastro ordenado por prontuario!\n");
                            for (i = 0; i < qtd_cadastrado; i++)
                            {
                                printf("\nNome: %s\n", alunos[i].nome);
                                printf("Sobrenome: %s\n", alunos[i].sobrenome);
                                printf("Nascimento: %d-%d-%d\n", alunos[i].datadenascimento.dia, alunos[i].datadenascimento.mes, alunos[i].datadenascimento.ano);
                                printf("Prontuario: %d\n", alunos[i].prontuario);
                                printf("Curso: %s\n", alunos[i].curso);
                            }
                            system("PAUSE");
                            system("CLS");
                            escolha3 = 0;
                            break;
                        case 5:
                            quick_sort_curso(alunos, 0, qtd_cadastrado - 1);
                            printf("Cadastro ordenado por curso!\n");
                            for (i = 0; i < qtd_cadastrado; i++)
                            {
                                printf("\nNome: %s\n", alunos[i].nome);
                                printf("Sobrenome: %s\n", alunos[i].sobrenome);
                                printf("Nascimento: %d-%d-%d\n", alunos[i].datadenascimento.dia, alunos[i].datadenascimento.mes, alunos[i].datadenascimento.ano);
                                printf("Prontuario: %d\n", alunos[i].prontuario);
                                printf("Curso: %s\n", alunos[i].curso);
                            }
                            system("PAUSE");
                            system("CLS");
                            escolha3 = 0;
                            break;
                        case 0:
                            break;
                        default:
                            printf("Escolha uma opcao entre 0 e 5\n");
                            system("PAUSE");
                            system("CLS");
                        }
                    } while (escolha3 != 0);

                    escolha2 = 0;
                    break;
                case 3:
                    do
                    {
                        printf("Buscar por:\n");
                        printf("  1 - Nome e sobrenome\n");
                        printf("  2 - Nome\n");
                        printf("  3 - Sobrenome\n");
                        printf("  4 - Prontuario\n");
                        printf("  5 - Data de nascimento\n");
                        printf("  6 - Curso\n");
                        printf("  0 - Voltar\n");
                        printf("Escolha: ");
                        scanf("%d", &escolha3);
                        system("CLS");
                        fflush(stdin);

                        switch (escolha3)
                        {
                        case 1:
                            printf("Remover aluno por nome e sobrenome:\n");
                            printf("Nome: ");
                            gets(busca.nome);
                            printf("Sobrenome: ");
                            gets(busca.sobrenome);
                            for (i = 0; i < qtd_cadastrado; i++)
                            {
                                if (!strcmp(alunos[i].nome, busca.nome) && !strcmp(alunos[i].sobrenome, busca.sobrenome))
                                {
                                    printf("\nNome: %s\n", alunos[i].nome);
                                    printf("Sobrenome: %s\n", alunos[i].sobrenome);
                                    printf("Nascimento: %d-%d-%d\n", alunos[i].datadenascimento.dia, alunos[i].datadenascimento.mes, alunos[i].datadenascimento.ano);
                                    printf("Prontuario: %d\n", alunos[i].prontuario);
                                    printf("Curso: %s\n", alunos[i].curso);
                                }
                            }

                            system("PAUSE");
                            system("CLS");
                            escolha3 = 0;
                            break;
                        case 2:
                            printf("Remover aluno por nome:\n");
                            printf("Nome: ");
                            gets(busca.nome);
                            for (i = 0; i < qtd_cadastrado; i++)
                            {
                                if (!strcmp(alunos[i].nome, busca.nome))
                                {
                                    printf("\nNome: %s\n", alunos[i].nome);
                                    printf("Sobrenome: %s\n", alunos[i].sobrenome);
                                    printf("Nascimento: %d-%d-%d\n", alunos[i].datadenascimento.dia, alunos[i].datadenascimento.mes, alunos[i].datadenascimento.ano);
                                    printf("Prontuario: %d\n", alunos[i].prontuario);
                                    printf("Curso: %s\n", alunos[i].curso);
                                }
                            }
                            system("PAUSE");
                            system("CLS");
                            escolha3 = 0;
                            break;
                        case 3:
                            printf("Remover aluno por sobrenome:\n");
                            printf("Sobrenome: ");
                            gets(busca.sobrenome);
                            for (i = 0; i < qtd_cadastrado; i++)
                            {
                                if (!strcmp(alunos[i].sobrenome, busca.sobrenome))
                                {
                                    printf("\nNome: %s\n", alunos[i].nome);
                                    printf("Sobrenome: %s\n", alunos[i].sobrenome);
                                    printf("Nascimento: %d-%d-%d\n", alunos[i].datadenascimento.dia, alunos[i].datadenascimento.mes, alunos[i].datadenascimento.ano);
                                    printf("Prontuario: %d\n", alunos[i].prontuario);
                                    printf("Curso: %s\n", alunos[i].curso);
                                }
                            }
                            system("PAUSE");
                            system("CLS");
                            escolha3 = 0;
                            break;
                        case 4:
                            printf("Remover aluno por prontuario:\n");
                            printf("Prontuario: ");
                            scanf("%d", &busca.prontuario);
                            for (i = 0; i < qtd_cadastrado; i++)
                            {
                                if (alunos[i].prontuario == busca.prontuario)
                                {
                                    printf("\nNome: %s\n", alunos[i].nome);
                                    printf("Sobrenome: %s\n", alunos[i].sobrenome);
                                    printf("Nascimento: %d-%d-%d\n", alunos[i].datadenascimento.dia, alunos[i].datadenascimento.mes, alunos[i].datadenascimento.ano);
                                    printf("Prontuario: %d\n", alunos[i].prontuario);
                                    printf("Curso: %s\n", alunos[i].curso);
                                }
                            }
                            system("PAUSE");
                            system("CLS");
                            escolha3 = 0;
                            break;
                        case 5:
                            printf("Remover aluno por data de nascimento:\n");
                            printf("Dia de nascimento: ");
                            scanf("%d", &busca.datadenascimento.dia);
                            printf("Mes de nascimento: ");
                            scanf("%d", &busca.datadenascimento.mes);
                            printf("Ano de nascimento: ");
                            scanf("%d", &busca.datadenascimento.ano);
                            for (i = 0; i < qtd_cadastrado; i++)
                            {
                                if (alunos[i].datadenascimento.dia == busca.datadenascimento.dia &&
                                    alunos[i].datadenascimento.mes == busca.datadenascimento.mes &&
                                    alunos[i].datadenascimento.ano == busca.datadenascimento.ano)
                                {
                                    printf("\nNome: %s\n", alunos[i].nome);
                                    printf("Sobrenome: %s\n", alunos[i].sobrenome);
                                    printf("Nascimento: %d-%d-%d\n", alunos[i].datadenascimento.dia, alunos[i].datadenascimento.mes, alunos[i].datadenascimento.ano);
                                    printf("Prontuario: %d\n", alunos[i].prontuario);
                                    printf("Curso: %s\n", alunos[i].curso);
                                }
                            }
                            system("PAUSE");
                            system("CLS");
                            escolha3 = 0;
                            break;
                        case 6:
                            printf("Remover aluno por curso:\n");
                            printf("Curso: ");
                            gets(busca.curso);
                            for (i = 0; i < qtd_cadastrado; i++)
                            {
                                if (!strcmp(alunos[i].curso, busca.curso))
                                {
                                    printf("\nNome: %s\n", alunos[i].nome);
                                    printf("Sobrenome: %s\n", alunos[i].sobrenome);
                                    printf("Nascimento: %d-%d-%d\n", alunos[i].datadenascimento.dia, alunos[i].datadenascimento.mes, alunos[i].datadenascimento.ano);
                                    printf("Prontuario: %d\n", alunos[i].prontuario);
                                    printf("Curso: %s\n", alunos[i].curso);
                                }
                            }
                            system("PAUSE");
                            system("CLS");
                            escolha3 = 0;
                            break;
                        case 0:
                            break;
                        default:
                            printf("Escolha uma opcao entre 0 e 6\n");
                            system("PAUSE");
                            system("CLS");
                        }
                    } while (escolha3 != 0);

                    escolha2 = 0;
                    break;
                case 0:
                    break;
                default:
                    printf("Escolha uma opcao entre 0 e 3\n");
                    system("PAUSE");
                    system("CLS");
                }
            } while (escolha2 != 0);
            break;
        case 0:
            printf("Saindo...\n");

            break;
        default:
            printf("Escolha uma opcao entre 1 e 5\n");
            system("PAUSE");
            system("CLS");
        }
    } while (escolha != 0);

    return 0;
}

void cadastrar(aluno *alunos, int *qtd_cadastrado)
{
    if (*qtd_cadastrado < 1000)
    {
        printf("  Nome: ");
        gets(alunos[*qtd_cadastrado].nome);
        printf("  Sobrenome: ");
        gets(alunos[*qtd_cadastrado].sobrenome);
        printf("  Dia de Nascimento: ");
        scanf("%d", &alunos[*qtd_cadastrado].datadenascimento.dia);
        printf("  Mes de Nascimento: ");
        scanf("%d", &alunos[*qtd_cadastrado].datadenascimento.mes);
        printf("  Ano de Nascimento: ");
        scanf("%d", &alunos[*qtd_cadastrado].datadenascimento.ano);
        printf("  Prontuario: ");
        scanf("%d", &alunos[*qtd_cadastrado].prontuario);
        fflush(stdin);
        printf("  Curso: ");
        gets(alunos[*qtd_cadastrado].curso);

        *qtd_cadastrado = *qtd_cadastrado + 1;
        printf("Aluno Cadastrado com Sucesso!\n");
    }
    else
    {
        printf("Espaco insuficiente\n");
    }
}

int buscar_nome(aluno *alunos, aluno *busca, int qtd_cadastrado)
{
    int i;
    for (i = 0; i < qtd_cadastrado; i++)
    {
        if (!strcmp(alunos[i].nome, busca->nome) && !strcmp(alunos[i].sobrenome, busca->sobrenome))
        {
            busca->datadenascimento.dia = alunos[i].datadenascimento.dia;
            busca->datadenascimento.mes = alunos[i].datadenascimento.mes;
            busca->datadenascimento.ano = alunos[i].datadenascimento.ano;
            busca->prontuario = alunos[i].prontuario;
            strcpy(busca->curso, alunos[i].curso);

            return 1;
        }
    }

    return 0;
}

int buscar_prontuario(aluno *alunos, aluno *busca, int qtd_cadastrado)
{
    int i;
    for (i = 0; i < qtd_cadastrado; i++)
    {
        if (alunos[i].prontuario == busca->prontuario)
        {
            strcpy(busca->nome, alunos[i].nome);
            strcpy(busca->sobrenome, alunos[i].sobrenome);
            busca->datadenascimento.dia = alunos[i].datadenascimento.dia;
            busca->datadenascimento.mes = alunos[i].datadenascimento.mes;
            busca->datadenascimento.ano = alunos[i].datadenascimento.ano;
            strcpy(busca->curso, alunos[i].curso);

            return 1;
        }
    }
    return 0;
}

int remover_nome_sobrenome(aluno *alunos, aluno busca, int *qtd_cadastrado)
{
    int i, j, cont = 0;
    for (i = 0; i < *qtd_cadastrado; i++)
    {
        if (!strcmp(alunos[i].nome, busca.nome) && !strcmp(alunos[i].sobrenome, busca.sobrenome))
        {
            for (j = i; j < *qtd_cadastrado - 1; j++)
            {
                alunos[j] = alunos[j + 1];
            }
            *qtd_cadastrado = *qtd_cadastrado - 1;
            cont++;
            i--;
        }
    }
    return cont;
}
int remover_nome(aluno *alunos, aluno busca, int *qtd_cadastrado)
{
    int i, j, cont = 0;
    for (i = 0; i < *qtd_cadastrado; i++)
    {
        if (!strcmp(alunos[i].nome, busca.nome))
        {
            for (j = i; j < *qtd_cadastrado - 1; j++)
            {
                alunos[j] = alunos[j + 1];
            }
            *qtd_cadastrado = *qtd_cadastrado - 1;
            cont++;
            i--;
        }
    }
    return cont;
}
int remover_sobrenome(aluno *alunos, aluno busca, int *qtd_cadastrado)
{
    int i, j, cont = 0;
    for (i = 0; i < *qtd_cadastrado; i++)
    {
        if (!strcmp(alunos[i].sobrenome, busca.sobrenome))
        {
            for (j = i; j < *qtd_cadastrado - 1; j++)
            {
                alunos[j] = alunos[j + 1];
            }
            *qtd_cadastrado = *qtd_cadastrado - 1;
            cont++;
            i--;
        }
    }
    return cont;
}
int remover_prontuario(aluno *alunos, aluno busca, int *qtd_cadastrado)
{
    int i, j, cont = 0;
    for (i = 0; i < *qtd_cadastrado; i++)
    {
        if (alunos[i].prontuario == busca.prontuario)
        {
            for (j = i; j < *qtd_cadastrado - 1; j++)
            {
                alunos[j] = alunos[j + 1];
            }
            *qtd_cadastrado = *qtd_cadastrado - 1;
            cont++;
            i--;
        }
    }
    return cont;
}
int remover_nascimento(aluno *alunos, aluno busca, int *qtd_cadastrado)
{
    int i, j, cont = 0;
    for (i = 0; i < *qtd_cadastrado; i++)
    {
        if (alunos[i].datadenascimento.dia == busca.datadenascimento.dia &&
            alunos[i].datadenascimento.mes == busca.datadenascimento.mes &&
            alunos[i].datadenascimento.ano == busca.datadenascimento.ano)
        {
            for (j = i; j < *qtd_cadastrado - 1; j++)
            {
                alunos[j] = alunos[j + 1];
            }
            *qtd_cadastrado = *qtd_cadastrado - 1;
            cont++;
            i--;
        }
    }
    return cont;
}
int remover_curso(aluno *alunos, aluno busca, int *qtd_cadastrado)
{
    int i, j, cont = 0;
    for (i = 0; i < *qtd_cadastrado; i++)
    {
        if (!strcmp(alunos[i].curso, busca.curso))
        {
            for (j = i; j < *qtd_cadastrado - 1; j++)
            {
                alunos[j] = alunos[j + 1];
            }
            *qtd_cadastrado = *qtd_cadastrado - 1;
            cont++;
            i--;
        }
    }
    return cont;
}

void quick_sort_nome(aluno *alunos, int ini, int fim)
{
    int pos;
    if (ini < fim)
    {
        pos = particionar_nome(alunos, ini, fim);
        quick_sort_nome(alunos, ini, pos - 1);
        quick_sort_nome(alunos, pos, fim);
    }
}
void quick_sort_sobrenome(aluno *alunos, int ini, int fim)
{
    int pos;
    if (ini < fim)
    {
        pos = particionar_sobrenome(alunos, ini, fim);
        quick_sort_sobrenome(alunos, ini, pos - 1);
        quick_sort_sobrenome(alunos, pos, fim);
    }
}
void quick_sort_nascimento(aluno *alunos, int ini, int fim)
{
    int pos;
    if (ini < fim)
    {
        pos = particionar_nascimento(alunos, ini, fim);
        quick_sort_nascimento(alunos, ini, pos - 1);
        quick_sort_nascimento(alunos, pos, fim);
    }
}
void quick_sort_prontuario(aluno *alunos, int ini, int fim)
{
    int pos;
    if (ini < fim)
    {
        pos = particionar_prontuario(alunos, ini, fim);
        quick_sort_prontuario(alunos, ini, pos - 1);
        quick_sort_prontuario(alunos, pos, fim);
    }
}
void quick_sort_curso(aluno *alunos, int ini, int fim)
{
    int pos;
    if (ini < fim)
    {
        pos = particionar_curso(alunos, ini, fim);
        quick_sort_curso(alunos, ini, pos - 1);
        quick_sort_curso(alunos, pos, fim);
    }
}
int particionar_nome(aluno *alunos, int ini, int fim)
{
    aluno pivo;
    pivo = alunos[fim];

    while (ini < fim)
    {
        while (ini < fim && strcmp(alunos[ini].nome, pivo.nome) <= 0)
            ini++;
        while (ini < fim && strcmp(alunos[fim].nome, pivo.nome) > 0)
            fim--;
        troca(&alunos[ini], &alunos[fim]);
    }

    return ini;
}

int particionar_sobrenome(aluno *alunos, int ini, int fim)
{
    aluno pivo;
    pivo = alunos[fim];

    while (ini < fim)
    {
        while (ini < fim && strcmp(alunos[ini].sobrenome, pivo.sobrenome) <= 0)
            ini++;
        while (ini < fim && strcmp(alunos[fim].sobrenome, pivo.sobrenome) > 0)
            fim--;
        troca(&alunos[ini], &alunos[fim]);
    }

    return ini;
}

int particionar_nascimento(aluno *alunos, int ini, int fim)
{
    aluno pivo;
    pivo = alunos[fim];

    while (ini < fim)
    {
        while (ini < fim &&
               (alunos[ini].datadenascimento.ano * pow(10.0, 4.0) + alunos[ini].datadenascimento.mes * pow(10.0, 2.0) + alunos[ini].datadenascimento.dia) <=
                   (pivo.datadenascimento.ano * pow(10.0, 4.0) + pivo.datadenascimento.mes * pow(10.0, 2.0) + pivo.datadenascimento.dia))
            ini++;
        while (ini < fim &&
               (alunos[fim].datadenascimento.ano * pow(10.0, 4.0) + alunos[fim].datadenascimento.mes * pow(10.0, 2.0) + alunos[fim].datadenascimento.dia) >
                   (pivo.datadenascimento.ano * pow(10.0, 4.0) + pivo.datadenascimento.mes * pow(10.0, 2.0) + pivo.datadenascimento.dia))
            fim--;
        troca(&alunos[ini], &alunos[fim]);
    }

    return ini;
}

int particionar_prontuario(aluno *alunos, int ini, int fim)
{
    aluno pivo;
    pivo = alunos[fim];

    while (ini < fim)
    {
        while (ini < fim && alunos[ini].prontuario <= pivo.prontuario)
            ini++;
        while (ini < fim && alunos[fim].prontuario > pivo.prontuario)
            fim--;
        troca(&alunos[ini], &alunos[fim]);
    }

    return ini;
}

int particionar_curso(aluno *alunos, int ini, int fim)
{
    aluno pivo;
    pivo = alunos[fim];

    while (ini < fim)
    {
        while (ini < fim && strcmp(alunos[ini].curso, pivo.curso) <= 0)
            ini++;
        while (ini < fim && strcmp(alunos[fim].curso, pivo.curso) > 0)
            fim--;
        troca(&alunos[ini], &alunos[fim]);
    }

    return ini;
}

void troca(aluno *a, aluno *b)
{
    aluno aux = *a;
    *a = *b;
    *b = aux;
}
