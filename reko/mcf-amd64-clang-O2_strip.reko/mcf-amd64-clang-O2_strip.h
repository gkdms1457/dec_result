// mcf-amd64-clang-O2_strip.h
// Generated by decompiling mcf-amd64-clang-O2_strip
// using Reko decompiler version 0.11.4.0.

/*
// Equivalence classes ////////////
Eq_1: (struct "Globals"
		(400846 code t400846)
		(400856 code t400856)
		(400866 code t400866)
		(400876 code t400876)
		(400886 code t400886)
		(400896 code t400896)
		(4008A6 code t4008A6)
		(4008B6 code t4008B6)
		(4008C6 code t4008C6)
		(4008D6 code t4008D6)
		(4008E6 code t4008E6)
		(4008F6 code t4008F6)
		(400906 code t400906)
		(400916 code t400916)
		(400926 code t400926)
		(400936 code t400936)
		(400B10 Eq_14 t400B10)
		(402DD0 Eq_17 t402DD0)
		(402E40 Eq_18 t402E40)
		(404FD8 (ptr64 code) __libc_start_main_GOT)
		(404FE0 (ptr64 code) __gmon_start___GOT)
		(405000 (ptr64 code) printf_GOT)
		(405008 (ptr64 code) puts_GOT)
		(405010 (ptr64 code) exit_GOT)
		(405018 (ptr64 code) putchar_GOT)
		(405020 (ptr64 code) memset_GOT)
		(405028 (ptr64 code) strcpy_GOT)
		(405030 (ptr64 code) fwrite_GOT)
		(405038 (ptr64 code) free_GOT)
		(405040 (ptr64 code) fopen_GOT)
		(405048 (ptr64 code) fgets_GOT)
		(405050 (ptr64 code) __isoc99_sscanf_GOT)
		(405058 (ptr64 code) calloc_GOT)
		(405060 (ptr64 code) fclose_GOT)
		(405068 (ptr64 code) realloc_GOT)
		(405070 (ptr64 code) fflush_GOT)
		(405078 (ptr64 code) fprintf_GOT)
		(407F20 word64 stderr)
		(407F28 word64 stdout))
	globals_t (in globals : (ptr64 (struct "Globals")))
Eq_2: (fn void ())
	T_2 (in rdx : (ptr64 Eq_2))
	T_19 (in rtld_fini @ 0000000000400964 : (ptr64 (fn void ())))
Eq_7: (fn void ((ptr64 (ptr64 char))))
	T_7 (in __align_stack<word64> @ 0000000000400949 : ptr32)
	T_8 (in signature of __align_stack : void)
Eq_12: (fn int32 ((ptr64 Eq_14), int32, (ptr64 (ptr64 char)), (ptr64 Eq_17), (ptr64 Eq_18), (ptr64 Eq_2), (ptr64 void)))
	T_12 (in __libc_start_main @ 0000000000400964 : ptr64)
	T_13 (in signature of __libc_start_main : void)
Eq_14: (fn int32 (int32, (ptr64 (ptr64 char)), (ptr64 (ptr64 char))))
	T_14 (in main @ 0000000000400964 : (ptr64 (fn int32 (int32, (ptr64 (ptr64 char)), (ptr64 (ptr64 char))))))
	T_21 (in 0x400B10<64> @ 0000000000400964 : word64)
Eq_17: (fn void ())
	T_17 (in init @ 0000000000400964 : (ptr64 (fn void ())))
	T_24 (in 0x402DD0<64> @ 0000000000400964 : word64)
Eq_18: (fn void ())
	T_18 (in fini @ 0000000000400964 : (ptr64 (fn void ())))
	T_25 (in 0x402E40<64> @ 0000000000400964 : word64)
Eq_27: (fn void ())
	T_27 (in __halt @ 000000000040096A : ptr32)
	T_28 (in signature of __halt : void)
// Type Variables ////////////
globals_t: (in globals : (ptr64 (struct "Globals")))
  Class: Eq_1
  DataType: (ptr64 Eq_1)
  OrigDataType: (ptr64 (struct "Globals"))
T_2: (in rdx : (ptr64 Eq_2))
  Class: Eq_2
  DataType: (ptr64 Eq_2)
  OrigDataType: (ptr64 (fn void ()))
T_3: (in dwArg00 : word32)
  Class: Eq_3
  DataType: word32
  OrigDataType: word32
T_4: (in ptrArg08 : (ptr64 char))
  Class: Eq_4
  DataType: (ptr64 char)
  OrigDataType: (ptr64 char)
T_5: (in fp @ 0000000000400940 : (ptr64 void))
  Class: Eq_5
  DataType: (ptr64 void)
  OrigDataType: (ptr64 void)
T_6: (in qwArg00 @ 0000000000400940 : word64)
  Class: Eq_6
  DataType: word64
  OrigDataType: word64
T_7: (in __align_stack<word64> @ 0000000000400949 : ptr32)
  Class: Eq_7
  DataType: (ptr32 Eq_7)
  OrigDataType: (ptr32 (fn T_11 (T_10)))
T_8: (in signature of __align_stack : void)
  Class: Eq_7
  DataType: (ptr32 Eq_7)
  OrigDataType: 
T_9: (in p1 @ 0000000000400949 : word64)
  Class: Eq_9
  DataType: (ptr64 (ptr64 char))
  OrigDataType: 
T_10: (in &ptrArg08 @ 0000000000400949 : (ptr64 (ptr64 char)))
  Class: Eq_9
  DataType: (ptr64 (ptr64 char))
  OrigDataType: (ptr64 (ptr64 char))
T_11: (in __align_stack<word64>(&ptrArg08) @ 0000000000400949 : void)
  Class: Eq_11
  DataType: void
  OrigDataType: void
T_12: (in __libc_start_main @ 0000000000400964 : ptr64)
  Class: Eq_12
  DataType: (ptr64 Eq_12)
  OrigDataType: (ptr64 (fn T_26 (T_21, T_22, T_23, T_24, T_25, T_2, T_5)))
T_13: (in signature of __libc_start_main : void)
  Class: Eq_12
  DataType: (ptr64 Eq_12)
  OrigDataType: 
T_14: (in main @ 0000000000400964 : (ptr64 (fn int32 (int32, (ptr64 (ptr64 char)), (ptr64 (ptr64 char))))))
  Class: Eq_14
  DataType: (ptr64 Eq_14)
  OrigDataType: 
T_15: (in argc @ 0000000000400964 : int32)
  Class: Eq_15
  DataType: int32
  OrigDataType: 
T_16: (in ubp_av @ 0000000000400964 : (ptr64 (ptr64 char)))
  Class: Eq_16
  DataType: (ptr64 (ptr64 char))
  OrigDataType: 
T_17: (in init @ 0000000000400964 : (ptr64 (fn void ())))
  Class: Eq_17
  DataType: (ptr64 Eq_17)
  OrigDataType: 
T_18: (in fini @ 0000000000400964 : (ptr64 (fn void ())))
  Class: Eq_18
  DataType: (ptr64 Eq_18)
  OrigDataType: 
T_19: (in rtld_fini @ 0000000000400964 : (ptr64 (fn void ())))
  Class: Eq_2
  DataType: (ptr64 Eq_2)
  OrigDataType: 
T_20: (in stack_end @ 0000000000400964 : (ptr64 void))
  Class: Eq_5
  DataType: (ptr64 void)
  OrigDataType: 
T_21: (in 0x400B10<64> @ 0000000000400964 : word64)
  Class: Eq_14
  DataType: (ptr64 Eq_14)
  OrigDataType: (ptr64 (fn int32 (int32, (ptr64 (ptr64 char)), (ptr64 (ptr64 char)))))
T_22: (in SLICE(qwArg00, int32, 0) @ 0000000000400964 : int32)
  Class: Eq_15
  DataType: int32
  OrigDataType: int32
T_23: (in &ptrArg08 @ 0000000000400964 : (ptr64 (ptr64 char)))
  Class: Eq_16
  DataType: (ptr64 (ptr64 char))
  OrigDataType: (ptr64 (ptr64 char))
T_24: (in 0x402DD0<64> @ 0000000000400964 : word64)
  Class: Eq_17
  DataType: (ptr64 Eq_17)
  OrigDataType: (ptr64 (fn void ()))
T_25: (in 0x402E40<64> @ 0000000000400964 : word64)
  Class: Eq_18
  DataType: (ptr64 Eq_18)
  OrigDataType: (ptr64 (fn void ()))
T_26: (in __libc_start_main(&g_t400B10, (int32) qwArg00, &ptrArg08, &g_t402DD0, &g_t402E40, rdx, fp) @ 0000000000400964 : int32)
  Class: Eq_26
  DataType: int32
  OrigDataType: int32
T_27: (in __halt @ 000000000040096A : ptr32)
  Class: Eq_27
  DataType: (ptr32 Eq_27)
  OrigDataType: (ptr32 (fn T_29 ()))
T_28: (in signature of __halt : void)
  Class: Eq_27
  DataType: (ptr32 Eq_27)
  OrigDataType: 
T_29: (in __halt() @ 000000000040096A : void)
  Class: Eq_29
  DataType: void
  OrigDataType: void
T_30:
  Class: Eq_30
  DataType: word64
  OrigDataType: word64
T_31:
  Class: Eq_31
  DataType: word64
  OrigDataType: word64
*/
typedef struct Globals {
	<anonymous> t400846;	// 400846
	<anonymous> t400856;	// 400856
	<anonymous> t400866;	// 400866
	<anonymous> t400876;	// 400876
	<anonymous> t400886;	// 400886
	<anonymous> t400896;	// 400896
	<anonymous> t4008A6;	// 4008A6
	<anonymous> t4008B6;	// 4008B6
	<anonymous> t4008C6;	// 4008C6
	<anonymous> t4008D6;	// 4008D6
	<anonymous> t4008E6;	// 4008E6
	<anonymous> t4008F6;	// 4008F6
	<anonymous> t400906;	// 400906
	<anonymous> t400916;	// 400916
	<anonymous> t400926;	// 400926
	<anonymous> t400936;	// 400936
	Eq_14 t400B10;	// 400B10
	Eq_17 t402DD0;	// 402DD0
	Eq_18 t402E40;	// 402E40
	<anonymous> * __libc_start_main_GOT;	// 404FD8
	<anonymous> * __gmon_start___GOT;	// 404FE0
	<anonymous> * printf_GOT;	// 405000
	<anonymous> * puts_GOT;	// 405008
	<anonymous> * exit_GOT;	// 405010
	<anonymous> * putchar_GOT;	// 405018
	<anonymous> * memset_GOT;	// 405020
	<anonymous> * strcpy_GOT;	// 405028
	<anonymous> * fwrite_GOT;	// 405030
	<anonymous> * free_GOT;	// 405038
	<anonymous> * fopen_GOT;	// 405040
	<anonymous> * fgets_GOT;	// 405048
	<anonymous> * __isoc99_sscanf_GOT;	// 405050
	<anonymous> * calloc_GOT;	// 405058
	<anonymous> * fclose_GOT;	// 405060
	<anonymous> * realloc_GOT;	// 405068
	<anonymous> * fflush_GOT;	// 405070
	<anonymous> * fprintf_GOT;	// 405078
	word64 stderr;	// 407F20
	word64 stdout;	// 407F28
} Eq_1;

typedef void (Eq_2)();

typedef void (Eq_7)(char * *);

typedef int32 (Eq_12)( *, int32, char * *,  *,  *,  *, void);

typedef int32 (Eq_14)(int32 rdi, char * * rsi, char * * rdx);

typedef void (Eq_17)();

typedef void (Eq_18)();

typedef void (Eq_27)();
