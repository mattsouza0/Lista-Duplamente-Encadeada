#include "elemento.h"

namespace ed1 {
Elemento::Elemento()
{
    proximo = nullptr;
    anterior = nullptr;
    conteudo = 0;
}

Elemento::~Elemento()
{
    if(proximo != nullptr)
        delete proximo;
    if(anterior != nullptr)
        delete anterior;
}

}
