```
#include<stdlib.h>
#include<string.h>

int main(void){
    char greeting[] = "memove can be very useful ... ";
    printf("before memove: %s\n",greeting);
    memmove(greeting + 5,greeting + 15,5);
    printf("after  memove: %s\n",greeting);
    return 0;
}
```