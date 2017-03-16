/*
 * Saga.cpp
 *
 *  Created on: Dec 16, 2016
 *      Author: miguel
 */
#include "Saga.h"

Saga::Saga() {

}

Saga::~Saga() {

}

void Saga::add_film(Pelicula *p) {
	films.push_back(p);
}

void Saga::delete_film(Pelicula *p) {
	std::vector<Pelicula *>::iterator it = films.begin();
	Pelicula *aux = *it;
	while (! aux->equals(p) && it != films.end()) {
		it ++;
		aux = *it;
	}
	if (*aux == *p)
		films.erase(it);
}
