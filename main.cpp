#include <iostream>
#include <string.h>
#include <random>

using namespace std;


///                     SPANZURATOARE

int n;/**lungime cuv**/

struct spanz{
    char l;
    bool gasita;
}cuvant[100];

///INITIALIZARE CUVANT
void i_c()
{
    int r = rand () %5;
    char cuv[100];

    if(r==0)
        strcpy(cuv,"renovare");
    else
    if(r==1)
        strcpy(cuv,"impacat");
    else
    if(r==2)
        strcpy(cuv,"omniprezent");
    else
    if(r==3)
        strcpy(cuv,"patura");
    else
    if(r==4)
        strcpy(cuv,"iubita");


    cuvant[0].l=cuv[0];
    cuvant[0].gasita=true;
    for(int i=1;i<strlen(cuv)-1;i++)
    {
        cuvant[i].l=cuv[i];
        cuvant[i].gasita=false;
    }
    cuvant[strlen(cuv)-1].l=cuv[strlen(cuv)-1];
    cuvant[strlen(cuv)-1].gasita=true;
    n=strlen(cuv);
}

///AFISARE SPANZURATOAREA
void a_spanz(int nr)
{
    if(nr==0)
    cout<<R"(
    _______________
        |    \ /
        |     |
        |
        |
        |
        |
        |
        |
        |
       / \
    __/___\__     )";
    else
    if(nr==1)
    cout<<R"(
    _______________
        |    \ /
        |     |
        |    / \
        |    \_/
        |
        |
        |
        |
        |
       / \
    __/___\__     )";
    else
    if(nr==2)
    cout<<R"(
    _______________
        |    \ /
        |     |
        |    / \
        |    \_/
        |     |
        |     |
        |     |
        |
        |
       / \
    __/___\__     )";
    else
    if(nr==3)
    cout<<R"(
    _______________
        |    \ /
        |     |
        |    / \
        |    \_/
        |   \ |
        |    \|
        |     |
        |
        |
       / \
    __/___\__     )";
    else
    if(nr==4)
    cout<<R"(
    _______________
        |    \ /
        |     |
        |    / \
        |    \_/
        |   \ | /
        |    \|/
        |     |
        |
        |
       / \
    __/___\__     )";
    else
    if(nr==5)
    cout<<R"(
    _______________
        |    \ /
        |     |
        |    / \
        |    \_/
        |   \ | /
        |    \|/
        |     |
        |    /
        |   /
       / \
    __/___\__     )";
    else
    if(nr==6)
    cout<<R"(
    _______________
        |    \ /
        |     |
        |    / \
        |    \_/
        |   \ | /
        |    \|/
        |     |
        |    / \
        |   /   \
       / \
    __/___\__     )";


}

///AFISARE CUVANT
void a_s_c()
{
    for(int i=0;i<n;i++)
    if(cuvant[i].gasita==true)
        cout<<cuvant[i].l;
    else
        cout<<"_";

    cout<<endl<<endl;
}

///VERIFICARE LITERA
int v_l(char l,int &nr)
{
    int k=0;
    for(int i=0;i<n;i++)
        if(l==cuvant[i].l)
        {
            cuvant[i].gasita=true;
            k=1;
        }

    if(k==0)
        return 0;
    else
        return 1;
}

///VERIFICARE CUVANT
int v_c()
{
    for(int i=0;i<n;i++)
    if(cuvant[i].gasita==false)
        return 0;

    return 1;
}

///SPANZURATOAREA
void spanzuratoare()
{
    char lit;
    int nr_g=0,c=0;

    i_c();
    while(nr_g<6 && c==0)
    {
        a_spanz(nr_g);
        a_s_c();
        cout<<endl<<endl;
        cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        cout<<"|            Ce litera vrei sa pui:";
        cin>>lit;

        if(v_l(lit,nr_g))
        cout<<"|      "<<lit<<" este in cuvantul tau                     |"<<endl<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        else
        {
            cout<<"|      "<<lit<<" nu este in cuvantul tau                  |"<<endl<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
            nr_g++;
        }
        system("pause");
        system("cls");
        c=v_c();
    }

    cout<<"gata joc!";
    a_spanz(nr_g);
    a_s_c();

}


///                     X SI 0

int a[10][10];

///AFISEAZA TABELA
///0 = gol 1 = x 2 = 0
void a_X_0(int a[10][10])
{
    cout<<endl<<endl;
    cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"     |        1    2    3        |"<<endl;
    for(int i=0;i<3;i++)
    {
    if(i==0)
        cout<<"     | a    ";
    else
    if(i==1)
        cout<<"     | b    ";
    else
    if(i==2)
        cout<<"     | c    ";

    for(int j=0;j<3;j++)
        if(a[i][j]==0)
            cout<<"|   |";
        else
        if(a[i][j]==1)
            cout<<"| x |";
        else
            cout<<"| 0 |";
    cout<<"      |"<<endl;
    }
    cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
}

/**
VERIFICA DACA E GATA SAU NU JOCUL
0 nu e gata jocul 1 e gata jocul
**/
int V_X_0()
{
    ///verifica daca a castigat cineva
    for(int i=0;i<3;i++)
    {
        if(a[i][0]==1 && a[i][1]==1 && a[i][2]==1)
            return 1;
        else
        if(a[i][0]==2 && a[i][1]==2 && a[i][2]==2)
            return 1;
        else
        if(a[0][i]==1 && a[1][i]==1 && a[2][i]==1)
            return 1;
        else
        if(a[0][i]==2 && a[1][i]==2 && a[2][i]==2)
            return 1;
    }
    if(a[0][0]==1 && a[1][1]==1 && a[2][2]==1)
        return 1;
    else
    if(a[0][0]==2 && a[1][1]==2 && a[2][2]==2)
        return 1;
    else
    if(a[0][2]==1 && a[1][1]==1 && a[2][0]==1)
        return 1;
    else
    if(a[0][2]==2 && a[1][1]==2 && a[2][0]==2)
        return 1;

    ///verifica daca e plina tabla
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
        if(a[i][j]==0)
            return 0;

    return 1;
}

