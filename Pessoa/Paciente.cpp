#include "Paciente.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Paciente::Paciente()
{
	
}

Paciente::Paciente(string relato, string dataUltimaConsulta, string medicacaoQueToma, string nome, char sexo, string endereco, int cpf, string telefone, string identidade) : Pessoa(nome, sexo, endereco, cpf, telefone, identidade)
{
	this->relato=relato;
    this->dataUltimaConsulta=dataUltimaConsulta;
    this->medicacaoQueToma=medicacaoQueToma;
}

//Gets
string Paciente::getRelato(){
    return relato;
}
string Paciente::getDataUltimaConsulta()
{
    return dataUltimaConsulta;
}
string Paciente::getMedicacaoQueToma()
{
    return medicacaoQueToma;
}

//Sets
void Paciente::setRelato(string relato){
    this->relato=relato;
}
void Paciente::setDataUltimaConsulta(string dataUltimaConsulta){
    this->dataUltimaConsulta=dataUltimaConsulta;
}
void Paciente::setMedicacaoQueToma(string medicacaoQueToma){
    this->medicacaoQueToma=medicacaoQueToma;
}

//Metodo
void Paciente::Imprimir(){
    
}