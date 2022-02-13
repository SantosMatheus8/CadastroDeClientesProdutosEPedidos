#ifndef NO_H
#define NO_H
#include<QString>
namespace titi
{
class NO;
}
template<class T>
class NO
{
private:
 T dado;
 NO* anterior;
 NO* proximo;
public:
    NO();
    NO(T valor);

    T getDado() const;
    void setDado(T value);

    NO *getAnterior() const;
    void setAnterior(NO *value);

    NO *getProximo() const;
    void setProximo(NO *value);
};

#endif // NO_H

template<class T>
NO<T>::NO():
    proximo(0),
    anterior(0),
    dado(0)
{
}
template<class T>
NO<T>::NO(T valor):
    dado(valor),
    anterior(0),
    proximo(0)
{
}
template<class T>
NO<T> *NO<T>::getAnterior()const
{
    return anterior;
}
template<class T>
void NO<T>::setAnterior(NO *value)
{
    anterior = value;
}
template<class T>
NO<T> *NO<T>::getProximo() const
{
    return proximo;
}
template<class T>
void NO<T>::setProximo(NO *value)
{
    proximo = value;
}
template<class T>
T NO<T>::getDado() const
{
    return dado;
}
template<class T>
void NO<T>::setDado(T value)
{
    dado = value;
}
