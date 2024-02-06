#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h> // delay()

void M_incidenta(int * matInc, int * matAdi, int ** listAdi, int m, int n);
void M_adiacenta(int * matInc, int * matAdi, int ** listAdi, int m, int n);
void L_adiacenta(int * matInc, int * matAdi, int ** listAdi, int m, int n);

void incidenta_adiacenta(int * matInc, int * matAdi, int m, int n);
void incidenta_lista(int * matInc, int ** listAdi, int m, int n);

void adiacenta_incidenta(int * matInc, int * matAdi, int m, int n);
void adiacenta_lista(int * matAdi, int ** listAdi, int m, int n);

void lista_incidenta(int * matInc, int ** listAdi, int m, int n);
void lista_adiacenta(int * matAdi, int ** listAdi, int m, int n);
int main(){
    int m, n;
    printf("Varfuri: ");
    scanf("%d", &n);
    printf("Arce: ");
    scanf("%d", &m);


    int *matIncidenta = (int *)malloc(sizeof(int) * m * n);
    int *matAdiacenta = (int *)malloc(sizeof(int) * n * n);
    int *listVarf = (int *)calloc(n+3, sizeof(int));
    int **listAdiacenta = (int **)malloc(sizeof(listVarf) * n);
    for (int i = 0; i < n; i++) {
        listAdiacenta[i] = (int *)calloc(n+3, sizeof(int));
    }

    int digit;
    printf("Introdu una din optiuni:\n");
    printf("1. Matrice de adiacenta.\n");
    printf("2. Matrice de incidenta.\n");
    printf("3. Lista de adiacenta.\n");
    printf("Enter: ");
    scanf("%d", &digit);

    switch(digit){
    case 1: //matricea de incidenta
        M_incidenta(matIncidenta, matAdiacenta, listAdiacenta, m, n);
        break;
    case 2: //matricea de adiacenta
        M_adiacenta(matIncidenta, matAdiacenta, listAdiacenta, m, n);
        break;
    case 3: //lista de adiacenta
        L_adiacenta(matIncidenta, matAdiacenta, listAdiacenta, m, n);
        break;
    }


    free(matAdiacenta);
    free(matIncidenta);
    free(listAdiacenta);
    free(listVarf);
    getch();
    return 0;
}

// setarea matricii de incidenta
void M_incidenta(int * matInc, int * matAdi, int ** listAdi, int m, int n){
    printf("Introdu -1 - varful adiacent, 1 - varful incident, 0 - lipsa, 2 - bucla\n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", (matInc + i * n + j));
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            *(matAdi + i * n + j) = 0;
        }
    }

    // convertirea matricei de incidenta in cea adiacenta si afisarea acesteia
    printf("\n");
    printf("Matricia de adiacenta:\n");
    incidenta_adiacenta(matInc, matAdi, m, n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", *(matAdi + i * n + j ));
        }
        printf("\n");
    }


    // convertirea matricei de incidenta in lista de adiacenta
    printf("\n");
    printf("Lista de adiacenta:\n");
    incidenta_lista(matInc, listAdi, m, n);
    for(int i = 0; i < n; i++){
        printf("%d | ", i+1);
        int j = 0;
        while(*(*(listAdi + i) + j) != 0){
            printf("%d ", *(*(listAdi + i) + j));
            j++;
        }
        printf("\n");
    }
}

// setarea matricii de adiacenta
void M_adiacenta(int * matInc, int * matAdi, int ** listAdi, int m, int n){
    printf("Introdu 1 in locurile unde este nevoie:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", (matAdi + i * n + j));
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            *(matInc + i * n + j) = 0;
        }
    }

    printf("\n");
    printf("Matricia de incidenta:\n");
    adiacenta_incidenta(matInc, matAdi, m, n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", *(matInc + i * n + j ));
        }
        printf("\n");
    }

    // convertirea matricei de adiacente in lista de adiacenta
    printf("\n");
    printf("Lista de adiacenta:\n");
    adiacenta_lista(matAdi, listAdi, m, n);
    for(int i = 0; i < n; i++){
        printf("%d | ", i+1);
        int j = 0;
        while(*(*(listAdi + i) + j) != 0){
            printf("%d ", *(*(listAdi + i) + j));
            j++;
        }
        printf("\n");
    }
}

