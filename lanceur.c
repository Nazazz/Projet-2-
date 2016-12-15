#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>


int randomVeille();
int afficheMenu();





int main(int argc, char *argv[])

{
  char stat[] = "-stat"; // declare la chaine de caractere -stat pour comparer a l argument entrer
  int randomChiffre;
  int type;
  int type2;
  char date[]= "JJ/MM/AAAA" ;
  char heure[]= "HH:MM:SS" ;
  int i = 0;
  char caractereActuel = 'a';
  int pid;
  int randomImage ;
  int randomSens ;
  int randomType;

  FILE* fichier = NULL; //le pointeur est initié a NULL car nous n'avons pas de valeur à lui donner.



  srand(time(NULL)); //srand permet de donner des valeurs aléatoire
  randomImage = rand()%5+1;

  srand(time(NULL)); //srand permet de donner des valeurs aléatoire
  randomSens = rand()%4+1;


  time_t now = time(NULL); //permet de lire l'heure courante
  struct tm tm_now = *localtime(&now);//permet de convertir l'heure en heure locale grâce a localtime
  char s_now[sizeof "JJ/MM/AAAA HH:MM:SS"];// crée une chaine pour savoir comment cela va s'afficher sur le terminal
  strftime (s_now, sizeof s_now, "%d/%m/%Y %H:%M:%S", &tm_now);

  randomChiffre = randomVeille() ;


if (randomChiffre == 2)
{
  while (randomChiffre == 2)
  {
  randomChiffre = randomVeille();
  }

}



  //randomChiffre = 3; // pour les test


  if (randomChiffre == 1)
    {
      randomType = randomImage;
    }

  if (randomChiffre == 3)
    {
      randomType = randomSens;
    }








  if (argc == 1) //si il n y a pas d'arguments
    {
       system("clear"); //vide le terminal
       fichier = fopen("historique.txt", "a+"); //nous demandons au fichier text.txt de s'ouvrir.

       if (fichier != NULL)
          {
            fprintf(fichier,"%s %d %d\n", s_now, randomChiffre, randomType);//ecrit le resultat dans le dossier text.txt
          }

       fclose(fichier);//permet de fermer le dossier grâce à la fonction fclose


       if (randomChiffre == 1)
          {
            pid = fork();

            switch(pid)

              {
                case -1:
                          printf("erreur");
                          break;

                case 0:
                          if (randomImage == 1)
                            {
                              execl("/home/afix/Documents/projet_2/EXIASAVER_HOME/statique","statique","EXIASAVER1_PBM/moustache.pbm",NULL);
                            }

                          if (randomImage == 2)
                            {
                              execl("/home/afix/Documents/projet_2/EXIASAVER_HOME/statique","statique","EXIASAVER1_PBM/mario.pbm",NULL);
                            }

                          if (randomImage == 3)
                            {
                              execl("/home/afix/Documents/projet_2/EXIASAVER_HOME/statique","statique","EXIASAVER1_PBM/chat.pbm",NULL);
                            }

                          if (randomImage == 4)
                            {
                              execl("/home/afix/Documents/projet_2/EXIASAVER_HOME/statique","statique","EXIASAVER1_PBM/pause.pbm",NULL);
                            }

                          if (randomImage == 5)
                            {
                              execl("/home/afix/Documents/projet_2/EXIASAVER_HOME/statique","statique","EXIASAVER1_PBM/yoga.pbm",NULL);
                            }

                          break;

              default:
                          wait(NULL);
                          break;
          }

       }


      if (randomChiffre == 3)
          {
            pid = fork();

            switch(pid)
                  {
                      case -1:
                                printf("erreur");
                                break;

                      case 0:
                                if (randomSens == 1)
                                    {
                                      execl("/home/afix/Documents/projet_2/EXIASAVER_HOME/interactif_touche","interactif_touche","1",NULL);
                                    }

                                if (randomSens == 2)
                                    {
                                      execl("/home/afix/Documents/projet_2/EXIASAVER_HOME/interactif_touche","interactif_touche","2",NULL);
                                     }

                                if (randomSens == 3)
                                    {
                                      execl("/home/afix/Documents/projet_2/EXIASAVER_HOME/interactif_touche","interactif_touche","3",NULL);
                                    }

                                if (randomSens == 4)
                                    {
                                      execl("/home/afix/Documents/projet_2/EXIASAVER_HOME/interactif_touche","interactif_touche","4",NULL);
                                    }


                                break;

            default:
                        wait(NULL);
                        break;
                      }

            }







       }





       else if (strcmp(argv[1], stat) != 0) // si l argument n est pas -stat
            {
              printf("mauvais argument \n");
            }


       else if (strcmp(argv[1], stat) == 0) // si l argument est stat
            {
              fichier = fopen("historique.txt", "r+");

              while (caractereActuel != EOF )
                  {
                    if (caractereActuel == '\n')
                        {
                            i++;
                        }

                    caractereActuel = fgetc(fichier);
                  }


              fclose(fichier);//permet de fermer le dossier grâce à la fonction fclose

              system("clear");

              switch(afficheMenu())
                    {
                      case 1:  //fichier = fopen("historique.txt", "r");

                                system("clear");
                                printf(">>>>>Voici les statistiques pour l'ecran statique<<<<<\n\n\n\n");
                                printf("date       heure      fichier ouvert\n\n\n");

                                fichier = fopen("historique.txt", "r+");

                                if (fichier != NULL)
                                    {
                                      while(i > 0)
                                          {
                                              fscanf(fichier, "%s %s %d %d", &date , &heure, &type, &type2);
                                              if (type == 1)
                                                  {
                                                    printf("%s %s   %d\n", date, heure, type2);
                                                  }

                                              i--;
                                          }


                        fclose(fichier);//permet de fermer le dossier grâce à la fonction fclose

                     }

                     break;

               case 2:
                      system("clear");
                     printf("Voici les statistiques pour l'ecran dynamique\n\n\n\n");
                     printf("date       heure      taille de l horloge\n\n\n");

                     fichier = fopen("historique.txt", "r+");

                     if (fichier != NULL)

                     {

                      while(i > 0)
                      {
                       fscanf(fichier, "%s %s %d %d", &date , &heure, &type, &type2);

                       if (type == 2)
                       {
                        printf("%s %s   %d\n", date, heure, type2);

                       }

                       i--;
                     }


                        fclose(fichier);//permet de fermer le dossier grâce à la fonction fclose

                     }

                     break;
               case 3:
                      system("clear");
                     printf("Voici les statistiques pour l'ecran interactif\n\n\n\n");
                     printf("date       heure      direction de l avion\n\n\n");

                     fichier = fopen("historique.txt", "r+");

                     if (fichier != NULL)

                     {

                      while(i > 0)
                      {
                       fscanf(fichier, "%s %s %d %d", &date , &heure, &type, &type2);

                       if (type == 3)
                       {
                        printf("%s %s   %d\n", date, heure, type2);

                       }

                       i--;
                     }


                        fclose(fichier);//permet de fermer le dossier grâce à la fonction fclose

                     }
           break;

                case 4:
                      printf("Voici les statistiques general\n\n\n");
                      printf("exiasveur a ete utiliser %d fois\n",i );


                      break;

           printf(":stat \n");
           printf("             date       type      description      \n");


       }
  }

    return EXIT_SUCCESS;


}


int randomVeille()
{
    srand(time(NULL)); //srand permet de donner des valeurs aléatoires
    int nombre ;
    nombre = rand()%3+1;   //le modulo % nous permet de réduire l'interval des nombres, ici le nombre aléatoires sera copris entre 1 et 3

    return nombre;

}

int afficheMenu()
{
  int ChoixMenu;

  printf("------MENU------\n\n");
  printf("1.STATIQUE\n");
  printf("2.DYNAMIQUE\n");
  printf("3.INTERACTIF\n");
  printf("4.General\n\n");
  printf("Faites votre choix\n");

  scanf("%d" , &ChoixMenu);
  return ChoixMenu;
}
