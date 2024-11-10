#ifndef _FPOINTERS_H
#define _FPOINTERS_H

typedef void (*ftype)(void);

void foo(void);
ftype set_foo(ftype fp);
void reg_func(ftype f);
void neco(void);
void reg_foo(void);

#endif /*_FPOINTERS_H*/