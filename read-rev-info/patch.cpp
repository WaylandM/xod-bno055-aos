
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_BNO055` class instance
    auto aos = getValue<input_DEV>(ctx);

    Adafruit_BNO055::adafruit_bno055_rev_info_t revInfo;
    aos->getRevInfo(&revInfo);
    emitValue<output_ACC>(ctx,revInfo.accel_rev);
    emitValue<output_MAG>(ctx,revInfo.mag_rev);
    emitValue<output_GYRO>(ctx,revInfo.gyro_rev);
    emitValue<output_SW>(ctx,revInfo.sw_rev);
    //emitValue<output_Y>(ctx,euler.y());
    //emitValue<output_Z>(ctx,euler.z());
    emitValue<output_DONE>(ctx, 1);
}
