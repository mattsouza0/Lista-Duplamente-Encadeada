#ifndef LISTA_H
#define LISTA_H
#include <QString>
#include <sstream>
#include <string>
#include <elemento.h>
namespace ed1 {
class Lista
{
private:
    int qtd;
    Elemento *primeiro,*ultimo;
   // Elemento *encontre(int conteudo);
public:
    Lista();
    virtual ~Lista();

    Elemento* getPrimeiro()const{return primeiro;}

    int getQtd()const{return qtd;}

    Elemento* getUltimo()const{return ultimo;}

    void inserir(Elemento* novo);

    void excluir(int numero);//Elemento* excluir(Elemento *numero);

    bool busca(int conteudo)const;

    std::string listar()const;
};
}

#endif // LISTA_H
