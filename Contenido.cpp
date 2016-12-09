/*
 * Contenido.cpp
 *
 *  Created on: Nov 8, 2016
 *      Author: miguel
 */
#include "Contenido.h"

Contenido::Contenido() {

}

Contenido::Contenido(std::string titulo, std::string genero, std::string sinopsis) {
	this->titulo = titulo;
	this->sinopsis = sinopsis;
	this->genero.push_back(genero);
}

Contenido::~Contenido(){

}

void Contenido::add_genero(std::string genero) {
	this->genero.push_back(genero);
}

std::string Contenido::get_title() const {
	return this->titulo;
}

std::string Contenido::get_sinopsis() const {
	return this->sinopsis;
}

std::list<std::string> Contenido::get_gender() const {
	return this->genero;
}

unsigned int Contenido::n_gender() const {
	unsigned int i = this->genero.size();
	return i;
}

int Contenido::compare(Contenido& c) const{
	if (this->titulo < c.titulo){
		return -1;
	}
	else if (this->titulo > c.titulo){
		return 1;
	}
	else
		return 0;
}

void Contenido::print() {
	std::cout << this->titulo << std::endl;
	std::list<std::string>::iterator it = this->genero.begin();
	std::string s = *it;
	std::cout << "	" << s;
	it ++;
	while (it != this->genero.end()) {
		s = *it;
		std::cout << ", " << s;
		it ++;
	}
//
	std::cout << "\n	" << this->sinopsis << std::endl;
}

bool Contenido::operator == (Contenido& c) const{
	return this->compare(c) == 0;
}

bool Contenido::is_title(std::string s) const{
	return this->titulo == s;
}

bool Contenido::is_gender(std::string gender) {
	std::list<std::string>::iterator it = this->genero.begin();
	while (it != this->genero.end()) {
		if (*it == gender)
			return true;
		else
			it++;
	}
	return false;
}

std::string Contenido::to_string() {
	std::string s = this->get_title();
	s += "\n\t";
	std::list<std::string>::iterator it = this->genero.begin();
	while (it != this->genero.end()) {
		if (it == this->genero.begin()) {
			s += *it;
			it ++;
		}
		else {
			s += ", ";
			s += *it;
			it ++;
		}
	}
	s += "\n\t";
	s += this->sinopsis;
	s += "\n\n";
	return s;
}

