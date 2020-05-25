//Projekt 3
//Eryk Matecki

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <time.h>
#include <cstdlib>
#include <chrono>

using namespace std;


struct ruch
{
public:
    int wiersz;
    int kolumna;
};


class gra
{
    public:

    int rozmiar;                    // rozmiar planszy
    int ilosc_znakow;               // ilosc znakow w linii powodująca wygrana
    char** plansza= NULL;           

    gra(int rzm, int ilosc1)        // konstruktor
    {
        ilosc_znakow = ilosc1;
        rozmiar = rzm;

        plansza = new char *[rzm];          
        for ( int i = 0; i < rzm; ++i )
        {             
            plansza[i] = new char [rzm];        
        }    
    }


    // Funkcja wypisuje aktualną sytuacje na planszy
    void wyswietl_pole()
    {
        cout<<"+";
        for(int r=0; r<rozmiar; r++)
        {
            cout << "-----";
        }
        for(int i=0; i<rozmiar-1; i++)
        {
            cout << "-";
        }
        cout<<"+";

        for (int i = 0; i < rozmiar; i++)
        {
            cout << "\n|";
            for (int j = 0; j < rozmiar; j++)
            {
                cout << std::setw(3) << static_cast<char>(plansza[i][j]) << std::setw(3) << " |";
            }
        }

        cout<<"\n";
        cout<<"+";
        for(int r=0; r<rozmiar; r++)
        {
            cout << "-----";
        }
        for(int i=0; i<rozmiar-1; i++)
        {
            cout << "-";
        }
        cout<<"+";
        cout<<"\n";
    }

    // Funkcja zapełnia plansze znakiem '-' który oznacza wolne pole
    void zapelnij_pole()
    {
        for(int i=0; i<rozmiar; i++)
        {
            for(int j=0; j<rozmiar; j++)
            {
                plansza[i][j] = '-';
            }
        }
    }


    // Funkcja sprawdza czy jest wygrana -> ilosc_znakow to ilosc znakow do wygranej w jednej linii
    char czy_wygrana()
    {
        // licznik liczy ilosć x lub o
        int licznik_x=0;
        int licznik_o=0;
        bool wygrana_x = false;
        bool wygrana_o = false;

        // SPRAWDZENIE POZIOMO

        
        for (int i = 0; i < rozmiar; i++)
        {
            for(int j=0; j<=rozmiar-ilosc_znakow; j++)
            {
                int l=j;
                for(int k=0; k<ilosc_znakow; k++)
                {
                    if(plansza[i][l] == 'x')
                        licznik_x++;

                   // cout<<"Dla pozycji: "<<i<<" , "<<l<<"   ";
                    // cout<<"LICZNIK X: "<<licznik_x<<endl;

                    if(plansza[i][l] == 'o')
                        licznik_o++;
                    l++;
                }
                if(wygrana_o == false)
                {
                    if(licznik_x == ilosc_znakow)
                    {
                        wygrana_x = true;
                    }
                }
                if(wygrana_x == false)
                {
                    if(licznik_o == ilosc_znakow)
                    {
                        wygrana_o = true;
                    }
                }
                licznik_x = 0;
                licznik_o = 0;
            }
        }
        

        // SPRAWDZENIE PIONOWO
        for (int i = 0; i <= rozmiar-ilosc_znakow; i++)
        {
            for(int j=0; j<rozmiar; j++)
            {
                int n=i;
                for(int k=0; k<ilosc_znakow; k++)
                {
                    if(plansza[n][j] == 'x')
                        licznik_x++;

                   //cout<<"Dla pozycji: "<<n<<" , "<<j<<"   ";
                    //cout<<"LICZNIK X: "<<licznik_x<<endl;

                    if(plansza[n][j] == 'o')
                        licznik_o++;
                    n++;
                }
                if(wygrana_o == false)
                {
                    if(licznik_x == ilosc_znakow)
                    {
                        wygrana_x = true;
                    }
                }
                if(wygrana_x == false)
                {
                    if(licznik_o == ilosc_znakow)
                    {
                        wygrana_o = true;
                    }
                }
                licznik_x = 0;
                licznik_o = 0;
            }
        }
        

        //Sprawdzenie na skos
        for (int i = 0; i <= rozmiar-ilosc_znakow; i++)
        {
            for(int j=0; j<=rozmiar - ilosc_znakow; j++)
            {
                int l=i;
                int m=j;

                for(int k=0; k<ilosc_znakow; k++)
                {
                    if(plansza[l][m] == 'x')
                        licznik_x++;

                    if(plansza[l][m] == 'o')
                        licznik_o++;

                    l++;
                    m++;
                }
                if(wygrana_o == false)
                {
                    if(licznik_x == ilosc_znakow)
                    {
                        wygrana_x = true;
                    }
                }
                if(wygrana_x == false)
                {
                    if(licznik_o == ilosc_znakow)
                    {
                        wygrana_o = true;
                    }
                }
                licznik_x = 0;
                licznik_o = 0;
            }
        }
        
        //Sprawdzenie na skos druga strona
        
        for (int i = rozmiar-1; i >= rozmiar-(rozmiar+1-ilosc_znakow); i--)
        {
            for(int j=0; j<=rozmiar - ilosc_znakow; j++)
            {
                int l=i;
                int m=j;

                for(int k=0; k<ilosc_znakow; k++)
                {
                    if(plansza[l][m] == 'x')
                        licznik_x++;

                    if(plansza[l][m] == 'o')
                        licznik_o++;

                    l--;
                    m++;
                }
                if(wygrana_o == false)
                {
                    if(licznik_x == ilosc_znakow)
                    {
                        wygrana_x = true;
                    }
                }
                if(wygrana_x == false)
                {
                    if(licznik_o == ilosc_znakow)
                    {
                        wygrana_o = true;
                    }
                }
                licznik_x = 0;
                licznik_o = 0;
            }
        }
        // WYNIKI OSTATECZNE
        if(wygrana_o == true)
        {
            return 'o';
        }

        if(wygrana_x == true)
        {
            return 'x';
        }

        return '-';     
    }