///JUCATORUL PUNE 0
void pune_0(int a[10][10])
{
     string opt_l;
    int opt_c;

    a_X_0(a);
    cout<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"|    Pe ce coloana vrei sa pui?                   |"<<endl;
    cout<<"|    Raspuns('1','2','3'): ";
    cin>>opt_c;
    system("cls");

    while(opt_c!=1 && opt_c!=2 && opt_c!=3)
    {
    a_X_0(a);
    cout<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"|    OBTIUNE INTRODUSA GRESIT!                    |"<<endl;
    cout<<"|    Pe ce coloana vrei sa pui?                   |"<<endl;
    cout<<"|    Raspuns('1','2','3'): ";
    cin>>opt_c;
    system("cls");
    }

    a_X_0(a);
    cout<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"|    Pe ce linie vrei sa pui?                     |"<<endl;
    cout<<"|    Ai ales coloana "<<opt_c<<"                  |"<<endl;
    cout<<"|    Raspuns('a','b','c'): ";
    cin>>opt_l;
    system("cls");

    while(opt_l!="a" && opt_l!="b" && opt_l!="c")
    {
    a_X_0(a);
    cout<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"|    OBTIUNE INTRODUSA GRESIT!                    |"<<endl;
    cout<<"|    Pe ce linie vrei sa pui?                     |"<<endl;
    cout<<"|    Ai ales coloana "<<opt_c<<"                  |"<<endl;
    cout<<"|    Raspuns('a','b','c'): ";
    cin>>opt_l;
    system("cls");
    }

    if(opt_l=="a")
    {
        if(a[0][opt_c-1]==0)
            a[0][opt_c-1]=2;
        else
            pune_0(a);
    }
    else
    if(opt_l=="b")
    {
        if(a[1][opt_c-1]==0)
            a[1][opt_c-1]=2;
        else
            pune_0(a);
    }
    else
    if(opt_l=="c")
    {
        if(a[2][opt_c-1]==0)
            a[2][opt_c-1]=2;
        else
            pune_0(a);
    }

}

///JUCATORUL PUNE X
void pune_x(int a[10][10])
{
    string opt_l;
    int opt_c;

    /**AFISARE TABLA**/
    a_X_0(a);
    cout<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"|    Pe ce coloana vrei sa pui?                   |"<<endl;
    cout<<"|    Raspuns('1','2','3'): ";
    cin>>opt_c;
    system("cls");

    while(opt_c!=1 && opt_c!=2 && opt_c!=3)
    {
    a_X_0(a);
    cout<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"|    OBTIUNE INTRODUSA GRESIT!                    |"<<endl;
    cout<<"|    Pe ce coloana vrei sa pui?                   |"<<endl;
    cout<<"|    Raspuns('1','2','3'): ";
    cin>>opt_c;
    system("cls");
    }

    a_X_0(a);
    cout<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"|    Pe ce linie vrei sa pui?                     |"<<endl;
    cout<<"|    Ai ales coloana "<<opt_c<<"                  |"<<endl;
    cout<<"|    Raspuns('a','b','c'): ";
    cin>>opt_l;
    system("cls");

    while(opt_l!="a" && opt_l!="b" && opt_l!="c")
    {
    a_X_0(a);
    cout<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"|    OBTIUNE INTRODUSA GRESIT!                    |"<<endl;
    cout<<"|    Pe ce linie vrei sa pui?                     |"<<endl;
    cout<<"|    Ai ales coloana "<<opt_c<<"                  |"<<endl;
    cout<<"|    Raspuns('a','b','c'): ";
    cin>>opt_l;
    system("cls");
    }

    if(opt_l=="a")
    {
        if(a[0][opt_c-1]==0)
            a[0][opt_c-1]=1;
        else
            pune_x(a);
    }
    else
    if(opt_l=="b")
    {
        if(a[1][opt_c-1]==0)
            a[1][opt_c-1]=1;
        else
            pune_x(a);
    }
    else
    if(opt_l=="c")
    {
        if(a[2][opt_c-1]==0)
            a[2][opt_c-1]=1;
        else
            pune_x(a);
    }

}

///CALCLATORUL PUNE X (DIF GREU)
int pune_x_cg(int a[10][10])
{

   ///VERIFICA DACA POATE SA CASTIGE
   for(int i=0;i<3;i++)
   {
       ///LINIE
       if(a[i][0]==1 && a[i][1]==1 && a[i][2]==0)
       {
           a[i][2]=1;
           return 0;
       }
       else
       if(a[i][0]==1 && a[i][1]==0 && a[i][2]==1)
       {
           a[i][1]=1;
           return 0;
       }
       if(a[i][0]==0 && a[i][1]==1 && a[i][2]==1)
       {
           a[i][0]=1;
           return 0;
       }

       ///COLOANA
       if(a[0][i]==1 && a[1][i]==1 && a[2][i]==0)
       {
           a[2][i]=1;
           return 0;
       }
       else
       if(a[0][i]==1 && a[1][i]==0 && a[2][i]==1)
       {
           a[1][i]=1;
           return 0;
       }
       else
       if(a[0][i]==0 && a[1][i]==1 && a[2][i]==1)
       {
           a[0][i]=1;
           return 0;
       }
   }
   ///DIAGONALA
    if(a[0][0]==1 && a[1][1]==1 && a[2][2]==0)
    {
        a[2][2]=1;
        return 0;
    }
    else
    if(a[0][0]==1 && a[1][1]==0 && a[2][2]==1)
    {
        a[1][1]=1;
        return 0;
    }
    else
    if(a[0][0]==0 && a[1][1]==1 && a[2][2]==1)
    {
        a[0][0]=1;
        return 0;
    }
    else
    if(a[0][2]==1 && a[1][1]==1 && a[2][0]==0)
    {
        a[2][0]=1;
        return 0;
    }
    else
    if(a[0][2]==1 && a[1][1]==0 && a[2][0]==1)
    {
        a[1][1]=1;
        return 0;
    }
    else
    if(a[0][2]==0 && a[1][1]==1 && a[2][0]==1)
    {
        a[0][2]=1;
        return 0;
    }

   ///OPRESTE JUCATORUL DIN A CASTIGA
   for(int i=0;i<3;i++)
   {
       ///LINIE
       if(a[i][0]==2 && a[i][1]==2 && a[i][2]==0)
       {
           a[i][2]=1;
           return 0;
       }
       else
       if(a[i][0]==2 && a[i][1]==0 && a[i][2]==2)
       {
           a[i][1]=1;
           return 0;
       }
       if(a[i][0]==0 && a[i][1]==2 && a[i][2]==2)
       {
           a[i][0]=1;
           return 0;
       }

       ///COLOANA
       if(a[0][i]==2 && a[1][i]==2 && a[2][i]==0)
       {
           a[2][i]=1;
           return 0;
       }
       else
       if(a[0][i]==2 && a[1][i]==0 && a[2][i]==2)
       {
           a[1][i]=1;
           return 0;
       }
       else
       if(a[0][i]==0 && a[1][i]==2 && a[2][i]==2)
       {
           a[0][i]=1;
           return 0;
       }
   }
   ///DIAGONALA
    if(a[0][0]==2 && a[1][1]==2 && a[2][2]==0)
    {
        a[2][2]=1;
        return 0;
    }
    else
    if(a[0][0]==2 && a[1][1]==0 && a[2][2]==2)
    {
        a[1][1]=1;
        return 0;
    }
    else
    if(a[0][0]==0 && a[1][1]==2 && a[2][2]==2)
    {
        a[0][0]=1;
        return 0;
    }
    else
    if(a[0][2]==2 && a[1][1]==2 && a[2][0]==0)
    {
        a[2][0]=1;
        return 0;
    }
    else
    if(a[0][2]==2 && a[1][1]==0 && a[2][0]==2)
    {
        a[1][1]=1;
        return 0;
    }
    else
    if(a[0][2]==0 && a[1][1]==2 && a[2][0]==2)
    {
        a[0][2]=1;
        return 0;
    }


    ///PUNE RANDOM
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
        if(a[i][j]==0)
        {
            a[i][j]=1;
            return 0;
        }


   return 0;
}

