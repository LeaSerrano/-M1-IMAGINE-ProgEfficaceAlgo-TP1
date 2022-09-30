#include "eval-perf.h"
#include <iostream>
#include <x86intrin.h>
#include <chrono>
#include <vector>
#include <math.h>

void EvalPerf::test_perf_Ex4() {
    long int n = 0;
    for (long int i = 0; i < 100000; i++) {
        n *= i;
    }
}

std::vector<int> EvalPerf::test_perf_Ex5(std::vector<int> tab, std::vector<int> tabP1, std::vector<int> tabP2, std::vector<int> tabFinal, int milieuTab) {

   for (int i = 0; i < milieuTab; i++) {
        if (i > 0) { 
            tabP1[i] = tabP1[i-1] + tab[i];
        }
        else {
            tabP1[i] = tab[i];
        }

        //std::cout << tabP1[i] << " " << i << std::endl;
    }

    for (int j = milieuTab; j < tab.size(); j++) {
        if (j > milieuTab) {
            tabP2[j] = tabP2[j-1] + tab[j];
        }
        else {
            tabP2[j] = tab[j];
        }

        //std::cout << tabP2[j] << " " << j << std::endl;
    }

    for (int k = 0; k < tab.size(); k++) {
        if (k < milieuTab) {
            tabFinal[k] = tabP1[k];
        }
        else {
            tabFinal[k] = tabFinal[milieuTab-1] + tabP2[k];
        }

        std::cout << tabFinal[k] << " " << k << std::endl;
    }

    //Methode de base mais plus couteuse sur les grands tableaux
    /*for (int i = 0; i < tab.size(); i++) {
        if (i == 0) {
            tabFinal[i] = tab[i];
        }
        else {
            tabFinal[i] = tab[i] + tab[i-1];
        }
    }*/

    return tabFinal;
}

int main() {
  int n, N;
  EvalPerf PE;

  //Exemple de base du tp
  /*std::vector<int> tab(4);
  tab[0] = 1;
  tab[1] = 3;
  tab[2] = 10;
  tab[3] = 2;

  std::vector<int> tabP1(2), tabP2(2), tabFinal(4), tabAffiche(4);

  int milieuTab = floor(2);*/

  std::vector<int> tab(10);
  for (int i = 0; i < 10; i++) {
    tab[i] = 100;
  }

  std::vector<int> tabP1(5), tabP2(5), tabFinal(10), tabAffiche(10);

  int milieuTab = floor(5);

  PE.start();
  //PE.test_perf_Ex4();

  PE.test_perf_Ex5(tab, tabP1, tabP2, tabFinal, milieuTab);

  PE.stop();

  std::cout << "nbr cycles: " << PE.cycles() << std::endl;
  std::cout << "nbr secondes: " << PE.seconds() << std::endl;
  std::cout << "nbr millisecondes: " << PE.millisecond() << std::endl;
  std::cout << "CPI = " << PE.CPI(N) << std::endl;
  std::cout << "IPC = " << PE.IPC(N) << std::endl;

  return 0;
}

