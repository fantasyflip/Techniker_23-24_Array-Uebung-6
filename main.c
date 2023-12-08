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

void task3(){

    printf("Aufgabe 3: Kleinste und Groesste Zahl tauschen\n\n");

    //Variablen definieren
    int randomArray[3][5];
    int biggestNumber, lowestNumber;
    int biggestNumberCords[2], lowestNumberCords[2];

    //Seed für den Zufallszahlengenerator initialisieren
    srand(time(NULL));

    //Array mit zufälligen Zahlen füllen
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            randomArray[i][j] = rand();
        }
    }

    //Array ausgeben
    printf("Array ausgeben:\n");

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            printf("%d\t", randomArray[i][j]);
        }
        printf("\n");
    }

    biggestNumber = randomArray[0][0];
    lowestNumber = randomArray[0][0];

    //Größte & kleinste Zahl finden und koordinaten abspeichern
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            if(biggestNumber < randomArray[i][j]){
                biggestNumber = randomArray[i][j];
                biggestNumberCords[1]=i;
                biggestNumberCords[0]=j;
            }
            if(lowestNumber > randomArray[i][j]){
                lowestNumber = randomArray[i][j];
                lowestNumberCords[1]=i;
                lowestNumberCords[0]=j;
            }
        }
    }

    //Größte und Kleinste Zahl ausgeben
    printf("\nBiggest: %d - at x: %d y: %d\n", biggestNumber, biggestNumberCords[0], biggestNumberCords[1]);
    printf("Lowest: %d - at x: %d y: %d\n\n", lowestNumber, lowestNumberCords[0], lowestNumberCords[1]);

    //Größte und kleinste Zahl tauschen
    randomArray[biggestNumberCords[1]][biggestNumberCords[0]] = lowestNumber;
    randomArray[lowestNumberCords[1]][lowestNumberCords[0]] = biggestNumber;

    //Array ausgeben
    printf("Array ausgeben:\n");

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            printf("%d\t", randomArray[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void task4(){

    printf("Aufgabe 4\n\n");

    //4 a) - Variable definieren
    int array[5][7];
    int counter = 1;

    //4 b) - Zahlen in Array schreiben
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 7; j++){
            array[i-1][j-1] = counter++;
        }
    }

    printf("\n4 c) - Array ausgeben\n\n");

    //4 c) - Array ausgeben
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 7; j++){
            printf("%d\t",array[i-1][j-1]);
        }
        printf("\n");
    }

    printf("\n4 d) - Array Spaltenweise ausgeben\n\n");

    //4 d) - Array Spaltenweise ausgeben
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 5; j++){
            printf("%d\t", array[j][i]);
        }
        printf("\n");
    }

    printf("\n4 e) - Array ruechwaerts ausgeben\n\n");

    //4 e) - Array rückwärts ausgeben
    for(int i = 5; i > 0; i--){
        for(int j = 7; j > 0; j--){
            printf("%d\t", array[i-1][j-1]);
        }
        printf("\n");
    }

    printf("\n4 f) - Zeilensummen berechnen und ausgeben\n\n");

    //4 f) - Zeilensummen berechnen und ausgeben
    int rowSums[5];
    for(int i = 0; i < 5; i++){
        rowSums[i] = 0;
        for(int j = 0; j < 7; j++){
            rowSums[i] = rowSums[i] + array[i][j];
        }
        printf("%d\t", rowSums[i]);
    }

    printf("\n\n4 g) - Spaltensummen berechnen und ausgeben\n\n");

    //4 f) - Spaltensummen berechnen und ausgeben\n\n
    int colSums[7];
    for(int i = 0; i < 7; i++){
        colSums[i] = 0;
        for(int j = 0; j < 5; j++){
            colSums[i] = colSums[i] + array[j][i];
        }
        printf("%d\t", colSums[i]);
    }

    printf("\n\n");
}

