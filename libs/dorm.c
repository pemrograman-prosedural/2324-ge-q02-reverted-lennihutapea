#include "dorm.h"
#include <string.h>
#include <stdio.h>

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender)
{
    struct dorm_t dorm_;

    strcpy (dorm_.name,_name);
    dorm_.capacity=_capacity; 
    dorm_.gender=_gender;
    dorm_.residents_num = 0;
    return dorm_; 
}

void print_dorm(struct dorm_t *_dorm)
{
    printf("%s|", _dorm->name);
    printf("%d|", _dorm->capacity);
    if (_dorm->gender == 0)
    {
        printf("male|");
        printf("%d\n", _dorm->residents_num);
    }
    else if (_dorm->gender == 1)
    {
        printf("female|");
        printf("%d\n", _dorm->residents_num);
    }
}