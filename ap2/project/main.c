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
  for (int i = 0; i <= tamamnhoVetor - 1; i++)
  {
    printf("Nome: %s", alunos[i].nome);
    printf("Sobrenome: %s", alunos[i].sobrenome);
    printf("Dia de nascimento: %d\n", alunos[i].dataNascimento.dia);
    printf("Mes de nascimento: %d\n", alunos[i].dataNascimento.mes);
    printf("Ano de nascimento: %d\n", alunos[i].dataNascimento.ano);
    printf("Prontuario: %d\n", alunos[i].prontuario);
    printf("Curso: %s\n", alunos[i].curso);
  }
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
