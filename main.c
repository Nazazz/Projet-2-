#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    srand(time(NULL)); //srand permet de donner des valeurs aléatoires
    int nombre = rand()%3+1;   //le modulo % nous permet de réduire l'interval des nombres, ici le nombre aléatoires sera copris entre 1 et 3
    printf("%d\n", nombre);  //affiche le nombre dans le terminal
    return 0;

}
