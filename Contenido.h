/*
 * Contenido.hpp
 *
 *  Created on: Nov 8, 2016
 *      Author: miguel
 */

#ifndef CONTENIDO_H_
#define CONTENIDO_H_
#include <string>
#include <list>
#include <iostream>
#include <fstream>

class Contenido {
public:
	Contenido();
	Contenido(std::string titulo, std::string genero, std::string sinopsis);
	virtual ~Contenido();

	//Anyadir genero a un contenido ya existente
	void add_genero(std::string genero);

	//virtual Contenido * consultar(const std::string *titulo) const {} = 0;

	int compare(Contenido& c) const;
	bool operator == (Contenido& c) const;
	bool is_title(std::string title) const;
	bool is_gender(std::string gender);
	virtual void print();
	virtual std::string to_string();

protected:
	std::string get_title() const;
	std::string get_sinopsis() const;
	std::list<std::string> get_gender() const;
	unsigned int n_gender() const;

private:
	std::string titulo;
	std::list <std::string> genero;
	std::string sinopsis;
};

#endif /* CONTENIDO_H_ */
