
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_BNO055` class instance
    auto aos = getValue<input_DEV>(ctx);

    uint8_t system_status, self_test_results, system_error;
    system_status = self_test_results = system_error = 0;
    aos->getSystemStatus(&system_status, &self_test_results, &system_error);
    emitValue<output_STAT>(ctx,system_status);
    emitValue<output_TEST>(ctx,self_test_results);
    emitValue<output_SERR>(ctx,system_error);
    emitValue<output_DONE>(ctx, 1);
}
