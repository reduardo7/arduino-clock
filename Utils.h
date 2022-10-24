#ifndef MODULE_UTILS
#define MODULE_UTILS

String digitPad(int d) {
  if (d > 9) {
    return String(d);
  }

  return "0" + String(d);
}

#endif