#ifndef PEDIDO_H
#define PEDIDO_H
#include "cliente.h"
namespace titi
{
    class Pedido;
}

class Pedido
{
protected:
    int codigoIdentificador; //ID DO PEDIDO
    int numero; //ID DO PRODUTO
    QString cliente; //ID DO CLIENTE
    QString status;
    int data;
    float valorTotal;
public:
    Pedido();
    Pedido(int PcodigoIdentificador, int Pnumero, QString Pcliente, QString Pstatus, int Pdata, float PvalorTotal);



    int getNumero() const;
    QString getCliente() const;
    QString getStatus() const;
    int getData() const;
    float getValorTotal() const;
    int getCodigoIdentificador() const;


    void setNumero(int value);
    void setCliente(const QString &value);
    void setStatus(const QString &value);
    void setData(int value);
    void setValorTotal(float value);
    void setCodigoIdentificador(int value);

    bool operator > (Pedido &id)
    {
        if(this->codigoIdentificador > id.getCodigoIdentificador())
            return true;
        else return false;
    }

    bool operator < (Pedido &id)
    {
        if(this->codigoIdentificador < id.getCodigoIdentificador())
            return true;
        else return false;
    }

    bool operator == (Pedido &id)
    {
        if(this->codigoIdentificador == id.getCodigoIdentificador())
            return true;
        else return false;
    }

    bool operator != (Pedido &id)
    {
        if(this->codigoIdentificador != id.getCodigoIdentificador())
            return true;
        else return false;
    }

    bool operator >= (Pedido &id)
    {
        if(this->codigoIdentificador >= id.getCodigoIdentificador())
            return true;
        else return false;
    }

    bool operator <= (Pedido &id)
    {
        if(this->codigoIdentificador <= id.getCodigoIdentificador())
            return true;
        else return false;
    }
};

#endif // PEDIDO_H
