//
// Created by Razvan Andrei on 22.08.2025.
//
#include "repo.h"
#include <stdlib.h>
#include <stdio.h>

Repo* create_repo() {
	/*
	Functie care creeaza un repository

	return: un repository
	*/
	Repo* repo = malloc(sizeof(Repo));
	if (repo != NULL) {
		repo->cars = malloc(INITIAL_CAPACITY * sizeof(Car));
		if (repo->cars != NULL) {
			repo->size = 0;
			repo->capacity = INITIAL_CAPACITY;
			repo->next_id = 1;
		}
	}
	return repo;
}

void ensure_capacity(Repo* repo) {
	/*
	Functie care asigura capacitatea necesara pentru a adauga o masina in repository

	repo: repository-ul pentru care se asigura capacitatea
	*/
	if (repo->size == repo->capacity) {
		repo->capacity *= 2;
		Car* new_cars = realloc(repo->cars, repo->capacity * sizeof(Car));
		if (new_cars != NULL) {
			repo->cars = new_cars;
		}
	}
}

void repo_add_car(Repo* repo, Car* car) {
	/*
	Functie care adauga o masina in repository

	repo: repository ul in care se adauga masina
	car: masina care se adauga
	*/
	ensure_capacity(repo);
	car->ID = repo->next_id++;
	repo->cars[repo->size++] = *car;
}

void destroy_repo(Repo* repo) {
	/*
	Functie care distruge un repository

	repo: repository ul care se distruge
	*/
	for (int i = 0; i < get_size(repo); i++) {
		destroy_car(&repo->cars[i]);
	}
	free(repo->cars);
	free(repo);
}

Car* get_cars(Repo* repo) {
	/*
	 * Functie care returneaza toate obiectele din repo
	 *
	 * repo: repository-ul din care se returneaza obiectele
	 *
	 * Return: pointer la un vector de obiecte
	 */
	return repo->cars;
}

int get_size(Repo* repo) {
	/*
	Functie care returneaza size ul repository-ului

	repo: repository ul pentru care se returneaza size ul

	return: size ul repository-ului
	*/
	return repo->size;
}

Car* find_by_id(Repo* repo, int id) {
	/*
	Functie care gaseste o masina dupa id

	repo: repository ul in care se cauta masina
	id: id ul masinii

	return: masina gasita sau NULL
	*/
	for (int i = 0; i < get_size(repo); i++) {
		if (repo->cars[i].ID == id) {
			return &repo->cars[i];
		}
	}
	return NULL;
}

Car* find_by_index(Repo* repo, int index) {
	/*
	Functie care gaseste o masina dupa index

	repo: repository ul in care se cauta masina
	index: index ul masinii

	return: masina gasita sau NULL
	*/
	if (index < 0 || index >= get_size(repo)) {
		return NULL;
	}
	return &repo->cars[index];
}

bool update_license(Repo* repo, int id, const char* license) {
	/*
	Functie care actualizeaza numarul de inmatriculare al unei masini

	repo: repository ul in care se afla masina
	id: id ul masinii
	license: noul numar de inmatriculare

	return: true, daca numarul de inmatriculare a fost actualizat, false in caz contrar
	*/
	Car* car = find_by_id(repo, id);
	if (car == NULL) {
		return false;
	}
	set_license(car, license);
	return true;
}

bool update_model(Repo* repo, int id, const char* model) {
	/*
	Functie care actualizeaza modelul unei masini

	repo: repository ul in care se afla masina
	id: id ul masinii
	model: noul model

	return: true, daca modelul a fost actualizat, false in caz contrar
	*/
	Car* car = find_by_id(repo, id);
	if (car == NULL) {
		return false;
	}
	set_model(car, model);
	return true;
}

bool update_category(Repo* repo, int id, const char* category) {
	/*
	Functie care actualizeaza categoria unei masini

	repo: repository ul in care se afla masina
	id: id ul masinii
	category: noua categorie

	return: true, daca categoria a fost actualizata, false in caz contrar
	*/
	Car* car = find_by_id(repo, id);
	if (car == NULL) {
		return false;
	}
	set_category(car, category);
	return true;
}

bool update_is_rented(Repo* repo, int id, bool is_rented) {
	/*
	Functie care actualizeaza starea de inchiriere a unei masini

	repo: repository ul in care se afla masina
	id: id ul masinii
	is_rented: noua stare de inchiriere

	return: true, daca starea de inchiriere a fost actualizata, false in caz contrar
	*/
	Car* car = find_by_id(repo, id);
	if (car == NULL) {
		return false;
	}
	set_is_rented(car, is_rented);
	return true;
}