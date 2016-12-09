/*
 * Temporada.h
 *
 *  Created on: Nov 14, 2016
 *      Author: miguel
 */

#ifndef TEMPORADA_H_
#define TEMPORADA_H_
#include "Episodio.h"
#include <iostream>
#include <vector>

class Temporada {
public:
	Temporada();
	Temporada(unsigned int nEpisodes);
	virtual ~Temporada();

	void add_chapter(Episodio *e);
	Episodio * consultar_n_episodio(unsigned int i) const;

private:
	// "number" indica el número de temporada
	// "nEpisodes" indica el numero de episodios por temporada
	// "index" indica la siguiente posicion vacía en el array de episodios
	unsigned int nEpisodes, index;
	Episodio **episodios;
};

#endif /* TEMPORADA_H_ */
