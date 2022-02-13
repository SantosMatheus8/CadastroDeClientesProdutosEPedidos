#include "pessoajuridica.h"

QString PessoaJuridica::getNome() const
{
    return nome;
}

QString PessoaJuridica::getRazaoSocial() const
{
    return razaoSocial;
}

void PessoaJuridica::setNome(const QString &value)
{
    nome = value;
}

void PessoaJuridica::setRazaoSocial(const QString &value)
{
    razaoSocial = value;
}

QString PessoaJuridica::getCNPJ() const
{
    return CNPJ;
}

void PessoaJuridica::setCNPJ(const QString &value)
{
    CNPJ = value;
}

bool PessoaJuridica::validaCNPJ(QString CNPJ)
{
    QString aux1, aux2;
    int validacao = 0, teste2 = 0, obs = 0;
    if (CNPJ.size()!=14)
    {
       return false;
    }
    else if (CNPJ.at(0) == CNPJ.at(1) && CNPJ.at(1) == CNPJ.at(2) && CNPJ.at(2) == CNPJ.at(3) &&
             CNPJ.at(3) == CNPJ.at(4) && CNPJ.at(4) == CNPJ.at(5) && CNPJ.at(5) == CNPJ.at(6) &&
             CNPJ.at(6) == CNPJ.at(7) && CNPJ.at(7) == CNPJ.at(8) && CNPJ.at(8) == CNPJ.at(9) &&
             CNPJ.at(9) == CNPJ.at(10) && CNPJ.at(10) == CNPJ.at(11) && CNPJ.at(11) == CNPJ.at(12)
             && CNPJ.at(12) == CNPJ.at(13))
    {
        return false;
    }

    else {

    int x = 5;
    for (int i = 0;i<4;i++)
    {
        aux1 = CNPJ.at(i);
        validacao = validacao + aux1.toInt()*x;
        x--;
    }
    x = 9;
    for (int i = 4; i < 12; i ++)
    {
        aux1 = CNPJ.at(i);
        validacao = validacao + aux1.toInt()*x;
        x--;
    }
    obs = validacao%11;
    if (obs == 0)
    {
        validacao = 0;
    }
        else
    {
            validacao = 11 - obs;
    }

    aux2 = CNPJ.at(12);
    teste2 =aux2.toInt();

    if (teste2==validacao){

         validacao = 0;
         int x = 6;

         for (int i = 0;i<5;i++)
         {
             aux1 = CNPJ.at(i);
             validacao = validacao + aux1.toInt()*x;
             x--;
         }
         x = 9;
         for (int i = 5; i < 13; i ++)
         {
             aux1 = CNPJ.at(i);
             validacao = validacao + aux1.toInt()*x;
             x--;
         }
        obs = validacao%11;
        if (obs == 0)
        {
            validacao = 0;
        }
            else
        {
                validacao = 11 - obs;
        }
        aux2 = CNPJ.at(13);
        teste2 = aux2.toInt();

        if(teste2==validacao)
        {
            return true;
        }
        else {
            return false;
        }
    }
    else {
         return false;
    }
   }
}
PessoaJuridica::PessoaJuridica():
    razaoSocial(""),
    CNPJ("")
{
}
PessoaJuridica::PessoaJuridica(int codigoIdentificador,QString rua,QString telefone,QString email,QString setor,QString cidade,QString estado, QString razaoSocial, QString nome, QString CNPJ):
     Cliente(codigoIdentificador, rua, telefone, email, setor, cidade, estado, nome),
     razaoSocial(razaoSocial),
     CNPJ(CNPJ)
{
}
