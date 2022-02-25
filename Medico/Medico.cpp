#include "Medico.hpp"
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>

using namespace std;

Medico::Medico()
{	
}

Medico::Medico(int CRM, string especialdiade, string nome, char sexo, string endereco, int cpf, string telefone, string identidade) : Pessoa(nome,sexo,endereco,cpf,telefone,identidade)
{
	this->CRM=CRM;
    this->especialidade=especialidade;
}

//Gets
int Medico::getCRM(){
    return CRM;
}
string Medico::getEspecialidade(){
    return especialidade;
}

//Sets
void Medico::setCRM(int CRM){
    this->CRM=CRM;
}
void Medico::setEspecialidade(string especialidade){
    this->especialidade=especialidade;
}

//Metodos
void Medico::Imprimir(){
}