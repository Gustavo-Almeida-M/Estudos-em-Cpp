
typedef int TipoItem;

const int max_itens = 100;


class pilha
{
private:
    int tamanho;
    TipoItem* estrutura;
public:
    pilha();
    ~pilha();
    bool estaCheia();
    bool estaVazia();
    void inserir(TipoItem item);
    TipoItem remover();
    void imprimir();
    int qualTamanho();
};

