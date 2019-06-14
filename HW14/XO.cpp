//#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <string>

#define FIGHIGH  6   // высота фигуры
#define FIGWID  10   // ширина фигуры
#define FILDSTY 10   // начальная позиция поля по У
#define FILDSTX 50   // начальная позиция поля по Х

struct figure_window
{
    WINDOW *cell;
    char   figure;
    int    numcell;
};
typedef struct figure_window fgwin;

fgwin *DisplayFigure (int numcell, char fig, int h, int w, int sy, int sx);  // отрисовка ячейки с заданным номером и заданной фигурой
WINDOW * DrawTitle( int h, int w, int y, int x);
void DrawField();

using namespace std;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class SimplFigure {  // класс для работы в режиме 2 игрока
     protected:
           char m_sym ;
           int m_step ;
     public:
           SimplFigure(char smb, int numst)
            {
             m_sym = smb;   // символ фигуры
             m_step = numst;  //номер шага  для данной фигуры

            }

           void set_step () {m_step++;}

           int  get_step() { return m_step;}

           char get_sym() {return m_sym;}

           int  TakePos ( char *arr, int position, char rg) {  //установка значения фигуры в главном массиве игры(с проверкой своб позиции)

                int i = check_position (arr, position);
                  switch (rg) {
                    case 'l': if (i == -1) printw("This position : %d is not free. Choose another.", position);
                              else {
                                    arr[i] = m_sym;
                                    set_step();
                               }
                               break;
                    case 's':if (i == -1) ;
                              else {
                                    arr[i] = m_sym;
                                    set_step();
                               }
                                  break;
                }
                return (i);
               }

            int Winner( char *arr ){ //выигрыш данной фигуры
                 int stp = get_step();
                 char f = get_sym();
                 if (stp > 2){
                   int w = check_8_lines(f, arr);
                   if ( w == 10){
                    printw("Player (%c) is winner !!!! Congratulation ! \n", f);
                    printw("The game is over !");
                    refresh();
                    getch();
                    return (1);  // игра окончена. Победа!
                   }
                 }
                 if (stp == 5){
                    printw("The Winner is a friendship !!! \n");
                    printw("The game is over !");
                    refresh();
                    getch();
                    return (1); // игра окончена, ничья
                 }
               return (0);// победы нет, игра не закончилась
           }


          void Print_fild(char *arr){
             for (int i =0; i<9; i++)
                printf ("%c, ",arr[i]);
             printf("\n");
            }
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int check_8_lines (char sym_ch,  char *ptrarr)
{
    int i = check_line(sym_ch, ptrarr, 0, 3, 6);
        if ((i > -1) && (i < 11)) return i;


        i = check_line(sym_ch, ptrarr, 2, 5, 8);
        if ((i > -1) && (i < 11)) return i;

        i = check_line(sym_ch, ptrarr, 0, 1, 2);
        if ((i > -1) && (i < 11)) return i;

        i = check_line(sym_ch, ptrarr, 6, 7, 8);
        if ((i > -1) && (i < 11)) return i;

        i = check_line(sym_ch, ptrarr, 0, 4, 8);
        if ((i > -1) && (i < 11))  return i;

        i = check_line(sym_ch, ptrarr, 1, 4, 7);
        if ((i > -1) && (i < 11)) return i;

        i = check_line(sym_ch, ptrarr, 3, 4, 5);
        if ((i > -1) && (i < 11)) return i;

        i = check_line(sym_ch, ptrarr, 2, 4, 6);
        if ((i > -1) && (i < 11)) return i;

  }

//-----------------------------------------------------------

int check_line( char smb, char *arr, int a, int b, int c)
  {
    int i = 0; // счетчик совпадений на линии с символом smb
    int k = -1;  // номер ячейки в которой нет совпадения

    if (arr[a] == smb) { i++;}
    else if (arr[a]==' ') { k = a;}  // если в ячейке "а" нет символа smb, ее номер запомним в k

    if (arr[b] == smb)  {i++;}
    else if (arr[b]==' '){k = b;}    // если в ячейке "b" нет символа smb, ее номер запомним в k

    if (arr[c] == smb) {i++;}
    else if(arr[c]==' '){k = c;}    // если в ячейке "c" нет символа smb, ее номер запомним в k


    if (i == 3) k = 10; // если в  линии 3 совпадения , то символ smb уже выиграл

    if (i < 2 ) k = -1; // если в линии 1 или  0 соврадений, возвращаем -1,

    return k;
}
//-----------------------------------------------------------

 int check_position( char *ptrarr, int pos){   // проверка свободна ли выбранная позиция (pos)

              if (ptrarr[pos]==' ') return pos;

              else return (-1);
    }
//---------------------------------------------------------
  int find_free_pos( char *ptrarr) { // поиск первой свободной ячейки

     for (int i = 0; i < 9; i++){
       if (ptrarr[i] == ' ') return (i);
     }
  }

}; // end of class
//++++++++++++++++++++++++++++++++++++++++++++++

