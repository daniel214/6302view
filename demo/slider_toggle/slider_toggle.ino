
#include "Six302.h"

/* For this demo, make sure to have the `#define S302_SERIAL`
   macro enabled in the library. 

   This demo presents a slider that alternates between -1
   and +1 */

// microseconds
#define STEP_TIME 100000
#define REPORT_TIME 500000

CommManager cm(STEP_TIME, REPORT_TIME);

float input;
float output;

void setup() {
   Serial.begin(115200);
   while(!Serial);
   
   /* Add modules */
   cm.addSlider(&input, "Left",   -1,   +1, 0.1, true); // true indicates toggle
   cm.addPlot(&output, "Right", -1.1, +1.1);

   /* Ready to communicate over Serial */
   cm.connect(&Serial, 115200);
}

void loop() {
   output = input;
   cm.step();
}
