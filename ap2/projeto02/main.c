/*
  TRABALHO DESENVOLVIDO POR: GABRIEL THOMAZINI JAYME
  Projeto 02
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

// FUNÇÃO PARA CADASTRAR NOVOS ALUNOS:
void cadastraAluno(aluno *alunos, int *numAlunos)
{
  if (*numAlunos < 1000)
  {
    printf("Bem vindo a tela de cadastro de aluno.\n");
    printf("Nome: ");
    fflush(stdin);
    scanf("%s", &alunos[*numAlunos].nome);

    printf("Sobrenome: ");
    fflush(stdin);
    scanf("%s", &alunos[*numAlunos].sobrenome);

    printf("Dia de nascimento: ");
    fflush(stdin);
    scanf("%d", &alunos[*numAlunos].dataNascimento.dia);

    printf("Mês de nascimento: ");
    fflush(stdin);
    scanf("%d", &alunos[*numAlunos].dataNascimento.mes);

    printf("Ano de nascimento: ");
    fflush(stdin);
    scanf("%d", &alunos[*numAlunos].dataNascimento.ano);

    printf("Número do prontuario ");
    fflush(stdin);
    scanf("%d", &alunos[*numAlunos].prontuario);

    printf("Curso: ");
    fflush(stdin);
    scanf("%s", &alunos[*numAlunos].curso);

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

//SUB MENU METODOS DE ORDENAÇÃO:
void printSubMenuMetodosDeOrdenacao()
{
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("|                                        QUAL METODO DESEJA UTILIZAR?                                        |\n");
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("1 - Quick Sort\n");
  printf("2 - Merge Sort\n");
  printf("3 - Insertion Sort\n");
  printf("4 - Selection Sort\n");
  printf("0 - Sair do métodos de ordenação\n");
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
/*
  Separar o vetor em duas partes e ordena
*/
{
  aluno pivo;
  pivo = alunos[posicaoFinal];
  int tamanho = TAM_nome + TAM_sobrenome;

  char nomeSobrenomeInicial[tamanho];
  char nomeSobrenomeFinal[tamanho];
  char pivoNomeSobrenome[tamanho];

  while (posicaoInicial < posicaoFinal)
  {
    concat(nomeSobrenomeInicial, alunos[posicaoInicial].nome, alunos[posicaoInicial].sobrenome);
    concat(nomeSobrenomeFinal, alunos[posicaoFinal].nome, alunos[posicaoFinal].sobrenome);
    concat(pivoNomeSobrenome, pivo.nome, pivo.sobrenome);

    while (posicaoInicial < posicaoFinal && strcmp(nomeSobrenomeInicial, pivoNomeSobrenome) <= 0) // posição inicial < que posição final e nomeSobrenome <= pivoSobrenome
    {
      posicaoInicial++;
      concat(nomeSobrenomeInicial, alunos[posicaoInicial].nome, alunos[posicaoInicial].sobrenome);
    }
    while (posicaoInicial < posicaoFinal && strcmp(nomeSobrenomeFinal, pivoNomeSobrenome) > 0)
    {
      posicaoFinal--;
      concat(nomeSobrenomeFinal, alunos[posicaoFinal].nome, alunos[posicaoFinal].sobrenome);
      concat(pivoNomeSobrenome, pivo.nome, pivo.sobrenome);
    }
    trocaPosicao(&alunos[posicaoInicial], &alunos[posicaoFinal]);
  }
  return posicaoInicial;
};

