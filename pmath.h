#ifndef PMATH_H
#define PMATH_H

// trunc
float m_trunc(float f) {
    float ret;
    int sign = 1;
    float p, r, fp;
    if(f < 0) {
        sign = -1;
        f *= sign;
    }
    ret = f;
    do {
        fp = f; p = 0, r = 1;
        do {
            p = r;
            r =  2 * p;
        } while(r < f);
        f -= p;
    } while(f > 0);
    ret -= fp;
    return ret * sign;
}

// sqrt


#endif
