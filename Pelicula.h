/*
 * Pelicula.h
 *
 *  Created on: Nov 8, 2016
 *      Author: miguel
 */

#ifndef PELICULA_H_
#define PELICULA_H_
#include "Contenido.h"


class Pelicula: public Contenido{
public:
	Pelicula();
	Pelicula(std::string titulo, std::string genero, std::string sinopsis, unsigned int duracion):
		Contenido(titulo, genero, sinopsis), duracion(duracion) {};
	virtual ~Pelicula();

	virtual void print();

	bool equals(const Pelicula *p) const;

private:
	unsigned int duracion;
};

#endif /* PELICULA_H_ */
