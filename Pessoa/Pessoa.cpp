#include "Pessoa.hpp"
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>

using namespace std;

Pessoa::Pessoa()
{
	
}

Pessoa::Pessoa(string nome, char sexo, string endereco, int cpf, string telefone, string identidade)
{
	this->nome=nome;
    this->sexo=sexo;
    this->endereco=endereco;
    this->cpf=cpf;
    this->telefone=telefone;
    this->identidade=identidade;
}

//Gets
string Pessoa::getNome(){
    return nome;
}
char Pessoa::getSexo(){
    return sexo;
}
string Pessoa::getEndereco(){
    return endereco;
}
int Pessoa::getCpf(){
    return cpf;
}
string Pessoa::getTelefone(){
    return telefone;
}
string Pessoa::getIdentidade(){
    return identidade;
}

//Sets
void Pessoa::setNome(string nome){
    this->nome=nome;
}
void Pessoa::setSexo(char sexo){
    this->sexo=sexo;
}
void Pessoa::setEndereco(string endereco)
{
    this->endereco = endereco;
}
void Pessoa::setCpf(int cpf){
    this->cpf=cpf;
}
void Pessoa::setTelefone(string telefone)
{
    this->telefone = telefone;
}
void Pessoa::setIdentidade(string identidade)
{
    this->identidade = identidade;
}

//Metodos
void Pessoa::Imprimir(){
    
}