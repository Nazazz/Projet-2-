#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


void inserTabPbm (FILE* image, int taby, int tabx ,int InfoImage[24][80])

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
