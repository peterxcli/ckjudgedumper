#include<stdio.h>
#include<string.h>

double getGrade(char f, char s) {
    if (f == 'F') return 0;
    double ret = 0;
    ret += (4 - (f-'A'));
    if (s == '+') ret += 0.3;
    if (s == '-') ret -= 0.3;
    return ret;
}

int isDigit(char c) {
    if (c >= '0' && c <= '9') return 1;
    else return 0;
}

int main () {
    double creditSum = 0, weightedScoreSum = 0;
    double credit = 0;
    char c, f = ' ', s = ' ';
    while (1) {
        scanf("%c", &c);
        if (c == '\n') {
            if (f != ' ') {
                creditSum += credit;
                weightedScoreSum += getGrade(f, s) * credit;
            }
            break;
        } 
        else if (isDigit(c) && f != ' ') {
            creditSum += credit;
            weightedScoreSum += getGrade(f, s) * credit;
            f = ' ', s = ' ';
            credit = 0;
            credit = credit * 10 + (c - '0');
            f = ' ', s = ' ';
        }
        else if (isDigit(c) && f == ' ') {
            credit = credit * 10 + (c - '0');
            f = ' ', s = ' ';
        }
        else if (!isDigit(c) && f == ' ') {
            f = c;
        }
        else if (!isDigit(c) && f != ' ') {
            s = c;
            creditSum += credit;
            weightedScoreSum += getGrade(f, s) * credit;
            f = ' ', s = ' ';
            credit = 0;
        }
    }
    printf("%.2lf", weightedScoreSum / creditSum);
    return 0;
}
