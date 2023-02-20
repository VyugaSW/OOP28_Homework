#pragma once
#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;


class Vocabular {
	string mainStr;
	map<string, int> words;
	string mostRepeatWord;

	int findRepeatWord(string tempStr,map<string,int> tempMap) {
		map<string, int>::iterator iter = tempMap.begin(); // Temp iterator

		for (; iter != tempMap.end(); iter++) {
			if (tempStr == iter->first) // If this word (tempStr) already exists
				return iter->second;
		}
		// If this map dont' has this word (tempStr)
		return 0;
	}

public:

	void readFromFile(const char* path);

	void dataOfAllWords();

	void print();

	void printMostRepeats();

	void recordingToFile(const char* path);

	string getMainStr();


};


void Vocabular::readFromFile(const char* path) {
	FILE* out;
	char temp;

	if (!fopen_s(&out, path, "r")) {
		while (!feof(out)) {
			temp = fgetc(out);
			mainStr.push_back(temp);
		}
		fclose(out);
		cout << "File was read\n";
	}
	// Entire string in lowercase
	transform(mainStr.begin(), mainStr.end(), mainStr.begin(), tolower);
}

void Vocabular::dataOfAllWords() {
	string tempStr;
	int max_repeats = 0;
	int counter_word = 0;

	for (auto i = mainStr.begin(); i < mainStr.end(); i++) {
		if (*i != ' ' && *i != '.' && *i != '!' &&
			*i != '?' && *i != ':' && *i != ',' &&
			*i != ';' && *i != '\n' && *i != '-')
			tempStr.push_back(*i);

		else {
			// Find repeat words
			counter_word = findRepeatWord(tempStr, words) + 1;
			// Add new pair or replace old
			words[tempStr] = counter_word;

			// Find maximum repeats of word
			if (max_repeats < counter_word) {
				max_repeats = counter_word;
				mostRepeatWord = tempStr;
			}
			// Clear temp variables 
			tempStr.clear();
		}
	}

}

void Vocabular::print() {
	map<string, int>::iterator iter = words.begin();
	if (iter != words.end()) {
		for (; iter != words.end(); iter++) {
			cout << iter->first << " - " << iter->second << endl;
		}
	}
	else
		cout << "Vocabular is empty\n";
}

void Vocabular::printMostRepeats() {
	map<string, int>::iterator iter = words.begin();
	// I don't know why this "  " is exists in my map... 
	if (iter != words.end()) {
		iter = words.find(mostRepeatWord);
		cout << "Most repeat word:\n";
		cout << iter->first << " - " << iter->second << endl;
	}
	else
		cout << "Vocabular is empty\n";
}

void Vocabular::recordingToFile(const char* path) {

	map<string, int>::iterator iter = words.begin();

	if (iter != words.end()) {
		FILE* in;
		char* buffer = new char[125];
		if (!fopen_s(&in, path, "w")) {
			for (; iter != words.end(); iter++) {
				strcpy_s(buffer, 126, iter->first.c_str());
				fputs(buffer, in);
				fputc(' ', in);
				fputc('-', in);
				fputc(' ', in);
				fprintf(in, "%d", iter->second);
				fputc('\n', in);
			}
			fclose(in);
			cout << "File was recorded\n";
		}
	}
	else
		cout << "Vocabular is empty\n";
}

string Vocabular::getMainStr() {
	return mainStr;
}

