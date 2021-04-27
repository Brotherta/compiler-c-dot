tab_symbole[l1,l2,l3,l4]
l1 // global a b c                                            // acc 0
l2 // global + test (a,b,c,f)    // declaration de fonction   // acc 1
l3 // global + test + if (a,b,c,f,d) // declaration bloc      // acc 2
l4 // global + main (a,b,c,i) // sortie de test               // acc 3
l                                                             // acc 3 + acc 4


/*
acc 0

tab[0] <- a,b,c
acc++ (acc = 1)


*/
// 0 
int a,b,c; 

int test() { 
    //1
    int d; 
    if()
    {
        // 2
        int e;
        if () 
        {
            // 3
            int f;
        }
        // 2

        if () 
        {
            // 3
            int g;
        }
        // 2
    }
    //1
    return 0;
}
// 0


int test2() {
    // 1
    int g;
    if(1==1)
    {
        // 2
        int h;
        if (1==1) 
        {
            // 3
            int i; 
        }
        // 2
    }
    //  1
    return 0;
}
// 0