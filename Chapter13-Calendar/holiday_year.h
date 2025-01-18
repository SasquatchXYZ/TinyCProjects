#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define FRIDAY 5
#define MONDAY 1
#define THURSDAY 4
#define FIRST_WEEK holiday->day < 8
#define SECOND_WEEK holiday->day > 7 && holiday->day < 15
#define THIRD_WEEK holiday->day > 14 && holiday->day < 22
#define FOURTH_WEEK holiday->day > 21 && holiday->day < 29
#define LAST_WEEK holiday->day > 24 && holiday->day < 32
#define COLUMNS 4
#define BOLD 1
#define RED 1
#define BLACK 0
#define CYAN 6
#define WHITE 7
#define FG 30
#define BG 40

struct holiday
{
    int month;
    int day;
    int year;
    int weekday;
    char* name;
};

int is_holiday(struct holiday* holiday);

//#ifndef HOLIDAY_YEAR_H
//#define HOLIDAY_YEAR_H
//#endif //HOLIDAY_YEAR_H
