
#include <iostream>
#include <vector>
#include <clocale>
using namespace std;
void LiczenieSytuacji(char plansza[], int *pozycjaBialych, int *pozycjaCzarnych){}
void rysowaniePlanszy(char *wskaznik)
{
	cout << "+------+";
	cout << "\n";
	for (int i = 0; i < 36; i++)
	{
		if (i % 6 == 0 or i == 0) cout << "|";
		if (i % 6 == 0 and i != 0)
		{
			cout << "\n";
			cout << "|";
		}
		cout << wskaznik[i];
	}
	cout << "|";
	cout << '\n';
	cout << "+------+";
}
void mozliwyRuchy(char *wskaznik, int *pozycjaBialych, int *pozycjaCzarnych, int *mozliweRuchy, bool Kolor)
{
	for (int i = 0; i < 6; i++)
	{
		if (Kolor == true) {
			if (wskaznik[pozycjaBialych[i]] == 'B') {
				if (wskaznik[pozycjaBialych[i] - 7] == 'X' and pozycjaBialych[i] != -1)
				{
					int x = pozycjaBialych[i] - 7;
					cout << pozycjaBialych[i] << " --> " << x << endl;
				}
				if (wskaznik[pozycjaBialych[i] - 5] == 'X' and pozycjaBialych[i] != -1) {

					int x = pozycjaBialych[i] - 5;
					cout << pozycjaBialych[i] << " --> " << x << endl;
				}
				if (wskaznik[pozycjaBialych[i] - 14] == 'X' and wskaznik[pozycjaBialych[i] - 7] == 'C' and pozycjaBialych[i] != -1)
				{
					int x = pozycjaBialych[i] - 14;
					cout << pozycjaBialych[i] << " --> " << x << endl;
				}
				if (wskaznik[pozycjaBialych[i] - 10] == 'X' and wskaznik[pozycjaBialych[i] - 5] == 'C' and pozycjaBialych[i] != -1)
				{
					int x = pozycjaBialych[i] - 10;
					cout << pozycjaBialych[i] << " --> " << x << endl;
				}
			}
			else if (wskaznik[pozycjaBialych[i]] == 'D') {}
		}
		else {
			if (wskaznik[pozycjaCzarnych[i]] == 'C') {
				if (wskaznik[pozycjaCzarnych[i] + 7] == 'X' and pozycjaCzarnych[i] != -1)
				{
					int x = pozycjaCzarnych[i] + 7;
					cout << pozycjaCzarnych[i] << " --> " << x << endl;
				}
				if (wskaznik[pozycjaCzarnych[i] + 5] == 'X' and pozycjaCzarnych[i] != -1) {
					int x = pozycjaCzarnych[i] + 5;
					cout << pozycjaCzarnych[i] << " --> " << x << endl;
				}
				if (wskaznik[pozycjaCzarnych[i] + 14] == 'X' and wskaznik[pozycjaCzarnych[i] + 7] == 'B' and pozycjaCzarnych[i] != -1)
				{

					int x = pozycjaCzarnych[i] + 14;
					cout << pozycjaCzarnych[i] << " --> " << x << endl;
				}
				if (wskaznik[pozycjaCzarnych[i] + 10] == 'X' and wskaznik[pozycjaCzarnych[i] + 5] == 'B' and pozycjaCzarnych[i] != -1) {
					int x = pozycjaCzarnych[i] + 10;
					cout << pozycjaCzarnych[i] << " --> " << x << endl;
				}
			}
		}
	}
}
void zmianaPozycji(int *pozycjaBialych, int *pozycjaCzarnych, bool Kolor, int pozycjaStartowa, int pozycjaKoncowa) {
	if (Kolor == true)
	{
		for (int i = 0; i <= 5; i++)
		{
			if (pozycjaBialych[i] == pozycjaStartowa) { pozycjaBialych[i] = pozycjaKoncowa; };
		}
	}
	else {
		for (int i = 0; i <= 5; i++)
		{
			if (pozycjaCzarnych[i] == pozycjaStartowa) { pozycjaCzarnych[i] = pozycjaKoncowa; };
		}
	}

}
void Damka(bool Kolor, char *wskaznik, int *pozycjaBialych, int *pozycjaCzarnych)
{
	if (Kolor == true) {
		for (int i = 0; i < 6; i++)
		{
			if (pozycjaBialych[i] == 1) {
				wskaznik[1] = 'D';
			}
			else if (pozycjaBialych[i] == 3) {
				wskaznik[3] = 'D';
			}
			else if (pozycjaBialych[i] == 5) {
				wskaznik[5] = 'D';
			}
		}
	}
	else {
		for (int i = 0; i < 6; i++)
		{
			if (pozycjaCzarnych[i] == 30) {
				wskaznik[30] = 'd';
			}
			else if (pozycjaCzarnych[i] == 32) {
				wskaznik[32] = 'd';
			}
			else if (pozycjaCzarnych[i] == 34) {
				wskaznik[34] = 'd';
			}
		}

	}
}
void ruch(char *wskaznik, int pozycjaStartowa, int pozycjaKoncowa, bool Kolor, int *pozycjaBialych, int *pozycjaCzarnych, int *wskaznikruchow)
{
	zmianaPozycji(pozycjaBialych, pozycjaCzarnych, Kolor, pozycjaStartowa, pozycjaKoncowa);
	int PozycjaPomiedzy;
	swap(wskaznik[pozycjaStartowa], wskaznik[pozycjaKoncowa]);
	if (wskaznik[pozycjaStartowa] == 'D' or wskaznik[pozycjaStartowa] == 'd')
	{
		if (pozycjaStartowa < pozycjaKoncowa) {
			if ((pozycjaKoncowa - pozycjaStartowa) % 7 == 0) {
				int pomoc = (pozycjaKoncowa - pozycjaStartowa) / 7;
				for (int i = 1; i < pomoc; i++) {
					wskaznik[pozycjaStartowa + (i * 7)] = 'X';
					for (int j = 0; j < 6; j++) {
						if (Kolor == true) {
							if (pozycjaCzarnych[j] == pozycjaStartowa + (i * 7)) {
								pozycjaCzarnych[j] = -1;
							}
						}
						else {
							if (pozycjaBialych[j] == pozycjaStartowa + (i * 7)) {
								pozycjaBialych[j] = -1;
							}
						}
					}
				}
			}
			else if ((pozycjaKoncowa - pozycjaStartowa) % 5 == 0) {
				int pomoc = (pozycjaKoncowa - pozycjaStartowa) / 5;
				for (int i = 1; i < pomoc; i++) {
					wskaznik[pozycjaStartowa + (i * 5)] = 'X';
					for (int j = 0; j < 6; j++) {
						if (Kolor == true) {
							if (pozycjaCzarnych[j] == pozycjaStartowa + (i * 5)) {
								pozycjaCzarnych[j] = -1;
							}
						}
						else {
							if (pozycjaBialych[j] == pozycjaStartowa + (i * 5)) {
								pozycjaBialych[j] = -1;
							}
						}
					}
				}
			}
		}
		else if (pozycjaStartowa > pozycjaKoncowa) {
			if ((pozycjaStartowa - pozycjaKoncowa) % 7 == 0) {
				int pomoc = (pozycjaStartowa - pozycjaKoncowa) / 7;
				for (int i = 1; i < pomoc; i++) {
					wskaznik[pozycjaStartowa - (i * 7)] = 'X';
					for (int j = 0; j < 6; j++) {
						if (Kolor == true) {
							if (pozycjaCzarnych[j] == pozycjaStartowa - (i * 7)) {
								pozycjaCzarnych[j] = -1;
							}
						}
						else {
							if (pozycjaBialych[j] == pozycjaStartowa - (i * 7)) {
								pozycjaBialych[j] = -1;
							}
						}
					}
				}
			}
			else if ((pozycjaStartowa - pozycjaKoncowa) % 5 == 0) {
				int pomoc = (pozycjaStartowa - pozycjaKoncowa) / 5;
				for (int i = 1; i < pomoc; i++) {
					wskaznik[pozycjaStartowa - (i * 5)] = 'X';
					for (int j = 0; j < 6; j++) {
						if (Kolor == true) {
							if (pozycjaCzarnych[j] == pozycjaStartowa - (i * 5)) {
								pozycjaCzarnych[j] = -1;
							}
						}
						else {
							if (pozycjaBialych[j] == pozycjaStartowa - (i * 5)) {
								pozycjaBialych[j] = -1;
							}
						}
					}
				}
			}

		}
		
	}
	else {
			PozycjaPomiedzy = (pozycjaKoncowa + pozycjaStartowa) / 2;
			if ((pozycjaStartowa - pozycjaKoncowa == 7)
				or (pozycjaStartowa - pozycjaKoncowa == 5)
				or (pozycjaKoncowa - pozycjaStartowa == 7)
				or (pozycjaKoncowa - pozycjaStartowa == 5)) {
			}
			else{
				wskaznik[PozycjaPomiedzy] = 'X';
				for (int i = 0; i < 6; i++)
				{
					if (Kolor != true)
					{
						if (pozycjaBialych[i] == PozycjaPomiedzy) pozycjaBialych[i] = -1;
					}
					else { if (pozycjaCzarnych[i] == PozycjaPomiedzy) pozycjaCzarnych[i] = -1; }
				}
			}
		}
	}
