#ifndef PESSOA_H
#define PESSOA_H
 

using namespace std;

class Pessoa  
{
	private:

	string nome;
	char sexo;
	string endereco;
	int cpf;
	string telefone;
	string identidade;

	public:

		Pessoa();
		Pessoa(string nome, char sexo, string endereco, int cpf, string telefone, string identidade);

		//Gets
		string getNome();
		char getSexo();
		string getEndereco();
		int getCpf();
		string getTelefone();
		string getIdentidade();

		//Sets
		void setNome(string nome);
		void setSexo(char sexo);
		void setEndereco(string endereco);
		void setCpf(int cpf);
		void setTelefone(string telefone);
		void setIdentidade(string identidade);

		//Metodos
		void Imprimir();
};
#endif