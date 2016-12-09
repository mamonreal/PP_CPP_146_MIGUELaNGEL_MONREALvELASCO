/*
 * main.cpp
 *
 *  Created on: Dec 8, 2016
 *      Author: miguel
 */
#include "Catalogo.h"
#include <iostream>

int main(){
	/*Las peliculas necesitan título, un genero, la sinopsis y la duracion(en min)
	Las series y los documentales necesitan de título, genero y sinopsis para ser
	iniciados.

	Peliculas, series y documentales se inician con un unico genero, en el caso
	de querer añadir más se hará mediante el método add_gender() de la clase
	Contenido.

	Para añadir un nuevo episodio a una serie será necesario incluirlo en una
	temporada que tenga hueco, y la temporada añadirla a la serie.

	Las temporadas tienen un tamaño fijo que se fija en el momento de la inicia-
	lización de la temporada.

	Para añadir un nuevo episodio a un documental se añade directamente a este.

	Se puede eliminar cualquier contenido teniendo su título.

	Los contenidos se almacenan en un objeto de la clase catálogo que se en-
	carga de la gestión de estos.*/

	//-----------------INICIALIZACION DE LAS PELICULAS-----------------
	Pelicula *p = new Pelicula("Batman", "Acción", "The Dark Knight of Gotham City begins his war on crime with his first major enemy being the clownishly homicidal Joker. ", 126);
	Pelicula *p2 = new Pelicula("El diario de Noa", "Drama", "A poor yet passionate young man falls in love with a rich young woman, giving her a sense of freedom, but they are soon separated because of their social differences. ", 123);
	Pelicula *p3 = new Pelicula("Superman", "Acción", "An alien orphan is sent from his dying planet to Earth, where he grows up to become his adoptive home's first and greatest superhero. ", 143);
	Pelicula *p4 = new Pelicula("TMNT", "Acción", "Unas tortugas son alteradas geneticamente y salvan la ciudad de NY", 130);
	Pelicula *p5 = new Pelicula("Rambo", "Acción", "In Thailand, John Rambo joins a group of missionaries to venture into war-torn Burma, and rescue a group of Christian aid workers who were kidnapped by the ruthless local infantry unit. ", 92);

	p->add_genero("Aventura");
	p2->add_genero("Romance");
	p3->add_genero("Aventura");
	p3->add_genero("Drama");
	p4->add_genero("Ciencia ficción");
	p5->add_genero("Thriler");
	p5->add_genero("Guerra");

	//--------------------INICIALIZACION DE LAS SERIES--------------------
	Serie *s = new Serie("Modern Family", "Comedia", "Three different, but related families face trials and tribulations in their own uniquely comedic ways.");
	Serie *s2 = new Serie("Castle", "Comedia", "After a serial killer imitates the plots of his novels, successful mystery novelist Richard Rick Castle receives permission from the Mayor of New York City to tag along with an NYPD homicide investigation team for research purposes. ");
	Serie *s3 = new Serie("El mentalista", "Crimen", "A famous psychic outs himself as a fake and starts working as a consultant for the California Bureau of Investigation so he can find Red John, the madman who killed his wife and daughter. ");
	Serie *s4 = new Serie("Shameless", "Comedia", "An alcoholic man lives in a perpetual stupor while his six children with whom he lives cope as best they can. ");

	s->add_genero("Romance");
	s2->add_genero("Crimen");
	s2->add_genero("Drama");
	s3->add_genero("Drama");
	s3->add_genero("Misterio");
	s4->add_genero("Drama");


	//--------------------INICIALIZACION DE LAS TEMPORADAS------------------
	Temporada *t = new Temporada(3);
	Temporada *t2 = new Temporada(3);
	Temporada *t3 = new Temporada(3);
	Temporada *t4 = new Temporada(3);
	Temporada *t5 = new Temporada(3);

	//---------------------INICIALIZACION DE LOS EPISODIOS--------------------
	//--------------------------------SERIES------------------------------
	Episodio *e = new Episodio("Pilot", 23);
	Episodio *e2 = new Episodio("Frank the Plank", 23);
	Episodio *e3 = new Episodio("Aunt Ginger", 23);
	Episodio *e4 = new Episodio("Summertime", 20);
	Episodio *e5 = new Episodio("Summer Love", 20);
	Episodio *e6 = new Episodio("I'll light a candel for you every day", 20);
	Episodio *e7 = new Episodio("Pilot", 25);
	Episodio *e8 = new Episodio("The bicycle thief", 25);
	Episodio *e9 = new Episodio("Come Fly with Me", 25);
	Episodio *e10 = new Episodio("The old wagon", 27);
	Episodio *e11 = new Episodio("The kiss", 27);
	Episodio *e12 = new Episodio("Earthquake", 27);
	Episodio *e13 = new Episodio("Dude Ranch", 23);
	Episodio *e14 = new Episodio("When good kids go bad", 23);
	Episodio *e15 = new Episodio("Phill on wire", 23);
	//---------------------------DOCUMENTALES---------------------------------
	Episodio *e16 = new Episodio("Introducción en Camboya", 56);
	Episodio *e17 = new Episodio("La politica en Camboya", 47);
	Episodio *e18 = new Episodio("Introducción en Costa Rica", 17);
	Episodio *e19 = new Episodio("Las tierras de Costa Rica", 37);
	Episodio *e20 = new Episodio("Costa Rica y el turismo", 39);

	//-------------------INICIALIZACION DE LOS DOCUMENTALES----------------
	Documental *d = new Documental("Camboya", "Geografia", "Descripcion de Camboya");
	Documental *d2 = new Documental("Costa Rica", "Geografia", "Descripción de Costa Rica");

	d->add_genero("Política");
	d2->add_genero("Politica");

	d->add_episode(e17);
	d2->add_episode(e19);
	d2->add_episode(e20);

	//----------------------------PRUEBA DE METODOS------------------
	Catalogo* c = new Catalogo();
	c->add_film(p);
	c->add_film(p2);
	c->add_film(p3);
	c->add_film(p4);
	c->add_film(p5);
	c->add_series(s);
	c->add_series(s2);
	c->add_series(s3);
	c->add_series(s4);
	c->add_documentary(d);
	c->add_documentary(d2);

	Temporada tp;
	tp.add_chapter(e9);
	tp.add_chapter(e8);

	t->add_chapter(e);
	t->add_chapter(e2);
	t->add_chapter(e3);
	t2->add_chapter(e4);
	t2->add_chapter(e5);
	t2->add_chapter(e6);
	t3->add_chapter(e7);
	t3->add_chapter(e8);
	t3->add_chapter(e9);
	t4->add_chapter(e10);
	t4->add_chapter(e11);
	t4->add_chapter(e12);
	t5->add_chapter(e13);
	t5->add_chapter(e14);
	t5->add_chapter(e15);

	s->add_temporada(t3);
	s->add_temporada(t4);
	s->add_temporada(t5);
	s4->add_temporada(t);
	s4->add_temporada(t2);

	d->add_episode(e16);
	d->add_episode(e17);
	d2->add_episode(e18);
	d2->add_episode(e19);
	d2->add_episode(e20);

	std::cout << "\n" << "Consulta la pelicula TMNT:" << "\n" << std::endl;
	Pelicula *consulta = c->consult_film("TMNT");
	consulta->print();

	std::cout << "\n" << "Consulta la serie Modern Family:" << "\n" << std::endl;
	Serie *consulta2 = c->consult_series("Modern Family");
	consulta2->print();

	std::cout << "\n" << "Consultar el episodio 2 de la temporada 1 de Shameless" << "\n" << std::endl;
	Episodio *consulta3 = c->consult_chapter("Shameless", 1, 2);
	std::cout << "\n" << consulta3->to_string() << "\n" << std::endl;

	std::cout << "\n" << "Se elimina la pelicula Superman de la colección." << "\n" << std::endl;
	c->delete_film("Superman");

	//Imprimir contenido cuyo tema sea Drama y Comedia
	std::cout << "\nContenido cuya tematica incluye Drama y Comedia" <<std::endl;
	std::list<std::string> lg;
	lg.push_back("Drama");
	lg.push_back("Comedia");
	std::list<Contenido*> lc = c->consult_gender(lg);
	std::list<Contenido*>::iterator it = lc.begin();
	while(it != lc.end()) {
		Contenido *cc = *it;
		cc->print();
		it ++;
	}


	std::cout << "\n" << "Se guarda una copia de la coleccion en el archivo copy.txt" << "\n" << std::endl;
	c->to_txt();

	//--------------------------DELETE DE PELICULAS---------------------------
	delete(p);
	delete(p2);
	delete(p3);
	delete(p4);
	delete(p5);

	//---------------------------DELETE DE SERIES---------------------------
	delete(s);
	delete(s2);
	delete(s3);
	delete(s4);

	//---------------------------DELETE DE DOCUMENTALES-------------------------------
	delete(d);
	delete(d2);

	//---------------------------DELETE DE TEMPORADAS--------------------------------
	delete(t);
	delete(t2);
	delete(t3);
	delete(t4);
	delete(t5);

	//---------------------------DELETE DE EPISODIOS------------------------------
	delete(e);
	delete(e2);
	delete(e3);
	delete(e4);
	delete(e5);
	delete(e6);
	delete(e7);
	delete(e8);
	delete(e9);
	delete(e10);
	delete(e11);
	delete(e12);
	delete(e13);
	delete(e14);
	delete(e15);
	delete(e16);
	delete(e17);
	delete(e18);
	delete(e19);
	delete(e20);


	//------------------------------DELETE DE CATALOGOS-----------------------------
	delete(c);

	return 0;
}
