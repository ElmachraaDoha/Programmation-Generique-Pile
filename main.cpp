#include <iostream>
#include <chrono>
#include <iomanip>
#include "PileTableau.h"
#include "PileListe.h"

using namespace std;
using namespace std::chrono;


template <class P>
void mesurer(int n, double& tempsEmpiler, double& tempsDepiler, long long& somme)
{
    P pile;

    auto debut = high_resolution_clock::now();

    for (int i = 0; i < n; i++)
    {
        pile.empiler(i);
    }

    auto fin = high_resolution_clock::now();

    tempsEmpiler =
        duration<double, milli>(fin - debut).count();


    debut = high_resolution_clock::now();

    somme = 0;

    for (int i = 0; i < n; i++)
    {
        somme += pile.depiler();
    }

    fin = high_resolution_clock::now();

    tempsDepiler =
        duration<double, milli>(fin - debut).count();
}


// ===============================
// NOUVELLE FONCTION
// ===============================

template <class P>
void compter(int n)
{
    P pile;

    long long pire = 0;

    for (int i = 0; i < n; i++)
    {
        long long avant = pile.getCompteur();

        pile.empiler(i);

        long long cout_ = pile.getCompteur() - avant;

        if (cout_ > pire)
        {
            pire = cout_;
        }
    }

    long long total = pile.getCompteur();

    cout << left
         << setw(10) << n
         << setw(15) << total
         << setw(15) << (double)total / n
         << setw(15) << pire
         << endl;
}


int main()
{
    const int tailles[] = {1000, 10000, 100000, 1000000};
    const int NB_REPETITIONS = 5;


    // ===============================
    // COMPTEUR
    // ===============================

    cout << fixed << setprecision(3);

    cout << "=== COMPTEUR (empiler) ===\n";

    cout << left
         << setw(10) << "N"
         << setw(15) << "total"
         << setw(15) << "total/N"
         << setw(15) << "pire appel"
         << endl;


    cout << "-- Tableau --\n";

    for (int n : tailles)
    {
        compter<PileTableau<int> >(n);
    }


    cout << "-- Liste --\n";

    for (int n : tailles)
    {
        compter<PileListe<int> >(n);
    }

    cout << "\n";


    // ===============================
    // TON CODE DE TEMPS
    // ===============================

    cout << "Temps moyens en millisecondes ("
         << NB_REPETITIONS
         << " repetitions)\n\n";


    cout << left
         << setw(10) << "N"
         << setw(20) << "Tableau empiler"
         << setw(20) << "Tableau depiler"
         << setw(20) << "Liste empiler"
         << setw(20) << "Liste depiler"
         << endl;


    for (int n : tailles)
    {
        double tabE = 0, tabD = 0;
        double lisE = 0, lisD = 0;

        long long somme = 0;


        for (int r = 0; r < NB_REPETITIONS; r++)
        {
            double e, d;


            mesurer<PileTableau<int> >
                (n, e, d, somme);

            tabE += e;
            tabD += d;


            mesurer<PileListe<int> >
                (n, e, d, somme);

            lisE += e;
            lisD += d;
        }


        cout << left
             << setw(10) << n
             << setw(20) << tabE / NB_REPETITIONS
             << setw(20) << tabD / NB_REPETITIONS
             << setw(20) << lisE / NB_REPETITIONS
             << setw(20) << lisD / NB_REPETITIONS
             << endl;
    }


    cout << "\n(somme de controle : verifie que rien n'a ete optimise a vide)"
         << endl;


    return 0;
}
