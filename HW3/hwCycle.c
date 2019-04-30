//HomeWork # 3
//Baturina Yelena
// Cycles illustration

#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>

int main(void)
{
register int y1,x0,xn;
char  symbol;

srand(time(NULL));
initscr();
start_color();
//refresh();
init_pair(1,COLOR_GREEN, COLOR_BLACK);

int ex=0;
do {
    
 int 	k=1;
            while (k<4)
		{
		y1 = ((0+rand() % 120)+1);
		x0 = 0+rand() %11;
		xn = 12 +rand()%30;
        	        for (int x=x0; x<xn; x++)
     	  	          {
         		        attron (A_BOLD);
			        attron (COLOR_PAIR(1));
                 	        symbol = (char)((0+rand() %26)+65);
			        usleep(100000);
			        refresh();
		                move(x,y1);
		                addch(symbol);
				}
			k++;
			usleep(100000);
		}
   ex++;
}       while(ex<4);


refresh();

endwin();

return 0;

}
