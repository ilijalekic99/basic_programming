#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

/* 
Funkcija koja proverava da li je a[i] blizi elementu x
u odnosu na svoje susede (a[i-1] i a[i+1]).
NAPOMENA: treba voditi racuna o granicnim slucajevima, npr. ako je i=0,
onda ne sme da se proverava a[i-1].
*/
bool provera(int* a, int n, int i, int x)
{
    int razlika = abs(a[i] - x);

    if(i > 0 && i<n-1)
    {
        return razlika < abs(a[i-1] - x) && razlika <= abs(a[i+1] - x);
    }else if(i > 0)
    {
        return razlika < abs(a[i-1] - x);
    }
    else if(i < n-1)
    {
       return razlika <= abs(a[i+1] - x);
    }
}

int binarna_iterativno(int* a, int n, int x)
{
    int l = 0;
    int d = n-1;
    
    int s;
    
    while(l<=d)
    {
            s = (l + (d-l)/2);

            //Provera da li je najblizi
            if(provera(a, n, s, x))
                return s;
            else if(x < a[s])
                d = s-1;
            else
                l = s+1;
    }
    return -1;
}

int binarna_rekurzivno(int* a, int l, int d, int x, int n)
{
    if(l > d)
        return -1;
    
    int s = l + (d-l)/2;
    
    if(provera(a,n,s,x))
        return s;
    else if(x < a[s])
        return binarna_rekurzivno(a, l, s-1, x, n);
    else 
        return binarna_rekurzivno(a, s+1, d, x, n);
}

int main()
{
    int* a = NULL;
    int n, x;
    scanf("%d", &n);
    if(n <= 0)
        greska();
    
    a = malloc(n*sizeof(int));
    if(a == NULL)
        greska();
    
    int i;
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    
    printf("Unesite trazeni broj: ");
    scanf("%d", &x);
    
    int i1 = binarna_iterativno(a,n,x);
    int i2 = binarna_rekurzivno(a,0, n-1,x, n);
    
    printf("Iterativno: %d\n", a[i1]);
    printf("Rekurzivno: %d\n", a[i2]);

    return 0;
}
