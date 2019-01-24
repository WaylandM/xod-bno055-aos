
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {

    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_BNO055` class instance
    auto aos = getValue<input_DEV>(ctx);
    uint8_t system, gyro, accel, mag;
    system = gyro = accel = mag = 0;
    aos->getCalibration(&system, &gyro, &accel, &mag);
    emitValue<output_SYS>(ctx, system);
    emitValue<output_DONE>(ctx, 1);
}
