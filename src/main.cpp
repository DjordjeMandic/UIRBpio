#include <Arduino.h>

// Check if the AVR Debugger library is installed
#if __has_include(<avr8-stub.h>)
  #include <avr8-stub.h>   // Include the AVR Debugger library
  #define AVR_DEBUG        // Define a macro to indicate debugging is enabled
#endif  // __has_include(<avr8-stub.h>)

// Check if the UIRBCore library is installed
#if __has_include(<UIRBCore.hpp>)
  #include <UIRBCore.hpp>    // Include the UIRBCore library
  using namespace uirbcore;  // Use the UIRBCore namespace for easy access to its classes and functions

  // Ensure the EEPROM contains valid UIRB hardware version data.
  // If the data is invalid, the system will hang and reboot during initialization.
  UIRB& uirb = UIRB::getInstance();  // Create a singleton instance of the UIRB class
#endif  // __has_include(<UIRBCore.hpp>)

#if !defined(AVR_DEBUG)
  // Define the baud rate for serial communication
  #if defined(MONITOR_SPEED)
    static constexpr unsigned long BAUD_RATE = MONITOR_SPEED;  // Use user-defined monitor speed if available
  #else
    static constexpr unsigned long BAUD_RATE = 1000000;  // Default baud rate: 1M BAUD
  #endif  // !defined(MONITOR_SPEED)

  // Enable serial communication macros when AVR debugging is not active
  #define SERIAL_BEGIN(x) Serial.begin(x)  // Start serial communication with the specified baud rate
  #define SERIAL_PRINT(x) Serial.print(x)  // Print to the serial monitor without a newline
  #define SERIAL_PRINTLN(x) Serial.println(x)  // Print to the serial monitor with a newline
#else
  // Disable serial communication when using AVR Debugger, as it is not compatible with Serial
  #warning "Serial is not compatible with avr-stub!"
  #define SERIAL_BEGIN(x)    /* Disabled: Serial.begin(x) */
  #define SERIAL_PRINT(x)    /* Disabled: Serial.print(x) */
  #define SERIAL_PRINTLN(x)  /* Disabled: Serial.println(x) */
#endif  // defined(AVR_DEBUG)

// Function declaration
int myFunction(int, int);  // Declares a simple function that adds two integers

void setup() {
  // Initial setup: runs once when the device powers on or resets

  #if defined(AVR_DEBUG)
    debug_init();  // Initialize the AVR Debugger if enabled
  #endif  // defined(AVR_DEBUG)

  // Start serial communication
  SERIAL_BEGIN(BAUD_RATE);
  SERIAL_PRINTLN(F("Hello PIO from UIRB!"));  // Print a greeting message

  #if defined(UIRB_CORE_LIB)
  SERIAL_PRINTLN(F("UIRBcore (" UIRB_CORE_LIB_VER_STR ") has been included."));  // Confirm inclusion of the UIRBCore library
  
  // Initialize the UIRB hardware
  if (!uirb.begin()) {
      SERIAL_PRINTLN(F("UIRBcore Initialization Failed!"));
      // Halt the system if initialization fails to prevent hardware issues
      while (1);
  }
  SERIAL_PRINTLN("UIRBcore initialized successfully.");  // Confirm successful initialization
  #endif

  // Demonstrate a custom function
  int result = myFunction(2, 3);  // Call the function with arguments 2 and 3
  SERIAL_PRINT(F("2 + 3 = "));  // Print the expression
  SERIAL_PRINTLN(result);       // Print the result
}

void loop() {
  // Main code: runs repeatedly after setup()
  SERIAL_PRINTLN(F("Looping..."));  // Print a message to indicate the loop is running
  delay(1000);  // Wait for 1 second
}

// Function definition
int myFunction(int x, int y) {
  // A simple function that returns the sum of two integers
  return x + y;
}
