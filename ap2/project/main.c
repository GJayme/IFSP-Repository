#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_nome 50
#define TAM_sobrenome 50

// STRUCT DATA
typedef struct data_nascimento
{
  int dia;
  int mes;
  int ano;
} data;

// STRUCT ALUNO
typedef struct cadastra_aluno
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
void printMenu()
{
  printf("---------------MENU---------------\n");
  printf("1 - Cadastrar novo aluno\n");
  printf("2 - Ordenar cadastro de alunos\n");
  printf("3 - Buscar aluno\n");
  printf("4 - Remover aluno\n");
  printf("0 - Sair\n");
  printf("----------------------------------\n");
};

// SUB MENU ORDENAÇAO DE ALUNOS
void printSubMenu()
{
  printf("---------------ORDENAR ALUNOS POR---------------\n");
  printf("1 - Nome e sobrenome\n");
  printf("2 - Sobrenome e nome\n");
  printf("3 - Data de nascimento\n");
  printf("4 - Prontuario\n");
  printf("0 - Curso\n");
  printf("------------------------------------------------\n");
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
}

int main()
{
  aluno alunos[1000];
  int selecionaOpcao, countAlunos = 0;

  while (1)
  {
    printMenu();
    printf("Selecione uma opção: \n");
    scanf("%d", &selecionaOpcao);
    switch (selecionaOpcao)
    {
    case 1:
      cadastraAluno(alunos, &countAlunos);
      printMenu();
      break;
    case 2:
      printf("Tela de ordenação de alunos");
      break;
    case 3:
      printf("Tela de ordenação de pesquisa de alunos");
      break;
    case 4:
      printf("Tela de ordenação de remoção de alunos");
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
