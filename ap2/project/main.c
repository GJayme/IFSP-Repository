#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_nome 50
#define TAM_sobrenome 50

// STRUCT DATA
struct data_nascimento
{
  int dia;
  int mes;
  int ano;
};

// STRUCT ALUNO
struct cadastra_aluno
{
  char nome[TAM_nome];
  char sobrenome[TAM_sobrenome];
  struct data_nascimento dataNascimento;
  int prontuario;
  char curso[4];
} alunos[1000];

// MENU
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

//PRINT ALL ALUNOS
void printAllAlunos(int tamamnhoVetor)
{
  printf("-------------------------------------------------------------------------------------------------------------\n");
  printf("|          Nome        |          Sobrenome        | Dia | Mês |  Ano  |        Prontuario        |  CURSO  |\n");
  printf("-------------------------------------------------------------------------------------------------------------\n");
  for (int i = 0; i < tamamnhoVetor; i++)
  {
    printf("|  %-18s  | %-25s | %-3d | %-3d | %-5d | %-24d | %-7s |\n", alunos[i].nome, alunos[i].sobrenome, alunos[i].dataNascimento.dia, alunos[i].dataNascimento.mes, alunos[i].dataNascimento.ano, alunos[i].prontuario, alunos[i].curso);
  }
  printf("-------------------------------------------------------------------------------------------------------------\n");
}

int main()
{
  int selecionaOpcao, countAlunos = 0;

  while (1)
  {
    printMenu();
    printf("Selecione uma opção: \n");
    scanf("%d", &selecionaOpcao);
    switch (selecionaOpcao)
    {
    case 1:
      if (countAlunos == 0)
      {
        printf("Bem vindo a tela de cadastro de aluno.\n");
        printf("Nome: ");
        getchar();
        fgets(alunos[countAlunos].nome, TAM_nome, stdin);

        printf("Sobrenome: ");
        fgets(alunos[countAlunos].sobrenome, TAM_sobrenome, stdin);

        printf("Dia de nascimento: ");
        scanf("%d", &alunos[countAlunos].dataNascimento.dia);

        printf("Mês de nascimento: ");
        scanf("%d", &alunos[countAlunos].dataNascimento.mes);

        printf("Ano de nascimento: ");
        scanf("%d", &alunos[countAlunos].dataNascimento.ano);

        printf("Número do prontuario ");
        scanf("%d", &alunos[countAlunos].prontuario);

        printf("Curso: ");
        getchar();
        fgets(alunos[countAlunos].curso, 4, stdin);
      }
      else
      {
        printf("Bem vindo a tela de cadastro de aluno.\n");
        printf("Nome: ");
        getchar();
        fgets(alunos[countAlunos].nome, TAM_nome, stdin);

        printf("Sobrenome: ");
        fgets(alunos[countAlunos].sobrenome, TAM_sobrenome, stdin);

        printf("Dia de nascimento: ");
        scanf("%d", &alunos[countAlunos].dataNascimento.dia);

        printf("Mês de nascimento: ");
        scanf("%d", &alunos[countAlunos].dataNascimento.mes);

        printf("Ano de nascimento: ");
        scanf("%d", &alunos[countAlunos].dataNascimento.ano);

        printf("Número do prontuario ");
        scanf("%d", &alunos[countAlunos].prontuario);

        printf("Curso: ");
        getchar();
        fgets(alunos[countAlunos].curso, 4, stdin);
      }
      alunos[countAlunos].nome[strcspn(alunos[countAlunos].nome, "\n")] = 0;           //tirando a quebra de linha que o fgets coloca
      alunos[countAlunos].sobrenome[strcspn(alunos[countAlunos].sobrenome, "\n")] = 0; //tirando a quebra de linha que o fgets coloca
      countAlunos += 1;
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
      printAllAlunos(countAlunos);
      exit(0);
      break;
    default:
      break;
    }
  }
  return 0;
}
