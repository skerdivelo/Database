#include <iostream>
#include <fstream>

using namespace std;

#define DIM 1000


struct anagrafe
{
    string nome;
    string cognome;
    string data;
    string citta;
    string telefono;
    string email;
    string password;
};


void inserisci(anagrafe a[], int dim, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "Inserisci nome: ";
        cin >> a[i].nome;
        cout << "Inserisci cognome: ";
        cin >> a[i].cognome;
        cout << "Inserisci data di nascita: ";
        cin >> a[i].data;
        cout << "Inserisci citta': ";
        cin >> a[i].citta;
        cout << "Inserisci telefono: ";
        cin >> a[i].telefono;
        cout << "Inserisci email: ";
        cin >> a[i].email;
    }
}

void nomeCognome(anagrafe a[], int dim, int n)
{
    for(int i = 0; i < n; i++)
    {
        a[i].nome[0] = toupper(a[i].nome[0]);
        for(int j = 1; j < a[i].nome.length(); j++)
        {
            a[i].nome[j] = tolower(a[i].nome[j]);
        }
        a[i].cognome[0] = toupper(a[i].cognome[0]);
        for(int j = 1; j < a[i].cognome.length(); j++)
        {
            a[i].cognome[j] = tolower(a[i].cognome[j]);
        }
        a[i].citta[0] = toupper(a[i].citta[0]);
        for(int j = 1; j < a[i].citta.length(); j++)
        {
            a[i].citta[j] = tolower(a[i].citta[j]);
        }
    }
}
void ordina(anagrafe a[], int dim, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i].cognome < a[j].cognome)
            {
                anagrafe temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}


void scriviFile(anagrafe a[], int dim, int n)
{
    ofstream file;
    file.open("/Users/skerdi/CLionProjects/DataBaseco/anagrafe.txt");
    for(int i = 0; i < n; i++)
    {
        file << i+1 << endl <<"-----------------------------" << endl;
        file << a[i].nome << endl;
        file << a[i].cognome << endl;
        file << a[i].data << endl;
        file << a[i].citta << endl;
        file << a[i].telefono << endl;
        file << a[i].email << endl;
    }
    file.close();
}

bool verifica(string s)
{
    if(s == "secret")
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    anagrafe a[DIM];
    int n,numeroUscita;
    cout << "Inserisci quante persone vuoi inserire: ";
    cin >> n;
    inserisci(a, DIM, n);
    nomeCognome(a, DIM, n);
    ordina(a, DIM, n);
    scriviFile(a, DIM, n);
    string s;
    cout << "Inserisci la password: ";
    cin >> s;
    if(verifica(s))
    {
        cout << "Password corretta" << endl;
    }
    else
    {
        cout << "Password errata" << endl;
    }
    do{
        cout << "Cosa vuoi fare: " << endl;
        cout << "1. Visualizza tutti i dati" << endl;
        cout << "2. Visualizza i dati di una persona" << endl;
        cout << "3. Modifica i dati di una persona" << endl;
        cout << "4. Cancella i dati di una persona" << endl;
        cout << "99. Esci" << endl;
        cin >> numeroUscita;
        if(numeroUscita == 1)
        {
            for(int i = 0; i < n; i++)
            {
                cout << "-----------------------------" << endl;
                cout << "Nome: " << a[i].nome << endl;
                cout << "Cognome: " << a[i].cognome << endl;
                cout << "Data di nascita: " << a[i].data << endl;
                cout << "Citta': " << a[i].citta << endl;
                cout << "Telefono: " << a[i].telefono << endl;
                cout << "Email: " << a[i].email << endl;
            }
        }
        else if(numeroUscita == 2)
        {
            int numero;
            cout << "Inserisci il numero della persona: ";
            cin >> numero;
            cout << "-----------------------------" << endl;
            cout << "Nome: " << a[numero-1].nome << endl;
            cout << "Cognome: " << a[numero-1].cognome << endl;
            cout << "Data di nascita: " << a[numero-1].data << endl;
            cout << "Citta': " << a[numero-1].citta << endl;
            cout << "Telefono: " << a[numero-1].telefono << endl;
            cout << "Email: " << a[numero-1].email << endl;
        }
        else if(numeroUscita == 3)
        {
            int numero;
            cout << "Inserisci il numero della persona: ";
            cin >> numero;
            cout << "-----------------------------" << endl;
            cout << "Nome: " << a[numero-1].nome << endl;
            cout << "Cognome: " << a[numero-1].cognome << endl;
            cout << "Data di nascita: ";
            cin >> a[numero-1].data;
            cout << "Citta': ";
            cin >> a[numero-1].citta;
            cout << "Telefono: ";
            cin >> a[numero-1].telefono;
            cout << "Email: ";
            cin >> a[numero-1].email;
        }
    }while(numeroUscita!=99);
    scriviFile(a, DIM, n);
    system("cp /Users/skerdi/CLionProjects/DataBaseco/anagrafe.txt /Users/skerdi/CLionProjects/DataBaseco/anagrafe.txt.bak");
}
