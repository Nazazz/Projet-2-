#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "fonction.h"


int main(int argc, char *argv[])

{
  FILE* image = NULL;

  int i = 0;
  int j = 0;
  int k = 0;
  int l = 0;
  int oc = 0;
  int a = 0;
  int b = 0;
  char caractereActuel;
  int tabx = 5;
  int taby = 5;

  int tabAff[23][80]= {0};
  int calcx = 0;
  int calcy = 0;
  int randomSens;
  char lettre = 'z';
  int save = 0;
  int savex = 0;
  int savey = 0;
  char* orien[4];
  int InfoImage[6][6];


  orien[0] = "EXIASAVER3_PBM/AvionHaut.pbm";
  orien[1] = "EXIASAVER3_PBM/AvionDroite.pbm";
  orien[2] = "EXIASAVER3_PBM/AvionBas.pbm";
  orien[3] = "EXIASAVER3_PBM/AvionGauche.pbm";



    system("clear");


    if (strcmp(argv[1], "1") == 0)
    {
      oc = 0;
      lettre = 'z';
    }

    if (strcmp(argv[1], "2") == 0)
    {
      oc = 1;
      lettre = 'd';
    }

    if (strcmp(argv[1], "3") == 0)
    {
      oc = 2;
      lettre = 's';
    }

    if (strcmp(argv[1], "4") == 0)
    {
      oc = 3;
      lettre = 'q';
    }



//EXIASAVER3_PBM/AvionHaut.pbm
//image = fopen( argv[1] , "r");

calcx = calcCentrex(6);
calcy = calcCentrey(6);





while (lettre != 'x')
{


if (lettre == 'z')
{
  oc = 0;
  a = 1;
  savey = savey + 1;

}

else if (lettre == 'd')
{
  oc = 1;
  b = 1;
  savex = savex + 1;


}

else if (lettre == 's')
{
  oc = 2;
  a = -1;
  savey = savey - 1;

}

else if (lettre == 'q')
{
  oc = 3;
  b = -1;
  savex = savex - 1;

}

else
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

save = oc;




    image = fopen(orien[oc] , "r");

    tabx = tailleImageX(image);
    taby = tailleImageY(image);



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

fclose(image);

i = 0;
j = 0;



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


printf("savey : %d\n",savey );
printf("savex : %d\n", savex);
printf("a : %d\n", a);
printf("b : %d\n", b);



int ligne ;
int col;

ligne = savey;
col = savex;

i = ligne ;
j = col;


if (ligne << 0)
{
  while(i != 0)
  {
    i++;
    decaler(-1,0,tabAff);

  }

}

else if (ligne >> 0)
{
  while(i != 0)
  {
    i--;
    decaler(1,0,tabAff);
  }
}

else if (col << 0)
{
  while(j != 0)
  {
    i++;
    decaler(0,-1,tabAff);
  }
}

else if (col >> 0)
{
  while(j != 0)
  {
    i--;
    decaler(0,1,tabAff);
  }
}



//DecPoint(savey , savex, a , b, tabAff);


i = 0 ;
j = 0 ;



      for (i = 0; i < 24; i++)
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
