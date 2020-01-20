#include <cstdlib>
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <random>
#include<string>
using namespace std;
VOID WINAPI Sleep(DWORD dwMilliseconds);

int kolo1 = 1; //50/50
int kolo2 = 1; //POMOC PUBLICZNOSCI
int kolo3 = 1; // TELEFON DO PRZYJACIELA
char poprawna;
char poprawna2;



//FUNKCJA WYWO£UJ¥CA KO£A RATUNKOWE
void kolo_ratunkowe(int &kolo1, int &kolo2, int &kolo3)
{
	
	int kolo=0;
	cout << "Wpisz numer wybranego kola ratunkowego (1,2 lub 3): ";
	cin >> kolo;

	if (kolo == 1)
	{
		kolo1 = 0;
		if (poprawna == 'A')
			cout << endl << "Odpowiedzi B i D sa niepoprawne" << endl << endl;
		if (poprawna == 'B')
			cout << endl << "Odpowiedzi A i D sa niepoprawne" << endl << endl;
		if (poprawna == 'C')
			cout << endl << "Odpowiedzi A i B sa niepoprawne" << endl << endl;
		if (poprawna == 'D')
			cout << endl << "Odpowiedzi B i C sa niepoprawne" << endl << endl;
		
		
	}
	else if (kolo == 2 )
	{

		char litera1{}, litera2{}, litera3{};
		if (poprawna == 'A')
		{
			litera1 = 'C';
			litera2 = 'B';
			litera3 = 'D';
		}
		else if (poprawna == 'B')
		{
			litera1 = 'C';
			litera2 = 'A';
			litera3 = 'D';
		}
		else if (poprawna == 'C')
		{
			litera1 = 'A';
			litera2 = 'B';
			litera3 = 'D';
		}
		else if (poprawna == 'D')
		{
			litera1 = 'C';
			litera2 = 'B';
			litera3 = 'A';
		}




		random_device device;
		mt19937 generator(device());
		uniform_int_distribution<int> liczba(50, 100);
		int liczba1 = liczba(generator);
		uniform_int_distribution<int> liczbaA(0, (100-liczba1));
		int liczba2 = liczbaA(generator);
		uniform_int_distribution<int> liczbaB(0, (100 - (liczba1 + liczba2)));
		int liczba3 = liczbaB(generator);
		int liczba4 = 100 - (liczba1 + liczba2 + liczba3);

		kolo2 = 0;
		cout << endl << liczba1 << "% publicznosci wskazalo odpowiedz " << poprawna << endl;
		cout << liczba2 << "% publicznosci wskazalo odpowiedz " << litera1 << endl;
		cout << liczba3 << "% publicznosci wskazalo odpowiedz " << litera2 << endl;
		cout << liczba4 << "% publicznosci wskazalo odpowiedz " << litera3 << endl << endl;

		
	}
	else if (kolo == 3)
	{
		random_device device;
		mt19937 generator(device());
		uniform_int_distribution<int> Opcja(1, 3);
		int opcja = Opcja(generator);
		if (opcja == 1)
			cout << endl << "'Na twoim miejscu wybralbym odpowiedz " << poprawna << "' " << endl << endl;
		else if (opcja == 2)
		{
			cout << endl << "'Wydaje mi sie ze poprawna jest odpowiedz";
			if (poprawna == 'A')
				cout << " B" << endl << endl;
			else if (poprawna == 'B')
				cout << " D" << endl << endl;
			else if (poprawna == 'C')
				cout << " A" << endl << endl;
			else if (poprawna == 'D')
				cout << " C" << endl << endl;

		}
		else if (opcja == 3)
			cout << endl << "'Przykro mi, nie potrafie ci pomoc'" << endl << endl;


		kolo3 = 0;
	}
	else
		cout << "wpisana liczba jest niepoprawna" << endl;
}

//FUNKCJA WYPISUJ¥CA DOSTEPNE KO£A RATUNKOWE
void dost_kola(int kolo1, int kolo2, int kolo3)
{
	cout << "Dostepne kola ratunkowe: " << endl;
	if (kolo1 == 1)
		cout << "1. 50/50" << endl;
	if (kolo2 == 1)
		cout << "2. POMOC PUBLICZNOSCI" << endl;
	if (kolo3 == 1)
		cout << "3. TELEFON DO PRZYJACIELA" << endl;
	cout << endl;
}




