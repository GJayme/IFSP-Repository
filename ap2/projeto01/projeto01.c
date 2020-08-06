/*
  TRABALHO DESENVOLVIDO POR: GABRIEL THOMAZINI JAYME
  AP2 - Projeto 01
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_nome 50
#define TAM_sobrenome 50

// STRUCT DATA
typedef struct data_nascimento
/*
  Criando struct para data de nascimento, nomeando para data.
*/
{
  int dia;
  int mes;
  int ano;
} data;

// STRUCT ALUNO
typedef struct cadastra_aluno
/*
  Criando struct para cadastro de aluno, nomeando para aluno.
*/
{
  char nome[TAM_nome];
  char sobrenome[TAM_sobrenome];
  data dataNascimento;
  int prontuario;
  char curso[4];
} aluno;

enum ordenacao // label para as ordenções
{
  ORDENACAO_POR_NOME = 0,
  ORDENACAO_POR_SOBRENOME = 1,
  ORDENACAO_POR_DATA = 2,
  ORDENACAO_POR_PRONTUARIO = 3,
  ORDENACAO_POR_CURSO = 4,
};

// FUNÇÃO PARA CADASTRAR NOVOS ALUNOS:
void cadastraAluno(aluno *alunos, int numAlunos)
{
  if (numAlunos < 1000)
  {
    printf("Bem vindo a tela de cadastro de aluno.\n");
    printf("Nome: ");
    fflush(stdin);
    scanf("%s", &alunos[numAlunos].nome);

    printf("Sobrenome: ");
    fflush(stdin);
    scanf("%s", &alunos[numAlunos].sobrenome);

    printf("Dia de nascimento: ");
    fflush(stdin);
    scanf("%d", &alunos[numAlunos].dataNascimento.dia);

    printf("Mês de nascimento: ");
    fflush(stdin);
    scanf("%d", &alunos[numAlunos].dataNascimento.mes);

    printf("Ano de nascimento: ");
    fflush(stdin);
    scanf("%d", &alunos[numAlunos].dataNascimento.ano);

    printf("Número do prontuario ");
    fflush(stdin);
    scanf("%d", &alunos[numAlunos].prontuario);

    printf("Curso: ");
    fflush(stdin);
    scanf("%s", &alunos[numAlunos].curso);
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
    printf("|  %-18s  | %-25s | %-3d | %-3d | %-5d | %-24d | %-7s |\n", alunos[i].nome, alunos[i].sobrenome, alunos[i].dataNascimento.dia, alunos[i].dataNascimento.mes, alunos[i].dataNascimento.ano, alunos[i].prontuario, alunos[i].curso);
  }
  printf("-------------------------------------------------------------------------------------------------------------\n");
};

//IMPRIMIR ALUNO ENCONTRADO:
void printAlunoEncontrado(aluno alunos)
{
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("|          Nome        |          Sobrenome        | Dia | Mês |  Ano  |        Prontuario        |  CURSO  |\n");
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("|  %-18s  | %-25s | %-3d | %-3d | %-5d | %-24d | %-7s |\n", alunos.nome, alunos.sobrenome, alunos.dataNascimento.dia, alunos.dataNascimento.mes, alunos.dataNascimento.ano, alunos.prontuario, alunos.curso);
  printf("-------------------------------------------------------------------------------------------------------------\n");
};

// WARNING - ALUNO NÃO ENCONTRADO
void printAlunoNaoEncontrado(aluno AlunoNaoEncontrado)
{
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("|                                                   AVISO                                                   |\n");
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("O aluno %s %s não foi encontrado!\n", AlunoNaoEncontrado.nome, AlunoNaoEncontrado.sobrenome);
  printf("-------------------------------------------------------------------------------------------------------------\n");
};

// FUNÇÃO PARA CONCATENAR:
void concat(char destino[], char primeiro[], char segundo[])
{
  strcpy(destino, primeiro);

  strcat(destino, segundo);
}

