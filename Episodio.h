/*
 * Episodo.hpp
 *
 *  Created on: Nov 8, 2016
 *      Author: miguel
 */

#ifndef EPISODIO_H_
#define EPISODIO_H_
#include <string>
#include "Contenido.h"

class Episodio {
public:
	Episodio();
	Episodio(std::string nombre, unsigned int duracion): nombre(nombre), duracion(duracion) {};
	virtual ~Episodio();

	std::string to_string() const;

private:
	std::string nombre;
	unsigned int duracion;
};


#endif /* EPISODIO_H_ */
