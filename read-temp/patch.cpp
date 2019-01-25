
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_BNO055` class instance
    auto aos = getValue<input_DEV>(ctx);


    //imu::Vector<3> euler = aos->getVector(Adafruit_BNO055::VECTOR_EULER);
    
    //int8_t Adafruit_BNO055::getTemp(void)
    //{
    //int8_t temp = (int8_t)(read8(BNO055_TEMP_ADDR));
    //return temp;
    //}

    int8_t temp = aos->getTemp();

    if (temp) {
        emitValue<output_TEMP>(ctx,temp);
        emitValue<output_OK>(ctx,1);
    } else {
        emitValue<output_ERR>(ctx,1);
    }



}
