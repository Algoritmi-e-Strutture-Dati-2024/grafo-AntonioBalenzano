#include <iostream>
#include "Grafo.cpp"  // Assicurati che la classe Grafo sia inclusa nel progetto

int main() {
    // Creazione del grafo
    Grafo<std::string> grafo;

    // Aggiunta dei nodi (città)
    grafo.aggiungiNodo("Torino");
    grafo.aggiungiNodo("Napoli");
    grafo.aggiungiNodo("Livorno");
    grafo.aggiungiNodo("Taranto");
    grafo.aggiungiNodo("Bari");

    // Aggiunta degli archi con i pesi (distanze tra le città)
    grafo.aggiungiArco("Torino", "Napoli", 200);
    grafo.aggiungiArco("Napoli", "Livorno", 150);
    grafo.aggiungiArco("Livorno", "Taranto", 300);
    grafo.aggiungiArco("Taranto", "Bari", 100);
    grafo.aggiungiArco("Bari", "Torino", 500);
    grafo.aggiungiArco("Livorno", "Bari", 400);

    // Visualizzazione del grafo (matrice di adiacenza)
    grafo.stampa();

    // Verifica se un nodo esiste
    std::cout << "\nEsiste il nodo 'Torino'? " << (grafo.verificaNodo("Torino") ? "Sì" : "No") << "\n";
    std::cout << "Esiste il nodo 'Ancona'? " << (grafo.verificaNodo("Ancona") ? "Sì" : "No") << "\n";

    // Verifica se esiste un arco tra due nodi
    std::cout << "\nEsiste un arco tra Torino e Napoli? " << (grafo.verificaArco("Torino", "Napoli") ? "Sì" : "No") << "\n";
    std::cout << "Esiste un arco tra Napoli e Torino? " << (grafo.verificaArco("Napoli", "Torino") ? "Sì" : "No") << "\n";

    // Verifica la connessione tra due nodi
    std::cout << "\nSono connessi Torino e Napoli? " << (grafo.sonoConnessi("Torino", "Napoli") ? "Sì" : "No") << "\n";
    std::cout << "Sono connessi Torino e Livorno? " << (grafo.sonoConnessi("Torino", "Livorno") ? "Sì" : "No") << "\n";

    // Trova l'arco con il peso minore da Torino
    grafo.arcoMinimo("Torino");

    // Nodi adiacenti a Torino
    grafo.nodiAdiacenti("Torino");

    // Rimozione di un nodo e dei suoi archi
    grafo.rimuoviNodo("Napoli");
    std::cout << "\nDopo la rimozione di Napoli:\n";
    grafo.stampa();

    // Rimozione di un arco specifico
    grafo.rimuoviArco("Torino", "Napoli");
    std::cout << "\nDopo la rimozione dell'arco Torino-Napoli:\n";
    grafo.stampa();

    // Aggiunta di un nuovo nodo e arco
    grafo.aggiungiNodo("Ancona");
    grafo.aggiungiArco("Ancona", "Taranto", 250);
    std::cout << "\nDopo l'aggiunta di Ancona e l'arco Ancona-Taranto:\n";
    grafo.stampa();

    // Applicazione dell'algoritmo di Dijkstra (cammini minimi da Torino)
    grafo.dijkstra("Torino");

    return 0;
}

