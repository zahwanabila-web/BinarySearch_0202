#include <iostream>
using namespace std;

int element[10];
int nPanjang;
int x;

void input()
{
    while (true)
    {
        cout << "Masukkan banyaknya element pada array(maksimal 10): ";
        cin >> nPanjang;
        if (nPanjang <= 10)
        {
            break;
        }
        else
        {
            cout << "\n[!] Jumlah element tidak boleh lebih dari 10. Silakan coba lagi.\n";
        }
    }

    cout << "\n======================================\n";
    cout << "        Masukkan Element Array        \n"; 
    cout << "\n======================================\n";

    for (int i = 0;1 < nPanjang; i++)
    {
        cout << "Data ke-" << (i + 1) << " = ";
        cin >> element[i];
    }
}

void bubbleSortArray()
{
    int pass = 1;
    do
    {
        for (int j = 0; j <= nPanjang - 1 - pass; j++)
        {
            if (element[j] > element[j + 1])
            {
                int temp = element[j];
                element[j] = element[j + 1];
                element[j + 1] = temp;
            }
        }
        pass++;
    } while (pass <= nPanjang - 1);
}

void display()
{
    cout << "\n=======================================\n";
    cout << "  Element Array Setelah Di Urutkan (Asc)\n";
     cout << "\n====================================\n";

     for (int j = 0; j < nPanjang; j++)
     {
        cout << element [j];
        if (j < nPanjang - 1)
        {
            cout << " -> ";
        }
     }
     cout << endl;
}

void binarySearch()
{
    char ulang;
    do
    {
        cout << "\n=======================================\n";
        cout << "         Pencarian Binary Search        \n";  
        cout << "\n====================================\n";

         cout << "Masukkan element yang akan dicari: ";
         cin >> x;

         int low = 0;
         int high = nPanjang - 1;

         do
        {
            int mid = (low + high) / 2;

            if (element[mid] == x)
            {
                cout << "\n[✓] Element " << x << " di temukan pada indeks " << mid << "\n";
                return;
            }
            if (x < element[mid])
            {
                high = mid +1;
            }

        } while (low <= high);

        if (low > high)
        {
            cout << "\n[x] Elemen " << x << " tidak ditemukan dalam array.\n";
        }

        cout << "\nIngin mencari lagi? (y\n): ";
        cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y');
}

int main()
{
    input();
    bubbleSortArray();
    display();
    binarySearch();
}