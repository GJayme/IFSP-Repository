package poo_java_02_list;

import java.util.Scanner;

public class Ex03 {
    public static void main(String[] args) {
        int[] array;
        int[] finalArray = new int [10];

        array = makeArray();

        for (int i = 0; i < array.length; i++) {
            int count = 0;
            for (int j = 0; j < array.length; j++) {
               if(array[i] == array[j]) {
                   count += 1;
               }
               if (count > 1) {
                   System.out.println("Erro");
                   return;
               }
            }
        }

        for (int i = 0; i < array.length; i++) {
            finalArray[i] = array[i];
        }

        rotulo:
        for (int i = 5; i < finalArray.length; i++) {
            Scanner scanner = new Scanner(System.in);

            int numTemp = scanner.nextInt();
            int [] arrayTemp = new int [10];
            int canAdd = 0;

            for (int j = 0; j < finalArray.length; j++) {
                if (finalArray[j] == numTemp) {
                    canAdd += 1;

                    for (int k = 0; k < finalArray.length; k++) {
                        if (finalArray[k] != numTemp) {
                            arrayTemp[k] = finalArray[k];
                        }
                    }
                    finalArray = arrayTemp;
                    printArray(finalArray);
                    if (finalArray == null || finalArray.length == 0) {
                        break rotulo;
                    }
                }
            }

            if (canAdd == 0 ) {
                finalArray[i] = numTemp;
                printArray(finalArray);
            } else {
                i--;
            }
        }
    }

    public static void printArray (int[] array) {
        for (int j : array) {
            System.out.println(j);
        }
    }

    public static int [] makeArray() {
        int[] array = new int[5];

        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < array.length; i++) {
            array[i] = scanner.nextInt();
        }
        return array;
    }

}
