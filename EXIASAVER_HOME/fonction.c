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
/*
  if (a == 1)
  {
    for (j = 0; j < 22 ; j++)
    {
      for(i = 0; i < 80 ; i ++)
      {
        tabSave[j][i] = tabAff[j][i];
      }
    }

    for (j = 0; j < 22 ; j++)
    {
      for(i = 0; i < 80 ; i ++)
      {
        tabAff[j][i] = tabSave[j+1][i];
      }
    }

    for(i = 0; i < 80 ; i ++)
    {
      tabAff[0][i] = tabSave[22][i];

    }

  }
*/





  if (a == -1)
  {
    for (j = 0; j < 22 ; j++)
    {
      for(i = 0; i < 80 ; i ++)
      {
        tabSave[j][i] = tabAff[j][i];
      }
    }

    for (j = 0; j < 22 ; j++)
    {
      for(i = 0; i < 80 ; i ++)
      {
        tabAff[j][i] = tabSave[j-1][i];
      }
    }

    for(i = 0; i < 80 ; i ++)
    {
      tabAff[0][i] = tabSave[21][i];

    }


  }



  //en haut

   if (a == 1)

    {

      for (j = 0; j < 22 ; j++)

      {

        for(i = 0; i < 80 ; i ++)
        {


          tabSave[j][i] = tabAff[j][i];

        }

      }



      for (j = 0; j < 22 ; j++)

      {

        for(i = 0; i < 80 ; i ++)

        {

          tabAff[j][i] = tabSave[j+1][i];

        }

      }



      for(i = 0; i < 80 ; i ++)

      {

        tabAff[0][i] = tabSave[21][i];



      }



}




  //a gauche

   if (a == -1)

    {

      for (i = 0; i < 79 ; i++)

      {

        for(j = 0; j < 23 ; j ++)
        {


          tabSave[i][j] = tabAff[i][j];

        }

      }



      for (i = 0; i < 79 ; i++)

      {

        for(j = 0; j < 23 ; j ++)

        {

          tabAff[i][j] = tabSave[i-1][j];

        }

      }



      for(j = 0; j < 22 ; j ++)

      {

        tabAff[0][j] = tabSave[79][j];



      }

}


  //a droite

   if (a == 1)

    {

      for (i = 0; i < 79 ; i++)

      {

        for(j = 0; j < 23 ; j ++)


          tabSave[i][j] = tabAff[i][j];

        }

      }



      for (i = 0; i < 79 ; i++)

      {

        for(j = 0; j < 23 ; j ++)

        {

          tabAff[i][j] = tabSave[i+1][j];

        }

      }



      for(j = 0; j < 22 ; j ++)

      {

        tabAff[0][j] = tabSave[79][j];



  }


/*

  if (b == -1)
  {
    tabAff[1][1] = 1;
  }

  if (a == 1);
  {
    for(j = 0; j < 80; j++)
    {
      tabSave[j][i] = tabAff[j][i];
    }

    j= 0;

    for (i=0;i <22 ; i++)
    {
      for(j = 0; j < 80; j++)
      {
        tabAff[j][i] = tabSave[j-1][i];
      }
    }

    for(i = 0; i < 80 ; i ++)
    {
      tabAff[0][i] = tabSave[22][i];
    }
  }


  if (b == 1);
  {
    for (i = 0; i < 22; i++)
    {
      tabAff[i][79] = tabAff[i][0];
    }

    i= 0;


    for(j = 0; j < 78; j++)
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
*/

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


return ;
}
