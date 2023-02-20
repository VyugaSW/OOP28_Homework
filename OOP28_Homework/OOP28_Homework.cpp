

#include <iostream>
#include "Vocabular.h"

using namespace std;

// Initial text:
// 
//He rushed to the corner, put his hand under the wallpaper and began to pull out 
//things and load his pockets with them. There were eight pieces in all: 
//two small boxes of earrings or something like that - he didn't 
//take a good look; then four small morocco cases. 
//One chain was simply wrapped in newsprint. 
//Something else in newsprint, it seems an order ...


int main()
{
    Vocabular a;
    a.readFromFile("C:\\Test\\test.txt");
    a.dataOfAllWords();
    //a.print();
    //cout << "\n\n";
    //a.printMostRepeats();
    a.recordingToFile("C:\\Test\\test2.txt");








}