///CALCLATORUL PUNE 0 (DIF GREU)
int pune_0_cg(int a[10][10])
{
     ///VERIFICA DACA POATE SA CASTIGE
   for(int i=0;i<3;i++)
   {
       ///LINIE
       if(a[i][0]==2 && a[i][1]==2 && a[i][2]==0)
       {
           a[i][2]=2;
           return 0;
       }
       else
       if(a[i][0]==2 && a[i][1]==0 && a[i][2]==2)
       {
           a[i][1]=2;
           return 0;
       }
       if(a[i][0]==0 && a[i][1]==2 && a[i][2]==2)
       {
           a[i][0]=2;
           return 0;
       }

       ///COLOANA
       if(a[0][i]==2 && a[1][i]==2 && a[2][i]==0)
       {
           a[2][i]=2;
           return 0;
       }
       else
       if(a[0][i]==2 && a[1][i]==0 && a[2][i]==2)
       {
           a[1][i]=2;
           return 0;
       }
       else
       if(a[0][i]==0 && a[1][i]==2 && a[2][i]==2)
       {
           a[0][i]=2;
           return 0;
       }
   }
   ///DIAGONALA
    if(a[0][0]==2 && a[1][1]==2 && a[2][2]==0)
    {
        a[2][2]=2;
        return 0;
    }
    else
    if(a[0][0]==2 && a[1][1]==0 && a[2][2]==2)
    {
        a[1][1]=2;
        return 0;
    }
    else
    if(a[0][0]==0 && a[1][1]==2 && a[2][2]==2)
    {
        a[0][0]=2;
        return 0;
    }
    else
    if(a[0][2]==2 && a[1][1]==2 && a[2][0]==0)
    {
        a[2][0]=2;
        return 0;
    }
    else
    if(a[0][2]==2 && a[1][1]==0 && a[2][0]==2)
    {
        a[1][1]=2;
        return 0;
    }
    else
    if(a[0][2]==0 && a[1][1]==2 && a[2][0]==2)
    {
        a[0][2]=2;
        return 0;
    }

   ///OPRESTE JUCATORUL DIN A CASTIGA
   for(int i=0;i<3;i++)
   {
       ///LINIE
       if(a[i][0]==1 && a[i][1]==1 && a[i][2]==0)
       {
           a[i][2]=2;
           return 0;
       }
       else
       if(a[i][0]==1 && a[i][1]==0 && a[i][2]==1)
       {
           a[i][1]=2;
           return 0;
       }
       if(a[i][0]==0 && a[i][1]==1 && a[i][2]==1)
       {
           a[i][0]=2;
           return 0;
       }

       ///COLOANA
       if(a[0][i]==1 && a[1][i]==1 && a[2][i]==0)
       {
           a[2][i]=2;
           return 0;
       }
       else
       if(a[0][i]==1 && a[1][i]==0 && a[2][i]==1)
       {
           a[1][i]=2;
           return 0;
       }
       else
       if(a[0][i]==0 && a[1][i]==1 && a[2][i]==1)
       {
           a[0][i]=2;
           return 0;
       }
   }
   ///DIAGONALA
    if(a[0][0]==1 && a[1][1]==1 && a[2][2]==0)
    {
        a[2][2]=2;
        return 0;
    }
    else
    if(a[0][0]==1 && a[1][1]==0 && a[2][2]==1)
    {
        a[1][1]=2;
        return 0;
    }
    else
    if(a[0][0]==0 && a[1][1]==1 && a[2][2]==1)
    {
        a[0][0]=2;
        return 0;
    }
    else
    if(a[0][2]==1 && a[1][1]==1 && a[2][0]==0)
    {
        a[2][0]=2;
        return 0;
    }
    else
    if(a[0][2]==1 && a[1][1]==0 && a[2][0]==1)
    {
        a[1][1]=2;
        return 0;
    }
    else
    if(a[0][2]==0 && a[1][1]==1 && a[2][0]==1)
    {
        a[0][2]=2;
        return 0;
    }


    ///PUNE RANDOM
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
        if(a[i][j]==0)
        {
            a[i][j]=2;
            return 0;
        }


   return 0;
}

///DACA JUCATORUL VREA SA JOACE CU X USOR
void X_0_x_u(int a[10][10])
{
    while(V_X_0()==0)
    {
    if(V_X_0()==0)
        pune_x(a);
    if(V_X_0()==0)
    {
        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(a[i][j]==0)
            {
                a[i][j]=2;
                i=4;
                j=4;
            }
    }
    }
}

///DACA JUCATORUL VREA SA JOACE CU X GREU
void X_0_x_g(int a[10][10])
{
    while(V_X_0()==0)
    {
    if(V_X_0()==0)
        pune_x(a);
    if(V_X_0()==0)
        pune_0_cg(a);
    }
}

///DACA JUCATORUL VREA SA JOACE CU 0 USOR
void X_0_0_u(int a[10][10])
{
    while(V_X_0()==0)
    {
    if(V_X_0()==0)
    {
        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(a[i][j]==0)
            {
                a[i][j]=1;
                i=4;
                j=4;
            }
    }
    if(V_X_0()==0)
        pune_0(a);
    }
}

///DACA JUCATORUL VREA SA JOACE CU 0 GREU
void X_0_0_g(int a[10][10])
{
    while(V_X_0()==0)
    {
    if(V_X_0()==0)
        pune_x_cg(a);
    if(V_X_0()==0)
        pune_0(a);
    }
}

///MENIU X SI 0
void X_0(int a[10][10])
{
    string opt_xsau0,opt_dif;

    /**CREARE TABLA**/
    for(int i=0;i<=10;i++)
    for(int j=0;j<=10;j++)
        a[i][j]=0;

    /**OBTIUNI JOC**/
    cout<<endl<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"|    Vrei sa joci cu 'X' sau cu '0'?              |"<<endl;
    cout<<"|    Raspuns('X' sau '0'): ";
    cin>>opt_xsau0;
    system("cls");

    while(opt_xsau0!="X" && opt_xsau0!="0")
    {
    cout<<endl<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"|    OPTIUNE INTRODUSA GRESIT!                    |"<<endl;
    cout<<"|    Vrei sa joci cu 'X' sau cu '0'?              |"<<endl;
    cout<<"|    Raspuns('X' sau '0'): ";
    cin>>opt_xsau0;
    system("cls");
    }

    cout<<endl<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"|    Ce dificultate vrei?                         |"<<endl;
    cout<<"|    Raspuns('GREU' sau 'USOR'): ";
    cin>>opt_dif;
    system("cls");

    while(opt_dif!="GREU" && opt_dif!="USOR")
    {
    cout<<endl<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"|    OPTIUNE INTRODUSA GRESIT!                    |"<<endl;
    cout<<"|    Ce dificultate vrei?                         |"<<endl;
    cout<<"|    Raspuns('GREU' sau 'USOR'): ";
    cin>>opt_dif;
    system("cls");
    }

    /**INCEPERE JOC**/
    if(opt_xsau0=="X")
    {
       if(opt_dif=="GREU")
            X_0_x_g(a);
       else
            X_0_x_u(a);
    }
    else
    {
        if(opt_dif=="GREU")
            X_0_0_g(a);
        else
            X_0_0_u(a);
    }
    cout<<endl<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"|              TABELA FINALA ESTE!                 |"<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    a_X_0(a);

}


