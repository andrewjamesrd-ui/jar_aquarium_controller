#define USER_SETUP_ID 100
#define TFT_RGB_ORDER TFT_BGR

// =========================
// Locked Hardware Pin Map
// =========================

// DISPLAY
#define TFT_MISO 13
#define TFT_MOSI 11
#define TFT_SCLK 12
#define TFT_CS   10
#define TFT_DC   14
#define TFT_RST  9
#define TFT_BL   46

// I2C
#define I2C_SDA_PIN 8
#define I2C_SCL_PIN 18

// TEMPERATURE
#define WATER_TEMP_PIN 4

// FLOW
#define FLOW_SENSOR_PIN 15

// MOSFETS
#define HEATER_MOSFET_PIN 6
#define PELTIER_MOSFET_PIN 7
#define PUMP_MOSFET_PIN 16
#define WHITE_LED_MOSFET_PIN 17
#define RGB_LED_MOSFET_PIN 21

// RESERVED INPUTS
#define WATER_LEVEL_PIN 1
#define LEAK_SENSOR_PIN 2
#define SPARE_PIN_3 3
#define SPARE_PIN_35 35
#define SPARE_PIN_36 36
#define SPARE_PIN_37 37
#define SPARE_PIN_38 38

#define TFT_WIDTH  320
#define TFT_HEIGHT 480

// 1. Driver
#define ST7796_DRIVER
//#define ILI9488_DRIVER

#define USE_HSPI_PORT
#define ESP32_DMA

// 3. Font Engine
#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8
#define LOAD_GFXFF
#define SMOOTH_FONT

// 4. Speed
#define SPI_FREQUENCY 40000000
#define SPI_READ_FREQUENCY 20000000
