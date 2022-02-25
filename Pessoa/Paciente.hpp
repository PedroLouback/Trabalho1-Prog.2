#ifndef PACIENTE_H
#define PACIENTE_H
#include <vector>
#include <string>
#include <iostream>
#include "Pessoa.hpp"

class Paciente : public Pessoa
{
	private:

	string relato;
	string dataUltimaConsulta;
	string medicacaoQueToma;

	public:

		Paciente();
		Paciente(string relato, string dataUltimaConsulta, string medicacaoQueToma, string nome, char sexo, string endereco, int cpf, string telefone, string identidade);

		//Gets
		string getRelato();
		string getDataUltimaConsulta();
		string getMedicacaoQueToma();

		//Sets
		void setRelato(string relato);
		void setDataUltimaConsulta(string dataUltimaConsulta);
		void setMedicacaoQueToma(string medicacaoQueToma);

		//Metodos
		void Imprimir();
};
#endif