// QUICKSORT NOME:
/*
  Ordena cada subvetor
*/
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
int particionarSobrenome(aluno *alunos, int posicaoInicial, int posicaoFinal)
{
  aluno pivo;
  pivo = alunos[posicaoFinal];
  int tamanho = TAM_nome + TAM_sobrenome;

  char sobrenomeNomeInicial[tamanho];
  char sobrenomeNomeFinal[tamanho];
  char pivoSobrenomeNome[tamanho];

  while (posicaoInicial < posicaoFinal)
  {
    concat(sobrenomeNomeInicial, alunos[posicaoInicial].sobrenome, alunos[posicaoInicial].nome);
    concat(sobrenomeNomeFinal, alunos[posicaoFinal].sobrenome, alunos[posicaoFinal].nome);
    concat(pivoSobrenomeNome, pivo.sobrenome, pivo.nome);

    while (posicaoInicial < posicaoFinal && strcmp(sobrenomeNomeInicial, pivoSobrenomeNome) <= 0)
    {
      posicaoInicial++;
      concat(sobrenomeNomeInicial, alunos[posicaoInicial].sobrenome, alunos[posicaoInicial].nome);
    }
    while (posicaoInicial < posicaoFinal && strcmp(sobrenomeNomeFinal, pivoSobrenomeNome) > 0)
    {
      posicaoFinal--;
      concat(sobrenomeNomeFinal, alunos[posicaoFinal].sobrenome, alunos[posicaoFinal].nome);
      concat(pivoSobrenomeNome, pivo.sobrenome, pivo.nome);
    }
    trocaPosicao(&alunos[posicaoInicial], &alunos[posicaoFinal]);
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
    while (posicaoInicial < posicaoFinal && (vetor[posicaoInicial].prontuario <= pivo.prontuario))
    {
      posicaoInicial++;
    }
    while (posicaoInicial < posicaoFinal && (vetor[posicaoFinal].prontuario > pivo.prontuario))
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
    //CONVERTENDO AS DATAS EM EM INT E SOMANDO PARA PODER EFETUAR AS COMPARAÇÕES
    while (posicaoInicial < posicaoFinal && (vetor[posicaoInicial].dataNascimento.ano * 10000 + vetor[posicaoInicial].dataNascimento.mes * 100 + vetor[posicaoInicial].dataNascimento.dia) <= (pivo.dataNascimento.ano * 10000 + pivo.dataNascimento.mes * 100 + pivo.dataNascimento.dia))
    {
      posicaoInicial++;
    };

    while (posicaoInicial < posicaoFinal && (vetor[posicaoFinal].dataNascimento.ano * 10000 + vetor[posicaoFinal].dataNascimento.mes * 100 + vetor[posicaoFinal].dataNascimento.dia) > (pivo.dataNascimento.ano * 10000 + pivo.dataNascimento.mes * 100 + pivo.dataNascimento.dia))
    {
      posicaoFinal--;
    }
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

// INSERTION-SORT:
// INSERT-SORT-NOME:
void insertionSortNome(aluno *alunos, int numAlunos)
{
  for (int i = 1; i < numAlunos; ++i)
  {
    aluno tmp = alunos[i];
    int j = i;
    while (j > 0 && strcmp(tmp.nome, alunos[j - 1].nome) <= 0)
    {
      alunos[j] = alunos[j - 1];
      --j;
    }
    alunos[j] = tmp;
  }
}
// INSERT-SORT-SOBRENOME:
void insertionSortSobrenome(aluno *alunos, int numAlunos)
{
  for (int i = 1; i < numAlunos; ++i)
  {
    aluno tmp = alunos[i];
    int j = i;
    while (j > 0 && strcmp(tmp.sobrenome, alunos[j - 1].sobrenome) <= 0)
    {
      alunos[j] = alunos[j - 1];
      --j;
    }
    alunos[j] = tmp;
  }
}
// INSET-SORT DATA DE NASCIMENTO:
void insertionSortDataDeNascimento(aluno *alunos, int numAlunos)
{
  for (int i = 1; i < numAlunos; ++i)
  {
    aluno tmp = alunos[i];
    int j = i;
    while (j > 0 && (tmp.dataNascimento.ano * 10000 + tmp.dataNascimento.mes * 100 + tmp.dataNascimento.dia <= alunos[j - 1].dataNascimento.ano * 10000 + alunos[j - 1].dataNascimento.mes * 100 + alunos[j - 1].dataNascimento.dia))
    {
      alunos[j] = alunos[j - 1];
      --j;
    }
    alunos[j] = tmp;
  }
}
// INSERT-SORT PRONTUÁRIO:
void insertionSortProntuario(aluno *alunos, int numAlunos)
{
  for (int i = 1; i < numAlunos; ++i)
  {
    aluno tmp = alunos[i];
    int j = i;
    while (j > 0 && (tmp.prontuario <= alunos[j - 1].prontuario))
    {
      alunos[j] = alunos[j - 1];
      --j;
    }
    alunos[j] = tmp;
  }
}
// INSERTION-SORT CURSO:
void insertionSortCurso(aluno *alunos, int numAlunos)
{
  for (int i = 1; i < numAlunos; ++i)
  {
    aluno tmp = alunos[i];
    int j = i;
    while (j > 0 && strcmp(tmp.curso, alunos[j - 1].curso) <= 0)
    {
      alunos[j] = alunos[j - 1];
      --j;
    }
    alunos[j] = tmp;
  }
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
    printf("Aluno não encontrado!");
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
  printf("Prontuário não cadastrado!");
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
    printf("Prontuário não encontrado!");
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
      return;
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
      return;
    }
  }
  printf("Nenhum aluno no curso de %s não foi encontrado!\n", buscarAluno.curso);
}

