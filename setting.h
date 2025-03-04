/*version 0.0.1 03032025*/
#include <Arduino.h>

/***********************************************************
 *                  DEVICE SETTING                         *
 ***********************************************************/
#define NET_PREFIX 0x10
#define DEVICE_INDEX 0
#if (DEVICE_INDEX == 0)
  #define ROOT_NODE  // ROOT NODE
#else
  #define END_DEVICE  // END DEVICE
#endif
#define RESET_TIMEOUT 4       // [s]
#define SKIP_TIMEOUT  3000    // [ms]
#define RTI_TIMEOUT   1000    // [ms]
#define SEND_DELAY    50      // [ms]

typedef unsigned long timestamp_t;

/***********************************************************
 *                  RTI SETTING                            *
 ***********************************************************/
#define RTI_NODE_COUNT 12
#define DEVICE_OFFSET 0x30
#define DEVICE_ID  (DEVICE_OFFSET + DEVICE_INDEX)
#if DEVICE_INDEX > RTI_NODE_COUNT
  #error DEVICE_INDEX must be in range of NODE COUNT
#endif /*DEVICE_ID > RTI_NODE_COUNT*/
/**
 * RTI_DEFAULT_SCHEME     0
 * RTI_SIDEWAY_SCHEME     1
 * RTI_RECTANGULAR_SCHEME 2
 * RTI_CUSTOM_SCHEME      3
 **/
#define RTI_SCHEME 1
//#define IR_COMM
//#define DEBUG_REPORT
/***********************************************************
 *              SERIAL_COM DEFINITION                      *
 ***********************************************************/
#define out(x)    Serial.print(x)
#define outf(...) Serial.printf(__VA_ARGS__)
#define outln(x)  Serial.println(x)
#define bout(...) Serial.write(__VA_ARGS__)   
#if defined(DEBUG_REPORT)
  #define VERBOSE_REPORT
  #define re(x)     Serial.print(x)
  #define repf(...) Serial.printf(__VA_ARGS__)
  #define reln(x)   Serial.println(x)
  #if defined(VERBOSE_REPORT)
    #define ver(x)    Serial.print(x)
    #define verf(...) Serial.printf(__VA_ARGS__)
    #define verln(x)  Serial.println(x)
  #else
    #define ver(x)
    #define verf(...)
    #define verln(x)
  #endif /*VERBOSE_REPORT*/
#else
  #define re(x)
  #define repf(...)
  #define reln(x)
  #define ver(x)
  #define verf(...)
  #define verln(x)
#endif /*DEBUG_REPORT*/
#define CLEARFLAG(B, F) B &= ~F
#define SETFLAG(B, F)   B |= F
#define CHECKFLAG(B, F) (B & F)
