 /*
 * Antarmuka ke LDR
 */

//========== Macros ========
#define LDR1_PIN A2
#define LDR2_PIN A3

#define LDR1_MIN 0
#define LDR1_MAX 4095

#define LDR2_MIN 0
#define LDR2_MAX 4095

//======= Data Type ========
struct ldrStruct{
  int ldr1;
  int ldr2;
};

//======= Variable Declaration ==========
struct ldrStruct ldrData;
float bias = 11.718; //diganti setelah dilakukan kalibrasi
float gain = 0.998; //diganti setelah dilakukan kalibrasi

//========== Functions ===========
// inisialisasi 
void ldrInit() 
{ 
  pinMode(LDR1_PIN, INPUT);   
  pinMode(LDR2_PIN, INPUT);  
}

// baca dari dua LDR
struct ldrStruct ldrRead()
{
  struct ldrStruct ldr;
  int a;
  a = analogRead(LDR1_PIN);
  ldr.ldr1 = a; // hitung koreksi 
  a = analogRead(LDR2_PIN);
  ldr.ldr2 =(int)(a*gain+bias+0.5); // hitung koreksi
  return ldr;
}