// FUNCAO COMPARA DATA DE NASCIMENTO:
int converterData(data data)
{
  return data.ano * 10000 + data.mes * 100 + data.dia;
}

// VERIFICADOR DE QUAL TIPO DE ORDENAÇÃO:
int isOrdenacaoPorNomeSobrenome(enum ordenacao ordenacao, aluno alunoTemp, aluno alunoAtual)
{

  char nomeSobrenomeAtual[TAM_nome + TAM_sobrenome];
  char nomeSobrenomeTemp[TAM_nome + TAM_sobrenome];

  // Ordenar por nome
  if (ordenacao == ORDENACAO_POR_NOME)
  {
    concat(nomeSobrenomeAtual, alunoAtual.nome, alunoAtual.sobrenome);
    concat(nomeSobrenomeTemp, alunoTemp.nome, alunoTemp.sobrenome);
    return (strcmp(nomeSobrenomeTemp, nomeSobrenomeAtual) < 0);
  }

  // Ordenar por sobrenome
  if (ordenacao == ORDENACAO_POR_SOBRENOME)
  {
    concat(nomeSobrenomeAtual, alunoAtual.sobrenome, alunoAtual.nome);
    concat(nomeSobrenomeTemp, alunoTemp.sobrenome, alunoTemp.nome);
    return (strcmp(nomeSobrenomeTemp, nomeSobrenomeAtual) < 0);
  }
  return 0;
}

int isOrdenacaoPorData(enum ordenacao ordenacao, aluno alunoTemp, aluno alunoAtual)
{
  return (ordenacao == ORDENACAO_POR_DATA && (converterData(alunoTemp.dataNascimento) < converterData(alunoAtual.dataNascimento)));
}

int isOrdenacaoProntuario(enum ordenacao ordenacao, aluno alunoTemp, aluno alunoAtual)
{
  return (ordenacao == ORDENACAO_POR_PRONTUARIO && (alunoTemp.prontuario < alunoAtual.prontuario));
}

int isOrdenacaoPorCurso(enum ordenacao ordenacao, aluno alunoTemp, aluno alunoAtual)
{
  return ((ordenacao == ORDENACAO_POR_CURSO) && strcmp(alunoTemp.curso, alunoAtual.curso) < 0);
}

// CHECANDO QUAL ORDENACAO FOI SOLICITADA:
int checarOrdencao(enum ordenacao ordenacao, aluno alunoTemp, aluno alunoAtual)
{
  return (isOrdenacaoPorNomeSobrenome(ordenacao, alunoTemp, alunoAtual) || isOrdenacaoPorData(ordenacao, alunoTemp, alunoAtual) || isOrdenacaoProntuario(ordenacao, alunoTemp, alunoAtual) || isOrdenacaoPorCurso(ordenacao, alunoTemp, alunoAtual));
}

// ORDENAR POSIÇÕES
// FUNÇÃO PARA TROCAR DE POSIÇÃO:
void trocaPosicao(aluno *a, aluno *b)
{
  aluno alunoAuxiliar = *a;
  *a = *b;
  *b = alunoAuxiliar;
};

// QUICK-SORT:
void quickSort(aluno *alunos, int len, enum ordenacao ordenacao)
{
  if (len < 2)
    return;

  aluno pivo = alunos[len / 2];

  int i, j;
  for (i = 0, j = len - 1;; i++, j--)
  {
    while (checarOrdencao(ordenacao, alunos[i], pivo))
      i++;
    while (checarOrdencao(ordenacao, pivo, alunos[j]))
      j--;

    if (i >= j)
      break;

    trocaPosicao(&alunos[i], &alunos[j]);
  }

  quickSort(alunos, i, ordenacao);
  quickSort(alunos + i, len - i, ordenacao);
}

// BUSCA DE ALUNO:
// BUSCA POR NOME E SOBRENOME LINEAR:
void buscarPorNome(aluno *alunos, aluno buscarAluno, int numAlunos)
{
  for (int i = 0; i < numAlunos; i++)
  {
    if (!strcmp(alunos[i].nome, buscarAluno.nome) && !strcmp(alunos[i].sobrenome, buscarAluno.sobrenome))
    {
      printAlunoEncontrado(alunos[i]);
      return;
    }
  }
  printAlunoNaoEncontrado(buscarAluno);
}

