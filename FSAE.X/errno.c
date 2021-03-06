/**
 * Error Number Header
 *
 * Processor:   PIC18F46K80 / PIC32MZ2048EFM
 * Compiler:    Microchip C18 / Microchip XC32
 * Author:      Andrew Mass
 * Created:     2015-2016
 */

#include "errno.h"

/**
 * Maps an error code to a string message describing the error
 */
const rom char* errno_msg[NUM_ERR] = {
  /*   0 */ "No error",
  /*   1 */ "Reserved",
  /*   2 */ "Reserved",
  /*   3 */ "Reserved",
  /*   4 */ "Reserved",
  /*   5 */ "Reserved",
  /*   6 */ "Reserved",
  /*   7 */ "Reserved",
  /*   8 */ "Reserved",
  /*   9 */ "Reserved",
  /*  10 */ "Reserved",
  /*  11 */ "Reserved",
  /*  12 */ "Reserved",
  /*  13 */ "Reserved",
  /*  14 */ "Reserved",
  /*  15 */ "Reserved",
  /*  16 */ "Reserved",
  /*  17 */ "Reserved",
  /*  18 */ "Reserved",
  /*  19 */ "Reserved",
  /*  20 */ "Shifting over neutral prevented due to low battery voltage",
  /*  21 */ "Shifting prevented due to very low battery voltage",
  /*  22 */ "Shifting prevented due to kill switch pressed",
  /*  23 */ "Shifting prevented due to stall protection",
  /*  24 */ "Shifting prevented due to overrev protection",
  /*  25 */ "Shifting to nonexistant gear prevented",
  /*  26 */ "Neutral shift from 3rd or higher prevented",
  /*  27 */ "Exceeded maximum number of retry shifts",
  /*  28 */ "CAN state variables are out-of-date",
  /*  29 */ "Shift queue prevented due to lockout timer",
  /*  30 */ "Shift killed due to maximum duration timer",
  /*  31 */ "Neutral shift missed neutral gear",
  /*  32 */ "Gear sensor reading invalid"
};

/**
 * void send_errno_CAN_msg(uint16_t origin_id, uint16_t errno)
 *
 * Sends an CAN error message with the sender's node ID and the error number.
 *
 * @param origin_id - Node ID of the sending node
 * @param errno - Error number of the error that occurred
 */
void send_errno_CAN_msg(uint16_t origin_id, uint16_t errno) {
  uint8_t data[8] = {0}; // Holds CAN data bytes
  ((uint16_t*) data)[ORIGIN_BYTE / 2] = origin_id;
  ((uint16_t*) data)[ERRNO_BYTE / 2] = errno;
  ECANSendMessage(ERROR_ID, data, 4, ECAN_TX_FLAGS);
}
