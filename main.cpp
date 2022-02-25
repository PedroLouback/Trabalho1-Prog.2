#include <vector>
#include <string>
#include <iostream>
#include <windows.h>
#include "Paciente.hpp"
#include "Medico.hpp"
#include "Pessoa.hpp"
#include "Consulta.hpp"
#include "Consultorio.hpp"


using namespace std;

/*1 para cadastrar um médico.
• 2 para cadastrar um paciente.
• 3 para cadastrar uma consulta.
• 4 para imprimir dados do médico.
• 5 para imprimir consultas.
• 6 para imprimir dados do paciente
• 7 para imprimir data, hora, paciente e médico de uma consulta em específico
• 9 para remover médico
• 10 para remover paciente
• 11 para remover consulta
• 12 para sair*/

int main() {

    SetConsoleOutputCP(CP_UTF8);
    int escolha, cpf, CRM;
    char sexo;
    string nome, endereco, telefone, identidade, especialidade, dataUltimaConsulta, relato, medicacaoQueToma, data, hora;
    Paciente p;
    Consultorio consultorio;
    Medico m;
    Consulta consulta;

    while (1)
    {
        cout << "\n|----------------- > PROGRAMA DE CADASTRO PARA CONSULTÓRIO < ------------------|";
        cout << "\n|     •  Selecione uma das alternativas abaixos conforme sua descrição!  •     |";
        cout << "\n|1. Cadastrar um médico;                                                       |";
        cout << "\n|2. Cadastrar um paciente;                                                     |";
        cout << "\n|3. Cadastrar uma consulta;                                                    |";
        cout << "\n|4. Imprimir dados de um determinado médico;                                   |";
        cout << "\n|5. Imprimir consultas;                                                        |";
        cout << "\n|6. Imprimir dados dos pacientes;                                              |";
        cout << "\n|7. Imprimir data, hora, paciente e médico de uma determinada consulta;        |";
        cout << "\n|8. Remover médico;                                                            |";
        cout << "\n|9. Remover paciente;                                                          |";
        cout << "\n|10. Remover consulta;                                                         |";
        cout << "\n|11. Para encerrar o programa.                                                 |";
        cout << "\n|------------------------------------------------------------------------------|";
        cout << ("\n\nInforme a opção em que deseja fazer: ");
        cin >> escolha;

        switch (escolha)
        {
            case 1:

                cout << "\nInforme o nome do médico: ";
                cin.ignore();
                getline(cin, nome);
                cout << "Informe o endereço do médico: ";
                getline(cin, endereco);
                cout << "Informe o telefone do médico: ";
                getline(cin, telefone);
                cout << "Informe o número da identidade do médico: ";
                getline(cin, identidade);
                cout << "Informe o sexo do médico - (M - Masculino), (F - Feminino) e (I - Indefinido): ";
                cin >> sexo;
                cout << "Informe o CPF do médico: ";
                cin >> cpf;
                cout << "Informe o CRM do médico: ";
                cin >> CRM;
                cout << "Informe a especialidade: ";
                cin.ignore();
                getline(cin, especialidade);
                
                m.setNome(nome);
                m.setEndereco(endereco);
                m.setTelefone(telefone);
                m.setIdentidade(identidade);
                m.setSexo(sexo);
                m.setCpf(cpf);
                m.setCRM(CRM);
                m.setEspecialidade(especialidade);

                consultorio.cadastrarMedico(m);
                
                break;
            
            case 2:

                cout << "\nInforme o nome do paciente: ";
                cin.ignore();
                getline(cin, nome);
                cout << "Informe o endereço do paciente: ";
                getline(cin, endereco);
                cout << "Informe o telefone do paciente: ";
                getline(cin, telefone);
                cout << "Informe o número da identidade do paciente: ";
                getline(cin, identidade);
                cout << "Informe o sexo do paciente - (M - Masculino), (F - Feminino) e (I - Indefinido): ";
                cin >> sexo;
                cout << "Informe o CPF do paciente: ";
                cin >> cpf;
                cout << "Informe o relato do paciente: ";
                cin.ignore();
                getline(cin, relato);
                cout << "Informe a data da ultima consulta desse paciente: ";
                getline(cin, dataUltimaConsulta);
                cout << "Informe a medicação que esse paciente toma: ";
                getline(cin, medicacaoQueToma);

                p.setNome(nome);
                p.setEndereco(endereco);
                p.setTelefone(telefone);
                p.setIdentidade(identidade);
                p.setSexo(sexo);
                p.setCpf(cpf);
                p.setRelato(relato);
                p.setDataUltimaConsulta(dataUltimaConsulta);
                p.setMedicacaoQueToma(medicacaoQueToma);

                consultorio.cadastrarPaciente(p);

                break;

            case 3:

                cout << "\nInforme a data da consulta: ";
                cin.ignore();
                getline(cin, data);
                cout << "Informe a hora da consulta: ";
                getline(cin, hora);
                cout << "Informe o nome do paciente dessa consulta: ";
                getline(cin, nome);
                if (consultorio.VerificaPaciente(nome) == false){
                    cout << "\nERRO: Paciente com o nome '" << nome << "' não foi cadastrado!\n";
                    break;
                }
                p.setNome(nome);
                cout << "Informe o CRM do médico dessa consulta: ";
                cin >> CRM;
                if (consultorio.VerificaMedico(CRM) == false)
                {
                    cout << "\nERRO: Médico com o CRM " << CRM << " não foi cadastrado!\n";
                    break;
                }
                m.setNome(nome);

                consulta.setData(data);
                consulta.setHora(hora);
                consulta.setPaciente(p);
                consulta.setMedico(m);

                consultorio.cadastrarConsulta(consulta);

                break;

            case 4:

                cout << "\nInforme o nome do médico que deseja imprimir os dados: ";
                cin.ignore();
                getline(cin, nome);
                consultorio.imprimirListaDeMedicos(nome);
                break;
            
            case 5: 

                consultorio.imprimirConsultas(); 
                break;

            case 6:

                consultorio.imprimirListaDeTodosOsPacientes();
                break;

            case 7:

                cout << "\nInforme o CRM do médico em que consta a consulta: ";
                cin >> CRM;
                if (consultorio.VerificaMedico(CRM) == false)
                {
                    cout << "\nERRO: Médico com o CRM " << CRM << " não foi cadastrado!\n";
                    break;
                }
                cout << "\nInforme o data em que consta a consulta para imprimi-la: ";
                cin.ignore();
                getline(cin, data);
                consultorio.imprimirConsultaDoMedico(CRM, data);
                
                break;

            case 8:

                cout << "\nInforme o CRM do médico em que deseja remover: ";
                cin >> CRM;
                consultorio.removerMedico(CRM); 
                
                break;

            case 9:

                cout << "\nInforme o CPF do paciente em que deseja remover: ";
                cin >> cpf;
                if (consultorio.removerPaciente(cpf) == false){
                    cout << "\nERRO: CPF do paciente não foi encontrado!\n";
                    break;
                }else {
                    cout << "\nPaciente com o CPF " << cpf << " removido com sucesso!\n"; 
                }

                break;

            case 10:

                cout << "\nInforme o nome do paciente em que consta na consulta que deseja remover: ";
                cin.ignore();
                getline(cin, nome);
                if (consultorio.VerificaPaciente(nome) == false){
                    cout << "\nERRO:Nome de paciente não foi encontrado!";
                    break;
                }
                cout << "\nInforme a data da consulta que deseja remover: ";
                getline(cin, data);
                consultorio.removerConsulta(nome, data);

                break;

            case 11:
                cout << "\nVocê selecionou a opção de encerrar o programa!";
                cout << "\nENCERRANDO...";
                return 0;

            default:
                cout << "\nERRO: Opção inexistente, informe uma opção com um número de 1 a 11!" << endl;
                break;
        }
    }
}