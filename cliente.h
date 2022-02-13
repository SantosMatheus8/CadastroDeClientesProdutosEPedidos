#ifndef CLIENTE_H
#define CLIENTE_H
#include<iostream>
#include<QString>
namespace titi
{
class Cliente;
}
class Cliente
{
protected:
    int codigoIdentificador;
    QString rua;
    QString telefone;
    QString email;
    QString setor;
    QString cidade;
    QString estado;
    QString nome;

public:
    Cliente();
    //Cliente(int codigoIdentificador, QString rua, QString telefone, QString email, QString setor,QString cidade,QString estado);
    Cliente(int PcodigoIdentificador, QString Prua, QString Ptelefone, QString Pemail, QString Psetor, QString Pcidade, QString Pestado, QString Pnome);

    QString getRua() const;
    QString getTelefone() const;
    QString getEmail() const;
    QString getSetor() const;
    QString getCidade() const;
    QString getEstado() const;
    int getCodigoIdentificador() const;


    void setRua(const QString &value);
    void setTelefone(const QString &value);
    void setEmail(const QString &value);
    void setSetor(const QString &value);
    void setCidade(const QString &value);
    void setEstado(const QString &value);
    void setCodigoIdentificador(int value);

    bool operator > (Cliente &ID)
    {
        if(this->codigoIdentificador > ID.getCodigoIdentificador()) return true;
        else return false;
    }
    bool operator < (Cliente &ID)
    {
        if(this->codigoIdentificador < ID.getCodigoIdentificador()) return true;
        else return false;
    }
    bool operator == (Cliente &ID)
    {
        if(this->codigoIdentificador == ID.getCodigoIdentificador()) return true;
        else return false;
    }
    bool operator != (Cliente &ID)
    {
        if(this->codigoIdentificador != ID.getCodigoIdentificador()) return true;
        else return false;
    }
    bool operator >= (Cliente &ID)
    {
        if(this->codigoIdentificador >= ID.getCodigoIdentificador()) return true;
        else return false;
    }
    bool operator <= (Cliente &ID)
    {
        if(this->codigoIdentificador <= ID.getCodigoIdentificador()) return true;
        else return false;
    }


    QString getNome() const;
    void setNome(const QString &value);
};

#endif // CLIENTE_H
