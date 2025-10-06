#include <stdio.h>
#include <list>

void AddName(const char name[], std::list<std::list<char>>& list) {
	std::list<char> namelist;
	for (int i = 0; i < strlen(name); i++) {
		namelist.push_back(name[i]);
	}
	list.push_back(namelist);
}

void AddNameItr(const char name[], std::list<std::list<char>>& list, std::list<std::list<char>>::iterator itr) {
	std::list<char> namelist;
	for (int i = 0; i < strlen(name); i++) {
		namelist.push_back(name[i]);
	}
	itr = list.insert(itr, namelist);
}

void listPrint(std::list<std::list<char>>* list) {
	for (std::list<char>& NameList : *list) {
		for (char& Name : NameList) {
			printf("%c", Name);
		}
		printf("\n");
	}
}

int main(){

	std::list<std::list<char>> yamanoteLine;
	std::list<std::list<char>>::iterator itr;
	
	printf("1970\n");
	AddName("Tokyo", yamanoteLine);
	AddName("Kanda", yamanoteLine);
	AddName("Akihabara", yamanoteLine);
	AddName("Okachimachi", yamanoteLine);
	AddName("Ueno", yamanoteLine);
	AddName("Uguisudani", yamanoteLine);
	AddName("Nippori", yamanoteLine);
	AddName("Tabata", yamanoteLine);
	AddName("Komagome", yamanoteLine);
	AddName("Sugamo", yamanoteLine);
	AddName("Otsuka", yamanoteLine);
	AddName("Ikebukuro", yamanoteLine);
	AddName("Mejiro", yamanoteLine);
	AddName("Takadanobaba", yamanoteLine);
	AddName("Shin-Okubo", yamanoteLine);
	AddName("Shinjuku", yamanoteLine);
	AddName("Yoyogi", yamanoteLine);
	AddName("Harajuku", yamanoteLine);
	AddName("Shibuya", yamanoteLine);
	AddName("Ebisu", yamanoteLine);
	AddName("Meguro", yamanoteLine);
	AddName("Gotanda", yamanoteLine);
	AddName("Osaki", yamanoteLine);
	AddName("Shinagawa", yamanoteLine);
	AddName("Tamachi", yamanoteLine);
	AddName("Hamamatsucho", yamanoteLine);
	AddName("Shimbashi", yamanoteLine);
	AddName("Yurakucho", yamanoteLine);

	listPrint(&yamanoteLine);

	itr = yamanoteLine.begin();
	for (int i = 0; i < 7; i++) {
		itr++;
	}

	AddNameItr("Nishi-Nippori", yamanoteLine, itr);

	printf("\n2019\n");
	listPrint(&yamanoteLine);

	for (int i = 0; i < 17; i++) {
		itr++;
	}

	AddNameItr("Takanawa Gateway", yamanoteLine, itr);

	printf("\n2022\n");
	listPrint(&yamanoteLine);

	return 0;
}
