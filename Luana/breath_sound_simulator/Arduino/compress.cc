/*
 *	Luana Okino Sawada - breath_sound_simulator.c
 *	https://github.com/simoesusp/PatientSimulator/tree/master/Luana/breath_sound_simulator
 *	To compile:
 *	g++ compress.cc -o compress
 *	To execute
 *	./compress
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h> 
using namespace std;

int main(int argc, char *argv[]) 
{
	//read this file
	ifstream infile;
	infile.open("sounddata.h");

	//create and write on this file
	ofstream outfile;
	outfile.open ("new_sounddata.h");

	//declare variables
	string line;
	string dlmt = "= ";
	size_t pos = 0;
	string token;

	//copy firsts lines
	getline(infile,line);
	outfile << line << endl;	
	getline(infile,line);
	outfile << line << endl;
	getline(infile,line);
	outfile << line << endl;
	
	getline(infile,line); //const int sounddata_length = XXXXX;

	//store the value of the size (XXXXX) in variable line
	pos = line.find(dlmt);
	token = line.substr(0, pos);		
	line.erase(0, pos + dlmt.length());
		
	//convert the variable line to a const char to be able to convert
	//				to int and store that value in the variable size
	const char * c = line.c_str();
	int size = atoi(c);
	cout << "size: " << size << endl;

	//store the value of the size of sounddata compressed to create a vector
	double nSize = ceil(size / 5.0);
	cout << "nSize: " << nSize << endl;

	//write in the output file	//const int sounddata_length = nSize;
	outfile << token << "= " << nSize << ";" << endl << endl;

	//jump a line and get the next one
	getline(infile,line);
	getline(infile,line);
	//cout << "Linha: " << line << endl;
	
	//inicialization of the sounddata vector
	int *sound;
	sound = (int *) calloc(size, sizeof(int));
	//inicialization of the sounddata compressed vector
	int *n_sound;
	n_sound = (int *) calloc(nSize, sizeof(int));	

	int position = 0;

	//define the delimiter as {, because I want to keep what comes after it
	pos = 0;
	dlmt = "{";
	pos = line.find(dlmt);
	token = line.substr(0, pos);
	//write in the output file //const signed char sounddata_data[] PROGMEM ={
	outfile << token << "{";
	line.erase(0, pos + dlmt.length());	
	//keeps just the number
	pos = 0;
	dlmt = ", ";
	pos = line.find(dlmt);
	token = line.substr(0, pos);
	
	//store the first value of the vector as int
	c = token.c_str();
	int bit = atoi(c);
	sound[position] = bit;
	position++;

	//Catch all the lines and all the numbers on it and save in the vector
	while(line != "};")
	{
		getline(infile,line);
		
		while(line != "" && line !="};")
		{
			pos = 0;
			dlmt = ", ";
			pos = line.find(dlmt);
			token = line.substr(0, pos);
			line.erase(0, pos + dlmt.length());
			c = token.c_str();
			bit = atoi(c);	
			sound[position] = bit;
			position++;
		}
	}

	//close input file
	infile.close();
	
	/*
	//print the old vector
	cout << "{";
	for(int i = 0; i < size; i++)
	{
		cout << sound[i] << ", ";
	}
	cout << "}" << endl;
	*/

	//compress the vector
	int j = 0;
	for(int i = 0; i < size; i=i+5)
	{
		n_sound[j] = sound[i];
		j++;
	}

	//save the compressed vector in the output file
	for(int i = 0; i < nSize; i++)
	{
		outfile << n_sound[i] << ", ";
	}
	outfile << "};" << endl;

	//close output file
	outfile.close();

	return 0;
}