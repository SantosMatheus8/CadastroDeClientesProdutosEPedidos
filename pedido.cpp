#include "pedido.h"

Pedido::Pedido():
    codigoIdentificador(0),
    numero(0),
    data(0),
    valorTotal(0)
{

}
Pedido::Pedido(int PcodigoIdentificador, int Pnumero, QString Pcliente, QString Pstatus, int Pdata, float PvalorTotal):
    codigoIdentificador(PcodigoIdentificador),
    numero(Pnumero),
    cliente(Pcliente),
    status(Pstatus),
    data(Pdata),
    valorTotal(PvalorTotal)

{

}

int Pedido::getNumero() const
{
    return numero;
}
QString Pedido::getCliente() const
{
    return cliente;
}
QString Pedido::getStatus() const
{
    return status;
}
int Pedido::getData() const
{
    return data;
}
float Pedido::getValorTotal() const
{
    return valorTotal;
}
int Pedido::getCodigoIdentificador() const
{
    return codigoIdentificador;
}
void Pedido::setNumero(int value)
{
    numero = value;
}
void Pedido::setCliente(const QString &value)
{
    cliente = value;
}
void Pedido::setStatus(const QString &value)
{
    status = value;
}
void Pedido::setData(int value)
{
    data = value;
}
void Pedido::setValorTotal(float value)
{
    valorTotal = value;
}
void Pedido::setCodigoIdentificador(int value)
{
    codigoIdentificador = value;
}
