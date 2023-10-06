#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class cFuncoes
{
private:
public:

	void CriarArquivo(wstring Local, wstring Dados)
	{
		wofstream wofst(Local);
		wofst << Dados.c_str() << endl;
		wofst.close();
	}

	void LerArquivo(wstring Local)
	{
		fstream fst;
		string TextoObtido;
		fst.open(Local, ios::in);

		if (fst.is_open() == true)
		{
			while (getline(fst, TextoObtido))
				cout << TextoObtido;

			fst.close();
		}
		else
		{
			cout << "Não foi possível criar e escrever em arquivo.";
		}
	}

	void AcrescentarDados(wstring Local, string Dados)
	{
		fstream fst;
		string TextoObtido;
		fst.open(Local, ios::in | ios::out);

		if (fst.is_open() == true)
		{
			while (getline(fst, TextoObtido))
			{
				fst << Dados << endl;
				fst.close();
			}
		}
		else
		{
			cout << "Não foi possível abrir o arquivo.";
		}
	}

	void RenomearArquivo(wstring Anterior, wstring Novo)
	{
		if (_wrename(Anterior.c_str(), Novo.c_str()) == 0)
		{
			cout << "Arquivo renomeado com sucesso.";
		}
		else
		{
			_wperror(L"Houve um erro ao renomear o arquivo.");
		}
	}

	void ObterTamanhoDoArquivo(wstring Local)
	{
		wfstream wfst;
		wfst.open(Local, ios::in | ios::binary);
		if (wfst.is_open() == true)
		{
			int Tamanho;
			wfst.seekg(0, ios::end);
			Tamanho = wfst.tellg();
			wfst.close();

			string Converter = to_string(Tamanho);
			cout << "Tamanho: " + Converter << " Bytes";

		}
		else
		{
			cout << "Não foi possível abrir o arquivo.";
		}
	}

	void DeletarArquivo(wstring Arquivo)
	{
		if (_wremove(Arquivo.c_str()) == -1)
		{
			_wperror(L"Não foi possível remover o arquivo.");
		}
		else
		{
			cout << "Arquivo removido com sucesso.";
		}
	}

}Funcoes;

int main()
{
	cout << "O assistente está efetuando operações em um arquivo...";

	wstring LocalPadrao = L"C:\\Teste.txt";

	//Poderá usar qualquer função.
	Funcoes.CriarArquivo(LocalPadrao, L"Texto1");
	Funcoes.LerArquivo(LocalPadrao);
	Funcoes.AcrescentarDados(LocalPadrao, "Texto2");
	Funcoes.RenomearArquivo(LocalPadrao, L"C:\\Renomeado.txt");
	Funcoes.ObterTamanhoDoArquivo(L"C:\\Renomeado.txt");
	Funcoes.DeletarArquivo(L"C:\\Renomeado.txt");

	system("pause");
}