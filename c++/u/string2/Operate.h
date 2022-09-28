#include <stdio.h>
#include <fstream>
#include <string>

struct word
{
    std::string word;
    int start, end;
    bool more = false;
};

class Operate
{
    private:
        std::string text;
    public:
        Operate(std::string filename)
        {
            std::ifstream fin(filename);
            if (fin.is_open())
                getline(fin, text);
            fin.close();
            printf("Зчитано:\n%s\n", text.c_str());
        }
        void task_1()
        {
            std::string buffer;
            char cur_c = text[0];
            buffer += text[0];
            for (int i = 1; text[i]; i++)
                if (text[i] != cur_c)
                    buffer += text[i];
            text = buffer;
            printf("1\n%s\n", text.c_str());
        }
        void task_2()
        {
            std::string buffer;
            int start_inx, end_inx;
            bool in_word = false;
            for (int i = 0; text[i]; i++)
            {
                if (text[i] != ' ' && !in_word)
                {
                    in_word = true;
                    start_inx = i;
                }
                if (text[i] == ' ' || text[i] == '.')
                {
                    if (in_word)
                    {
                        in_word = false;
                        end_inx = i-1;
                        int mid_inx;
                        if ( (end_inx - start_inx)%2 == 0 )
                            mid_inx = start_inx + (end_inx-start_inx)/2;
                        else
                            mid_inx = 1000000;
                        for (int j = start_inx; j <= end_inx; j++)
                            if (j != mid_inx)
                            {
                                buffer += text[j];
                            }
                    }
                    buffer += text[i];
                }
            }
            text = buffer;
            printf("2\n%s\n", text.c_str());
        }
        void task_3()
        {
            word words[100];
            int cur_inx = -1;
            for (int i = 0; text[i]; i++)
            {
                printf("3\n");
                int start_inx, end_inx;
                bool in_word = false;
                for (int i = 0; text[i]; i++)
                {
                    if (text[i] != ' ' && !in_word)
                    {
                        in_word = true;
                        start_inx = i;
                        cur_inx += 1;
                        words[cur_inx].start = start_inx;
                        words[cur_inx].word += text[i];
                    }
                    if (text[i] == ' ' || text[i] == '.')
                    {
                        if (in_word)
                        {
                            in_word = false;
                            words[cur_inx].end = i-1;
                            printf("+ %s\n", words[cur_inx].word.c_str());          // Хуйня
                        }
                    }
                }
            }
            for (int i = 0; i <= cur_inx; i++)
                printf("`%s` ", words[i].word.c_str());
            printf("\n");
        }
};