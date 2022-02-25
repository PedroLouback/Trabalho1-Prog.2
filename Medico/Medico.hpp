#ifndef MEDICO_H
#define MEDICO_H
#include <vector>
#include <string>
#include <iostream>
#include "Pessoa.hpp"

using namespace std;

class Medico : public Pessoa
{
	private:

	int CRM;
	string especialidade;

	public:

		Medico();
		Medico(int CRM, string especialdiade, string nome, char sexo, string endereco, int cpf, string telefone, string identidade);

		//Gets
		int getCRM();
		string getEspecialidade();

		//Sets
		void setCRM(int CRM);
		void setEspecialidade(string especialdiade);

		void Imprimir();
};
#endif