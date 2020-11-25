#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100




void afficher_vect( float x[MAX],int n) {
	int i;
	for (i=0;i<n;i++) printf("%1f\n",x[i]);
	printf("\n");
}

void afficher_mat(float A[MAX][MAX] , int n) {
	int i,j;

	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			printf("%.1f\t",A[i][j]);
		}
		printf("\n");
	}
}

void remplir_vect( float x[MAX],int n) {
	int i;
	for (i=0;i<n;i++) {
		printf("valeur [%d] : ",i+1);
	    if (scanf("%f",&x[i]) !=1) printf("error");

	}

}

void vect_Init( float x[MAX],int n, int init) {
	int i;

	for (i=0;i<n;i++) x[i]=init;

}



void remplir_mat_tridiag(float A[MAX][MAX] , int n, float diagP, float diagInfSup) {
	int i,j;

	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
		if(i==j)
            A[i][j]=diagP;
        if((i==j-1)||(i==j+1))
           A[i][j]=diagInfSup;
		}
		printf("\n");
	}
}


float prod_mat_vect(float v[MAX], float A[MAX][MAX], float x[MAX], int n){
    int i, j;

    for(i=0 ; i<n ; i++){
        v[i]=0;
    }

        for(i=0 ; i<n ; i++){
            for(j=0 ; j<n ; j++){
                v[i] = v[i]+(A[i][j])*(x[j]);
            }
        }

    return v[MAX];
}


void vect_schema_explicite(float Vn1[MAX], float A[MAX][MAX], float Vn[MAX],float a[MAX], int n){

    int i,j;
    float Xn[MAX];

    for (i=1; i<n-1; i++){

        prod_mat_vect(Vn1,A,Vn,n);
        afficher_vect(Vn1,n);
        for(j=0; j<n; j++){
            Vn1[j]=Vn1[j]+ a[j];

        }
        afficher_vect(Vn1,n);
        for(j=0; j<n; j++){
            Vn[j]= Vn1[j];
        }
    }


    prod_mat_vect(Vn1,A,Vn,n);
    for(j=0; j<n; j++){
        Vn1[j]=Vn1[j]+ a[j];

    }
    //return Vn1[MAX];
}





void somme_vect(float u[MAX], float v[MAX], int n){
    int i;
    for (i=0;i<n;i++){
        u[i]= u[i]+v[i];
    }
}

int main() {
	int n;
	float x[MAX],b[MAX],y[MAX],Tn1[MAX], Tn[MAX],T0[MAX];

	float B[MAX][MAX],L[MAX][MAX],U[MAX][MAX];

	printf("Veuillez entrer la valeur de n : ");
	if (scanf("%d",&n) !=1) printf("error");


	remplir_mat_tridiag(B , n,1,2);
	afficher_mat(B,n);

	//printf("Veuillez remplir le vecteur T0 : \n");
	vect_Init(T0,n,2);
	afficher_vect(T0,n);

	vect_Init(x,n,12);
    afficher_vect(x,n);

    //remplir_vect(b,n);
   // prod_mat_vect(t,B,x,n);

    //afficher_vect(t,n);

    vect_schema_explicite(Tn1, B, x, T0, n);
    afficher_vect(Tn1,n);

	/*factoriser_LU(A,L,U,n);
	printf("Matrice L : \n");
	afficher_mat(L , n);
	printf("Matrice U : \n");
	afficher_mat(U , n);

	printf("Solution de Ly=b: \n");
	resol_trig_inf( L,y,b ,n);
	afficher_vect(y,n);


	printf("Solution de Ux=y: \n");
	resol_trig_sup( U,x,y ,n);
	afficher_vect(x,n); */







	return 0;
}

