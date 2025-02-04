#ifndef NEC_TYPE_H
#define NEC_TYPE_H

#define UPPER 1
#define LOWER 2
#define DIGIT 4
#define HEX 8
#define PUNCT 16
#define SPACE 32
#define PRINT 64
#define CNTRL 128

extern const int nct_[];

#define ISUPPER(c) (nct_[(c)] & UPPER)
#define ISLOWER(c) (nct_[(c)] & LOWER)
#define ISALPHA(c) (nct_[(c)] & (LOWER | UPPER))
#define ISDIGIT(c) (nct_[(c)] & DIGIT)
#define ISALNUM(c) (nct_[(c)] & (LOWER | UPPER | DIGIT))
#define ISXDIGIT(c) (nct_[(c)] & XDIGIT)
#define ISPUNCT(c) (nct_[(c)] & PUNCT)
#define ISSPACE(c) (nct_[(c)] & SPACE)
#define ISPRINT(c) (nct_[(c)] & PRINT)
#define ISCNTRL(c) (nct_[(c)] & CNTRL)

#endif