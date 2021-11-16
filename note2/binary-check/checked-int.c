#include "checked-int.h"
#include <stdint.h>
#include <stdio.h>

uint64_t ci_encode(uint32_t value){
    uint64_t value64 = 0;
    value64=value64 | value;
    value64=value64 | (value64<<32);
    /*printf("valeur 32 : %u\n", value);
    printf("valeur 64 : %lu\n", value64); */
    return value64;
}

int ci_check(uint64_t value){
    uint32_t value32=(value & 0xFFFF);
    value=value>>32;
    //printf("ligne 35 : %u %u\n", value32, (uint32_t)value);
    if (value32&value){
        printf("Vrai\n");
        return 1;
    }
    printf("faux\n");
    return 0;
}

uint32_t ci_decode(uint64_t value, int *ok){
    (void)ok;
    /* if (!ci_check(value)){
        if (ok!=NULL) *ok=0;
        if ((0xFF & value)<(0xFF & (value>>32))){
            return (0xFF & value);
        }
        else{
            return (0xFF & (value>>32));
        }
    }
    if (ok!=NULL) *ok=1; */
    return (0xFFFFFFFF & value);
}
