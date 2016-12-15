#include <time.h>
#include <stdio.h>
#include <stdlib.h>



int tailleImageX(FILE* image)
{
  int i = 0;
  char caractereActuel;
  int tabx;
  int taby;

  fseek(image, 0, SEEK_SET);

  if (image != NULL)
  {
    while (i <=2)
    {
      while (caractereActuel != '\n')
      {
        caractereActuel = fgetc(image);
      }

      i++;

      if (i == 1)
      {
        fscanf(image, "%d %d ", &taby, &tabx);
        i++;
      }
    }
  }


return tabx;

}




int tailleImageY(FILE* image)
{
  int i = 0;
  char caractereActuel;
  int tabx;
  int taby;

  fseek(image, 0, SEEK_SET);

  if (image != NULL)
  {
    while (i <=2)
    {
      while (caractereActuel != '\n')
      {
        caractereActuel = fgetc(image);
      }

      i++;

      if (i == 1)
      {
        fscanf(image, "%d %d ", &taby, &tabx);
        i++;
      }
    }
  }


return taby;

}


/*

int** inserTabPbm (FILE* image,int tabx, int taby)

{

  int i = 0;
  int j = 0;

  char caractereActuel;


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

  int y;
  int x;
  y =taby;
  x = tabx;

  static int InfoImage[y][x];



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



    return InfoImage;
}
*/

int calcCentrex(int tabx)

{
  int calcx ;
  calcx = 80 - tabx ;
  calcx = calcx / 2 ;


  return calcx;
}


int calcCentrey(int taby)

{
  int calcy ;
  calcy = 24 - taby ;
  calcy = calcy / 2 ;

  return calcy;
}


void decaler(int a, int b , int tabAff[23][80])
{

  int i =0;
  int j =0;

  if (a == 1)
  {

    for(j = 0; j < 79; j++)
    {
      tabAff[22][j] = tabAff[0][j];
    }

    j= 0;

    for (i=1;i <22 ; i++)
    {
      for(j = 0; j < 79; j++)
      {
        tabAff[i-1][j] = tabAff[i][j];
      }
    }
  }

  if (a == -1);
  {
    for(j = 0; j < 79; j++)
    {
      tabAff[0][j] = tabAff[22][j];
    }

    j= 0;

    for (i=0;i <21 ; i++)
    {
      for(j = 0; j < 79; j++)
      {
        tabAff[i+1][j] = tabAff[i][j];
      }
    }

  }
  if (b == 1);
  {
    for (i = 0; i < 22; i++)
    {
      tabAff[i][22] = tabAff[i][0];
    }

    i= 0;


    for(j = 1; j < 79; j++)
    {
      for (i=0;i <22 ; i++)
      {
        tabAff[i][j-1] = tabAff[i][j];
      }
    }
  }
  if (b == -1);
  {
    for (i = 0; i < 22; i++)
    {
      tabAff[i][0] = tabAff[i][22];
    }

    i= 0;


    for(j = 0; j < 78; j++)
    {
      for (i=0;i <22 ; i++)
      {
        tabAff[i][j+1] = tabAff[i][j];
      }
    }

  }

}
