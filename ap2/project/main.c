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

// SUB MENU ORDENAÇÃO DE ALUNOS
void printSubMenuOrdenacao()
{
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("|                                             ORDENAR ALUNOS POR                                             |\n");
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("1 - Nome e sobrenome\n");
  printf("2 - Sobrenome e nome\n");
  printf("3 - Data de nascimento\n");
  printf("4 - Prontuário\n");
  printf("5 - Curso\n");
  printf("0 - Sair de ordenação\n");
  printf("-------------------------------------------------------------------------------------------------------------\n");
};

// SUB MENU BUSCAS POR ALUNOS
void printSubMenuBusca()
{
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("|                                             BUSCAR  ALUNOS POR                                            |\n");
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("1 - Nome e sobrenome\n");
  printf("2 - Prontuário\n");
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
    alunos[i].nome[strcspn(alunos[i].nome, "\n")] = 0;           //tirando a quebra de linha que o fgets coloca
    alunos[i].sobrenome[strcspn(alunos[i].sobrenome, "\n")] = 0; //tirando a quebra de linha que o fgets coloca
    printf("|  %-18s  | %-25s | %-3d | %-3d | %-5d | %-24d | %-7s |\n", alunos[i].nome, alunos[i].sobrenome, alunos[i].dataNascimento.dia, alunos[i].dataNascimento.mes, alunos[i].dataNascimento.ano, alunos[i].prontuario, alunos[i].curso);
  }
  printf("-------------------------------------------------------------------------------------------------------------\n");
};

//IMPRIMIR ALUNO ENCONTRADO:
void printAlunoEncontrado(aluno alunos)
{
  alunos.nome[strcspn(alunos.nome, "\n")] = 0;           //tirando a quebra de linha que o fgets coloca
  alunos.sobrenome[strcspn(alunos.sobrenome, "\n")] = 0; //tirando a quebra de linha que o fgets coloca
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("|          Nome        |          Sobrenome        | Dia | Mês |  Ano  |        Prontuario        |  CURSO  |\n");
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("|  %-18s  | %-25s | %-3d | %-3d | %-5d | %-24d | %-7s |\n", alunos.nome, alunos.sobrenome, alunos.dataNascimento.dia, alunos.dataNascimento.mes, alunos.dataNascimento.ano, alunos.prontuario, alunos.curso);
  printf("-------------------------------------------------------------------------------------------------------------\n");
};

