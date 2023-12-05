#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void task2(){

    printf("Aufgabe 2: Groesste Zahl\n\n");

    //Seed für den Zufallszahlengenerator initialisieren
    srand(time(NULL));

    //Variablen definieren
    int randomArray[2][3][3];
    int biggestNumber;

    //Array mit zufälligen Zahlen füllen
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                randomArray[i][j][k] = rand();
            }
        }
    }

    //biggestNumber vor der Suche mit einem Wert aus dem Array initialisieren, damit es einen sinnvollen Vergleichswert gibt
    biggestNumber = randomArray[0][0][0];

    //Größte Zahl aus dem Array finden
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(biggestNumber < randomArray[i][j][k]){
                    biggestNumber = randomArray[i][j][k];
                }

            }
        }
    }

    //Größte Zahl ausgeben
    printf("Groesste Zahl aus dem Array: %d\n\n", biggestNumber);
}

int main()
{
    task2();

    return 0;
}
