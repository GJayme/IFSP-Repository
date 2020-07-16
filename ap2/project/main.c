#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_nome 50
#define TAM_sobrenome 50

// STRUCT DATA
typedef struct data_nascimento //Nomendo o tipo de struct para data
{
  int dia;
  int mes;
  int ano;
} data;

// STRUCT ALUNO
typedef struct cadastra_aluno //Nomendo o tipo de struct para aluno
{
  char nome[TAM_nome];
  char sobrenome[TAM_sobrenome];
  data dataNascimento;
  int prontuario;
  char curso[4];
} aluno;

void cadastraAluno(aluno *alunos, int *numAlunos)
{
  if (*numAlunos < 1000)
  {
    printf("Bem vindo a tela de cadastro de aluno.\n");
    printf("Nome: ");
    getchar();
    fgets(alunos[*numAlunos].nome, TAM_nome, stdin);

    printf("Sobrenome: ");
    fgets(alunos[*numAlunos].sobrenome, TAM_sobrenome, stdin);

    printf("Dia de nascimento: ");
    scanf("%d", &alunos[*numAlunos].dataNascimento.dia);

    printf("Mês de nascimento: ");
    scanf("%d", &alunos[*numAlunos].dataNascimento.mes);

    printf("Ano de nascimento: ");
    scanf("%d", &alunos[*numAlunos].dataNascimento.ano);

    printf("Número do prontuario ");
    scanf("%d", &alunos[*numAlunos].prontuario);

    printf("Curso: ");
    getchar();
    fgets(alunos[*numAlunos].curso, 4, stdin);

    alunos[*numAlunos].nome[strcspn(alunos[*numAlunos].nome, "\n")] = 0;           //tirando a quebra de linha que o fgets coloca
    alunos[*numAlunos].sobrenome[strcspn(alunos[*numAlunos].sobrenome, "\n")] = 0; //tirando a quebra de linha que o fgets coloca

    *numAlunos += 1;
  }
  else
  {
    printf("Número máximo de alunos cadastrados!");
  }
};

// MENU PRINCIPAL
void printMenuPrincipal()
{
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("|                                                   MENU                                                    |\n");
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("1 - Cadastrar novo aluno\n");
  printf("2 - Ordenar cadastro de alunos\n");
  printf("3 - Buscar aluno\n");
  printf("4 - Remover aluno\n");
  printf("0 - Sair\n");
  printf("-------------------------------------------------------------------------------------------------------------\n");
};

// SUB MENU ORDENAÇAO DE ALUNOS
void printSubMenuOrdenacao()
{
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("|                                             ORDENAR ALUNOS POR                                             |\n");
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("1 - Nome e sobrenome\n");
  printf("2 - Sobrenome e nome\n");
  printf("3 - Data de nascimento\n");
  printf("4 - Prontuario\n");
  printf("5 - Curso\n");
  printf("0 - Sair de ordenação\n");
  printf("-------------------------------------------------------------------------------------------------------------\n");
};

// SUB MENU BUCAS POR ALUNOS
void printSubMenuBusca()
{
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("|                                             BUSCAR  ALUNOS POR                                            |\n");
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("1 - Nome e sobrenome\n");
  printf("2 - Prontuario\n");
  printf("0 - Sair da busca\n");
  printf("-------------------------------------------------------------------------------------------------------------\n");
};

// SUB MENU REMOCÃO DE ALUNOS
void printSubMenuRemocao()
{
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("|                                             REMOÇÃO ALUNOS POR                                            |\n");
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("1 - Nome e sobrenome\n");
  printf("2 - Nome\n");
  printf("3 - Sobrenome\n");
  printf("4 - Prontuário\n");
  printf("5 - Data de nascimento\n");
  printf("6 - Curso\n");
  printf("0 - Sair da remoção\n");
  printf("-------------------------------------------------------------------------------------------------------------\n");
};

