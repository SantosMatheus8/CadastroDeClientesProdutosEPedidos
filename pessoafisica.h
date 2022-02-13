#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H
#include"cliente.h"
namespace titi
{
class PessoaFisica;
}
class PessoaFisica : public Cliente
{
private:
    QString CPF;

public:
    PessoaFisica();
    PessoaFisica(int codigoIdentificador,QString rua,QString telefone,QString email,QString setor,QString cidade,QString estado, QString CPF, QString nome);

    static bool validaCPF(QString CPF);

    QString getNome() const;
    void setNome(const QString &value);

    QString getCPF() const;
    void setCPF(const QString &value);
};

#endif // PESSOAFISICA_H
