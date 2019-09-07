#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <conio.h>
#include <windows.h>
#include <experimental/filesystem>

using namespace std;

string main_directory()
{
	namespace fs = experimental::filesystem;
	string home1 = (fs::current_path().string());
	string filename = "Main_Directory.txt";
	ofstream files;
	files.open(filename);
	for (int i = 0; i < (int)home1.size(); i++)
	{
		if (i == (int)(home1.size() - 1))
		{
			files << home1[i] << home1[2] << home1[2];
		}
		if ((home1[i] == home1[2]) && (i != (int)(home1.size() - 1)))
		{
			files << home1[i] << home1[2];
		}
		if ((home1[i] != home1[2]) && (i != (int)(home1.size() - 1)))
		{
			files << home1[i];
		}
	}
	files.close();
	ifstream files2;
	files2.open(filename);
	files2 >> home1;
	return home1;
}
string home = main_directory();
void comm1(int sizestr2, int sizestr3, vector <string> &str2, vector <string> &str3)
{
	for (int i = 0; i < sizestr3; i++)
	{
		int k = 0;
		for (int j = 0; j < sizestr2; j++)
		{
			if (str3[i] == str2[j])
			{
				k++;
			}
		}
		if (k == 0)
		{
			cout << str3[i] << endl;
		}
		else
		{
			cout << "\t" << str3[i] << endl;
		}
	}
}
void comm2(int sizestr2, int sizestr3, vector <string> &str2, vector <string> &str3)
{
	for (int j = 0; j < sizestr2; j++)
	{
		int k = 0;
		for (int i = 0; i < sizestr3; i++)
		{
			if (str2[j] == str3[i])
			{
				k++;
			}
		}
		if (k == 0)
		{
			cout << str2[j] << endl;
		}
		else
		{
			cout << "\t" << str2[j] << endl;
		}
	}
}
void comm3(int sizestr2, int sizestr3, vector <string> &str2, vector <string> &str3)
{
	for (int j = 0; j < sizestr2; j++)
	{
		int k = 0;
		for (int i = 0; i < sizestr3; i++)
		{
			if (str2[j] == str3[i])
			{
				k++;
			}
		}
		if (k == 0)
		{
			cout << str2[j] << endl;
		}
	}
	for (int i = 0; i < sizestr3; i++)
	{
		int k = 0;
		for (int j = 0; j < sizestr2; j++)
		{
			if (str3[i] == str2[j])
			{
				k++;
			}
		}
		if (k == 0)
		{
			cout << str3[i] << "\t" << endl;
		}
	}
	cout << endl;
}
void comm12(int sizestr2, int sizestr3, vector <string> &str2, vector <string> &str3)
{
	for (int i = 0; i < sizestr3; i++)
	{
		int k = 0;
		for (int j = 0; j < sizestr2; j++)
		{
			if (str3[i] == str2[j])
			{
				k++;
			}
		}
		if (k != 0)
		{
			cout << str3[i] << endl;
		}
	}
}
void comm13(int sizestr2, int sizestr3, vector <string> &str2, vector <string> &str3)
{
	for (int i = 0; i < sizestr3; i++)
	{
		int k = 0;
		for (int j = 0; j < sizestr2; j++)
		{
			if (str3[i] == str2[j])
			{
				k++;
			}
		}
		if (k == 0)
		{
			cout << str3[i] << endl;
		}
	}
}
void comm23(int sizestr2, int sizestr3, vector <string> &str2, vector <string> &str3)
{
	for (int j = 0; j < sizestr2; j++)
	{
		int k = 0;
		for (int i = 0; i < sizestr3; i++)
		{
			if (str2[j] == str3[i])
			{
				k++;
			}
		}
		if (k == 0)
		{
			cout << str2[j] << endl;
		}
	}
}
void cat_reiteration(string command1)
{
	ifstream catfile;
	catfile.open(home + command1);
	if (!catfile.is_open())
	{
		cout << "cat: " << command1 << ": " << "Нет такого файла или каталога" << endl;
	}
	else
	{
		string strforcout;
		while (!catfile.eof())
		{
			strforcout = "";
			getline(catfile, strforcout);
			cout << strforcout << endl;
		}
		catfile.close();
	}
}
void pwd_reiteration()
{
	namespace fs = experimental::filesystem;
	cout << (fs::current_path().string()) << "\n";
}
void mv_reiteration(string command1, string command2, string command3, string command4)
{
	char file1[1000] = "", file2[1000] = "";
	for (int i = 0; i < (int)command1.size(); i++)
	{
		file1[i] = command1[i];
	}
	for (int i = 0; i < (int)command2.size(); i++)
	{
		file2[i] = command2[i];
	}
	if (MoveFile(file1, file2))
	{
		cout << "файл '" << command3 << "' перемещён" << endl;
	}
	else
	{
		cout << "mv: " << "невозможно переместить '" << command3 << "' в '" << command4 << "': Нет такого файла или каталога" << endl;
	}
}
void cp_reiteration(string command1, string command2, string command3, string command4)
{
	char file1[1000] = "", file2[1000] = "";
	for (int i = 0; i < (int)command1.size(); i++)
	{
		file1[i] = command1[i];
	}
	for (int i = 0; i < (int)command2.size(); i++)
	{
		file2[i] = command2[i];
	}
	if (CopyFile(file1, file2, true))
	{
		cout << "файл '" << command3 << "' скопирован" << endl;
	}
	else
	{
		cout << "mv: " << "невозможно скопировать '" << command3 << "' в '" << command4 << "': Нет такого файла или каталога" << endl;
	}
}
void tail_reiteration1(int esc)
{
	do
	{
		string stroka;
		getline(cin, stroka);
		esc = _getch();
	} while (esc != 27);
	cout << endl;
}
void tail_reiteration2(string command1)
{
	ifstream tailfile;
	tailfile.open(home + command1);
	if (!tailfile.is_open())
	{
		cout << "tail: " << command1 << ": " << "Нет такого файла или каталога" << endl;
	}
	else
	{
		string strforcout;
		vector <string> strtail;
		int kolvo = 0;
		while (!tailfile.eof())
		{
			getline(tailfile, strforcout);
			strtail.push_back(strforcout);
			strforcout = "";
			kolvo++;
		}
		cout << "==> " << command1 << " <==" << endl;
		if (kolvo >= 10)
		{
			for (int i = kolvo - 10; i < kolvo - 1; i++)
			{
				cout << strtail[i];
			}
		}
		if (kolvo < 10)
		{
			for (int i = 0; i < kolvo; i++)
			{
				cout << strtail[i];
			}
		}
	}
	tailfile.close();
}
void tail_reiteration3(string command1, string command2)
{
	ifstream tailfile;
	ofstream coutfile;
	tailfile.open(home + command1);
	coutfile.open(home + command2);
	if (!tailfile.is_open())
	{
		coutfile << "tail: " << command1 << ": " << "Нет такого файла или каталога" << endl;
	}
	else
	{
		string strforcout;
		vector <string> strtail;
		int kolvo = 0;
		while (!tailfile.eof())
		{
			getline(tailfile, strforcout);
			strtail.push_back(strforcout);
			strforcout = "";
			kolvo++;
		}
		if (kolvo >= 10)
		{
			for (int i = kolvo - 10; i < kolvo - 1; i++)
			{
				coutfile << strtail[i];
			}
		}
		if (kolvo < 10)
		{
			for (int i = 0; i < kolvo; i++)
			{
				coutfile << strtail[i];
			}
		}
		tailfile.close();
		coutfile.close();
	}
}
void tail_reiteration4(string command1, string command2, string command3, string command4)
{
	ifstream tail;
	ofstream coutf;
	tail.open(home + command3);
	coutf.open(home + command4);
	if (!tail.is_open())
	{
		coutf << "tail: " << command3 << ": " << "Нет такого файла или каталога" << endl;
	}
	else
	{
		vector <string> str;
		string str1;
		int kolvo = 0;
		while (!tail.eof())
		{
			getline(tail, str1);
			str.push_back(str1);
			str1 = "";
			kolvo++;
		}
		if (command1 == "-c")
		{
			if (command2[0] == '+')//tail -c +H file
			{
				char v[100];
				int i = 0, chislo;
				for (i; i < (int)command2.size(); i++)
				{
					v[i] = command2[i];
				}
				v[i + 1] = '\0';
				chislo = atoi(v);
				int i2 = 0;
				while (chislo > (int)str[i2].size() + 1)
				{
					if (chislo > (int)str[i2].size() + 1)
					{
						chislo = chislo - ((int)str[i2].size() + 1);
						i2++;
					}
				}
				for (int i = chislo - 1; i < (int)str[i2].size() + 1; i++)
				{
					coutf << str[i2][i];
				}
				coutf << endl;
				for (int i = i2 + 1; i < kolvo; i++)
				{
					coutf << str[i] << endl;
				}
			}
			if ((command2[0] != '+') && (command2[0] != '-'))//tail -c H file
			{
				char v[100];
				int i = 0, chislo;
				for (i; i < (int)command2.size(); i++)
				{
					v[i] = command2[i];
				}
				v[i + 1] = '\0';
				chislo = atoi(v);
				int fullstr = kolvo - 1;
				while (chislo > (int)str[fullstr].size() + 1)
				{
					if (chislo >= (int)str[fullstr].size() + 1)
					{
						chislo = chislo - ((int)str[fullstr].size() + 1);
						fullstr -= 1;
					}
				}
				for (int i = ((int)str[fullstr].size() + 1) - chislo; i < (int)str[fullstr].size() + 1; i++)
				{
					coutf << str[fullstr][i];
				}
				coutf << endl;
				for (int i = fullstr + 1; i <= kolvo - 1; i++)
				{
					coutf << str[i] << endl;
				}
			}
		}
		if (command1 == "-n")
		{
			if (command2[0] == '+')//tail -n +H file
			{
				char v[100];
				int i = 0, chislo;
				for (i; i < (int)command2.size(); i++)
				{
					v[i] = command2[i];
				}
				v[i + 1] = '\0';
				chislo = atoi(v);
				if (chislo <= kolvo)
				{
					for (int i = chislo - 1; i < kolvo; i++)
					{
						coutf << str[i] << endl;
					}
				}
				if (chislo > kolvo)
				{
					cout;
				}
			}
			if ((command2[0] != '+') && (command2[0] != '-')) //tail -n H file
			{
				char v[100];
				int i = 0, chislo;
				for (i; i < (int)command2.size(); i++)
				{
					v[i] = command2[i];
				}
				v[i + 1] = '\0';
				chislo = atoi(v);
				if (chislo >= kolvo)
				{
					for (int i = 0; i < kolvo; i++)
					{
						coutf << str[i] << endl;
					}
				}
				if (chislo < kolvo)
				{
					for (int i = kolvo - chislo; i < kolvo; i++)
					{
						coutf << str[i] << endl;
					}
				}
			}
		}
		if (!((command1 == "-c") || (command1 == "-n")))
		{
			coutf << "tail: неверный ключ - " << command1 << endl;
			coutf << "Попробуйте 'man tail' для получения более подробного описания." << endl;
		}
	}
}
void file_reiteration(string command1)
{
	ifstream file;
	file.open(home + command1);
	if (!file.is_open())
	{
		cout << "file: " << command1 << ": " << "Нет такого файла или каталога" << endl;
	}
	else
	{
		char typefile[100] = "";
		int k = 0;
		for (int i = 0; i < (int)command1.size() - 1; i++)
		{
			if (command1[i] == '.')
			{
				for (int j = i + 1; j < (int)command1.size(); j++)
				{
					typefile[k] = command1[j];
					k++;
				}
			}
		}
		if (k == 2)
		{
			if ((typefile[0] == '7') && (typefile[1] == 'z'))
			{
				cout << "file: '" << command1 << "' " << ": Файл: Сжатая папка " << endl;
			}
			else
			{
				cout << "file: '" << command1 << "' " << ": Невозможно определить тип файла!" << endl;
			}
		}
		if (k == 3)
		{
			if ((typefile[0] == 't') && (typefile[1] == 'x') && (typefile[2] == 't'))
			{
				cout << "file: '" << command1 << "' " << ": Текстовый файл" << endl;
			}
			else if ((typefile[0] == 'j') && (typefile[1] == 'p') && (typefile[2] == 'g'))
			{
				cout << "file: '" << command1 << "' " << ": Файл: Изображения" << endl;
			}
			else if ((typefile[0] == 'o') && (typefile[1] == 'd') && (typefile[2] == 't'))
			{
				cout << "file: '" << command1 << "' " << ": Файл: Документ OpenOffice Word" << endl;
			}
			else if ((typefile[0] == 's') && (typefile[1] == 'l') && (typefile[2] == 'n'))
			{
				cout << "file: '" << command1 << "' " << ": Файл: Приложения Visual Studio" << endl;
			}
			else
			{
				cout << "file: '" << command1 << "' " << ": Невозможно определить тип файла!" << endl;
			}
		}
		if (k == 4)
		{
			if ((typefile[0] == 'd') && (typefile[1] == 'o') && (typefile[2] == 'c') && (typefile[2] == 'x'))
			{
				cout << "file: '" << command1 << "' " << ": Файл: Документ Microsoft Word" << endl;
			}
			else if ((typefile[0] == 'x') && (typefile[1] == 'l') && (typefile[2] == 's') && (typefile[2] == 'x'))
			{
				cout << "file: '" << command1 << "' " << ": Файл: Документ Microsoft Excel" << endl;
			}
			else if ((typefile[0] == 'p') && (typefile[1] == 'p') && (typefile[2] == 't') && (typefile[2] == 'x'))
			{
				cout << "file: '" << command1 << "' " << ": Файл: Презентация Microsoft PowerPoint " << endl;
			}
			else
			{
				cout << "file: '" << command1 << "' " << ": Невозможно определить тип файла!" << endl;
			}
		}
	}
	file.close();
}
void egrep_reiteration1()
{
	cout << "Использование: egrep [опции]... [шаблон] [файл]..." << endl;
	cout << "Попробуйте 'man egrep' для получения более подробного описания." << endl;
}
void egrep_reiteration2(string command1, string command2)
{
	string coutstr;
	ifstream file;
	file.open(home + command2);
	if (!file.is_open())
	{
		cout << "egrep: " << command2 << ": " << "Нет такого файла или каталога" << endl;
	}
	else
	{
		while (!file.eof())
		{
			getline(file, coutstr);
			size_t pos = coutstr.find(command1);
			if (pos != string::npos)
			{
				cout << command2 << ": " << coutstr << endl;
			}
		}
	}
	file.close();
}
void egrep_reiteration3(string command1, string command2)
{
	string coutstr;
	ifstream file;
	int num = 1;
	file.open(home + command2);
	if (!file.is_open())
	{
		cout << "egrep: " << command2 << ": " << "Нет такого файла или каталога" << endl;
	}
	else
	{
		while (!file.eof())
		{
			getline(file, coutstr);
			size_t pos = coutstr.find(command1);
			if (pos != string::npos)
			{
				cout << command2 << ":" << num << ":" << coutstr << endl;
			}
			num++;
		}
	}
	file.close();
}
void egrep_reiteration4(string command1, string command2)
{
	string coutstr;
	ifstream file;
	int num = 0;
	file.open(home + command2);
	if (!file.is_open())
	{
		cout << "egrep: " << command2 << ": " << "Нет такого файла или каталога" << endl;
	}
	else
	{
		while (!file.eof())
		{
			getline(file, coutstr);
			size_t pos = coutstr.find(command1);
			if (pos != string::npos)
			{
				num++;
			}
			cout << command2 << ":" << num << endl;
		}
	}
	file.close();
}
void cd_reiteration(string command1, const char *folderpath)
{
	DWORD dwFileAttributes = GetFileAttributesA(folderpath);
	if (dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY || dwFileAttributes == 22)
	{
		home += command1;
	}
	else
	{
		cout << "bash: cd: " << command1 << ": " << "Нет такого файла или каталога" << endl;
	}
}
void sort_reiteration(vector <string> &str)
{
	sort(str.begin(), str.end(), [](const string & p1, const string & p2)
		{
			bool result = p1 < p2;
			return result;
		}
	);
	for (int i = 0; i < (int)str.size(); i++)
	{
		cout << str[i] << endl;
	}
}
void ls_reiteration1(string directori)
{
	WIN32_FIND_DATA FindFileData;
	const char *z = new char[1000];
	z = directori.c_str();
	HANDLE hf = FindFirstFile(z, &FindFileData);
	setlocale(LC_ALL, "");
	if (INVALID_HANDLE_VALUE != hf)
	{
		do
		{
			cout << &FindFileData.cFileName[0] << endl;
		} while (FindNextFile(hf, &FindFileData) != 0);
		FindClose(hf);
	}
}
void ls_reiteration2(string directori)
{
	WIN32_FIND_DATA FindFileData;
	SYSTEMTIME st;
	const char *z = new char[1000];
	z = directori.c_str();
	HANDLE hf = FindFirstFile(z, &FindFileData);
	setlocale(LC_ALL, "");
	if (INVALID_HANDLE_VALUE != hf)
	{
		do
		{
			cout << &FindFileData.cFileName[0] << "\t\t";
			FileTimeToLocalFileTime(&FindFileData.ftLastWriteTime, &FindFileData.ftLastWriteTime);
			if (FileTimeToSystemTime(&FindFileData.ftLastWriteTime, &st) == TRUE)
			{
				cout << st.wDay << "-" << st.wMonth << "-" << st.wYear << " " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << "  ";
			}
			cout << FindFileData.nFileSizeLow << " байт \t";
			if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE)
			{
				cout << "АРХИВНЫЙ";
			}
			if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN)
			{
				cout << "СКРЫТЫЙ";
			}
			if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM)
			{
				cout << "СИСТЕМНЫЙ";
			}
			if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_READONLY)
			{
				cout << "ТОЛЬКО ДЛЯ ЧТЕНИЯ";
			}
			cout << endl;
		} while (FindNextFile(hf, &FindFileData) != 0);
		FindClose(hf);
	}
}
void ls_reiteration3(string directori)
{
	WIN32_FIND_DATA FindFileData;
	SYSTEMTIME st;
	const char *z = new char[1000];
	z = directori.c_str();
	HANDLE hf = FindFirstFile(z, &FindFileData);
	setlocale(LC_ALL, "");
	if (INVALID_HANDLE_VALUE != hf)
	{
		do
		{
			cout << &FindFileData.cFileName[0] << "\t\t";
			FileTimeToLocalFileTime(&FindFileData.ftLastWriteTime, &FindFileData.ftLastWriteTime);
			if (FileTimeToSystemTime(&FindFileData.ftLastWriteTime, &st) == TRUE)
			{
				cout << st.wDay << "-" << st.wMonth << "-" << st.wYear << " " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << "  ";
			}
			cout << endl;
		} while (FindNextFile(hf, &FindFileData) != 0);
		FindClose(hf);
	}
}
void ls_reiteration4(string directori)
{
	WIN32_FIND_DATA FindFileData;
	const char *z = new char[1000];
	z = directori.c_str();
	HANDLE hf = FindFirstFile(z, &FindFileData);
	setlocale(LC_ALL, "");
	if (INVALID_HANDLE_VALUE != hf)
	{
		do
		{
			experimental::filesystem::path dirWindows(home + &FindFileData.cFileName[0]);
			if (experimental::filesystem::is_directory(home + &FindFileData.cFileName[0]))
			{
				cout << &FindFileData.cFileName[0] << home[2] << endl;
			}
			else
			{
				cout << &FindFileData.cFileName[0] << endl;
			}
		} while (FindNextFile(hf, &FindFileData) != 0);
		FindClose(hf);
	}
}
// Функции команд:
void cat(int kolvo, vector <string> &command, int esc)
{
	switch (kolvo)
	{
	case 1:
	{
		do
		{
			string stroka;
			getline(cin, stroka);
			cout << stroka << endl;
			esc = _getch();
		} while (esc != 27);
		break;
	}
	case 2:
	{
		if (command[1][0] == '-')
		{
			if (command[1] == "-s") //cat -s
			{
				string stroka;
				vector <string> text;
				do
				{
					getline(cin, stroka);
					text.push_back(stroka);
					esc = _getch();
				} while (esc != 27);
				for (int i = 0; i < (int)text.size(); i++)
				{
					if (text[i].size() == 0 && text[i].size() == text[i + 1].size()) NULL;
					else cout << text[i] << endl;
				}
			}
			if (command[1] != "-s")
			{
				cout << "cat: неверный ключ - " << command[1] << endl;
				cout << "Попробуйте 'man cat' для получения более подробного описания." << endl;
			}
		}
		if (command[1][0] != '-') //cat file
		{
			cat_reiteration(command[1]);
		}
		break;
	}
	case 3:
	{
		if (command[1][0] == '-')
		{
			if (command[1] == "-s") //cat -s file
			{
				ifstream cats;
				cats.open(home + command[2]);
				if (!cats.is_open())
				{
					cout << command[0] << ": " << command[2] << ": " << "Нет такого файла или каталога" << endl;
				}
				else
				{
					vector <string> str;
					string str1;
					int i = 0, k;
					while (!cats.eof())
					{
						str1 = "";
						getline(cats, str1);
						str.push_back(str1);
					}
					k = str.size();
					while (k > 0)
					{
						if ((str[i].size() == 0) && (str[i].size() == str[i + 1].size()))
						{
							i++;
						}
						else
						{
							cout << str[i] << endl;
							i++;
						}
						k--;
					}
				}
				cats.close();
			}
			if (command[1] != "-s")
			{
				cout << "cat: неверный ключ - " << command[1] << endl;
				cout << "Попробуйте 'man cat' для получения более подробного описания." << endl;
			}
		}
		if (command[1][0] != '-')
		{
			if (command[1] == ">") // cat > file
			{
				ofstream cat;
				cat.open(home + command[2]);
				string stroka;
				vector <string> vecstroka;
				do
				{
					getline(cin, stroka);
					vecstroka.push_back(stroka);
					esc = _getch();
				} while (esc != 27);
				if (cat.is_open())
				{
					for (int i = 0; i < (int)vecstroka.size(); i++)
					{
						cat << vecstroka[i] << endl;
					}
				}
				cat.close();
			}
			if (command[1] == "<") //cat < file
			{
				ifstream catfile;
				catfile.open(home + command[2]);
				if (!catfile.is_open())
				{
					cout << command[0] << ": " << command[2] << ": " << "Нет такого файла или каталога" << endl;
				}
				else
				{
					string strforcout;
					while (!catfile.eof())
					{
						strforcout = "";
						getline(catfile, strforcout);
						cout << strforcout << endl;
					}
					catfile.close();
				}
			}
			if ((command[1] != ">") && (command[1] != "<")) //cat file1 file2
			{
				cat_reiteration(command[1]);
				cat_reiteration(command[2]);
			}
		}
		break;
	}
	case 4:
	{
		if (command[1][0] == '-')
		{
			if (command[1] == "-s")
			{
				if (command[2] == ">")//cat -s > file
				{
					string stroka;
					vector <string> text2, text3;
					do
					{
						getline(cin, stroka);
						text2.push_back(stroka);
						esc = _getch();
					} while (esc != 27);
					for (int i = 0; i < (int)text2.size(); i++)
					{
						if (text2[i].size() == 0 && text2[i].size() == text2[i + 1].size()) NULL;
						else text3.push_back(text2[i]);
					}
					ofstream cat;
					cat.open(home + command[3]);
					if (!cat.is_open())
					{
						cout << command[0] << ": " << command[3] << ": " << "Нет такого файла или каталога" << endl;
					}
					else
					{
						for (int i = 0; i < (int)text3.size(); i++)
						{
							cat << text3[i] << endl;
						}
					}
					cat.close();
				}
				if (command[2] == "<") //cat -s < file
				{
					ifstream cats1;
					cats1.open(home + command[3]);
					if (!cats1.is_open())
					{
						cout << command[0] << ": " << command[3] << ": " << "Нет такого файла или каталога" << endl;
					}
					else
					{
						vector <string> str2;
						string str3;
						int i = 0, k1;
						while (!cats1.eof())
						{
							str3 = "";
							getline(cats1, str3);
							str2.push_back(str3);
						}
						k1 = str2.size();
						for (int i = 0; i < (k1 - 1); i++)
						{
							if ((str2[i].size() == 0) && (str2[i].size() == str2[i + 1].size()))
							{
								cout;
							}
							else
							{
								cout << str2[i] << endl;
							}
						}
					}
					cats1.close();
				}
				if ((command[2] != ">") && (command[2] != "<")) //cat -s file1 file2
				{
					ifstream cats1, cats2;
					cats1.open(home + command[2]);
					cats2.open(home + command[3]);
					if (!cats1.is_open())
					{
						cout << command[0] << ": " << command[2] << ": " << "Нет такого файла или каталога" << endl;
					}
					if (!cats2.is_open())
					{
						cout << command[0] << ": " << command[3] << ": " << "Нет такого файла или каталога" << endl;
					}
					if ((cats1.is_open()) && (cats2.is_open()))
					{
						vector <string> str1, str2;
						string str11, str22;
						int i1 = 0, i2 = 0, k1, k2;
						while (!cats1.eof())
						{
							str11 = "";
							getline(cats1, str11);
							str1.push_back(str11);
						}
						while (!cats2.eof())
						{
							str22 = "";
							getline(cats2, str22);
							str2.push_back(str22);
						}
						k1 = str1.size();
						k2 = str2.size();
						while (k1 > 0)
						{
							if ((str1[i1].size() == 0) && (str1[i1].size() == str1[i1 + 1].size()))
							{
								i1++;
							}
							else
							{
								cout << str1[i1] << endl;
								i1++;
							}
							k1--;
						}
						while (k2 > 0)
						{
							if ((str1[i2].size() == 0) && (str1[i2].size() == str1[i2 + 1].size()))
							{
								i2++;
							}
							else
							{
								cout << str1[i2] << endl;
								i2++;
							}
							k2--;
						}
					}
					cats1.close();
					cats2.close();
				}
			}
			if (command[1] != "-s")
			{
				cout << "cat: неверный ключ - " << command[1] << endl;
				cout << "Попробуйте 'man cat' для получения более подробного описания." << endl;
			}
		}
		if (command[1][0] != '-')// cat file1 > file2
		{
			if (command[2] == ">")
			{
				ifstream catfile1;
				ofstream catfile2;
				catfile1.open(home + command[1]);
				catfile2.open(home + command[3]);
				if (!catfile1.is_open())
				{
					cout << command[0] << ": " << command[1] << ": " << "Нет такого файла или каталога" << endl;
				}
				else
				{
					vector <string> strforcout1;
					string strforcout;
					while (!catfile1.eof())
					{
						strforcout = "";
						getline(catfile1, strforcout);
						strforcout1.push_back(strforcout);
					}
					if (!catfile2.is_open())
					{
						cout << command[0] << ": " << command[3] << ": " << "Нет такого файла иди каталога" << endl;
					}
					else
					{
						for (int i = 0; i < (int)strforcout1.size(); i++)
						{
							catfile2 << strforcout1[i] << endl;
						}
					}
				}
				catfile1.close();
				catfile2.close();
			}
			if (command[2] == "<") //cat file1 < file2
			{
				ifstream catfile2;
				ofstream catfile1;
				catfile1.open(home + command[1]);
				catfile2.open(home + command[3]);
				if (!catfile2.is_open())
				{
					cout << command[0] << ": " << command[3] << ": " << "Нет такого файла или каталога" << endl;
				}
				else if (!catfile1.is_open())
				{
					cout << command[0] << ": " << command[1] << ": " << "Нет такого файла или каталога" << endl;
				}
				else if ((catfile1.is_open()) && (catfile2.is_open()))
				{
					vector <string> strforcout1;
					string strforcout;
					while (!catfile2.eof())
					{
						strforcout = "";
						getline(catfile2, strforcout);
						strforcout1.push_back(strforcout);
					}
					for (int i = 0; i < (int)strforcout1.size(); i++)
					{
						cout << strforcout1[i] << endl;
						catfile1 << strforcout1[i] << endl;
					}
				}
				catfile1.close();
				catfile2.close();
			}
			if (!((command[2] == ">") || (command[2] == "<")))
			{
				cout << "cat: недопустимое значение '" << command[2] << "'" << endl;
				cout << "Попробуйте 'man cat' для получения более подробного описания." << endl;
			}
		}
		break;
	}
	case 5:
	{
		if (command[1] == "-s") // cat -s file1 > file2
		{
			if (command[3] == ">")
			{
				ifstream catsfile1;
				ofstream catsfile2;
				catsfile1.open(home + command[2]);
				catsfile2.open(home + command[4]);
				if (!catsfile1.is_open())
				{
					cout << command[0] << ": " << command[2] << ": " << "Нет такого файла или каталога" << endl;
				}
				else
				{
					vector <string> str;
					string str1;
					int i = 0, k;
					while (!catsfile1.eof())
					{
						str1 = "";
						getline(catsfile1, str1);
						str.push_back(str1);
					}
					k = str.size();
					if (!catsfile2.is_open())
					{
						cout << command[0] << ": " << command[4] << ": " << "Нет такого файла или каталога" << endl;
					}
					else
					{
						while (k > 0)
						{
							if ((str[i].size() == 0) && (str[i].size() == str[i + 1].size()))
							{
								i++;
							}
							else
							{
								catsfile2 << str[i] << endl;
								i++;
							}
							k--;
						}
					}
				}
				catsfile1.close();
				catsfile2.close();
			}
			if (command[4] == "<") // cat -s file1 < file2
			{
				ifstream catsfile2;
				ofstream catsfile1;
				catsfile1.open(home + command[2]);
				catsfile2.open(home + command[4]);
				if (!catsfile2.is_open())
				{
					cout << command[0] << ": " << command[4] << ": " << "Нет такого файла или каталога" << endl;
				}
				else if (!catsfile1.is_open())
				{
					cout << command[0] << ": " << command[2] << ": " << "Нет такого файла или каталога" << endl;
				}
				else if ((catsfile1.is_open()) && (catsfile2.is_open()))
				{
					vector <string> str;
					string str1;
					int i = 0, k;
					while (!catsfile1.eof())
					{
						str1 = "";
						getline(catsfile2, str1);
						str.push_back(str1);
					}
					k = str.size();
					while (k > 0)
					{
						if ((str[i].size() == 0) && (str[i].size() == str[i + 1].size()))
						{
							i++;
						}
						else
						{
							cout << str[i] << endl;
							catsfile1 << str[i] << endl;
							i++;
						}
						k--;
					}
				}
				catsfile1.close();
				catsfile2.close();
			}
		}
		break;
	}
	default:
	{
		cout << "cat: недопустимое значение '" << command[5] << "' " << endl;
		cout << "Попробуйте 'man cat' для получения более подробного описания." << endl;
	}
	}
}
void comm(int kolvo, vector <string> &command)
{
	switch (kolvo)
	{
	case 1:
	{
		cout << "comm: пропущен операнд" << endl;
		cout << "Попробуйте 'man comm' для получения более подробного описания." << endl;
		break;
	}
	case 2:
	{
		//comm ...
		if (command[1][0] == '-')
		{
			if ((command[1] == "-12") || (command[1] == "-13") || (command[1] == "-23") || (command[1] == "-1") || (command[1] == "-2") || (command[1] == "-3") || (command[1] == "-12") || (command[1] == "-21") || (command[1] == "-31") || (command[1] == "-32"))
			{
				cout << "comm: пропущен операнд" << endl;
				cout << "Попробуйте 'man comm' для получения более подробного описания." << endl;
			}
			if (!((command[1] == "-12") || (command[1] == "-13") || (command[1] == "-23") || (command[1] == "-1") || (command[1] == "-2") || (command[1] == "-3") || (command[1] == "-12") || (command[1] == "-21") || (command[1] == "-31") || (command[1] == "-32")))
			{
				cout << "comm: неверный ключ - " << command[1] << endl;
				cout << "Попробуйте 'man comm' для получения более подробного описания." << endl;
			}
		}
		if (command[1][0] != '-')
		{
			cout << "comm: пропущен операнд после '" << command[1] << "'" << endl;
			cout << "Попробуйте 'man comm' для получения более подробного описания." << endl;
		}
		break;
	}
	case 3:
	{
		if (command[1][0] == '-')//comm -key file1
		{
			cout << command[0] << "пропущен операнд после '" << command[2] << "'" << endl;
			cout << "Попробуйте 'man comm' для получения более подробного описания." << endl;
		}
		if (command[1][0] != '-')//comm file1 file2
		{
			ifstream com2, com3;
			com2.open(home + command[1]);
			com3.open(home + command[2]);
			if (!com2.is_open())
			{
				cout << command[0] << ": " << command[1] << ": " << "Нет такого файла или каталога" << endl;
			}
			else if (!com3.is_open())
			{
				cout << command[0] << ": " << command[2] << ": " << "Нет такого файла или каталога" << endl;
			}
			else if ((com2.is_open()) && (com3.is_open()))
			{
				vector <string> str2, str3;
				string str22, str33;
				while (!com2.eof())
				{
					getline(com2, str22);
					str2.push_back(str22);;
				}
				while (!com3.eof())
				{
					getline(com3, str33);
					str3.push_back(str33);
				}
				int sizestr2 = str2.size(), sizestr3 = str3.size();
				for (int j = 0; j < sizestr2; j++)
				{
					int k = 0;
					for (int i = 0; i < sizestr3; i++)
					{
						if (str2[j] == str3[i])
						{
							k++;
						}
					}
					if (k == 0)
					{
						cout << str2[j] << endl;
					}
				}
				for (int i = 0; i < sizestr3; i++)
				{
					int k = 0;
					for (int j = 0; j < sizestr2; j++)
					{
						if (str3[i] == str2[j])
						{
							k++;
						}
					}
					if (k == 0)
					{
						cout << "\t" << str3[i] << endl;
					}
				}
				for (int i = 0; i < sizestr3; i++)
				{
					int k = 0;
					for (int j = 0; j < sizestr2; j++)
					{
						if (str3[i] == str2[j])
						{
							k++;
						}
					}
					if (k != 0)
					{
						cout << "\t" << "\t" << str3[i] << endl;
					}
					else
					{
						cout;
					}
				}
			}
			com2.close();
			com3.close();
		}
		break;
	}
	case 4:
	{
		// comm -key file1 file2
		ifstream com2, com3;
		com2.open(home + command[2]);
		com3.open(home + command[3]);
		if (!com2.is_open())
		{
			cout << command[0] << ": " << command[2] << ": " << "Нет такого файла или каталога" << endl;
		}
		if (!com3.is_open())
		{
			cout << command[0] << ": " << command[3] << ": " << "Нет такого файла или каталога" << endl;
		}
		if ((com2.is_open()) && (com3.is_open()))
		{
			vector <string> str2, str3;
			string str22, str33;
			while (!com2.eof())
			{
				getline(com2, str22);
				str2.push_back(str22);;
			}
			while (!com3.eof())
			{
				getline(com3, str33);
				str3.push_back(str33);
			}
			int sizestr2 = str2.size(), sizestr3 = str3.size();
			if (command[1][0] == '-')
			{
				if (command[1] == "-1") // comm -1 file1 file2
				{
					comm1(sizestr2, sizestr3, str2, str3);
				}
				else if (command[1] == "-2")// comm -2 file1 file2
				{
					comm2(sizestr2, sizestr3, str2, str3);
				}
				else if (command[1] == "-3")// comm -3 file1 file2
				{
					comm3(sizestr2, sizestr3, str2, str3);
				}
				else if (command[1] == "-12")// comm -12 file1 file2
				{
					comm12(sizestr2, sizestr3, str2, str3);
				}
				else if (command[1] == "-13")// comm -13 file1 file2
				{
					comm13(sizestr2, sizestr3, str2, str3);
				}
				else if (command[1] == "-23")// comm -23 file1 file2
				{
					comm23(sizestr2, sizestr3, str2, str3);
				}
				else
				{
					cout << "comm: неверный ключ - " << command[1] << endl;
					cout << "Попробуйте 'man comm' для получения более подробного описания." << endl;
				}
			}
			com2.close();
			com3.close();
		}
		break;
	}
	case 5:
	{
		if ((command[1][0] != '-') && (command[2][0] != '-')) //comm file1 file2 > file3
		{
			ifstream com2, com3;
			ofstream com4;
			com2.open(home + command[1]);
			com3.open(home + command[2]);
			com4.open(home + command[4]);
			if (!com2.is_open())
			{
				cout << command[0] << ": " << command[1] << ": " << "Нет такого файла или каталога" << endl;
			}
			if (!com3.is_open())
			{
				cout << command[0] << ": " << command[2] << ": " << "Нет такого файла или каталога" << endl;
			}
			if ((com2.is_open()) && (com3.is_open()))
			{
				vector <string> str2, str3;
				string str22, str33;
				while (!com2.eof())
				{
					getline(com2, str22);
					str2.push_back(str22);;
				}
				while (!com3.eof())
				{
					getline(com3, str33);
					str3.push_back(str33);
				}
				int sizestr2 = str2.size(), sizestr3 = str3.size();
				if (command[3] == ">")
				{
					for (int j = 0; j < sizestr2; j++)
					{
						int k = 0;
						for (int i = 0; i < sizestr3; i++)
						{
							if (str2[j] == str3[i])
							{
								k++;
							}
						}
						if (k == 0)
						{
							com4 << str2[j] << endl;
						}
					}
					for (int i = 0; i < sizestr3; i++)
					{
						int k = 0;
						for (int j = 0; j < sizestr2; j++)
						{
							if (str3[i] == str2[j])
							{
								k++;
							}
						}
						if (k == 0)
						{
							com4 << "\t" << str3[i] << endl;
						}
					}
					for (int i = 0; i < sizestr3; i++)
					{
						int k = 0;
						for (int j = 0; j < sizestr2; j++)
						{
							if (str3[i] == str2[j])
							{
								k++;
							}
						}
						if (k != 0)
						{
							com4 << "\t" << "\t" << str3[i] << endl;
						}
						else
						{
							com4;
						}
					}
				}
				if (command[3] != ">")
				{
					cout << "comm: лишний операнд '" << command[3] << "' " << endl;
					cout << "Попробуйте 'man comm' для получения более подробного описания." << endl;
				}
			}
			com2.close();
			com3.close();
			com4.close();
		}
		if ((command[1][0] == '-') && (command[2][0] == '-')) // comm -key1 -key2 file1 file2
		{
			ifstream com2, com3;
			com2.open(home + command[3]);
			com3.open(home + command[4]);
			if (!com2.is_open())
			{
				cout << command[0] << ": " << command[3] << ": " << "Нет такого файла или каталога" << endl;
			}
			if (!com3.is_open())
			{
				cout << command[0] << ": " << command[4] << ": " << "Нет такого файла или каталога" << endl;
			}
			if ((com2.is_open()) && (com3.is_open()))
			{
				vector <string> str2, str3;
				string str22, str33;
				while (!com2.eof())
				{
					getline(com2, str22);
					str2.push_back(str22);;
				}
				while (!com3.eof())
				{
					getline(com3, str33);
					str3.push_back(str33);
				}
				int sizestr2 = str2.size(), sizestr3 = str3.size();
				if ((command[1] == "-1") && (command[2] == "-2"))
				{
					comm12(sizestr2, sizestr3, str2, str3);
				}
				else if ((command[1] == "-1") && (command[2] == "-3"))
				{
					comm13(sizestr2, sizestr3, str2, str3);
				}
				else if ((command[1] == "-2") && (command[2] == "-3"))
				{
					comm23(sizestr2, sizestr3, str2, str3);
				}
				else
				{
					cout << "comm: неверный ключ" << endl;
					cout << "Попробуйте 'man comm' для получения более подробного описания." << endl;
				}
			}
			com2.close();
			com3.close();
		}
		if (((command[1][0] != '-') && (command[2][0] == '-')) || ((command[1][0] == '-') && (command[2][0] != '-')))
		{
			cout << "comm: лишний операнд '" << command[4] << "' " << endl;
			cout << "Попробуйте 'man comm' для получения более подробного описания." << endl;
		}
		break;
	}
	default:
	{
		cout << "comm: лишний операнд '" << command[5] << "' " << endl;
		cout << "Попробуйте 'man comm' для получения более подробного описания." << endl;
	}
	}
}
void wc(int kolvo, vector <string> &command, int esc)
{
	switch (kolvo)
	{
	case 1:
	{
		tail_reiteration1(esc);  //wc
		break;
	}
	case 2:
	{
		vector <string> filestrok; // wc file
		ifstream file;
		file.open(home + command[1]);
		string str;
		int kolvostrok = 0;
		while (!file.eof())
		{
			getline(file, str);
			filestrok.push_back(str);
			str = "";
			kolvostrok++;
		}
		int kolvosymbols = 0;
		for (int i = 0; i < kolvostrok; i++)
		{
			kolvosymbols += (int)filestrok[i].size() + 1;
		}
		vector <string> slov;
		string word;
		int KolvoSlov = 0;
		for (int i = 0; i < (int)filestrok.size(); i++)
		{
			istringstream iss(filestrok[i]);
			while (iss >> word)
			{
				slov.push_back(word);
				KolvoSlov++;
			}
		}
		cout << kolvostrok << " " << KolvoSlov << " " << kolvosymbols << " " << command[1] << endl;
		file.close();
		break;
	}
	case 3:
	{
		if (command[1] == "-l") // wc -l file
		{
			vector <string> filestrok;
			ifstream file;
			file.open(home + command[2]);
			string str;
			int kolvostrok = 0;
			while (!file.eof())
			{
				getline(file, str);
				filestrok.push_back(str);
				str = "";
				kolvostrok++;
			}
			cout << kolvostrok << " " << command[2] << endl;
			file.close();
		}
		if (command[1] == "-w")// wc -w file
		{
			vector <string> filestrok;
			ifstream file;
			file.open(home + command[2]);
			string str;
			while (!file.eof())
			{
				getline(file, str);
				filestrok.push_back(str);
				str = "";
			}
			vector <string> slov;
			string word;
			int KolvoSlov = 0;
			for (int i = 0; i < (int)filestrok.size(); i++)
			{
				istringstream iss(filestrok[i]);
				while (iss >> word)
				{
					slov.push_back(word);
					KolvoSlov++;
				}
			}
			cout << KolvoSlov << " " << command[2] << endl;
			file.close();
		}
		if (command[1] == "-c")// wc -c file
		{
			vector <string> filestrok;
			ifstream file;
			file.open(home + command[2]);
			string str;
			int kolvostrok = 0;
			while (!file.eof())
			{
				getline(file, str);
				filestrok.push_back(str);
				str = "";
				kolvostrok++;
			}
			int kolvosymbols = 0;
			for (int i = 0; i < kolvostrok; i++)
			{
				kolvosymbols += (int)filestrok[i].size() + 1;
			}
			cout << kolvosymbols << " " << command[2] << endl;
			file.close();
		}
		break;
	}
	case 4:
	{
		ofstream file2;  // wc file1 > file2
		file2.open(home + command[3]);
		vector <string> filestrok;
		ifstream file;
		file.open(home + command[1]);
		string str;
		int kolvostrok = 0;
		while (!file.eof())
		{
			getline(file, str);
			filestrok.push_back(str);
			str = "";
			kolvostrok++;
		}
		int kolvosymbols = 0;
		for (int i = 0; i < kolvostrok; i++)
		{
			kolvosymbols += (int)filestrok[i].size() + 1;
		}
		vector <string> slov;
		string word;
		int KolvoSlov = 0;
		for (int i = 0; i < (int)filestrok.size(); i++)
		{
			istringstream iss(filestrok[i]);
			while (iss >> word)
			{
				slov.push_back(word);
				KolvoSlov++;
			}
		}
		file2 << kolvostrok << " " << KolvoSlov << " " << kolvosymbols << " " << command[1] << endl;
		file.close();
		file2.close();
		break;
	}
	case 5:
	{
		// wc -key file1 > file2
		ofstream file2;
		file2.open(home + command[4]);
		if (command[1] == "-l") // wc -l file
		{
			vector <string> filestrok;
			ifstream file;
			file.open(home + command[2]);
			string str;
			int kolvostrok = 0;
			while (!file.eof())
			{
				getline(file, str);
				filestrok.push_back(str);
				str = "";
				kolvostrok++;
			}
			file2 << kolvostrok << " " << command[2] << endl;
			file.close();
		}
		if (command[1] == "-w")// wc -w file
		{
			vector <string> filestrok;
			ifstream file;
			file.open(home + command[2]);
			string str;
			while (!file.eof())
			{
				getline(file, str);
				filestrok.push_back(str);
				str = "";
			}
			vector <string> slov;
			string word;
			int KolvoSlov = 0;
			for (int i = 0; i < (int)filestrok.size(); i++)
			{
				istringstream iss(filestrok[i]);
				while (iss >> word)
				{
					slov.push_back(word);
					KolvoSlov++;
				}
			}
			file2 << KolvoSlov << " " << command[2] << endl;
			file.close();
		}
		if (command[1] == "-c")// wc -c file
		{
			vector <string> filestrok;
			ifstream file;
			file.open(home + command[2]);
			string str;
			int kolvostrok = 0;
			while (!file.eof())
			{
				getline(file, str);
				filestrok.push_back(str);
				str = "";
				kolvostrok++;
			}
			int kolvosymbols = 0;
			for (int i = 0; i < kolvostrok; i++)
			{
				kolvosymbols += (int)filestrok[i].size() + 1;
			}
			file2 << kolvosymbols << " " << command[2] << endl;
			file.close();
		}
		file2.close();
	}
	default:
	{
		cout << command[0] << ": " << command[5] << ": " << "Нет такого файла или каталога" << endl;
	}
	}
}
void pwd(int kolvo, vector <string> &command)
{
	switch (kolvo)
	{
	case 1:
	{
		// pwd
		pwd_reiteration();
		break;
	}
	case 2:
	{
		//pwd ...
		pwd_reiteration();
		break;
	}
	case 3:
	{
		if (command[1] == ">") //pwd > file
		{
			ofstream pwdfile;
			pwdfile.open(home + command[2]);
			namespace fs = experimental::filesystem;
			pwdfile << (fs::current_path().string());
		}
		if (command[1] != ">") // pwd ... ...
		{
			pwd_reiteration();
			break;
		}
	}
	default:
	{
		pwd_reiteration();
	}
	}
}
void mv(int kolvo, vector <string> &command)
{
	switch (kolvo)
	{
	case 1:
	{
		// mv
		cout << "mv: пропущен операнд, задающий файл!" << endl;
		cout << "Попробуйте 'man mv' для получения более подробного описания." << endl;
		break;
	}
	case 2:
	{
		if (command[1][0] == '-') //mv -key
		{
			if (command[1] == "-i")
			{
				cout << "mv: пропущен операнд, задающий файл!" << endl;
				cout << "Попробуйте 'man mv' для получения более подробного описания." << endl;
			}
			if (command[1] != "-i")
			{
				cout << "mv: неверный ключ - " << command[1] << endl;
				cout << "Попробуйте 'man mv' для получения более подробного описания." << endl;
			}
		}
		if (command[1][0] != '-') //mv file
		{
			cout << "mv: после '" << command[1] << "' пропущен операнд, задающий целевой каталог!" << endl;
			cout << "Попробуйте 'man mv' для получения более подробного описания." << endl;
		}
		break;
	}
	case 3:
	{
		if (command[1][0] == '-')
		{
			if (command[1] == "-i") //mv -i file1
			{
				cout << command[0] << " пропущен операнд после '" << command[2] << "'" << endl;
				cout << "Попробуйте 'man mv' для получения более подробного описания." << endl;
			}
			else if (command[1] != "-i") //mv -key file1
			{
				cout << command[0] << " неверный ключ - " << command[1] << endl;
				cout << "Попробуйте 'man mv' для получения более подробного описания." << endl;
			}
		}
		if (command[1][0] != '-') // mv file1 katalog
		{
			mv_reiteration(home + command[1], home + command[2], command[1], command[2]);
		}
		break;
	}
	case 4:
	{
		//mv -i file1 katalog
		if (command[1] == "-i")
		{
			char mv_i;
			cout << "Переместить файл '" << command[2] << "' ? ";
			cin >> mv_i;
			if (mv_i == 'y ')
			{
				mv_reiteration(home + command[2], home + command[3], command[2], command[3]);
			}
			else
			{
				cout;

			}
		}
		if (command[1] != "-i")
		{
			cout << command[0] << " неверный ключ - " << command[1] << endl;
			cout << "Попробуйте 'man mv' для получения более подробного описания." << endl;
		}
		break;
	}
	default:
	{
		cout << "mv: указанная цель '" << command[kolvo - 1] << "' не является каталогом" << endl;
	}
	}
}
void cd(int kolvo, vector <string> &command)
{
	switch (kolvo)
	{
	case 1:
	{
		// сd
		cout << "cd: пропущена директория!" << endl;
		cout << "Попробуйте 'man cd' для получения более подробного описания." << endl;
		break;
	}
	case 2:
	{
		// cd directori
		const char *z = new char[1000];
		z = command[1].c_str();
		cd_reiteration(command[1], z);
		break;
	}
	case 3:
	{
		if (command[1] == ">")  // cd > directori
		{
			const char *z = new char[1000];
			z = command[2].c_str();
			DWORD dwFileAttributes = GetFileAttributesA(z);
			if (dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY || dwFileAttributes == 22)
			{
				cout << "bash: " << command[2] << " Это каталог" << endl;
			}
			else
			{
				cout << "bash: cd: " << command[2] << ": " << "Нет такого файла или каталога" << endl;
				cout << "Попробуйте 'man cd' для получения более подробного описания." << endl;
			}
		}
		else
		{
			const char *z = new char[1000];
			z = command[1].c_str();
			cd_reiteration(command[1], z);
		}
		break;
	}
	default:
	{
		const char *z = new char[1000];
		z = command[1].c_str();
		cd_reiteration(command[1], z);
	}
	}
}
void ls(int kolvo, vector <string> &command)
{
	switch (kolvo)
	{
	case 1:
	{
		string home1 = home + "*"; // ls
		ls_reiteration1(home1);
		break;
	}
	case 2:
	{
		if (command[1][0] == '-')
		{
			string home1 = home + "*";
			if (command[1] == "-l") // ls -l
			{
				ls_reiteration2(home1);
			}
			else if (command[1] == "-c") // ls - c
			{
				ls_reiteration3(home1);
			}
			else if (command[1] == "-p") // ls - p
			{
				ls_reiteration4(home1);
			}
			else
			{
				cout << "ls: неверный ключ - " << command[1] << endl;
				cout << "Попробуйте 'man ls' для получения более подробного описания." << endl;
			}
		}
		else // ls directori
		{
			string home1 = home + command[1] + "*";
			ls_reiteration1(home1);
		}
		break;
	}
	case 3:
	{
		string home1 = home + command[2] + "*";
		if (command[1][0] == '-')
		{
			if (command[1] == "-l") // ls -l directori
			{
				ls_reiteration2(home1);
			}
			else if (command[1] == "-c") // ls - c directori
			{
				ls_reiteration3(home1);
			}
			else if (command[1] == "-p") // ls - p directori
			{
				ls_reiteration4(home1);
			}
			else
			{
				cout << "ls: неверный ключ - " << command[1] << endl;
				cout << "Попробуйте 'man ls' для получения более подробного описания." << endl;
			}
		}
		if (command[1][0] != '-')
		{
			if (command[1] == ">") //ls > file
			{
				ofstream file;
				file.open(home + command[2]);
				WIN32_FIND_DATA FindFileData;
				const char *z = new char[1000];
				z = home.c_str();
				HANDLE hf = FindFirstFile(z, &FindFileData);
				setlocale(LC_ALL, "");
				if (INVALID_HANDLE_VALUE != hf)
				{
					do
					{
						file << &FindFileData.cFileName[0] << endl;
					} while (FindNextFile(hf, &FindFileData) != 0);
					FindClose(hf);
				}
				file.close();
			}
			if (command[1] == "<") //ls < directori
			{
				ls_reiteration1(home1);
			}
		}
		break;
	}
	case 4:
	{
		if (command[1][0] == '-')
		{
			if (command[2] == ">")
			{
				ofstream files;
				files.open(command[3]);
				string home1 = home + "*";
				WIN32_FIND_DATA FindFileData;
				const char *z = new char[1000];
				z = home1.c_str();
				HANDLE hf = FindFirstFile(z, &FindFileData);
				setlocale(LC_ALL, "");
				if (command[1] == "-l") // ls -l > file
				{
					SYSTEMTIME st;
					if (INVALID_HANDLE_VALUE != hf)
					{
						do
						{
							files << &FindFileData.cFileName[0] << "\t\t";
							FileTimeToLocalFileTime(&FindFileData.ftLastWriteTime, &FindFileData.ftLastWriteTime);
							if (FileTimeToSystemTime(&FindFileData.ftLastWriteTime, &st) == TRUE)
							{
								files << st.wDay << "-" << st.wMonth << "-" << st.wYear << " " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << "  ";
							}
							files << FindFileData.nFileSizeLow << " байт \t";
							if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE)
							{
								files << "АРХИВНЫЙ";
							}
							if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN)
							{
								files << "СКРЫТЫЙ";
							}
							if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM)
							{
								files << "СИСТЕМНЫЙ";
							}
							if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_READONLY)
							{
								files << "ТОЛЬКО ДЛЯ ЧТЕНИЯ";
							}
							files << endl;
						} while (FindNextFile(hf, &FindFileData) != 0);
						FindClose(hf);
					}
				}
				else if (command[1] == "-c") // ls - c > file
				{
					SYSTEMTIME st;
					if (INVALID_HANDLE_VALUE != hf)
					{
						do
						{
							files << &FindFileData.cFileName[0] << "\t\t";
							FileTimeToLocalFileTime(&FindFileData.ftLastWriteTime, &FindFileData.ftLastWriteTime);
							if (FileTimeToSystemTime(&FindFileData.ftLastWriteTime, &st) == TRUE)
							{
								files << st.wDay << "-" << st.wMonth << "-" << st.wYear << " " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << "  ";
							}
							files << endl;
						} while (FindNextFile(hf, &FindFileData) != 0);
						FindClose(hf);
					}
				}
				else if (command[1] == "-p") // ls - p > file
				{
					if (INVALID_HANDLE_VALUE != hf)
					{
						do
						{
							experimental::filesystem::path dirWindows(home + &FindFileData.cFileName[0]);
							if (experimental::filesystem::is_directory(home + &FindFileData.cFileName[0]))
							{
								files << &FindFileData.cFileName[0] << home[2] << endl;
							}
							else
							{
								files << &FindFileData.cFileName[0] << endl;
							}
						} while (FindNextFile(hf, &FindFileData) != 0);
						FindClose(hf);
					}
				}
				else
				{
					cout << "ls: неверный ключ - " << command[1] << endl;
					cout << "Попробуйте 'man ls' для получения более подробного описания." << endl;
				}
				files.close();
			}
		}
		if (command[1][0] != '-') // ls directori > file
		{
			ofstream files;
			files.open(command[3]);
			WIN32_FIND_DATA FindFileData;
			string home1 = home + command[1] + "*";
			const char *z = new char[1000];
			z = home1.c_str();
			HANDLE hf = FindFirstFile(z, &FindFileData);
			setlocale(LC_ALL, "");
			if (INVALID_HANDLE_VALUE != hf)
			{
				do
				{
					files << &FindFileData.cFileName[0] << endl;
				} while (FindNextFile(hf, &FindFileData) != 0);
				FindClose(hf);
			}
			files.close();
		}
	}
	default:
	{
		cout << "ls: Слишком много слов!" << endl;
		cout << "Выполнение команды ls для текущей директории." << endl;
		ls_reiteration1(home);
	}
	}
}
void cp(int kolvo, vector <string> &command)
{
	switch (kolvo)
	{
	case 1:
	{
		// cp
		cout << "cp: пропущен операнд, задающий файл!" << endl;
		cout << "Попробуйте 'man cp' для получения более подробного описания." << endl;
		break;
	}
	case 2:
	{
		if (command[1][0] == '-') //cp -key
		{
			if (command[1] == "-i")
			{
				cout << "cp: пропущен операнд, задающий файл!" << endl;
				cout << "Попробуйте 'man cp' для получения более подробного описания." << endl;
			}
			if (command[1] != "-i")
			{
				cout << "cp: неверный ключ - " << command[1] << endl;
				cout << "Попробуйте 'man cp' для получения более подробного описания." << endl;
			}
		}
		if (command[1][0] != '-') //cp file
		{
			cout << "cp: после '" << command[1] << "' пропущен операнд, задающий целевой каталог!" << endl;
			cout << "Попробуйте 'man cp' для получения более подробного описания." << endl;
		}
		break;
	}
	case 3:
	{
		if (command[1][0] == '-')
		{
			if (command[1] == "-i") //cp -i file1
			{
				cout << command[0] << " пропущен операнд после '" << command[2] << "'" << endl;
				cout << "Попробуйте 'man cp' для получения более подробного описания." << endl;
			}
			else if (command[1] != "-i") //cp -key file1
			{
				cout << command[0] << " неверный ключ - " << command[1] << endl;
				cout << "Попробуйте 'man cp' для получения более подробного описания." << endl;
			}
		}
		if (command[1][0] != '-') // cp file1 katalog
		{
			cp_reiteration(home + command[1], home + command[2], command[1], command[2]);
		}
		break;
	}
	case 4:
	{
		//cp -i file1 katalog
		if (command[1] == "-i")
		{
			char mv_i;
			cout << "Скопировать файл '" << command[2] << "' ?";
			cin >> mv_i;
			if (mv_i == 'y')
			{
				cp_reiteration(home + command[2], home + command[3], command[2], command[3]);
			}
			else
			{
				cout;
			}
		}
		if (command[1] != "-i")
		{
			cout << command[0] << " неверный ключ - " << command[1] << endl;
			cout << "Попробуйте 'man cp' для получения более подробного описания." << endl;
		}
		break;
	}
	default:
	{
		cout << "cp: указанная цель '" << command[kolvo - 1] << "' не является каталогом" << endl;
	}
	}
}
void sort(int kolvo, vector <string> &command, int esc)
{
	switch (kolvo)
	{
	case 1:
	{
		tail_reiteration1(esc); // sort
		break;
	}
	case 2:
	{
		ifstream file; // sort file
		file.open(home + command[1]);
		string fg;
		vector <string> str;
		if (!file.is_open())
		{
			cout << command[0] << ": " << command[1] << ": " << "Нет такого файла или каталога" << endl;
		}
		else
		{
			while (!file.eof())
			{
				getline(file, fg);
				str.push_back(fg);
			}
			sort_reiteration(str);
		}
		file.close();
		break;
	}
	case 3:
	{
		ifstream file1, file2; // sort file1 file2
		file1.open(home + command[1]);
		file2.open(home + command[2]);
		string fg;
		vector <string> str;
		if (!file1.is_open())
		{
			cout << command[0] << ": " << command[1] << ": " << "Нет такого файла или каталога" << endl;
		}
		if (!file2.is_open())
		{
			cout << command[0] << ": " << command[2] << ": " << "Нет такого файла или каталога" << endl;
		}
		if ((file1.is_open()) && (file2.is_open()))
		{
			while (!file1.eof())
			{
				getline(file1, fg);
				str.push_back(fg);
			}
			while (!file2.eof())
			{
				getline(file2, fg);
				str.push_back(fg);
			}
			sort_reiteration(str);
		}
		file1.close();
		file2.close();
		break;
	}
	case 4:
	{
		if (command[2] == ">") // sort file1 > file2
		{
			ifstream file1;
			ofstream file2;
			file1.open(home + command[1]);
			file2.open(home + command[3]);
			string fg;
			vector <string> str;
			if (!file1.is_open())
			{
				cout << command[0] << ": " << command[1] << ": " << "Нет такого файла или каталога" << endl;
			}
			else
			{
				while (!file1.eof())
				{
					getline(file1, fg);
					str.push_back(fg);
				}
				sort(str.begin(), str.end(), [](const string & p1, const string & p2)
					{
						bool result = p1 < p2;
						return result;
					}
				);
				for (int i = 0; i < (int)str.size(); i++)
				{
					file2 << str[i] << endl;
				}
			}
			file1.close();
			file2.close();
		}
		if (command[2] == "<") // sort file1 < file2
		{
			ifstream file1;
			ofstream file2;
			file1.open(home + command[3]);
			file2.open(home + command[1]);
			string fg;
			vector <string> str;
			if (!file1.is_open())
			{
				cout << command[0] << ": " << command[3] << ": " << "Нет такого файла или каталога" << endl;
			}
			else
			{
				while (!file1.eof())
				{
					getline(file1, fg);
					str.push_back(fg);
				}
				sort(str.begin(), str.end(), [](const string & p1, const string & p2)
					{
						bool result = p1 < p2;
						return result;
					}
				);
				for (int i = 0; i < (int)str.size(); i++)
				{
					cout << str[i] << endl;
					file2 << str[i] << endl;
				}
			}
			file1.close();
			file2.close();
		}
		if ((command[2] != "<") && ((command[2] != "<"))) // sort ... ... ...
		{
			cout << "Использование команды sort более чем с 2-мя файлами пока не возможно!" << endl;
		}
		break;
	}
	default:
	{
		cout << "Использование команды sort более чем с 2-мя файлами пока не возможно!" << endl;
	}
	}
}
void tail(int kolvo, vector <string> &command, int esc)
{
	switch (kolvo)
	{
	case 1:
	{
		tail_reiteration1(esc);  //tail
		break;
	}
	case 2:
	{
		tail_reiteration2(command[1]); //tail file
		break;
	}
	case 3:
	{
		if (command[1][0] == '-')
		{
			if ((command[1] == "-c") || (command[1] == "-n")) // tail -c H or tail -c +H or tail -n +H or tail -n H
			{
				tail_reiteration1(esc);
			}
			else // tail - key ...
			{
				cout << "tail: неверный ключ - " << command[1] << endl;
				cout << "Попробуйте 'man tail' для получения более подробного описания." << endl;
			}
		}
		else
		{
			tail_reiteration2(command[1]); //tail file1 file2
			tail_reiteration2(command[2]);
		}
		break;
	}
	case 4:
	{
		if (command[1][0] == '-')
		{
			ifstream tail;
			tail.open(home + command[3]);
			if (!tail.is_open())
			{
				cout << command[0] << ": " << command[3] << ": " << "Нет такого файла или каталога" << endl;
			}
			else
			{
				vector <string> str;
				string str1;
				int kolvo = 0;
				while (!tail.eof())
				{
					getline(tail, str1);
					str.push_back(str1);
					str1 = "";
					kolvo++;
				}
				if (command[1] == "-c")
				{
					if (command[2][0] == '+')//tail -c +H file
					{
						char v[100];
						int i = 0, chislo;
						for (i; i < (int)command[2].size(); i++)
						{
							v[i] = command[2][i];
						}
						v[i + 1] = '\0';
						chislo = atoi(v);
						int i2 = 0;
						while (chislo > (int)str[i2].size() + 1)
						{
							if (chislo > (int)str[i2].size() + 1)
							{
								chislo = chislo - ((int)str[i2].size() + 1);
								i2++;
							}
						}
						for (int i = chislo - 1; i < (int)str[i2].size() + 1; i++)
						{
							cout << str[i2][i];
						}
						cout << endl;
						for (int i = i2 + 1; i < kolvo; i++)
						{
							cout << str[i] << endl;
						}
					}
					if ((command[2][0] != '+') && (command[2][0] != '-'))//tail -c H file
					{
						char v[100];
						int i = 0, chislo;
						for (i; i < (int)command[2].size(); i++)
						{
							v[i] = command[2][i];
						}
						v[i + 1] = '\0';
						chislo = atoi(v);
						int fullstr = kolvo - 1;
						while (chislo > (int)str[fullstr].size() + 1)
						{
							if (chislo >= (int)str[fullstr].size() + 1)
							{
								chislo = chislo - ((int)str[fullstr].size() + 1);
								fullstr -= 1;
							}
						}
						for (int i = ((int)str[fullstr].size() + 1) - chislo; i < (int)str[fullstr].size() + 1; i++)
						{
							cout << str[fullstr][i];
						}
						cout << endl;
						for (int i = fullstr + 1; i <= kolvo - 1; i++)
						{
							cout << str[i] << endl;
						}
					}
				}
				if (command[1] == "-n")
				{
					if (command[2][0] == '+')//tail -n +H file
					{
						char v[100];
						int i = 0, chislo;
						for (i; i < (int)command[2].size(); i++)
						{
							v[i] = command[2][i];
						}
						v[i + 1] = '\0';
						chislo = atoi(v);
						if (chislo <= kolvo)
						{
							for (int i = chislo - 1; i < kolvo; i++)
							{
								cout << str[i] << endl;
							}
						}
						if (chislo > kolvo)
						{
							cout << endl;
						}
					}
					if ((command[2][0] != '+') && (command[2][0] != '-')) //tail -n H file
					{
						char v[100];
						int i = 0, chislo;
						for (i; i < (int)command[2].size(); i++)
						{
							v[i] = command[2][i];
						}
						v[i + 1] = '\0';
						chislo = atoi(v);
						if (chislo >= kolvo)
						{
							for (int i = 0; i < kolvo; i++)
							{
								cout << str[i] << endl;
							}
						}
						if (chislo < kolvo)
						{
							for (int i = kolvo - chislo; i < kolvo; i++)
							{
								cout << str[i] << endl;
							}
						}
					}
				}
				if (!((command[1] == "-c") || (command[1] == "-n")))
				{
					cout << "tail: неверный ключ '" << command[1] << endl;
					cout << "Попробуйте 'man tail' для получения более подробного описания." << endl;
				}
			}
		}
		if (command[1][0] != '-')
		{
			if (command[2] == ">") //tail file1 > file2
			{
				tail_reiteration3(command[1], command[3]);
			}
			if (command[2] == "<") //tail file1 < file2
			{
				tail_reiteration3(command[3], command[1]);
			}
		}
		break;
	}
	case 5:
	{
		cout << "Использование ключей с двумя файлами пока не предусмотрен!" << endl;
		break;
	}
	case 6:
	{
		if (command[1][0] == '-')
		{
			if (command[4] == ">")
			{
				tail_reiteration4(command[1], command[2], command[3], command[5]);
			}
			if (command[4] == "<")
			{
				tail_reiteration4(command[1], command[2], command[5], command[3]);
			}
		}
		break;
	}
	default:
	{
		cout << "tail: невозможно открыть '" << command[6] << "' для чтения: Нет такого файла или каталога" << endl;
		cout << "Попробуйте 'man tail' для получения более подробного описания." << endl;
	}
	}
}
void cmp(int kolvo, vector <string> &command, int esc)
{
	switch (kolvo)
	{
	case 1:
	{
		//cmp
		cout << "Пропущен операнд после 'cmp'" << endl;
		cout << "Попробуйте 'man cmp' для получения более подробного описания." << endl;
		break;
	}
	case 2:
	{
		//cmp file
		ifstream cmpfile;
		cmpfile.open(home + command[1]);
		if (!cmpfile.is_open())
		{
			cout << command[0] << ": " << command[1] << ": " << "Нет такого файла или каталога" << endl;
		}
		else
		{
			tail_reiteration1(esc);
		}
		cmpfile.close();
		break;
	}
	case 3:
	{
		//cmp file1 file2
		string strforconstfile1, strforfile11, strforfile21;
		vector <string> strforfile1, strforfile2;
		ifstream cmpforfile1, cmpforfile2;
		int i = 0, j = 0, k = 0;
		cmpforfile1.open(home + command[1]);
		cmpforfile2.open(home + command[2]);
		if (!cmpforfile1.is_open())
		{
			cout << command[0] << ": " << command[1] << ": " << "Нет такого файла или каталога" << endl;
		}
		if (!cmpforfile2.is_open())
		{
			cout << command[0] << ": " << command[2] << ": " << "Нет такого файла или каталога" << endl;
		}
		if ((cmpforfile2.is_open()) && (cmpforfile1.is_open()))
		{
			while (!cmpforfile1.eof())
			{
				getline(cmpforfile1, strforfile11);
				strforfile1.push_back(strforfile11);
				j++;
			}
			while (!cmpforfile2.eof())
			{
				getline(cmpforfile2, strforfile21);
				strforfile2.push_back(strforfile21);
				k++;
			}
			const int  kolichestvostrokbyfile1 = j, kolichestvostrokbyfile2 = k;
			int  *sizestrforfile1, *sizestrforfile2;
			sizestrforfile1 = new int[kolichestvostrokbyfile1];
			sizestrforfile2 = new int[kolichestvostrokbyfile2];
			int i3 = 0, j3 = 0, j4 = 0;
			while (strforfile1[i3][j3] == strforfile2[i3][j3])
			{
				j3++;
				j4++;
				if ((strforfile1[i3][j3] == '\0') && (strforfile2[i3][j3] == '\0'))
				{
					i3++;
					j3 = 0;
				}
			}
			cout << command[1] << " " << command[2] << " различаются:  байт " << j4 + 1 << ", строка " << i3 + 1;
			cout << endl;
		}
		cmpforfile1.close();
		cmpforfile2.close();
		break;
	}
	case 4:
	{
		if (command[1][0] == '-')
		{
			if (command[1] == "-l") //cmp -l file1 file2
			{
				string strforconstfile1, strforfile11, strforfile21;
				vector <string> strforfile1, strforfile2, strforconstfile;
				ifstream cmpforfile1, cmpforfile2, cmpforconstfile;
				int i = 0, j = 0, k = 0;
				cmpforfile1.open(home + command[2]);
				cmpforfile2.open(home + command[3]);
				cmpforconstfile.open(home + "cmp.txt");
				if (!cmpforfile1.is_open())
				{
					cout << command[0] << ": " << command[2] << ": " << "Нет такого файла или каталога" << endl;
				}
				if (!cmpforfile2.is_open())
				{
					cout << command[0] << ": " << command[3] << ": " << "Нет такого файла или каталога" << endl;
				}
				if (!cmpforconstfile.is_open())
				{
					cout << command[0] << ": 'cmp.txt': " << "Нет такого файла или каталога" << endl;
				}
				if ((cmpforfile2.is_open()) && (cmpforfile1.is_open()) && (cmpforconstfile.is_open()))
				{
					while (!cmpforconstfile.eof())
					{
						getline(cmpforconstfile, strforconstfile1);
						strforconstfile.push_back(strforconstfile1);
						i++;
					}
					while (!cmpforfile1.eof())
					{
						getline(cmpforfile1, strforfile11);
						strforfile1.push_back(strforfile11);
						j++;
					}
					while (!cmpforfile2.eof())
					{
						getline(cmpforfile2, strforfile21);
						strforfile2.push_back(strforfile21);
						k++;
					}
					int  kolichestvostrokbyconstfile = i, kolichestvostrokbyfile1 = j, kolichestvostrokbyfile2 = k;
					int i3 = 0, j3 = 0, j4 = 0;
					while (strforfile1[i3][j3] == strforfile2[i3][j3])
					{
						j3++;
						j4++;
						if ((strforfile1[i3][j3] == '\0') && (strforfile2[i3][j3] == '\0'))
						{
							i3++;
							j3 = 0;
						}
					}
					char f1[3] = "", f2[3] = "";
					int i4 = 0;
					while (i4 != (i - 3))
					{
						if (strforfile1[i3][j3] == strforconstfile[i4][3])
						{
							for (int i5 = 0; i5 < 3; i5++)
							{
								f1[i5] = strforconstfile[i4][i5];

							}
						}
						if (strforfile2[i3][j3] == strforconstfile[i4][3])
						{
							for (int i5 = 0; i5 < 3; i5++)
							{
								f2[i5] = strforconstfile[i4][i5];
							}
						}
						i4++;
					}
					cout << j4 + 1 << " " << f1[0] << f1[1] << f1[2] << " " << f2[0] << f2[1] << f2[2];
					cout << endl;

				}
				cmpforfile1.close();
				cmpforfile2.close();
				cmpforconstfile.close();
			}
			if (command[1] != "-l")
			{
				cout << "cmp: неверный ключ - " << command[1] << endl;
				cout << "Попробуйте 'man cmp' для получения более подробного описания." << endl;
			}
		}
		if (command[1][0] != '-') //cmp ... ... ...
		{
			cout << "cmp: недопустимое значение '" << command[1] << "' " << endl;
			cout << "Попробуйте 'man cmp' для получения более подробного описания." << endl;
		}
		break;
	}
	case 5:
	{
		//cmp file1 file2 > file3
		if (command[3] == ">")
		{
			string strforfile11, strforfile21;
			vector <string> strforfile1, strforfile2;
			ifstream cmpforfile1, cmpforfile2;
			ofstream file3;
			int i = 0, j = 0, k = 0;
			cmpforfile1.open(home + command[1]);
			cmpforfile2.open(home + command[2]);
			file3.open(home + command[4]);
			if (!cmpforfile1.is_open())
			{
				cout << command[0] << ": " << command[1] << ": " << "Нет такого файла или каталога" << endl;
			}
			else if (!cmpforfile2.is_open())
			{
				cout << command[0] << ": " << command[2] << ": " << "Нет такого файла или каталога" << endl;
			}
			else
			{
				while (!cmpforfile1.eof())
				{
					getline(cmpforfile1, strforfile11);
					strforfile1.push_back(strforfile11);
					j++;
				}
				while (!cmpforfile2.eof())
				{
					getline(cmpforfile2, strforfile21);
					strforfile2.push_back(strforfile21);
					k++;
				}
				int i3 = 0, j3 = 0;
				while (strforfile1[i3][j3] == strforfile2[i3][j3])
				{
					j3++;
					if ((strforfile1[i3][j3] == '\0') && (strforfile2[i3][j3] == '\0'))
					{
						i3++;
						j3 = 0;
					}
				}
				if (!file3.is_open())
				{
					cout << command[0] << ": " << command[4] << ": " << "Нет такого файла или каталога" << endl;
				}
				else
				{
					file3 << command[1] << " " << command[2] << " различаются:  байт " << j3 + 1 << ", строка " << i3 + 1;
				}
				cout << endl;
			}
			cmpforfile1.close();
			cmpforfile2.close();
			file3.close();
		}
		else
		{
			cout << "cmp: недопустимое значение '" << command[3] << "' " << endl;
			cout << "Попробуйте 'man cmp' для получения более подробного описания." << endl;
		}
		break;
	}
	default:
	{
		cout << "cmp: недопустимое значение '" << command[5] << "' " << endl;
		cout << "Попробуйте 'man cmp' для получения более подробного описания." << endl;
	}
	}
}
void egrep(int kolvo, vector <string> &command, int esc)
{
	switch (kolvo)
	{
	case 1:
	{
		egrep_reiteration1(); // egrep
		break;
	}
	case 2:
	{
		if ((command[1] == "-b") || (command[1] == "-c"))
		{
			egrep_reiteration1();  // egrep -b or egrep -c
		}
		else
		{
			do  // egrep шаблон
			{
				string stroka;
				getline(cin, stroka);
				size_t pos = stroka.find(command[1]);
				if (pos != string::npos)
				{
					cout << stroka << endl;
				}
				esc = _getch();
			} while (esc != 27);
			cout << endl;
		}
		break;
	}
	case 3:
	{
		if (command[1][0] == '-')
		{
			if ((command[1] == "-b") || (command[1] == "-c")) // egrep -key ...
			{
				tail_reiteration1(esc);
			}
			else
			{
				cout << "egrep: неверный ключ - " << command[1] << endl;
				egrep_reiteration1();
			}
		}
		if (command[1][0] != '-') //egrep шаблон file
		{
			if ((command[1] == ">") || (command[1] == "<"))
			{
				egrep_reiteration1();
			}
			else
			{
				string coutstr;
				ifstream file;
				file.open(home + command[2]);
				if (!file.is_open())
				{
					cout << command[0] << ": " << command[2] << ": " << "Нет такого файла или каталога" << endl;
				}
				else
				{
					while (!file.eof())
					{
						getline(file, coutstr);
						size_t pos = coutstr.find(command[1]);
						if (pos != string::npos)
						{
							cout << coutstr << endl;
						}
					}
				}
				file.close();
			}
		}
		break;
	}
	case 4:
	{
		if (command[1][0] == '-')
		{
			if (command[1] == "-b") // egrep -b шаблон file
			{
				string coutstr;
				ifstream file;
				int num = 1;
				file.open(home + command[3]);
				if (!file.is_open())
				{
					cout << command[0] << ": " << command[3] << ": " << "Нет такого файла или каталога" << endl;
				}
				else
				{
					while (!file.eof())
					{
						getline(file, coutstr);
						size_t pos = coutstr.find(command[2]);
						if (pos != string::npos)
						{
							cout << num << " " << coutstr << endl;
						}
						num++;
					}
				}
				file.close();
			}
			else if (command[1] == "-c") // egrep -c шаблон file
			{
				string coutstr;
				ifstream file;
				int num = 0;
				file.open(home + command[3]);
				if (!file.is_open())
				{
					cout << command[0] << ": " << command[3] << ": " << "Нет такого файла или каталога" << endl;
				}
				else
				{
					while (!file.eof())
					{
						getline(file, coutstr);
						size_t pos = coutstr.find(command[2]);
						if (pos != string::npos)
						{
							num++;
						}
						cout << num << endl;
					}
				}
				file.close();
			}
			else
			{
				cout << "egrep: неверный ключ - " << command[1] << endl;
				egrep_reiteration1();
			}
		}
		if (command[1][0] != '-')
		{
			egrep_reiteration2(command[1], command[2]);
			egrep_reiteration2(command[1], command[3]);
		}
		break;
	}
	case 5:
	{
		if (command[1][0] == '-')
		{
			if (command[1] == "-b") // egrep -b шаблон file1 file2
			{
				egrep_reiteration3(command[2], command[3]);
				egrep_reiteration3(command[2], command[4]);
			}
			else if (command[1] == "-c") // egrep -c шаблон file1 file2
			{
				egrep_reiteration4(command[2], command[3]);
				egrep_reiteration4(command[2], command[4]);
			}
			else
			{
				cout << "egrep: неверный ключ - " << command[1] << endl;
				egrep_reiteration1();
			}
		}
		if (command[1][0] != '-')
		{
			if (command[3] == ">") // egrep шаблон file1 > file2
			{
				string coutstr;
				ifstream file1;
				ofstream file2;
				file1.open(command[2]);
				file2.open(command[4]);
				if (!file1.is_open())
				{
					file2 << command[0] << ": " << command[2] << ": " << "Нет такого файла или каталога" << endl;
				}
				else
				{
					while (!file1.eof())
					{
						getline(file1, coutstr);
						size_t pos = coutstr.find(command[1]);
						if (pos != string::npos)
						{
							file2 << coutstr << endl;
						}
					}
				}
				file1.close();
				file2.close();
			}
			else //egrep шаблон file1 file2 file3
			{
				egrep_reiteration2(command[1], command[2]);
				egrep_reiteration2(command[1], command[3]);
				egrep_reiteration2(command[1], command[4]);
			}
		}
		break;
	}
	default:
	{
		if (command[1][0] == '-')
		{
			if (command[1] == "-b")
			{
				for (int i = 3; i < kolvo - 1; i++)
				{
					egrep_reiteration3(command[2], command[i]);
				}
			}
			else if (command[1] == "-c")
			{
				for (int i = 3; i < kolvo - 1; i++)
				{
					egrep_reiteration4(command[2], command[i]);
				}
			}
			else
			{
				cout << "egrep: неверный ключ - " << command[1] << endl;
				egrep_reiteration1();
			}
		}
		if (command[1][0] != '-')
		{
			for (int i = 2; i < kolvo - 1; i++)
			{
				egrep_reiteration3(command[1], command[i]);
			}
		}
	}
	}
}
void file(int kolvo, vector <string> &command)
{
	switch (kolvo)
	{
	case 1:
	{
		cout << "Попробуйте 'man file' для получения более подробного описания." << endl;
		break;
	}
	case 2:
	{
		file_reiteration(command[1]); //file file
		break;
	}
	case 3:
	{
		//file file1 file2
		file_reiteration(command[1]); //file file1
		file_reiteration(command[2]); //file file2
		break;
	}
	case 4:
	{
		ifstream file1; //file file1 > file2
		ofstream file2;
		file1.open(home + command[1]);
		if (!file1.is_open())
		{
			cout << command[0] << ": " << command[1] << ": " << "Нет такого файла или каталога" << endl;
		}
		else
		{
			char typefile[100] = "";
			int k = 0;
			for (int i = 0; i < (int)command[1].size() - 1; i++)
			{
				if (command[1][i] == '.')
				{
					for (int j = i + 1; j < (int)command[1].size(); j++)
					{
						typefile[k] = command[1][j];
						k++;
					}
				}
			}
			if (k == 2)
			{
				if ((typefile[0] == '7') && (typefile[1] == 'z'))
				{
					file2 << command[0] << " '" << command[1] << "' " << ": Файл: Сжатая папка " << endl;
				}
				else
				{
					file2 << command[0] << " '" << command[1] << "' " << ": Невозможно определить тип файла!" << endl;
				}
			}
			if (k == 3)
			{
				if ((typefile[0] == 't') && (typefile[1] == 'x') && (typefile[2] == 't'))
				{
					file2 << command[0] << " '" << command[1] << "' " << ": Текстовый файл" << endl;
				}
				else if ((typefile[0] == 'j') && (typefile[1] == 'p') && (typefile[2] == 'g'))
				{
					file2 << command[0] << " '" << command[1] << "' " << ": Файл: Изображения" << endl;
				}
				else if ((typefile[0] == 'o') && (typefile[1] == 'd') && (typefile[2] == 't'))
				{
					file2 << command[0] << " '" << command[1] << "' " << ": Файл: Документ OpenOffice Word" << endl;
				}
				else if ((typefile[0] == 's') && (typefile[1] == 'l') && (typefile[2] == 'n'))
				{
					file2 << command[0] << " '" << command[1] << "' " << ": Файл: Приложения Visual Studio" << endl;
				}
				else
				{
					file2 << command[0] << " '" << command[1] << "' " << ": Невозможно определить тип файла!" << endl;
				}
			}
			if (k == 4)
			{
				if ((typefile[0] == 'd') && (typefile[1] == 'o') && (typefile[2] == 'c') && (typefile[2] == 'x'))
				{
					file2 << command[0] << " '" << command[1] << "' " << ": Файл: Документ Microsoft Word" << endl;
				}
				else if ((typefile[0] == 'x') && (typefile[1] == 'l') && (typefile[2] == 's') && (typefile[2] == 'x'))
				{
					file2 << command[0] << " '" << command[1] << "' " << ": Файл: Документ Microsoft Excel" << endl;
				}
				else if ((typefile[0] == 'p') && (typefile[1] == 'p') && (typefile[2] == 't') && (typefile[2] == 'x'))
				{
					file2 << command[0] << " '" << command[1] << "' " << ": Файл: Презентация Microsoft PowerPoint " << endl;
				}
				else
				{
					file2 << command[0] << " '" << command[1] << "' " << ": Невозможно определить тип файла!" << endl;
				}
			}
		}
		file1.close();
		break;
	}
	default:
	{
		for (int i = 1; i < kolvo; i++)
		{
			file_reiteration(command[i]);
		}
	}
	}
}
void man(int kolvo, vector <string> &command)
{
	switch (kolvo)
	{
	case 1:
	{
		cout << "Какая страница руководства вам нужна?" << endl;
		break;
	}
	case 2:
	{
		if (command[1] == "cat") // man cat
		{
			cout << "Команда cat:" << endl;
			cout << "Функция команды:" << endl;
			cout << "Читать данные из файла или стандартного ввода и выводить их на экран." << endl;
			cout << "Синтаксис команды:" << endl;
			cout << endl;
			cout << "cat[опции][файл]" << endl;
			cout << endl;
			cout << "Опции команды:" << endl;
			cout << "-s - удалять пустые повторяющиеся строки;" << endl;
		}
		else if (command[1] == "comm") // man comm
		{
			cout << "Команда comm:" << endl;
			cout << "Функция команды:" << endl;
			cout << "Утилита будет выводить строки в трех столбцах: " << endl;
			cout << "первый столбец будет содержать строки, присутствующие лишь в файле 1. " << endl;
			cout << "второй столбец — строки, присутствующие лишь в файле 2. " << endl;
			cout << "третий столбец — строки, присутствующие в обоих файлах." << endl;
			cout << "Синтаксис команды:" << endl;
			cout << endl;
			cout << "comm [опции] [файл1] [файл2]" << endl;
			cout << endl;
			cout << "Опции команды:" << endl;
			cout << "-1 - не выводить на экран строки, присутствующие лишь в файле 1." << endl;
			cout << "-2 - не выводить на экран строки, присутствующие лишь в файле 2." << endl;
			cout << "-3 - не выводить на экран строки, присутствующие в обоих файлах." << endl;
			cout << "-12 - выводит строки, общие для двух файлов." << endl;
			cout << "-13 - выводит строки, имеющиеся только в файле 2." << endl;
			cout << "-23 - выводит строки, имеющиеся только в файле 1." << endl;
		}
		else if (command[1] == "cmp") // man cmp
		{
			cout << "Команда cmp:" << endl;
			cout << "Функция команды:" << endl;
			cout << "Побайтовое сравнение двух произвольных файлов." << endl;
			cout << "Синтаксис команды:" << endl;
			cout << endl;
			cout << "cmp [опции] [файл1] [файл2]" << endl;
			cout << endl;
			cout << "Опции команды:" << endl;
			cout << "-l - вывод значений отличающихся байтов в первом и во втором файле " << endl;
		}
		else if (command[1] == "egrep") // man egrep
		{
			cout << "Команда egrep:" << endl;
			cout << "Функция команды:" << endl;
			cout << "Поиск шаблонов, соответствующих строке в тексте или содержимому файлов." << endl;
			cout << "Шаблон - это любая строка, по которой будет вестись поиск." << endl;
			cout << "Синтаксис команды:" << endl;
			cout << endl;
			cout << "egrep [опции] [шаблон] [файл]" << endl;
			cout << endl;
			cout << "Опции команды:" << endl;
			cout << "-b - показывать номер строки в которой находится шаблон" << endl;
			cout << "-c - подсчитать количество вхождений шаблона" << endl;
		}
		else if (command[1] == "mv") // man mv
		{
			cout << "Команда mv:" << endl;
			cout << "Функция команды:" << endl;
			cout << "Команда mv перемещает файл в новое место." << endl;
			cout << "Синтаксис команды:" << endl;
			cout << endl;
			cout << "mv [опции] [файл] [каталог]" << endl;
			cout << endl;
			cout << "Опции команды:" << endl;
			cout << "-i - вывод запроса на подтверждение операции перемещения " << endl;
		}
		else if (command[1] == "sort") // man sort
		{
			cout << "Команда sort:" << endl;
			cout << "Функция команды:" << endl;
			cout << "Команда sort выводит текстовые строки в определенном порядке (сортирует). " << endl;
			cout << "Ее можно использовать для сортировки текста из одного или нескольких файлов" << endl;
			cout << "Синтаксис команды:" << endl;
			cout << endl;
			cout << "sort [файл]..." << endl;
			cout << endl;
		}
		else if (command[1] == "cp") // man cp
		{
			cout << "Команда cp:" << endl;
			cout << "Функция команды:" << endl;
			cout << "Команда cp копирует файл в новое место." << endl;
			cout << "Синтаксис команды:" << endl;
			cout << endl;
			cout << "cp [опции] [файл] [каталог]" << endl;
			cout << endl;
			cout << "Опции команды:" << endl;
			cout << "-i - вывод запроса на подтверждение операции копирования " << endl;
		}
		else if (command[1] == "cd") // man cd
		{
			cout << "Команда cd:" << endl;
			cout << "Функция команды:" << endl;
			cout << "Команда cd заменяет текущую директорию на новую, если она существует." << endl;
			cout << "Синтаксис команды:" << endl;
			cout << endl;
			cout << "cd [опции] [директория]" << endl;
			cout << endl;
		}
		else if (command[1] == "ls") // man ls
		{
			cout << "Команда ls:" << endl;
			cout << "Функция команды:" << endl;
			cout << "Команда ls выводит содержимое каталога (по умолчанию текущего)." << endl;
			cout << "Синтаксис команды:" << endl;
			cout << endl;
			cout << "ls [опции] [каталог]" << endl;
			cout << endl;
			cout << "Опции команды:" << endl;
			cout << "-l - выводит список содержимого каталога с расширенной информацией (дата, размер, группа). " << endl;
			cout << "-c - выводит список содержимого каталога с датой." << endl;
			cout << "-p - добавляет индикатор '" << home[2] << "' к каталогам." << endl;
		}
		else if (command[1] == "pwd") // man pwd
		{
			cout << "Команда pwd:" << endl;
			cout << "Синтаксис команды:" << endl;
			cout << endl;
			cout << "pwd" << endl;
			cout << endl;
			cout << "Функция команды:" << endl;
			cout << "Команда pwd выводит полный путь текущего рабочего каталога. " << endl;
		}
		else if (command[1] == "tail") // man tail
		{
			cout << "Команда tail:" << endl;
			cout << "Функция команды:" << endl;
			cout << "По умолчанию утилита выводит десять последних строк из файла" << endl;
			cout << "Синтаксис команды:" << endl;
			cout << endl;
			cout << "tail [опции] [Bytes/String] [файл]" << endl;
			cout << endl;
			cout << "Опции команды:" << endl;
			cout << "-c H=Bytes - выводить указанное количество байт с конца файла (+H - вывести все байты, начиная с H) " << endl;
			cout << "-n H=String - выводить указанное количество строк из конца файла (+H - вывести все строки, начиная с H)" << endl;
		}
		else if (command[1] == "wc") // man wc
		{
			cout << "Команда wc:" << endl;
			cout << "Функция команды:" << endl;
			cout << "Команда wc предназначена для подсчёта количества строк, слов или байт в тексте." << endl;
			cout << "Синтаксис команды:" << endl;
			cout << endl;
			cout << "wc [опции] [файл]" << endl;
			cout << endl;
			cout << "Опции команды:" << endl;
			cout << "-c - напечатать число байт " << endl;
			cout << "-l - напечатать число строк " << endl;
			cout << "-w - напечатать число слов " << endl;
		}
		else if (command[1] == "file") // man file
		{
			cout << "Команда file:" << endl;
			cout << "Функция команды:" << endl;
			cout << "Команда file предназначена для определение типа файла" << endl;
			cout << "Синтаксис команды:" << endl;
			cout << endl;
			cout << "file [файл]" << endl;
			cout << endl;
		}
		else
		{
			cout << "Нет справочного руководства для " << command[1] << endl;
		}
		break;
	}
	default:
	{
		for (int i = 1; i < kolvo; i++)
		{
			cout << "Нет справочного руководства для " << command[i] << endl;
		}
	}
	}
}
int exit(int kolvo, vector <string> &command)
{
	switch (kolvo)
	{
	case 1:
	{
		exit(0);
		break;
	}
	case 2:
	{
		if (command[1] == "0")
		{
			exit(0);
		}
		else
		{
			exit(1);
		}
		break;
	}
	default:
	{
		exit(1);
	}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		cout << home << ":~$ ";
		vector <string> command;
		string commands, word;
		int KolvoSlov = 0;
		getline(cin, commands);
		istringstream iss(commands);
		while (iss >> word)
		{
			command.push_back(word);
			KolvoSlov++;
		}
		int esc = 0;
		if (command[0] == "cat")
		{
			cat(KolvoSlov, command, esc);
		}
		else if (command[0] == "comm")
		{
			comm(KolvoSlov, command);
		}
		else if (command[0] == "wc")
		{
			wc(KolvoSlov, command, esc);
		}
		else if (command[0] == "mv")
		{
			mv(KolvoSlov, command);
		}
		else if (command[0] == "cp")
		{
			cp(KolvoSlov, command);
		}
		else if (command[0] == "sort")
		{
			sort(KolvoSlov, command, esc);
		}
		else if (command[0] == "cd")
		{
			cd(KolvoSlov, command);
		}
		else if (command[0] == "ls")
		{
			ls(KolvoSlov, command);
		}
		else if (command[0] == "egrep")
		{
			egrep(KolvoSlov, command, esc);
		}
		else if (command[0] == "pwd")
		{
			pwd(KolvoSlov, command);
		}
		else if (command[0] == "tail")
		{
			tail(KolvoSlov, command, esc);
		}
		else if (command[0] == "cmp")
		{
			cmp(KolvoSlov, command, esc);
		}
		else if (command[0] == "file")
		{
			file(KolvoSlov, command);
		}
		else if (command[0] == "man")
		{
			man(KolvoSlov, command);
		}
		else if (command[0] == "exit")
		{
			exit(KolvoSlov, command);
		}
		else
		{
			cout << "bash: " << command[0] << ": " << "команда не найдена" << endl;
		}
	}
}