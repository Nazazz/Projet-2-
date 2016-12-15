
#include <stdio.h>              //librairie de base
#include <stdlib.h>             //librairie de base
#include <string.h>             //librairie de caractere
#include <time.h>               //librairie de temps / date
#include <unistd.h>             //librairie linux
#include "fonction.h"           //notre librairie de fonction
#include "fonction_ins.h"       //notre librairie d insertion des valeurs

int main(int argc, char *argv[])

{

    FILE* image = NULL;


    int i = 0;                      // initialise toute les variables à 0
    int j = 0;
    int k = 0;
    int l = 0;
    int calcx = 0;
    int calcy = 0;
    int tabx = 0;
    int taby = 0;

    char caractereActuel;           // stocke le caractère lu dans le fichier


    int tabAff[24][80]= {0};         // taille fixe du tableau



    system("clear");                //vide le terminal


    if (strcmp(argv[1], "EXIASAVER1_PBM/moustache.pbm") == 0)
      {
        image = fopen( argv[1] , "r"); // ouvre le fichier contenant l'image
      }

    if (strcmp(argv[1], "EXIASAVER1_PBM/mario.pbm") == 0)
      {
        image = fopen(argv[1], "r"); // ouvre le fichier contenant l'image
      }

    if (strcmp(argv[1], "EXIASAVER1_PBM/chat.pbm") == 0)
      {
        image = fopen(argv[1], "r"); // ouvre le fichier contenant l'image
      }

    if (strcmp(argv[1], "EXIASAVER1_PBM/pause.pbm") == 0)
      {
        image = fopen(argv[1], "r"); // ouvre le fichier contenant l'image
      }

    if (strcmp(argv[1], "EXIASAVER1_PBM/yoga.pbm") == 0)
      {
        image = fopen(argv[1], "r"); // ouvre le fichier contenant l'image
      }


    tabx = tailleImageX(image);       //Permet de prendre la taille x de l'image
    taby = tailleImageY(image);       //Permet de prendre la taille y de l'image

    int InfoImage[24][80] ; // taille fixe du tableau

    inserTabPbm(image,taby,tabx,InfoImage); //inserre less valeurs dans le tableau image

    fclose(image); // on ferme le fichier image

    i = 0;
    j = 0;

    calcx = calcCentrex(tabx); // callcul du centrage pour x
    calcy = calcCentrey(taby); // callcul du centrage pour y

    k = calcy;
    l = calcx;

    for (i = 0  ; i < taby  ; i++ )            // on insert les valeurs dans le tableau d affichage
        {
          for(j = 0 ; j < tabx ; j++)
              {
                tabAff[k][l] = InfoImage[i][j];
                l++;
              }

          l = calcx;
          k++;
       }

    i = 0;
    j = 0;




    for (i = 0; i < 24; i++)     // on affiche dans le terminal les valeurs du tableau d affichage avec le langage ascii
      {
          printf ("\n");

          for(j = 0; j < 80; j++)
              {

                if (tabAff[i][j] == 0)
                  {
                    printf("%c",255);
                  }

                  else if(tabAff[i][j] == 1)
                  {
                    printf("%c",178);
                  }

              }



      }

    system("stty cbreak -echo");      // on attends que l utlisateur n appuie sur n importe quel touche sans rien afficher sur le termimal
    getchar();
    system("stty cooked echo");
    system("clear");

    return 1;

}
