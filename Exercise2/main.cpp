#include<iostream>
#include<iomanip>			 
#include "Eigen/Eigen"
#include "functions.cpp"

using namespace std;
using namespace Eigen;

int main()
{
	Vector2d exact_sol;				
	exact_sol << -1.0e+0, -1.0e+0;		//Inizializzo il vettore della soluzione esatta, utilizzato per calcolare l'errore relativo per ciascun metodo numerico
	
	/*Inizializzazione dell'array di matrici dei coefficienti A[i] per i sistemi lineri.
	  Questo evita di ridefinire la matrice a ogni interazione e presuppone un numero fisso di sistemi. */
	
	Matrix2d coeff_matrix[3];
	coeff_matrix[0] <<  5.547001962252291e-01, -3.770900990025203e-02,
	8.320502943378437e-01,-9.992887623566787e-01;
	
	coeff_matrix[1] << 5.547001962252291e-01, -5.540607316466765e-01, 
	8.320502943378437e-01, -8.324762492991313e-01;
	
	coeff_matrix[2] << 5.547001962252291e-01, -5.547001955851905e-01, 
	8.320502943378437e-01, -8.320502947645361e-01;
	
	/* Inizializzazione dell'array di vettori termine noto b[i] corrispondenti a ciascuna A[i].
	   In questo modo ogni sistema lineare A[i]x = b[i] può essere risolto indipendentemente. */
	
	Vector2d rhs[3];
	rhs[0] << -5.169911863249772e-01, 1.672384680188350e-01;
	rhs[1] << -6.394645785530173e-04, 4.259549612877223e-04;
	rhs[2] << -6.400391328043042e-10, 4.266924591433963e-10;
	
	double relative_error;		//Variabile usata per memorizzare l'errore relativo, calcolato all'interno di functions.cpp
	
	for(int i = 0; i<3; i++)
	{
		/* Itero sui sistemi definiti risolvendo ciascuno sia con il metodo LU parziale che con quello QR.
           La soluzione esatta viene confrontata con quella calcolata per valutare la precisone di ciascun metodo. */
		
		PALU_solution(coeff_matrix[i], rhs[i], exact_sol, relative_error);
		cout <<"Errore relativo con PALU (sistema " << i+1 << " ): " << relative_error << endl;
		QR_solution(coeff_matrix[i], rhs[i], exact_sol, relative_error);
		cout <<"Errore relativo con QR (sistema " << i+1 << " ): " << relative_error << endl;
	}		
} 