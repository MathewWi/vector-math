// 
//
// Easyvector, Hans-Kristian Arntzen
/////////////////////////////////////

#include <iostream>
#include "vector.h"
using namespace std;

	
int main(int argc, char* argv[]){  // Hovedfunksjon main, denne tar argumentene argc og **argv, som 
				// der argc er antall kommandolinjeargument og **argv er pointern til
                                // kommandolinjeargumentene ...
	bool volumemode = false; // Initialiserer en bool (true/false) som indikerer om vi har aktivert volummodus.
	
	if (argc > 9){ cout << "Volume mode initiated ..." << endl; volumemode = true;}// Hvis vi får 10 eller fler argumenter (1 + 9)
							// initialiseres volummodus (3 vektorer)
	vectors *a = new vectors() , *b = new vectors() , *c = new vectors() , *volume = new vectors(); // Definerer tre objekter i klassen vectors.
// Definerer pointere som initialiseres til å vise til dynamisk allokerte objekt! a,b,c,vectors viser til objekter. vectors() med paranteser indikerer at vi vil lage en ny vektor med standard constructor, som definert i "vectors.h"
	
	while(true){  // Går inn i en uendelig loop, helt til loopen brytes, basert på brukerinput.
		      // Er normalt dårlig design i større prosjekt, siden bugs kan forårsake at "break" aldri forekommer, og man får en loop.
	
	                  
	a->scan(argc, argv); // a->scan() er en fiffig måte å skrive (*a).scan() på. *a har ikke et definert variabelnavn, men sett at den var x ville (*a).scan() blitt til x.scan(). AliRoot-syntaks bruker svært mange pointere. Man har større kontroll over minnebruken med pointere, og er dermed nyttig.

	b->scan(argc, argv); // Samme tankegang
	
	if (volumemode){     // Hvis volum
	volume->scan(argc,argv); 
	}

 	c = a->operator + (b); // Vi har definert hvordan to objekt i vectors-klassen kan legges sammen for å danne et nytt objekt c.
 	

	cout << endl;
	//cout << "Added vector is\t\t"; c->printVector(); // Printer ut x, y og z - verdi til
	                         //  summen, c.
	//c = a-> operator - (b); 
	//cout << "Subtracted vector is\t"; c->printVector(); // Printer ut x, y og z - verdi til
	                         //  differansen, c.
	int d; d = a->operator * (b);
	cout << "Scalar product is\t" << d << endl; // Printer ut x, y og z - verdi til
	                         //  skalarproduktet, c.
	if (d == 0) cout << "90 degrees!" << endl;
	c = a->operator % (b);
	cout << "Cross product is\t"; c->printVector();
    cout << "Length of cross product\t" << c->Length() << "\t\t\t\t" << "sqrt( " << c->LengthSqrt() << " )" << endl;
	if (c->Length() == 0) { cout << "Vectors are parallell!" << endl; }				    
	
	if (volumemode){ 
	d = c->operator * (volume);

        if (d < 0) d = -d;
	cout << "Volume is\t\t"<< d << endl;
	}
	
	


	if(a->Length() == 0 || b->Length() == 0) break;

    	double angle = a-> operator / (b);
	if (angle < 0.5) angle = 0.0;
	cout.precision(getPrecision(angle));
	cout << "Angle is\t\t" << angle << endl;			 	
	cout << endl << endl;

}
        delete a,b,c,volume; 	
	return 0; // Returnerer med ingen feil til operativsystemet.
}
