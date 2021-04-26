#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// functions declarations
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
double L(int letters , int words);
double S(int words , int sentences);
int coleman_test(int letters , int words , int sentences);

int main(void)
{
    //assigning values of needed variables after taking text as input
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int grade = coleman_test(letters , words , sentences);
    //checking if grade less than 1 or more than 16
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

//count letters in text

int count_letters(string text)
{
    int Letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            Letters++;
        }
    }
    return Letters;
}

// count words in text

int count_words(string text)
{
    int Words = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            Words++;
        }
    }
    return Words + 1;
}

// count sentences in text

int count_sentences(string text)
{
    int Sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            Sentences++;
        }
    }
    return Sentences;
}

// calculation average letters/100 words

double L(int letters , int words)
{
    double L = (double)letters / words * 100;
    return L;
}

// calculate average sentences/100 words

double S(int words , int sentences)
{
    double S = (double)sentences / words * 100;
    return S;
}

// calculate the grade by coleman formula

int coleman_test(int letters , int words , int sentences)
{
    double index = 0.0588 * L(letters , words) - 0.296 * S(words , sentences) - 15.8;
    int grade = round(index);
    return grade;
}