/*
 * Catalogo.cpp
 *
 *  Created on: Dec 8, 2016
 *      Author: miguel
 */
#include "Catalogo.h"

Catalogo::Catalogo() {

}

Catalogo::~Catalogo() {

}



//--------------------METODOS PARA AÑADIR CONTENIDOS--------------------
void Catalogo::add_film(Pelicula* film){
	peliculas.push_back(film);
}

void Catalogo::add_series(Serie* series){
	this->series.push_back(series);
}

void Catalogo::add_documentary(Documental* documentary){
	documentales.push_back(documentary);
}

//------------------METODOS PARA ELIMINAR ELEMENTOS---------------------
void Catalogo::delete_film(std::string title) {
	itPeliculas = peliculas.begin();
	bool b = false;
	Pelicula *p;
	while (itPeliculas != peliculas.end() && !b) {
		p = *itPeliculas;
		if (p->is_title(title)) {
			b = true;
			itPeliculas = peliculas.erase(itPeliculas);
			//*p = NULL;
			delete(p);
		}
		else
			itPeliculas ++;
	}
	p = *itPeliculas;
	if (p->is_title(title)) {
		peliculas.erase(itPeliculas);
		//*p = NULL;
		delete(p);
	}
}

void Catalogo::delete_series(std::string title) {
	itSeries = series.begin();
	bool b = false;
	Serie *s;
	while (itSeries != series.end() && !b) {
		s = *itSeries;
		if (s->is_title(title)) {
			b = true;
			itSeries = series.erase(itSeries);
			//*s = NULL;
			delete(s);
		}
		else
			itSeries ++;
	}
	s = *itSeries;
	if (s->is_title(title)) {
		series.erase(itSeries);
		//*s = NULL;
		delete(s);
	}
}

void Catalogo::delete_documentary(std::string title) {
	itDocumentales = documentales.begin();
	bool b = false;
	Documental *d;
	while (itDocumentales != documentales.end() && !b) {
		d = *itDocumentales;
		if (d->is_title(title)) {
			b = true;
			itDocumentales = documentales.erase(itDocumentales);
			//*d = NULL;
			delete(d);
		}
		else
			itDocumentales ++;
	}
	d = *itDocumentales;
	if (d->is_title(title)) {
		documentales.erase(itDocumentales);
		//*d = NULL;
		delete(d);
	}
}


//--------------------METODOS DE CONSULTA DE CONTENIDO------------------
//Dado que dos contenidos son iguales si comparten el título,
//se puede usar un objeto que solo tenga el nombre para buscar
Pelicula* Catalogo::consult_film(std::string title) {
	itPeliculas = peliculas.begin();
	while (itPeliculas != peliculas.end()) {
		Pelicula *p = *itPeliculas;
		if (p->is_title(title))
			return p;
		else
			itPeliculas ++;
	}
	Pelicula *p = *itPeliculas;
	if (p->is_title(title))
		return p;
	else
		return 0;
}

Serie* Catalogo::consult_series(std::string title) {
	itSeries = series.begin();
	while (itSeries != series.end()) {
		Serie *s = *itSeries;
		if (s->is_title(title))
			return s;
		else
			itSeries ++;
	}
	Serie *s = *itSeries;
	if (s->is_title(title))
		return s;
	else
		return 0;
}

Documental* Catalogo::consult_documentary(std::string title) {
	itDocumentales = documentales.begin();
	while (itDocumentales != documentales.end()) {
		Documental *d = *itDocumentales;
		if (d->is_title(title))
			return d;
		else
			itDocumentales ++;
	}
	Documental *d  = *itDocumentales;
	if (d->is_title(title))
		return d;
	else
		return 0;
}

//--------------------METODOS PARA CONSULTAR EPISODIOS-----------------
Episodio* Catalogo::consult_chapter(std::string title, unsigned int chapter) {
	Documental *d = consult_documentary(title);
	return d->consult_chapter(chapter);
}

Episodio* Catalogo::consult_chapter(std::string title, unsigned int season, unsigned int chapter) {
	Serie *s = consult_series(title);
	return s->consult_chapter(season, chapter);
}

//-----------------METODOS PARA CONSULTAR GENERO---------------------------
std::list<Contenido*> Catalogo::consult_gender(std::list<std::string> genders) {
	//Primero se crea una lista de contenidos c que perteneceran al género
	//que aparezca primero en la lista
	std::list<Contenido*> c;
	std::list<Contenido*>::iterator it;
	std::string s = genders.front();
	//Se incluyen las peliculas en la lista c
	itPeliculas = peliculas.begin();
	Contenido *aux;
	while (itPeliculas != peliculas.end()) {
		aux = *itPeliculas;
		if (aux->is_gender(s))
			c.push_back(aux);
		itPeliculas ++;
	}
	//Se incluyen las series en la lista c
	itSeries = series.begin();

	while (itSeries != series.end()) {
		aux = *itSeries;
		if (aux->is_gender(s))
			c.push_back(aux);
		itSeries ++;
	}
	//Se incluyen los documentales en la lista c
	itDocumentales = documentales.begin();

	while (itDocumentales != documentales.end()) {
		aux = *itDocumentales;
		if (aux->is_gender(s))
			c.push_back(aux);
		itDocumentales ++;
	}
	genders.pop_front();
	//Una vez se hayan incluido todos los contenidos en la lista c, se procede
	//a eliminar aquellos que no pertenezcan a los demás géneros de la lista
	while (! genders.empty()) {
		s = genders.front();
		it = c.begin();
		while (it != c.end()) {
			aux = *it;
			if (! aux->is_gender(s))
				it = c.erase(it);
			else
				it ++;
		}
		genders.pop_front();
	}
	return c;
}

void Catalogo::to_txt() {
	std::ofstream file("copy.txt");
	file << "Peliculas:\n";
	itPeliculas = peliculas.begin();
	Pelicula *p;
	while(itPeliculas != peliculas.end()) {
		p = *itPeliculas;
		file << p->to_string();
		itPeliculas ++;
	}
	file << "Series:\n";
	itSeries = series.begin();
	Serie *s;
	while(itSeries != series.end()) {
		s = *itSeries;
		file << s->to_string();
		itSeries ++;
	}
	file << "Documentales:\n";
	itDocumentales = documentales.begin();
	Documental *d;
	while (itDocumentales != documentales.end()) {
		d = *itDocumentales;
		file << d->to_string();
		itDocumentales ++;
	}
	file.close();
}














