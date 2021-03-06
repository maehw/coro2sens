// Define if the Octopus PCB layout is used or not
// ----------------------------------------------------------------------------
#define OCTOPUS          1

// Logging to serial console
// ----------------------------------------------------------------------------
#define USE_SERIAL_CONSOLE  0
//#undef USE_SERIAL_CONSOLE // Uncomment this line to disable logging to serial console (e.g. "deactivates" bright blue LED on NodeMCU)
#if defined(USE_SERIAL_CONSOLE)
#define serial_begin   Serial.begin
#define serial_printf  Serial.printf
#define serial_println Serial.println
#else
#define serial_begin   
#define serial_printf  
#define serial_println 
#endif

// LED and NeoPixel ring
// ----------------------------------------------------------------------------
// Activity indicator LED (use the built-in LED if your board has one).
// Which pin on the Arduino is connected to the NeoPixels?

#if defined(OCTOPUS)
#define LED_GREEN_PIN    D5
//#define LED_YELLOW_PIN   D7
//#define LED_RED_PIN      D6
#define LED_WARN_PIN     D7 /* combined warning LED to replace separate yellow+red LEDs */
#define NEOPIXEL_PIN     D8
#else
#define LED_GREEN_PIN    D8
#define LED_YELLOW_PIN   D7
#define LED_RED_PIN      D6
#define NEOPIXEL_PIN     D4
#endif

//#undef NEOPIXEL_PIN

// How many NeoPixels are attached to the Arduino?
#if defined(NEOPIXEL_PIN)
  #define NUMPIXELS      16
  #define LED_INTENSITY  5
  #define COLOR_BLACK    0, 0, 0
  #define COLOR_GREEN    0, 3*LED_INTENSITY, 0
  #define COLOR_YELLOW   2*LED_INTENSITY, LED_INTENSITY, 0
  #define COLOR_RED      3*LED_INTENSITY, 0, 0
#endif /* defined(NEOPIXEL_PIN) */

// Buzzer, activated continuously when CO2 level is critical.
// ----------------------------------------------------------------------------
#if defined(OCTOPUS)
#define BUZZER_PIN       D6
#endif
//#undef BUZZER_PIN // Uncomment if buzzer shall not be used

#ifdef BUZZER_PIN
  #define BEEP_DURATION_MS  200  /* Beep duration in milliseconds */
  #define BEEP_TONE         1047 /* Note C6 (see also: pitches.h on toneMelody example) */
  #define BUZZER_MAX_BEEPS  7    /* Maximum number of beeps for an active alarm */
#endif


// CO2 thresholds for warning and critical warning
// ----------------------------------------------------------------------------
// CO2 Thresholds (ppm).
//
// Recommendation from REHVA (Federation of European Heating, Ventilation and Air Conditioning associations, rehva.eu)
// for preventing COVID-19 aerosol spread especially in schools:
// - warn: 800, critical: 1000
// (https://www.rehva.eu/fileadmin/user_upload/REHVA_COVID-19_guidance_document_V3_03082020.pdf)
//
// General air quality recommendation by the German Federal Environmental Agency (2008):
// - warn: 1000, critical: 2000
// (https://www.umweltbundesamt.de/sites/default/files/medien/pdfs/kohlendioxid_2008.pdf)
//
#define CO2_WARN_PPM     800
#define CO2_CRITICAL_PPM 1000

// CO2 measurement
// ----------------------------------------------------------------------------
// Update CO2 level every MEASURE_INTERVAL_S seconds.
// Should be kept at 2 unless you want to save power.
#define MEASURE_INTERVAL_S 2

// WiFi hotspot configuration
// ----------------------------------------------------------------------------
// Set to 0 to disable altogether.
#define WIFI_ENABLED 1
#define WIFI_HOTSPOT_PREFIX "coro2sens"
#define WIFI_HOTSPOT_SIZE 255

// How long the graph/log in the WiFi portal should go back, in minutes.
#define LOG_MINUTES 120
// Label describing the time axis.
#define TIME_LABEL "2 Stunden"

#define GRAPH_W 600
#define GRAPH_H 260
#define LOG_SIZE GRAPH_W

// Button
// ----------------------------------------------------------------------------
#define BUTTON_PIN  D3  // "GPIO0/FLASH" button on NodeMCU


