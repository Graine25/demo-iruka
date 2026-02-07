#include <rex/runtime/guest/function.h>
#include "generated/iruka_init.h"

// Memory functions
GUEST_FUNCTION_HOOK(sub_8208EB80, memset)
GUEST_FUNCTION_HOOK(sub_8208F1F0, memcpy)
GUEST_FUNCTION_HOOK(sub_8208F760, memmove)

// String functions
GUEST_FUNCTION_HOOK(sub_8208FBE0, strncmp)
GUEST_FUNCTION_HOOK(sub_82090348, strncpy)

// Math functions
GUEST_FUNCTION_HOOK(sub_82263CF0, atof)