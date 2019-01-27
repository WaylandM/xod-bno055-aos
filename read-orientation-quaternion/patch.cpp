
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_BNO055` class instance
    auto aos = getValue<input_DEV>(ctx);

    imu::Quaternion quaternion = aos->getQuat();
    emitValue<output_W>(ctx,quaternion.w());
    emitValue<output_X>(ctx,quaternion.x());
    emitValue<output_Y>(ctx,quaternion.y());
    emitValue<output_Z>(ctx,quaternion.z());
    emitValue<output_DONE>(ctx, 1);
}
