#pragma once
#include"Eigen/Eigen"

using namespace Eigen;

/* Dichiarazione delle funzioni di risoluzione utilizzate nel programma principale
   Le matrici e i vettori sono passati per riferimento per evitare copie inutili e ridurre l'uso di memoria.
   Invece la variabile "err" è passata per riferimento costante perchè viene modificata all'interno delle funzioni*/

void PALU_solution (const Matrix2d &A, const Vector2d &b, const Vector2d &true_sol, double &err);
void QR_solution (const Matrix2d &A, const Vector2d &b, const Vector2d &true_sol, double &err);