#include "PileDLL.h"
#include "PileListe.h"
#include "PileTableau.h"

// ============================================================
// PILE LISTE
// ============================================================

void* creerPileListe()
{
    return new PileListe<int>();
}

void detruirePileListe(void* pile)
{
    delete static_cast<PileListe<int>*>(pile);
}

void empilerPileListe(void* pile, int valeur)
{
    static_cast<PileListe<int>*>(pile)->empiler(valeur);
}

int depilerPileListe(void* pile)
{
    return static_cast<PileListe<int>*>(pile)->depiler();
}

long long compteurPileListe(void* pile)
{
    return static_cast<PileListe<int>*>(pile)->getCompteur();
}

int estVidePileListe(void* pile)
{
    return static_cast<PileListe<int>*>(pile)->estVide() ? 1 : 0;
}


// ============================================================
// PILE TABLEAU
// ============================================================

void* creerPileTableau()
{
    return new PileTableau<int>();
}

void detruirePileTableau(void* pile)
{
    delete static_cast<PileTableau<int>*>(pile);
}

void empilerPileTableau(void* pile, int valeur)
{
    static_cast<PileTableau<int>*>(pile)->empiler(valeur);
}

int depilerPileTableau(void* pile)
{
    return static_cast<PileTableau<int>*>(pile)->depiler();
}

long long compteurPileTableau(void* pile)
{
    return static_cast<PileTableau<int>*>(pile)->getCompteur();
}

int estVidePileTableau(void* pile)
{
    return static_cast<PileTableau<int>*>(pile)->estVide() ? 1 : 0;
}