bool CzyWygrana(int *pozycjaBialych, int *pozycjaCzarnych, bool Kolor) {
	int Wygrana = 0;
	if (Kolor == true) {
		for (int i = 0; i < 6; i++) {
			if (pozycjaBialych[i] == -1) {
				Wygrana++;
			}
		}
	}
	else {
		for (int i = 0; i < 6; i++) {
			if (pozycjaCzarnych[i] == -1) {
				Wygrana++;
			}
		}
	}
	if (Wygrana == 6) return true;
	else return false;
}

int main()
{
	setlocale(LC_ALL, "");
	bool Kolor = false, Wygrana = false;
	int pozycjaStartowa, pozycjaKoncowa, ileBic;
	char playground[36] =
	{

		' ','C',' ','C',' ' ,'C',
		'C',' ','C',' ','C' ,' ',
		' ','X',' ','X',' ' ,'X',
		'X',' ','X',' ','X' ,' ',
		' ','B',' ','B',' ' ,'B',
		'B',' ','B',' ','B' ,' ',

	};
	char *wskaznikPlayground = &playground[0];
	int mozliweRuchy[18] =
	{
	 1,3,5,6,8,10,13,15,17,18,20,22,25,27,29,30,32,34
	};
	int *wskaznikruchow = &mozliweRuchy[0];
	int pozycjaBialych[6] =
	{
		25,27,29,30,32,34
	};
	int *wskaznikBialych = &pozycjaBialych[0];
	int pozycjaCzarnych[6] =
	{
		1,3,5,6,8,10
	};
	int *wskaznikCzarnych = &pozycjaCzarnych[0];
	rysowaniePlanszy(wskaznikPlayground);
	cout << "\n";
	while (Wygrana == false)
	{
		mozliwyRuchy(wskaznikPlayground, wskaznikBialych, wskaznikCzarnych, mozliweRuchy, Kolor);
		cout << "Podaj ruch";
		cin >> pozycjaStartowa >> pozycjaKoncowa;
		ruch(wskaznikPlayground, pozycjaStartowa, pozycjaKoncowa, Kolor, wskaznikBialych, wskaznikCzarnych, wskaznikruchow);
		Damka(Kolor, wskaznikPlayground, wskaznikBialych, wskaznikCzarnych);
		zmianaPozycji(pozycjaBialych, pozycjaCzarnych, Kolor, pozycjaStartowa, pozycjaKoncowa);
		Wygrana = CzyWygrana(pozycjaBialych, pozycjaCzarnych, Kolor);
		rysowaniePlanszy(wskaznikPlayground);
		cout << "\n";
		(Kolor) ? (Kolor = false) : (Kolor = true);
	}
	cout << "Wygrana!";
}
