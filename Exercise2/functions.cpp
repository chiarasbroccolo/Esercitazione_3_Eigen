#include"Eigen/Eigen"
#include"functions.hpp"		//Includo l'header in cui sono dichiarate le funzioni

using namespace Eigen;

void PALU_solution (const Matrix2d &A, const Vector2d &b, const Vector2d &true_sol, double &err)
{
	/* Risolvo il sistema utilizzando la decomposizione LU con pivot parziale.
	   Ho deciso di utilizzare questo metodo, rispetto al pivoting completo, per le maggiori prestazioni su matrici piccole ben condizionate.
	   Ha precisone minore rispetto al full pivoting, ma fornisce comunque un'accuratezza sufficiente nella maggior parte dei casi. */
	
	Vector2d PALU_sol = A.partialPivLu().solve(b);
	
	/* Calcolo l'errore relativo tra la soluzione esatta e quella ottenuta tramite la decomposizione LU */
	
	err = ((true_sol-PALU_sol).norm())/(true_sol.norm());		//La funzione .norm() di Eigen è utilizzata per calcolare la norma dei vettori 
}

void QR_solution (const Matrix2d &A, const Vector2d &b, const Vector2d &true_sol, double &err)
{
	/* Risolvo il sistema utilizzando la decomposizione QR di Householder.
	   E' preferibile usare questo metodo per matrici di piccole dimensioni perchè, secondo la documentazione ufficiale di Eigen,
	   è computazionalmente efficiente e numericamente stabile. */
	
	Vector2d QR_sol = A.householderQr().solve(b);
	
	/* Calcolo l'errore relativo tra la soluzione esatta e quella ottenuta tramite il metodo QR */
	
	err = ((true_sol-QR_sol).norm())/(true_sol.norm());
}