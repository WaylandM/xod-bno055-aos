
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    //auto inValue = getValue<input_IN>(ctx);
    //emitValue<output_OUT>(ctx, inValue);

    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_BNO055` class instance
    auto aos = getValue<input_DEV>(ctx);

    // read orientation
    //sensors_event_t event;
    //aos->getEvent(&event);
    //emitValue<output_X>(ctx,event.orientation.x);
    //emitValue<output_Y>(ctx,event.orientation.y);
    //emitValue<output_Z>(ctx,event.orientation.z);

    imu::Vector<3> euler = aos->getVector(Adafruit_BNO055::VECTOR_EULER);
    if (euler) {
        emitValue<output_X>(ctx,euler.x());
        emitValue<output_Y>(ctx,euler.y());
        emitValue<output_Z>(ctx,euler.z());
        emitValue<output_OK>(ctx, 1);
    } else {
        emitValue<output_ERR>(ctx, 1);
    }
}
