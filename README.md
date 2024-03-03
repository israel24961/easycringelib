In c23 the "auto" keyword with another meaning is introduced,
so, now we can use the beloved "var" and "let" keywords in C. 

Also, I've seen rust's type names like "u64" and "i64" and I liked them.
isize, usize, size_t are kinda cringe.
```c
#include <assert.h>
#include <easycringelib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

fn dummyFunction() {
  printf("This is a dummy function\n");
}

su64 *currentDate() __attribute__((malloc));
su64 *currentDate() {
  var currTime = time(NULL);
  let tmp = localtime(&currTime);
  char *dateFormat = "%Y-%m-%d %H:%M:%S", *timeStr = malloc(32);
  var len = strftime(timeStr, 32, dateFormat, tmp);
  assert(len > 0 && len < 32);

  char *outMessage;
  var outlen =
      asprintf(&outMessage, "Current date and time: %s (a %lu bytes string)",
               timeStr, len);

  su64 *pData = malloc(sizeof(su64));
  pData->size = outlen;
  pData->data = outMessage;
  return pData;
}

int main() {
  dummyFunction();
  var data = currentDate();
  printf("%.*s\n", data->size, data->data);
}
```
