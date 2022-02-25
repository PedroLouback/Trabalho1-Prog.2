#ifndef CONSULTORIO_H
#define CONSULTORIO_H
#include <vector>
#include <string>
#include <iostream>
#include "Paciente.hpp"
#include "Medico.hpp"
#include "Consulta.hpp"

using namespace std;

class Consultorio  
{
	private:

	string nome;
	string endereco;
	string telefone;
	vector <Paciente> vetPaciente;
	vector <Medico> vetMedico;
	vector <Consulta> vetConsulta;

	public:

		Consultorio();
		Consultorio(string nome, string endereco, string telefone);

		//Gets
		string getNome();
		string getEndereco();
		string getTelefone();

		//Sets
		void setNome(string nome);
		void setEndereco(string endereco);
		void setTelefone(string telefone);
		void setVetPaciente(vector <Paciente> vetPaciente);
		void setVetMedico(vector <Medico> vetMedico);
		void setVetConsulta(vector <Consulta> vetConsulta);	

		//Metodos
		void cadastrarPaciente(Paciente p);
		bool removerPaciente(int cpf);
		void cadastrarMedico(Medico m);
		void removerMedico(int CRM);
		void cadastrarConsulta(Consulta consulta);
		void removerConsulta(string nome, string data);
		void imprimirListaDeTodosOsPacientes();
		void imprimirConsultas();
		void imprimirConsultaDoMedico(int CRM, string data);
		void imprimirListaDeMedicos(string nome);
		bool VerificaPaciente(string nome);
		bool VerificaMedico(int CRM);
};
#endif