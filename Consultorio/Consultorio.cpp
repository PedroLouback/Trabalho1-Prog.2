#include "Consultorio.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Consultorio::Consultorio()
{	
}

Consultorio::Consultorio(string nome, string endereco, string telefone)
{
	this->nome=nome;
    this->endereco=endereco;
    this->telefone=telefone;
}

//Gets
string Consultorio::getNome()
{
    return nome;
}
string Consultorio::getEndereco()
{
    return endereco;
}
string Consultorio::getTelefone()
{
    return telefone;
}

//Sets
void Consultorio::setNome(string nome)
{
    this->nome = nome;
}

void Consultorio::setEndereco(string endereco)
{
    this->endereco = endereco;
}
void Consultorio::setTelefone(string telefone)
{
    this->telefone = telefone;
}

void Consultorio::setVetConsulta(vector <Consulta> vetConsulta){
    this->vetConsulta=vetConsulta;
}

//Metodos
void Consultorio::cadastrarPaciente(Paciente p){

    vetPaciente.push_back(p);
    cout << "\nPaciente foi cadastrado com sucesso!\n";

}
bool Consultorio::removerPaciente(int cpf){

    if (vetPaciente.size() == 0)
    {
        return false;
    }
    for (int i = 0; i < vetPaciente.size(); i++)
    {
        if (vetPaciente[i].getCpf() != cpf)
        {
            return false;
        }
    }

    for (int i = 0; i < vetPaciente.size(); i++)
    {
        if (vetPaciente[i].getCpf() == cpf)
        {
            vetPaciente.erase(vetPaciente.begin() + i);
            return true;
        }
    }
}
void Consultorio::cadastrarMedico(Medico m){
    vetMedico.push_back(m);
    cout << "\nMédico foi cadastrado com sucesso!\n";
}
void Consultorio::removerMedico(int CRM){

    if (vetMedico.size() == 0)
    {
        cout << "\nAVISO: Não existe nenhum médico cadastrado no sistema!\n";
    }

    for (int i = 0; i < vetMedico.size(); i++)
    {
        if (vetMedico[i].getCRM() != CRM)
        {
            cout << "\nERRO: Médico com o CRM " << CRM << " não foi encontrado para concluir a remoção!\n";
            break;
        }
    }

    for(int i=0; i < vetMedico.size(); i++){
        if(vetMedico[i].getCRM() == CRM){
            cout << "\nMédico com o CRM " << CRM << " removido com sucesso!\n";
            vetMedico.erase(vetMedico.begin() + i);
            break;
        }
    }
}
void Consultorio::cadastrarConsulta(Consulta consulta){
    vetConsulta.push_back(consulta);
    cout << "\nA consulta foi cadastrada com sucesso!\n";
}
void Consultorio::removerConsulta(string nome, string data){

    if (vetConsulta.size() == 0)
    {
        cout << "\nAVISO: Não existe nenhum consulta cadastrada!\n";
    }

    for(int i = 0; i < vetConsulta.size(); i++){
        if(vetConsulta[i].getData() == data){
            if(vetConsulta[i].getPaciente().getNome() == nome){
                vetConsulta.erase(vetConsulta.begin() + i);
                cout << "\nConsulta em que consta o nome do paciente " << nome << " marcada na data de " << data << " foi removida com sucesso!\n";
                break;
            }
        }else{
            cout << "\nERRO: Data da consulta não foi encontrada!";
        }
    }
}
void Consultorio::imprimirListaDeTodosOsPacientes(){

    if (vetPaciente.size() == 0)
    {
        cout << "\nAVISO: Não há nenhum paciente cadastrado!\n";
    }

    for(int i = 0; i < vetPaciente.size(); i++){
        cout << "\nPACIENTE " << i+1 << endl;
        cout << "Nome: " << vetPaciente[i].getNome() << endl;
        cout << "Sexo: " << vetPaciente[i].getSexo() << endl;
        cout << "Endereço: " << vetPaciente[i].getIdentidade() << endl;
        cout << "CPF: " << vetPaciente[i].getCpf() << endl;
        cout << "Telefone: " << vetPaciente[i].getTelefone() << endl;
        cout << "Identidade: " << vetPaciente[i].getIdentidade() << endl;
        cout << "Relato: " << vetPaciente[i].getRelato() << endl;
        cout << "Data da última consulta feita: " << vetPaciente[i].getDataUltimaConsulta() << endl;
        cout << "Medicação que esse paciente toma: " << vetPaciente[i].getMedicacaoQueToma() << endl;
    }

}
void Consultorio::imprimirConsultas(){

    if (vetConsulta.size() == 0)
    {
        cout << "\nAVISO: Não há nenhuma consulta cadastrada!\n";
    }

    for(int i = 0; i < vetConsulta.size(); i++){
        cout << "\n" << i + 1 << "º CONSULTA:";
        cout << "\nData marcada da consulta: " << vetConsulta[i].getData() << endl;
        cout << "Hora marcada: " << vetConsulta[i].getHora() << endl;
        cout << "Paciente: " << vetConsulta[i].getPaciente().getNome() << endl;
        cout << "CRM do médico: " << vetConsulta[i].getMedico().getCRM() << endl;
    }

}
void Consultorio::imprimirConsultaDoMedico(int CRM, string data){
    
    for(int i = 0; i < vetConsulta.size(); i++){
        if(vetConsulta[i].getData() == data){
            if(vetConsulta[i].getMedico().getCRM() == CRM){
                cout << "\nData marcada da consulta: " << vetConsulta[i].getData() << endl;
                cout << "Hora marcada: " << vetConsulta[i].getHora() << endl;
                cout << "Nome do paciente: " << vetConsulta[i].getPaciente().getNome() << endl;
                cout << "CRM do médico: " << vetConsulta[i].getMedico().getCRM() << endl;
            }
        }else{
            cout << "\nERRO: Data da consulta não foi encontrada!";
        }
    }
}
void Consultorio::imprimirListaDeMedicos(string nome){
    if(vetMedico.size() == 0){
        cout << "\nERRO: Não existe nenhum médico cadastrado no sistema!";
    }
    
    for(int i = 0; i < vetMedico.size(); i++){
        if (vetMedico[i].getNome() == nome){
            cout << "\nMédico com o nome " << nome << " encontrado com sucesso, segue seus dados: ";
            cout << "\n\nNome: " << vetMedico[i].getNome() << endl;
            cout << "Sexo: " << vetMedico[i].getSexo() << endl;
            cout << "Endereço: " << vetMedico[i].getIdentidade() << endl;
            cout << "CPF: " << vetMedico[i].getCpf() << endl;
            cout << "Telefone: " << vetMedico[i].getTelefone() << endl;
            cout << "Identidade: " << vetMedico[i].getIdentidade() << endl;
            cout << "CRM: " << vetMedico[i].getCRM() << endl;
            cout << "Especialidade: " << vetMedico[i].getEspecialidade() << endl;
            break;
        }
    }
    for(int i = 0; i < vetMedico.size(); i++){
        if (vetMedico[i].getNome() != nome){
            cout << "\nERRO: Não foi encontrado nenhum médico com o nome de " << nome << " no sistema!\n";
            break; 
        }
    }
    
}
bool Consultorio::VerificaPaciente(string nome){
    for (int i =0; i < vetPaciente.size(); i++){
        if (vetPaciente[i].getNome() == nome){
            return true;
        }
        return false;
    }
}
bool Consultorio::VerificaMedico(int CRM)
{
    for (int i = 0; i < vetMedico.size(); i++)
    {
        if (vetMedico[i].getCRM() == CRM)
        {
            return true;
        }
        return false;
    }
}
