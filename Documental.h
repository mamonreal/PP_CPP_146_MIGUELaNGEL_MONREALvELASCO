/*
 * Documental.h
 *
 *  Created on: Nov 8, 2016
 *      Author: miguel
 */

#ifndef DOCUMENTAL_H_
#define DOCUMENTAL_H_
#include "Contenido.h"
#include "Episodio.h"
#include <vector>

class Documental: public Contenido {
public:
	Documental();
	Documental(std::string titulo, std::string genero, std::string sinopsis):
		Contenido(titulo, genero, sinopsis) {};
	virtual ~Documental();

	void add_episode(Episodio *e);

	Episodio * consult_chapter(unsigned int i) const;
private:
	std::vector<Episodio *> episodios;
};

#endif /* DOCUMENTAL_H_ */
