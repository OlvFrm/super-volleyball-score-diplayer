#pragma once

#define USE_LOGS

#define USE_DEBUG
#define USE_INFO
#define USE_ERROR


#ifdef USE_LOGS

#ifdef USE_DEBUG
    #define LOG_DEBUG(x) Serial.print("DEBUG: "); Serial.println(x)
#else
    #define LOG_DEBUG(x)
#endif

#ifdef USE_INFO
    #define LOG_INFO(x) Serial.print("INFO: "); Serial.println(x)
#else
    #define LOG_INFO(x)
#endif

#ifdef USE_ERROR
    #define LOG_ERROR(x) Serial.print("ERROR: "); Serial.println(x)
#else
    #define LOG_ERROR(x)
#endif

#else

    #define LOG_DEBUG(x)
    #define LOG_INFO(x)
    #define LOG_ERROR(x)

#endif