///                              ZARURI

///ANIMATIE FAINA CAND "ARUNCI" ZARURILE
void zar_rnd()
{
    int i,j,z;
      i=rand()%5;
      z=rand()%6;
    for(j=1;j<=50;j++)
        {
        i=rand()%5;
        z=rand()%6;
    if(i==0)
        system("Color 0A");
    if(i==1)
        system("Color 0B");
    if(i==2)
        system("Color 0D");
    if(i==3)
        system("Color 0E");
    if(i==4)
        system("Color 0F");
    if(i==5)
        system("Color 09");

    if(z==1)
        cout<<R"(
       _______
      |       |
      |   o   |
      |       |
      '-------')"<<endl;
    if(z==2)
        cout<<R"(
       _______
      | o     |
      |       |
      |     o |
      '-------')"<<endl;
    if(z==3)
        cout<<R"(
       _______
      | o     |
      |   o   |
      |     o |
      '-------')"<<endl;
    if(z==4)
        cout<<R"(
       _______
      | o   o |
      |       |
      | o   o |
      '-------')"<<endl;
    if(z==5)
        cout<<R"(
       _______
      | o   o |
      |   o   |
      | o   o |
      '-------')"<<endl;
    if(z==6)
        cout<<R"(
       _______
      | o   o |
      | o   o |
      | o   o |
      '-------')"<<endl;
        }
        system("cls");
}

///AFISARE ZARURI

/**

    if(z1==1)
    {
    if(z2==1)
            cout<<R"(
|       _______                _______      |
|      |       |              |       |     |
|      |   o   |              |   o   |     |
|      |       |              |       |     |
|      '-------'              '-------'     |)";
    else
    if(z2==2)
    cout<<R"(
|       _______                _______      |
|      |       |              | o     |     |
|      |   o   |              |       |     |
|      |       |              |     o |     |
|      '-------'              '-------'     |)";
    else
    if(z2==3)
        cout<<R"(
|       _______                _______      |
|      |       |              | o     |     |
|      |   o   |              |   o   |     |
|      |       |              |     o |     |
|      '-------'              '-------'     |)";
    else
    if(z2==4)
        cout<<R"(
|       _______                _______      |
|      |       |              | o   o |     |
|      |   o   |              |       |     |
|      |       |              | o   o |     |
|      '-------'              '-------'     |)";
    else
    if(z2==5)
    cout<<R"(
|       _______                _______      |
|      |       |              | o   o |     |
|      |   o   |              |   o   |     |
|      |       |              | o   o |     |
|      '-------'              '-------'     |)";
    else
    if(z2==6)
    cout<<R"(
|       _______                _______      |
|      |       |              | o   o |     |
|      |   o   |              | o   o |     |
|      |       |              | o   o |     |
|      '-------'              '-------'     |)";
    }

    if(z1==2)
    {
      if(z2==1)
            cout<<R"(
|       _______                _______      |
|      | o     |              |       |     |
|      |       |              |   o   |     |
|      |     o |              |       |     |
|      '-------'              '-------'     |)";
    else
    if(z2==2)
    cout<<R"(
|       _______                _______      |
|      | o     |              | o     |     |
|      |       |              |       |     |
|      |     o |              |     o |     |
|      '-------'              '-------'     |)";
    else
    if(z2==3)
        cout<<R"(
|       _______                _______      |
|      | o     |              | o     |     |
|      |       |              |   o   |     |
|      |     o |              |     o |     |
|      '-------'              '-------'     |)";
    else
    if(z2==4)
        cout<<R"(
|       _______                _______      |
|      | o     |              | o   o |     |
|      |       |              |       |     |
|      |     o |              | o   o |     |
|      '-------'              '-------'     |)";
    else
    if(z2==5)
    cout<<R"(
|       _______                _______      |
|      | o     |              | o   o |     |
|      |       |              |   o   |     |
|      |     o |              | o   o |     |
|      '-------'              '-------'     |)";
    else
    if(z2==6)
    cout<<R"(
|       _______                _______      |
|      | o     |              | o   o |     |
|      |       |              | o   o |     |
|      |     o |              | o   o |     |
|      '-------'              '-------'     |)";
    }

    if(z1==3)
    {
    if(z2==1)
            cout<<R"(
|       _______                _______      |
|      | o     |              |       |     |
|      |   o   |              |   o   |     |
|      |     o |              |       |     |
|      '-------'              '-------'     |)";
    else
    if(z2==2)
    cout<<R"(
|       _______                _______      |
|      | o     |              | o     |     |
|      |   o   |              |       |     |
|      |     o |              |     o |     |
|      '-------'              '-------'     |)";
    else
    if(z2==3)
        cout<<R"(
|       _______                _______      |
|      | o     |              | o     |     |
|      |   o   |              |   o   |     |
|      |     o |              |     o |     |
|      '-------'              '-------'     |)";
    else
    if(z2==4)
        cout<<R"(
|       _______                _______      |
|      | o     |              | o   o |     |
|      |   o   |              |       |     |
|      |     o |              | o   o |     |
|      '-------'              '-------'     |)";
    else
    if(z2==5)
    cout<<R"(
|       _______                _______      |
|      | o     |              | o   o |     |
|      |   o   |              |   o   |     |
|      |     o |              | o   o |     |
|      '-------'              '-------'     |)";
    else
    if(z2==6)
    cout<<R"(
|       _______                _______      |
|      | o     |              | o   o |     |
|      |   o   |              | o   o |     |
|      |     o |              | o   o |     |
|      '-------'              '-------'     |)";
    }

    if(z1==4)
    {
        if(z2==1)
            cout<<R"(
|       _______                _______      |
|      | o   o |              |       |     |
|      |       |              |   o   |     |
|      | o   o |              |       |     |
|      '-------'              '-------'     |)";
    else
    if(z2==2)
    cout<<R"(
|       _______                _______      |
|      | o   o |              | o     |     |
|      |       |              |       |     |
|      | o   o |              |     o |     |
|      '-------'              '-------'     |)";
    else
    if(z2==3)
        cout<<R"(
|       _______                _______      |
|      | o   o |              | o     |     |
|      |       |              |   o   |     |
|      | o   o |              |     o |     |
|      '-------'              '-------'     |)";
    else
    if(z2==4)
        cout<<R"(
|       _______                _______      |
|      | o   o |              | o   o |     |
|      |       |              |       |     |
|      | o   o |              | o   o |     |
|      '-------'              '-------'     |)";
    else
    if(z2==5)
    cout<<R"(
|       _______                _______      |
|      | o   o |              | o   o |     |
|      |       |              |   o   |     |
|      | o   o |              | o   o |     |
|      '-------'              '-------'     |)";
    else
    if(z2==6)
    cout<<R"(
|       _______                _______      |
|      | o   o |              | o   o |     |
|      |       |              | o   o |     |
|      | o   o |              | o   o |     |
|      '-------'              '-------'     |)";
    }

    if(z1==5)
    {
        if(z2==1)
            cout<<R"(
|       _______                _______      |
|      | o   o |              |       |     |
|      |   o   |              |   o   |     |
|      | o   o |              |       |     |
|      '-------'              '-------'     |)";
    else
    if(z2==2)
    cout<<R"(
|       _______                _______      |
|      | o   o |              | o     |     |
|      |   o   |              |       |     |
|      | o   o |              |     o |     |
|      '-------'              '-------'     |)";
    else
    if(z2==3)
        cout<<R"(
|       _______                _______      |
|      | o   o |              | o     |     |
|      |   o   |              |   o   |     |
|      | o   o |              |     o |     |
|      '-------'              '-------'     |)";
    else
    if(z2==4)
        cout<<R"(
|       _______                _______      |
|      | o   o |              | o   o |     |
|      |   o   |              |       |     |
|      | o   o |              | o   o |     |
|      '-------'              '-------'     |)";
    else
    if(z2==5)
    cout<<R"(
|       _______                _______      |
|      | o   o |              | o   o |     |
|      |   o   |              |   o   |     |
|      | o   o |              | o   o |     |
|      '-------'              '-------'     |)";
    else
    if(z2==6)
    cout<<R"(
|       _______                _______      |
|      | o   o |              | o   o |     |
|      |   o   |              | o   o |     |
|      | o   o |              | o   o |     |
|      '-------'              '-------'     |)";
    }

    if(z1==6)
    {
    if(z2==1)
            cout<<R"(
|       _______                _______      |
|      | o   o |              |       |     |
|      | o   o |              |   o   |     |
|      | o   o |              |       |     |
|      '-------'              '-------'     |)";
    else
    if(z2==2)
    cout<<R"(
|       _______                _______      |
|      | o   o |              | o     |     |
|      | o   o |              |       |     |
|      | o   o |              |     o |     |
|      '-------'              '-------'     |)";
    else
    if(z2==3)
        cout<<R"(
|       _______                _______      |
|      | o   o |              | o     |     |
|      | o   o |              |   o   |     |
|      | o   o |              |     o |     |
|      '-------'              '-------'     |)";
    else
    if(z2==4)
        cout<<R"(
|       _______                _______      |
|      | o   o |              | o   o |     |
|      | o   o |              |       |     |
|      | o   o |              | o   o |     |
|      '-------'              '-------'     |)";
    else
    if(z2==5)
    cout<<R"(
|       _______                _______      |
|      | o   o |              | o   o |     |
|      | o   o |              |   o   |     |
|      | o   o |              | o   o |     |
|      '-------'              '-------'     |)";
    else
    if(z2==6)
    cout<<R"(
|       _______                _______      |
|      | o   o |              | o   o |     |
|      | o   o |              | o   o |     |
|      | o   o |              | o   o |     |
|      '-------'              '-------'     |)";
    }
**/
void afisare_zaruri(int z1,int z2)
{

    if(z1==1)
    {
    if(z2==1)
            cout<<R"(
|       _______                _______
|      |       |              |       |
|      |   o   |              |   o   |
|      |       |              |       |
|      '-------'              '-------'     )";
    else
    if(z2==2)
    cout<<R"(
|       _______                _______
|      |       |              | o     |
|      |   o   |              |       |
|      |       |              |     o |
|      '-------'              '-------'     )";
    else
    if(z2==3)
        cout<<R"(
