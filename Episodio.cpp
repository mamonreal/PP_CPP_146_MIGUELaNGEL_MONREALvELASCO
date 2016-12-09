/*
 * Episodio.cpp
 *
 *  Created on: Nov 15, 2016
 *      Author: miguel
 */
#include "Episodio.h"

Episodio::Episodio() {

}

Episodio::~Episodio() {

}

std::string Episodio::to_string() const{
	return this->nombre;
}
