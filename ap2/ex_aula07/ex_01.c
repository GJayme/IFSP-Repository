#include <stdio.h>

// – Criar um programa capaz de calcular o tempo entre
// dois horários quaisquer de um determinado dia.
// – O programa deve ler dois horários, no formato
// HH:MM:SS(dois dígitos para hora, dois para minutos e
// dois para segundos). O programa deve verificar se o
// horário é válido(HH entre 00 e 23, MM entre 00 e 59,
// SS entre 00 e 59).
// – O programa deve ter uma função para calcular a
// quantidade de segundos em um horário, e outra função
// para calcular e imprimir a quantidade de horas, minutos
// e segundos em uma quantidade de segundos;

long int calculaTempoParaSegundos(HH, MM, SS)
{
  int HH, MM, SS;
  int totalSegundos;

  totalSegundos = (HH * 60 * 60) + (MM * 60) + (SS);

  return totalSegundos;
}

int main(void)
{
  int HH_1 = 0;
  int MM_1 = 0;
  int SS_1 = 0;
  int HH_2 = 0;
  int MM_2 = 0;
  int SS_2 = 0;

  int difHH = 0;
  int difMM = 0;
  int difSS = 0;
  // Input primeira hora:
  printf("Primeira Hora: \n");
  printf("Digite a primeira HH: \n");
  scanf("%d", &HH_1);

  if (HH_1 >= 0 && HH_1 < 24)
  {
    printf("Digite o primeiro MM: \n");
    scanf("%d", &MM_1);

    if (MM_1 >= 0 && MM_1 < 60)
    {
      printf("Digite o primeiro SS: \n");
      scanf("%d", &SS_1);
    }
  }

  printf("A primeira hora foi de: %d:%d:%d", HH_1, MM_1, SS_1);

  // Input segunda hora:
  printf("Segunda Hora: \n");
  printf("Digite a segunda HH: \n");
  scanf("%d", &HH_2);

  if (HH_2 >= 0 && HH_2 < 24)
  {
    printf("Digite o segundo MM: \n");
    scanf("%d", &MM_2);

    if (MM_2 >= 0 && MM_2 < 60)
    {
      printf("Digite o segundo SS: \n");
      scanf("%d", &SS_2);
    }
  }

  printf("A primeira hora foi de: %d:%d:%d", HH_2, MM_2, SS_2);

  // Verificando a diferença entre as horas:
  return 0;
}