int main()
{
	//WSTÊP DO GRY

	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	string odpkolo{};;
	char odp;
	int punkty = 0;
	int start = 0;
	string tak = "tak";
	string nie = "nie";
	string czystart{};
	

	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	
	cout << "                           ______                ______  ______   ______                  " << endl;
	cout << " |\\    /|  |  |        |  /      \\   |\\      |  |        |     \\        /   \\      /     " << endl;
	cout << " | \\  / |  |  |        | |        |  | \\     |  |        |      |      /     \\    /      " << endl;
	cout << " |  \\/  |  |  |        | |        |  |  \\    |  |        |_____/      /       \\  /	     " << endl;
	cout << " |      |  |  |        | |        |  |   \\   |  |_____   |\\          /         \\/        " << endl;
	cout << " |      |  |  |        | |        |  |    \\  |  |        | \\        /           |         " << endl;
	cout << " |      |  |  |        | |        |  |     \\ |  |        |  \\      /            |         " << endl;
	cout << " |      |  |  |______  |  \\______/   |      \\|  |______  |   \\    /______       |         " << endl;






	cout << "Witaj w grze Milionerzy: Edycja Disney!" << endl << "Czy chcesz rozpaczac gre? ";
	cin >> czystart;
	system("cls");


//PYTANIA TO TEN SAM SCHEMAT OD LINIJKI 174 DO 680
	if (czystart == tak)
	{
		//PYTANIE 1
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "Ilosc punktow: " << punkty << endl << endl;

		dost_kola(kolo1, kolo2, kolo3);

		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "Pytanie 1: " << endl << "Jakiej wartosci Lilo probowala nauczyc Sticha (Lilo i Stich) " << endl;
		cout << "A: 'Ohana' znaczy rodzina " << endl;
		cout << "B: 'kuikahi' znaczy jednosc " << endl;
		cout << "C: 'Aloha' znaczy milosc" << endl;
		cout << "D: 'Pomaikai' znaczy szczescie" << endl << endl;
		poprawna = 'A';
		poprawna2 = 'a';

		cout << "Czy chcesz uzyc kola ratunkowego? (tak/nie): ";
		cin >> odpkolo;
		if (odpkolo == tak)
			kolo_ratunkowe(kolo1, kolo2, kolo3);

		cout << "Twoja odpowiedz: ";
		cin >> odp;

		
		if (odp == poprawna || odp == poprawna2)
		{
			system("cls");
			punkty += 500;
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
			cout << endl << "GRATULACJE! To jest poprawna odpowiedz!" << endl;
			Sleep(2500);
		}

		else
		{
			system("cls");
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
			cout << endl << "Podana odpowiedz jest niepoprawna" << endl << "Ilosc zdobytych punktow: " << punkty << endl << " Koniec gry" << endl;
			Sleep(4000);
			return 0;
		}
		system("cls");

		//PYTANIE 2
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "Ilosc punktow: " << punkty << endl << endl;


	dost_kola(kolo1, kolo2, kolo3);

	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Pytanie 2: " << endl << "Jak nazywal sie gadajacy smok w filmie 'Mulan'? " << endl;
	cout << "A: Masha " << endl;
	cout << "B: Wielki Kamienny Smok " << endl;
	cout << "C: Mushu" << endl;
	cout << "D: Ling" << endl << endl;
	poprawna = 'C';
	poprawna2 = 'c';

	cout << "Czy chcesz uzyc kola ratunkowego? (tak/nie): ";
	cin >> odpkolo;
	if (odpkolo == tak)
	kolo_ratunkowe(kolo1, kolo2, kolo3);

	cout << "Twoja odpowiedz: ";
	cin >> odp;

	if (odp == poprawna || odp == poprawna2)
	{
		system("cls");
		punkty += 500;
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
		cout << endl << "GRATULACJE! To jest poprawna odpowiedz!" << endl;
		Sleep(2500);
	}

	else
	{
		system("cls");
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
		cout << endl << "Podana odpowiedz jest niepoprawna" << endl << "Ilosc zdobytych punktow: " << punkty << endl << " Koniec gry" << endl;
		Sleep(4000);
		return 0;
	}
	system("cls");


	//PYTANIE 3
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "Ilosc punktow: " << punkty << endl << endl;


	dost_kola(kolo1, kolo2, kolo3);

	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Pytanie 3: " << endl << "Jaki tytul nosi piosenka z filmu 'Zaplatni' spiewana przez Roszpunke na lodzi? " << endl;
	cout << "A: Nowe dni " << endl;
	cout << "B: Po raz pierwszy widze blask " << endl;
	cout << "C: Po raz pierwszy widze swiatlo" << endl;
	cout << "D: Po raz pierwszy plyne lodzia " << endl << endl;
	poprawna = 'B';
	poprawna2 = 'b';

	cout << "Czy chcesz uzyc kola ratunkowego? (tak/nie): ";
	cin >> odpkolo;
	if (odpkolo == tak)
		kolo_ratunkowe(kolo1, kolo2, kolo3);

	cout << "Twoja odpowiedz: ";
	cin >> odp;

	if (odp == poprawna || odp == poprawna2)
	{
		system("cls");
		punkty += 1000;
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
		cout << endl << "GRATULACJE! To jest poprawna odpowiedz!" << endl;
		Sleep(2500);
	}

	else
	{
		system("cls");
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
		cout << endl << "Podana odpowiedz jest niepoprawna" << endl << "Ilosc zdobytych punktow: " << punkty << endl << " Koniec gry" << endl;
		Sleep(4000);
		return 0;
	}
	system("cls");

	//PYTANIE 4
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "Ilosc punktow: " << punkty << endl << endl;


	dost_kola(kolo1, kolo2, kolo3);

	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Pytanie 4: " << endl << "Dzieki jakiej potrawie Linguini zostal kucharzem? (Ratatuj) " << endl;
	cout << "A: Ryba " << endl;
	cout << "B: Zupa " << endl;
	cout << "C: Stek" << endl;
	cout << "D: Ratatuj " << endl << endl;
	poprawna = 'B';
	poprawna2 = 'b';

	cout << "Czy chcesz uzyc kola ratunkowego? (tak/nie): ";
	cin >> odpkolo;
	if (odpkolo == tak)
		kolo_ratunkowe(kolo1, kolo2, kolo3);

	cout << "Twoja odpowiedz: ";
	cin >> odp;

	if (odp == poprawna || odp == poprawna2)
	{
		system("cls");
		punkty += 3000;
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
		cout << endl << "GRATULACJE! To jest poprawna odpowiedz!" << endl;
		Sleep(2500);
	}

	else
	{
		system("cls");
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
		cout << endl << "Podana odpowiedz jest niepoprawna" << endl << "Ilosc zdobytych punktow: " << punkty << endl << " Koniec gry" << endl;
		Sleep(4000);
		return 0;
	}
	system("cls");


	}

	//PYTANIE 5
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "Ilosc punktow: " << punkty << endl << endl;


	dost_kola(kolo1, kolo2, kolo3);

	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Pytanie 5: Jakie zwierze udomowil Wall-e? (WALL-E)" << endl << " " << endl;
	cout << "A: Mrowka" << endl;
	cout << "B: Gasienica " << endl;
	cout << "C: Motyl" << endl;
	cout << "D: Karaluch " << endl << endl;
	poprawna = 'D';
	poprawna2 = 'd';

	cout << "Czy chcesz uzyc kola ratunkowego? (tak/nie): ";
	cin >> odpkolo;
	if (odpkolo == tak)
		kolo_ratunkowe(kolo1, kolo2, kolo3);

	cout << "Twoja odpowiedz: ";
	cin >> odp;

	if (odp == poprawna || odp == poprawna2)
	{
		system("cls");
		punkty += 5000;
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
		cout << endl << "GRATULACJE! To jest poprawna odpowiedz!" << endl;
		Sleep(2500);
	}

	else
	{
		system("cls");
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
		cout << endl << "Podana odpowiedz jest niepoprawna" << endl << "Ilosc zdobytych punktow: " << punkty << endl << " Koniec gry" << endl;
		Sleep(4000);
		return 0;
	}
	system("cls");
	//PYTANIE 6
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "Ilosc punktow: " << punkty << endl << endl;


	dost_kola(kolo1, kolo2, kolo3);

	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Pytanie 6: Jaka kara grozila Mulan za podszywanie sie pod mezczyne? (Mulan) " << endl << " " << endl;
	cout << "A: Wygnanie" << endl;
	cout << "B: Wiezienie " << endl;
	cout << "C: Okrycie hanba" << endl;
	cout << "D: Smierc " << endl << endl;
	poprawna = 'D';
	poprawna2 = 'd';

	cout << "Czy chcesz uzyc kola ratunkowego? (tak/nie): ";
	cin >> odpkolo;
	if (odpkolo == tak)
		kolo_ratunkowe(kolo1, kolo2, kolo3);

	cout << "Twoja odpowiedz: ";
	cin >> odp;

	if (odp == poprawna || odp == poprawna2)
	{
		system("cls");
		punkty += 10000;
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
		cout << endl << "GRATULACJE! To jest poprawna odpowiedz!" << endl;
		Sleep(2500);
	}

	else
	{
		system("cls");
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
		cout << endl << "Podana odpowiedz jest niepoprawna" << endl << "Ilosc zdobytych punktow: " << punkty << endl << " Koniec gry" << endl;
		Sleep(4000);
		return 0;
	}
	system("cls");


	//PYTANIE 7
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "Ilosc punktow: " << punkty << endl << endl;


	dost_kola(kolo1, kolo2, kolo3);

	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Pytanie 7: Ryba Deb myslala ze jej odbicie jest: (Gdzie jest Nemo?) " << endl << " " << endl;
	cout << "A: Duchem " << endl;
	cout << "B: Jej siostra " << endl;
	cout << "C: Wrozka" << endl;
	cout << "D: Zwyklym odbiciem " << endl << endl;
	poprawna = 'B';
	poprawna2 = 'b';

	cout << "Czy chcesz uzyc kola ratunkowego? (tak/nie): ";
	cin >> odpkolo;
	if (odpkolo == tak)
		kolo_ratunkowe(kolo1, kolo2, kolo3);

	cout << "Twoja odpowiedz: ";
	cin >> odp;

	if (odp == poprawna || odp == poprawna2)
	{
		system("cls");
		punkty += 20000;
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
		cout << endl << "GRATULACJE! To jest poprawna odpowiedz!" << endl;
		Sleep(2500);
	}

	else
	{
		system("cls");
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
		cout << endl << "Podana odpowiedz jest niepoprawna" << endl << "Ilosc zdobytych punktow: " << punkty << endl << " Koniec gry" << endl;
		Sleep(4000);
		return 0;
	}
	system("cls");


	//PYTANIE 8
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "Ilosc punktow: " << punkty << endl << endl;


	dost_kola(kolo1, kolo2, kolo3);

	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Pytanie 8: Jaka moc posiadal Max Parr? (Iniemamocni) " << endl << " " << endl;
	cout << "A: Sila " << endl;
	cout << "B: Telekineza " << endl;
	cout << "C: Szybkosc" << endl;
	cout << "D: Niewidzialnosc " << endl << endl;
	poprawna = 'C';
	poprawna2 = 'c';

	cout << "Czy chcesz uzyc kola ratunkowego? (tak/nie): ";
	cin >> odpkolo;
	if (odpkolo == tak)
		kolo_ratunkowe(kolo1, kolo2, kolo3);

	cout << "Twoja odpowiedz: ";
	cin >> odp;

	if (odp == poprawna || odp == poprawna2)
	{
		system("cls");
		punkty += 35000;
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
		cout << endl << "GRATULACJE! To jest poprawna odpowiedz!" << endl;
		Sleep(2500);
	}

	else
	{
		system("cls");
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
		cout << endl << "Podana odpowiedz jest niepoprawna" << endl << "Ilosc zdobytych punktow: " << punkty << endl << " Koniec gry" << endl;
		Sleep(4000);
		return 0;
	}
	system("cls");

	//PYTANIE 9
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "Ilosc punktow: " << punkty << endl << endl;


	dost_kola(kolo1, kolo2, kolo3);

	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Pytanie 9: Jak rozladowany Baymax nazywal kota Hiro? (Wielka Szostka) " << endl << " " << endl;
	cout << "A: Wlochata dzidzia" << endl;
	cout << "B: Futrzany bobas " << endl;
	cout << "C: Dziecko w siersci" << endl;
	cout << "D: Klaczek " << endl << endl;
	poprawna = 'A';
	poprawna2 = 'a';

	cout << "Czy chcesz uzyc kola ratunkowego? (tak/nie): ";
	cin >> odpkolo;
	if (odpkolo == tak)
		kolo_ratunkowe(kolo1, kolo2, kolo3);

	cout << "Twoja odpowiedz: ";
	cin >> odp;

	if (odp == poprawna || odp == poprawna2)
	{
		system("cls");
		punkty += 50000;
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
		cout << endl << "GRATULACJE! To jest poprawna odpowiedz!" << endl;
		Sleep(2500);
	}

	else
	{
		system("cls");
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
		cout << endl << "Podana odpowiedz jest niepoprawna" << endl << "Ilosc zdobytych punktow: " << punkty << endl << " Koniec gry" << endl;
		Sleep(4000);
		return 0;
	}
	system("cls");




	//PYTANIE 10
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "Ilosc punktow: " << punkty << endl << endl;


	dost_kola(kolo1, kolo2, kolo3);

	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Pytanie 10: Jakie danie bylo popisowym daniem Shreka? " << endl << " " << endl;
	cout << "A: Wata cukrowa z pajeczej sieci " << endl;
	cout << "B: Marynowane slimaki" << endl;
	cout << "C: Szczur w sosie wlasnym" << endl;
	cout << "D: Zabie oczy w zalewie " << endl << endl;
	poprawna = 'C';
	poprawna2 = 'c';

	cout << "Czy chcesz uzyc kola ratunkowego? (tak/nie): ";
	cin >> odpkolo;
	if (odpkolo == tak)
		kolo_ratunkowe(kolo1, kolo2, kolo3);

	cout << "Twoja odpowiedz: ";
	cin >> odp;

	if (odp == poprawna || odp == poprawna2)
	{
		system("cls");
		punkty += 125000;
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
		cout << endl << "GRATULACJE! To jest poprawna odpowiedz!" << endl;
		Sleep(2500);
	}

	else
	{
		system("cls");
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
		cout << endl << "Podana odpowiedz jest niepoprawna" << endl << "Ilosc zdobytych punktow: " << punkty << endl << " Koniec gry" << endl;
		Sleep(4000);
		return 0;
	}
	system("cls");
	//PYTANIE 11
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "Ilosc punktow: " << punkty << endl << endl;


	dost_kola(kolo1, kolo2, kolo3);

	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Pytanie 11: Jaka zupe gotowal ojciec Tiany? (Ksiezniczka i Zaba) " << endl << " " << endl;
	cout << "A: Rosol " << endl;
	cout << "B: Ramen " << endl;
	cout << "C: Gambo " << endl;
	cout << "D: Tom Yam Kung" << endl << endl;
	poprawna = 'C';
	poprawna2 = 'c';

	cout << "Czy chcesz uzyc kola ratunkowego? (tak/nie): ";
	cin >> odpkolo;
	if (odpkolo == tak)
		kolo_ratunkowe(kolo1, kolo2, kolo3);

	cout << "Twoja odpowiedz: ";
	cin >> odp;

	if (odp == poprawna || odp == poprawna2)
	{
		system("cls");
		punkty += 250000;
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
		cout << endl << "GRATULACJE! To jest poprawna odpowiedz!" << endl;
		Sleep(2500);
	}

	else
	{
		system("cls");
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
		cout << endl << "Podana odpowiedz jest niepoprawna" << endl << "Ilosc zdobytych punktow: " << punkty << endl << " Koniec gry" << endl;
		Sleep(4000);
		return 0;
	}
	system("cls");

	//PYTANIE 12
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "Ilosc punktow: " << punkty << endl << endl;


	dost_kola(kolo1, kolo2, kolo3);

	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "PYTANIE FINALOWE: Jak nazywala sie ryba z obsejsa na punkcie bakterii? (Gdzie jest Nemo?) " << endl << " " << endl;
	cout << "A: Zoltek " << endl;
	cout << "B: Bulgotek" << endl;
	cout << "C: Idol" << endl;
	cout << "D: Rozdym " << endl << endl;
	poprawna = 'B';
	poprawna2 = 'b';

	cout << "Czy chcesz uzyc kola ratunkowego? (tak/nie): ";
	cin >> odpkolo;
	if (odpkolo == tak)
		kolo_ratunkowe(kolo1, kolo2, kolo3);

	cout << "Twoja odpowiedz: ";
	cin >> odp;

	if (odp == poprawna || odp == poprawna2)
	{
		system("cls");
		punkty += 500000;
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
		cout << endl << "GRATULACJE! WYGRALES " << endl;
		
			cout << "                           ______                  " << endl;
		cout << " |\\    /|  |  |        |  /      \\   |\\      |    " << endl;
		cout << " | \\  / |  |  |        | |        |  | \\     |     " << endl;
		cout << " |  \\/  |  |  |        | |        |  |  \\    |  " << endl;
		cout << " |      |  |  |        | |        |  |   \\   |     " << endl;
		cout << " |      |  |  |        | |        |  |    \\  |      " << endl;
		cout << " |      |  |  |        | |        |  |     \\ |       " << endl;
		cout << " |      |  |  |______  |  \\______/   |      \\|         " << endl;



		Sleep(2500);
	}

	else
	{
		system("cls");
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
		cout << endl << "Podana odpowiedz jest niepoprawna" << endl << "Ilosc zdobytych punktow: " << punkty << endl << " Koniec gry" << endl;
		Sleep(4000);
		return 0;
	}
	system("cls");


	system("pause");
}