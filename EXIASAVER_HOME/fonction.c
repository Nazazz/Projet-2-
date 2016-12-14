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
int chargementPbm(FILE* image)
{
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

  int InfoImage[taby][tabx];


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


}
*/