|       _______                _______
|      |       |              | o     |
|      |   o   |              |   o   |
|      |       |              |     o |
|      '-------'              '-------'     )";
    else
    if(z2==4)
        cout<<R"(
|       _______                _______
|      |       |              | o   o |
|      |   o   |              |       |
|      |       |              | o   o |
|      '-------'              '-------'     )";
    else
    if(z2==5)
    cout<<R"(
|       _______                _______
|      |       |              | o   o |
|      |   o   |              |   o   |
|      |       |              | o   o |
|      '-------'              '-------'     )";
    else
    if(z2==6)
    cout<<R"(
|       _______                _______
|      |       |              | o   o |
|      |   o   |              | o   o |
|      |       |              | o   o |
|      '-------'              '-------'     )";
    }

    if(z1==2)
    {
      if(z2==1)
            cout<<R"(
|       _______                _______
|      | o     |              |       |
|      |       |              |   o   |
|      |     o |              |       |
|      '-------'              '-------'     )";
    else
    if(z2==2)
    cout<<R"(
|       _______                _______
|      | o     |              | o     |
|      |       |              |       |
|      |     o |              |     o |
|      '-------'              '-------'     )";
    else
    if(z2==3)
        cout<<R"(
|       _______                _______
|      | o     |              | o     |
|      |       |              |   o   |
|      |     o |              |     o |
|      '-------'              '-------'     )";
    else
    if(z2==4)
        cout<<R"(
|       _______                _______
|      | o     |              | o   o |
|      |       |              |       |
|      |     o |              | o   o |
|      '-------'              '-------'     )";
    else
    if(z2==5)
    cout<<R"(
|       _______                _______
|      | o     |              | o   o |
|      |       |              |   o   |
|      |     o |              | o   o |
|      '-------'              '-------'     )";
    else
    if(z2==6)
    cout<<R"(
|       _______                _______
|      | o     |              | o   o |
|      |       |              | o   o |
|      |     o |              | o   o |
|      '-------'              '-------'     )";
    }

    if(z1==3)
    {
    if(z2==1)
            cout<<R"(
|       _______                _______
|      | o     |              |       |
|      |   o   |              |   o   |
|      |     o |              |       |
|      '-------'              '-------'     )";
    else
    if(z2==2)
    cout<<R"(
|       _______                _______
|      | o     |              | o     |
|      |   o   |              |       |
|      |     o |              |     o |
|      '-------'              '-------'     )";
    else
    if(z2==3)
        cout<<R"(
