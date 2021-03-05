#ifndef GALILEOSIM_H
#define GALILEOSIM_H

#define LAMBDA_E1 0.190293672798365
#define PRIMARY_CODE_RATE (1023)
#define PRIMARY_CODE_LEN (4092)
#define BOC_FREQ (1.2276e7)
#define FLOAT_CARR_PHASE // For RKT simulation. Higher computational load, but smoother carrier phase.

/*! \brief Structure representing Galileo time */
typedef struct
{
	int week;	/*!< Galileo week number (since 1999) */
	double sec; 	/*!< second inside the Galileo \a week */
} galileo_time_t;

typedef struct
{
	galileo_time_t g;
	double range; // pseudorange
	double rate;
	double d; // geometric distance
	double azel[2];
	double iono_delay;
} galileo_range_t;


/*! \brief Structure representing a Channel */
typedef struct
{
	int prn;	/*< PRN Number */
	int c_primary_code[PRIMARY_CODE_LEN]; /*< C/A Sequence */
    int b_primary_code[PRIMARY_CODE_LEN]; /*< C/A Sequence */
	double f_carr;	/*< Carrier frequency */
	double f_code;	/*< Code frequency */
    double f_boc; /*< boc frequency */
#ifdef FLOAT_CARR_PHASE
	double carr_phase;
#else
	unsigned int carr_phase; /*< Carrier phase */
	int carr_phasestep;	/*< Carrier phasestep */
#endif
	double primary_code_phase; /*< Primary code phase */
    double secondary_code_phase; /*< Secondary code phase */
    double boc_phase; /*< Secondary code phase */
	galileo_time_t g0;	/*!< GPS time at start */
	unsigned long sbf[5][N_DWRD_SBF]; /*!< current subframe */
	unsigned long dwrd[N_DWRD]; /*!< Data words of sub-frame */
    int page_even_odd; // even or odd page 0-1 in HORIZONTAL!!!! page (1-0 in vertical!!!)
    int nominal_page; // 1-15(0-30 sec, 2 sec each nominal page)
    int subframe; //(1-24) - 720 sec for whole frame
    

	//int iword;	/*!< initial word */
	//int ibit;	/*!< initial bit */
	int icode;	/*!< initial code */
	int dataBit;	/*!< current data bit */
	//int codeCA;	/*!< current C/A code */
	//double azel[2];
	galileo_range_t rho0;
} galileo_channel_t;






#endif