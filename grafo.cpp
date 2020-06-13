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




std::vector<AristaGrafo> Grafo::viajanteComercioVecino(Grafo G, int v){


    std::vector<int> V;
    int i =0;
    while (i < G.totalVertices()) {
        V.push_back(i);
        i++;
    }
   

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






