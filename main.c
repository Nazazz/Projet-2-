#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    srand(time(NULL)); //srand permet de donner des valeurs al�atoires
    int nombre = rand()%3+1;   //le modulo % nous permet de r�duire l'interval des nombres, ici le nombre al�atoires sera copris entre 1 et 3
    printf("%d\n", nombre);  //affiche le nombre dans le terminal
    return 0;

}
