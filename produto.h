#ifndef PRODUTO_H
#define PRODUTO_H
#include <QString>
namespace titi
{
class Produto;
}
class Produto
{

private:
    int codigoid;
    QString descricao;
    float preco;
    int quant;

public:
    Produto();
    Produto(int Pcodigoid, QString Pdescricao, float Ppreco, int Pquant);

    int getCodigoid() const;
    void setCodigoid(const int &value);

    QString getDescricao() const;
    void setDescricao(const QString &value);

    float getPreco() const;
    void setPreco(float value);

    int getQuant() const;
    void setQuant(int value);

    bool operator > (Produto &ID){
        if(this->codigoid > ID.getCodigoid()) return  true;
        else return false;
    }

    bool operator < (Produto &ID){
        if(this->codigoid < ID.getCodigoid()) return  true;
        else return false;
    }

    bool operator == (Produto &ID){
        if(this->codigoid == ID.getCodigoid()) return  true;
        else return false;
    }

    bool operator != (Produto &ID){
        if(this->codigoid != ID.getCodigoid()) return  true;
        else return false;
    }

    bool operator >= (Produto &ID){
        if(this->codigoid >= ID.getCodigoid()) return  true;
        else return false;
    }

    bool operator <= (Produto &ID){
        if(this->codigoid <= ID.getCodigoid()) return  true;
        else return false;
    }

};

#endif // PRODUTO_H
