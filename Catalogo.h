/*
 * Catalogo.h
 *
 *  Created on: Dec 8, 2016
 *      Author: miguel
 */

#ifndef CATALOGO_H_
#define CATALOGO_H_
#include "Pelicula.h"
#include "Serie.h"
#include "Documental.h"
#include "Saga.h"
#include <list>
#include <fstream>

class Catalogo{
public:
	Catalogo();
	virtual ~Catalogo();

	void add_film(Pelicula* film);
	void add_series(Serie* series);
	void add_documentary(Documental* documentary);
	void add_saga(Saga *s);

	//Se buscara una pelicula serie o documental a partir de su título
	//y se elimina
	void delete_film(std::string title);
	void delete_series(std::string title);
	void delete_documentary(std::string title);

	//Se buscara una película, serie o documental a partir de su título
	Pelicula* consult_film(std::string title);
	Serie* consult_series(std::string title);
	Documental* consult_documentary(std::string title);

	//Método sobrecargado que devuelve un puntero a un episodio,
	//en el caso de que se busque el episodio de una serie se debe decir:
	//título de la serie, temporada y número de capítulo.
	//En el caso de buscar el episodio de un documental se debe decir:
	//título del documental y número de episodio.
	Episodio* consult_chapter(std::string title, unsigned int season, unsigned int chapter);
	Episodio*consult_chapter(std::string title, unsigned int chapter);

	std::list<Contenido*> consult_gender(std::list<std::string> genders);

	void to_txt();


private:
	std::list<Pelicula*> peliculas;
	std::list<Serie*> series;
	std::list<Documental *> documentales;
	std::list<Saga *> sagas;

	std::list<Pelicula*>::iterator itPeliculas;
	std::list<Serie*>::iterator itSeries;
	std::list<Documental*>::iterator itDocumentales;
};


#endif /* CATALOGO_H_ */
