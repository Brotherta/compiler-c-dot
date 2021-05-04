extern int printd( int i );

int fact( int n ) {
  if ( n <= 1 )
    return 1;
   fact(n-1, 1);
  return n;
}

int main() {
  printd(fact(10));
  return 0;
}