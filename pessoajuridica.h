#ifndef PESSOAJURIDICA_H
#define PESSOAJURIDICA_H
#include"cliente.h"
namespace titi
{
class PessoaJuridica;
}
class PessoaJuridica : public Cliente
{
private:
    QString razaoSocial;
    QString CNPJ;
public:
    PessoaJuridica();
    PessoaJuridica(int codigoIdentificador,QString rua,QString telefone,QString email,QString setor,QString cidade,QString estado, QString razaoSocial, QString nome, QString CNPJ);
    static bool validaCNPJ(QString CNPJ);

    QString getNome() const;
    QString getRazaoSocial() const;
    QString getCNPJ() const;

    void setNome(const QString &value);
    void setRazaoSocial(const QString &value);
    void setCNPJ(const QString &value);


};

#endif // PESSOAJURIDICA_H
