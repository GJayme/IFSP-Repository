#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

// ORDENAR POSIÇÕES
// FUNÇÃO PARA TROCAR DE POSIÇÃO:
void trocaPosicao(aluno *a, aluno *b)
{
  aluno alunoAuxiliar = *a;
  *a = *b;
  *b = alunoAuxiliar;
};

// PARTICIONANDO NOMES:
int particionarNome(aluno *alunos, int posicaoInicial, int posicaoFinal)
{
  aluno pivo;
  pivo = alunos[posicaoFinal];

  while (posicaoInicial < posicaoFinal)
  {
    while (posicaoInicial < posicaoFinal && strcmp(alunos[posicaoInicial].nome, pivo.nome) <= 0)
    {
      posicaoInicial++;
    }
    while (posicaoInicial < posicaoFinal && strcmp(alunos[posicaoFinal].nome, pivo.nome) > 0)
    {
      posicaoFinal--;
    }
    trocaPosicao(&alunos[posicaoInicial], &alunos[posicaoFinal]);
  }
  return posicaoInicial;
};

// QUICKSORT NOME:
void quickSortNome(aluno *alunos, int posicaoInicial, int posicaoFinal)
{
  int posicaoAtual;
  if (posicaoInicial < posicaoFinal)
  {
    posicaoAtual = particionarNome(alunos, posicaoInicial, posicaoFinal);
    quickSortNome(alunos, posicaoInicial, posicaoAtual - 1);
    quickSortNome(alunos, posicaoAtual, posicaoFinal);
  };
};

// PARTICIPAR SOBRENOME
int particionarSobrenome(aluno *vetor, int posicaoInicial, int posicaoFinal)
{
  aluno pivo;
  pivo = vetor[posicaoFinal];

  while (posicaoInicial < posicaoFinal)
  {
    while (posicaoInicial < posicaoFinal && strcmp(vetor[posicaoInicial].sobrenome, pivo.sobrenome) <= 0)
    {
      posicaoInicial++;
    }
    while (posicaoInicial < posicaoFinal && strcmp(vetor[posicaoFinal].sobrenome, pivo.sobrenome) > 0)
    {
      posicaoFinal--;
    }
    trocaPosicao(&vetor[posicaoInicial], &vetor[posicaoFinal]);
  };
  return posicaoInicial;
};

// QUICKSORT SOBRENOME:
void quickSortSobreNome(aluno *alunos, int posicaoInicial, int posicaoFinal)
{
  int posicaoAtual;
  if (posicaoInicial < posicaoFinal)
  {
    posicaoAtual = particionarSobrenome(alunos, posicaoInicial, posicaoFinal);
    quickSortSobreNome(alunos, posicaoInicial, posicaoAtual - 1);
    quickSortSobreNome(alunos, posicaoAtual, posicaoFinal);
  };
};

// PARTICIONAR PRONTUÁRIO:
int particionarProntuario(aluno *vetor, int posicaoInicial, int posicaoFinal)
{
  aluno pivo;
  pivo = vetor[posicaoFinal];

  while (posicaoInicial < posicaoFinal)
  {
    while (posicaoInicial < posicaoFinal && strcmp(vetor[posicaoInicial].prontuario, pivo.prontuario) <= 0)
    {
      posicaoInicial++;
    }
    while (posicaoInicial < posicaoFinal && strcmp(vetor[posicaoFinal].prontuario, pivo.prontuario) > 0)
    {
      posicaoFinal--;
    }
    trocaPosicao(&vetor[posicaoInicial], &vetor[posicaoFinal]);
  };
  return posicaoInicial;
};

// QUICKSORT PRONTUÁRIO:
void quickSortProntuario(aluno *alunos, int posicaoInicial, int posicaoFinal)
{
  int posicaoAtual;
  if (posicaoInicial < posicaoFinal)
  {
    posicaoAtual = particionarProntuario(alunos, posicaoInicial, posicaoFinal);
    quickSortProntuario(alunos, posicaoInicial, posicaoAtual - 1);
    quickSortProntuario(alunos, posicaoAtual, posicaoFinal);
  };
};

// PARTICIONAR CURSO:
int particionarCurso(aluno *vetor, int posicaoInicial, int posicaoFinal)
{
  aluno pivo;
  pivo = vetor[posicaoFinal];

  while (posicaoInicial < posicaoFinal)
  {
    while (posicaoInicial < posicaoFinal && strcmp(vetor[posicaoInicial].curso, pivo.curso) <= 0)
    {
      posicaoInicial++;
    }
    while (posicaoInicial < posicaoFinal && strcmp(vetor[posicaoInicial].curso, pivo.curso) > 0)
    {
      posicaoFinal--;
    }
    trocaPosicao(&vetor[posicaoInicial], &vetor[posicaoFinal]);
  };
  return posicaoInicial;
};

// QUICKSORT CURSO:
void quickSortCurso(aluno *alunos, int posicaoInicial, int posicaoFinal)
{
  int posicaoAtual;
  if (posicaoInicial < posicaoFinal)
  {
    posicaoAtual = particionarCurso(alunos, posicaoInicial, posicaoFinal);
    quickSortCurso(alunos, posicaoInicial, posicaoAtual - 1);
    quickSortCurso(alunos, posicaoAtual, posicaoFinal);
  };
};

// int particionarDataNascimento(aluno *vetor, int ini, int fim)
// {
//   aluno pivo;
//   pivo = vetor[fim];

//   while (ini < fim)
//   {
//     while (ini < fim &&
//            (vetor[ini].dataNascimento.ano * pow(10.0, 4.0) + vetor[ini].dataNascimento.mes * pow(10.0, 2.0) + vetor[ini].dataNascimento.dia) <=
//                (pivo.dataNascimento.ano * pow(10.0, 4.0) + pivo.dataNascimento.mes * pow(10.0, 2.0) + pivo.dataNascimento.dia))
//       ini++;
//     while (ini < fim &&
//            (vetor[fim].dataNascimento.ano * pow(10.0, 4.0) + vetor[fim].dataNascimento.mes * pow(10.0, 2.0) + vetor[fim].dataNascimento.dia) >
//                (pivo.dataNascimento.ano * pow(10.0, 4.0) + pivo.dataNascimento.mes * pow(10.0, 2.0) + pivo.dataNascimento.dia))
//       fim--;
//     trocaPosicao(&vetor[ini], &vetor[fim]);
//   }
//   return ini;
// }

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
        quickSortNome(alunos, 0, countAlunos - 1);
        printAllAlunos(countAlunos, alunos);
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
