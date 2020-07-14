#include <stdio.h>
#include <stdlib.h>

#define TAM_nome 50
#define TAM_sobrenome 50

// MENU
void printMenu()
{
  printf("---------------MENU---------------\n");
  printf("1 - Cadastrar novo aluno\n");
  printf("2 - Ordenar cadastro de alunos\n");
  printf("3 - Buscar aluno\n");
  printf("4 - Remover Aluno\n");
  printf("0 - Sair\n");
  printf("----------------------------------\n");
}
// FUNCAO CADASTRA ALUNO
int cadastraAluno()
{
  // ESTRUCT DATA
  struct data_nascimento
  {
    int dia;
    int mes;
    int ano;
  };

  // REGISTRA ALUNO
  struct cadastra_aluno
  {
    char nome[TAM_nome];
    char sobrenome[TAM_sobrenome];
    struct data_nascimento dataNascimento;
    int prontuario;
    char curso;
  } aluno;

  printf("Nome:\n");
  scanf("%c", aluno.nome);

  printf("Sobrenome:\n");
  scanf("%c", aluno.sobrenome);

  printf("Dia de nascimento:\n");
  scanf("%c", aluno.dataNascimento.dia);

  printf("Mês de nascimento:\n");
  scanf("%c", aluno.dataNascimento.mes);

  printf("Ano de nascimento:\n");
  scanf("%c", aluno.dataNascimento.ano);

  printf("Número do prontuario\n");
  scanf("%c", aluno.prontuario);

  printf("Curso: \n");
  scanf("%c", aluno.curso);

  return aluno;
};

int main()
{
  int selecionaOpcao;
  char aluno;
  char alunos[1000];

  printMenu();
  printf("Selecione uma opção: \n");
  scanf("%d", &selecionaOpcao);
  if (selecionaOpcao == 1)
  {
    printf("Bem vindo a tela de cadastro de aluno");
    aluno = cadastraAluno();
  }

  return 0;
}
