#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
void substitution(string letter);
int subsarray[10];
int quotient[10];
int remainder[10];
int ascii[10];
int cypher[30];
int y;
int a;
void convertToASCII(string letter)
{

	for (int i = 0; i < letter.length(); i++)
    {
        char x = letter.at(i);
        y=int(x);
        ascii[i]=y;
    }
}
void CBC(string letter)
{
 char keyToEncrypt = 's';
 char t ;

 	for (int temp = 0; temp < letter.length(); temp++)
	{
   		letter[temp] ^= (int(keyToEncrypt) + temp) % 255;
   		keyToEncrypt=letter[temp];

	}
 cout << "The encrypted data = "<<letter<<endl;
 convertToASCII(letter);
}
void substitution(string letter)
{
	cout<<endl<<"Substitution array= "<<endl;
	for (int i=0;i<letter.length();i++)
	{
		subsarray[i]=rand() % 1000 + 1000;
		cout<<subsarray[i]<<" ";
	}
	cout<<endl;
}
void division(string letter)
{
	for (int i=0;i<letter.length();i++)
	{
		quotient[i]=subsarray[i]/ascii[i];
		remainder[i]=subsarray[i]%ascii[i];
	}
}
void cipher(string letter)
{
	int k=0;
	for (int i=0;i<letter.length()*3;i++)
	{
		cypher[i]=subsarray[k];
		i++;
		cypher[i]=quotient[k];
		i++;
		cypher[i]=remainder[k];
		k++;
	}

}
int encryptsendertext()
{
	string plainText;
	cout << "Enter Plain Text ";
	getline(cin, plainText);
	::a=plainText.length();
	CBC(plainText);
	substitution(plainText);
	division(plainText);
	cipher(plainText);

}
void decryptreceivedtext()
{
	int k;
	int sub,q,r;
	string letter="";
	char keyToEncrypt='s',t;
	cout<<"Extracted string from the substitution array"<<endl;
	for (int i=0;i<a*3;i++)
	{
		sub=cypher[i];
		i++;
		q=cypher[i];
		i++;
		r=cypher[i];
		k=(sub-r)/q;
		int x = k;
        letter+=char(x);
	}
	cout<<letter<<endl;
	for (int temp = 0; temp < a ; temp++)
	{
		t=letter[temp];
   		letter[temp] ^= (int(keyToEncrypt) + temp) % 255;
   		keyToEncrypt=t;
	}
	 cout << "The unencrypted data = " <<letter<<endl;
}
int main()
{
    encryptsendertext();
    decryptreceivedtext();
}