class RandFigure : public SimplFigure {

     public:
           RandFigure( char ch, int st) : SimplFigure( ch, st)
            {

              }
           int Rand_position( char *ptrarr){
               int p = -1;
               while (p == -1) {
                   int num = get_step();
                    if (num > 3) p = find_free_pos( ptrarr);
                    p = 0 + rand()%8;
                    p = TakePos ( ptrarr, p,'s'); //check_position(p);
               }
             return p;
            }
};  // end of class

//+++++++++++++++++++++++++++++++++++++++++++++

class AIFigure :public SimplFigure {

   protected:

   public:
        AIFigure (char symb, int stp) : SimplFigure (symb, stp)
        {

          }

        int First_step (char *ptrar) {

              switch (get_sym()){
                  case  'X' : return step_X_1( ptrar);
                  case  'O' : return step_O_1( ptrar);
                  default : return -1;
              }
          }

        int Second_step( char *ptrarr) {

             switch (get_sym()){
                 case  'X' : return step_X_2( ptrarr);
                 case  'O' : return step_O_2( ptrarr);
                 default : return -1;
            }
       }

        int Third_step( char *ptrarr){

               switch (get_sym()){
                   case  'X' : return step_F_N( ptrarr,'X','O' );
                   case  'O' : return step_F_N( ptrarr, 'O','X');
                  default : return -1;
               }
           }


        int Fourth_step(char *ptrarr){

               switch (get_sym()){
                   case  'X' : return step_F_N( ptrarr, 'X', 'O');
                   case  'O' : return step_F_N( ptrarr, 'O', 'X');
                   default : return -1;
              }
            }

        int Fifth_step( char *ptrarr){
            return step_F_N( ptrarr, 'X','O');
            }

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

   int step_X_1(char *ptrarr){

       int p = 4;  // первый ход "Х" в центральную ячейку (4)
       TakePos ( ptrarr, p, 's');
       return (p);
   }
//----------------------------------------------------------------------
  int step_O_1(char *ptrarr) {

      int repst = -1; // флаг для повторного шага если занято ранее выбранное
      int i;
      if (ptrarr[4] == ' '){   // если центральная ячейка свободна, 
         int p = 4;
             TakePos ( ptrarr, p,'s');      // первый ход  "О" в центральную ячейку
         return (p);
       }

      else {               // если центральная ячейка занята, О ходит в угловую(четную, !=4)ячейку
        repst = -1;
        do {
            i = 0 + rand()%7;
            //int k = i % 2;
            if (!(i%2) && (i!=4) ) ;
            else if (i==4){ i=i+2;}
            else i++;
            repst = TakePos ( ptrarr, i,'s');
        } while (repst == -1);
        return (i);
      }
  }
//----------------------------------------------------------------------
  int step_X_2 (char *ptrarr){

       int i =-1;
       int j = -1;
       int k = -1;
   while (k ==-1) {
       while (i ==-1) {   // пока не сгенерировали нужного значения 
            i = 0 + rand()%7;   // герерируем номер от 0 до 7!
            if (i % 2) {i++;}   // если  значение сгерерировалось нечетное добавим единицу

            if ((ptrarr[i] != ' ') &&(i == 8)) { i = 2;}   // если ячейка занята и она 8 i = 2

            else if ((ptrarr[i] != ' ') || (i == 4)) {i = i + 2;} // если  ячейка не пустая или  это 4 ячейка, выбираем след. четную
            j = 8 - i; // а теперь берем диаганальную к ячейке i
            if (ptrarr[j]!=' ') {i = -1;}  // если вдруг она занята генерим заново
      }

    k = TakePos ( ptrarr, i,'s');
    i = -1;
  }
     return (k);
  }
//---------------------------------------------------------------------
   int step_O_2(char *ptrarr) {

     int i= -1;

     if (ptrarr[4] == 'O') {   // если "О" на первом шаге занял центральную ячейку

        i = check_line('X', ptrarr, 0, 3, 6);
        if ((i > -1) && (i < 9)) {
            TakePos ( ptrarr, i,'s');
            return i;
        }
        i = check_line('X', ptrarr, 2, 5, 8);
        if ((i > -1) && (i < 9)) {
            TakePos ( ptrarr, i,'s');
            return i;
        }
        i = check_line('X', ptrarr, 0, 1, 2);
        if ((i > -1) && (i < 9)) {
            TakePos ( ptrarr, i,'s');
            return i;
        }
        i = check_line('X', ptrarr, 6, 7, 8);
        if ((i > -1) && (i < 9)) {
            TakePos ( ptrarr, i, 's');
            return i;
        }

     }
   // иначе (он занял угловую ячейку) проверяем все строчки, столбцы, диогонали
   // на наличе в линнии 2 фигур противника ("Х")

     else {
             int i = check_8_lines ('X', ptrarr);
             if ((i > -1) && (i < 9)) {
                 TakePos ( ptrarr, i,'s');
                 return (i);
              }
      }
  }

//--------------------------------------------------------------------

