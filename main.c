/*
 * Projekt: Metoda nejmensich ctvercu
 * Autor: Roman Grmela
 * Datum: 4.3. 2025
 */

#include "gvid.h"       // par drobnosti pro zjednoduseni prace
#include <stdio.h>
#include <stdlib.h>
#include "pole.h"
// #include <string.h>  // pro praci s textovymi retezci
// #include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racionalni typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celociselne typy INT_MAX, INT_MIN, ...
// #include <time.h>    // funkce time a dalsi pro praci s casem

//2 rovnice a 3 sloupce
typedef struct{
  double prvek[2][3];
  int sloupcu, radku;
}TMatice;



// Funkce pro Gaussovu eliminaci - chatgpt
void gaussEliminace(TMatice *m, double *a, double *b) {
    int i, j, k;
    double pom;

    for (i = 0; i < m->radku; i++) {
        // Pivotace - zajistíme, že na hlavní diagonále je nejvìtší prvek
        int maxRow = i;
        for (k = i + 1; k < m->radku; k++) {
            if (fabs(m->prvek[k][i]) > fabs(m->prvek[maxRow][i])) {
                maxRow = k;
            }
        }
        // Prohodíme øádky
        if (maxRow != i) {
            for (j = 0; j < m->sloupcu; j++) {
                double temp = m->prvek[i][j];
                m->prvek[i][j] = m->prvek[maxRow][j];
                m->prvek[maxRow][j] = temp;
            }
        }

        // Normalizace hlavního prvku na 1
        pom = m->prvek[i][i];
        if (pom == 0) {
            printf("Soustava nemá jednoznaèné øešení!\n");
            return;
        }
        for (j = i; j < m->sloupcu; j++) {
            m->prvek[i][j] /= pom;
        }

        // Odeètení øádkù pod hlavní diagonálou
        for (k = i + 1; k < m->radku; k++) {
            pom = m->prvek[k][i];
            for (j = i; j < m->sloupcu; j++) {
                m->prvek[k][j] -= pom * m->prvek[i][j];
            }
        }
    }

    // Zpìtná substituce
    *b = m->prvek[1][2] / m->prvek[1][1];
    *a = (m->prvek[0][2] - m->prvek[0][1] * (*b)) / m->prvek[0][0];
}


void linRegrese(double x[], double y[], int n, double *a, double *b){
  double sumx=0.0;
  double sumx2=0.0;// x na 2
  double sumxy=0.0;
  double sumy=0.0;

  for(int i=0; i<n; i++){
    sumx=sumx+x[i];
    sumx2=sumx2+x[i]*x[i];
    sumxy=sumxy+x[i]*y[i];
    sumy=sumy+y[i];
  }//konec for

  TMatice m = {
  .prvek = {
    {sumx2, sumx, sumxy},
    {sumx, n, sumy},
  },
  .radku = 2,
  .sloupcu = 3,
};

// Øešíme pomocí Gaussovy eliminace
gaussEliminace(&m, a, b);

/*

*a=(sumxy-(sumy*sumx)/n)/(sumx2-(sumx*sumx)/n);
*b=(sumy-*a*sumx)/n;

*/

}


// Funkce pro konstantní regresi (y = b)
void konstRegrese(double y[], int n, double *b) {
  double sumy = 0.0;

  for (int i = 0; i < n; i++) {
    sumy = sumy + y[i];
  }

  *b = sumy / n; // Prùmìrná hodnota y
}





//int main(int argc, char *argv[])  // pro parametry prikazoveho radku
int main(void)
{
  double a, b;
  int volba;

  printf("Vyberte typ regrese:\n");
  printf("1 - linearni (y = ax + b)\n");
  printf("2 - konstantni (y = b)\n");
  printf("Zadejte volbu: ");
  scanf("%d", &volba);

  if (volba == 1) {
    linRegrese(TAB_X, TAB_Y, TAB_LEN, &a, &b);
    printf("y = %.2fx + %.2f\n", a, b);
  } else if (volba == 2) {
    konstRegrese(TAB_Y, TAB_LEN, &b);
    printf("y = %.2f\n", b);
  } else {
    printf("Neplatná volba!\n");
  }

  return 0;

  return 0;
}