//setarea listei de adiacenta
void L_adiacenta(int * matInc, int * matAdi, int ** listAdi, int m, int n){

    for(int i = 1; i <= n; i++){
        printf("%d | ", i);
        int j = 0;
        do{
            scanf("%d", *(listAdi + (i-1)) + j);
            j++;
        } while(*(*(listAdi + (i-1)) + (j-1)) != 0);
    }

    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d | ", i+1);
        int j = 0;
        while(*(*(listAdi + i) + j) != 0){
            printf("%d ", *(*(listAdi + i) + j));
            j++;
        }

        printf("0");
        printf("\n");
    }

    printf("\n");
    printf("Matricea de incidenta:\n");
    lista_incidenta(matInc, listAdi, m, n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", *(matInc + i * m + j));
        }
        printf("\n");
    }

    printf("\n");
    printf("Matricea de adiacenta:\n");
    lista_adiacenta(matAdi, listAdi, m, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", *(matAdi + i * n + j));
        }
        printf("\n");
    }
}

//convertirea matricii din incidenta in adiacenta
void incidenta_adiacenta(int * matInc, int * matAdi, int m, int n){
    int tempi;
    int tempj;
    int tempn = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(*(matInc + i * n + j) == 2){
                tempi = j;
                tempj = j;
            }
            if(*(matInc + i * n + j) == -1){
                tempi = j;
            }
            if(*(matInc + i * n + j) == 1){
                tempj = j;
            }
        }
        *(matAdi + tempi*n + tempj) = 1;
        tempn++;
    }
}

// convertirea matricii din adiacenta in incidenta
void adiacenta_incidenta(int * matInc, int * matAdi, int m, int n){
    int rand = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(*(matAdi + i * n + j) == 1 && i == j){
                *(matInc + rand * n + j) = 2;
                rand++;
                continue;
            }
            if(*(matAdi + i * n + j) == 1){
                *(matInc + rand * n + i) = -1;
                *(matInc + rand * n + j) = 1;
                rand++;
            }
        }
    }
}

void incidenta_lista(int * matInc, int ** listAdi, int m, int n){
    int tempi, tempj;

    for(int i = 0; i < m; i++){
        int b = 0;
        int next = 0;
        for(int j = 0; j < n; j++){
            if(*(matInc + i * n + j) == 2){
                b = 0;
                while(*(*(listAdi + j) + b) != 0){
                    b++;
                }
                *(*(listAdi + j) + b) = j+1;
                next = 1;
                continue;
            }

            if(*(matInc + i * n + j) == 1){
                tempj = j+1;
            }
            if(*(matInc + i * n + j) == -1){
                tempi = j;
            }
        }
        if(next == 1) continue;
        while(*(*(listAdi + tempi) + b) != 0){
                b++;
            }
        *(*(listAdi + tempi) + b) = tempj;
    }
}

void adiacenta_lista(int * matAdi, int ** listAdi, int m, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(*(matAdi + i * n + j) == 1){
                int b = 0;
                while(*(*(listAdi + i) + b) != 0){
                    b++;
                }
                *(*(listAdi + i) + b) = j + 1;
            }
        }
    }
}

void lista_incidenta(int * matInc, int ** listAdi, int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            *(matInc + i * m + j) = 0;
        }
    }

    int rand = 0;
    for(int i = 0; i < n; i++){
        int j = 0;
        while(*(*(listAdi + i) + j) != 0){
            int temp = *(*(listAdi + i) + j);
            if(temp == (i+1)){
                *(matInc + rand * m + i) = 2;
                j++;
                rand++;
                continue;
            }

            *(matInc + rand * m + i) = -1;
            *(matInc + rand * m + (temp-1)) = 1;
            j++;
            rand++;
        }
    }
}

void lista_adiacenta(int * matAdi, int ** listAdi, int m, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            *(matAdi + i * n + j) = 0;
        }
    }

    for(int i = 0; i < n; i++){
        int j = 0;
        while(*(*(listAdi + i) + j) != 0){
            int temp = *(*(listAdi + i) + j);
            *(matAdi + i * n + (temp-1)) = 1;
            j++;
        }
    }
}

