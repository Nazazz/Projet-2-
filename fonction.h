#include "fonction.c"

int tailleImageX(FILE* image);
int tailleImageY(FILE* image);
int** inserTabPbm (FILE* image,int tabx, int taby);
int calcCentrex(int tabx);
int calcCentrey(int taby);
void decaler(int a, int b , int tabAff[23][80]);