// BUSCA POR NOME E SOBRENOME BINÁRIA:
void buscarPorNomeBinario(aluno *alunos, aluno buscarAluno, int numAlunos)
{
  int ini = 0;
  int fim = numAlunos - 1;
  int meio;
  while (ini <= fim)
  {
    meio = (ini <= fim) / 2;
    if (!strcmp(buscarAluno.nome, alunos[meio].nome) && !strcmp(buscarAluno.sobrenome, alunos[meio].sobrenome))
    {
      return printAlunoEncontrado(alunos[meio]);
    }
    if ((strcmp(buscarAluno.nome, alunos[meio].nome) == -1) && (strcmp(buscarAluno.sobrenome, alunos[meio].sobrenome) == -1))
    {
      fim = meio - 1;
    }
    else
    {
      ini = meio + 1;
    }
    printf("Aluno não encontrado!\n");
  }
}

// BUSCA POR PRONTUÁRIO LINEAR:
void bucarPorProntuario(aluno *alunos, aluno buscarAluno, int numAlunos)
{
  for (int i = 0; i < numAlunos; i++)
  {
    if (alunos[i].prontuario == buscarAluno.prontuario)
    {
      printAlunoEncontrado(alunos[i]);
      return;
    }
  }
  printf("Prontuário não cadastrado!\n");
}

// BUSCA POR PRONTUÁRIO BINÁRIO:
void buscarPorProntuarioBinario(aluno *alunos, aluno buscarAluno, int numAlunos)
{
  int ini = 0;
  int fim = numAlunos - 1;
  int meio;
  while (ini <= fim)
  {
    meio = (ini <= fim) / 2;
    if (buscarAluno.prontuario == alunos[meio].prontuario)
    {
      return printAlunoEncontrado(alunos[meio]);
    }
    if (buscarAluno.prontuario < alunos[meio].prontuario)
    {
      fim = meio - 1;
    }
    else
    {
      ini = meio + 1;
    }
    printf("Prontuário não encontrado!\n");
  }
}

// REMOVER ALUNOS:
// REMOVER POR NOME E SOBRENOME:
void removeAlunoNomeSobrenome(aluno *alunos, aluno buscarAluno, int numAlunos)
{
  for (int i = 0; i < numAlunos; i++) // For percorrendo todos os alunos
  {
    if (!strcmp(alunos[i].nome, buscarAluno.nome) && !strcmp(alunos[i].sobrenome, buscarAluno.sobrenome)) // Encontrou o aluno
    {
      for (int j = i; j < numAlunos; j++) //Ajusta o restante dos alunos
      {
        alunos[j] = alunos[j + 1];
      }
      numAlunos--; // Remove um aluno do total
      printAllAlunos(numAlunos, alunos);
      return;
    }
  }
  printf("Nenhum aluno chamado %s %s não foi encontrado!\n", buscarAluno.nome, buscarAluno.sobrenome);
}

// REMOVER POR NOME:
void removeAlunoNome(aluno *alunos, aluno buscarAluno, int numAlunos)
{
  for (int i = 0; i < numAlunos; i++) // For percorrendo todos os alunos
  {
    if (!strcmp(alunos[i].nome, buscarAluno.nome)) // Encontrou o aluno
    {
      for (int j = i; j < numAlunos; j++) //Ajusta o restante dos alunos
      {
        alunos[j] = alunos[j + 1];
      }
      numAlunos--; // Remove um aluno do total
      printAllAlunos(numAlunos, alunos);
      return;
    }
  }
  printf("Nenhum aluno chamado %s não foi encontrado!\n", buscarAluno.nome);
}