 int step_F_N (char *ptrarr, char chsl, char chpt){

    //проверка на выигрыш
     int i = check_8_lines (chsl,  ptrarr);
         if ((i > -1) && (i < 9)) {
            TakePos ( ptrarr, i,'s');
            return i;
           }

         else {
                // проверка на достроение линии соперника
            int i = check_8_lines (chpt,  ptrarr);
            if ((i > -1) && (i < 9)) {
               TakePos ( ptrarr, i,'s');
               return i;
             }

            else { // если нет достроения линии соперника, просто ищем первую свободную ячейку
                int fr = find_free_pos(ptrarr);
//                  return fr;
                //if ((i > -1) && (i < 9)) {
                 TakePos ( ptrarr, fr,'s');
                 return  fr;   
 //            }
            }
         }

    // int w = Winner ( ptrarr);  // проверка на окончание игры
    //     if ( w == 1) return (1);   // конц игры
     //    else return (0);  // игра продолжается  
   //return (i);
  }
};  // end of class
//----------------------------------------------------
void AIGame (char *fild) {

   int win = 0;
   int pos =-1;
   int repstep =-1; // флаг требуется ли  выбрать другую ячейку, так как выбранная ранее занята
   char usr_fig =' ';  // фигура выбранная пользователем
   int  fg = -1; // флаг о том что фигура выбрана игроком корректно
   
   fgwin * win_[9];
   int h = FIGHIGH;
   int w = FIGWID;
   int sty = FILDSTY + 2;
   int stx = FILDSTX + 2;
   int count = -1;


   AIFigure X_fig('X', 0);
   AIFigure O_fig('O', 0);
   
   do {
       attron( COLOR_PAIR(3));
       printw("Choose your figure, X or O ? ->  ");
       scanw("%c", &usr_fig);
       printw ("                               \n");
       refresh();

       switch (usr_fig){
          case ('X'):
                 for (int i = 1; i < 6; i++){
                       repstep = -1;
                       do{
                          attron( COLOR_PAIR(3));
                          printw ("Put X ->  ");
                          scanw ("%i", &pos);
                          printw ("                               \n");
                          refresh();

                          repstep = X_fig.TakePos( fild, pos,'l');
                       } while (repstep == -1);
                       count++;
                       win_[count] = DisplayFigure (pos, 'X', h, w, sty, stx);
                       win = X_fig.Winner( fild);
                       if (win ==1 ) break;

                       switch (i){
                            case(1): pos = O_fig.First_step( fild);
                                     sleep(1);
                                     count++;
                                     win_[count] = DisplayFigure (pos, 'O', h, w, sty, stx);
                                     win = O_fig.Winner(fild);
    //                                 O_fig.Print_fild (fild);
                                     break;
                            case(2):  pos = O_fig.Second_step( fild);
                                      sleep(1);
                                      count++;
                                      win_[count] = DisplayFigure (pos, 'O', h, w, sty, stx);
                                      win = O_fig.Winner(fild);
      //                               O_fig.Print_fild (fild);
                                     break;
                            case(3):  pos = O_fig.Third_step( fild);
                                      sleep(1);
                                      count++;
                                      win_[count] = DisplayFigure (pos, 'O', h, w, sty, stx);
                                      win = O_fig.Winner(fild);
//                                     O_fig.Print_fild (fild);
                                     break;
                            case(4): pos = O_fig.Fourth_step( fild);
                                     sleep(1);
                                     count++;
                                     win_[count] = DisplayFigure (pos, 'O', h, w, sty, stx);
                                     win = O_fig.Winner(fild);
  //                                   O_fig.Print_fild (fild);
                                     break;

                           default : break;

                      }  //end switch i
                       if (win ==1 ) break;
                 }   // end for
                 fg = 1; break;

        case ('O'):
                   for (int i = 1; i < 6; i++){
                       //repstep =-1;
                       switch (i){
                            case(1): pos =X_fig.First_step( fild);
                                     sleep(1);
                                     count++;
                                     win_[count] = DisplayFigure (pos, 'X', h, w, sty, stx);
                                     win = O_fig.Winner(fild);
//                                     X_fig.Print_fild (fild);
                                     break;
                            case(2): pos = X_fig.Second_step( fild);
                                     sleep(1);
                                     count++;
                                     win_[count] = DisplayFigure (pos, 'X', h, w, sty, stx);
                                     win = X_fig.Winner(fild);
  //                                   X_fig.Print_fild (fild);
                                     break;
                            case(3): pos = X_fig.Third_step( fild);
                                     sleep(1);
                                     count++;
                                     win_[count] = DisplayFigure (pos, 'X', h, w, sty, stx);
                                     win = X_fig.Winner(fild);
      //                               X_fig.Print_fild (fild);
                                     break;
                            case(4): pos = X_fig.Fourth_step( fild);
                                     sleep(1);
                                     count++;
                                     win_[count] = DisplayFigure (pos, 'X', h, w, sty, stx);
                                     win = X_fig.Winner(fild);
      //                               X_fig.Print_fild (fild);
                                     break;
                            case(5): pos =X_fig.Fifth_step( fild);
                                     sleep(1);
                                     count++;
                                     win_[count] = DisplayFigure (pos, 'X', h, w, sty, stx);
                                     win = X_fig.Winner(fild);
     //                                X_fig.Print_fild (fild);
                                     break;

                           default : break;

                      }  // end switch i

                       if (win == 1 ) break;

                       repstep = -1;
                       do {
                          attron( COLOR_PAIR(3));
                          printw ("Put O ->  ");
                          scanw ("%i", &pos);
                          printw ("                               \n");
                          refresh();
                          repstep = O_fig.TakePos( fild, pos, 'l');
                       } while (repstep == -1);
                        count++;
                        win_[count] = DisplayFigure (pos, 'O', h, w, sty, stx);
                        win = O_fig.Winner(fild);
      //                 X_fig.Print_fild (fild);
                       if (win ==1 ) break;
                }  //end for 
               fg = 1; break;
        default : fg = 0; break;
      }  //end  switch 

   } while (fg == 0);

  for (int i = 0; i<9; i++){
      win_[i] = DisplayFigure (i, ' ', h, w, sty, stx);
   }

 return;

}
//-----------------------------------------------------
void RandGame( char *fild) {

   int win = 0;
   int pos =-1;
   int repstep =-1; // флаг требуется ли  выбрать другую ячейку, так как выбранная ранее занята
   char usr_fig =' ';  // фигура выбранная пользователем
   int  fg = -1; // флаг о том что фигура выбрана игроком корректно

   fgwin * win_[9];
   int h = FIGHIGH;
   int w = FIGWID;
   int sty = FILDSTY + 2;
   int stx = FILDSTX + 2;
   int count = -1;

   RandFigure X_fig('X', 0);
   RandFigure O_fig('O', 0);

   do {
       attron( COLOR_PAIR(3));
       printw("Choose your figure, X or O ? ->  ");
       scanw("%c", &usr_fig);
       printw("                                \n");
       refresh();

       switch (usr_fig){
          case ('X'):
             while (!win){
                 repstep = -1;
                 do{
                   attron( COLOR_PAIR(3));
                   printw ("Put X ->  ");
                   scanw ("%i", &pos);
                   printw ("                               \n");
                   refresh();
                   repstep = X_fig.TakePos( fild, pos,'l');
                 } while (repstep == -1);
                 count++;
                 win_[count] = DisplayFigure (pos, 'X', h, w, sty, stx);
                 win = X_fig.Winner( fild);
                 if (win ==1 ) break;

                 pos = O_fig.Rand_position( fild);
                 sleep(1);
                 count++;
                 win_[count] = DisplayFigure (pos, 'O', h, w, sty, stx);
                 win = O_fig.Winner(fild);
//                 X_fig.Print_fild (fild);
             }
             fg = 1; break;

        case ('O'):
            while (!win){
                 repstep =-1;
                 pos = X_fig.Rand_position( fild);
                 sleep(1);
                 count++;
                 win_[count] = DisplayFigure (pos, 'X', h, w, sty, stx);
                 win = X_fig.Winner( fild);
                 if (win ==1 ) break;

                 repstep = -1;
                 do {
                   attron( COLOR_PAIR(3));

                   printw ("Put O ->  ");
                   scanw ("%i", &pos);
                   printw ("                               \n");
                   refresh();
                   repstep = O_fig.TakePos( fild, pos, 'l');
                 } while (repstep == -1);
                 count++;
                 win_[count] = DisplayFigure (pos, 'O', h, w, sty, stx);
                 win = O_fig.Winner(fild);
//                  X_fig.Print_fild (fild);
           }
          fg = 1; break;

        default : fg = 0; break;
      }
   } while (fg == 0);

   for (int i = 0; i<9; i++){
      win_[i] = DisplayFigure (i, ' ', h, w, sty, stx);
   }
   return;
}

