#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>
#include <ctime>
#include <iostream>



void frame(char **& display, int width, int height, bool stop_flag)
{
    char com;
    std::cout << width << ' ' << height << std::endl;
    for (int w = 0; w < width; w++)
    {
        std::cout << display[w];
        if (w < width-1)
            std::cout << std::endl;
        else
        {
            system("stty raw");
            std::cin.get(com);
            switch ((int) com)
            {
                case 72:            // up
                    ;
                case 80:            // down
                    ;
                case 75:            // left
                    ;
                case 66:            // right
                    ;
                case 27:            // ESC
                    ;
            }
            system("stty cooked");
        }
    }
}

int main ()
{
    struct winsize w;
    bool game_ESCAPE_flag = false;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);        // Отримуємо розмір вікна

    //char display[w.ws_row][w.ws_col];
    char ** display = new char *[w.ws_row];
    for (int r = 0; r < w.ws_row; r++)
    {
        display[r] = new char [w.ws_col];
        for (int c = 0; c < w.ws_col; c++)
            display[r][c] = '.';
    }


    frame (display, w.ws_col, w.ws_row, game_ESCAPE_flag);


    return 0;  // make sure your main returns int
}



/*

    printf ("lines %d\n", w.ws_row);
    printf ("columns %d\n", w.ws_col);

    std::cout << w.ws_row << std::endl;
    std::cout << w.ws_col << std::endl;

*/