// REMOVER POR SOBRENOME SOBRENOME:
void removeAlunoSobrenome(aluno *alunos, aluno buscarAluno, int numAlunos)
{
  for (int i = 0; i < numAlunos; i++) // For percorrendo todos os alunos
  {
    if (!strcmp(alunos[i].sobrenome, buscarAluno.sobrenome)) // Encontrou o aluno
    {
      for (int j = i; j < numAlunos; j++) //Ajusta o restante dos alunos
      {
        alunos[j] = alunos[j + 1];
      }
      numAlunos--; // Remove um aluno do total
      printAllAlunos(numAlunos, alunos);
      return;
    }
  }
  printf("Nenhum aluno com sobrenome de %s não foi encontrado!\n", buscarAluno.sobrenome);
}

// REMOVER POR PRONTUÁRIO:
void removerAlunoPorProntuario(aluno *alunos, aluno buscarAluno, int numAlunos)
{
  for (int i = 0; i < numAlunos; i++)
  {
    if (alunos[i].prontuario == buscarAluno.prontuario)
    {
      for (int j = i; j < numAlunos; j++) //Ajusta o restante dos alunos
      {
        alunos[j] = alunos[j + 1];
      }
      numAlunos--; // Remove um aluno do total
      printAllAlunos(numAlunos, alunos);
      return;
    }
  }
  printf("O prontuário %d não foi encontrado!\n", buscarAluno.prontuario);
}

// REMOVER POR DATA DE NASCIMENTO:
void removerAlunoPorDataNascimento(aluno *alunos, aluno buscarAluno, int numAlunos)
{
  for (int i = 0; i < numAlunos; i++) // For percorrendo todos os alunos
  {
    if ((alunos[i].dataNascimento.ano * 10000 + alunos[i].dataNascimento.mes * 100 + alunos[i].dataNascimento.dia) == (buscarAluno.dataNascimento.ano * 10000 + buscarAluno.dataNascimento.mes * 100 + buscarAluno.dataNascimento.dia)) // Encontrou o aluno
    {
      for (int j = i; j < numAlunos; j++) //Ajusta o restante dos alunos
      {
        alunos[j] = alunos[j + 1];
      }
      numAlunos--; // Remove um aluno do total
      printAllAlunos(numAlunos, alunos);
    }
  }
  printf("Nenhum aluno com data de nascimento de %d-%d-%d não foi encontrado!\n", buscarAluno.dataNascimento.dia, buscarAluno.dataNascimento.mes, buscarAluno.dataNascimento.ano);
}

// CURSO
void removeAlunoCurso(aluno *alunos, aluno buscarAluno, int numAlunos)
{
  for (int i = 0; i < numAlunos; i++) // For percorrendo todos os alunos
  {
    if (!strcmp(alunos[i].curso, buscarAluno.curso)) // Encontrou o aluno
    {
      for (int j = i; j < numAlunos; j++) //Ajusta o restante dos alunos
      {
        alunos[j] = alunos[j + 1];
      }
      numAlunos--; // Remove um aluno do total
      printAllAlunos(numAlunos, alunos);
    }
  }
  printf("Nenhum aluno no curso de %s não foi encontrado!\n", buscarAluno.curso);
}

