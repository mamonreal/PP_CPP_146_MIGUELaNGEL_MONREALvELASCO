/*
 * Pelicula.cpp
 *
 *  Created on: Nov 8, 2016
 *      Author: miguel
 */

#include "Pelicula.h"

Pelicula::Pelicula() {

}

Pelicula::~Pelicula() {
	// TODO Auto-generated destructor stub
}

void Pelicula::print() {
	std::cout << this->get_title() << std::endl;
	std::list<std::string> l = this->get_gender();
	std::list<std::string>::iterator it = l.begin();
	std::string s = *it;
	std::cout << "	" << s;
	it ++;
	while (it != l.end()) {
		s = *it;
		std::cout << ", " << s;
		it ++;
	}
	std::cout << "	" << this->get_sinopsis() << std::endl;
	std::cout << "	" << this->duracion << std::endl;
	std::cout << std::endl;
}

bool Pelicula::equals(const Pelicula *p) const{
	this->get_title() == p->get_title();
}


