#include "Consulta.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Consulta::Consulta()
{
	
}
	
Consulta::Consulta(string data, string hora)
{
	this->data=data;
    this->hora=hora;
}

//Gets
string Consulta::getData(){
    return data;
}
string Consulta::getHora(){
    return hora;
}
Paciente Consulta::getPaciente(){
    return paciente;
}
Medico Consulta::getMedico()
{
    return medico;
}

//Sets
void Consulta::setData(string data){
    this->data=data;
}
void Consulta::setHora(string hora){
    this->hora=hora;
}
void Consulta::setPaciente(Paciente paciente)
{
    this->paciente = paciente;
}
void Consulta::setMedico(Medico medico)
{
    this->medico = medico;
}

//Metodos
void Consulta::imprimir(){

    cout << "\nData da consulta: " << this->data << endl;
    cout << "Hora da consulta: " << this->hora << endl;
    cout << "Paciente: " << this->paciente.getNome() << endl;
    cout << "Médico: " << this->medico.getNome() << endl;
}