#include <stdio.h>
#include <string.h>

// c) Elabore um programa que manipule os dados para uma sala de 40 alunos. O
// programa deve receber como entrada (via leitura de teclado):
// - Os nomes dos alunos (máximo 50 caracteres).
// - As duas notas parciais.
// O programa deve calcular e imprimir, numa mesma linha, para cada aluno:
// - O nome, a média final e a freqüência.
// E também deve apresentar:
// - A maior média da turma, e a menor média da turma.
// - A quantidade de alunos aprovados, reprovados e em exame.
// - Uma listagem com o nome dos alunos que irão para a final.

int main(void)
{
  int numeroAlunos;
  printf("Digite a quantidade de aluno: ");
  scanf("%d", &numeroAlunos);

  fflush(stdin);

  // Vetor nome dos alunos
  char nomesAlunos[numeroAlunos][50];

  // vetor das notas
  float notas1[numeroAlunos];
  float notas2[numeroAlunos];

  // vetor frequencia
  int frequenciaAlunos[numeroAlunos];

  // vetor de das médias
  float medias[numeroAlunos];

  float maiorMedia = 0;
  float menorMedia = 999;

  // Quantidades de reprovas, aprovados e em exame
  int quantidadeReprovados = 0;
  int quantidadeAprovados = 0;
  int quantidadeEmExame = 0;

  char alunosEmExame[numeroAlunos][50];

  for (int idx = 0; idx < numeroAlunos; idx++)
  {

    printf("Digite o nome do aluno: \n");
    fgets(nomesAlunos[idx], 50, stdin);
    nomesAlunos[idx][strlen(nomesAlunos[idx]) - 1] = 0;
    fflush(stdin);

    printf("Digite a 1ª nota: \n");
    scanf("%f", &notas1[idx]);

    printf("Digite a 2ª nota: \n");
    scanf("%f", &notas2[idx]);

    printf("Digite a frequência do aluno: \n");
    scanf("%d", &frequenciaAlunos[idx]);

    // calcular media de alunos
    medias[idx] = (notas1[idx] + notas2[idx]) / 2.0;

    printf("O aluno %s tem média igual a %f e frequência de %d \n", nomesAlunos[idx], medias[idx], frequenciaAlunos[idx]);

    // Testes de reprovações:
    if (medias[idx] > 6)
    {
      quantidadeAprovados++;
    }
    else if (medias[idx] < 6 && medias[idx] > 4)
    {
      strcpy(alunosEmExame[idx], nomesAlunos[quantidadeEmExame]);
      quantidadeEmExame++;
    }
    else
    {
      quantidadeReprovados++;
    }

    if (medias[idx] > maiorMedia)
    {
      maiorMedia = medias[idx];
    }

    if (medias[idx] < menorMedia)
    {
      menorMedia = medias[idx];
    }
  }

  // Printando os resultados:
  printf("A menor média é de %f \n", menorMedia);
  printf("A maior média é de %f \n", maiorMedia);
  printf("O número de reprovas foi(foram) de %d: \n", quantidadeReprovados);
  printf("O número de aprovados foi(foram) de %d: \n", quantidadeAprovados);
  for (int i = 0; i < numeroAlunos; i++)
  {
    printf("%s", alunosEmExame[i]);
    printf("\n");
  }
  printf("Totalizando %d \n", quantidadeEmExame);

  return 0;
}