#ifndef ELEMENTO_H
#define ELEMENTO_H
#include <QString>
#include <sstream>
#include <string>

namespace ed1 {
class Elemento
{
private:
    int conteudo;
    Elemento *proximo,*anterior;
public:
    Elemento();
    virtual ~Elemento();

    Elemento* getAnterior(){return anterior;}
    void setAnterior(Elemento* anterior){this->anterior=anterior;}

    int getConteudo()const{return conteudo;}
    void setConteudo(int conteudo){this->conteudo=conteudo;}

    Elemento* getProximo()const{return proximo;}
    void setProximo(Elemento* proximo){this->proximo=proximo;}

};
}

#endif // ELEMENTO_H
