#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include "vector.h"
#define PI 3.1415
using namespace std;

vectors::vectors(){  // Definisjonen til vectors(), som ble deklarert tidligere i klassedefinisjonen.
	x = y = z = 0;
}

vectors::vectors(int a, int b, int c){ // Definisjonen til vectors(int, int, int)
	x = a;
	y = b;
	z = c;
}	

vectors* vectors::operator+ (vectors *a){ // Definisjonen til vectors operator + (vectors). 
                                        // operator + er her funksjonen! vectors er hva operator + returnerer. (Som jo er logisk.)
	vectors *temp = new vectors();
	temp->x = x + a->x;
	temp->y = y + a->y;
	temp->z = z + a->z;
	return temp;
}	

vectors* vectors::operator- (vectors *a){ // Definisjonen til vectors operator + (vectors). 
                                        // operator - er her funksjonen! vectors er hva operator - returnerer. (Som jo er logisk.)
	vectors *temp = new vectors();
	temp->x = -x + a->x;
	temp->y = -y + a->y;
	temp->z = -z + a->z;
	return temp;
}

int vectors::operator* (vectors *a){ // Definisjonen til vectors operator + (vectors). 
    int d;                                    // operator * er her funksjonen! vectors er hva operator * returnerer. (Som jo er logisk.)
	vectors temp;
	temp.x = x * a->x;
	temp.y = y * a->y;
	temp.z = z * a->z;
	d = temp.x + temp.y + temp.z;
	return d;
}

vectors* vectors::operator% (vectors *a){ // Definisjonen til vectors operator + (vectors). 
                                        // operator % (finne vektorproduktet) er her funksjonen! vectors er hva operator + returnerer. (Som jo er logisk.)
	vectors *temp = new vectors();
	temp->x = y * a->z - a->y * z;
	temp->y = -x * a->z + a->x * z;
	temp->z = x * a->y - a->x * y;
	
	return temp;
}

double vectors::operator / (vectors *b){
    int c;
    double d = 0;
    c = (this->operator * (b));
	double cosine = (double)c/(this->Length()*b->Length());
	
	if (cosine > 1.0) return -1.0;
	if (cosine < -1.0) return -1.0;

	d = acos(cosine); 
	
	return ((d*180.0)/PI);   
}


double vectors::Length(){
	return (sqrt((double)x*(double)x+(double)y*(double)y+(double)z*(double)z));
}

int vectors::LengthSqrt(){
	return (x*x+y*y+z*z);
}

void vectors::scan(int& argc, char* argv[]){ // Definerer scan-funksjonen. 
	
	
	if(argc>=4){
    
	stringstream (argv[1]) >> x;
	stringstream (argv[2]) >> y;
	stringstream (argv[3]) >> z;
	
    for(int a=1; a<argc-2; a++) argv[a] = argv[a+3];

	argc -= 3;
}
	else{ 
		cout << "Insert vector: "; 
		cin >> x >> y >> z;
		
		}
		
		cout << endl << "Vector typed is " << "[" << x << ", " << y << ", " << z << "]";
    cout << "\t Length: " << Length() << "       \t" << "sqrt( " << LengthSqrt() << " )" << endl;	
		
}

// Alle funksjonene er nå definert. Vi kan nå skrive selve programmet med noen få linjer.

void vectors::printVector(){
	cout << "[" << x << ", " << y << ", " << z << "]" << endl;
} 

int getPrecision(double a){
	int precision=6;
	if (a>=1) precision=2;
	if (a>=10) precision=3;
	if (a>=100) precision=4; 
	if (a<=1)   precision=1;
		
		
	
	return precision;
} 
