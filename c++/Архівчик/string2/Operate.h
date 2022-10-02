#include <stdio.h>
#include <fstream>
#include <string>

struct word
{
    std::string word;
    int start, end;
    int len;
    bool more;
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
        void get()
        {
            printf("%s\n", text.c_str());
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
            printf("3\n");
            word words[100];
            int cur_inx = -1;
            int start_inx, end_inx;
            bool in_word = false;
            for (int i = 0; text[i]; i++)
            {
                if (text[i] != ' ' && !in_word)
                {
                    in_word = true;
                    cur_inx ++;
                    words[cur_inx].start = i;
                    words[cur_inx].word += text[i];
                } else if (text[i] == ' ' || text[i] == '.')
                {
                    in_word = false;
                    words[cur_inx].end = i-1;
                } else
                {
                    words[cur_inx].word += text[i];
                }
            }
            for (int i = 0; i <= cur_inx; i++)
            {
                int count = 0;
                for (int j = 0; j <= cur_inx; j++)
                {
                    if (words[i].word == words[j].word)
                        count++;
                }
                if (count > 1)
                    words[i].more = true;
                else
                    words[i].more = false;
            }
            //for (int i = 0; i <= cur_inx; i++)
            //    printf("`%s` %d ", words[i].word.c_str(), words[i].more);
            //printf("\n");
            std::string buffer;
            for (int i = 0; i <= cur_inx; i++)
            {
                if (!words[i].more)
                    buffer += words[i].word + ' ';
            }
            buffer[ buffer.length()-1 ] = '.';
            text = buffer;
            printf("%s\n", text.c_str());
        }
        void task_4()
        {
            printf("4\n");
            word words[100];
            int min_inx, max_inx;
            int minl_cand = 100, maxl_cand = 0;
            int cur_inx = -1;
            int start_inx, end_inx;
            bool in_word = false;
            for (int i = 0; text[i]; i++)
            {
                if (text[i] != ' ' && !in_word)
                {
                    in_word = true;
                    cur_inx ++;
                    words[cur_inx].start = i;
                    words[cur_inx].word += text[i];
                } else if (text[i] == ' ' || text[i] == '.')
                {
                    in_word = false;
                    words[cur_inx].end = i-1;
                    words[cur_inx].len = i - words[cur_inx].start;
                } else
                {
                    words[cur_inx].word += text[i];
                }
            }
            for (int i = 0; i <= cur_inx; i++)
            {
                if (words[i].len < minl_cand)
                {
                    min_inx = i;
                    minl_cand = words[i].len;
                }
                if (words[i].len > maxl_cand)
                {
                    max_inx = i;
                    maxl_cand = words[i].len;
                }
            }
            std::string temp = words[min_inx].word;
            words[min_inx].word = words[max_inx].word;
            words[max_inx].word = temp;
            std::string buffer;
            for (int i = 0; i <= cur_inx; i++)
                buffer += words[i].word + ' ';
            buffer[ buffer.length()-1 ] = '.';
            text = buffer;
            printf("%s\n", text.c_str());
        }
        void task_9()
        {
            printf("9\n");
            word words[100];
            int cur_inx = -1;
            bool in_word = false;
            for (int i = 0; text[i]; i++)
            {
                if (text[i] != ' ' && !in_word)
                {
                    in_word = true;
                    cur_inx ++;
                    words[cur_inx].start = i;
                    words[cur_inx].word += text[i];
                } else if (text[i] == ' ' || text[i] == '.')
                {
                    in_word = false;
                    words[cur_inx].end = i-1;
                    words[cur_inx].len = i - words[cur_inx].start;
                } else
                {
                    words[cur_inx].word += text[i];
                }
            }
            for (int i = 0; i <= cur_inx; i++)
            {
                bool tru_word = true;
                int ch_code = int(words[i].word[0]);
                for (int j = 1; words[i].word[j] != '\0'; j++)
                {
                    if (int(words[i].word[j]) != ch_code + 1)
                    {
                        tru_word = false;
                        break;
                    }
                    ch_code = int(words[i].word[j]);
                }
                //printf("\n");
                words[i].more = tru_word;
            }
            for (int i = 0; i <= cur_inx; i++)
            {
                if (words[i].more)
                {
                    printf("%s ", words[i].word.c_str());
                }
            }
            printf("\n");
        }
};