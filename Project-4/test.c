int a;
int main()
{
  int a,b,c,d;

  if(a<b && c>d){
    a=10;
  }
  else{
    c=10;
  }
  while(a>b){
    if(c>d)
      continue;
    a = c;
  }
  b = d;

  /*
  a = b + 5;
  b = a * 9;*/
}
