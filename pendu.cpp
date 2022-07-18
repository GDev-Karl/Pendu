#include <iostream>
#include <ctype.h>
#include <fstream>
#include <time.h>
#define clear() system("cls")

using namespace std;
	int Aleatoire(int nbre_max) //Choisit un nombre aleatoire de 0 a nbre_max
	{
		srand(time(NULL));
		return (rand()%nbre_max);
	}
	
	string  piochemot() // choisit un mot au hasard dans le dictionnaire
	{
		int nbre_mot(0), num_mot;
		string mot_cache;
		string const dict("dict.txt");
		ifstream flux(dict.c_str());

		if (flux)
		{
			char a;
			while(flux.get(a)) // Tant qu'on peut lire un caractere dans le fichier
			{	
				if(a == '\n')
					nbre_mot += 1;
			}
			num_mot = Aleatoire(nbre_mot);
		}
		else
			cout<<"Erreur";
		flux.close();
		flux.open(dict.c_str());

		if (flux){
			string ligne;
			while(num_mot >= 0)
			{
				while(getline(flux,ligne)){// tant qu'on peut lire une ligne dans le fichier
					mot_cache = ligne;
					num_mot--;
					break;
				}
			}
		}
		else
			cout<<"echouer";
		return mot_cache;
	}

	int verif(char letter,string mot)//on verife que la lettre appartient au mot
	{
		
		for (int i=0 ; i < mot.size();i++)
			{
				if (mot[i] == letter)
					return 1;
			}
		return 0;
	}

	int compare(string mot1, string mot2)// Verifie si deux mots sont egaux
	{
		string tamp;

		tamp += mot1;
		if (tamp == mot2)
			return 1;
		else 
			return 0;
	}

	int main () //Fonction principale
	{
		string mot, cp_mot;
		char letter(0);
		int i,coup(10);
		mot = piochemot();// On met le mot cache dans la variable mot
		cp_mot = piochemot();

		for ( i=0 ; i < cp_mot.size();i++)
			cp_mot[i] = '*';

		while(coup > 0)
		{
			cout<<"il vous reste "<< coup <<"coups a jouer"<< endl;
			cout<<"Quel est le mot secret ? "<<cp_mot<< endl;
			cout<<"Proposez une lettre : ";
			cin>>letter;
			letter = toupper(letter);//on transforme le lettre en majuscule
			for ( i=0 ; i < mot.size();i++)
				{
					if (mot[i] == letter){
						cp_mot[i] = letter;
					}
				}
			if (verif(letter,mot) == 0)
				coup--;

			clear();

			if (compare(cp_mot,mot) == 1){
				cout<<"\n Bravo vous avez gagnez le mot Mystere est "<<mot<< endl;
				break;
			}
		}
		if (compare(cp_mot,mot) == 0)
			cout<<"\n Vous avez perdu le mot Mystere etait "<<mot<< endl;
	}