#include <rex/cvar.h>
#include <rex/types.h>
#include <rex/system/kernel_state.h>
#include <atomic>
#include <chrono>
#include <cstdint>
#include <cmath>
#include <cstring>

REXCVAR_DEFINE_STRING(iruka_data_root, "", "WebOfShadows/config",
                      "Path to game asset directory. Overrides the default data root when non-empty.");

