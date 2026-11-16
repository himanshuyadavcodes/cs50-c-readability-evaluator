#include <ctype.h>
#include <stdio.h>
#include <string.h>

int space_count(char* text);
double avg_letter(char* text, int words);
double avg_sentence(char* text, int words);
void grade(double index);

int main(void)
{
    char text[2000];
    printf("Text: ");
    if (fgets(text, sizeof(text), stdin) != NULL)
    {
        text[strcspn(text, "\n")] = '\0';
    }
    int words = space_count(text) + 1;
    double L = avg_letter(text, words);
    double S = avg_sentence(text, words);
    double index = 0.0588 * L - 0.296 * S - 15.8;
    grade(index);
}

int space_count(char* text)
{
    int sum = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            sum++;
        }
    }
    return sum;
}

double avg_letter(char* text, int words)
{
    int sum = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            sum++;
        }
    }
    double average = (double) sum / (double) words * 100;
    return average;
}

double avg_sentence(char* text, int words)
{
    int sum = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sum++;
        }
    }
    double average = (double) sum / (double) words * 100;
    return average;
}

void grade(double index)
{
    int level = index + 0.5;
    if (level >= 1 && level <= 16)
    {
        printf("Grade %i\n", level);
    }
    else if (level < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}
