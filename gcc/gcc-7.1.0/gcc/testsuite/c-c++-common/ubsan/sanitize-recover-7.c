/* { dg-do compile } */
/* { dg-options "-fsanitize=address -fsanitize=thread" } */

int i;

/* { dg-error "-fsanitize=address and -fsanitize=kernel-address are incompatible with -fsanitize=thread" "" { target *-*-* } 0 } */
