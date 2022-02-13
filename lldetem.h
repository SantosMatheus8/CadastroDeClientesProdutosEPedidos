#ifndef LTEM_H
#define LTEM_H
#include <no.h>
#include<QString>
namespace titi
{
class LTEM;
}
template<class T>
class LTEM
{
        NO<T>* inicio;
        NO<T>* fim;
        int quantidade;

    public:
        LTEM();

        int getQuantidade() {return quantidade;}
        bool estavazia()const{return quantidade == 0;}

        void inserirInicio(T valor);
        void inserirFim(T valor);
        void inserirOrdenado(T elemento);

        T operator[](int posicao);

        T retirarInicio();
        T retirarFim();
        T retirarPosicao(int posicao);

};
#endif // LTEM_H
template<class T>
LTEM<T>::LTEM():
    inicio(0),
    fim(0),
    quantidade(0)
{
}

template<class T>
void LTEM<T>::inserirInicio(T valor)
{
    NO<T>* pAux = new NO<T>(valor);
    if(estavazia())
    {
        inicio = fim = pAux;
    }
   else
    {
    pAux->setProximo(inicio);
    inicio->setAnterior(pAux);
    inicio = pAux;
    }
    quantidade++;
}
template<class T>
void LTEM<T>::inserirFim(T valor)
{
    NO<T>* pAux = new NO<T>(valor);
    if(estavazia())
    {
        inicio = fim = pAux;
        quantidade++;
    }
    else
    {
        fim->setProximo(pAux);
    pAux->setAnterior(fim);
    fim = pAux;
    quantidade++;
    }
}
template<class T>
T LTEM<T>::operator[](int posicao)
{
    if(posicao>=quantidade||posicao<0){throw QString("Posição Inexistente");}
    if(posicao==0){
        return inicio->getDado();
    }
    if(posicao==quantidade-1){
        return fim->getDado();
    }

    NO<T>* aux;
    aux = inicio;
    int cont = 0;
    while (cont<posicao){
        aux = aux->getProximo();
        cont++;
    }
    return aux->getDado();
}
template<class T>
void LTEM<T>::inserirOrdenado(T elemento)
{
    if(estavazia()) return inserirInicio(elemento);
    if(elemento <= inicio->getDado()) return inserirInicio(elemento);
    if(elemento >= fim->getDado()) return inserirFim(elemento);
    NO<T> *pAux = inicio;
    NO<T> *pNO = new NO<T>(elemento);
    while(elemento > pAux->getDado())
    {
        pAux = pAux->getProximo();
    }
    pNO->setProximo(pAux);
    pNO->setAnterior(pAux->getAnterior());
    pAux->getAnterior()->setProximo(pNO);
    pAux->setAnterior(pNO);
    quantidade++;

}
template<class T>
T LTEM<T>::retirarInicio()
{
    if(estavazia()) throw QString("Erro ao retirar");
    if(quantidade==1)
    {
        T valor = inicio->getDado();
        inicio = fim = 0;
        quantidade = 0;
        return valor;
    }
    NO<T>* pAux = inicio;
    inicio = inicio->getProximo();
    inicio->setAnterior(0);
    quantidade--;
    T valor = pAux->getDado();
    delete pAux;
    return valor;
}
template<class T>
T LTEM<T>::retirarFim()
{

   if(estavazia()) throw QString ("Lista vazia");
   NO<T>* pAux;
   if(quantidade ==1){
       pAux = fim;
       inicio = fim = 0;
       quantidade = 0;
       T valor = pAux->getDado();
       delete pAux;
       return valor;
   }
   pAux = fim;
   fim = fim->getAnterior();
   fim->setProximo(0);
   quantidade--;
   T valor = pAux->getDado();
   delete pAux;
   return valor;

}
template<class T>
T LTEM<T>::retirarPosicao(int posicao)
{
    if(posicao >= quantidade || posicao < 0) throw QString ("Posicao inexistente");
    if(posicao == 0) return retirarInicio();
    if(quantidade == 0) throw QString("Lista vazia");
    if(posicao == quantidade-1) return retirarFim();
    NO<T>* pAux = inicio;
    T valor;
    for(int i=0; i<posicao; i++)
    {
        pAux = pAux->getProximo();

    }
    pAux->getProximo()->setAnterior(pAux->getAnterior());
    valor = pAux->getDado();
    pAux->getAnterior()->setProximo(pAux->getProximo());
    quantidade--;
    return valor;
}