|       _______                _______
|      | o     |              | o     |
|      |   o   |              |   o   |
|      |     o |              |     o |
|      '-------'              '-------'     )";
    else
    if(z2==4)
        cout<<R"(
|       _______                _______
|      | o     |              | o   o |
|      |   o   |              |       |
|      |     o |              | o   o |
|      '-------'              '-------'     )";
    else
    if(z2==5)
    cout<<R"(
|       _______                _______
|      | o     |              | o   o |
|      |   o   |              |   o   |
|      |     o |              | o   o |
|      '-------'              '-------'     )";
    else
    if(z2==6)
    cout<<R"(
|       _______                _______
|      | o     |              | o   o |
|      |   o   |              | o   o |
|      |     o |              | o   o |
|      '-------'              '-------'     )";
    }

    if(z1==4)
    {
        if(z2==1)
            cout<<R"(
|       _______                _______
|      | o   o |              |       |
|      |       |              |   o   |
|      | o   o |              |       |
|      '-------'              '-------'     )";
    else
    if(z2==2)
    cout<<R"(
|       _______                _______
|      | o   o |              | o     |
|      |       |              |       |
|      | o   o |              |     o |
|      '-------'              '-------'     )";
    else
    if(z2==3)
        cout<<R"(
|       _______                _______
|      | o   o |              | o     |
|      |       |              |   o   |
|      | o   o |              |     o |
|      '-------'              '-------'     )";
    else
    if(z2==4)
        cout<<R"(
|       _______                _______
|      | o   o |              | o   o |
|      |       |              |       |
|      | o   o |              | o   o |
|      '-------'              '-------'     )";
    else
    if(z2==5)
    cout<<R"(
|       _______                _______
|      | o   o |              | o   o |
|      |       |              |   o   |
|      | o   o |              | o   o |
|      '-------'              '-------'     )";
    else
    if(z2==6)
    cout<<R"(
|       _______                _______
|      | o   o |              | o   o |
|      |       |              | o   o |
|      | o   o |              | o   o |
|      '-------'              '-------'     )";
    }

    if(z1==5)
    {
        if(z2==1)
            cout<<R"(
|       _______                _______
|      | o   o |              |       |
|      |   o   |              |   o   |
|      | o   o |              |       |
|      '-------'              '-------'     )";
    else
    if(z2==2)
    cout<<R"(
|       _______                _______
|      | o   o |              | o     |
|      |   o   |              |       |
|      | o   o |              |     o |
|      '-------'              '-------'     )";
    else
    if(z2==3)
        cout<<R"(
|       _______                _______
|      | o   o |              | o     |
|      |   o   |              |   o   |
|      | o   o |              |     o |
|      '-------'              '-------'     )";
    else
    if(z2==4)
        cout<<R"(
|       _______                _______
|      | o   o |              | o   o |
|      |   o   |              |       |
|      | o   o |              | o   o |
|      '-------'              '-------'     )";
    else
    if(z2==5)
    cout<<R"(
|       _______                _______
|      | o   o |              | o   o |
|      |   o   |              |   o   |
|      | o   o |              | o   o |
|      '-------'              '-------'     )";
    else
    if(z2==6)
    cout<<R"(
|       _______                _______
|      | o   o |              | o   o |
|      |   o   |              | o   o |
|      | o   o |              | o   o |
|      '-------'              '-------'     )";
    }

    if(z1==6)
    {
    if(z2==1)
            cout<<R"(
|       _______                _______
|      | o   o |              |       |
|      | o   o |              |   o   |
|      | o   o |              |       |
|      '-------'              '-------'     )";
    else
    if(z2==2)
    cout<<R"(
|       _______                _______
|      | o   o |              | o     |
|      | o   o |              |       |
|      | o   o |              |     o |
|      '-------'              '-------'     )";
    else
    if(z2==3)
        cout<<R"(
|       _______                _______
|      | o   o |              | o     |
|      | o   o |              |   o   |
|      | o   o |              |     o |
|      '-------'              '-------'     )";
    else
    if(z2==4)
        cout<<R"(
|       _______                _______
|      | o   o |              | o   o |
|      | o   o |              |       |
|      | o   o |              | o   o |
|      '-------'              '-------'     )";
    else
    if(z2==5)
    cout<<R"(
|       _______                _______
|      | o   o |              | o   o |
|      | o   o |              |   o   |
|      | o   o |              | o   o |
|      '-------'              '-------'     )";
    else
    if(z2==6)
    cout<<R"(
|       _______                _______
|      | o   o |              | o   o |
|      | o   o |              | o   o |
|      | o   o |              | o   o |
|      '-------'              '-------'     )";
    }
}

///ZARURI
void Zaruri()
{
    int z1_b,z2_b,z1_adversar,z2_adversar;
    cout<<endl<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<R"(
                    ______
        .-------.  /\     \
       /   o   /| /o \  o  \
      /_______/o|/   o\_____\
      | o     | |\o   /o    /
      |   o   |o/ \ o/  o  /
      |     o |/   \/____o/
      '-------'

      )"<<endl;

    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<endl<<endl;
    system("pause");
    system("cls");

    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"|    Arunca zarurile!                             |"<<endl;
    zar_rnd();

    for(int i=1;i<=10;i++)
        {
        z1_b = rand() % 6+1;
        }
    for(int i=1;i<=10;i++)
        {
        z2_b = rand() % 6+1;
        }
    z1_adversar = rand() % 6+1;
    for(int i=1;i<=10;i++)
        {
        z1_adversar = rand() % 6+1;
        }

    for(int i=1;i<=10;i++)
        {
        z2_adversar = rand() % 6+1;
        }
    cout<<endl<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"|    Zarurile mele          Zarurile adversarului           |"<<endl;
    afisare_zaruri(z1_b,z1_adversar);
    afisare_zaruri(z2_b,z2_adversar);
    cout<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;


    if(z1_adversar+z2_adversar==z1_b+z2_b)
    {
        cout<<endl<<endl;
        cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        cout<<"|                 Egalitate!                      |"<<endl;
        cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    }
    else
    if(z1_b==1 && z2_b==1 && (z1_adversar!=1 || z2_adversar!=1))
    {
        cout<<endl<<endl;
        cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        cout<<"|                 Ai castigat!                    |"<<endl;
        cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    }
    else
    if(z1_b+z2_b > z1_adversar+z2_adversar && (z1_adversar!=1 || z2_adversar!=1))
    {
        cout<<endl<<endl;
        cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        cout<<"|                 Ai castigat!                    |"<<endl;
        cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    }
    else
    if(z1_adversar==1 && z2_adversar==1 && (z1_b!=1 || z2_b!=1))
    {
        cout<<endl<<endl;
        cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        cout<<"|                 Ai pierdut!                     |"<<endl;
        cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    }
    else
    if(z1_adversar+z2_adversar > z1_b+z2_b && (z1_b!=1 || z2_b!=1))
    {
        cout<<endl<<endl;
        cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        cout<<"|                 Ai pierdut!                     |"<<endl;
        cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    }

    system("pause");
    system("cls");
}


