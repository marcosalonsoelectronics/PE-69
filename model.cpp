// Automatically generated C++ file on Wed Jun 12 10:21:14 2024
//
// To build with Digital Mars C++ Compiler:
//
//    dmc -mn -WD model.cpp kernel32.lib

#include <cmath>

double
Vik=0,          // input voltage samples
Vik_1=0,        //
Vik_2=0,
Vok=0,          // output voltage samples
Vok_1=0,        //
Vok_2=0;        //




union uData
{
   bool b;
   char c;
   unsigned char uc;
   short s;
   unsigned short us;
   int i;
   unsigned int ui;
   float f;
   double d;
   long long int i64;
   unsigned long long int ui64;
   char *str;
   unsigned char *bytes;
};

// int DllMain() must exist and return 1 for a process to load the .DLL
// See https://docs.microsoft.com/en-us/windows/win32/dlls/dllmain for more information.
int __stdcall DllMain(void *module, unsigned int reason, void *reserved) { return 1; }

// #undef pin names lest they collide with names in any header file(s) you might include.
#undef in0
#undef in1
#undef in2
#undef in3
#undef out0
#undef out1
#undef out2
#undef out3

extern "C" __declspec(dllexport) void model(void **opaque, double t, union uData *data)
{
   double  in0  = data[ 0].d; // input
   double  in1  = data[ 1].d; // input
   double  in2  = data[ 2].d; // input
   double  in3  = data[ 3].d; // input
   double  w0   = data[ 4].d; // input parameter
   double  Tsp  = data[ 5].d; // input parameter
   double &out0 = data[6].d; // output
   double &out1 = data[7].d; // output
   double &out2 = data[8].d; // output
   double &out3 = data[9].d; // output

// Implement module evaluation code here:


      // CLK is at in1


      if ((in1>0.999)&&(in1<=1.001))  {

                                       Vok_2=  Vok_1;      // save previous Output Voltage samples
                                       Vok_1=  Vok;        //

                                       Vik_2=  Vik_1;      // save previous Input Voltage samples
                                       Vik_1=  Vik;        //

                                       Vik=  in0;          // load current input voltage sample

                                       // calculate current output voltage sample

                                       Vok= 1.0466*Vok_1 - 0.5477*Vok_2 + 0.5*Vik_2  ;


                                       }


   out0=Vok;
   out1=Vik;
   out2=Vok_1;
   out3=Vik_1;








}
