/*
 * Temporada.cpp
 *
 *  Created on: Nov 14, 2016
 *      Author: miguel
 */
#include "Temporada.h"
#include <iostream>

Temporada::Temporada() {
	this->nEpisodes = 3;
	this->index = 0;
	episodios = new Episodio*[nEpisodes];
}

Temporada::Temporada(unsigned int nEpisodes) {
	this->nEpisodes = nEpisodes;
	this->index = 0;
	episodios = new Episodio*[nEpisodes];
}

Temporada::~Temporada() {
	for (unsigned int i = 0; i < nEpisodes; i++)
		delete episodios[i];
	delete [] episodios;
}

//Anyade un nuevo episodio en la temporada en la posición "index", que marca la siguiente posicion vacía en el array
void Temporada::add_chapter(Episodio *e) {
	if (index < nEpisodes) {
		episodios [index] = e;
		index++;
	}
}

Episodio * Temporada::consultar_n_episodio(unsigned int i) const {
	if (i <= nEpisodes && i>0)
		return episodios[i-1];
	else
		return 0;
}
