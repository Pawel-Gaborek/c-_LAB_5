//
//////////////////////////////////////////////////////////////
//  Pawel Gaborek                                           //
//  Programowanie C++                                       //
//  Semestr 3, rok 2, album nr: 45093                       //
//  Prowadzacy, Pan dr inż. Piotr Błaszyński                //
//  LABOLATORIUM_NR-5.cpp                                   //
//  LABOLATORIUM_NR-5                                       //
//                                                          //
//  Created by Paweł Gaborek on 15/04/2019.                 //
//  Copyright © 2019 Paweł Gaborek. All rights reserved.    //
//////////////////////////////////////////////////////////////

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdlib>
#include <ctime>


using namespace std;
//ponizej przedmiot jako klasa bazowa
class przedmiot
{
public:
    string nazwa;
    int wartosc;
    //ponizej jest konstruktor bazowy dla przedmiot
    przedmiot (){};
    
    przedmiot (string _nazwa, int _wartosc)
    {
        this -> nazwa = _nazwa;
        this -> wartosc = _wartosc;
    }
private:
protected:
};

//ponizej opis jako klasa pochodna
class opis
{
    przedmiot _przedmiot;
    string opis_pomieszczenia;
    float wsp_x;
    float wsp_y;
    opis *wsk_zach;
    opis *wsk_wsch;
    opis *wsk_pn;
    opis *wsk_pld;
    
public:
    
    //ponizej jest konstruktor bazowy dla opis
    opis(): _przedmiot(){};
    
    void pobranie_opisu(string O_OPIS, int O_WSPOLRZEDNE_X, int O_WSPOLRZEDNE_Y)
    {
        opis_pomieszczenia=O_OPIS;
        wsp_x=O_WSPOLRZEDNE_X;
        wsp_y=O_WSPOLRZEDNE_Y;
    }
    
    void pn_wsk(opis **&tablica_pomieszczen, int i_wiersze, int j_kolumny)
    {
        if (i_wiersze==0)
        {
            opis *wsk;
            wsk=&tablica_pomieszczen[2][j_kolumny];
            wsk_pn=wsk;
            cout << wsk_pn << "\n";
        }
        else
        {
            opis *wsk;
            wsk=&tablica_pomieszczen[i_wiersze-1][j_kolumny];
            wsk_pn=wsk;
            cout << wsk_pn << "\n";
        }
        
    }
    
    void wsch_wsk(opis **&tablica_pomieszczen, int i_wiersze, int j_kolumny)
    {
        if (j_kolumny==0)
        {
            opis *wsk;
            wsk=&tablica_pomieszczen[i_wiersze][5];
            wsk_wsch=wsk;
            cout << wsk_wsch << "\n";
        }
        else
        {
            opis *wsk;
            wsk=&tablica_pomieszczen[i_wiersze][j_kolumny-1];
            wsk_wsch=wsk;
            cout << wsk_wsch << "\n";
        }
    }
    
    void pd_wsk(opis **&tablica_pomieszczen, int i_wiersze, int j_kolumny)
    {
        if (i_wiersze==2)
        {
            opis *wsk;
            wsk=&tablica_pomieszczen[0][j_kolumny];
            wsk_pld=wsk;
            cout << wsk_pld << "\n";
        }
        else
        {
            opis *wsk;
            wsk=&tablica_pomieszczen[i_wiersze+1][j_kolumny];
            wsk_pld=wsk;
            cout << wsk_pld << "\n";
        }
    }
    
    void zach_wsk(opis **&tablica_pomieszczen, int i_wiersze, int j_kolumny)
    {
        if (j_kolumny==5)
        {
            opis *wsk;
            wsk=&tablica_pomieszczen[i_wiersze][0];
            wsk_zach=wsk;
            cout << wsk_zach << "\n";
        }
        else
        {
            opis *wsk;
            wsk=&tablica_pomieszczen[i_wiersze][j_kolumny+1];
            wsk_zach=wsk;
            cout << wsk_zach << "\n";
        }
    }
    
    void wskaznik_sciany(opis **&tablica_pomieszczen, int i_wiersze, int j_kolumny)
    {
        if (j_kolumny==0)
        {
            wsk_zach=0;
            tablica_pomieszczen[i_wiersze][5].wsk_wsch=0;
        }
        else
        {
            wsk_zach=0;
            tablica_pomieszczen[i_wiersze][j_kolumny-1].wsk_wsch=0;
        }
    }
    
    
    
    void get() const
    {
        cout << "Pomieszczenie nr: " << opis_pomieszczenia << "\n";
        cout << "Wspolrzedna x: " << wsp_x << "\n";
        cout << "Wspolrzedna y: " << wsp_y << "\n";
    }
    