///                         AVIOANELE


int b[10][10]/**JUCATOR 1**/,c[10][10]/**JUCATOR 2**/;

///AFISARE TABLA AVIOANE JUCATOR 1
void a_a_tabla_1()
{
    cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"     |               TABLA JUCATORULUI 1             |"<<endl;
    cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"     |        A    B    C    D    E    F    G        |"<<endl;
    for(int i=0;i<7;i++)
    {
    cout<<"     | "<<i+1<<"    ";
    for(int j=0;j<7;j++)
        {
        if(b[i][j]==0)
            cout<<"|   |";
        else
        if(b[i][j]==1 )
            cout<<"| % |";
        else
        if(b[i][j]==2)
            cout<<"| X |";
        }
    cout<<"      |"<<endl;
    }
    cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
}

///AFISARE TABLA AVIOANE JUCATOR 2
void a_a_tabla_2()
{

    cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"     |               TABLA JUCATORULUI 2             |"<<endl;
    cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"     |        A    B    C    D    E    F    G        |"<<endl;
    for(int i=0;i<7;i++)
    {
    cout<<"     | "<<i+1<<"    ";
    for(int j=0;j<7;j++)
        {
        if(c[i][j]==0)
            cout<<"|   |";
        else
        if(c[i][j]==1)
            cout<<"| % |";
        else
        if(c[i][j]==2)
            cout<<"| X |";
        }
    cout<<"      |"<<endl;
    }
    cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
}

///INITIALIZEAZA TABLELE
void i_t()
{
    for(int i=0;i<7;i++)
    for(int j=0;j<7;j++)
    {
        b[i][j]=0;
        c[i][j]=0;
    }
}

///VERIFICA DACA JUCATORUL 1 A CASTIGAT (cauta daca j2 mai are avioane)
int v_c_1()
{
    for(int i=0;i<7;i++)
    for(int j=0;j<7;j++)
       if(c[i][j]==1)
            return 0;
    return 1;
}

///VERIFICA DACA JUCATORUL 2 A CASTIGAT (cauta daca j1 mai are avioane)
int v_c_2()
{
    for(int i=0;i<7;i++)
    for(int j=0;j<7;j++)
       if(b[i][j]==1)
            return 0;
    return 1;
}

///VERIFICA DACA SPATIUL ALES DE JUCATORUL 1 E OK PT AVION
int v_s_oc_1(int l,int k,int nr)
{
    int ok=1;
    if(l>7 || k+nr>7 || l<0 || k<0)
        return 0;
    for(int i=0;i<nr;i++)
        if(b[l][k+i]==1)
         ok=0;
    return ok;
}

///VERIFICA DACA SPATIUL ALES DE JUCATORUL 2 E OK PT AVION
int v_s_oc_2(int l,int k,int nr)
{
    int ok=1;
    if(l>7 || k+nr>7 || l<0 || k<0)
        return 0;
    for(int i=0;i<nr;i++)
        if(c[l][k+1]==1)
            ok=0;
    return ok;
}

///JUCATORUL 1 ISI PUNE AVIOANELE
void p_a_1()
{
    int l,c_i,spatiu_ocupat;
    char c_c;

        a_a_tabla_1();
        cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        cout<<"     |           Vreau sa pun pe linia: ";
        cin>>l;
        l--;
        cout<<"     |           Coloana: ";
        cin>>c_c;

        c_i=c_c-65;

        system("cls");
        spatiu_ocupat=v_s_oc_1(l,c_i,2);
        while(spatiu_ocupat==0)
        {
        cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        cout<<"     |               Eroare                          |"<<endl;
        a_a_tabla_1();
        cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        cout<<"     |           Vreau sa pun pe linia: ";
        cin>>l;
        l--;
        cout<<"     |           Coloana: ";
        cin>>c_c;

        c_i=c_c-65;
        system("cls");
        spatiu_ocupat=v_s_oc_1(l,c_i,2);
        }
        b[l][c_i]=1;
        b[l][c_i+1]=1;


        a_a_tabla_1();
        cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        cout<<"     |           Vreau sa pun pe linia: ";
        cin>>l;
        l--;
        cout<<"     |           Coloana: ";
        cin>>c_c;

        c_i=c_c-65;
        system("cls");
        spatiu_ocupat=v_s_oc_1(l,c_i,3);
        while(spatiu_ocupat==0)
        {
        cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        cout<<"     |               Eroare                          |"<<endl;
        a_a_tabla_1();
        cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        cout<<"     |           Vreau sa pun pe linia: ";
        cin>>l;
        l--;
        cout<<"     |           Coloana: ";
        cin>>c_c;

        c_i=c_c-65;
        system("cls");
        spatiu_ocupat=v_s_oc_1(l,c_i,3);
        }
        b[l][c_i]=1;
        b[l][c_i+1]=1;
        b[l][c_i+2]=1;

    a_a_tabla_1();
        cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        cout<<"     |           Vreau sa pun pe linia: ";
        cin>>l;
        l--;
        cout<<"     |           Coloana: ";
        cin>>c_c;
        system("cls");
        c_i=c_c-65;

    spatiu_ocupat=v_s_oc_1(l,c_i,4);
    while(spatiu_ocupat==0)
    {
    cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"     |               Eroare                          |"<<endl;
    a_a_tabla_1();
    cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"     |           Vreau sa pun pe linia: ";
    cin>>l;
    l--;
    cout<<"     |           Coloana: ";
    cin>>c_c;

        c_i=c_c-65;
    system("cls");
    spatiu_ocupat=v_s_oc_1(l,c_i,4);
    }

    b[l][c_i]=1;
    b[l][c_i+1]=1;
    b[l][c_i+2]=1;
    b[l][c_i+3]=1;

    a_a_tabla_1();
    system("pause");
    system("cls");
}

