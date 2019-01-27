
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_BNO055` class instance
    auto aos = getValue<input_DEV>(ctx);

    imu::Vector<3> gravity = aos->getVector(Adafruit_BNO055::VECTOR_GRAVITY);
    emitValue<output_X>(ctx,gravity.x());
    emitValue<output_Y>(ctx,gravity.y());
    emitValue<output_Z>(ctx,gravity.z());
    emitValue<output_DONE>(ctx, 1);
}