    void get_wskazniki() const
    {
        cout << "\n";
        
        cout << "Wskaznik pomieszczenia nr: " << opis_pomieszczenia << "\n";
        {
            if (wsk_pn == 0x0)
            {
                cout << "Wskaznik polnoc: sciana" <<"\n";
            }
            else
            {
                cout << "Wskaznik polnoc: " << wsk_pn << "\n";
            }
        }
        {
            if (wsk_pld == 0x0)
            {
                cout << "Wskaznik poludnie: sciana" <<"\n";
            }
            else
            {
                cout << "Wskaznik poludnie: " << wsk_pld << "\n";
            }
        }
        {
            if (wsk_wsch == 0x0)
            {
                cout << "Wskaznik wschod: sciana" <<"\n";
            }
            else
            {
                cout << "Wskaznik wschod: " << wsk_wsch << "\n";
            }
        }
        {
            if (wsk_zach == 0x0)
            {
                cout << "Wskaznik zachod: sciana" <<"\n";
            }
            else
            {
                cout << "Wskaznik zachod: " << wsk_zach << "\n";
            }
        }
        cout << "\n";
    }
    
    void get_sciany_jak_w_zadaniu() const
    {
        if (wsk_wsch == 0x0)
        {
            cout << "X";
        }
    }
    
    void alokuj_pamiec()
    {
        
    }
    
    void get_przedmiot(opis **&tablica_pomieszczen, przedmiot przedmiot_temp, int y, int x)
    {
        tablica_pomieszczen[y][x]._przedmiot=przedmiot_temp;
    }
    
    void get_przedmiot_print() const
    {
        cout << "Nazwa przedmiotu:  " << _przedmiot.nazwa << " oraz wartosc: " << _przedmiot.wartosc << "\n";
    }
    
    void get_przedmioty_jak_w_zadaniu() const
    {
        if ((_przedmiot.nazwa).empty())
        {
            cout << "#";
        }
        else
        {
            cout << _przedmiot.nazwa[0];
        }
    }
    
    
    
    void get_przedmioty_wedlug_sciezki() const
    {
        if ((_przedmiot.nazwa).empty())
        {
            cout << "#";
        }
        else
        {
            cout << _przedmiot.nazwa[0];
        }
    }
    
    void get_krok_przedmiot(int krok) const
    {
        if (!(_przedmiot.nazwa).empty())
        {
            cout << "W kroku numer: " << krok << " jest przedmiot: " <<_przedmiot.nazwa << "\n";
        }
    }
    
    
    
private:
protected:
};

////////////////////////////////////////////////////////////////////////////////////////////////
////--------------------------stworznie macierzy obiektow-----------------------------------////

