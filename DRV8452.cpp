void DRV8452::setCurrentLimit(float current){
  _SPI->beginTransaction(_settings);
  byte value = round((current * 0.66 / 3.3) * 256) - 1;
  writeReg(0x0E, value);
  delayMicroseconds(1);
  writeReg(0x10, 0x12);
  _SPI->endTransaction();
}

void DRV8452::fullStep(bool foward){
  _SPI->beginTransaction(_settings);
  writeReg(0x05, (forward << 7) | 0b01110000)
  _SPI->endTransaction();
}

void DRV8452::setup(){
  setCurrentLimit(3.5);
  delayMicroseconds(1);
  _SPI->beginTransaction(_settings);
  writeReg(0x05, 0b00110000);
  _SPI->endTransaction();
}

void DRV8452::_writeReg(byte reg, byte val) {
    digitalWrite(_cs, 0);
    _SPI->transfer(reg);
    _SPI->transfer(val);
    digitalWrite(_cs, 1);
}