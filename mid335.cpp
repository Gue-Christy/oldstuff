//CMPS 335
//mid335.cpp
//
//
//
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

//frequency definitions
#define A4 440.0
#define F0 A4
#define F0_note A
#define F0_octave 4

typedef enum {
	C = 1,
	Cs,
	D,
	Ds,
	E,
	F,
	Fs,
	G,
	Gs,
	A,
	As,
	B,
	END = B,
	HALF_STEPS_PER_OCTAVE = B 
} note_t;

double freq(note_t note, int octave_delta);

//void freq_unit_test();

int main(int argc, char *argv[])
{
	note_t note;
	int octave_delta;

	if (argc != 3) {
		cout << "Usage: " << argv[0] << " <NOTE>  <OCTAVE_DELTA>" << endl;
		return 0;
	}
	//
	note = (note_t)(toupper(argv[1][0]) - 64);
	switch(toupper(argv[1][0])) {
		case 'A': note = A; break;
		case 'B': note = B; break;
		case 'C': note = C; break;
		case 'D': note = D; break;
		case 'E': note = E; break;
		case 'F': note = F; break;
	}
	//You may call your unit test here...
	float tolerance, diff;
	//diff = 
	if (tolerance == diff){
	cout << " bad " << endl;
	}
	cout << "tolerance: \n";
	cout << "frequency function unit-test\n";
	cout << "note octave value     diff   \n";
	cout << "---- ------ -------   ---------\n";
	
	cout << "  " << C << "   " <<octave_delta<< "     " << freq(C , octave_delta)<< tolerance << endl;
	cout << "  " << Cs << "   " <<octave_delta<<"     " << freq(Cs, octave_delta) << endl;
	cout << "  " << D << "   " <<octave_delta<< "     " << freq(D, octave_delta) << endl;
	cout << "  " << Ds << "   " <<octave_delta<<"     " << freq(Ds, octave_delta) << endl;
	cout << "  " << E << "   " <<octave_delta<< "     " << freq(E, octave_delta) << endl;
	cout << "  " << F << "   " <<octave_delta<< "     " << freq(F, octave_delta) << endl;
	cout << "  " << Fs << "   " <<octave_delta<<"     " << freq(Fs, octave_delta) << endl;
	cout << "  " << G << "   " <<octave_delta<< "     " << freq(G, octave_delta) << endl;
	cout << "  " << Gs << "   " <<octave_delta<<"     " << freq(Gs, octave_delta) << endl;
	cout << "  " << A << "   " << octave_delta<<"     " << freq(A, octave_delta) << endl;
	cout << "  " << As << "   " <<octave_delta<<"     " << freq(As, octave_delta) << endl;
	cout << "  " << B << "   " << octave_delta<<"     " << freq(B, octave_delta)  << endl;
	

	if (note > END) {
		cout << "Invalid note!" << endl;
		return 1;
	}
	octave_delta = atoi(argv[2]);
	cout << HALF_STEPS_PER_OCTAVE << endl;
	cout << freq(note, octave_delta) << endl;
	return 0;
}

//-----------------------------------------------------------
//Generate a frequency in hz that is half_steps away from C_4
//Do not modify this function.
//-----------------------------------------------------------
double freq(note_t note, int octave_delta)
{
	double freq;
	double factor;
	double a;
	int n;
	int octave = octave_delta - F0_octave;

	a = pow(2.0, 1.0/(double)HALF_STEPS_PER_OCTAVE);
	n = note - F0_note;
	freq = F0 * pow(a, (double)n);
	factor = pow(2.0, (double)octave);
	freq = freq * factor;
	return freq;
}


