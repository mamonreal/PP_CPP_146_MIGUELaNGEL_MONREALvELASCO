/*
 * Documental.cpp
 *
 *  Created on: Nov 8, 2016
 *      Author: miguel
 */

#include "Documental.h"

Documental::Documental() {
	// TODO Auto-generated constructor stub

}

Documental::~Documental() {
	// TODO Auto-generated destructor stub
}

void Documental::add_episode(Episodio *e) {
	episodios.push_back(e);
}

Episodio * Documental::consult_chapter(unsigned int i) const {
	if (i <= episodios.size() && i > 0)
		return episodios[i-1];
	else
		return 0;
}


