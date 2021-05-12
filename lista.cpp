#include "lista.h"

namespace ed1 {
Lista::Lista()
{
    primeiro = nullptr;
    ultimo = nullptr;
    qtd = 0;
}

Lista::~Lista()
{
    if(primeiro != nullptr)
        delete  primeiro;
}

void Lista::inserir(Elemento *novo){
    if(primeiro == nullptr){//primeiro e ultimo elemento
        primeiro = ultimo = novo;
        qtd++;
    }
    else if (primeiro->getConteudo()>=novo->getConteudo()){//insere no inicio
        novo->setProximo(primeiro);
        primeiro->setAnterior(novo);
        primeiro=novo;
        qtd++;
    }else{
        Elemento *cont = primeiro;
        while(cont != nullptr && cont->getConteudo() <= novo->getConteudo()){
            cont = cont->getProximo();
        }
        if(cont == nullptr){//insere no fim
            ultimo->setProximo(novo);
            novo->setAnterior(ultimo);
            ultimo = novo;
            qtd++;
        }else{//insere meio
            novo->setAnterior(cont->getAnterior());
            novo->setProximo(cont);
            cont->getAnterior()->setProximo(novo);
            cont->setAnterior(novo);
            qtd++;
        }
    }
}

bool Lista::busca(int conteudo) const{
    if(qtd==0){
        throw "\nOPERACAO INVALIDA\nLISTA VAZIA\n";
    }
    for(Elemento*i=primeiro;i!=nullptr;i=i->getProximo())
    {
        if(i->getConteudo()==conteudo){
            return true;
        }
    }
    return false;
}

void Lista::excluir(int numero){
    if(primeiro == nullptr)
        throw "\nOPERACAO INVALIDA\nLISTA VAZIA\n";
    for(Elemento*i=primeiro;i!=nullptr;i=i->getProximo()){
        if(i->getConteudo() == numero){
            Elemento* aux;
            if(i->getAnterior() == nullptr){//está no inicio
                aux = primeiro;
                primeiro = primeiro->getProximo();
                primeiro->setAnterior(nullptr);
                aux->setProximo(nullptr);
                qtd--;
            }
            else if(i->getProximo() == nullptr){//está no fim
                aux = ultimo;
                ultimo = ultimo->getAnterior();
                ultimo->setProximo(nullptr);
                aux->setAnterior(nullptr);
                qtd--;
            }else{//está no meio
                i->getAnterior()->setProximo(i->getProximo());
                i->getProximo()->setAnterior(i->getAnterior());
                qtd--;
            }
        }
    }
}

std::string Lista::listar() const{
    if(primeiro==nullptr)
        throw "\nOPERACAO INVALIDA\nLISTA VAZIA\n";
    std::stringstream ptr;
    for(Elemento*i=primeiro;i!= nullptr;i = i->getProximo()){
        ptr<<i->getConteudo()<<" ";
    }
    ptr<<"\n";
    return ptr.str();
}

}
