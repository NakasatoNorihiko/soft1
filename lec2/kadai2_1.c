#include <stdio.h>

#define MAXLEN      100
#define THRESHOLD  50.0
/* 以後のMAXLEN,THRESHOLDは100,50.0にコンパイル前(プリプロセス)に置き換えられる。 */

main()
{
  int i, maxindex;
  int max, min, value;
  /* 4バイトのint型の変数が５つ宣言されている */
  int score[MAXLEN];
  /* int型MAXLEN個(=100個)の配列が宣言されている。今のところ配列の中にどのような値が入っているかは処理系依存 */
  double average;
  /* double型(8ビット倍精度浮動小数点実数)を宣言している。 */

  for( i = 0 ; i < MAXLEN ; ++i ) {
      
    scanf( "%d", &value );     // printf とは逆で，キーボード入力。40[return]という
                               // キー入力をすると，value に 40 という値が代入される。
                               // &value の & はまだ教えてないので，言及しなくてよい。
    /* valueに数値を入力する scanfでは文字の区切りとしてスペース、タブ、改行などを使用する。*/
/* もしも、数字以外の入力があった場合にはストリーム上にその文字が残る。下のbreakを抜けられなかった場合次回以降のループもその文字を読み込みiがMAXLENになるまで入力ができない状態でループが回る可能性がある。 */

    if( value < 0 )  break;    // for ループを強引に抜ける
    /* もし入力された値が負の数であればループを抜ける ただし、数字以外の入力がされた場合には異常値となり脱出できないことがある。*/
    score[i] = value;
    /* score[i]にvalueを代入する */
  }
  
  maxindex = i-1;
/* 数値が入力されているscoreの最大の添字をmaxindexに代入している。i-1が代入されているのは入力完了を意味する-1を入力するときによけいに１回ループが回っているため */

  if( maxindex >= 0 ) {
    max = min = score[0];
    /* max = (min = score[0]);と処理される。(min=score[0])の式の値はscore[0]なので、max,minにscore[0]が代入される */
    
    average = 0;
/* averageを初期化している */
    for( i = 0 ; i <= maxindex ; ++i ) {
        /* iを0からmaxindexに達するまでループする(ループ一回ごとにiが+1される) */
      if( max < score[i] ) 
          max = score[i];
      if( min > score[i] )
          min = score[i];
/* 最大値maxよりもscore[i]が大きい場合maxを書き換える,最小値minよりも小さい場合はminを置き換える */
      average = average + score[i];
/* averageにscore[i]を足す。これを毎回ループすることによってaverageはscore[0]-score[i]の合計点数が入っている */
    }

    if( ( average = average / (maxindex+1) ) < THRESHOLD ) {
        /* まずmaxindex+1(=入力された数値の個数)を計算する。この式の値を用いて、(合計/数値の数)=平均を計算し、averageに代入する。最後に、THRESHOLDとの大小を評価する。もしも最後に計算した式の値が1(=平均点数がTHRESHOLDよりも小さい)のであれば、if文の中に入る */
      printf( "Students of this class are poor.....¥n" );
/* 引数の中身を標準出力に出力 */
    }
    printf( "averaged score = %.2lf, min = %d, max = %d, ndata = %d¥n", average, min, max, maxindex+1 );
    /* average,min,max,maxindex+1(=入力された数値の個数)を標準出力に出力する。ただし、averageは倍精度浮動小数点として小数点以下2桁まで表示する */
  }
  else {
    printf( "no data¥n" );
/* 引数の中身を標準出力に出力 */
  }

}
