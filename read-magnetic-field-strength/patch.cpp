
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_BNO055` class instance
    auto aos = getValue<input_DEV>(ctx);

    imu::Vector<3> magnetometer = aos->getVector(Adafruit_BNO055::VECTOR_MAGNETOMETER);
        emitValue<output_X>(ctx,magnetometer.x());
        emitValue<output_Y>(ctx,magnetometer.y());
        emitValue<output_Z>(ctx,magnetometer.z());
        emitValue<output_DONE>(ctx, 1);
}