void alokuj_pamiec(opis **&tablica_pomieszczen)
{
    tablica_pomieszczen = new opis*[3];
    for (int i=0 ; i<3 ; i++)
    {
        tablica_pomieszczen[i] = new opis [6];
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
////-------------------------pobranie, inicjalizacja  obiektow------------------------------////

void inicjalizuj_obiekty(opis **&tablica_pomieszczen)
{
    int objekt_numer=0;
    string opis_pomieszczenia;
    for (int ii =0 ; ii<3 ; ii++)
    {
        for (int j =0; j<6 ; j++)
        {
            objekt_numer=1+objekt_numer;
            opis_pomieszczenia=to_string(objekt_numer);
            tablica_pomieszczen[ii][j].pobranie_opisu(opis_pomieszczenia, ii, j);
        }
    }
    
    
    int objekt=0;
    
    for (int iil =0 ; iil<3 ; iil++)
    {
        for (int jl =0; jl<6 ; jl++)
        {
            objekt=1+objekt;
            cout << "Adres obiektu nr: " << objekt << " to: " <<&tablica_pomieszczen[iil][jl] << "\n";
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
////-------------------------wyswietlanie zawartosci obiektow-------------------------------////

void pokaz_obiekty(opis **&tablica_pomieszczen)
{
    for (int im =0; im<3 ; im++)
    {
        for (int jm =0; jm<6 ; jm++)
        {
            tablica_pomieszczen[im][jm].get();
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
////------------------------------------wskaznik polnoc-------------------------------------////

void wskaznik_polnoc(opis **&tablica_pomieszczen)
{
    for (int im =0; im<3 ; im++)
    {
        for (int jm =0; jm<6 ; jm++)
        {
            tablica_pomieszczen[im][jm].pn_wsk(tablica_pomieszczen, im, jm);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
////-----------------------------------wskaznik poludnie------------------------------------////

void wskaznik_poludnie(opis **&tablica_pomieszczen)
{
    for (int im =0; im<3 ; im++)
    {
        for (int jm =0; jm<6 ; jm++)
        {
            tablica_pomieszczen[im][jm].pd_wsk(tablica_pomieszczen, im, jm);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
////------------------------------------wskaznik wschod-------------------------------------////

void wskaznik_wschod(opis **&tablica_pomieszczen)
{
    for (int im =0; im<3 ; im++)
    {
        for (int jm =0; jm<6 ; jm++)
        {
            tablica_pomieszczen[im][jm].zach_wsk(tablica_pomieszczen, im, jm);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
////------------------------------------wskaznik zachod-------------------------------------////

void wskaznik_zachod(opis **&tablica_pomieszczen)
{
    for (int im =0; im<3 ; im++)
    {
        for (int jm =0; jm<6 ; jm++)
        {
            tablica_pomieszczen[im][jm].wsch_wsk(tablica_pomieszczen, im, jm);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
////------------------------------------wskaznik sciany-------------------------------------////

void wskaznik_do_scian(opis **&tablica_pomieszczen, int i, int j)
{
    tablica_pomieszczen[i][j].wskaznik_sciany(tablica_pomieszczen, i, j);
}

////////////////////////////////////////////////////////////////////////////////////////////////
////---------------wyswietlanie zawartosci wskaznikow po modyfikacji------------------------////

void pokaz_wskazniki(opis **&tablica_pomieszczen)
{
    for (int im =0; im<3 ; im++)
    {
        for (int jm =0; jm<6 ; jm++)
        {
            tablica_pomieszczen[im][jm].get_wskazniki();
        }
    }
    
}

////////////////////////////////////////////////////////////////////////////////////////////////
////-------------------wyswietlanie pomieszczenia jak w zadaniu-----------------------------////

void pokaz_pomieszczenia_jak_w_zadaniu(opis **&tablica_pomieszczen)
{
    for (int im =0; im<3 ; im++)
    {
        for (int jm =0; jm<6 ; jm++)
        {
            cout << "#";
            tablica_pomieszczen[im][jm].get_sciany_jak_w_zadaniu();
        }
        cout << "\n";
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
////--------------------------------kasowanie pamieci---------------------------------------////

void kasuj_pamiec(opis **&tablica_pomieszczen)
{
    for (int il =0; il<3 ; il++)
    {
        delete []tablica_pomieszczen[il];
    }
    delete []tablica_pomieszczen;
    tablica_pomieszczen = nullptr ;
}

////////////////////////////////////////////////////////////////////////////////////////////////
////----------------------------przydzielanie przedmiotu------------------------------------////


void przydziel_przedmiot(opis **&tablica_pomieszczen, przedmiot przedmiot_temp)
{
    int kolumny_max=5;
    int kolumny_min=0;
    int wiersze_max=2;
    int wiersze_min=0;
    int wspolrzedna_x;
    int wspolrzedna_y;
    
    
    
    //srand(time(NULL));
    
    wspolrzedna_x=rand() % (kolumny_min - kolumny_max);
    wspolrzedna_y=rand() % (wiersze_min - wiersze_max);
    tablica_pomieszczen[wspolrzedna_y][wspolrzedna_x].get_przedmiot(tablica_pomieszczen, przedmiot_temp, wspolrzedna_y, wspolrzedna_x);
}

////////////////////////////////////////////////////////////////////////////////////////////////
////----------------------------wyswietlanie przedmiotow------------------------------------////

void pokaz_przedmioty(opis **&tablica_pomieszczen)
{
    for (int i=0 ; i<3 ; i++)
    {
        for (int j=0; j<6 ; j++)
        {
            tablica_pomieszczen[i][j].get_przedmiot_print();
        }
        cout << "\n";
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
////---------------------wyswietlanie przedmiotow jak w zadaniu-----------------------------////

void pokaz_przedmioty_jak_w_zadaniu(opis **&tablica_pomieszczen)
{
    for (int im =0; im<3 ; im++)
    {
        for (int jm =0; jm<6 ; jm++)
        {
            tablica_pomieszczen[im][jm].get_przedmioty_jak_w_zadaniu();
        }
        cout << "\n";
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////
////-----------------------------------zliczanie krokow-------------------------------------////



void przedmiot_krok(opis **&tablica_pomieszczen, int krok, int x, int y)
{
    tablica_pomieszczen[x][y].get_krok_przedmiot(krok);
}


void zliczanie_krokow(opis **&tablica_pomieszczen, char *str)
{
    int kroki_ogolne=0;
    int kroki_przedmiotow=0;
    int kolumny=0;
    int wiersze=0;
    
    przedmiot_krok(tablica_pomieszczen, kroki_ogolne, wiersze, kolumny);
    
    for(int j=0; str[j]!='\0' ; j++)
    {
        kroki_ogolne=j+1;
        if (str[j]=='n')
        {
            
            
            wiersze=wiersze-1;
            {
                if(wiersze<0)
                {
                    wiersze=2;
                }
            }
            przedmiot_krok(tablica_pomieszczen, kroki_ogolne, wiersze, kolumny);
            //cout << "Krok: " << str[j] << " numer: " << kroki_ogolne << "\n";
        }
        else if (str[j]=='s')
        {
            wiersze=wiersze+1;
            {
                if(wiersze>2)
                {
                    wiersze=0;
                }
            }
            przedmiot_krok(tablica_pomieszczen, kroki_ogolne, wiersze, kolumny);
            //cout << "Krok: " << str[j] << " numer: " << kroki_ogolne << "\n";
        }
        else if (str[j]=='e')
        {
            kolumny=kolumny+1;
            {
                if (kolumny>5)
                {
                    kolumny=0;
                }
            }
            przedmiot_krok(tablica_pomieszczen, kroki_ogolne, wiersze, kolumny);
            //cout << "Krok: " << str[j] << " numer: " << kroki_ogolne << "\n";
        }
        else if (str[j]=='w')
        {
            kolumny=kolumny-1;
            {
                if (kolumny<0)
                {
                    kolumny=5;
                }
            }
            przedmiot_krok(tablica_pomieszczen, kroki_ogolne, wiersze, kolumny);
            //cout << "Krok: " << str[j] << " numer: " << kroki_ogolne << "\n";
        }
    }
    cout << "Liczba krokow ogolnych wynosi: " << kroki_ogolne << "\n";
}


int main()
{
    
    opis** tablica;
    alokuj_pamiec(tablica);
    inicjalizuj_obiekty(tablica);
    pokaz_obiekty(tablica);
    cout << "Wskaznik polnoc:\n";
    wskaznik_polnoc(tablica);
    cout << "\n\n\n\n\n\n";
    cout << "Wskaznik poludnie:\n";
    wskaznik_poludnie(tablica);
    cout << "\n\n\n\n\n\n";
    cout << "Wskaznik wschod:\n";
    wskaznik_wschod(tablica);
    cout << "\n\n\n\n\n\n";
    cout << "Wskaznik zachod:\n";
    wskaznik_zachod(tablica);
    cout << "\n\n\n\n\n\n";
    cout << "Wskaznik, sciany:\n";
    wskaznik_do_scian(tablica, 0, 2);
    wskaznik_do_scian(tablica, 0, 3);
    wskaznik_do_scian(tablica, 1, 0);
    wskaznik_do_scian(tablica, 1, 5);
    wskaznik_do_scian(tablica, 2, 2);
    wskaznik_do_scian(tablica, 2, 3);
    cout << "\n\n\n\n\n\n";
    pokaz_wskazniki(tablica);
    cout << "\n\n\n\n\n\n";
    cout << "Wyswietlenie pomieszczen jak w zadaniu: \n";
    pokaz_pomieszczenia_jak_w_zadaniu(tablica);
    
    przedmiot obiekt_1("latarka", 14);
    przedmiot obiekt_2("suszartka", 50);
    przedmiot obiekt_3("kompas", 40);
    cout << "\n\n\n\n\n\n";
    przydziel_przedmiot(tablica, obiekt_1);
    przydziel_przedmiot(tablica, obiekt_2);
    przydziel_przedmiot(tablica, obiekt_3);
    pokaz_przedmioty(tablica);
    
    cout << "Wyswietlenie przedmiotow jak w zadaniu: \n";
    pokaz_przedmioty_jak_w_zadaniu(tablica);
    
    cout << "Wyswietlenie przedmiotow jak w zadaniu: \n";
    char tablica_znakow[100];
    tablica_znakow[0]='e';
    tablica_znakow[1]='s';
    tablica_znakow[2]='s';
    tablica_znakow[3]='w';
    tablica_znakow[4]='e';
    tablica_znakow[5]='n';
    tablica_znakow[6]='e';
    tablica_znakow[7]='e';
    tablica_znakow[8]='s';
    tablica_znakow[9]='n';
    tablica_znakow[10]='n';
    tablica_znakow[11]='s';
    tablica_znakow[12]='e';
    tablica_znakow[13]='e';
    tablica_znakow[14]='n';
    tablica_znakow[15]='e';
    tablica_znakow[16]='e';
    tablica_znakow[17]='w';
    tablica_znakow[18]='w';
    tablica_znakow[19]='s';
    tablica_znakow[20]='s';
    tablica_znakow[21]='e';
    tablica_znakow[22]='e';
    tablica_znakow[23]='\0';
    
    zliczanie_krokow(tablica, tablica_znakow);
    
    
    
    kasuj_pamiec(tablica);
    
    
    
    if (tablica == nullptr)
        cout << "Pamiec pomyslnie skasowana.\n";
};
