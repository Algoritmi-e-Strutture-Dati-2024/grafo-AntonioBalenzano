int main() {
    Grafo<std::string> grafo;

    // Aggiungi nodi
    grafo.aggiungiNodo("torino");
    grafo.aggiungiNodo("napoli");
    grafo.aggiungiNodo("livorno");
    grafo.aggiungiNodo("taranto");
    grafo.aggiungiNodo("bari");

    // Aggiungi archi
    grafo.aggiungiArco("torino", "napoli", 200);
    grafo.aggiungiArco("napoli", "livorno", 150);
    grafo.aggiungiArco("livorno", "taranto", 300);
    grafo.aggiungiArco("taranto", "bari", 100);
    grafo.aggiungiArco("bari", "torino", 500);
    grafo.aggiungiArco("livorno", "bari", 400);

    
    grafo.stampa();
    std::cout<<"esiste il nodo 'torino'?"<< (grafo.verificaNodo ("torino")? "si" : "no")<<"\n";
    std::cout<<"esiste il nodo 'ancona'?"<< (grafo.verificaNodo ("ancona")? "si" : "no")<<"\n";
 

    // Stampa i nodi adiacenti a "torino"
    grafo.nodiAdiacenti("torino");
    std::cout<<"esiste l'arco tra 'torino' e 'napoli?"<< (grafo.verificaArco ("torino,", "napoli")? "si" : "no")<<"\n";
    std::cout<<"esiste l'arco tra 'napoli' e 'torino'?"<< (grafo.verificaArco ("napoli", "torino")? "si" : "no")<<"\n";
 
    grafo.RimuoviArco ("torino", "napoli");
    std::cout << "matrice di adiacenza dopo la rimozione dell'arco:"<<std::endl;
    
    grafo.graforimuoviNodo("torino");
     std::cout << "matrice di adiacenza dopo la rimozione del nodo 'torino':"<<std::endl;
     
     grafo.aggiunginodo("lecce");
     
     grafo.aggiungiArco("lecce","torino"):
     
     std::cout <<"sono connessi torino e napoli?"<<(grafo.sonoconnessi ("torino","napoli")? "si" : "no")<<"\n";
     std::cout <<"sono connessi napoli e torino?"<<(grafo.sonoconnessi ("napoli","torino")? "si" : "no")<<"\n";
    return 0;
}
