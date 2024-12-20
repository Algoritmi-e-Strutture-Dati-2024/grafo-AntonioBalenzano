#include <iostream>
#define MAX_NODI 100
#define INF 1000000000 // Rappresenta l'assenza di connessione

template <typename T>
class Grafo {
private:
    T nodi[MAX_NODI]; // Array dei nodi
    int matriceAdiacenza[MAX_NODI][MAX_NODI]; // Matrice di adiacenza
    bool esisteNodo[MAX_NODI]; // Indica se un nodo esiste
    int numeroNodi = 0; // Numero attuale di nodi

public:
    // Costruttore
    Grafo() {
        for (int i = 0; i < MAX_NODI; ++i) {
            esisteNodo[i] = false; // Imposto che non esistano nodi inizialmente
            for (int j = 0; j < MAX_NODI; ++j) {
                matriceAdiacenza[i][j] = INF; // Imposto la matrice di adiacenza con INF (assenza di connessione)
            }
            matriceAdiacenza[i][i] = 0; // La distanza da un nodo a se stesso è 0
        }
    }

    // Aggiunge un nodo al grafo, in input viene inserito il valore che rappresenta quel nodo (es. nome della città)
    void aggiungiNodo(const T& nodo) {
        if (numeroNodi >= MAX_NODI) {
            std::cout << "Errore: numero massimo di nodi raggiunto.\n";
            return;
        }
        // Verifica che il nodo non sia già presente
        for (int i = 0; i < numeroNodi; ++i) {
            if (esisteNodo[i] && nodi[i] == nodo) {
                std::cout << "Errore: il nodo esiste già.\n";
                return;
            }
        }
        nodi[numeroNodi] = nodo; // Aggiungi il nodo all'array dei nodi
        esisteNodo[numeroNodi] = true; // Marca il nodo come esistente
        numeroNodi++; // Incrementa il numero di nodi
    }

    // Aggiunge un arco tra due nodi dando in input i nomi dei nodi e il peso dell'arco
    void aggiungiArco(const T& sorgente, const T& destinazione, int peso) {
        int indiceSorgente = trovaIndice(sorgente); // Trova l'indice del nodo sorgente
        int indiceDestinazione = trovaIndice(destinazione); // Trova l'indice del nodo destinazione

        if (indiceSorgente == -1 || indiceDestinazione == -1) {
            std::cout << "Errore: uno o entrambi i nodi non esistono.\n";
            return;
        }
        matriceAdiacenza[indiceSorgente][indiceDestinazione] = peso; // Aggiungi l'arco con il peso indicato
    }

    // Rimuove un nodo dando in input il nome del nodo
    void rimuoviNodo(const T& nodo) {
        int indice = trovaIndice(nodo); // Trova l'indice del nodo
        if (indice == -1) {
            std::cout << "Errore: il nodo non esiste.\n";
            return;
        }
        esisteNodo[indice] = false; // Marca il nodo come non esistente
        // Rimuove tutti gli archi che collegano il nodo da rimuovere
        for (int i = 0; i < MAX_NODI; ++i) {
            matriceAdiacenza[indice][i] = INF; // Rimuove l'arco uscenti
            matriceAdiacenza[i][indice] = INF; // Rimuove l'arco entrante
        }
    }

    // Rimuove un arco tra due nodi dando in input il nome del nodo di partenza e del nodo di arrivo
    void rimuoviArco(const T& sorgente, const T& destinazione) {
        int indiceSorgente = trovaIndice(sorgente); // Trova l'indice del nodo sorgente
        int indiceDestinazione = trovaIndice(destinazione); // Trova l'indice del nodo destinazione

        if (indiceSorgente == -1 || indiceDestinazione == -1) {
            std::cout << "Errore: uno o entrambi i nodi non esistono.\n";
            return;
        }
        matriceAdiacenza[indiceSorgente][indiceDestinazione] = INF; // Rimuove l'arco tra i due nodi
    }

    // Restituisce i nodi adiacenti a un dato nodo
    void nodiAdiacenti(const T& nodo) const {
        int indice = trovaIndice(nodo); // Trova l'indice del nodo
        if (indice == -1) {
            std::cout << "Errore: il nodo non esiste.\n";
            return;
        }
        std::cout << "Nodi adiacenti a " << nodo << ": ";
        // Stampa tutti i nodi adiacenti al nodo dato
        for (int i = 0; i < numeroNodi; ++i) {
            if (esisteNodo[i] && matriceAdiacenza[indice][i] != INF) {
                std::cout << nodi[i] << " (peso: " << matriceAdiacenza[indice][i] << ") ";
            }
        }
        std::cout << "\n";
    }

    // Stampa la matrice di adiacenza
    void stampa() const {
        std::cout << "Matrice di Adiacenza:\n";
        // Stampa ogni riga della matrice di adiacenza
        for (int i = 0; i < numeroNodi; ++i) {
            if (!esisteNodo[i]) continue; // Ignora i nodi non esistenti

            for (int j = 0; j < numeroNodi; ++j) {
                if (!esisteNodo[j]) continue; // Ignora i nodi non esistenti

                if (matriceAdiacenza[i][j] == INF) {
                    std::cout << "INF "; // Rappresenta un'assenza di connessione
                } else {
                    std::cout << matriceAdiacenza[i][j] << " "; // Stampa il peso dell'arco
                }
            }
            std::cout << "\n";
        }
    }

    // Verifica se un nodo esiste
    bool verificaNodo(const T& nodo) const {
        return trovaIndice(nodo) != -1; // Se trova l'indice del nodo, significa che esiste
    }

    // Verifica se un arco esiste
    bool verificaArco(const T& sorgente, const T& destinazione) const {
        int indiceSorgente = trovaIndice(sorgente); // Trova l'indice del nodo sorgente
        int indiceDestinazione = trovaIndice(destinazione); // Trova l'indice del nodo destinazione

        if (indiceSorgente == -1 || indiceDestinazione == -1) {
            return false; // Se uno dei nodi non esiste, l'arco non esiste
        }
        return matriceAdiacenza[indiceSorgente][indiceDestinazione] != INF; // Se esiste un arco, il peso sarà diverso da INF
    }
    
private:
    // Trova l'indice di un nodo
    int trovaIndice(const T& nodo) const {
        for (int i = 0; i < numeroNodi; ++i) {
            if (esisteNodo[i] && nodi[i] == nodo) {
                return i; // Restituisce l'indice se il nodo è trovato
            }
        }
        return -1; // Restituisce -1 se il nodo non è trovato
    }
};
