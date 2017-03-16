/*
 * Saga.h
 *
 *  Created on: Dec 16, 2016
 *      Author: miguel
 */

#ifndef SAGA_H_
#define SAGA_H_
#include "Contenido.h"
#include "Pelicula.h"
#include <vector>

class Saga: public Contenido {
public:
	Saga();
	Saga(std::string titulo, std::string genero, std::string sinopsis):
		Contenido(titulo, genero, sinopsis) {};
	~Saga();

	void add_film(Pelicula *p);
	void delete_film(Pelicula *p);
private:
	std::vector<Pelicula *> films;
};

#endif /* SAGA_H_ */
