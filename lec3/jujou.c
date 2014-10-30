#include <stdio.h>

int y; //グローバル変数
int z; //グローバル変数

void myfunc(int a)
{
  int z; // myfuncのローカル変数
  int x; // myfuncのローカル変数
  x = a; // ローカル
  y = a; // グローバル変数
  z = a; // グローバルではなくローカルが優先される
}

int main()
{
  int x;  // mainのローカル変数
  x = 10; // mainのローカル変数
  y = 10; // グローバル変数
  z = 10; // グローバル変数
  printf("x,y,zの値は%d, %d, %d\n", x, y, z);
  myfunc(5);
  printf("x,y,zの値は%d, %d, %d\n", x, y, z);
}

/*
x,y,zの値は10, 10, 10
x,y,zの値は10, 5, 10
 */
