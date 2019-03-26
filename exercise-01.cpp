/*
Nama        : Falah Rizqi Abudllah Fairuz
NPM         : 140810180069
Deskripsi   : Double linked list
Kelas       : A
Tanggal     : 26 Maret 2019
*/

#include <iostream>
using namespace std;

struct pembalap
{
    int nomor;
    char nama;
    int waktu;
    pembalap* next;
    pembalap* prev;
};

// typedef pembalap* pointer;
// typedef pointer list;

void createNode (pembalap* &p, int nomor, char nama)
{
    p = new pembalap;
    cout << "Nomor  : "; cin >> p->nomor;
    cout << "Nama   : "; cin >> p->nama;
    cout << "Waktu  : "; cin >> p->waktu;
    p->next = NULL;
    p->prev = NULL;
}

void insertFirst (pembalap* &head, pembalap* node)
{
    cout << "Insert first : " << endl;
    if (head == NULL)
    {
        head = node;
    }

    else
    {
        node->next = head;
        head->prev = node;
        head = node;
    }
}

void insertBefore (pembalap* &head, int nomorKey, pembalap* node)
{
    pembalap* searching;
    search(head,nomorKey,searching);
    if (head == NULL)
    {
        head = node;
    }
    else
    {
        node->next = searching;
        node->prev = searching->prev;
        searching->prev->next = node;
        searching->prev = node;   
    }
}

void deleteByKey (pembalap* &head, int nomorKey, pembalap* &deletedNode)
{
    
}

void search (pembalap* &firstNode, int nomorKey, pembalap* &pToUpdate)
{
    pToUpdate = firstNode;
    while(pToUpdate->nomor != nomorKey)
    {
        pToUpdate = pToUpdate->next;
    }
}

void traversal (pembalap* head)
{
    pembalap* pBantu;

    if (head == NULL)
    {
        cout << "List kosong" << endl;
    }

    else
    {
        pBantu = head;
        do
        {
            cout << "Nomor  : " << pBantu->nomor;
            cout << "Nama   : " << pBantu->nama;
            cout << "Waktu  : " << pBantu->waktu;
            pBantu = pBantu->next;
        } while (pBantu != NULL);
        
    }
}

void sortingByNomor (pembalap* &head)
{

}

void update (pembalap* firstNode, int nomorKey)
{

}

int main ()
{
    pembalap* head = NULL;
    pembalap* pBaru = NULL;
    pembalap* pToUpdate = NULL;
    char nama = 'a';

    for (int i = 0; i<4; i++)
    {
        createNode (pBaru, i+1, nama++);
        insertFirst (head, pBaru);
    }

    cout << "\n>>> List" << endl;
    traversal (head);

    int keyNomor = 2;

    cout << "\n>>> Insert Before nomor " << keyNomor << endl;
    createNode(pBaru, 99, 'z');
    insertBefore(head, keyNomor, pBaru);
    traversal(head);

    cout << "\n>>> SortingByNomor" << endl;
    sortingByNomor(head);
    traversal(head);

    keyNomor = 3;
    cout << "\n>>> Delete nomor " << keyNomor << endl;
    pembalap* pHapus = NULL;
    deleteByKey(head, keyNomor, pHapus);
    traversal(head);

    keyNomor = 4;

    cout << "\n>>> Undate nomor " << keyNomor << endl;
    update(head, keyNomor);

    cout << "\n>>> Update list" << endl;
    traversal(head);
}