int main()
{
  aluno alunos[1000];
  aluno buscaAluno;
  int selecionaOpcaoDashMenu, selecionaOpcaoOrdenacao, selecionaMetodoDeOrdenacao, selecionaOpcaoBusca, selecionaOpcaoRemocao, countAlunos = 0;
  int validaOrdenacaoNome = 0, validaOrdenacaoSobreNome = 0, validaOrdenacaoProntuario = 0;

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
        printSubMenuMetodosDeOrdenacao();
        printf("Selecione uma opção: \n");
        scanf("%d", &selecionaMetodoDeOrdenacao);
        switch (selecionaMetodoDeOrdenacao)
        {
        case 1:
          quickSortNome(alunos, 0, countAlunos - 1);
          printAllAlunos(countAlunos, alunos);
          validaOrdenacaoNome = 1;
          validaOrdenacaoProntuario = 0;
          break;
        case 2:
          //MERGE SORT
          break;
        case 3:
          insertionSortNome(alunos, countAlunos);
          printAllAlunos(countAlunos, alunos);
          validaOrdenacaoSobreNome = 1;
          validaOrdenacaoProntuario = 0;
          break;
        case 4:
          //SELECTION SORT
          break;
        case 0:
          printf("Voltando para o menu principal...\n\n");
          break;
        default:
          printf("Comando inválido!\n");
          break;
        }
        break;
      case 2:
        printSubMenuMetodosDeOrdenacao();
        printf("Selecione uma opção: \n");
        scanf("%d", &selecionaMetodoDeOrdenacao);
        switch (selecionaMetodoDeOrdenacao)
        {
        case 1:
          quickSortSobreNome(alunos, 0, countAlunos - 1);
          printAllAlunos(countAlunos, alunos);
          validaOrdenacaoSobreNome = 1;
          validaOrdenacaoProntuario = 0;
          break;
        case 2:
          //MERGE SORT
          break;
        case 3:
          insertionSortSobrenome(alunos, countAlunos);
          printAllAlunos(countAlunos, alunos);
          validaOrdenacaoSobreNome = 1;
          validaOrdenacaoProntuario = 0;
          break;
        case 4:
          //SELECTION SORT
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
        printSubMenuMetodosDeOrdenacao();
        printf("Selecione uma opção: \n");
        scanf("%d", &selecionaMetodoDeOrdenacao);
        switch (selecionaMetodoDeOrdenacao)
        {
        case 1:
          quickSortDataDeNascimento(alunos, 0, countAlunos - 1);
          printAllAlunos(countAlunos, alunos);
          validaOrdenacaoNome = 0;
          validaOrdenacaoSobreNome = 0;
          validaOrdenacaoProntuario = 0;
          break;
        case 2:
          //MERGE SORT
          break;
        case 3:
          insertionSortDataDeNascimento(alunos, countAlunos);
          printAllAlunos(countAlunos, alunos);
          validaOrdenacaoNome = 0;
          validaOrdenacaoSobreNome = 0;
          validaOrdenacaoProntuario = 0;
          break;
        case 4:
          //SELECTION SORT
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
        printSubMenuMetodosDeOrdenacao();
        printf("Selecione uma opção: \n");
        scanf("%d", &selecionaMetodoDeOrdenacao);
        switch (selecionaMetodoDeOrdenacao)
        {
        case 1:
          quickSortProntuario(alunos, 0, countAlunos - 1);
          printAllAlunos(countAlunos, alunos);
          validaOrdenacaoProntuario = 1;
          validaOrdenacaoSobreNome = 0;
          validaOrdenacaoNome = 0;
          break;
        case 2:
          //MERGE SORT
          break;
        case 3:
          insertionSortProntuario(alunos, countAlunos);
          printAllAlunos(countAlunos, alunos);
          validaOrdenacaoProntuario = 1;
          validaOrdenacaoSobreNome = 0;
          validaOrdenacaoNome = 0;
          break;
        case 4:
          //SELECTION SORT
          break;
        case 0:
          printf("Voltando para o menu principal...\n\n");
          break;
        default:
          printf("Comando inválido!\n");
          break;
        }
        break;
      case 5:
        printSubMenuMetodosDeOrdenacao();
        printf("Selecione uma opção: \n");
        scanf("%d", &selecionaMetodoDeOrdenacao);
        switch (selecionaMetodoDeOrdenacao)
        {
        case 1:
          quickSortCurso(alunos, 0, countAlunos - 1);
          printAllAlunos(countAlunos, alunos);
          validaOrdenacaoNome = 0;
          validaOrdenacaoSobreNome = 0;
          validaOrdenacaoProntuario = 0;
          break;
        case 2:
          //MERGE SORT
          break;
        case 3:
          insertionSortCurso(alunos, countAlunos);
          printAllAlunos(countAlunos, alunos);
          validaOrdenacaoNome = 0;
          validaOrdenacaoSobreNome = 0;
          validaOrdenacaoProntuario = 0;
          break;
        case 4:
          //SELECTION SORT
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