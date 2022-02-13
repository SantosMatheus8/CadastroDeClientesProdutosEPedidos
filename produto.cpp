#include "produto.h"

Produto::Produto():
    codigoid(0),
    descricao(""),
    preco(0),
    quant(0)
{
}
Produto::Produto(int Pcodigoid, QString Pdescricao, float Ppreco, int Pquant):
    codigoid(Pcodigoid),
    descricao(Pdescricao),
    preco(Ppreco),
    quant(Pquant)
{
}
QString Produto::getDescricao() const
{
    return descricao;
}

void Produto::setDescricao(const QString &value)
{
    descricao = value;
}

float Produto::getPreco() const
{
    return preco;
}

void Produto::setPreco(float value)
{
    preco = value;
}

int Produto::getQuant() const
{
    return quant;
}

void Produto::setQuant(int value)
{
    quant = value;
}
int Produto::getCodigoid() const
{
    return codigoid;
}

void Produto::setCodigoid(const int &value)
{
    codigoid = value;
}
