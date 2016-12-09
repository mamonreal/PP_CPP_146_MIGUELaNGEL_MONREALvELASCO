/*
 * Serie.cpp
 *
 *  Created on: Nov 8, 2016
 *      Author: miguel
 */

#include "Serie.h"

Serie::Serie() {
	// TODO Auto-generated constructor stub

}

Serie::~Serie() {
	// TODO Auto-generated destructor stub
}

void Serie::add_temporada(Temporada *t) {
	temporadas.push_back(t);
}

Temporada * Serie::consultar_n_temporada(unsigned int i) const {
	if (i < temporadas.size())
		return temporadas[i-1];
	else
		return 0;
}

Episodio * Serie::consult_chapter(unsigned int season, unsigned int chapter) const {
	if (season <= temporadas.size() && season > 0) {
		Temporada * t = temporadas[season-1];
		return t->consultar_n_episodio(chapter);
	}
	else
		return 0;
}

