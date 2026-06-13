#include "../string.h"
#include "strerror.h"

char* strerror(int errnum) {
  static const char* error[] = CURRENT_SYSTEM_ERRORS;
  const char* message = NULL;
  if (errnum < 0 || errnum > MAX_ERROR_CODE || error[errnum] == NULL) {
    message = "Unknown error";
  } else {
    message = error[errnum];
  }
  return (char*)message;
}