//IMPRIMIR TODOS OS ALUNOS
void printAllAlunos(int tamanhoVetor, aluno *alunos)
{
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("|          Nome        |          Sobrenome        | Dia | Mês |  Ano  |        Prontuario        |  CURSO  |\n");
  printf("-------------------------------------------------------------------------------------------------------------\n");
  for (int i = 0; i < tamanhoVetor; i++)
  {
    printf("|  %-18s  | %-25s | %-3d | %-3d | %-5d | %-24d | %-7s |\n", alunos[i].nome, alunos[i].sobrenome, alunos[i].dataNascimento.dia, alunos[i].dataNascimento.mes, alunos[i].dataNascimento.ano, alunos[i].prontuario, alunos[i].curso);
  }
  printf("-------------------------------------------------------------------------------------------------------------\n");
};

// ORDENAR POSICOES
// particionar
int particionar(aluno *vetor, int ini, int fim)
{
  aluno pivo;
  pivo = vetor[fim];

  while (ini < fim)
  {
    while (ini < fim && strcmp(vetor[ini].nome, pivo.nome) <= 0)
    {
      ini++;
    }
    while (ini < fim && strcmp(vetor[ini].nome, pivo.nome) > 0)
    {
      fim--;
    }
    trocaPosicao(&vetor[ini], &vetor[fim]);
  };
};

// trocar de posicao
void trocaPosicao(aluno *a, aluno *b)
{
  aluno alunoAuxiliar = *a;
  *a = *b;
  *b = alunoAuxiliar;
};

// quicksort
void quickSort(aluno *alunos, int posicaoInicial, int posicaoFinal)
{
  int posicaoAtual;
  if (posicaoInicial < posicaoFinal)
  {
    posicaoAtual = particionar(alunos, posicaoInicial, posicaoFinal);
    quickSort(alunos, posicaoInicial, posicaoAtual - 1);
    quickSort(alunos, posicaoAtual, posicaoFinal);
  };
};

int main()
{
  aluno alunos[1000];
  int selecionaOpcaoDashMenu, selecionaOpcaoOrdenacao, selecionaOpcaoBusca, selecionaOpcaoRemocao, countAlunos = 0;

  while (1)
  {
    printMenuPrincipal();
    printf("Selecione uma opção: \n");
    scanf("%d", &selecionaOpcaoDashMenu);
    switch (selecionaOpcaoDashMenu)
    {
    case 1:
      cadastraAluno(alunos, &countAlunos);
      printMenuPrincipal();
      break;
    case 2:
      printSubMenuOrdenacao();
      printf("Selecione uma opção: \n");
      scanf("%d", &selecionaOpcaoOrdenacao);
      switch (selecionaOpcaoOrdenacao)
      {
      case 1:
        /* code */
        break;
      case 2:
        //
        break;
      case 3:
        //
        break;
      case 4:
        //
        break;
      case 5:
        //
        break;
      case 0:
        printf("Voltando para o menu principal...\n\n");
        break;

      default:
        break;
      }
      break;
    case 3:
      printSubMenuBusca();
      scanf("%d", &selecionaOpcaoBusca);
      switch (selecionaOpcaoBusca)
      {
      case 1:
        /* code */
        break;
      case 2:
        //
        break;
      case 0:
        printf("Voltando para o menu principal...\n\n");
        break;
      }
      break;
    case 4:
      printSubMenuRemocao();
      scanf("%d", &selecionaOpcaoRemocao);
      switch (selecionaOpcaoBusca)
      {
      case 1:
        /* code */
        break;
      case 2:
        //
        break;
      case 3:
        /* code */
        break;
      case 4:
        //
        break;
      case 5:
        /* code */
        break;
      case 6:
        /* code */
        break;
      case 0:
        printf("Voltando para o menu principal...\n\n");
        break;
      }
      break;
    case 0:
      printf("Saindo do programa...\n");
      printAllAlunos(countAlunos, alunos);
      exit(0);
      break;
    default:
      break;
    }
  }
  return 0;
}