    // Funkcja sprawdza czy są jakies wolne pola na planszy, jesli tak - gra toczy sie dalej
    bool czy_remis()
    {
        int licznik=0;
        int ilosc_pol = rozmiar*rozmiar;
        for(int i=0; i<rozmiar; i++)
        {
            for(int j=0; j<rozmiar; j++)
            {
                if(plansza[i][j] != '-')
                {
                    licznik++;
                }
            }
        }

        if(licznik == ilosc_pol)
            return true;            // jest remis, poniewaz nie ma juz mozliwosci ruchu
        else
            return false;           // nie ma remisu sa wolne pola
    }

    // Funkcja bierze numer wiersza i kolumny od uzytkownika a nastepnie w podane pole zapisuje znak 'x'
    void ruch_gracza()
    {
        int numer_wiersza;
        int numer_kolumny;
        cout<<"Twoj ruch."<<endl;
       
        cout<<"Wprowadz numer wiersza i kolumny gdzie chcesz postawić krzyzyk: ";
        cin>>numer_wiersza;
        cin>>numer_kolumny;
        if(plansza[numer_wiersza-1][numer_kolumny-1] == '-')
        {
            plansza[numer_wiersza-1][numer_kolumny-1] = 'x';
        }

        while(plansza[numer_wiersza-1][numer_kolumny-1] == 'o')
        {
            cout<<"To miejsce jest juz zajete"<<endl;
            cout<<"Wprowadz jeszcze raz numer wiersza i kolumny gdzie chcesz postawić krzyzyk: ";
            cin>>numer_wiersza;
            cin>>numer_kolumny;
            if(plansza[numer_wiersza-1][numer_kolumny-1] == '-')
            {
                plansza[numer_wiersza-1][numer_kolumny-1] = 'x';
            }   
        }
    }



////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Funkcja przypisuje ruch komputera we wskazane pole
    void ruch_komputera()
    {

        
       
        
        cout<<"Ruch komputera: "<<endl;

        int glebokosc=3;
        
        if(rozmiar <=3)
        {
            glebokosc = 9;      // nie bedzie opoznienia gry
        }

        ruch ruch = minimax(glebokosc,-1000, 1000);
        plansza[ruch.wiersz][ruch.kolumna] = 'o';
        


          
    }


////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Minimax 

    ruch minimax(int glebokosc, int alfa, int beta) 
    {
        int wynik = std::numeric_limits<int>::max();
        ruch ruch;

        for (int i = 0; i < rozmiar; i++)
        {
            for (int j = 0; j < rozmiar; j++)
            {
                if (plansza[i][j] == '-')
                {
                    plansza[i][j] = 'o';

                    int tymczasowy = szukaj_max(glebokosc-1, alfa, beta);

                    if (tymczasowy < wynik)
                    {
                        wynik = tymczasowy;
                        ruch.wiersz = i;
                        ruch.kolumna = j;
                    }
                    plansza[i][j] = '-';        // cofniecie ruchu symulacji rozgrywki
                }
            }
        }
        return ruch;
    }

    // Gracz maksymalizujacy zyski 

    int szukaj_max(int glebokosc, int alfa, int beta) 
    {
        if (czy_wygrana() == 'x') { return 10; }
        else if (czy_wygrana() == 'o') { return -10; }
        else if (czy_remis()==true) { return 0; }
        else if (glebokosc == 0) { return 0; }

        int wynik = std::numeric_limits<int>::min();

        for (int i = 0; i < rozmiar; i++)
        {
            for (int j = 0; j < rozmiar; j++)
            {
                if (plansza[i][j] == '-')
                {
                    plansza[i][j] = 'x';
                    wynik = max(wynik, szukaj_min(glebokosc-1, alfa, beta));
                    plansza[i][j] = '-';

                    int alfa = max(alfa, wynik);
                    if(beta<=alfa)
                    {
                        break;
                    }
                    plansza[i][j] = '-';        // cofniecie ruchu symulacji rozgrywki
                }
            }
        }

        return wynik;
    }