///JUCATORUL 2 ISI PUNE AVIOANELE
void p_a_2()
{
    int l,c_i,spatiu_ocupat;
    char c_c;

        a_a_tabla_2();
        cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        cout<<"     |           Vreau sa pun pe linia: ";
        cin>>l;
                l--;

        cout<<"     |           Coloana: ";
        cin>>c_c;

        c_i=c_c-65;
        system("cls");
        spatiu_ocupat=v_s_oc_2(l,c_i,2);
        while(spatiu_ocupat==0)
        {
        cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        cout<<"     |               Eroare                          |"<<endl;
        a_a_tabla_2();
        cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        cout<<"     |           Vreau sa pun pe linia: ";
        cin>>l;
                l--;

        cout<<"     |           Coloana: ";
        cin>>c_c;

        c_i=c_c-65;
        system("cls");
        spatiu_ocupat=v_s_oc_2(l,c_i,2);
        }
        c[l][c_i]=1;
        c[l][c_i+1]=1;


        a_a_tabla_2();
        cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        cout<<"     |           Vreau sa pun pe linia: ";
        cin>>l;
                l--;

        cout<<"     |           Coloana: ";
        cin>>c_c;

        c_i=c_c-65;
        system("cls");
        spatiu_ocupat=v_s_oc_2(l,c_i,3);
        while(spatiu_ocupat==0)
        {
        cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        cout<<"     |               Eroare                          |"<<endl;
        a_a_tabla_2();
        cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        cout<<"     |           Vreau sa pun pe linia: ";
        cin>>l;
                l--;

        cout<<"     |           Coloana: ";
        cin>>c_c;

        c_i=c_c-65;
        system("cls");
        spatiu_ocupat=v_s_oc_2(l,c_i,3);
        }

        c[l][c_i]=1;
        c[l][c_i+1]=1;
        c[l][c_i+2]=1;

    a_a_tabla_2();
        cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        cout<<"     |           Vreau sa pun pe linia: ";
        cin>>l;
                l--;

        cout<<"     |           Coloana: ";
        cin>>c_c;
        system("cls");
        c_i=c_c-65;

        spatiu_ocupat=v_s_oc_2(l,c_i,4);
        while(spatiu_ocupat==0)
        {
        cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        cout<<"     |               Eroare                          |"<<endl;
        a_a_tabla_2();
        cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        cout<<"     |           Vreau sa pun pe linia: ";
        cin>>l;
                l--;

        cout<<"     |           Coloana: ";
        cin>>c_c;
        c_i=c_c-65;

        system("cls");
        spatiu_ocupat=v_s_oc_2(l,c_i,4);

        }



    c[l][c_i]=1;
    c[l][c_i+1]=1;
    c[l][c_i+2]=1;
    c[l][c_i+3]=1;

    a_a_tabla_2();
    system("pause");
    system("cls");
}

///ATACA JUCATORUL 1
void at_1()
{
    int l,c_i;
    char c_c;
    a_a_tabla_1();
    cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"     |           Vreau sa atac pe linia: ";
    cin>>l;
        l--;

    cout<<"     |           Coloana: ";
    cin>>c_c;

    c_i=c_c-65;
    while(l<0 || l>6|| c_i<0 || c_i>6)
    {
    system("cls");
    a_a_tabla_1();
    cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"     |               Eroare                          |"<<endl;
    cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"     |           Vreau sa atac pe linia: ";
    cin>>l;
        l--;

    cout<<"     |           Coloana: ";
    cin>>c_c;

    c_i=c_c-65;

    }

    if(c[l][c_i]==1)
    {
        cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        cout<<"     |               Ai nimerit!                     |"<<endl;
        cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        c[l][c_i]=2;
    }
    else
    {
        cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        cout<<"     |               Nu ai nimerit!                  |"<<endl;
        cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    }
    system("pause");
    system("cls");
}

///ATACA JUCATORUL 2
void at_2()
{
    int l,c_i;
    char c_c;
    a_a_tabla_2();
    cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"     |           Vreau sa atac pe linia: ";
    cin>>l;
            l--;

    cout<<"     |           Coloana: ";
    cin>>c_c;

    c_i=c_c-65;
    while(l<0 || l>6 || c_i<0 || c_i>6)
    {
    system("cls");
    a_a_tabla_2();
    cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"     |               Eroare                          |"<<endl;
    cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"     |           Vreau sa atac pe linia: ";
    cin>>l;
        l--;

    cout<<"     |           Coloana: ";
    cin>>c_c;

    c_i=c_c-65;

    }


    if(b[l][c_i]==1)
    {
        cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        cout<<"     |               Ai nimerit!                     |"<<endl;
        cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        b[l][c_i]=2;
    }
    else
    {
        cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
        cout<<"     |               Nu ai nimerit!                  |"<<endl;
        cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    }
    system("pause");
    system("cls");
}

///AVIOANELE
void Avioanele()
{
    int ok=0;

    i_t();
    p_a_1();
    p_a_2();

    while(!ok)
    {
        at_1();
        ok=v_c_1();
        if(ok==1)
            break;
        system("pause");
        system("cls");

        at_2();
        ok=v_c_2();
        system("pause");
        system("cls");
    }
    cout<<endl<<endl;
    cout<<"      =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"     |            Tablele finale!                    |"<<endl;
    a_a_tabla_1();
    a_a_tabla_2();
    system("pause");
    system("cls");

}

int main()
{
    string opt_joc;
    int Ok=1;

    while(Ok==1)
    {
    /**MENIU**/
    cout<<endl<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"|    Daca vrei sa joci X si 0 scrie 'X_si_0'!     |"<<endl;
    cout<<"|    Daca vrei sa joci Zaruri scrie 'ZARURI'!     |"<<endl;
    cout<<"|    Daca vrei sa joci Spanzuratoarea scrie 'SP'! |"<<endl;
    cout<<"|    Daca vrei sa joci Avioanele scrie 'AVION'!   |"<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<endl<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"|    Vreau sa joc: ";
    cin>>opt_joc;
    system("cls");

    while(opt_joc!="X_si_0" && opt_joc!="ZARURI" && opt_joc!="SP" && opt_joc!="AVION")
    {
    cout<<endl<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"|    OPTIUNE INTRODUSA GRESIT!                    |"<<endl;
    cout<<"|    Daca vrei sa joci X si 0 scrie 'X_si_0'!     |"<<endl;
    cout<<"|    Daca vrei sa joci Zaruri scrie 'ZARURI'!     |"<<endl;
    cout<<"|    Daca vrei sa joci Spanzuratoarea scrie 'SP'! |"<<endl;
    cout<<"|    Daca vrei sa joci Avioanele scrie 'AVION'!   |"<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<endl<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"|    Vreau sa joc: ";
    cin>>opt_joc;
    system("cls");
    }

    /**PRONIRE JOCURI**/
    if(opt_joc=="X_si_0")
        X_0(a);
    else
    if(opt_joc=="ZARURI")
        Zaruri();
    else
    if(opt_joc=="SP")
        spanzuratoare();
    else
    if(opt_joc=="AVION")
        Avioanele();

    /**EXIT/ALT JOC**/
    cout<<endl<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"|    Vrei sa mai joci ceva?                        |"<<endl;
    cout<<"|    Raspuns('DA' sau 'NU'): ";
    cin>>opt_joc;
    system("cls");

    while(opt_joc!="DA" && opt_joc!="NU")
    {
    cout<<endl<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"|    OBTIUNE INTRODUSA GRESIT!                    |"<<endl;
    cout<<"|    Vrei sa ma joci ceva?                        |"<<endl;
    cout<<"|    Raspuns('DA' sau 'NU'): ";
    cin>>opt_joc;
    system("cls");
    }

    if(opt_joc=="NU")
        Ok=0;

    }

    cout<<endl<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"|    Sper ca v-ati distrat!                       |"<<endl;
    cout<<" =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    return 0;
}
