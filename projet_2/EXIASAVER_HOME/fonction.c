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
  int tabSave[24][80];




  if (a == -1)
  {
    for (j = 0; j < 23 ; j++)
      {
        for(i = 0; i < 80 ; i ++)
          {
            tabSave[j][i] = tabAff[j][i];
          }
      }

    for (j = 0; j < 23 ; j++)
      {
        for(i = 0; i < 80 ; i ++)
          {
            tabAff[j][i] = tabSave[j-1][i];
          }
      }

    for(i = 0; i < 80 ; i ++)
      {
        tabAff[0][i] = tabSave[22][i];
      }

  }



  //en haut

   if (a == 1)
      {
        for (j = 0; j < 23 ; j++)
            {
              for(i = 0; i < 80 ; i ++)
                  {
                    tabSave[j][i] = tabAff[j][i];
                  }
            }

        for (j = 0; j < 23 ; j++)
            {
              for(i = 0; i < 80 ; i ++)
                  {
                    tabAff[j][i] = tabSave[j+1][i];
                  }

            }

        for(i = 0; i < 80 ; i ++)
            {
              tabAff[22][i] = tabSave[0][i];
            }

      }




  //a gauche

   if (b == 1)
      {
        for (i = 0; i < 80 ; i++)
            {
              for(j = 0; j < 23 ; j ++)
                  {
                    tabSave[j][i] = tabAff[j][i];
                  }
            }

        for (i = 0; i < 80 ; i++)
            {
              for(j = 0; j < 23 ; j ++)
                  {
                    tabAff[j][i] = tabSave[j][i-1];
                  }
            }

        for(j = 0; j < 23 ; j ++)
            {
              tabAff[j][0] = tabSave[j][79];
            }

      }




  //a droite

   if (b == -1)
    {
      for (i = 0; i < 80 ; i++)
          {
            for(j = 0; j < 23 ; j ++)
                {
                  tabSave[j][i] = tabAff[j][i];
                }
          }

      for (i = 0; i < 80 ; i++)
          {
            for(j = 0; j < 23 ; j ++)
                {
                  tabAff[j][i] = tabSave[j][i+1];
                }
          }

      for(j = 0; j < 23 ; j ++)
          {
            tabAff[j][79] = tabSave[i][0];
          }
    }

}

void DecPoint(int ligne , int col, int a , int b, int tabAff[23][80])
{
//39
//7
int i = 0;
int j = 0;
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
    j++;
    decaler(0,-1,tabAff);
  }
}

else if (col >> 0)
{
  while(j != 0)
  {
    j--;
    decaler(0,1,tabAff);
  }
}


return ;
}
