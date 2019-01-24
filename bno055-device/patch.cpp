// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/adafruit/Adafruit_Sensor"
#pragma XOD require "https://github.com/adafruit/Adafruit_BNO055"

//Include C++ libraries
{{#global}}
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
{{/global}}

// Adafruit_BNO055 class wants to know id and address in the moment of instantiation
// but we don't know them at this moment.
// Therefore, we reserve memory to store an instance of the class,
// and create the instance later:
struct State {
    uint8_t mem[sizeof(Adafruit_BNO055)];
};

// Define our custom type as a pointer on the class instance.
using Type = Adafruit_BNO055*;

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // It should be evaluated only once on the first (setup) transaction
    if (!isSettingUp())
        return;

    auto state = getState(ctx);
    auto sensorID = getValue<input_ID>(ctx);
    auto address = getValue<input_ADDRESS>(ctx);

    // Create a new object in the memory area reserved previously.
    Type aos = new (state->mem) Adafruit_BNO055(sensorID, address);

    emitValue<output_DEV>(ctx, aos);
}
