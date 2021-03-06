// ProjetCPPGraphe.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "CLecture.h"
#include "CGraphe.h"
using namespace std;


int main(int argc, char *argv[])
{
	try {
		CLecture Test(argv[1]);
		Test.LECLireFichier();

		unsigned int uiboucleSommets;
		unsigned int uiboucleArcs;
		unsigned int uiboucleArcs2;
		CSommet** sommets = new CSommet*[Test.LECGetNbSommets()];
		for (uiboucleSommets = 0; uiboucleSommets < Test.LECGetNbSommets(); uiboucleSommets++) {
			sommets[uiboucleSommets] = new CSommet(Test.LECGetSommets()[uiboucleSommets]);
		}

		for (uiboucleArcs = 0; uiboucleArcs < Test.LECGetNbArcs(); uiboucleArcs++) {
			for (uiboucleArcs2 = 0; uiboucleArcs2 < Test.LECGetNbSommets(); uiboucleArcs2++) {
				if (sommets[uiboucleArcs2]->SOMGetIndice() == Test.LECGetArcsDepart()[uiboucleArcs]) {
					sommets[uiboucleArcs2]->SOMAddArcPartant(Test.LECGetArcsArrivee()[uiboucleArcs]);
				}
				if (sommets[uiboucleArcs2]->SOMGetIndice() == Test.LECGetArcsArrivee()[uiboucleArcs]) {
					sommets[uiboucleArcs2]->SOMAddArcArrivant(Test.LECGetArcsDepart()[uiboucleArcs]);
				}
			}
			//sommets[Test.LECGetArcsDepart()[uiboucleArcs] - 1]->SOMAddArcPartant(Test.LECGetArcsArrivee()[uiboucleArcs]);
			//sommets[Test.LECGetArcsArrivee()[uiboucleArcs] - 1]->SOMAddArcArrivant(Test.LECGetArcsDepart()[uiboucleArcs]);
		}


		CGraphe graphe(sommets, Test.LECGetNbSommets());

		graphe.GRAAfficherGraphe();

		graphe.GRAInverserGraphe();
		std::cout << "/!\\INVERSION DU GRAPHE/!\\" << std::endl;

		graphe.GRAAfficherGraphe();
		system("pause");
	}
		
	catch (CException *EXCException) {
		EXCException->EXCAfficherException();
	}
	return 0;
}