// WARNING - ALUNO NÃO ENCONTRADO
void printAlunoNaoEncontrado(aluno AlunoNaoEncontrado)
{
  AlunoNaoEncontrado.nome[strcspn(AlunoNaoEncontrado.nome, "\n")] = 0;           //tirando a quebra de linha que o fgets coloca
  AlunoNaoEncontrado.sobrenome[strcspn(AlunoNaoEncontrado.sobrenome, "\n")] = 0; //tirando a quebra de linha que o fgets coloca
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("|                                                   AVISO                                                   |\n");
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("O aluno %s %s não foi encontrado!\n", AlunoNaoEncontrado.nome, AlunoNaoEncontrado.sobrenome);
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

// PARTICIONAR DATA DE NASCIMENTO:
int particionarDataNascimento(aluno *vetor, int posicaoInicial, int posicaoFinal)
{
  aluno pivo;
  pivo = vetor[posicaoFinal];

  while (posicaoInicial < posicaoFinal)
  {
    while (posicaoInicial < posicaoFinal &&
           (vetor[posicaoInicial].dataNascimento.ano * 10000 + vetor[posicaoInicial].dataNascimento.mes * 100 + vetor[posicaoInicial].dataNascimento.dia) <= //CONVERTENDO AS DATAS EM EM INT E SOMANDO PARA PODER EFETUAR AS COMPARAÇÕES
               (pivo.dataNascimento.ano * 10000 + pivo.dataNascimento.mes * 100 + pivo.dataNascimento.dia))
      posicaoInicial++;
    while (posicaoInicial < posicaoFinal &&
           (vetor[posicaoFinal].dataNascimento.ano * 10000 + vetor[posicaoFinal].dataNascimento.mes * 100 + vetor[posicaoFinal].dataNascimento.dia) >
               (pivo.dataNascimento.ano * 10000 + pivo.dataNascimento.mes * 100 + pivo.dataNascimento.dia))
      posicaoFinal--;
    trocaPosicao(&vetor[posicaoInicial], &vetor[posicaoFinal]);
  }
  return posicaoInicial;
}

// QUICKSORT DATA DE NASCIMENTO:
void quickSortDataDeNascimento(aluno *alunos, int posicaoInicial, int posicaoFinal)
{
  int posicaoAtual;
  if (posicaoInicial < posicaoFinal)
  {
    posicaoAtual = particionarDataNascimento(alunos, posicaoInicial, posicaoFinal);
    quickSortDataDeNascimento(alunos, posicaoInicial, posicaoAtual - 1);
    quickSortDataDeNascimento(alunos, posicaoAtual, posicaoFinal);
  };
};

// BUSCA DE ALUNO:
// BUSCA POR NOME:
int buscarPorNome(aluno *alunos, aluno *buscarAluno, int numAlunos)
{
  for (int i = 0; i < numAlunos; i++)
  {
    if (!strcmp(alunos[i].nome, (*buscarAluno).nome) & !strcmp(alunos[i].sobrenome, (*buscarAluno).sobrenome))
    {
      (*buscarAluno).dataNascimento.dia = alunos[i].dataNascimento.dia;
      (*buscarAluno).dataNascimento.mes = alunos[i].dataNascimento.mes;
      (*buscarAluno).dataNascimento.ano = alunos[i].dataNascimento.ano;
      (*buscarAluno).prontuario = alunos[i].prontuario;
      strcpy((*buscarAluno).curso, alunos[i].curso);
      return 1;
    }
  }

  return 0;
}

int main()
{
  aluno alunos[1000];
  aluno buscaAluno;
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
        quickSortSobreNome(alunos, 0, countAlunos - 1);
        printAllAlunos(countAlunos, alunos);
        break;
      case 3:
        quickSortDataDeNascimento(alunos, 0, countAlunos - 1);
        printAllAlunos(countAlunos, alunos);
        break;
      case 4:
        quickSortProntuario(alunos, 0, countAlunos - 1);
        printAllAlunos(countAlunos, alunos);
        break;
      case 5:
        quickSortCurso(alunos, 0, countAlunos - 1);
        printAllAlunos(countAlunos, alunos);
        break;
      case 0:
        printf("Voltando para o menu principal...\n\n");
        break;
      default:
        printf("Comando inválido!\n");
        break;
      }
      break;
    case 3:
      printSubMenuBusca();
      scanf("%d", &selecionaOpcaoBusca);
      switch (selecionaOpcaoBusca)
      {
      case 1:
        printf("Nome: ");
        getchar();
        fgets(buscaAluno.nome, TAM_nome, stdin);

        printf("Sobrenome: ");
        fgets(buscaAluno.sobrenome, TAM_sobrenome, stdin);
        if (buscarPorNome(alunos, &buscaAluno, countAlunos))
        {
          printAlunoEncontrado(buscaAluno);
        }
        else
        {
          printAlunoNaoEncontrado(buscaAluno);
        }
        break;
      case 2:
        //
        break;
      case 0:
        printf("Voltando para o menu principal...\n\n");
        break;
      default:
        printf("Comando inválido!\n");
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
      default:
        printf("Comando inválido!\n");
        break;
      }
      break;
    case 0:
      printf("Saindo do programa...\n");
      printAllAlunos(countAlunos, alunos);
      exit(0);
      break;
    default:
      printf("Comando inválido!\n");
      break;
    }
  }
  return 0;
}
