#include <stdio.h>
#include <math.h>

// 2- Elabore um programa para ler as notas dos 22 alunos
// da turma, calcule a média da turma, e calcule também
// quantos alunos tiveram notas abaixo da média, e quantos
// tiveram notas acima da média.

int main(void)
{
  int numAlunos, mediaAluno, notasAbaixo, notasAcima;
  int contAlunos;

  float notaAluno, totalNota, mediaTurma;
  char nomeAluno[50];

  numAlunos = 22;
  mediaAluno = 6;
  mediaTurma = 0.00;
  notasAbaixo = 0;
  notasAcima = 0;
  contAlunos = 0;
  notaAluno = 0.00;
  totalNota = 0.00;

  while (contAlunos < numAlunos)
  {
    printf("Nota: ");
    scanf("%f", &notaAluno);

    totalNota = totalNota + notaAluno;

    if (notaAluno > mediaAluno)
    {
      notasAcima++;
    }
    else
    {
      notasAbaixo++;
    }
    contAlunos++;
  }

  mediaTurma = totalNota / numAlunos;

  printf("A média da turma foi de: %f\n", mediaTurma);
  printf("O número de alunos com nota abaixo da média foram de: %d\n", notasAbaixo);
  printf("O número de alunos com nota acima foram de: %d\n", notasAcima);
}