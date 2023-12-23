#ifndef SURVIVOR
#define SURVIVOR

typedef struct survivor *p_sur;

//Struct that holds information of given survivor
//name-> Name of the survivor
//days -> Days survived untill now
struct survivor {
    char name[31];
    int days;
};

p_sur add_survivor();

#endif