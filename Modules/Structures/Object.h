#ifndef OBERONSCOMPILER_C_OBJECT_H
#define OBERONSCOMPILER_C_OBJECT_H

struct Item;
struct Object;
struct Type;


struct Item {
    int mode;
    int level;
    struct Type type;
    long a, b, c, r;
};

struct Object {
    int class;
    int level;
    struct Object next;
    struct Object dsc;
    struct Type type;
    char *name;
    long val;


};
struct Type {
    int form;
    struct Object fields;
    struct Type base;
    int size;
    int len;

};


#endif //OBERONSCOMPILER_C_OBJECT_H
