#include "grafo.h"
#include <algorithm>
#include <sstream>
#include <vector>


const int Grafo::INFINITO;

Grafo::Grafo(int v)
{
    vertices = v;
    aristas = std::vector<int>(vertices*vertices,Grafo::INFINITO);

}

Grafo::Grafo(int v, std::vector<std::vector<int>> costes)
{
    vertices=v;
    aristas=std::vector<int>(vertices*vertices);
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            set(i,j,costes[i][j]);
        }
    }
}

Grafo::~Grafo(){}

int Grafo::coste(int v, int w)
{
    return getPos(v,w);
}

void Grafo::inserta(int v, int w, int coste)
{
    set(v,w,coste);
}

int Grafo::totalVertices()
{
    return vertices;
}



/*Grafo Grafo::prim(Grafo G)
{
    Conjunto U(G.totalVertices());
    Conjunto W(0); // no lo uso  W=N-U  (todos los nodos del conjunto - U
    Grafo H(G.totalVertices());
    int u,w;
    int cardinalU=0;
    U.inserta(0);
    while(cardinalU<G.totalVertices()){
        costeMinimoArista(G,U,W,u,w);
        H.inserta(u,w,G.aristas[u][w]);
        U.inserta(w);
        cardinalU++;
    }
    return H;

}*/

std::vector<AristaGrafo> Grafo::viajanteComercioVecino(Grafo G, int v){


    std::vector<int> V;
    int i =0;
    while (i < G.totalVertices()) {
        V.push_back(i);
        i++;
    }
    /* V.push_back(0); V.push_back(1);V.push_back(2);V.push_back(3);
    V.push_back(4); V.push_back(5);V.push_back(6);V.push_back(7);
    V.push_back(8); V.push_back(9);V.push_back(10);V.push_back(11);
    V.push_back(12); V.push_back(13);V.push_back(14);V.push_back(15);
    V.push_back(16); V.push_back(17);V.push_back(18);V.push_back(19);*/   //NODOS CIUDADES(NO ES GENERICO)

    std::vector<int> T;
    T.push_back(v);
    std::vector<int> W;
    std::sort(V.begin(),V.end());
    std::sort(T.begin(),T.end());
    for(unsigned int i  =0; i<V.size(); i++){
        for(unsigned int j = 0;j<T.size();j++){
            if(V[i] != T[j]){
                W.push_back(V[i]);
            }
        }
    }

    std::vector<AristaGrafo> lista;
    int u = v;
    int w = 0;

    while (!esIgual(T,V)){
        int costeMinimo=Grafo::INFINITO;

        for(int j=0;j<G.totalVertices();j++){
            if(G.getPos(u,j)<costeMinimo && u!=j && pertenece(W,j) /*&& j != anterior*/){
                costeMinimo=G.getPos(u,j);
                w=j;

            }
        }
        lista.push_back(AristaGrafo(u,w,G.getPos(u,w)));
        T.push_back(w);
        for(unsigned int i = 0; i<  W.size();i++){
            if(W[i] == w){
                W.erase(W.begin()+i);
            }
        }
        std::sort(W.begin(),W.end());
        u=w;
    }

    AristaGrafo b (w,v,G.getPos(w,v));
    lista.push_back(b);

    return lista;
}

std::string Grafo::imprime(std::string s){
    std::stringstream ss ;
    ss << s << ": " << std::endl;
    for(int i  =0; i< vertices; i++){
        ss << "\n[" <<(i+1) << "]" << ((i< 9)?" ":"");
        for(int j = 0; j < vertices; j++){
            if(getPos(i,j) == Grafo::INFINITO){
                ss << "----";
            }else{
                if(getPos(i,j) < 10){
                    ss << "    " << getPos(i,j) << " ";
                }else{
                    if(getPos(i,j) < 100){
                        ss << "   " << getPos(i,j) << " ";
                    }else{
                        if(getPos(i,j) < 1000){
                            ss << "  " << getPos(i,j) << " ";
                        }else{
                            ss << " " << getPos(i,j) << " ";
                        }
                    }
                }
            }
        }
    }
    return ss.str();
}



/*
void Grafo::costeMinimoArista(Grafo G, Conjunto T, Conjunto W, int &u, int &w)
{
    int costeMinimo=Grafo::INFINITO;

    w=0;
    for(int i=u;i<G.totalVertices();i++){
        for(int j=0;j<G.totalVertices();j++){
            if(G.aristas[i][j]<costeMinimo && G.aristas[i][j] !=-1 && T.pertenece(i) && !T.pertenece(j)){
                costeMinimo=G.aristas[i][j];
                u=i;
                w=j;
            }
        }
    }
}
*/



