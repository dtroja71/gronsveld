#include <iostream>
#include <string>
#include <fstream> 
#include <Windows.h>

using namespace std;

string lib;



string encrypt(string str, int key)
{
	int temp;
	string encryptText;
	cout << "Encryption..." << endl;
	cout << "key: " << key << "\ntext: " << str << "    " << endl;
	for (int i = 0; i < str.length(); i++)
	{
		for (int j = 0; j < lib.length(); j++)
		{
			if ((char)str[i] == lib[j])
			{
				temp = (j + key) % lib.length();
				encryptText += lib[temp];
			}
		}
	}
	cout << "Encrypted text: " << encryptText << endl;
	return encryptText;
}

string decrypt(string str, int key)
{
	int temp;
	string decryptText;
	cout << "Decryption..." << endl;
	cout << "key: " << key << "\ntext: " << str << "    " << endl;
	for (int i = 0; i < str.length(); i++)
	{
		for (int j = 0; j < lib.length(); j++)
		{
			if ((char)str[i] == lib[j])
			{
				temp = j - key;
				if (temp < 0) {
					temp += lib.length();
				}
				else {
					temp = (j - key) % lib.length();
				}
				decryptText += lib[temp];
			}
		}
	}
	cout << "Decrypted text: " << decryptText << endl;
	return decryptText;
}
string readFromFile(string filename)
{
	string text;
	ifstream fileIn;    //read
	fileIn.open(filename);
	if (fileIn.fail())
	{
		cout << "Error opening file!\a";
		return "error";
	}
	while (!fileIn.eof())
	{
		string line;
		getline(fileIn, line);
		text += line + '\n';
	}
	fileIn.close();
	return text;
}

string writeInFile(string filename, string text)
{
	ofstream fileOut; //write
	fileOut.open(filename);
	if (fileOut.fail())
	{
		cout << "Error opening file!\a";
		return "error";
	}
	fileOut << text;
	fileOut.close();
}

string makeLib()
{

	for (int i = 33; i < 47; i++) //большие буквы
	{
		lib += (char)i;
	}
	for (int i = 65; i < 91; i++) //большие буквы
	{
		lib += (char)i;
	}
	for (int i = 97; i <= 122; i++) //маленькие буквы
	{
		lib += (char)i;
	}
	for (int i = 48; i <= 57; i++) //цифры
	{
		lib += (char)i;
	}
	for (int i = 192; i < 224; i++) //большие буквы
	{
		lib += (char)i;
	}
	for (int i = 224; i < 256; i++) //большие буквы
	{
		lib += (char)i;
	}
	lib += (char)32;
	lib += '\n';
	return lib;
}

void PrintLib(string lib)
{
	for (int i = 0; i < lib.length(); i++)
	{
		cout << lib[i] << i << " ";
	}
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "");

	string fileN = "text.txt";
	string fileNE = "e.txt";
	string fileND = "d.txt";
	makeLib();

	//cout << makeLib() << endl;
	while (true)
	{
		PrintLib(lib);
		//шифрование
		string str, key;
		cout << "¬ведите ключ: ";
		cin >> key;
		str = readFromFile(fileN);
		cout << str;

		writeInFile(fileNE, encrypt(str, stoi(key)));

		system("pause");

		//дешифрование
		str = readFromFile(fileNE);
		writeInFile(fileND, decrypt(str, stoi(key)));

		system("pause");
	}



	return 0;
}