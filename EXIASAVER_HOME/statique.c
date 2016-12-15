
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "fonction.h"



int calcCentrex(int tabx);
int calcCentrey(int taby);


int main(int argc, char *argv[])

{

    FILE* image = NULL;

    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    char caractereActuel;
    int tabx;
    int taby;
    int* tabAdd[5];
    int tabAff[24][80]= {0};
    int calcx = 0;
    int calcy = 0;


    system("clear");




    if (strcmp(argv[1], "pbm/moustache.pbm") == 0)
    {
      image = fopen( argv[1] , "r");
    }

    if (strcmp(argv[1], "pbm/mario.pbm") == 0)
    {
      image = fopen(argv[1], "r");
    }

    if (strcmp(argv[1], "pbm/chat.pbm") == 0)
    {
      image = fopen(argv[1], "r");
    }

    if (strcmp(argv[1], "pbm/pause.pbm") == 0)
    {
      image = fopen(argv[1], "r");
    }

    if (strcmp(argv[1], "pbm/yoga.pbm") == 0)
    {
      image = fopen(argv[1], "r");
    }






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

    int InfoImage[taby][tabx] ;


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


  //int **InfoImage;

  //InfoImage = inserTabPbm (image, tabx, taby);

      fclose(image);

      i = 0;
      j = 0;

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

      system("stty cbreak -echo");
      getchar();
      system("stty cooked echo");
      system("clear");

    return 1;



}