void task5(){

    printf("Aufgabe 5: Tic Tac Toe\n\n");

    printf("Willkommen bei Tic Tac Toe\n\nSpieler 1:\tO\nSpieler 2:\tX\n\n");

    int currentPlayer = 1;
    int winner = -1;
    int field[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    int coords[2] = {0,0};
    int playerTurn[2]={0,0};

    while(winner == -1){
        printf("Spieler %d ist am Zug.", currentPlayer);

        int validX;
        do {
            validX = 1;
            printf("\n\nBitte geben Sie die X-Koordinate ihres Zuges ein.\n\n");

            scanf("%d", &coords[0]);

            if(coords[0] > 3 || coords[0] < 0){
                printf("\nIhre Eingabe ist ungueltig. Bitte versuchen Sie es erneut. Der Wert muss 1, 2 oder 3 sein.\n");
                validX = 0;
            }

            int hasFreeXSpot = 0;

            for(int i = 0; i < 3; i++){
                if(field[coords[0]-1][i] == 0){
                    hasFreeXSpot = 1;
                    i = 3;
                }
            }

            if(hasFreeXSpot != 1){
                printf("\nIn dieser Spalte gibt es keinen freien Platz mehr. Wählen Sie einen anderen Wert.\n");
                validX = 0;
            }


        } while(validX != 1);

        printf("\nDie gewaehlte X-Koordinate ist: %d\n\n", coords[0]);

        int validY;
        do {
            validY = 1;
            printf("\n\nBitte geben Sie die Y-Koordinate ihres Zuges ein.\n\n");

            scanf("%d", &coords[1]);

            if(coords[1] > 3 || coords[1] < 0){
                printf("\nIhre Eingabe ist ungueltig. Bitte versuchen Sie es erneut. Der Wert muss 1, 2 oder 3 sein.\n");
                validY = 0;
            }

            int hasFreeYSpot = 0;

            for(int i = 0; i < 3; i++){
                if(field[i][coords[1]] == 0){
                    hasFreeYSpot = 1;
                    i = 3;
                }
            }

            if(hasFreeYSpot != 1){
                validY = 0;
            }

            if(field[coords[1]-1][coords[0]-1] != 0){
                printf("\nDieses Feld ist bereits belegt. Bitte verwenden Sie einen anderen Y-Wert.");
                validY = 0;
            }

        } while(validY != 1);

        printf("\nDie gewaehlte Y-Koordinate ist: %d\n\nSpieler %d setzt eine Markierung auf %d/%d\n\nDas Spielfeld sieht nun wie folgt aus:\n\n", coords[1],currentPlayer,coords[0],coords[1]);


        field[coords[1]-1][coords[0]-1] = currentPlayer;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(field[i][j] == 1){
                    printf(" O ");
                } else if (field[i][j] == 2){
                    printf(" X ");
                } else {
                    printf("   ");
                }
                if(j < 2){
                    printf("|");
                }
            }
            if(i < 2){
                printf("\n-----------\n");
            } else {
                printf("\n");
            }

        }


        playerTurn[currentPlayer-1]++;


        printf("\n--------------------------------------------------------\n");

        if(playerTurn[0]+playerTurn[1] == 9){
            printf("\nDas Spiel ist vorbei. Ergebnis: Unentschieden.");
            winner = 0;
        }

        //Check winning conditions

        //horizontal
        for(int i = 0; i < 3; i++){
            int counter = 0;
            for(int j = 0; j < 3; j++){
                if(field[i][j] == currentPlayer){
                    counter++;
                }

            }

            if(counter == 3){
                winner = currentPlayer;
                printf("\nDas Spiel ist vorbei. Spieler %d hat durch eine horizontale Linie gewonnen!\n", winner);
            } else {
                counter = 0;
            }
        }

        //vertical
        for(int i = 0; i < 3; i++){
            int counter = 0;
            for(int j = 0; j < 3; j++){
                if(field[j][i] == currentPlayer){
                    counter++;
                }

            }

            if(counter == 3){
                winner = currentPlayer;
                printf("\nDas Spiel ist vorbei. Spieler %d hat durch eine vertikale Linie gewonnen!\n", winner);
            } else {
                counter = 0;
            }
        }

        //diagonal
        //top left - bottom right
        int diagonalCounter = 0;
        for(int i = 0; i < 3; i++){
            if(field[i][i]==currentPlayer){
                diagonalCounter++;
            }

        }


        if(diagonalCounter == 3){
            winner = currentPlayer;
            printf("\nDas Spiel ist vorbei. Spieler %d hat durch eine Diagonale Linie von oben links nach unten rechts gewonnen!\n", winner);
        }


        //top right - bottom left
        if(field[2][0] == currentPlayer && field[1][1] == currentPlayer && field[0][2] == currentPlayer){
            winner = currentPlayer;
            printf("\nDas Spiel ist vorbei. Spieler %d hat durch eine Diagonale Linie von oben rechts nach unten links gewonnen!\n", winner);
        }


        if(currentPlayer == 1){
            currentPlayer = 2;
        } else {
            currentPlayer = 1;
        }
    }
}

int main()
{
    task2();
    task3();
    task4();
    task5();

    return 0;
}
