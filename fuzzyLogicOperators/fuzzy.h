#ifndef _FUZZY
#define _FUZZY

// Fuzzy Logic of My_Theory

float FUZZY_NOT(float a) {
  return (1.0 - a);
}

float FUZZY_AND(float a, float b) {
  return (a * b);
}

float FUZZY_NAND(float a, float b) {
  return FUZZY_NOT(a * b);
}

float FUZZY_NOR(float a, float b) {
  // ¬(A + B) = ¬(¬A * ¬B)
  return (FUZZY_NOT(a)*FUZZY_NOT(b));
}

float FUZZY_OR(float a, float b) {
  // A + B = ¬(¬A * ¬B)
  return FUZZY_NOT(FUZZY_NOR(a,b));
}

float FUZZY_NXOR(float a, float b) {
  // ¬(A x B) = (A*B ++ ¬(A+B))
  return (FUZZY_AND(a, b) + FUZZY_NOR(a, b) );
}

float FUZZY_XOR(float a, float b) {
  // A x B = ¬(A x B)
  return FUZZY_NOT(FUZZY_NXOR(a, b));
}

#endif

