#ifndef CONSULTA_H
#define CONSULTA_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Consulta  
{
	private:

	string data;
	string hora;
	Paciente paciente;
	Medico medico;

	public:

		Consulta();
		Consulta(string data, string hora);

		//Gets
		string getData();
		string getHora();
		Paciente getPaciente();
		Medico getMedico();

		//Sets
		void setData(string data);
		void setHora(string hora);
		void setPaciente(Paciente paciente);
		void setMedico(Medico medico);

		//Metodos
		void imprimir();

};
#endif