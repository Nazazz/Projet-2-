#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILE_MAXIMUM 1000 // peut être modifié


int main(int argc, char *argv[])
{

//-------------------------------------------------------------------------------- pour ouvrir le fichier---------------------------------------------------------------------------//

        FILE* fichier = NULL; //le pointeur est initié a NULL car nous n'avons pas de valeur à lui donner.
        char chaine[TAILLE_MAXIMUM] = ""; // Chaîne vide de taille TAILLE_MAXiMUM
        fichier = fopen("text.txt", "a+"); //nous demandons au fichier text.txt de s'ouvrir.
        if (fichier != NULL)
        {
        }
        else
        {
                printf("Le fichier n'a pas pu s'ouvrir\n"); // si le fichier ne s'ouvre pas ce sera écrit ce message.
        }

//----------------------------------------------------------------------------------ecrire dans le fichier-----------------------------------------------------------------------------//

        if (fichier != NULL)
        {
                time_t now = time(NULL); //permet de lire l'heure courante
                struct tm tm_now = *localtime(&now);//permet de convertir l'heure en heure locale grâce a localtime
                char s_now[sizeof "JJ/MM/AAAA HH:MM:SS"];// crée une chaine pour savoir comment cela va s'afficher sur le terminal
                strftime (s_now, sizeof s_now, "%d/%m/%Y %H:%M:%S", &tm_now);
                fprintf(fichier,"%s %d", s_now, randomVeille);//afficher le resultat dans le dossier text.txt

        }


//----------------------------------------------------------------------------------------pour fermer un fichier----------------------------------------------------------------------//

        if (fichier != NULL)
        {
                fclose(fichier);//permet de fermer le dossier grâce à la fonction fclose
        }
        else
        {
                printf("le fichier n'a pas pu se fermer"); //si le fichier ne se ferme pas, cela affiche ce message.
        }

//--------------------------------------------------------------------------------------------ouvrir le fichier-----------------------------------------------------------------------//

     if (fichier != NULL)
        {
                fichier = fopen("text.txt", "r+"); //nous demandons au fichier text.txt de s'ouvrir.
        }
        else
        {
                printf("Le fichier n'a pas pu s'ouvrir\n"); // si le fichier ne s'ouvre pas cela affiche ce message.
        }

//-----------------------------------------------------------------------------------------------lire le fichier---------------------------------------------------------------------//
                if (fichier != NULL)
                {
                        fgets(chaine, TAILLE_MAXIMUM, fichier);  //permet de lire au maximum la taille max prédéfini
                        printf("%s", chaine) // permet d'affichier la chaîne

                fclose(fichier);
                }


return 0;
}

