#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "fonction.h"
#include "fonction_ins.h"


int main(int argc, char *argv[])

{
  FILE* image = NULL; //initialise l'image comme pointeur de FILE

  int i = 0; //déclaration des variables
  int j = 0;
  int k = 0;
  int l = 0;
  int oc = 0; //numéro de case du tableau contenant le nom des fichiers
  int a = 0;
  int b = 0;
  char caractereActuel; //permet
  int tabx = 5; // déclaration tableau ligne
  int taby = 5; // déclaration tableau colonne

  int tabAff[23][80]= {0}; //déclaration tableau de la console
  int calcx = 0; //déclaration variable pour le centrage ligne
  int calcy = 0; //déclaration variable pour le centrage colonne
  int randomSens; //déclaration random du sens de l'avion lors du démarrage


  int lettre ; // déclaration de la lettre taper en ASCII

  int save = 0; //déclaration qui permet de sauvegarder oc
  int savex = 0; //permet de sauvegarder l'incrémentation du décalage + ou - sur les lignes
  int savey = 0; // permet de sauvegarder l'incrémentation + ou - sur les colonnes
  char* orien[4]; // tableau contenant le nom des fichiers
  int InfoImage[6][6];//tableau contenant les images de l'avion
  int ligne ; // conserve savex
  int col; //conserve savey


  orien[0] = "EXIASAVER3_PBM/AvionHaut.pbm"; //tableau contenant le nom des fichiers
  orien[1] = "EXIASAVER3_PBM/AvionDroite.pbm";
  orien[2] = "EXIASAVER3_PBM/AvionBas.pbm";
  orien[3] = "EXIASAVER3_PBM/AvionGauche.pbm";



    system("clear"); //vidage de la console


    if (strcmp(argv[1], "1") == 0) //permet de transformer l'argument en un nombre en language ASCII (lettre)
    {

      lettre = 122;
      //oc = 0;
    }

    if (strcmp(argv[1], "2") == 0)
    {

      lettre = 100;
      //oc = 1;
    }

    if (strcmp(argv[1], "3") == 0)
    {

      lettre = 115;
      //oc = 2;
    }

    if (strcmp(argv[1], "4") == 0)
    {

      lettre = 113;
      //oc = 3;
    }





calcx = calcCentrex(6); //donne la position ligne pour le centrage
calcy = calcCentrey(6); //donne la position colonne pour le centrage





while (lettre != 120) //grande boucle qui permet de sortir du programme si on la lettre rentrer est x
{


if (lettre == 122) //si la lettre entrer change le fichier a charger et afficher et incrémente ou décremente une direction X ou Y
{
  oc = 0;
  a = 1;
  savey = savey + 1;

}

else if (lettre == 100)
{
  oc = 1;
  b = 1;
  savex = savex + 1;


}

else if (lettre == 115)
{
  oc = 2;
  a = -1;
  savey = savey - 1;

}

else if (lettre == 113)
{
  oc = 3;
  b = -1;
  savex = savex - 1;

}

else  //si on ne n'appuis pas sur ZQSD ou X, on répete l'opération précédente (en appuyant sur juste entrer)
{
  oc = save;

  if (oc == 0)
  {
    savey = savey + 1;
  }
  if (oc == 1)
  {
    savex = savex + 1;
  }
  if (oc == 2)
  {
    savey = savey - 1 ;
  }
  if(oc == 3)
  {
    savex = savex - 1 ;
  }
}


save = oc; //sauvegarde la case du tableau




    image = fopen(orien[oc] , "r"); //ouvre l'image

    tabx = tailleImageX(image); //calcul le nombre de ligne de l'image
    taby = tailleImageY(image);// calcule le nombre de colonne de l'image




    fseek(image, 0, SEEK_SET); //place le curseur au début du fichier




i = 0;

   if (image != NULL)
    {
      while (i <=2)                             //permet d'arriver à la troisième ligne
      {
        while (caractereActuel != '\n')
        {
          caractereActuel = fgetc(image);
        }

        i++;

      }
   }

fseek(image, 1, SEEK_CUR); //déplace le curseur de 1 en avant dans le fichier



      i = 0;
      j = 0;




if (image != NULL)
{

      for (i = 0; i < taby ; i++)                       //rentre les valeurs du fichier dans un tableau
      {
          for(j = 0; j < tabx; j++)
          {
                caractereActuel = fgetc(image);


                if ( (caractereActuel == '1') || (caractereActuel == '0'))    //permet de convertir un char en int
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
if (image == NULL) //message d'erreur si fichier pas ouvert
{
  printf("erreur de fichier \n" );
}

fclose(image); //fermeture de l'image

i = 0;
j = 0;



k = calcy; //permet de sauvegarder calcy pour pouvoir l'utiliser en dessous et lui redonner sa valeur
l = calcx; //permet de sauvegarder calcx pour pouvoir l'utiliser en dessous et lui redonner sa valeur

for (i = 0  ; i < taby  ; i++ )
  {

          for(j = 0 ; j < tabx ; j++)
          {
            tabAff[k][l] = InfoImage[i][j]; //permet d'inserer le tableau de l'image dans le tableau d'affichage
            l++;
          }

          l = calcx;
          k++;
 }

      i = 0;
      j = 0;




ligne = savey;
col = savex;

i = ligne ;
j = col;


if (ligne < 0)
{
  while(i != 0) //permet de décaler les valeurs du tableau d'affichage x fois vers le bas
  {
    i++;
    decaler(-1,0,tabAff);

  }

}

if (ligne > 0)
{
  while(i != 0)//permet de décaler les valeurs du tableau d'affichage x fois vers le haut
  {
    i--;
    decaler(1,0,tabAff);
  }
}

 if (col < 0)
{
  while(j != 0)//permet de décaler les valeurs du tableau d'affichage x fois vers la gauche
  {
    j++;
    decaler(0,-1,tabAff);
  }
}

 if (col > 0)
{
  while(j != 0)//permet de décaler les valeurs du tableau d'affichage x fois vers la droite
  {
    j--;
    decaler(0,1,tabAff);
  }
}






i = 0 ;
j = 0 ;



      for (i = 0; i < 23; i++)    //permet d'afficher le tableau d'affichage dans le terminal
      {
        printf ("\n");
          for(j = 0; j < 80; j++)

          {

            if (tabAff[i][j] == 0) // prend la valeur binaire du tableau d'affichage et l'affiche en caractère ASCII dans le terminal
            {
              printf("%c",255);
            }
            else if(tabAff[i][j] == 1)
            {
              printf("%c",178);
            }

        }



      }




printf("\nutiliser zqsd pour se deplacer et x pour sortir " );
scanf("%c",&lettre ); //demande de rentrer la lettre de direction ou pour quitter


system("clear"); // vide la console

for (i = 0; i < 24; i++) //vide le tableau d'affichage de ses valeurs
{
    for(j = 0; j < 80; j++)

    {
      tabAff[i][j] = 0;
    }
}


}





return 1;
}
