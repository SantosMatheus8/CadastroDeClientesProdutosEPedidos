#include "pessoafisica.h"

QString PessoaFisica::getNome() const
{
    return nome;
}

void PessoaFisica::setNome(const QString &value)
{
    nome = value;
}

QString PessoaFisica::getCPF() const
{
    return CPF;
}

void PessoaFisica::setCPF(const QString &value)
{
    CPF = value;
}
bool PessoaFisica::validaCPF(QString CPF)
{
    std::string cpf1= CPF.toStdString();
    int teste = -1;
    if(cpf1.length() != 11) return false;
    else if (CPF.at(0) == CPF.at(1) && CPF.at(1) == CPF.at(2) && CPF.at(2) == CPF.at(3) &&
             CPF.at(3) == CPF.at(4) && CPF.at(4) == CPF.at(5) && CPF.at(5) == CPF.at(6) &&
             CPF.at(6) == CPF.at(7) && CPF.at(7) == CPF.at(8) && CPF.at(8) == CPF.at(9) &&
             CPF.at(9) == CPF.at(10))
    {
        return false;
    }

    else
    {
    while(teste != 0)
    {
        int digito1 = cpf1.at(0) - 48;
        int digito2 = cpf1.at(1) - 48;
        int digito3 = cpf1.at(2) - 48;
        int digito4 = cpf1.at(3) - 48;
        int digito5 = cpf1.at(4) - 48;
        int digito6 = cpf1.at(5) - 48;
        int digito7 = cpf1.at(6) - 48;
        int digito8 = cpf1.at(7) - 48;
        int digito9 = cpf1.at(8) - 48;
        int digito10 = cpf1.at(9) - 48;
        int digito11 = cpf1.at(10) - 48;

        int verificacao1 = 0;
        verificacao1 = digito1 * 10 + digito2 * 9 + digito3 * 8 + digito4 * 7 + digito5 * 6 + digito6 * 5 + digito7 * 4 + digito8 * 3 + digito9 * 2 ;
        verificacao1 = verificacao1 * 10;

        int D1 = verificacao1%11;
        int verificacao2 = 0;
        verificacao2 = digito1 * 11 + digito2 * 10 + digito3 * 9 + digito4 * 8 + digito5 * 7 + digito6 * 6 + digito7 * 5 + digito8 * 4 + digito9 * 3 ;
        int D2 = verificacao2;
        verificacao2 =(D2 + (D1 * 2)) * 10;
        verificacao2 = verificacao2%11;

        if(D1 == digito10 && verificacao2 == digito11)
        {
            return true;
        }
        else return false;
        teste = 0;
    }
    }
}






PessoaFisica::PessoaFisica():
    Cliente(),
    CPF("")
{
}

PessoaFisica::PessoaFisica(int codigoIdentificador,QString rua,QString telefone,QString email,QString setor,QString cidade,QString estado, QString CPF, QString nome):
     Cliente(codigoIdentificador, rua, telefone, email, setor, cidade, estado, nome),
     CPF(CPF)

{
}