//-----------------------------------------------------
void SimplGame( char *fild){

   int win = 0;
   int pos =-1;
   int repstep = -1;
   fgwin * win_[9];
   int h = FIGHIGH;
   int w = FIGWID;
   int sty = FILDSTY + 2;
   int stx = FILDSTX + 2;
   int count = -1;

   SimplFigure X_fig('X', 0);
   SimplFigure O_fig('O', 0);

   while (!win){
        repstep =-1;
        do{
          printw ("                               \n");
          refresh();
          attron( COLOR_PAIR(3));
          printw ("  Put X ->  ");
          scanw ("%i", &pos);
          repstep = X_fig.TakePos( fild, pos, 'l');
        } while (repstep == -1);
        count++;
        win_[count] = DisplayFigure (pos, 'X', h, w, sty, stx);
        win = X_fig.Winner( fild);
        if (win ==1 ) break;

        repstep = -1;
        do {
          printw ("                               \n");
          refresh();
          attron( COLOR_PAIR(3));
          printw ("  Put O ->  ");
          scanw ("%i", &pos);
          repstep = O_fig.TakePos( fild, pos, 'l');}
        while (repstep == -1);
        count++;
        win_[count] = DisplayFigure (pos, 'O', h, w, sty, stx);
        win = O_fig.Winner(fild);
    }

for (int i = 0; i<9; i++){
    win_[i] = DisplayFigure (i, ' ', h, w, sty, stx);
   }

  refresh();
return;
}
//--------------------------------------------------------------------
int main(){

 enum Mode { ARTINT = 1, PLAY2, RANDART, EXT}; //Режим игры
 enum Mode regim;
 int ext = 0; // флаг выхода из главного меню
 int pos = -1; //  номер ячейки при шаге N данной фигуры
 int win = 0 ; //флаг выигрыша(окончания игры) 1-игра окончена, 0-игра продолжается
 
 initscr();
 cbreak();
 start_color();

 int h = FIGHIGH;
 int w = FIGWID;
 int sty = FILDSTY + 2;
 int stx = FILDSTX + 2;
 WINDOW *winT;
//   use_default_colors();

 srand(time(NULL));

    do {
        char fildplay[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '}; // создаем игровое поле 

        DrawField();
        winT = DrawTitle( 8,76,1, 50);

        printw ("\n");
	printw ("Choose the regime of Game running: \n");
	printw ("\n");
 	printw ("1 - ArtIntelligence;\n");
        printw ("2 - Two Players ;\n");
 	printw ("3 - RandIntelligence;\n");
 	printw ("4 - Exit;\n");
	printw ("\n");

       scanw ("%d", (int*) &regim);

       switch (regim){

             case(ARTINT):  AIGame( fildplay); break;

             case(RANDART): RandGame( fildplay); break;

             case(PLAY2): SimplGame( fildplay ); break;

             case(EXT): printw ("See you late !\n"); ext = 1; break;

             default : printw ("Chosen regim is not realized!\n"); break;
      }
   } while (ext < 1);
  
  refresh();
  wgetch(winT);
  endwin();

return 0;
}
//----------------------------------------------------------------------
void DrawField(){

  int c = 0;
  init_pair(3, COLOR_WHITE,COLOR_BLACK);
// горизонтальные линии
   for (int y1 = FILDSTY; y1 < FILDSTY + 3 * (FIGHIGH + 2) + 1;  y1 = y1 + (FIGHIGH + 2)) {
       int x0 = FILDSTX;
       int xn = FILDSTX + 3*(FIGWID + 2);
       for (int x = x0; x < xn; x++) {
           attron (A_BOLD);
           attron( COLOR_PAIR(3));
           if  (((x == FILDSTX) || (x == FILDSTX +12) 
                || (x == FILDSTX + 24)) && (y1 <  FILDSTY + 3 * (FIGHIGH + 2) )){
              char symbol = (char) (48 + c);
              move(y1 + 4, x + 4);
              attron( COLOR_PAIR(3));
              addch(symbol);
              refresh();
              c++;
           }

          char symbol = '_';
          move(y1,x);
          attron( COLOR_PAIR(3));
          addch(symbol);
          refresh();
      }

    }

   for (int x1 = FILDSTX; x1 < FILDSTX + 3*(FIGWID + 2) + 2; x1 = x1 + (FIGWID + 2)) {// вертикальные линии
       int y0 = FILDSTY + 1;
       int yn = FILDSTY + 3*(FIGHIGH + 2) + 1;
       for (int y = y0; y < yn; y++) {
           attron (A_BOLD);
           attron( COLOR_PAIR(3));
           char symbol = '|';
           move(y,x1);
           attron( COLOR_PAIR(3));
           addch(symbol);
           refresh();
       }
  }
  printw("\n");
  refresh();
}

//---------------------------------------------------------------------

  fgwin *DisplayFigure (int numcell, char fig, int h, int w, int sy, int sx)
   {

   string str_o =  "   @ @   \n"
                   " @     @ \n"
                   "@       @\n"
                   "@       @\n"
                   " @     @ \n"
                   "   @ @   ";


  string str_x = " @     @ \n" //0
                 "  @   @  \n" //1
                 "    @    \n" //2
                 "  @   @  \n"
                 " @     @ ";

    init_pair(1, COLOR_GREEN, COLOR_BLACK); //X
    init_pair(2, COLOR_BLUE, COLOR_BLACK);  //O


    int starty ;
    int startx ;

    int j = numcell % 3; // номер столбца
    int k = numcell / 3; // номер строки 

    starty = sy + k*(h + 2);
    startx = sx + j*(w + 2);

    fgwin *nwin = new fgwin;
    nwin->cell = newwin( h, w, starty, startx);

    wattron (nwin->cell, A_BOLD);

    switch (fig) {

           case 'X':wattron(nwin->cell, COLOR_PAIR(1));
                    wprintw (nwin->cell, str_x.c_str()); break;

           case 'O':wattron(nwin->cell, COLOR_PAIR(2));
                    wprintw (nwin->cell, str_o.c_str()); break;
    }

    wrefresh(nwin->cell);

   return (nwin);
 }
//---------------------------------------------------------------

WINDOW *DrawTitle(int h, int w, int y, int x){
//WINDOW *DrawTitle( WINDOW * winTitle){
   string str_1 =  "@     @                         @ @   \n"
                   " @   @                   @    @     @ \n"
                   "  @ @                    @   @       @\n"
                   "  @ @      @ @   @ @   @ @   @       @\n"
                   " @   @    @   @  @  @ @  @    @     @ \n"
                   "@     @    @ @ @ @  @  @ @      @ @   \n" 
                   "______________________________________ ";


   init_pair(4, COLOR_MAGENTA, COLOR_BLACK); //TiTle
   attron (A_BOLD);
   attron( COLOR_PAIR(4));

   WINDOW *winTitle = newwin( h, w, y, x);
   
   wattron (winTitle, A_BOLD);
   wattron(winTitle, COLOR_PAIR(4));

   wprintw( winTitle, str_1.c_str());
   wrefresh(winTitle);
//   wgetch(winTitle);
  return (winTitle);
}

