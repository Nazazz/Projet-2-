
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>       // on inclut les bibliothèques
#include <unistd.h>
#include "fonction.h"
#include "fonction_ins.h"



int calcCentrex(int tabx); // variable qui permet int calcCentrey(int taby);


int main(int argc, char *argv[])

{

    FILE* image = NULL;
    int i = 0; // initialise toute les variables à 0
    int j = 0;
    int k = 0;
    int l = 0;
    char caractereActuel; // stocke le caractère lu dans le fichier
    int tabx;
    int taby;
    int* tabAdd[5];
    int tabAff[24][80]= {0}; // taille fixe du tableau
    int calcx = 0;
    int calcy = 0;


    system("clear"); // supprime le contenu utilisé auparavant




    if (strcmp(argv[1], "pbm/moustache.pbm") == 0)
    {
      image = fopen( argv[1] , "r"); // ouvre le fichier contenant l'image 
    }

    if (strcmp(argv[1], "pbm/mario.pbm") == 0)
    {      image = fopen(argv[1], "r"); // ouvre le fichier contenant l'image
    }

    if (strcmp(argv[1], "pbm/chat.pbm") == 0)
    {
      image = fopen(argv[1], "r"); // ouvre le fichier contenant l'image
    }

    if (strcmp(argv[1], "pbm/pause.pbm") == 0)
    {
      image = fopen(argv[1], "r"); // ouvre le fichier contenant l'image
    }

    if (strcmp(argv[1], "pbm/yoga.pbm") == 0)
    {
      image = fopen(argv[1], "r"); // ouvre le fichier contenant l'image
    }



    tabx = tailleImageX(image); // Permet de prendre la taille de l'image
    taby = tailleImageY(image); // Permet de prendre la taille de l'image

    int InfoImage[24][80] ;

inserTabPbm(image,taby,tabx,InfoImage); // 

/*
    fseek(image, 0, SEEK_SET);


i = 0;

   if (image != NULL)
    {
      while (i <=2)
      {
         while (caractereActuel != '\n')
        {
          caractereActuel = fgetc(image);
        }

        i++;

      }
   }

fseek(image, 1, SEEK_CUR);


 
 
      i = 0;
      j = 0;



if (image != NULL)
{

      for (i = 0; i < taby ; i++)
      {
          for(j = 0; j < tabx; j++)
          {
                caractereActuel = fgetc(image);

                if ( (caractereActuel == '1') || (caractereActuel == '0'))
                {
                  if (caractereActuel == '0')
                  {
                    InfoImage[i][j] = 0;
                  }

                  if (caractereActuel == '1')
                  {
                    InfoImage[i][j] = 1;
                  }


                }

                else
                {
                  j--;
                }


          }

      }

  }

*/
  //int **InfoImage;

  //InfoImage = inserTabPbm (image, tabx, taby);

      fclose(image); // Permet de fermer le fichier contenant les images

      i = 0; // on attribut la valeur 0 à i
      j = 0; // on attribut la valeur 0 à j

      calcx = calcCentrex(tabx); 
      calcy = calcCentrey(taby);
      k = calcy;
      l = calcx;

      for (i = 0  ; i < taby  ; i++ )
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




            for (i = 0; i < 24; i++)
            {
              printf ("\n"); // permet de faire un retour à la ligne
                for(j = 0; j < 80; j++)
                {

                  if (tabAff[i][j] == 0)
                  {
                    printf("%c",255); // affiche un caractère blanc
                  }
                  else if(tabAff[i][j] == 1)
                  {
                    printf("%c",254); // affiche un caractère noir
                  }

              }



            }

      system("stty cbreak -echo"); // sert à detécter l'ajout d'un caractère 
      getchar(); // reconnait si l'utilisteur appuie sur un caractère
      system("stty cooked echo"); // Reconnait si c'est un caractère qui est utilisé
      system("clear"); // nettoie la console

    return 1;



}
