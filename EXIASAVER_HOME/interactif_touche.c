#include <stdio.h>      //
#include <stdlib.h>     //
#include <string.h>     //
#include <time.h>       // on inclut les bibliothèques
#include <unistd.h>     //
#include "fonction.h"   //


int main(int argc, char *argv[])

{
  FILE* image = NULL;

  int i = 0;              //initialise tous les variables à zero
  int j = 0;              //
  int k = 0;              //
  int l = 0;              //
  int oc = 0;             //
  int a = 0;              //
  int b = 0;              //
  char caractereActuel;    // pour stocker le caractère lu dans le fichier 
  int tabx = 6;           // déclaration de la taille colonne
  int taby = 6;           // déclaration de la taille ligne

  int tabAff[23][80]= {0};  // déclaration du tableau d'affichage
  int calcx = 0;    //
  int calcy = 0;    //
  int randomSens;     // random pour la position de l'avion au début
  char lettre = 'z';      // permet de bouger vers le haut
  int save = 0;     //
  int savex = 0;    //
  int savey = 0;    //
  char* orien[4];   // déclaration des 4 positions de l'avion
  int InfoImage[6][6];    // déclaration de la taille de l'image


  orien[0] = "EXIASAVER3_PBM/AvionHaut.pbm";     // orien[0] correspond a l'image qui va vers le haut
  orien[1] = "EXIASAVER3_PBM/AvionDroite.pbm";   // orien[1] correspond a l'image qui va vers la droite
  orien[2] = "EXIASAVER3_PBM/AvionBas.pbm";      //orien[2] correspond a l'image qui va vers le bas
  orien[3] = "EXIASAVER3_PBM/AvionGauche.pbm";   //orien[3] correspond a l'image qui va vers la gauche



    system("clear"); //permet de vider la console


    if (strcmp(argv[1], "1") == 0) // en fonction de l'argument, on ouvre une certaine image
    {
      oc = 0;
      lettre = 'z';
    }

    if (strcmp(argv[1], "2") == 0) //en fonction de l'argument, on ouvre une certaine image
    {
      oc = 1;
      lettre = 'd';
    }

    if (strcmp(argv[1], "3") == 0) // en fonction de l'argument, on ouvre une certaine image
    {
      oc = 2;
      lettre = 's';
    }

    if (strcmp(argv[1], "4") == 0) //en fonction de l'argument, on ouvre une certaine image
    {
      oc = 3;
      lettre = 'q';
    }



//EXIASAVER3_PBM/AvionHaut.pbm
//image = fopen( argv[1] , "r");

calcx = calcCentrex(6); // permet de trouver la case pour centrer l'image
calcy = calcCentrey(6); // permet de trouver la case pour centrer l'image





while (lettre != 'x') //tant que la valeur scannée n'est pas x, il se passe:
{


if (lettre == 'z') // si on appuie sur la lettre z, on charge la nouvelle image et on incrémente le curseur y
{
  oc = 0;
  a = 1;
  savey = savey + 1;

}

else if (lettre == 'd') //si on appuie sur la lettre d, on charge la nouvelle image et on incrémente le curseur x
{
  oc = 1;
  b = 1;
  savex = savex + 1;


}

else if (lettre == 's') //si on appuie sur la lettre z, on charge la nouvelle image et on décremente le curseur y
{
  oc = 2;
  a = -1;
  savey = savey - 1;

}

else if (lettre == 'q') //si on appuie sur la lettre z, on charge la nouvelle image et on décremente le curseur x
{
  oc = 3;
  b = -1;
  savex = savex - 1;

}

else //si le scan f n'a rien reçu ou a reçu un mauvais caractère
{
  oc = save;

  if (oc == 0) //oc prend la valeur 0
  {
    savey = savey + 1; //on incrémente le curseur y
  }
  if (oc == 1)
  {
    savex = savex + 1;//on incrémente le curseur x
  }
  if (oc == 2)
  {
    savey = savey - 1 ;//on décrémente le curseur y
  }
  if(oc == 3)
  {
    savex = savex - 1 ;//on décrement le curseur x
  }
}

save = oc;




    image = fopen(orien[oc] , "r");  //ouvre le fichier contenant l'image demandé

    tabx = tailleImageX(image); // permet de savoir la taille de l'image
    taby = tailleImageY(image); //permet de savoir la taille de l'image



    fseek(image, 0, SEEK_SET); // place le curseur au début du fichier




i = 0;

   if (image != NULL) //permet de se placer a la troisième ligne 
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

fseek(image, 1, SEEK_CUR); //permet de décaler le curseur d'un caractère



      i = 0;
      j = 0;




if (image != NULL) 
{

      for (i = 0; i < taby ; i++) // lit l'image dans le fichier et écrit dans un tableau 
      {
          for(j = 0; j < tabx; j++)
          {
                caractereActuel = fgetc(image); // permet de lire le caractère


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

fclose(image); //ferme le fichier image

i = 0;
j = 0;



k = calcy; //k prend est désignée par calcy
l = calcx; //k prend est désignée par calcy

for (i = 0  ; i < taby  ; i++ )// permet d inserrer le tableau contenant l image dans le tableau d affichage a partir d un indice x et y 
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


printf("savey : %d\n",savey ); //permet d'afficher la phrase demandé  // test 
printf("savex : %d\n", savex); // pour les test 
printf("a : %d\n", a); // pour les test 
printf("b : %d\n", b); // pour les test 



int ligne ;
int col;

ligne = savey;
col = savex;

i = ligne ; //initialise les variables des lignes et des colonnes
j = col; //initialise les variables des lignes et des colonnes


if (ligne << 0)
{
  while(i != 0)
  {
    i++;
    decaler(-1,0,tabAff); // appel la fonction décaler et descend les valeurs du tableau

  }

}

else if (ligne >> 0)
{
  while(i != 0)
  {
    i--;
    decaler(1,0,tabAff); //// appel la fonction décaler et monte les valeurs du tableau
  }
}

else if (col << 0)
{
  while(j != 0)
  {
    i++;
    decaler(0,-1,tabAff); //// appel la fonction décaler et deplace vers la gauchez les valeurs du tableau
  }
}

else if (col >> 0)
{
  while(j != 0)
  {
    i--;
    decaler(0,1,tabAff);//// appel la fonction décaler et déplace vers la droite les valeurs du tableau
  }
}



//DecPoint(savey , savex, a , b, tabAff);


i = 0 ;
j = 0 ;



      for (i = 0; i < 24; i++)// permet d'afficher le tableau d'affichage dans le terminal avec les caractère ASCII
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
              printf("%c",254);
            }

        }



      }




printf("utiliser zqsd pour se deplacer et x pour sortir " );
scanf("%c",&lettre ); 

system("clear");


}





return 1;
}
