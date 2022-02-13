#include "cliente.h"

QString Cliente::getRua() const
{
    return rua;
}

QString Cliente::getTelefone() const
{
    return telefone;
}

QString Cliente::getEmail() const
{
    return email;
}
QString Cliente::getSetor() const
{
    return setor;
}

QString Cliente::getCidade() const
{
    return cidade;
}

QString Cliente::getEstado() const
{
    return estado;
}

void Cliente::setRua(const QString &value)
{
    rua = value;
}

void Cliente::setTelefone(const QString &value)
{
    telefone = value;
}

void Cliente::setEmail(const QString &value)
{
    email = value;
}

void Cliente::setSetor(const QString &value)
{
    setor = value;
}

void Cliente::setCidade(const QString &value)
{
    cidade = value;
}

void Cliente::setEstado(const QString &value)
{
    estado = value;
}

int Cliente::getCodigoIdentificador() const
{
    return codigoIdentificador;
}

void Cliente::setCodigoIdentificador(int value)
{
    codigoIdentificador = value;
}

QString Cliente::getNome() const
{
    return nome;
}

void Cliente::setNome(const QString &value)
{
    nome = value;
}

Cliente::Cliente():

    codigoIdentificador(0),
    rua(""),
    telefone(""),
    email(""),
    setor(""),
    cidade(""),
    estado(""),
    nome("")
{
}
Cliente::Cliente(int PcodigoIdentificador, QString Prua, QString Ptelefone, QString Pemail, QString Psetor, QString Pcidade, QString Pestado, QString Pnome):
    codigoIdentificador(PcodigoIdentificador),
    rua(Prua),
    telefone(Ptelefone),
    email(Pemail),
    setor(Psetor),
    cidade(Pcidade),
    estado(Pestado),
    nome(Pnome)
{
}
