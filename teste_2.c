#include <termios.h>
#include <stdio.h>
#include <time.h>


struct termios info;
int main(){
    tcgetattr(0, &info);          /* get current terminal attirbutes; 0 is the file descriptor for stdin */
    info.c_lflag &= ~ICANON;      /* disable canonical mode */
    info.c_cc[VMIN] = 0;          /* wait until at least one keystroke available */
    info.c_cc[VTIME] = 0;         /* no timeout */
    tcsetattr(0, TCSANOW, &info); /* set immediately */
    int ch;
    int i=0;
    while(1){
        do{
            printf("teste %d\n",i);
            i++;
            sleep(1);
            ch=getchar();
            if (ch < 0) {
                if (ferror(stdin)) { printf("DEU RUIM!"); }
                clearerr(stdin);
            }            
            system("clear");
        }while(ch!=116);
         
            printf("AHH muleke!\n");
            i=0;
    }
    printf("Saiu!\n");
    tcgetattr(0, &info);
    info.c_lflag |= ICANON;
    tcsetattr(0, TCSANOW, &info);

return 0;
}