    // Gracz minimalizujacy
    int szukaj_min(int glebokosc, int alfa, int beta)
    {
        if (czy_wygrana() == 'x') { return 10; }
        else if (czy_wygrana() == 'o') { return -10; }
        else if (czy_remis()==true) { return 0; }
        else if (glebokosc == 0) { return 0; }

        int wynik = std::numeric_limits<int>::max();

        for (int i = 0; i < rozmiar; i++)
        {
            for (int j = 0; j < rozmiar; j++)
            {
                if (plansza[i][j] == '-')
                {
                    plansza[i][j] = 'o';
                    wynik = std::min(wynik, szukaj_max(glebokosc-1, alfa, beta));
                    plansza[i][j] = '-';

                    int beta = std::min(beta, wynik);
                    if(beta<=alfa)
                    {
                        break;
                    }
                }
            }
        }
        return wynik;
    }


/////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // funkcja losuje kto zaczyna rozgrywke
    char losowanie()
    {

        int liczba = rand() % 2;

        char rozpoczynajacy;
        if(liczba != 0)
        {
            cout<<"Rozpoczyna gracz."<<endl;
            rozpoczynajacy = 'x';
        } 
        else
        {
            cout<<"Rozpoczyna komputer."<<endl;
            rozpoczynajacy = 'o';
        }
        return rozpoczynajacy;
    }


    // Funkcja w ktorej wywolują sie inne funkcje odpowiedzialne za przebieg rozgrywki
    void rozgywka()
    {
        bool wyjdz = false;

        zapelnij_pole();                    // tworzenie pustej planszy
        
        cout<<"Rozpoczynamy gre."<<endl;

        char x = losowanie();               // losowanie gracza rozpoczynajcego


        do
        {
            if(x=='x')                      // schemat gdy zaczyna uzytkownik
            {
                wyswietl_pole();
                ruch_gracza();
                if(czy_wygrana()=='x')           // jesli wygrał 'x' to koniec gry - wyjscie z pętli    
                {
                    wyjdz = true;
                    break;
                }
                if(czy_remis()==true)
                {
                    wyjdz = true;
                    break;
                }
                wyswietl_pole();
                ruch_komputera();                               

                if(czy_wygrana() == 'o')           // jesli wygrał 'o' to koniec gry - wyjscie z pętli  
                {
                    wyjdz = true;
                    break;
                }
                if(czy_remis()==true)               // jesli remis to koniec gry - wyjscie z pętli  
                {
                    wyjdz = true;
                    break;
                }
            }

            if(x=='o')                          // schemat gdy zaczyna komputer
            {
                wyswietl_pole();
                ruch_komputera();                                                            

                if(czy_wygrana() == 'o')        
                {
                    wyjdz = true;
                    break;
                }
                if(czy_remis()==true)
                {
                    wyjdz = true;
                    break;
                }
                wyswietl_pole();
                ruch_gracza();
                if(czy_wygrana() == 'x')
                {
                    wyjdz = true;
                    break;
                }
                if(czy_remis()==true)
                {
                    wyjdz = true;
                    break;
                }
            }

        }   while(!wyjdz);

        wyswietl_pole();

        if(czy_wygrana() == 'x')
        {
            cout<<endl<<"KONIEC GRY. Wygrales!!"<<endl;
        }
        if(czy_wygrana() == 'o')
        {
            cout<<endl<<"KONIEC GRY. Przegrales!!"<<endl;
        }
        if(czy_wygrana() == '-')
        {
            cout<<endl<<"KONIEC GRY. Padł remis!!"<<endl;
        }
    }
};





int main()
{
    int rozmiar1;
    int ilosc_znakow1;
    srand( time( 0 ) );

    cout<<"Proszę wprowadzić rozmiar planszy na jakiej chcesz grać."<<endl<<"Rozmiar: ";
    cin>>rozmiar1;
    cout<<endl<<"Proszę wprowadzić ile znaków w jednej linii daje zwycięstwo."<<endl<<"Ilość znaków: ";
    cin>>ilosc_znakow1;

    while(ilosc_znakow1 > rozmiar1 || ilosc_znakow1 <= 1)
    {
        if(ilosc_znakow1 > rozmiar1)
        {
        cout<<endl<<"*** Wprowadzona ilosc znaków jest wieksza od rozmiaru planszy ***"<<endl;
        }

        if(ilosc_znakow1 <= 1)
        {
        cout<<endl<<"*** Ilosc znaków powinna być większa lub równa 2 ***"<<endl;
        }
        cout<<"Proszę jeszcze raz wprowadzić ile znaków w jednej linii daje zwycięstwo."<<endl<<"Ilość znaków: ";
        cin>>ilosc_znakow1;
    }

    gra gra(rozmiar1, ilosc_znakow1);            // konstruktor -> przypisanie wczytanych wartosci do pól klasy oraz stowrzenie planszy o podanym rozmiarze


    gra.rozgywka();


}

