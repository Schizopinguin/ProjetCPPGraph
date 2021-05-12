#include <string>
#include <iostream>
#include "CSommet.h"


CSommet::CSommet()
{
	pARCarrivants = nullptr;
	pARCpartants = nullptr;

	uiSOMindice = 0;
	uiSOMnbArrivees = 0;
	uiSOMnbDeparts = 0;
}

CSommet::CSommet(unsigned int uiindice)
{
	pARCarrivants = nullptr;
	pARCpartants = nullptr;

	uiSOMindice = uiindice;
	uiSOMnbArrivees = 0;
	uiSOMnbDeparts = 0;
}

CSommet::~CSommet()
{
}

CSommet::CSommet(const CSommet &SOMsommet)
{

	pARCarrivants = SOMsommet.pARCarrivants;
	pARCpartants = SOMsommet.pARCpartants;

	uiSOMindice = SOMsommet.uiSOMindice;
	uiSOMnbArrivees = SOMsommet.uiSOMnbArrivees;
	uiSOMnbDeparts = SOMsommet.uiSOMnbDeparts;
}

unsigned int CSommet::SOMGetIndice()
{
	return uiSOMindice;
}

CArc** CSommet::SOMGetTabArrivants()
{
	return pARCarrivants;
}

CArc** CSommet::SOMGetTabPartants()
{
	return pARCpartants;
}

unsigned int CSommet::SOMGetTabNbDeparts()
{
	return uiSOMnbDeparts;
}

unsigned int CSommet::SOMGetTNbArrivees()
{
	return uiSOMnbArrivees;
}

void CSommet::SOMSetIndice(unsigned int uiindice)
{
	uiSOMindice = uiindice;
}

void CSommet::SOMSetTabArrivants(CArc** pARCtab)
{
	pARCarrivants = pARCtab;
}

void CSommet::SOMSetTabPartants(CArc** pARCtab)
{
	pARCpartants = pARCtab;
}

void CSommet::SOMSetTabNbDeparts(unsigned int uinb)
{
	uiSOMnbDeparts = uinb;
}

void CSommet::SOMSetTNbArrivees(unsigned int uinb)
{
	uiSOMnbArrivees = uinb;
}

void CSommet::SOMAddArcArrivant(CSommet SOMdepart)
{
	CArc* pARCarc = new CArc(SOMdepart.uiSOMindice);

	uiSOMnbArrivees++;
	realloc(pARCpartants, uiSOMnbDeparts * sizeof(CArc*));

	pARCarrivants[uiSOMnbArrivees] = pARCarc;

	//ajouter un arc partant dans l'autre sommet
	//SOMdepart.SOMAddArcPartant(*this);
}

void CSommet::SOMAddArcPartant(CSommet SOMarrive)
{
	CArc* pARCarc = new CArc(SOMarrive.uiSOMindice);

	uiSOMnbDeparts ++;
	realloc(pARCpartants, uiSOMnbDeparts * sizeof(CArc*));

	pARCpartants[uiSOMnbDeparts] = pARCarc;
}

void CSommet::SOMModArcArrivant(CSommet SOMdest, CSommet SOMnouvelleDest)
{
	unsigned int uicompteArc;
	for (uicompteArc = 0; uicompteArc<uiSOMnbArrivees ;uicompteArc++) {
		if (pARCarrivants[uicompteArc]->ARCGetDestination() == SOMdest.uiSOMindice) {
			pARCarrivants[uicompteArc]->ARCSetDestination(SOMnouvelleDest.uiSOMindice);
		}

	}

}

void CSommet::SOMModArcPartant(CSommet SOMdest, CSommet SOMnouvelleDest)
{
	unsigned int uicompteArc;
	for (uicompteArc = 0; uicompteArc < uiSOMnbDeparts; uicompteArc++) {
		if (pARCpartants[uicompteArc]->ARCGetDestination() == SOMdest.uiSOMindice) {
			pARCpartants[uicompteArc]->ARCSetDestination(SOMnouvelleDest.uiSOMindice);
		}

	}

}

void CSommet::SOMDelArcArrivant(unsigned int uidest)
{
	for (unsigned int uicompteArc = 0; uicompteArc < uiSOMnbArrivees ; uicompteArc++) {
		if (pARCarrivants[uicompteArc]->ARCGetDestination() == uidest) {
			//suppression de l'arc
			delete pARCpartants[uicompteArc];
			//suppression de l'element du tableau des arrivees
			for (unsigned int uicompteSuppr = uicompteArc ; uicompteSuppr < uiSOMnbArrivees; uicompteSuppr++) {
				pARCarrivants[uicompteSuppr] = pARCarrivants[uicompteSuppr+1];
			}

			uiSOMnbArrivees --;
			realloc(pARCarrivants, uiSOMnbArrivees * sizeof(CArc*));

		}

	}

}

void CSommet::SOMDelArcPartant(unsigned int uidest)
{
	for (unsigned int uicompteArc = 0; uicompteArc < uiSOMnbDeparts; uicompteArc++) {
		if (pARCpartants[uicompteArc]->ARCGetDestination() == uidest) {
			//suppression de l'arc
			delete pARCpartants[uicompteArc];
			//suppression de l'element du tableau des arrivees
			for (unsigned int uicompteSuppr = uicompteArc; uicompteSuppr < uiSOMnbDeparts; uicompteSuppr++) {
				pARCpartants[uicompteSuppr] = pARCpartants[uicompteSuppr + 1];
			}

			uiSOMnbDeparts --;
			realloc(pARCpartants, uiSOMnbDeparts * sizeof(CArc*));

		}

	}

}

void CSommet::SOMRechercherArcArrivant(unsigned int uidest)
{

}

void CSommet::SOMRechercherArcPartant(unsigned int uidest)
{

}

void CSommet::SOMInverseTableaux() {
	CArc** pARCTemp = pARCarrivants;

	pARCarrivants = pARCpartants;
	pARCpartants = pARCTemp;
}
