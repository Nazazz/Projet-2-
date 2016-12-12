#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLE_MAXIMUM 1000 //tableau avec une taille de 1000 (modifiable)

int main(int argc, char *argv[])
{

//-------------------------------------------------------------------------------- pour ouvrir le fichier---------------------------------------------------------------------------//

        FILE* fichier = NULL; //le pointeur est initié a NULL car nous n'avons pas de valeur à lui donner.
        char chaine[TAILLE_MAXIMUM] = ""; //chaine vide de TAILLE_MAX (1000)
        fichier = fopen("text.txt", "r+"); //nous demandons au fichier text.txt de s'ouvrir.
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
                fprintf(fichier,"%s ecran tiré au sort", s_now);//afficher le resultat dans le dossier text.txt

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

//      if (fichier != NULL)
//      {
//                      fgets(chaine, TAILLE_MAXIMUM, fichier);
//              printf("%s", chaine);
//              printf("\n\n");
                fclose(fichier);
//     }


return 0;
}

