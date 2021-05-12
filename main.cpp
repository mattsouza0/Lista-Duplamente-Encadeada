#include <QCoreApplication>
#include <iostream>
#include <elemento.h>
#include <lista.h>
using namespace std;
int menu(){
    int opcao;
    cout<<"---------------------------------------------------\n"<<endl;
    cout<<" 1 - Inserir na lista"<<endl;
    cout<<" 2 - Excluir da lista"<<endl;
    cout<<" 3 - Buscar elemento na lista"<<endl;
    cout<<" 4 - Listar elementos da lista"<<endl;
    cout<<" 0 - Sair"<<endl;
    cout<<"\n OPCAO-> ";
    cin>>opcao;
    return opcao;
}

int main(){
    ed1::Elemento* obj;
    ed1::Lista lista;
    int num,opcao=menu();
    while (opcao!=0) {
        switch (opcao) {
        case 1:
            try {
            cout<<"\n --->DIGITE UM NUMERO PARA INSERIR NA LISTA<---\n"<<" ";
            cin>>num;
            cout<<endl;
            obj = new ed1::Elemento();
            obj->setConteudo(num);
            lista.inserir(obj);
            obj=nullptr;
        } catch (const char* erro) {
            cout<<erro<<endl;
        }
            break;
        case 2:
            try {
            cout<<"\n --->DIGITE UM VALOR PARA SER EXCLUIDO<---\n"<<" ";
            cin>>num;
            cout<<endl;
            lista.excluir(num);
            cout<<" NUMERO REMOVIDO"<<endl;
        } catch (const char* erro) {
            cout<<erro<<endl;
        }
            break;
        case 3:
            try {
            cout<<"\n --->DIGITE UM NUMERO PARA BUSCAR NA LISTA<---\n"<<" ";
            cin>>num;
            cout<<endl;
            if(lista.busca(num) == true){
                cout<<"\n ELEMENTO ENCONTRADO\n"<<endl;
            }else{
                cout<<"\n ELEMENTO NAO ENCONTRADO\n"<<endl;
            }
        } catch (const char* erro) {
            cout<<erro<<endl;
        }
            break;
        case 4:
            try {
            cout<<"\n Elementos da lista: "<<lista.listar();
        } catch (const char* erro) {
            cout<<erro<<endl;
        }
            break;
        default:
        cout<<"\n Opcao invalida\nEscolha uma das opcoes acima"<<endl;
        break;
        }
        opcao = menu();
    }
    cout << "\n PROGRAMA FINALIZADO\n" << endl;
    return 0;
}
