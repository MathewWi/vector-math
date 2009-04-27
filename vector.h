class vectors { // Definerer en klasse, vectors. Vektorer er definert som                
	public:     // en verdi med en retning. Vi gir denne vektoren tre retninger i x,y,z-retninger. 
	int x;      // Denne definisjonen er nyttig ikke bare for dette programmet. Så den kan brukes i andre programmer om
	int y;      // det skulle det være nyttig. Dette er sentralt i objektorientert programmering, og er en stor fordel
	int z;      // for større prosjekter.
	
	vectors(); // Setter x, y og z lik 0 når objektet til vectors blir opprettet.
	vectors(int, int, int); // Hvis man initialiserer et objekt med tre integerparametre vil denne funksjonen brukes
                                  // isteden	
	vectors* operator + (vectors*); // Denne funksjonen definerer hvordan to objekter fra vectors-klassen skal kunne adderes.
	vectors* operator - (vectors*); // Definerer for minus og gange også. 
	int operator * (vectors*);
	vectors* operator % (vectors*);
	void scan(int&, char* []);                  // Denne funksjonen tar seg av å hente input fra bruker 
 	                              // (eller andre steder om det skulle vært 
	 double Length();                       // programmert.)
	void printVector();							        
	double operator / (vectors*); 
	int LengthSqrt();            
};

int getPrecision(double);