int main()
{
  aluno alunos[1000];
  aluno buscaAluno;
  int selecionaOpcaoDashMenu, selecionaOpcaoOrdenacao, selecionaOpcaoBusca, selecionaOpcaoRemocao, countAlunos = 0;
  int validaOrdenacaoNome = 0, validaOrdenacaoSobreNome = 0, validaOrdenacaoProntuario = 0;

  while (1)
  {
    printMenuPrincipal();
    printf("Selecione uma opção: \n");
    scanf("%d", &selecionaOpcaoDashMenu);
    switch (selecionaOpcaoDashMenu)
    {
    case 1:
      cadastraAluno(alunos, countAlunos);
      countAlunos += 1;
      printMenuPrincipal();
      break;
    case 2:
      printSubMenuOrdenacao();
      printf("Selecione uma opção: \n");
      scanf("%d", &selecionaOpcaoOrdenacao);
      switch (selecionaOpcaoOrdenacao)
      {
      case 1:
        quickSort(alunos, countAlunos, ORDENACAO_POR_NOME);
        printAllAlunos(countAlunos, alunos);
        validaOrdenacaoNome = 1;
        validaOrdenacaoProntuario = 0;
        break;
      case 2:
        quickSort(alunos, countAlunos, ORDENACAO_POR_SOBRENOME);
        printAllAlunos(countAlunos, alunos);
        validaOrdenacaoSobreNome = 1;
        validaOrdenacaoProntuario = 0;
        break;
      case 3:
        quickSort(alunos, countAlunos, ORDENACAO_POR_DATA);
        printAllAlunos(countAlunos, alunos);
        validaOrdenacaoNome = 0;
        validaOrdenacaoSobreNome = 0;
        validaOrdenacaoProntuario = 0;
        break;
      case 4:
        quickSort(alunos, countAlunos, ORDENACAO_POR_PRONTUARIO);
        printAllAlunos(countAlunos, alunos);
        validaOrdenacaoProntuario = 1;
        validaOrdenacaoSobreNome = 0;
        validaOrdenacaoNome = 0;
        break;
      case 5:
        quickSort(alunos, countAlunos, ORDENACAO_POR_CURSO);
        printAllAlunos(countAlunos, alunos);
        validaOrdenacaoNome = 0;
        validaOrdenacaoSobreNome = 0;
        validaOrdenacaoProntuario = 0;
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
        fflush(stdin);
        scanf("%s", &buscaAluno.nome);

        printf("Sobrenome: ");
        fflush(stdin);
        scanf("%s", &buscaAluno.sobrenome);

        if (validaOrdenacaoNome && validaOrdenacaoSobreNome)
        {
          buscarPorNomeBinario(alunos, buscaAluno, countAlunos);
        }
        else
        {
          buscarPorNome(alunos, buscaAluno, countAlunos);
        }
        break;
      case 2:
        printf("Prontuário: ");
        scanf("%d", &buscaAluno.prontuario);
        if (validaOrdenacaoProntuario)
        {
          buscarPorProntuarioBinario(alunos, buscaAluno, countAlunos);
        }
        else
        {
          bucarPorProntuario(alunos, buscaAluno, countAlunos);
        }
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
      switch (selecionaOpcaoRemocao)
      {
      case 1:
        printf("Nome: ");
        fflush(stdin);
        scanf("%s", &buscaAluno.nome);

        printf("Sobrenome: ");
        fflush(stdin);
        scanf("%s", &buscaAluno.sobrenome);
        removeAlunoNomeSobrenome(alunos, buscaAluno, countAlunos);
        break;
      case 2:
        printf("Nome: ");
        fflush(stdin);
        scanf("%s", &buscaAluno.nome);
        removeAlunoNome(alunos, buscaAluno, countAlunos);
        break;
      case 3:
        printf("Sobrenome: ");
        fflush(stdin);
        scanf("%s", &buscaAluno.sobrenome);
        removeAlunoSobrenome(alunos, buscaAluno, countAlunos);
        break;
      case 4:
        printf("Número do prontuario ");
        fflush(stdin);
        scanf("%d", &buscaAluno.prontuario);
        removerAlunoPorProntuario(alunos, buscaAluno, countAlunos);
        break;
      case 5:
        printf("Dia de nascimento: ");
        fflush(stdin);
        scanf("%d", &buscaAluno.dataNascimento.dia);

        printf("Mês de nascimento: ");
        fflush(stdin);
        scanf("%d", &buscaAluno.dataNascimento.mes);

        printf("Ano de nascimento: ");
        fflush(stdin);
        scanf("%d", &buscaAluno.dataNascimento.ano);

        removerAlunoPorDataNascimento(alunos, buscaAluno, countAlunos);
        break;
      case 6:
        printf("Curso: ");
        fflush(stdin);
        scanf("%s", &buscaAluno.curso);
        removeAlunoCurso(alunos, buscaAluno, countAlunos);
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