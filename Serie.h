/*
 * Serie.h
 *
 *  Created on: Nov 8, 2016
 *      Author: miguel
 */

#ifndef SERIE_H_
#define SERIE_H_
#include "Contenido.h"
#include "Temporada.h"

class Serie: public Contenido {
public:
	Serie();
	Serie(std::string titulo, std::string genero, std::string sinopsis):
		Contenido(titulo, genero, sinopsis) {};
	virtual ~Serie();

	void add_temporada(Temporada * t);
	Temporada * consultar_n_temporada(unsigned int i) const;

	Serie * consultar(std::string *s) const;

	Episodio * consult_chapter(unsigned int season, unsigned int chapter) const;

private:
	std::vector<Temporada *> temporadas;
};

#endif /* SERIE_H_ */
