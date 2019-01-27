
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_BNO055` class instance
    auto aos = getValue<input_DEV>(ctx);

    int8_t temp = aos->getTemp();
    emitValue<output_TEMP>(ctx,temp);
    emitValue<output_DONE>(ctx,1);
}
