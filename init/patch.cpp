
struct State {
};

{{ GENERATED_CODE }}


void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_INIT>(ctx))
        return;

    // Get a pointer to the `Adafruit_BNO055` class instance
    auto aos = getValue<input_DEV>(ctx);

    // Attempt to initialize aos module; if attempt fails emit pulse from error port
    if (!aos->begin()) {
        emitValue<output_ERR>(ctx, 1);
        return;
    }

    // Pulse that module initialized successfully
    emitValue<output_OK>(ctx, 1);
}
